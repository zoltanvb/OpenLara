#ifndef H_LEVEL
#define H_LEVEL

#include "core.h"
#include "utils.h"
#include "format.h"
#include "lara.h"
#include "enemy.h"
#include "camera.h"
#include "trigger.h"

#ifdef _DEBUG
    #include "debug.h"
#endif

const char SHADER[] =
    #include "shader.glsl"
;

const char GUI[] =
    #include "gui.glsl"
;

struct Level {
    enum { shStatic, shCaustics, shSprite, shShadowOpaque, shShadowSprite, shGUI, shMAX };

    TR::Level   level;
    Shader      *shaders[shMAX];
    Texture     *atlas;
    MeshBuilder *mesh;

    Lara        *lara;
    Camera      *camera;
    Texture     *shadow;

    float       time;
    bool        perspShadows;

    Level(const char *name, bool demo, bool home) : level(name, demo), lara(NULL), time(0.0f), perspShadows(false) {
        #ifdef _DEBUG
            Debug::init();
        #endif
        mesh = new MeshBuilder(level);
        
	    shadow = new Texture(1024, 1024, true);

        initAtlas();
        initShaders();
        initOverrides();

        for (int i = 0; i < level.entitiesBaseCount; i++) {
            TR::Entity &entity = level.entities[i];
            switch (entity.type) {
                case TR::Entity::LARA                  : 
                    entity.controller = (lara = new Lara(&level, i, home));
                    break;
                case TR::Entity::LARA_CUT              :
                    entity.controller = (lara = new Lara(&level, i, false));
                    break;
                case TR::Entity::ENEMY_WOLF            :   
                    entity.controller = new Wolf(&level, i);
                    break;
                case TR::Entity::ENEMY_BEAR            : 
                    entity.controller = new Bear(&level, i);
                    break;
                case TR::Entity::ENEMY_BAT             :   
                    entity.controller = new Bat(&level, i);
                    break;
                case TR::Entity::ENEMY_TWIN            :   
                case TR::Entity::ENEMY_CROCODILE_LAND  :   
                case TR::Entity::ENEMY_CROCODILE_WATER :   
                case TR::Entity::ENEMY_LION_MALE       :   
                case TR::Entity::ENEMY_LION_FEMALE     :   
                case TR::Entity::ENEMY_PUMA            :   
                case TR::Entity::ENEMY_GORILLA         :   
                case TR::Entity::ENEMY_RAT_LAND        :   
                case TR::Entity::ENEMY_RAT_WATER       :   
                case TR::Entity::ENEMY_REX             :   
                case TR::Entity::ENEMY_RAPTOR          :   
                case TR::Entity::ENEMY_MUTANT          :   
                case TR::Entity::ENEMY_CENTAUR         :   
                case TR::Entity::ENEMY_MUMMY           :   
                case TR::Entity::ENEMY_LARSON          :
                    entity.controller = new Enemy(&level, i, 100);
                    break;
                case TR::Entity::DOOR_1                :
                case TR::Entity::DOOR_2                :
                case TR::Entity::DOOR_3                :
                case TR::Entity::DOOR_4                :
                case TR::Entity::DOOR_5                :
                case TR::Entity::DOOR_6                :
                case TR::Entity::DOOR_BIG_1            :
                case TR::Entity::DOOR_BIG_2            :
                    entity.controller = new Door(&level, i);
                    break;
                case TR::Entity::TRAP_DOOR_1           :
                case TR::Entity::TRAP_DOOR_2           :
                    entity.controller = new TrapDoor(&level, i);
                    break;
                case TR::Entity::BRIDGE_0              :
                case TR::Entity::BRIDGE_1              :
                case TR::Entity::BRIDGE_2              :
                    entity.controller = new Bridge(&level, i);
                    break;
                case TR::Entity::GEARS_1               :
                case TR::Entity::GEARS_2               :
                case TR::Entity::GEARS_3               :
                    entity.controller = new Boulder(&level, i);
                    break;
                case TR::Entity::TRAP_FLOOR            :
                    entity.controller = new TrapFloor(&level, i);
                    break;
                case TR::Entity::TRAP_BLADE            :
                case TR::Entity::TRAP_SPIKES           :
                    entity.controller = new Trigger(&level, i, true);
                    break;
                case TR::Entity::TRAP_BOULDER          :
                    entity.controller = new Boulder(&level, i);
                    break;
                case TR::Entity::TRAP_DARTGUN          :
                    entity.controller = new Dartgun(&level, i);
                    break;
                case TR::Entity::BLOCK_1               :
                case TR::Entity::BLOCK_2               :
                    entity.controller = new Block(&level, i);
                    break;
                case TR::Entity::SWITCH                :
                case TR::Entity::SWITCH_WATER          :
                case TR::Entity::HOLE_PUZZLE           :
                case TR::Entity::HOLE_KEY              :
                    entity.controller = new Trigger(&level, i, false);
                    break;
                default                                : 
                    if (entity.modelIndex > 0)
                        entity.controller = new Controller(&level, i);
                    else
                        entity.controller = new Sprite(&level, i, 0);
            }
        }

        ASSERT(lara != NULL);
        camera = new Camera(&level, lara);

        level.cameraController = camera;
    }

    ~Level() {
        #ifdef _DEBUG
            Debug::free();
        #endif
        for (int i = 0; i < level.entitiesCount; i++)
            delete (Controller*)level.entities[i].controller;

        for (int i = 0; i < shMAX; i++)
            delete shaders[i];

        delete shadow;
        delete atlas;
        delete mesh;

        delete camera;        
    }

    void initAtlas() {
        if (!level.tilesCount) {
            atlas = NULL;
            return;
        }

        // merge all tiles into one 1024x1024 32bpp 
        TR::Color32 *data = new TR::Color32[1024 * 1024];
        for (int i = 0; i < level.tilesCount; i++) {
            int tx = (i % 4) * 256;
            int ty = (i / 4) * 256;

            TR::Color32 *ptr = &data[ty * 1024 + tx];
            for (int y = 0; y < 256; y++) {
                memcpy(ptr, &level.tiles[i].color[y * 256], 256 * sizeof(TR::Color32));
                ptr += 1024;
            }
        }

        // white texture
        for (int y = 1020; y < 1024; y++)
            for (int x = 1020; x < 1024; x++) {
                int i = y * 1024 + x;
                data[i].r = data[i].g = data[i].b = data[i].a = 255;    // white texel for colored triangles
            }
/*
        FILE *f = fopen("atlas.raw", "wb");
        fwrite(data, 1024 * 1024 * 4, 1, f);
        fclose(f);
*/

        atlas = new Texture(1024, 1024, false, data);
        PROFILE_LABEL(TEXTURE, atlas->ID, "atlas");

        delete[] data;
        delete[] level.tiles;
        level.tiles = NULL;
    }

    void initShaders() {
        char def[255], ext[255];

        ext[0] = 0;
		if (Core::support.shadowSampler) {
			#ifdef MOBILE
				strcat(ext, "#extension GL_EXT_shadow_samplers : require\n");
			#endif
			strcat(ext, "#define SHADOW_SAMPLER\n");
		} else
			if (Core::support.depthTexture)
				strcat(ext, "#define SHADOW_DEPTH\n");
			else
				strcat(ext, "#define SHADOW_COLOR\n");

        sprintf(def, "%s#define PASS_SHADOW\n", ext);
        shaders[shShadowOpaque] = new Shader(SHADER, def);
        strcat(def, "#define SPRITE\n");
        shaders[shShadowSprite] = new Shader(SHADER, def);

        sprintf(def, "%s#define MAX_LIGHTS %d\n#define MAX_RANGES %d\n#define MAX_OFFSETS %d\n#define MAX_SHADOW_DIST %d.0\n", ext, MAX_LIGHTS, mesh->animTexRangesCount, mesh->animTexOffsetsCount, MAX_SHADOW_DIST);
        shaders[shStatic]   = new Shader(SHADER, def);
        sprintf(ext, "%s#define CAUSTICS\n", def);
        shaders[shCaustics] = new Shader(SHADER, ext);
        sprintf(ext, "%s#define SPRITE\n", def);
        shaders[shSprite]   = new Shader(SHADER, ext);
        sprintf(ext, "%s#define SPRITE\n", def);
        shaders[shGUI]      = new Shader(GUI, "");
    }

    void initOverrides() {
    /*
        for (int i = 0; i < level.entitiesCount; i++) {
            int16 &id = level.entities[i].id;
            switch (id) {
            // weapon
                case 84 : id =  99; break; // pistols
                case 85 : id = 100; break; // shotgun
                case 86 : id = 101; break; // magnums
                case 87 : id = 102; break; // uzis
            // ammo
                case 88 : id = 103; break; // for pistols
                case 89 : id = 104; break; // for shotgun
                case 90 : id = 105; break; // for magnums
                case 91 : id = 106; break; // for uzis
            // medikit
                case 93 : id = 108; break; // big
                case 94 : id = 109; break; // small
            // keys
                case 110 : id = 114; break; 
                case 111 : id = 115; break; 
                case 112 : id = 116; break; 
                case 113 : id = 117; break; 
                case 126 : id = 127; break; 
                case 129 : id = 133; break; 
                case 130 : id = 134; break; 
                case 131 : id = 135; break; 
                case 132 : id = 136; break; 
                case 141 : id = 145; break; 
                case 142 : id = 146; break; 
                case 143 : id = 150; break; 
                case 144 : id = 150; break;
            }
        }
    */
    }

#ifdef LEVEL_EDITOR
    struct Light {
        vec3    pos;
        float   radius;
        float   intensity;
    } lights[255];
    int lightsCount    = 0;
    int lightIntensity = 0.5f;
    float lightRadius  = 4096.0f;

    int findLight(const vec3 &pos, float maxDist) const {
        int index = 0;
        for (int i = 0; i < lightsCount; i++) {
            float d = (lights[i].pos - pos).length();
            if (d < maxDist) {
                maxDist = d;
                index   = i;
            }
        }
        return index;
    }

    void addLight(const vec3 &pos, float radius) {
        int index = findLight(pos, 1024.0f);
        if (index > -1) {
            lightRadius    = lights[index].radius;
            lightIntensity = lights[index].intensity;
        } else
            index = lightsCount++;
        
        lights[index].pos    = pos;
        lights[index].radius = radius;
    }

    void removeLight(const vec3 &pos) {
        int index = findLight(pos, 1024.0f);
        if (index > -1)
            lights[index] = lights[--lightsCount];
    }

    void updateLight(const vec3 &pos, float addRadius, float addIntensity) {
        int index = findLight(pos, 1024.0f);
        if (index > -1) {            
            lights[index].radius    = max(lights[index].radius + addRadius, 256.0f);
            lights[index].intensity = clamp(lights[index].intensity + addIntensity, 0.0f, 1.0f);
            lightRadius    = lights[index].radius;
            lightIntensity = lights[index].intensity;
        }
    }

    void updateEditor() {


    }

    void renderEditor() {
    #ifdef _DEBUG
        Debug::begin();

        Debug::end();
    #endif
    }
#endif

    Shader *setRoomShader(const TR::Room &room, float intensity) {
        if (Core::pass == Core::passShadow)
            return shaders[shShadowOpaque];

        if (room.flags.water) {
            Core::color = vec4(0.6f, 0.9f, 0.9f, intensity);
            return shaders[shCaustics];
        } else {
            Core::color = vec4(1.0f, 1.0f, 1.0f, intensity);
            return shaders[shStatic];
        }
    }

    void renderRoom(int roomIndex, int from = -1) {
        ASSERT(roomIndex >= 0 && roomIndex < level.roomsCount);
        PROFILE_MARKER("ROOM");

        TR::Room &room = level.rooms[roomIndex];
        vec3 offset = vec3(float(room.info.x), 0.0f, float(room.info.z));

        Shader *sh = setRoomShader(room, 1.0f);

        Core::lightColor[0] = vec4(0, 0, 0, 1);
       // glDisable(GL_CULL_FACE);
        sh->bind();
        sh->setParam(uColor,      Core::color);
        sh->setParam(uLightColor, Core::lightColor[0], MAX_LIGHTS);
        sh->setParam(uLightPos,   Core::lightPos[0], MAX_LIGHTS);

    // room static meshes
        if (Core::pass != Core::passShadow)
            for (int i = 0; i < room.meshesCount; i++) {
                TR::Room::Mesh &rMesh = room.meshes[i];
                if (rMesh.flags.rendered) continue;    // skip if already rendered

                TR::StaticMesh *sMesh = level.getMeshByID(rMesh.meshID);
                ASSERT(sMesh != NULL);

                if (!mesh->meshMap[sMesh->mesh]) continue;

            // check visibility
                Box box;
                vec3 offset = vec3((float)rMesh.x, (float)rMesh.y, (float)rMesh.z);
                sMesh->getBox(false, rMesh.rotation, box);
                if (!camera->frustum->isVisible(offset + box.min, offset + box.max))
                    continue;
                rMesh.flags.rendered = true;

                Core::color.w = intensityf(rMesh.intensity == -1 ? room.ambient : rMesh.intensity);
                sh->setParam(uColor, Core::color);

            // render static mesh
                mat4 mTemp = Core::mModel;
                Core::mModel.translate(offset);
                Core::mModel.rotateY(rMesh.rotation);
                sh->setParam(uModel, Core::mModel);
                mesh->renderMesh(mesh->meshMap[sMesh->mesh]);
                Core::mModel = mTemp;
            }

    // room geometry & sprites
        if (!room.flags.rendered) {    // skip if already rendered
            mat4 mTemp = Core::mModel;
            room.flags.rendered = true;

            Core::lightColor[0] = vec4(0, 0, 0, 1);

            Core::mModel.translate(offset);

        // render room geometry
            sh->setParam(uModel, Core::mModel);
            if (Core::pass == Core::passOpaque) {
                Core::color.w = intensityf(room.ambient);
                sh->setParam(uLightColor, Core::lightColor[0], MAX_LIGHTS);
                sh->setParam(uLightPos,   Core::lightPos[0],   MAX_LIGHTS);
                sh->setParam(uColor,      Core::color);
                mesh->renderRoomGeometry(roomIndex);
            }

        // render room sprites
            if (mesh->hasRoomSprites(roomIndex) && Core::pass != Core::passShadow) {
                sh = shaders[Core::pass == Core::passShadow ? shShadowSprite : shSprite];
                sh->bind();
                Core::color.w = 1.0f;
                sh->setParam(uModel,      Core::mModel);
                sh->setParam(uColor,      Core::color);
                sh->setParam(uLightColor, Core::lightColor[0], MAX_LIGHTS);
                sh->setParam(uLightPos,   Core::lightPos[0],   MAX_LIGHTS);
                mesh->renderRoomSprites(roomIndex);
            }

            Core::mModel = mTemp;
        }

    #ifdef LEVEL_EDITOR
        return;
    #endif

    // render rooms through portals recursively
        Frustum *camFrustum = camera->frustum;   // push camera frustum
        Frustum frustum;
        camera->frustum = &frustum;

        for (int i = 0; i < room.portalsCount; i++) {
            TR::Room::Portal &p = room.portals[i];

            if (p.roomIndex == from) continue;

            vec3 v[] = {
                offset + p.vertices[0],
                offset + p.vertices[1],
                offset + p.vertices[2],
                offset + p.vertices[3],
            };

            frustum = *camFrustum;
            if (frustum.clipByPortal(v, 4, p.normal))
                renderRoom(p.roomIndex, roomIndex);
        }
        camera->frustum = camFrustum;    // pop camera frustum
    }

    int getLightIndex(const vec3 &pos, int &room) {
        int idx = -1;
        float dist;
      //  for (int j = 0; j < level.roomsCount; j++)
        int j = room;
            for (int i = 0; i < level.rooms[j].lightsCount; i++) {
                TR::Room::Light &light = level.rooms[j].lights[i];
                float d = (pos - vec3(float(light.x), float(light.y), float(light.z))).length2();
                if (idx == -1 || d < dist) {
                    idx = i;
                    dist = d;
                //    room = j;
                }
            }
        return idx;
    }


    int getLightIndex2(const vec3 &pos, int &room, float maxAtt = -1.0f, int depth = 3) {
        int idx = -1;

        TR::Room &r = level.rooms[room];

        for (int i = 0; i < r.lightsCount; i++) {
            TR::Room::Light &light = r.lights[i];
            float att = max(0.0f, 1.0f - (pos - vec3(float(light.x), float(light.y), float(light.z))).length2() / ((float)light.attenuation * (float)light.attenuation));
            if (att > maxAtt) {
                maxAtt = att;
                idx    = i;
            }
        }

        if (depth > 0) 
            for (int i = 0; i < r.portalsCount; i++) {
                int nextRoom = r.portals[i].roomIndex;
                int nextLight = getLightIndex2(pos, nextRoom, maxAtt, depth - 1);
                if (nextLight > -1) {
                    room = nextRoom;
                    idx  = nextLight;
                }
            }

        return idx;
    }

    void getLight(const vec3 &pos, int roomIndex) {
        int room = roomIndex;
        int idx = getLightIndex(pos, room);

        if (idx > -1) {
            TR::Room::Light &light = level.rooms[room].lights[idx];
            float c = 1.0f - intensityf(level.rooms[room].lights[idx].intensity);
            Core::lightPos[0]   = vec3(float(light.x), float(light.y), float(light.z));
            Core::lightColor[0] = vec4(c, c, c, (float)light.attenuation * (float)light.attenuation);
        } else {
            Core::lightPos[0]   = vec3(0);
            Core::lightColor[0] = vec4(0, 0, 0, 1);
        }
    }

    void renderEntity(const TR::Entity &entity) {
        //if (entity.room != lara->getRoomIndex()) return;
        if (entity.type == TR::Entity::NONE) return;
        if (Core::pass == Core::passShadow && !TR::castShadow(entity.type)) return;

        ASSERT(entity.controller);

        TR::Room &room = level.rooms[entity.room];
        if (!room.flags.rendered || entity.flags.invisible || entity.flags.rendered)
            return;

        int16 lum = entity.intensity == -1 ? room.ambient : entity.intensity; 
        setRoomShader(room, sqrtf(intensityf(lum)))->bind();

        if (entity.modelIndex > 0) // model
            getLight(((Controller*)entity.controller)->pos, entity.room);

        if (entity.modelIndex < 0) { // sprite
            shaders[Core::pass == Core::passShadow ? shShadowSprite : shSprite]->bind();
            Core::lightPos[0]   = vec3(0);
            Core::lightColor[0] = vec4(0, 0, 0, 1);
        }        
       
        Core::active.shader->setParam(uColor, Core::color);
        Core::active.shader->setParam(uLightPos, Core::lightPos[0], MAX_LIGHTS);
        Core::active.shader->setParam(uLightColor, Core::lightColor[0], MAX_LIGHTS);

        ((Controller*)entity.controller)->render(camera->frustum, mesh);
    }


    void update() {
        time += Core::deltaTime;

        for (int i = 0; i < level.entitiesCount; i++) 
            if (level.entities[i].type != TR::Entity::NONE) {
                Controller *controller = (Controller*)level.entities[i].controller;
                if (controller) 
                    controller->update();
            }
        
        camera->update();

        static bool tmpFlag = false;

        if (Input::down[ikEnter]) {
            if (!tmpFlag) {
                perspShadows = !perspShadows;
                tmpFlag = true;
            }
        } else
            tmpFlag = false;
    }

    void setup() {
        PROFILE_MARKER("SETUP");

        camera->setup(Core::pass != Core::passShadow);;

        atlas->bind(0);

        if (!Core::support.VAO)
            mesh->bind();

        // set frame constants for all shaders
        Core::active.shader = NULL;
        for (int i = 0; i < shMAX; i++) {
            shaders[i]->bind();
            shaders[i]->setParam(uViewProj, Core::mViewProj);
            shaders[i]->setParam(uLightProj, Core::mLightProj);
            shaders[i]->setParam(uViewInv, Core::mViewInv);
            shaders[i]->setParam(uViewPos, Core::viewPos);
            shaders[i]->setParam(uParam, vec4(time, 0, 0, 0));
            shaders[i]->setParam(uLightTarget, lara->pos);
            shaders[i]->setParam(uAnimTexRanges, mesh->animTexRanges[0], mesh->animTexRangesCount);
            shaders[i]->setParam(uAnimTexOffsets, mesh->animTexOffsets[0], mesh->animTexOffsetsCount);
        }
        glEnable(GL_DEPTH_TEST);

        Core::setCulling(cfFront);

        Core::mModel.identity();

        // clear visible flags for rooms & static meshes
        for (int i = 0; i < level.roomsCount; i++) {
            TR::Room &room = level.rooms[i];
            room.flags.rendered = false;                            // clear visible flag for room geometry & sprites

            for (int j = 0; j < room.meshesCount; j++)
                room.meshes[j].flags.rendered = false;     // clear visible flag for room static meshes
        }    
        
        for (int i = 0; i < level.entitiesCount; i++)
            level.entities[i].flags.rendered = false;
    }

    void renderRooms() {
        PROFILE_MARKER("ROOMS");
    #ifdef LEVEL_EDITOR
        for (int i = 0; i < level.roomsCount; i++)
            renderRoom(i);
    #else
        renderRoom(camera->getRoomIndex());
    #endif
    }

    void renderEntities() {
        PROFILE_MARKER("ENTITIES");
        shaders[Core::pass == Core::passShadow ? shShadowOpaque : shStatic]->bind();
        for (int i = 0; i < level.entitiesCount; i++)
            renderEntity(level.entities[i]);
    }

    void renderScene() {
        PROFILE_MARKER("SCENE");
        setup();
        renderRooms();
        renderEntities();
    }
    
    bool setupLightCamera() {
        vec3 pos = (lara->animation.getJoints(lara->getMatrix(), 0, false, NULL)).getPos();
    
    // omni-spot light shadows
        int room = lara->getRoomIndex();
        int idx = getLightIndex2(lara->pos, room);
        if (idx < 0) return false;

        if (perspShadows) {
            TR::Room::Light &light = level.rooms[room].lights[idx];
            vec3 lightPos = vec3(float(light.x), float(light.y), float(light.z)); 
	        Core::mView = mat4(lightPos, pos - vec3(0, 256, 0), vec3(0, -1, 0)).inverse();
	        Core::mProj = mat4(120, 1.0f, camera->znear, camera->zfar);
            //Core::mProj.e22 /= camera->zfar;
            //Core::mProj.e32 /= camera->zfar;
        } else {
        // fixed direct light shadows
            float size = MAX_SHADOW_DIST;
            float zfar = 8192.0f;
	        Core::mView = mat4(pos - vec3(1536, 4096, 1024), pos, vec3(1, 0, 0)).inverse();
	        Core::mProj = mat4(-size, size, -size, size, 0, zfar);

        //    Core::mProj.e22 /= zfar;
        //    Core::mProj.e23 /= zfar;
        }


	    Core::mViewProj = Core::mProj * Core::mView;

	    mat4 bias;
	    bias.identity();
	    bias.e03 = bias.e13 = bias.e23 = bias.e00 = bias.e11 = bias.e22 = 0.5f;
	    Core::mLightProj = bias * Core::mProj * Core::mView; //  * ( * ) ?

        Shader *sh = shaders[shShadowOpaque];
        sh->bind();
        sh->setParam(uViewProj, Core::mViewProj);
        sh->setParam(uLightProj, Core::mLightProj);

        sh = shaders[shShadowSprite];
        sh->bind();
        sh->setParam(uViewProj, Core::mViewProj);
        sh->setParam(uLightProj, Core::mLightProj);

        return true;
    }

    void renderShadows() {
        if (!setupLightCamera()) return;
        PROFILE_MARKER("PASS_SHADOW");
        Texture::unbind(sShadow);
        Core::pass = Core::passShadow;
	    Core::setBlending(bmNone);
	    Core::setTarget(shadow);
	    Core::setViewport(0, 0, shadow->width, shadow->height);
	    Core::clear(vec4(1.0));	    
	    renderScene();
	    Core::setTarget(NULL);
        shadow->bind(sShadow);
    }
    
    void render() {
        renderShadows();

        Core::pass = Core::passOpaque;
        Core::setBlending(bmAlpha);
        Core::clear(vec4(0.0f));
        Core::setViewport(0, 0, Core::width, Core::height);
        renderScene();

    #ifdef _DEBUG
        static int modelIndex = 0;
        static bool lastStateK = false;
        static int lastEntity = -1;
        if (Input::down[ikM]) {
            if (!lastStateK) {
                lastStateK = true;
            //    modelIndex = (modelIndex + 1) % level.modelsCount;
                modelIndex = (modelIndex + 1) % level.spriteSequencesCount;
                LOG("model: %d %d\n", modelIndex, level.spriteSequences[modelIndex].type);
                if (lastEntity > -1) {
                    delete level.entities[lastEntity].controller;
                    level.entityRemove(lastEntity);
                }
                vec3 p = lara->pos + lara->getDir() * 256.0f;
                lastEntity = level.entityAdd(level.models[modelIndex].type, lara->getRoomIndex(), p.x, p.y - 512, p.z, lara->getEntity().rotation, -1);
                level.entities[lastEntity].controller = new Controller(&level, lastEntity);
            }
        } else
            lastStateK = false;

        if (lastEntity > -1)
            renderEntity(level.entities[lastEntity]);
//        renderModel(level.models[modelIndex], level.entities[4]);




        Debug::begin();
        //    Debug::Level::rooms(level, lara->pos, lara->getEntity().room);
            Debug::Level::lights(level);
        //    Debug::Level::sectors(level, lara->getRoomIndex(), (int)lara->pos.y);
        //    Debug::Level::portals(level);
        //    Debug::Level::meshes(level);
        //    Debug::Level::entities(level);
            /*
            glPushMatrix();
            glColor3f(1, 1, 1);
            glTranslatef(lara->pos.x, lara->pos.y, lara->pos.z);
            Texture::unbind(sShadow);
            shadow->bind(sDiffuse);
            glEnable(GL_TEXTURE_2D);
            glDisable(GL_CULL_FACE);
            glBegin(GL_QUADS);
                glTexCoord2f(0, 0); glVertex3f(   0,     0, 0);
                glTexCoord2f(1, 0); glVertex3f(1024,     0, 0);
                glTexCoord2f(1, 1); glVertex3f(1024, -1024, 0);
                glTexCoord2f(0, 1); glVertex3f(   0, -1024, 0);
            glEnd();
            glPopMatrix();
            glDisable(GL_CULL_FACE);
            glDisable(GL_TEXTURE_2D);
            */
           /*
            shaders[shGUI]->bind();
            Core::mViewProj = mat4(0, (float)Core::width, (float)Core::height, 0, 0, 1);
            Core::active.shader->setParam(uViewProj, Core::mViewProj);            
            atlas->bind(0);

            glDisable(GL_DEPTH_TEST);
            glDisable(GL_CULL_FACE);
            //
            glEnable(GL_CULL_FACE);
            glEnable(GL_DEPTH_TEST);
            */

            Debug::Level::info(level, lara->getEntity(), lara->animation);
        Debug::end();
    #endif
    }
};

#endif