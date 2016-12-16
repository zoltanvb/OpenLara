R"====(
varying vec2 vTexCoord;

#ifndef PASS_SHADOW
    varying vec4 vLightProj;
    varying vec4 vNormal;
    varying vec3 vLightVec[MAX_LIGHTS];
    varying vec3 vLightTarget;
    varying vec3 vViewVec;
    varying vec4 vColor;
#endif

#ifdef VERTEX
    uniform mat4 uViewProj;
    uniform mat4 uModel;
    uniform mat4 uViewInv;
    uniform mat4 uLightProj;
    uniform vec3 uLightTarget;

    #ifndef PASS_SHADOW
        uniform vec3 uLightPos[MAX_LIGHTS];
        uniform vec3 uViewPos;

        #ifndef SPRITE
            uniform vec2 uAnimTexRanges[MAX_RANGES];
            uniform vec2 uAnimTexOffsets[MAX_OFFSETS];
        #endif
    
        uniform vec4 uParam; // x - time
    #endif

    
    attribute vec4 aCoord;
    attribute vec4 aTexCoord;
    #ifndef PASS_SHADOW
        attribute vec4 aNormal;
        attribute vec4 aColor;
    #endif

    #define TEXCOORD_SCALE (1.0 / 32767.0)
    
    void main() {
        vec4 coord  = uModel * vec4(aCoord.xyz, 1.0);

        #ifndef SPRITE
            #ifndef PASS_SHADOW
                // animated texture coordinates
                vec2 range  = uAnimTexRanges[int(aTexCoord.z)]; // x - start index, y - count

                float f = fract((aTexCoord.w + uParam.x * 4.0 - range.x) / range.y) * range.y;
                vec2 offset = uAnimTexOffsets[int(range.x + f)]; // texCoord offset from first frame

                vTexCoord   = (aTexCoord.xy + offset) * TEXCOORD_SCALE; // first frame + offset * isAnimated
                vNormal     = vec4((uModel * vec4(aNormal.xyz, 0.0)).xyz, aNormal.w);
            #else
                vTexCoord   = aTexCoord.xy * TEXCOORD_SCALE;
            #endif
        #else
            coord.xyz  += uViewInv[0].xyz * aTexCoord.z - uViewInv[1].xyz * aTexCoord.w;
            #ifndef PASS_SHADOW
                vTexCoord   = aTexCoord.xy * TEXCOORD_SCALE;
                vNormal     = vec4(uViewPos.xyz - coord.xyz, 0.0);
            #endif
        #endif

        #ifndef PASS_SHADOW
            vColor = aColor;

            #if defined(CAUSTICS) 
                float sum = coord.x + coord.y + coord.z;
                vColor.xyz *= abs(sin(sum / 512.0 + uParam.x)) * 1.5 + 0.5; // color dodge
            #endif

            vViewVec = uViewPos - coord.xyz;
            for (int i = 0; i < MAX_LIGHTS; i++)
                vLightVec[i] = uLightPos[i] - coord.xyz;

            vLightTarget  = uLightTarget - coord.xyz;
            
            
            //float rLightAngle = dot(normalize(vLightVec[0]), normalize(vNormal.xyz));
            //float rNormalScale = clamp(1.0 - rLightAngle, 0.0, 1.0);
            //rNormalScale *= 50.0;//10.0 * (1.0 / 1024.0);
            vLightProj = uLightProj * coord;//vec4(coord.xyz + normalize(vNormal.xyz) * rNormalScale, 1.0f);

            coord = uViewProj * coord;
        #else
            coord = uViewProj * coord;
           // coord.z *= coord.w;
        #endif

        gl_Position = coord;
    }
#else
    uniform sampler2D   sDiffuse;
    uniform vec4        uColor;
    #ifndef PASS_SHADOW
        uniform vec4    uLightColor[MAX_LIGHTS];
    #endif

    #ifdef PASS_SHADOW
        #ifdef SHADOW_COLOR
            vec4 pack(in float value) {
                vec4 bitSh = vec4(256.0*256.0*256.0, 256.0*256.0, 256.0, 1.0);
                vec4 bitMsk = vec4(0.0, 1.0/256.0, 1.0/256.0, 1.0/256.0);
                vec4 res = fract(value * bitSh);
                res -= res.xxyz * bitMsk;
                return res;
            }
        #endif
    #else
        #ifdef AMBIENT_CUBE
            uniform vec3 uAmbientCube[6];

            vec3 getAmbientLight(vec3 n) {
                vec3 sqr = n * n;
                vec3 pos = step(0.0, n);
                return sqr.x * mix(uAmbientCube[0], uAmbientCube[1], pos.x) + 
                       sqr.y * mix(uAmbientCube[2], uAmbientCube[3], pos.y) +
                       sqr.z * mix(uAmbientCube[4], uAmbientCube[5], pos.z);
            }
        #else
            uniform vec3 uAmbient;

            vec3 getAmbientLight(vec3 n) {
                return vec3(vColor.w);
            }
        #endif

        #ifdef SHADOW_SAMPLER
            uniform sampler2DShadow sShadow;
            #ifdef MOBILE
                #define SHADOW(V) (shadow2DEXT(sShadow, V))             
            #else
                #define SHADOW(V) (shadow2D(sShadow, V).x)
            #endif
        #else
            uniform sampler2D sShadow;
            #define CMP(a,b) float(a > b)

            #ifdef SHADOW_DEPTH
                #define SHADOW(V) CMP(texture2D(sShadow, (V).xy).x, p.z)
            #elif defined(SHADOW_COLOR)
                float unpack(vec4 value) {
                    vec4 bitSh = vec4(1.0/(256.0*256.0*256.0), 1.0/(256.0*256.0), 1.0/256.0, 1.0);
                    return dot(value, bitSh);
                }
                #define SHADOW(V) CMP(unpack(texture2D(sShadow, (V).xy)), p.z)
            #else
                #define SHADOW(v) 1.0
            #endif
        #endif

        float getShadow(vec4 lightProj) {
            vec3 p = lightProj.xyz / lightProj.w;

            if (lightProj.w < 1.0) return 1.0; 

            float rShadow = 0.0;
            for (float y = -3.5 ; y <=3.5 ; y+=1.0)
                for (float x = -3.5 ; x <=3.5 ; x+=1.0)
                    rShadow += SHADOW(p + vec3(x, y, 0.0) * (1.0 / 1024.0) );					
            rShadow /= 64.0;

            float fade = min(1.0, dot(vLightTarget.xz, vLightTarget.xz) / (MAX_SHADOW_DIST * MAX_SHADOW_DIST));
            return mix(rShadow, 1.0, fade);
        }
    #endif

    void main() {
        vec4 color = texture2D(sDiffuse, vTexCoord);
        if (color.w < 0.6)
            discard;
        
        #ifdef PASS_SHADOW
            #ifdef SHADOW_COLOR
                gl_FragColor = pack(gl_FragCoord.z);
            #else
                gl_FragColor = vec4(1.0);
            #endif
        #else
            color.xyz *= uColor.xyz;
            color.xyz *= vColor.xyz;

            color.xyz = pow(abs(color.xyz), vec3(2.2)); // to linear space

        // calc point lights
            vec3 normal   = normalize(vNormal.xyz);
            vec3 viewVec  = normalize(vViewVec);
            vec3 light    = vec3(0.0);
            for (int i = 0; i < MAX_LIGHTS; i++) {
                vec3 lv = vLightVec[i];
                vec4 lc = uLightColor[i];
                float lum = max(0.0, dot(normal, normalize(lv)));
                float att = max(0.0, 1.0 - dot(lv, lv) / lc.w);
                light += lc.xyz * (lum * att);
            }

        // apply lighting
            #ifdef SPRITE
                color.xyz *= light + vColor.w;
            #else
                float shadow = getShadow(vLightProj);

                vec3 dlight = mix(vec3(uColor.w * uColor.w), light + uColor.w, shadow);
                dlight *= dot(normal, viewVec) * 0.5 + 0.5; //  backlight

                vec3 slight = light + mix(uColor.w, vColor.w, shadow);
                
                light = mix(slight, dlight, vNormal.w);

                color.xyz *= light;
            #endif

            color.xyz = pow(abs(color.xyz), vec3(1.0/2.2)); // back to gamma space

        // apply fog
            float fog = clamp(1.0 / exp(gl_FragCoord.z / gl_FragCoord.w * 0.000025), 0.0, 1.0);
            color = mix(vec4(0.0, 0.0, 0.0, 1.0), color, fog);

            gl_FragColor = color;
        #endif
    }
#endif
)===="