#ifndef H_FORMAT
#define H_FORMAT

#include "utils.h"

#define MAX_RESERVED_ENTITIES 128
#define MAX_FLIPMAP_COUNT     16
#define MAX_SECRETS_COUNT     16
#define MAX_TRACKS_COUNT      64
#define MAX_TRIGGER_COMMANDS  32
#define MAX_MESHES            512

#define TR1_TYPES(E) \
    E( LARA                  ) \
    E( LARA_PISTOLS          ) \
    E( LARA_SHOTGUN          ) \
    E( LARA_MAGNUMS          ) \
    E( LARA_UZIS             ) \
    E( LARA_SPEC             ) \
    E( ENEMY_DOPPELGANGER    ) \
    E( ENEMY_WOLF            ) \
    E( ENEMY_BEAR            ) \
    E( ENEMY_BAT             ) \
    E( ENEMY_CROCODILE_LAND  ) \
    E( ENEMY_CROCODILE_WATER ) \
    E( ENEMY_LION_MALE       ) \
    E( ENEMY_LION_FEMALE     ) \
    E( ENEMY_PUMA            ) \
    E( ENEMY_GORILLA         ) \
    E( ENEMY_RAT_LAND        ) \
    E( ENEMY_RAT_WATER       ) \
    E( ENEMY_REX             ) \
    E( ENEMY_RAPTOR          ) \
    E( ENEMY_MUTANT_1        ) \
    E( ENEMY_MUTANT_2        ) \
    E( ENEMY_MUTANT_3        ) \
    E( ENEMY_CENTAUR         ) \
    E( ENEMY_MUMMY           ) \
    E( UNUSED_1              ) \
    E( UNUSED_2              ) \
    E( ENEMY_LARSON          ) \
    E( ENEMY_PIERRE          ) \
    E( ENEMY_SKATEBOARD      ) \
    E( ENEMY_SKATEBOY        ) \
    E( ENEMY_COWBOY          ) \
    E( ENEMY_MR_T            ) \
    E( ENEMY_NATLA           ) \
    E( ENEMY_GIANT_MUTANT    ) \
    E( TRAP_FLOOR            ) \
    E( TRAP_BLADE            ) \
    E( TRAP_SPIKES           ) \
    E( TRAP_BOULDER          ) \
    E( TRAP_DART             ) \
    E( TRAP_DART_EMITTER     ) \
    E( DRAWBRIDGE            ) \
    E( TRAP_SLAM             ) \
    E( TRAP_SWORD            ) \
    E( HAMMER_HANDLE         ) \
    E( HAMMER_BLOCK          ) \
    E( LIGHTNING_BALL        ) \
    E( DOOR_LATCH            ) \
    E( BLOCK_1               ) \
    E( BLOCK_2               ) \
    E( BLOCK_3               ) \
    E( BLOCK_4               ) \
    E( MOVING_BLOCK          ) \
    E( TRAP_CEILING_1        ) \
    E( TRAP_CEILING_2        ) \
    E( SWITCH                ) \
    E( SWITCH_WATER          ) \
    E( DOOR_1                ) \
    E( DOOR_2                ) \
    E( DOOR_3                ) \
    E( DOOR_4                ) \
    E( DOOR_BIG_1            ) \
    E( DOOR_BIG_2            ) \
    E( DOOR_5                ) \
    E( DOOR_6                ) \
    E( TRAP_DOOR_1           ) \
    E( TRAP_DOOR_2           ) \
    E( UNUSED_3              ) \
    E( BRIDGE_0              ) \
    E( BRIDGE_1              ) \
    E( BRIDGE_2              ) \
    E( INV_PASSPORT          ) \
    E( INV_COMPASS           ) \
    E( INV_HOME              ) \
    E( GEARS_1               ) \
    E( GEARS_2               ) \
    E( GEARS_3               ) \
    E( CUT_1                 ) \
    E( CUT_2                 ) \
    E( CUT_3                 ) \
    E( CUT_4                 ) \
    E( INV_PASSPORT_CLOSED   ) \
    E( INV_MAP               ) \
    E( CRYSTAL               ) \
    E( PISTOLS               ) \
    E( SHOTGUN               ) \
    E( MAGNUMS               ) \
    E( UZIS                  ) \
    E( AMMO_PISTOLS          ) \
    E( AMMO_SHOTGUN          ) \
    E( AMMO_MAGNUMS          ) \
    E( AMMO_UZIS             ) \
    E( AMMO_EXPLOSIVE        ) \
    E( MEDIKIT_SMALL         ) \
    E( MEDIKIT_BIG           ) \
    E( INV_DETAIL            ) \
    E( INV_SOUND             ) \
    E( INV_CONTROLS          ) \
    E( INV_GAMMA             ) \
    E( INV_PISTOLS           ) \
    E( INV_SHOTGUN           ) \
    E( INV_MAGNUMS           ) \
    E( INV_UZIS              ) \
    E( INV_AMMO_PISTOLS      ) \
    E( INV_AMMO_SHOTGUN      ) \
    E( INV_AMMO_MAGNUMS      ) \
    E( INV_AMMO_UZIS         ) \
    E( INV_AMMO_EXPLOSIVE    ) \
    E( INV_MEDIKIT_SMALL     ) \
    E( INV_MEDIKIT_BIG       ) \
    E( PUZZLE_1              ) \
    E( PUZZLE_2              ) \
    E( PUZZLE_3              ) \
    E( PUZZLE_4              ) \
    E( INV_PUZZLE_1          ) \
    E( INV_PUZZLE_2          ) \
    E( INV_PUZZLE_3          ) \
    E( INV_PUZZLE_4          ) \
    E( PUZZLE_HOLE_1         ) \
    E( PUZZLE_HOLE_2         ) \
    E( PUZZLE_HOLE_3         ) \
    E( PUZZLE_HOLE_4         ) \
    E( PUZZLE_DONE_1         ) \
    E( PUZZLE_DONE_2         ) \
    E( PUZZLE_DONE_3         ) \
    E( PUZZLE_DONE_4         ) \
    E( LEADBAR               ) \
    E( INV_LEADBAR           ) \
    E( MIDAS_TOUCH           ) \
    E( KEY_ITEM_1            ) \
    E( KEY_ITEM_2            ) \
    E( KEY_ITEM_3            ) \
    E( KEY_ITEM_4            ) \
    E( INV_KEY_1             ) \
    E( INV_KEY_2             ) \
    E( INV_KEY_3             ) \
    E( INV_KEY_4             ) \
    E( KEY_HOLE_1            ) \
    E( KEY_HOLE_2            ) \
    E( KEY_HOLE_3            ) \
    E( KEY_HOLE_4            ) \
    E( UNUSED_4              ) \
    E( UNUSED_5              ) \
    E( SCION_QUALOPEC        ) \
    E( SCION_DROP            ) \
    E( SCION_TARGET          ) \
    E( SCION_NATLA           ) \
    E( SCION_HOLDER          ) \
    E( UNUSED_6              ) \
    E( UNUSED_7              ) \
    E( INV_SCION             ) \
    E( EXPLOSION             ) \
    E( UNUSED_8              ) \
    E( WATER_SPLASH          ) \
    E( UNUSED_9              ) \
    E( BUBBLE                ) \
    E( UNUSED_10             ) \
    E( UNUSED_11             ) \
    E( BLOOD                 ) \
    E( UNUSED_12             ) \
    E( SMOKE                 ) \
    E( STATUE                ) \
    E( CABIN                 ) \
    E( MUTANT_EGG_SMALL      ) \
    E( RICOCHET              ) \
    E( SPARKLES              ) \
    E( MUZZLE_FLASH          ) \
    E( UNUSED_13             ) \
    E( UNUSED_14             ) \
    E( VIEW_TARGET           ) \
    E( WATERFALL             ) \
    E( UNUSED_15             ) \
    E( MUTANT_BULLET         ) \
    E( MUTANT_GRENADE        ) \
    E( UNUSED_16             ) \
    E( UNUSED_17             ) \
    E( TRAP_LAVA_PARTICLE    ) \
    E( TRAP_LAVA_EMITTER     ) \
    E( TRAP_FLAME            ) \
    E( TRAP_FLAME_EMITTER    ) \
    E( TRAP_LAVA             ) \
    E( MUTANT_EGG_BIG        ) \
    E( BOAT                  ) \
    E( EARTHQUAKE            ) \
    E( UNUSED_18             ) \
    E( UNUSED_19             ) \
    E( UNUSED_20             ) \
    E( UNUSED_21             ) \
    E( UNUSED_22             ) \
    E( BRAID                 ) \
    E( GLYPH                 )

namespace TR {

    enum {
        NO_FLOOR = -127,
        NO_ROOM  = 0xFF,
        NO_BOX   = 0xFFFF,
        ACTIVE   = 0x1F,
    };

    enum {
        ANIM_CMD_NONE       ,
        ANIM_CMD_OFFSET     ,
        ANIM_CMD_JUMP       ,
        ANIM_CMD_EMPTY      ,
        ANIM_CMD_KILL       ,
        ANIM_CMD_SOUND      ,
        ANIM_CMD_EFFECT     ,
    };

    enum Effect : int32 {
        NONE           = -1,
        ROTATE_180     ,
        FLOOR_SHAKE    ,
        LARA_NORMAL    ,
        LARA_BUBBLES   ,
        FINISH_LEVEL   ,
        EARTHQUAKE     ,
        FLOOD          ,
        UNK1           ,
        STAIRS2SLOPE   ,
        UNK3           ,
        UNK4           ,
        EXPLOSION      ,
        LARA_HANDSFREE ,
        FLIP_MAP       ,
        DRAW_RIGHTGUN  ,
        UNK5           ,
        FLICKER        ,
    };

    enum {
        SND_NO              = 2,

        SND_LANDING         = 4,
        
        SND_UNHOLSTER       = 6,
        SND_HOLSTER         = 7,
        SND_PISTOLS_SHOT    = 8,
        SND_SHOTGUN_RELOAD  = 9,
        SND_RICOCHET        = 10,
        
        SND_HIT_BEAR        = 16,
        SND_HIT_WOLF        = 20,

        SND_SCREAM          = 30,
        SND_HIT             = 31,
        
        SND_BUBBLE          = 37,
         
        SND_UZIS_SHOT       = 43,
        SND_MAGNUMS_SHOT    = 44,
        SND_SHOTGUN_SHOT    = 45,
        
        SND_UNDERWATER      = 60,

        SND_BOULDER         = 70,

        SND_FLOOD           = 81,

        SND_HIT_LION        = 85,

        SND_HIT_RAT         = 95,
        
        SND_ROCK            = 99,

        SND_EXPLOSION       = 104,

        SND_INV_SPIN        = 108,
        SND_INV_HOME        = 109,
        SND_INV_CONTROLS    = 110,
        SND_INV_SHOW        = 111,
        SND_INV_HIDE        = 112,
        SND_INV_COMPASS     = 113,
        SND_INV_WEAPON      = 114,
        SND_INV_PAGE        = 115,
        SND_HEALTH          = 116,
        
        SND_STAIRS2SLOPE    = 119,

        SND_HIT_SKATEBOY    = 132,

        SND_HIT_MUTANT      = 142,
        SND_STOMP           = 147,
        
        SND_FLAME           = 150,
        SND_DART            = 151,
        
        SND_TNT             = 170,
        SND_MUTANT_DEATH    = 171,
        SND_SECRET          = 173,
    };

    enum {
        TRACK_TITLE   = 2,
        TRACK_CAVES   = 5,
        TRACK_SECRET  = 13,
        TRACK_CISTERN = 57,
        TRACK_EGYPT   = 58,
        TRACK_MINE    = 59,
        TRACK_CUT1    = 23,
        TRACK_CUT2    = 25,
        TRACK_CUT3    = 24,
        TRACK_CUT4    = 22,
    };

    enum {
        MODEL_LARA          = 0,
        MODEL_PISTOLS       = 1,
        MODEL_SHOTGUN       = 2,
        MODEL_MAGNUMS       = 3,
        MODEL_UZIS          = 4,
        MODEL_LARA_SPEC     = 5,
    };

    enum HitType {
        HIT_DEFAULT,
        HIT_FALL,
        HIT_BLADE,
        HIT_BOULDER,
        HIT_SPIKES,
        HIT_LAVA,
        HIT_SLAM,
        HIT_REX,
    };

    enum Action : uint16 {
        ACTIVATE        ,   // activate item
        CAMERA_SWITCH   ,   // switch to camera
        FLOW            ,   // underwater flow
        FLIP            ,   // flip map
        FLIP_ON         ,   // flip on
        FLIP_OFF        ,   // flip off
        CAMERA_TARGET   ,   // look at item
        END             ,   // end level
        SOUNDTRACK      ,   // play soundtrack
        EFFECT          ,   // special effect trigger
        SECRET          ,   // secret found
    };

    namespace Limits {

        struct Limit {
            float  dy, dz, ay;
            ::Box  box;
            bool   alignAngle;
            bool   alignHoriz;
        };

        Limit SWITCH = {
            0, 376, 30,     {{-200, 0, 312}, {200, 0, 512}}, true, false
        };

        Limit SWITCH_UNDERWATER = {
            0, 100, 80,     {{-1024, -1024, -1024}, {1024, 1024, 512}}, true, true
        };

        Limit PICKUP = {
            0, -100, 180,   {{-256, -100, -256}, {256, 100, 100}}, false, true
        };

        Limit PICKUP_UNDERWATER = {
            -200, -350, 45, {{-512, -512, -512}, {512, 512, 512}}, false, true
        };

        Limit KEY_HOLE = { 
            0, 362, 30,     {{-200, 0, 312}, {200, 0, 512}}, true, true
        };

        Limit PUZZLE_HOLE = { 
            0, 327, 30,     {{-200, 0, 312}, {200, 0, 512}}, true, true
        };

        Limit BLOCK = { 
            0, -612, 30,    {{-300, 0, -692}, {300, 0, -512}}, true, false
        };

        Limit SCION = { 
            640, -202, 30,   {{-256, 540, -350}, {256, 740, -200}}, false, false
        };
    }

    struct fixed {
        uint16  L;
        int16   H;
        operator float() const {
            return H + L / 65535.0f;
        }
    };

    struct angle {
        uint16 value;

        angle() {}
        angle(float value) : value(uint16(value / (PI * 0.5f) * 16384.0f)) {}
        operator float() const { return value / 16384.0f * PI * 0.5f; };
    };

    struct Color32 {
        uint8 r, g, b, a;

        Color32() {}
        Color32(uint8 r, uint8 g, uint8 b, uint8 a) : r(r), g(g), b(b), a(a) {}
    };

    struct Color24 {
        uint8 r, g, b;

        Color24() {}
        Color24(uint8 r, uint8 g, uint8 b) : r(r), g(g), b(b) {}

        operator Color32() const { return Color32(r, g, b, 255); }
    };

    struct Color16 {
        uint16 r:5, g:5, b:5, a:1;

        operator Color24() const { return Color24((r << 3) | (r >> 2), (g << 3) | (g >> 2), (b << 3) | (b >> 2)); }
        operator Color32() const { return Color32((r << 3) | (r >> 2), (g << 3) | (g >> 2), (b << 3) | (b >> 2), -a); }
    };

    struct Vertex {
        int16 x, y, z;

        operator vec3()   const { return vec3((float)x, (float)y, (float)z); }
        operator short3() const { return *((short3*)this); }
    };

    struct Rectangle {
        uint16 vertices[4];
        uint16 texture:15, color:1;
    };

    struct Triangle {
        uint16 vertices[3];
        uint16 texture:15, color:1;
    };

    struct Tile4 {
        struct {
            uint8 a:4, b:4;
        } index[256 * 256 / 2];
    };

    struct Tile8 {
        uint8 index[256 * 256];
    };

    struct Tile32 {
        Color32 color[256 * 256]; // + 128 for mips data
    };

    struct CLUT {
        Color16 color[16];
    };

    struct Room {

        struct Info {
            int32 x, z;
            int32 yBottom, yTop;
        } info;

        struct Data {
            uint32      size;       // Number of data words (uint16_t's)

            int16       vCount;
            int16       rCount;
            int16       tCount;
            int16       sCount;

            struct Vertex {
                TR::Vertex  vertex;
                int16       lighting;   // 0 (bright) .. 0x1FFF (dark)
            } *vertices;

            Rectangle   *rectangles;
            Triangle    *triangles;

            struct Sprite {
                int16       vertex;
                int16       texture;
            } *sprites;
        } data;

        uint16  portalsCount;
        uint16  zSectors;
        uint16  xSectors;
        uint16  ambient;    // 0 (bright) .. 0x1FFF (dark)
        uint16  lightsCount;
        uint16  meshesCount;
        int16   alternateRoom;
        struct {
            uint16 water:1, unused:14, visible:1;
        } flags;

        struct Portal {
            uint16  roomIndex;
            Vertex  normal;
            Vertex  vertices[4];

            vec3 getCenter() const {
                return vec3(float( (int(vertices[0].x) + int(vertices[1].x) + int(vertices[2].x) + int(vertices[3].x)) / 4 ),
                            float( (int(vertices[0].y) + int(vertices[1].y) + int(vertices[2].y) + int(vertices[3].y)) / 4 ),
                            float( (int(vertices[0].z) + int(vertices[1].z) + int(vertices[2].z) + int(vertices[3].z)) / 4 ));
            }

            vec3 getSize() const {
                return vec3(float( abs(int(vertices[0].x) - int(vertices[2].x)) / 2 ),
                            float( abs(int(vertices[0].y) - int(vertices[2].y)) / 2 ),
                            float( abs(int(vertices[0].z) - int(vertices[2].z)) / 2 ));
            }
        } *portals;

        struct Sector {
            uint16  floorIndex; // Index into FloorData[]
            uint16  boxIndex;   // Index into Boxes[] (-1 if none)
            uint8   roomBelow;  // 255 is none
            int8    floor;      // Absolute height of floor * 256
            uint8   roomAbove;  // 255 if none
            int8    ceiling;    // Absolute height of ceiling * 256
        } *sectors;

        struct Light {
            int32   x, y, z;
            uint16  align;          // ! not exists in file !
            uint16  intensity;
            uint32  radius;
        } *lights;

        struct Mesh {
            int32   x, y, z;
            angle   rotation;
            int16   intensity;
            uint16  meshID;
            uint16  meshIndex; // index into static meshes array
        } *meshes;

        vec3 getOffset() const {
            return vec3(float(info.x), 0.0f, float(info.z));
        }
    };

    union FloorData {
        uint16 data;
        struct Command {
            uint16 func:8, sub:7, end:1;
        } cmd;
        struct Slant {
            int8 x:8, z:8;
        } slant;
        struct TriggerInfo {
            uint16  timer:8, once:1, mask:5, :2;
        } triggerInfo;
        union TriggerCommand {
            uint16 value;
            struct {
                uint16 args:10;
                Action action:5;
                uint16 end:1;
            };
            struct {
                uint16 timer:8, once:1, speed:5, :2;
            };
        } triggerCmd;

        enum {
            NONE    ,
            PORTAL  ,
            FLOOR   ,
            CEILING ,
            TRIGGER ,
            LAVA    ,
        };
    };

    struct Overlap {
        uint16 boxIndex:15, end:1;
    };

    struct Flags {
        uint16 :8, once:1, active:5, :2;
    };

    // internal mesh structure
    struct Mesh {

        struct Vertex {
            short4 coord;
            short4 normal;
        };

        TR::Vertex  center;
        uint16      radius;
        union {
            struct {
                uint16 transparent:1, reserved:15;
            };
            uint16 value;
        }           flags;
        int16       vCount;
        int16       rCount;
        int16       tCount;

        int32       offset;
        Vertex      *vertices;
        Rectangle   *rectangles;
        Triangle    *triangles;

        Mesh() : vertices(0), rectangles(0), triangles(0) {}
        ~Mesh() {
            delete[] vertices;
            delete[] rectangles;
            delete[] triangles;
        }
    };

    struct Entity {

        enum Type : int16 { NONE = -1, TR1_TYPES(DECL_ENUM) } type;

        int16   room;
        int32   x, y, z;
        angle   rotation;
        int16   intensity;
        union Flags {
            struct { uint16 unused:6, collision:1, invisible:1, once:1, active:5, reverse:1, rendered:1; };
            uint16 value;
        } flags;
    // not exists in file
        uint16  align;
        int32   modelIndex;     // index of representation in models (index + 1) or spriteSequences (-(index + 1)) arrays
        void    *controller;    // Controller implementation or NULL

        bool isEnemy() const {
            return (type >= ENEMY_DOPPELGANGER && type <= ENEMY_GIANT_MUTANT) || type == SCION_TARGET;
        }

        bool isBigEnemy() const {
            return type == ENEMY_REX || type == ENEMY_MUTANT_1 || type == ENEMY_CENTAUR;
        }

        bool isDoor() const {
            return type >= DOOR_1 && type <= DOOR_6;
        }

        bool isCollider() const {
            return isEnemy() ||
                   isDoor() ||
                   (type == DRAWBRIDGE && flags.active != ACTIVE) ||
                   (type == SCION_HOLDER);
        }

        bool isItem() const {
            return (type >= PISTOLS && type <= AMMO_UZIS) ||
                   (type >= PUZZLE_1 && type <= PUZZLE_4) ||
                   (type >= KEY_ITEM_1 && type <= KEY_ITEM_4) ||
                   (type == MEDIKIT_SMALL || type == MEDIKIT_BIG || type == SCION_QUALOPEC || type == SCION_DROP || type == SCION_NATLA || type == LEADBAR); // TODO: recheck all items
        }

        bool isActor() const {
            return type >= CUT_1 && type <= CUT_4;
        }

        bool isPuzzleHole() const {
            return type >= PUZZLE_HOLE_1 && type <= PUZZLE_HOLE_2;
        }

        bool isBlock() const {
            return type >= TR::Entity::BLOCK_1 && type <= TR::Entity::BLOCK_4;
        }

        bool isLara() const {
            return type == LARA;
        }

        bool castShadow() const {
            return isLara() || isEnemy() || isActor();
        }

        void getAxis(int &dx, int &dz) {
            switch (rotation.value / 0x4000) {
                case 0  : dx =  0; dz =  1; break;
                case 1  : dx =  1; dz =  0; break;
                case 2  : dx =  0, dz = -1; break;
                case 3  : dx = -1, dz =  0; break;
                default : dx =  0; dz =  0; break;
            }
        }

        static Type convToInv(Type type) {
            switch (type) {
                case PISTOLS       : return INV_PISTOLS;
                case SHOTGUN       : return INV_SHOTGUN;
                case MAGNUMS       : return INV_MAGNUMS;
                case UZIS          : return INV_UZIS;
 
                case AMMO_PISTOLS  : return INV_AMMO_PISTOLS;
                case AMMO_SHOTGUN  : return INV_AMMO_SHOTGUN;
                case AMMO_MAGNUMS  : return INV_AMMO_MAGNUMS;
                case AMMO_UZIS     : return INV_AMMO_UZIS;

                case MEDIKIT_SMALL : return INV_MEDIKIT_SMALL;
                case MEDIKIT_BIG   : return INV_MEDIKIT_BIG;

                case PUZZLE_1      : return INV_PUZZLE_1;
                case PUZZLE_2      : return INV_PUZZLE_2;
                case PUZZLE_3      : return INV_PUZZLE_3;
                case PUZZLE_4      : return INV_PUZZLE_4;

                case KEY_ITEM_1    : return INV_KEY_1;
                case KEY_ITEM_2    : return INV_KEY_2;
                case KEY_ITEM_3    : return INV_KEY_3;
                case KEY_ITEM_4    : return INV_KEY_4;

                case LEADBAR       : return INV_LEADBAR;
                //case TR::Entity::SCION         : return TR::Entity::INV_SCION;
                default            : return type;
            }
        }

        static Type getItemForHole(Type hole) {
            switch (hole) {
                case PUZZLE_HOLE_1 : return PUZZLE_1;   break;
                case PUZZLE_HOLE_2 : return PUZZLE_2;   break;
                case PUZZLE_HOLE_3 : return PUZZLE_3;   break;
                case PUZZLE_HOLE_4 : return PUZZLE_4;   break;
                case KEY_HOLE_1    : return KEY_ITEM_1; break;
                case KEY_HOLE_2    : return KEY_ITEM_2; break;
                case KEY_HOLE_3    : return KEY_ITEM_3; break;
                case KEY_HOLE_4    : return KEY_ITEM_4; break;
                default            : return NONE;
            }
        }

        static void fixOpaque(Type type, bool &opaque) { // to boost performance on mobile devices
            if (type >= LARA && type <= ENEMY_GIANT_MUTANT
                && type != ENEMY_REX
                && type != ENEMY_RAPTOR
                && type != ENEMY_MUTANT_1
                && type != ENEMY_MUTANT_2
                && type != ENEMY_MUTANT_3
                && type != ENEMY_CENTAUR
                && type != ENEMY_GIANT_MUTANT
                && type != ENEMY_MUMMY
                && type != ENEMY_NATLA)
                opaque = true;
            if (type == SWITCH || type == SWITCH_WATER)
                opaque = true;
            if (type == PUZZLE_HOLE_1) // LEVEL3A cogs
                opaque = false;
        }
    };

    struct Animation {
        uint32  frameOffset;    // Byte offset into Frames[] (divide by 2 for Frames[i])
        uint8   frameRate;      // Engine ticks per frame
        uint8   frameSize;      // Number of int16_t's in Frames[] used by this animation

        uint16  state;

        fixed   speed;
        fixed   accel;

        uint16  frameStart;     // First frame in this animation
        uint16  frameEnd;       // Last frame in this animation
        uint16  nextAnimation;
        uint16  nextFrame;

        uint16  scCount;
        uint16  scOffset;       // Offset into StateChanges[]

        uint16  acCount;        // How many of them to use.
        uint16  animCommand;    // Offset into AnimCommand[]
    };

    struct AnimState {
        uint16  state;
        uint16  rangesCount;    // number of ranges
        uint16  rangesOffset;   // Offset into animRanges[]
    };

    struct AnimRange {
        int16   low;            // Lowest frame that uses this range
        int16   high;           // Highest frame that uses this range
        int16   nextAnimation;  // Animation to dispatch to
        int16   nextFrame;      // Frame offset to dispatch to
    };

    struct MinMax {
        int16 minX, maxX, minY, maxY, minZ, maxZ;

        vec3 min() const { return vec3((float)minX, (float)minY, (float)minZ); }
        vec3 max() const { return vec3((float)maxX, (float)maxY, (float)maxZ); }
    };

    #pragma warning( push )
    #pragma warning( disable : 4200 ) // zero-sized array warning
    struct AnimFrame {
        MinMax  box;
        Vertex  pos;
        int16   aCount;
        uint16  angles[0];  // angle frames in YXZ order

        vec3 getAngle(int index) {
            #define ANGLE_SCALE (2.0f * PI / 1024.0f)

            uint16 b = angles[index * 2 + 0];
            uint16 a = angles[index * 2 + 1];

            return vec3(float((a & 0x3FF0) >> 4), float( ((a & 0x000F) << 6) | ((b & 0xFC00) >> 10)), float(b & 0x03FF)) * ANGLE_SCALE;
        }
    };

    struct AnimTexture {
        int16   count;        // number of texture offsets - 1 in group
        int16   textures[0];  // offsets into objectTextures[]
    };
    #pragma warning( push )

    struct Node {
        uint32  flags;
        int32   x, y, z;
    };

    struct Model {
        Entity::Type    type;
        uint16          unused;
        uint16          mCount;    
        uint16          mStart;    
        uint32          node;      
        uint32          frame;     
        uint16          animation; 
        uint16          align;     
    };

    struct StaticMesh {
        uint32  id;    
        uint16  mesh;  
        MinMax  vbox;
        MinMax  cbox;
        uint16  flags;

        void getBox(bool collision, angle rotation, ::Box &box) {
            int k = rotation.value / 0x4000;

            MinMax &m = collision ? cbox : vbox;

            ASSERT(m.minX <= m.maxX && m.minY <= m.maxY && m.minZ <= m.maxZ);

            box = ::Box(m.min(), m.max());
            box.rotate90(k);

            ASSERT(box.min.x <= box.max.x && box.min.y <= box.max.y && box.min.z <= box.max.z);
        }
    };

    struct Tile {
        uint16 index:14, undefined:1, triangle:1;
    };

    struct ObjectTexture {
        uint16  clut;
        Tile    tile;                        // tile or palette index
        uint16  attribute:15, repeat:1;      // 0 - opaque, 1 - transparent, 2 - blend additive, 
        short2  texCoord[4];

        short4 getMinMax() const {
            return {
                min(min(texCoord[0].x, texCoord[1].x), texCoord[2].x),
                min(min(texCoord[0].y, texCoord[1].y), texCoord[2].y),
                max(max(texCoord[0].x, texCoord[1].x), texCoord[2].x),
                max(max(texCoord[0].y, texCoord[1].y), texCoord[2].y),
            };
        }
    };

    struct SpriteTexture {
        uint16  clut;
        uint16  tile;
        int16   l, t, r, b;
        short2  texCoord[2];

        short4 getMinMax() const {
            return { texCoord[0].x, texCoord[0].y, texCoord[1].x, texCoord[1].y };
        }
    };

    struct SpriteSequence {
        Entity::Type    type;
        uint16          unused;
        int16           sCount;    
        int16           sStart;    
    };

    struct Camera {
        int32   x, y, z;
        union {
            int16   room;   // for camera
            int16   speed;  // for sink (underwater current)
        };
        struct {
            uint16 :8, once:1, :5, :2;
        } flags;
    };

    struct CameraFrame {
        Vertex  target;
        Vertex  pos;
        int16   fov;
        int16   roll;
    };

    struct SoundSource {
        int32   x, y, z;    // absolute position of sound source (world coordinates)
        uint16  id;         // internal sample index
        uint16  flags;      // 0x40, 0x80, or 0xC0
    };

    struct Box {
        uint32  minZ, maxZ; // Horizontal dimensions in global units
        uint32  minX, maxX;
        int16   floor;      // Height value in global units
        union {
            struct {
                uint16 index:14, block:1, blockable:1;    // Index into Overlaps[].
            };
            uint16 value;
        } overlap;

        bool contains(uint32 x, uint32 z) {
            return x >= minX && x <= maxX && z >= minZ && z <= maxZ;
        }
    };

    struct Zone {
        uint16  *ground1;
        uint16  *ground2;
        uint16  *fly;
    };

    struct SoundInfo {
        uint16 offset;
        uint16 volume;
        uint16 chance;   // If !=0 and ((rand()&0x7fff) > Chance), this sound is not played
        union {
            struct { uint16 mode:2, count:4, unused:6, camera:1, pitch:1, gain:1, :1; };
            uint16 value;
        } flags;
    };

    enum Version : uint32 {
        VER_TR1_PC  = 0x00000020,
        VER_TR1_PSX = 0x56414270,
    };

    enum LevelID : uint32 {
        LEVEL_CUSTOM,
        TITLE,
        GYM,
        LEVEL_1,
        LEVEL_2,
        LEVEL_3A,
        LEVEL_3B,
        CUTSCENE_1,
        LEVEL_4,
        LEVEL_5,
        LEVEL_6,
        LEVEL_7A,
        LEVEL_7B,
        CUTSCENE_2,
        LEVEL_8A,
        LEVEL_8B,
        LEVEL_8C,
        LEVEL_10A,
        CUTSCENE_3,
        LEVEL_10B,
        CUTSCENE_4,
        LEVEL_10C,
        LEVEL_EGYPT,
        LEVEL_CAT,
        LEVEL_END,
        LEVEL_END2,
        LEVEL_MAX,
    };

    struct {
        const char *name;
        const char *title;
        int        ambientTrack;
    } LEVEL_INFO[LEVEL_MAX] = {
        { ""         , "Custom Level",              TRACK_CAVES },
        { "TITLE"    , "",                          TRACK_TITLE },
        { "GYM"      , "Lara's Home",               0 },
        { "LEVEL1"   , "Caves",                     TRACK_CAVES },
        { "LEVEL2"   , "City of Vilcabamba",        TRACK_CAVES },
        { "LEVEL3A"  , "Lost Valley",               TRACK_CAVES },
        { "LEVEL3B"  , "Tomb of Qualopec",          TRACK_CAVES },
        { "CUT1"     , "",                          TRACK_CUT1  },
        { "LEVEL4"   , "St. Francis' Folly",        TRACK_CAVES },
        { "LEVEL5"   , "Colosseum",                 TRACK_CAVES },
        { "LEVEL6"   , "Palace Midas",              TRACK_CAVES },
        { "LEVEL7A"  , "The Cistern",               TRACK_CISTERN },
        { "LEVEL7B"  , "Tomb of Tihocan",           TRACK_CISTERN },
        { "CUT2"     , "",                          TRACK_CUT2  },
        { "LEVEL8A"  , "City of Khamoon",           TRACK_EGYPT },
        { "LEVEL8B"  , "Obelisk of Khamoon",        TRACK_EGYPT },
        { "LEVEL8C"  , "Sanctuary of the Scion",    TRACK_EGYPT },
        { "LEVEL10A" , "Natla's Mines",             TRACK_MINE  },
        { "CUT3"     , "",                          TRACK_CUT3  },
        { "LEVEL10B" , "Atlantis",                  TRACK_MINE  },
        { "CUT4"     , "",                          TRACK_CUT4  },
        { "LEVEL10C" , "The Great Pyramid",         TRACK_MINE  },
        { "EGYPT"    , "Return to Egypt",           TRACK_EGYPT },
        { "CAT"      , "Temple of the Cat",         TRACK_EGYPT },
        { "END"      , "Atlantean Stronghold",      TRACK_EGYPT },
        { "END2"     , "The Hive",                  TRACK_EGYPT },
    };

    struct Level {
        Version         version;
        LevelID         id;

        int32           tilesCount;
        Tile32          *tiles;

        uint32          unused;

        uint16          roomsCount;
        Room            *rooms;

        int32           floorsCount;
        FloorData       *floors;

        int16           meshesCount;
        Mesh            meshes[MAX_MESHES];

        int32           meshOffsetsCount;
        uint32          *meshOffsets;

        int32           animsCount;
        Animation       *anims;

        int32           statesCount;
        AnimState       *states;

        int32           rangesCount;
        AnimRange       *ranges;

        int32           commandsCount;
        int16           *commands;

        int32           nodesDataSize;
        uint32          *nodesData;

        int32           frameDataSize;
        uint16          *frameData;

        int32           modelsCount;
        Model           *models;

        int32           staticMeshesCount;
        StaticMesh      *staticMeshes;

        int32           objectTexturesCount;
        ObjectTexture   *objectTextures;

        int32           spriteTexturesCount;
        SpriteTexture   *spriteTextures;

        int32           spriteSequencesCount;
        SpriteSequence  *spriteSequences;

        int32           camerasCount;
        Camera          *cameras;

        int32           soundSourcesCount;
        SoundSource     *soundSources;

        int32           boxesCount;
        Box             *boxes;
        int32           overlapsCount;
        Overlap         *overlaps;
        Zone            zones[2];   // default and alternative

        int32           animTexturesDataSize;
        uint16          *animTexturesData;

        int32           entitiesBaseCount;
        int32           entitiesCount;
        Entity          *entities;

        Color24         *palette;
        CLUT            *cluts;
        Tile4           *tiles4;

        uint16          cameraFramesCount;
        CameraFrame     *cameraFrames;

        uint16          demoDataSize;
        uint8           *demoData;

        int16           *soundsMap;

        int32           soundsInfoCount;
        SoundInfo       *soundsInfo;

        int32           soundDataSize;
        uint8           *soundData;

        int32           soundOffsetsCount;
        uint32          *soundOffsets;
        uint32          *soundSize;

   // common
        enum Trigger : uint32 {
            ACTIVATE    ,
            PAD         ,
            SWITCH      ,
            KEY         ,
            PICKUP      ,
            HEAVY       ,
            ANTIPAD     ,
            COMBAT      ,
            DUMMY       ,
        };
    
        struct FloorInfo {
            int roomFloor, roomCeiling;
            int roomNext, roomBelow, roomAbove;
            int floor, ceiling;
            int slantX, slantZ;
            int floorIndex;
            int boxIndex;
            int lava;
            int trigCmdCount;
            Trigger trigger;
            FloorData::TriggerInfo trigInfo;
            FloorData::TriggerCommand trigCmd[MAX_TRIGGER_COMMANDS];

            vec3 getNormal() {
                return vec3((float)-slantX, -4.0f, (float)-slantZ).normal();
            }

            vec3 getSlant(const vec3 &dir) {
                // project floor normal into plane(dir, up) 
                vec3 r = vec3(dir.z, 0.0f, -dir.x); // up(0, 1, 0).cross(dir)
                vec3 n = getNormal();
                n = n - r * r.dot(n);
                // project dir into plane(dir, n)
                return n.cross(dir.cross(n)).normal();
            }
        };

        Flags   flipmap[MAX_FLIPMAP_COUNT];
        bool    secrets[MAX_SECRETS_COUNT];
        Flags   tracks[MAX_TRACKS_COUNT];

        void    *cameraController;
        void    *laraController;

        int     cutEntity;
        mat4    cutMatrix;
        bool    isDemoLevel;
        bool    isHomeLevel;
        bool    isFlipped;

        struct {
            int16 muzzleFlash;
            int16 puzzleDone[4];
            int16 weapons[4];
            int16 braid;

            struct {
                int16 passport;
                int16 passport_closed;
                int16 map;
                int16 compass;
                int16 home;
                int16 detail;
                int16 sound;
                int16 controls;
                int16 gamma;

                int16 weapon[4];
                int16 ammo[4];
                int16 medikit[2];
                int16 puzzle[4];
                int16 key[4];

                int16 leadbar;
                int16 scion;
            } inv;

            int16 glyphSeq;
        } extra;

        Level(Stream &stream) {
            int startPos = stream.pos;
            memset(this, 0, sizeof(*this));
            cutEntity = -1;
            Tile8 *tiles8 = NULL;

            int soundOffset = 0;

            stream.read(version);
            if (version != VER_TR1_PC) {
                soundOffset = version;
                stream.read(version);
            }

            if (version && version != VER_TR1_PC && version != VER_TR1_PSX) {
                LOG("unsupported level format\n"); 
                ASSERT(false); 
                memset(this, 0, sizeof(*this)); 
                return;
            }

            id = getLevelID(stream.size);

            if (version == VER_TR1_PSX) {
                uint32 offsetTexTiles;
                stream.seek(8);
                stream.read(offsetTexTiles);
            // sound offsets
                uint16 numSounds;
                stream.setPos(startPos + 22);
                stream.read(numSounds);
                stream.setPos(startPos + 2086 + numSounds * 512);
                soundOffsetsCount = numSounds;
                soundOffsets = new uint32[soundOffsetsCount];
                soundSize    = new uint32[soundOffsetsCount];
                uint32 soundDataSize = 0;
                for (int i = 0; i < soundOffsetsCount; i++) {
                    soundOffsets[i] = soundDataSize;
                    uint16 size;
                    stream.read(size);
                    soundDataSize += soundSize[i] = size * 8;
                }           
            // sound data
                stream.setPos(startPos + 2600 + numSounds * 512);
                stream.read(soundData, soundDataSize);
                stream.setPos(startPos + offsetTexTiles + 8);
            } else if (version == VER_TR1_PC) {
            // tiles
                stream.read(tiles8, stream.read(tilesCount));
            }

            if (!version /*PSX cutscene*/ || version == VER_TR1_PSX) {
                version = VER_TR1_PSX;
            // tiles
                stream.read(tiles4, tilesCount = 13);
                stream.read(cluts, 512);                
                stream.seek(0x4000);
            }
            stream.read(unused);

        // rooms
            rooms = new Room[stream.read(roomsCount)];
            for (int i = 0; i < roomsCount; i++) {
                Room &r = rooms[i];
                Room::Data &d = r.data;
            // room info
                stream.read(r.info);
            // room data
                stream.read(d.size);
                if (version == VER_TR1_PSX) stream.seek(2);
                stream.read(d.vertices, stream.read(d.vCount));

                if (version == VER_TR1_PSX)
                    for (int j = 0; j < d.vCount; j++) // convert vertex luminance from PSX to PC format
                        d.vertices[j].lighting = 0x1FFF - (d.vertices[j].lighting << 5);               

                stream.read(d.rectangles, stream.read(d.rCount));
                
                if (version == VER_TR1_PSX)
                    for (int j = 0; j < d.rCount; j++) // swap indices (quad strip -> quad list)
                        swap(d.rectangles[j].vertices[2], d.rectangles[j].vertices[3]);
                        
                stream.read(d.triangles,    stream.read(d.tCount));
                stream.read(d.sprites,      stream.read(d.sCount));
            // portals
                stream.read(r.portals,  stream.read(r.portalsCount));
            // sectors
                stream.read(r.zSectors);
                stream.read(r.xSectors);
                stream.read(r.sectors, r.zSectors * r.xSectors);
            // ambient light luminance
                stream.read(r.ambient);
            // lights
                r.lights = new Room::Light[stream.read(r.lightsCount)];
                for (int i = 0; i < r.lightsCount; i++) {
                    Room::Light &light = r.lights[i];
                    stream.read(light.x);
                    stream.read(light.y);
                    stream.read(light.z);
                    if (version == VER_TR1_PSX) {
                        uint32 intensity;
                        light.intensity = stream.read(intensity);
                    } else
                        stream.read(light.intensity);
                    stream.read(light.radius);

                    light.radius *= 2;
                }
            // meshes
                stream.read(r.meshesCount);
                r.meshes = r.meshesCount ? new Room::Mesh[r.meshesCount] : NULL;
                for (int i = 0; i < r.meshesCount; i++) {
                    Room::Mesh &m = r.meshes[i];
                    stream.read(m.x);
                    stream.read(m.y);
                    stream.read(m.z);
                    stream.read(m.rotation);
                    stream.read(m.intensity);
                    stream.read(m.meshID);
                    if (version == VER_TR1_PSX)
                        stream.read(m.meshIndex); // just an align for PSX version
                }
            // misc flags
                stream.read(r.alternateRoom);
                stream.read(r.flags);
            }

        // floors
            stream.read(floors,         stream.read(floorsCount));
        // meshes
            readMeshes(stream);
        // animations
            stream.read(anims,          stream.read(animsCount));
            stream.read(states,         stream.read(statesCount));
            stream.read(ranges,         stream.read(rangesCount));
            stream.read(commands,       stream.read(commandsCount));
            stream.read(nodesData,      stream.read(nodesDataSize));
            stream.read(frameData,      stream.read(frameDataSize));
        // models
            stream.read(modelsCount);
            models = modelsCount ? new Model[modelsCount] : NULL;
            for (int i = 0; i < modelsCount; i++) {
                Model &m = models[i];
                stream.read(m.type);
                stream.read(m.unused);
                stream.read(m.mCount);
                stream.read(m.mStart);
                stream.read(m.node);
                stream.read(m.frame);
                stream.read(m.animation);
                if (version == VER_TR1_PSX)
                    stream.seek(sizeof(m.align));
            }
            stream.read(staticMeshes, stream.read(staticMeshesCount));
        // textures & UV
            readObjectTex(stream);
            readSpriteTex(stream);
        // palette for demo levels
            if (version == VER_TR1_PC && isDemoLevel) stream.read(palette, 256);
        // cameras
            stream.read(cameras,        stream.read(camerasCount));
        // sound sources
            stream.read(soundSources,   stream.read(soundSourcesCount));
        // AI
            stream.read(boxes,          stream.read(boxesCount));

            stream.read(overlaps,       stream.read(overlapsCount));
            for (int i = 0; i < 2; i++) {
                stream.read(zones[i].ground1, boxesCount);
                stream.read(zones[i].ground2, boxesCount);
                stream.read(zones[i].fly,     boxesCount);
            }
        // animated textures
            stream.read(animTexturesData,   stream.read(animTexturesDataSize));
        // entities (enemies, items, lara etc.)
            entitiesCount = stream.read(entitiesBaseCount) + MAX_RESERVED_ENTITIES;
            entities = new Entity[entitiesCount];
            for (int i = 0; i < entitiesBaseCount; i++) {
                Entity &e = entities[i];
                stream.read(e.type);
                stream.read(e.room);
                stream.read(e.x);
                stream.read(e.y);
                stream.read(e.z);
                stream.read(e.rotation);
                stream.read(e.intensity);
                stream.read(e.flags);

                e.align = 0;
                e.controller = NULL;
                e.modelIndex = getModelIndex(e.type);

                if (e.type == Entity::CUT_1)
                    cutEntity = i;
            }
            for (int i = entitiesBaseCount; i < entitiesCount; i++) {
                entities[i].type = Entity::NONE;
                entities[i].controller = NULL;
            }

            if (version == VER_TR1_PC) {
                stream.seek(32 * 256);
            // palette for release levels
                if (!isDemoLevel) 
                    stream.read(palette, 256);
            // cinematic frames for cameras (PC)
                stream.read(cameraFrames,   stream.read(cameraFramesCount));
            // demo data
                stream.read(demoData,       stream.read(demoDataSize));
            }

        // sounds
            stream.read(soundsMap,      256);
            stream.read(soundsInfo,     stream.read(soundsInfoCount));
            if (version == VER_TR1_PC) {
                stream.read(soundData,      stream.read(soundDataSize));
                stream.read(soundOffsets,   stream.read(soundOffsetsCount));
            }
        // cinematic frames for cameras (PSX)
            if (version == VER_TR1_PSX) {
                stream.seek(4); // unknown 4 bytes always == 6
                stream.read(cameraFrames, stream.read(cameraFramesCount));
            }

            initRoomMeshes();
            initTiles(tiles4, tiles8, palette, cluts);

            //delete[] tiles4;
            //tiles4 = NULL;
            delete[] tiles8;
            tiles8 = NULL;

        // init flipmap states
            isFlipped = false;
            memset(flipmap, 0, MAX_FLIPMAP_COUNT * sizeof(flipmap[0]));
        // init secrets states
            memset(secrets, 0, MAX_SECRETS_COUNT * sizeof(secrets[0]));
        // init soundtracks states
            memset(tracks, 0, MAX_TRACKS_COUNT * sizeof(tracks[0]));

        // get special models indices
            memset(&extra, 0xFF, sizeof(extra));

            for (int i = 0; i < modelsCount; i++)
                switch (models[i].type) {
                    case Entity::MUZZLE_FLASH        : extra.muzzleFlash     = i; break;
                    case Entity::PUZZLE_DONE_1       : extra.puzzleDone[0]   = i; break;
                    case Entity::PUZZLE_DONE_2       : extra.puzzleDone[1]   = i; break;
                    case Entity::PUZZLE_DONE_3       : extra.puzzleDone[2]   = i; break;
                    case Entity::PUZZLE_DONE_4       : extra.puzzleDone[3]   = i; break;
                    case Entity::LARA_PISTOLS        : extra.weapons[0]      = i; break;
                    case Entity::LARA_SHOTGUN        : extra.weapons[1]      = i; break;
                    case Entity::LARA_MAGNUMS        : extra.weapons[2]      = i; break;
                    case Entity::LARA_UZIS           : extra.weapons[3]      = i; break;
                    case Entity::BRAID               : extra.braid           = i; break;

                    case Entity::INV_PASSPORT        : extra.inv.passport    = i; break;
                    case Entity::INV_PASSPORT_CLOSED : extra.inv.passport_closed = i; break;
                    case Entity::INV_MAP             : extra.inv.map         = i; break;
                    case Entity::INV_COMPASS         : extra.inv.compass     = i; break;
                    case Entity::INV_HOME            : extra.inv.home        = i; break;
                    case Entity::INV_DETAIL          : extra.inv.detail      = i; break;
                    case Entity::INV_SOUND           : extra.inv.sound       = i; break;
                    case Entity::INV_CONTROLS        : extra.inv.controls    = i; break;
                    case Entity::INV_GAMMA           : extra.inv.gamma       = i; break;

                    case Entity::INV_PISTOLS         : extra.inv.weapon[0]   = i; break;
                    case Entity::INV_SHOTGUN         : extra.inv.weapon[1]   = i; break;
                    case Entity::INV_MAGNUMS         : extra.inv.weapon[2]   = i; break;
                    case Entity::INV_UZIS            : extra.inv.weapon[3]   = i; break;

                    case Entity::INV_AMMO_PISTOLS    : extra.inv.ammo[0]     = i; break;
                    case Entity::INV_AMMO_SHOTGUN    : extra.inv.ammo[1]     = i; break;
                    case Entity::INV_AMMO_MAGNUMS    : extra.inv.ammo[2]     = i; break;
                    case Entity::INV_AMMO_UZIS       : extra.inv.ammo[3]     = i; break;

                    case Entity::INV_MEDIKIT_SMALL   : extra.inv.medikit[0]  = i; break;
                    case Entity::INV_MEDIKIT_BIG     : extra.inv.medikit[1]  = i; break;

                    case Entity::INV_PUZZLE_1        : extra.inv.puzzle[0]   = i; break;
                    case Entity::INV_PUZZLE_2        : extra.inv.puzzle[1]   = i; break;
                    case Entity::INV_PUZZLE_3        : extra.inv.puzzle[2]   = i; break;
                    case Entity::INV_PUZZLE_4        : extra.inv.puzzle[3]   = i; break;

                    case Entity::INV_KEY_1           : extra.inv.key[0]      = i; break;
                    case Entity::INV_KEY_2           : extra.inv.key[1]      = i; break;
                    case Entity::INV_KEY_3           : extra.inv.key[2]      = i; break;
                    case Entity::INV_KEY_4           : extra.inv.key[3]      = i; break;
                                                                         
                    case Entity::INV_LEADBAR         : extra.inv.leadbar     = i; break;
                    case Entity::INV_SCION           : extra.inv.scion       = i; break;

                    default : ;
                }
                
            for (int i = 0; i < spriteSequencesCount; i++) 
                if (spriteSequences[i].type == TR::Entity::GLYPH) {
                    extra.glyphSeq = i;
                    break;
                }
            ASSERT(extra.glyphSeq != -1);

            initCutscene();
        }

        ~Level() {
            delete[] tiles;
        // rooms
            for (int i = 0; i < roomsCount; i++) {
                Room &r = rooms[i];
                delete[] r.data.vertices;
                delete[] r.data.rectangles;
                delete[] r.data.triangles;
                delete[] r.data.sprites;
                delete[] r.portals;
                delete[] r.sectors;
                delete[] r.lights;
                delete[] r.meshes;
            }
            delete[] rooms;
            delete[] floors;
            delete[] meshOffsets;
            delete[] anims;
            delete[] states;
            delete[] ranges;
            delete[] commands;
            delete[] nodesData;
            delete[] frameData;
            delete[] models;
            delete[] staticMeshes;
            delete[] objectTextures;
            delete[] spriteTextures;
            delete[] spriteSequences;
            delete[] cameras;
            delete[] soundSources;
            delete[] boxes;
            delete[] overlaps;
            for (int i = 0; i < 2; i++) {
                delete[] zones[i].ground1;
                delete[] zones[i].ground2;
                delete[] zones[i].fly;
            }
            delete[] animTexturesData;
            delete[] entities;
            delete[] palette;
            delete[] cluts;
            delete[] tiles4;
            delete[] cameraFrames;
            delete[] demoData;
            delete[] soundsMap;
            delete[] soundsInfo;
            delete[] soundData;
            delete[] soundOffsets;
            delete[] soundSize;
        }

        LevelID getLevelID(int size) {
            isDemoLevel = false;
            isHomeLevel = false;
            switch (size) {
                case 508614  :
                case 316460  : return TITLE;
                case 1074234 :
                case 3237128 : isHomeLevel = true; return GYM;
                case 1448896 :
                case 2533634 : return LEVEL_1;
                case 2873406 : isDemoLevel = true; return LEVEL_2;
                case 1535734 :
                case 2873450 : return LEVEL_2;
                case 1630560 :
                case 2934730 : return LEVEL_3A;
                case 1506614 :
                case 2738258 : return LEVEL_3B;
                case 722402  :
                case 599840  : return CUTSCENE_1;
                case 1621970 :
                case 3030872 : return LEVEL_4;
                case 1585942 :
                case 2718540 : return LEVEL_5;
                case 1708464 :
                case 3074376 : return LEVEL_6;
                case 1696664 :
                case 2817612 : return LEVEL_7A;
                case 1733274 :
                case 3389096 : return LEVEL_7B;
                case 542960  :
                case 354320  : return CUTSCENE_2;
                case 1563356 :
                case 2880564 : return LEVEL_8A;
                case 1565630 :
                case 2886756 : return LEVEL_8B;
                case 1619360 :
                case 3105450 : return LEVEL_8C;
                case 1678018 :
                case 3224138 : return LEVEL_10A;
                case 636660  :
                case 512104  : return CUTSCENE_3;
                case 1686748 :
                case 3094020 : return LEVEL_10B;
                case 940398  :
                case 879582  : return CUTSCENE_4;
                case 1814278 :
                case 3532024 : return LEVEL_10C;
                case 3279242 : return LEVEL_EGYPT;
                case 3270998 : return LEVEL_CAT;
                case 3208018 : return LEVEL_END;
                case 3153300 : return LEVEL_END2;
            }
            return LEVEL_CUSTOM;
        }

        void initCutscene() {
        // init cutscene transform
            cutMatrix.identity();
            if (cutEntity > -1) {
                Entity &e = entities[cutEntity];
                switch (id) { // HACK to detect cutscene level number
                    case CUTSCENE_1 :
                        cutMatrix.translate(vec3(36668, float(e.y), 63180));
                        cutMatrix.rotateY(-23312.0f / float(0x4000) * PI * 0.5f);
                        break;
                    case CUTSCENE_2 :
                        cutMatrix.translate(vec3(51962, float(e.y), 53760));
                        cutMatrix.rotateY(16380.0f / float(0x4000) * PI * 0.5f);
                        break;
                    case CUTSCENE_3 :
                        isFlipped = true;
                    case CUTSCENE_4 :
                        cutMatrix.translate(vec3(float(e.x), float(e.y), float(e.z)));
                        cutMatrix.rotateY(PI * 0.5f);
                        break;
                    default : ;
                }
            }
        }

        void readMeshes(Stream &stream) {
            uint32 meshDataSize;
            stream.read(meshDataSize);
            int32 start = stream.pos;
            int32 end   = stream.pos + meshDataSize * 2;
            meshesCount = 0;
            while (stream.pos < end) {
                Mesh &mesh = meshes[meshesCount++];
                mesh.offset = stream.pos - start;

                stream.read(mesh.center);
                stream.read(mesh.radius);
                stream.read(mesh.flags);
                stream.read(mesh.vCount);

                switch (version) {
                    case VER_TR1_PC : {
                    /*  struct {
                            short3      center;
                            short2      collider;
                            short       vCount;
                            short3      vertices[vCount];
                            short       nCount;
                            short3      normals[max(0, nCount)];
                            ushort      luminance[-min(0, nCount)];
                            short       rCount;
                            Rectangle   rectangles[rCount];
                            short       tCount;
                            Triangle    triangles[tCount];
                            short       crCount;
                            Rectangle   crectangles[crCount];
                            short       ctCount;
                            Triangle    ctriangles[ctCount];
                        }; */
                        mesh.vertices = new Mesh::Vertex[mesh.vCount];
                        for (int i = 0; i < mesh.vCount; i++) {
                            short4 &c = mesh.vertices[i].coord;
                            stream.read(c.x);
                            stream.read(c.y);
                            stream.read(c.z);
                        }
                        int16 nCount;
                        stream.read(nCount);
                        ASSERT(mesh.vCount == abs(nCount));
                        for (int i = 0; i < mesh.vCount; i++) {
                            short4 &c = mesh.vertices[i].coord;
                            short4 &n = mesh.vertices[i].normal;
                            if (nCount > 0) { // normal
                                stream.read(n.x);
                                stream.read(n.y);
                                stream.read(n.z);
                                n.w = 1;
                                c.w = 0x1FFF;
                            } else { // intensity
                                stream.read(c.w);
                                n = { 0, 0, 0, 0 };
                            }
                        }

                        uint16 rCount, crCount, tCount, ctCount;

                        int tmp = stream.pos;
                        stream.seek(stream.read(rCount)  * sizeof(Rectangle));
                        stream.seek(stream.read(tCount)  * sizeof(Triangle));
                        stream.seek(stream.read(crCount) * sizeof(Rectangle));
                        stream.seek(stream.read(ctCount) * sizeof(Triangle));
                        stream.setPos(tmp);

                        mesh.rCount = rCount + crCount;
                        mesh.tCount = tCount + ctCount;

                        mesh.rectangles = mesh.rCount ? new Rectangle[mesh.rCount] : NULL;
                        mesh.triangles  = mesh.tCount ? new Triangle[mesh.tCount]  : NULL;

                        stream.seek(sizeof(uint16)); stream.raw(&mesh.rectangles[0],      rCount  * sizeof(Rectangle));
                        stream.seek(sizeof(uint16)); stream.raw(&mesh.triangles[0],       tCount  * sizeof(Triangle));
                        stream.seek(sizeof(uint16)); stream.raw(&mesh.rectangles[rCount], crCount * sizeof(Rectangle));
                        stream.seek(sizeof(uint16)); stream.raw(&mesh.triangles[tCount],  ctCount * sizeof(Triangle));
                    // add "use palette color" flags
                        for (int i = rCount; i < mesh.rCount; i++) mesh.rectangles[i].color = true;
                        for (int i = tCount; i < mesh.tCount; i++) mesh.triangles[i].color  = true;
                        break;
                    }
                    case VER_TR1_PSX : {
                    /*  struct {
                            short3      center;
                            short2      collider;
                            short       vCount;
                            short4      vertices[abs(vCount)];
                            short4      normals[max(0, vCount)];
                            ushort      luminance[-min(0, vCount)];
                            short       rCount;
                            Rectangle   rectangles[rCount];
                            short       tCount;
                            Triangle    triangles[tCount];
                        }; */
                        int nCount = mesh.vCount;
                        mesh.vCount = abs(mesh.vCount);
                        mesh.vertices = new Mesh::Vertex[mesh.vCount];

                        for (int i = 0; i < mesh.vCount; i++)
                            stream.read(mesh.vertices[i].coord);

                        for (int i = 0; i < mesh.vCount; i++) {
                            short4 &c = mesh.vertices[i].coord;
                            short4 &n = mesh.vertices[i].normal;
                            if (nCount > 0) { // normal
                                stream.read(n);
                                n.w = 1;
                                c.w = 0x1FFF;
                            } else { // intensity
                                stream.read(c.w);
                                n = { 0, 0, 0, 0 };
                            }
                        }

                        stream.read(mesh.rectangles, stream.read(mesh.rCount));
                        stream.read(mesh.triangles,  stream.read(mesh.tCount));   
                        for (int i = 0; i < mesh.rCount; i++) if (mesh.rectangles[i].texture < 256) mesh.rectangles[i].color = true;
                        for (int i = 0; i < mesh.tCount; i++) if (mesh.triangles[i].texture  < 256) mesh.triangles[i].color  = true;
                        break;
                    }
                }

                #define RECALC_ZERO_NORMALS(mesh, face, count)\
                    int fn = -1;\
                    for (int j = 0; j < count; j++) {\
                        Mesh::Vertex &v = mesh.vertices[face.vertices[j]];\
                        short4 &n = v.normal;\
                        if (!(n.x | n.y | n.z)) {\
                            if (fn > -1) {\
                                n = mesh.vertices[face.vertices[fn]].normal;\
                                continue;\
                            }\
                            vec3 o(mesh.vertices[face.vertices[0]].coord);\
                            vec3 a = o - mesh.vertices[face.vertices[1]].coord;\
                            vec3 b = o - mesh.vertices[face.vertices[2]].coord;\
                            o = b.cross(a).normal() * 16300.0f;\
                            n.x = (int)o.x;\
                            n.y = (int)o.y;\
                            n.z = (int)o.z;\
                            fn = j;\
                        }\
                    }

            // recalc zero normals
                for (int i = 0; i < mesh.rCount; i++) {
                    Rectangle &f = mesh.rectangles[i];
                    RECALC_ZERO_NORMALS(mesh, f, 4);
                }

                for (int i = 0; i < mesh.tCount; i++) {
                    Triangle &f = mesh.triangles[i];
                    RECALC_ZERO_NORMALS(mesh, f, 3);
                }

                #undef RECALC_ZERO_NORMALS

                int32 align = (stream.pos - start - mesh.offset) % 4;
                if (align) stream.seek(4 - align);
            }
            ASSERT(stream.pos - start == meshDataSize * 2);

            stream.read(meshOffsets, stream.read(meshOffsetsCount));

        // remap offsets to mesh index
            for (int i = 0; i < meshOffsetsCount; i++) {
                int index = -1;
//                if (!meshOffsets[i] && i)
//                    index = -1;
//                else
                for (int j = 0; j < meshesCount; j++)
                    if (meshes[j].offset == meshOffsets[i]) {                       
                        index = j;
                        break;
                    }
                meshOffsets[i] = index;
            }
        }

        void readObjectTex(Stream &stream) {
            #define SET_PARAMS(t, d, c) {\
                    t.clut        = c;\
                    t.tile        = d.tile;\
                    t.attribute   = d.attribute;\
                    t.texCoord[0] = { d.x0, d.y0 };\
                    t.texCoord[1] = { d.x1, d.y1 };\
                    t.texCoord[2] = { d.x2, d.y2 };\
                    t.texCoord[3] = { d.x3, d.y3 };\
                }

            stream.read(objectTexturesCount);
            objectTextures = new ObjectTexture[objectTexturesCount];
            for (int i = 0; i < objectTexturesCount; i++) {
                ObjectTexture &t = objectTextures[i];
                switch (version) {
                    case VER_TR1_PC : {                   
                        struct {
                            uint16  attribute;
                            Tile    tile;       
                            uint8   xh0, x0, yh0, y0;
                            uint8   xh1, x1, yh1, y1;
                            uint8   xh2, x2, yh2, y2;
                            uint8   xh3, x3, yh3, y3;
                        } d;
                        stream.read(d);
                        SET_PARAMS(t, d, 0);
                        break;
                    }
                    case VER_TR1_PSX : {
                        struct {
                            uint8   x0, y0;
                            uint16  clut;
                            uint8   x1, y1;
                            Tile    tile;
                            uint8   x2, y2;
                            uint16  unknown;
                            uint8   x3, y3;
                            uint16  attribute; 
                        } d;
                        stream.read(d);
                        SET_PARAMS(t, d, d.clut);
                        break;
                    }
                }
            }

            #undef SET_PARAMS
        }

        void readSpriteTex(Stream &stream) {
            #define SET_PARAMS(t, d, c) {\
                    t.clut = c;\
                    t.tile = d.tile;\
                    t.l    = d.l;\
                    t.t    = d.t;\
                    t.r    = d.r;\
                    t.b    = d.b;\
                }

            stream.read(spriteTexturesCount);
            spriteTextures = new SpriteTexture[spriteTexturesCount];
            for (int i = 0; i < spriteTexturesCount; i++) {
                SpriteTexture &t = spriteTextures[i];
                switch (version) {
                    case VER_TR1_PC : {
                        struct {
                            uint16  tile;
                            uint8   u, v;
                            uint16  w, h;
                            int16   l, t, r, b;
                        } d;
                        stream.read(d);
                        SET_PARAMS(t, d, 0);
                        t.texCoord[0] = { d.u,                       d.v                       };
                        t.texCoord[1] = { (uint8)(d.u + (d.w >> 8)), (uint8)(d.v + (d.h >> 8)) };
                        break;
                    }
                    case VER_TR1_PSX : {
                        struct {
                            int16   l, t, r, b;
                            uint16  clut;
                            uint16  tile;
                            uint8   u0, v0;
                            uint8   u1, v1;
                        } d;
                        stream.read(d);
                        SET_PARAMS(t, d, d.clut);
                        t.texCoord[0] = { d.u0, d.v0 };
                        t.texCoord[1] = { d.u1, d.v1 };
                        break;
                    }
                }
            }

            #undef SET_PARAMS

            stream.read(spriteSequences, stream.read(spriteSequencesCount));
            for (int i = 0; i < spriteSequencesCount; i++)
                spriteSequences[i].sCount = -spriteSequences[i].sCount;
        }

        void initRoomMeshes() {
            for (int i = 0; i < roomsCount; i++) {
                Room &room = rooms[i];
                for (int j = 0; j < room.meshesCount; j++)
                    room.meshes[j].meshIndex = getMeshByID(room.meshes[j].meshID);
            }
        }

        void initTiles(Tile4 *tiles4, Tile8 *tiles8, Color24 *palette, CLUT *cluts) {
            tiles = new Tile32[tilesCount];
        // convert to RGBA
            switch (version) {
                case VER_TR1_PC : {
                    ASSERT(tiles8);
                    ASSERT(palette);

                    for (int j = 0; j < 256; j++) { // Amiga -> PC color palette
                        Color24 &c = palette[j];
                        c.r <<= 2;
                        c.g <<= 2;
                        c.b <<= 2;
                    }

                    for (int i = 0; i < tilesCount; i++) {
                        Color32 *ptr = &tiles[i].color[0];
                        for (int y = 0; y < 256; y++) {
                            for (int x = 0; x < 256; x++) {
                                uint8 index = tiles8[i].index[y * 256 + x];
                                Color24 &p = palette[index];
                                ptr[x].r = p.r;
                                ptr[x].g = p.g;
                                ptr[x].b = p.b;
                                ptr[x].a = index == 0 ? 0 : 255;
                            }
                            ptr += 256;
                        }
                    }
                    break;
                }
                case VER_TR1_PSX : {
                    ASSERT(tiles4);
                    ASSERT(cluts);

                    for (int i = 0; i < objectTexturesCount; i++) {
                        ObjectTexture &t = objectTextures[i];
                        CLUT   &clut = cluts[t.clut];
                        Tile32 &dst  = tiles[t.tile.index];
                        Tile4  &src  = tiles4[t.tile.index];

                        int minX = min(min(t.texCoord[0].x, t.texCoord[1].x), t.texCoord[2].x);
                        int maxX = max(max(t.texCoord[0].x, t.texCoord[1].x), t.texCoord[2].x);
                        int minY = min(min(t.texCoord[0].y, t.texCoord[1].y), t.texCoord[2].y);
                        int maxY = max(max(t.texCoord[0].y, t.texCoord[1].y), t.texCoord[2].y);

                        for (int y = minY; y <= maxY; y++)
                            for (int x = minX; x <= maxX; x++)
                                dst.color[y * 256 + x] = clut.color[(x % 2) ? src.index[(y * 256 + x) / 2].b : src.index[(y * 256 + x) / 2].a];
                    }

                    for (int i = 0; i < spriteTexturesCount; i++) {
                        SpriteTexture &t = spriteTextures[i];
                        CLUT   &clut = cluts[t.clut];
                        Tile32 &dst  = tiles[t.tile];
                        Tile4  &src  = tiles4[t.tile];
                        
                        for (int y = t.texCoord[0].y; y <= t.texCoord[1].y; y++)
                            for (int x = t.texCoord[0].x; x <= t.texCoord[1].x; x += 2) {                           
                                dst.color[y * 256 + x + 0] = clut.color[src.index[(y * 256 + x) / 2].a];
                                dst.color[y * 256 + x + 1] = clut.color[src.index[(y * 256 + x) / 2].b];
                            }
                    }

                    break;
                }
            }
        }

    // common methods
        Color24 getColor(int texture) const {
            switch (version) {
                case VER_TR1_PC  : return palette[texture & 0xFF];
                case VER_TR1_PSX : {
                    ASSERT((texture & 0x7FFF) < 256);
                    ObjectTexture &t = objectTextures[texture & 0x7FFF];
                    int idx  = (t.texCoord[0].y * 256 + t.texCoord[0].x) / 2;
                    int part = t.texCoord[0].x % 2;
                    Tile4 &tile = tiles4[t.tile.index];
                    CLUT  &clut = cluts[t.clut];
                    return clut.color[part ? tile.index[idx].b : tile.index[idx].a];
                }
            }
            return Color24(255, 0, 255);
        }

        Stream* getSampleStream(int index) const {
            if (!soundOffsets) return NULL;
            uint8 *data = &soundData[soundOffsets[index]];
            uint32 size = 0;
            switch (version) {
                case VER_TR1_PC  : size = ((uint32*)data)[1] + 8; break; // read size from wave header
                case VER_TR1_PSX : size = soundSize[index]; break;
            }
            return new Stream(data, size);
        }

        int getMeshByID(int id) const {
            for (int i = 0; i < staticMeshesCount; i++)
                if (staticMeshes[i].id == id)
                    return i;
            ASSERT(false);
            return 0;
        }

        int16 getModelIndex(Entity::Type type) const {
            if (type == TR::Entity::ENEMY_MUTANT_2 || type == TR::Entity::ENEMY_MUTANT_3)
                type = TR::Entity::ENEMY_MUTANT_1; // hardcoded mutant models remapping

            for (int i = 0; i < modelsCount; i++)
                if (type == models[i].type)
                    return i + 1;
    
            for (int i = 0; i < spriteSequencesCount; i++)
                if (type == spriteSequences[i].type)
                    return -(i + 1);

            ASSERT(false);
            return 0;
        }

        int entityAdd(TR::Entity::Type type, int16 room, int32 x, int32 y, int32 z, angle rotation, int16 intensity) {
            for (int i = entitiesBaseCount; i < entitiesCount; i++) 
                if (entities[i].type == Entity::NONE) {
                    Entity &e = entities[i];
                    e.type          = type;
                    e.room          = room;
                    e.x             = x;
                    e.y             = y;
                    e.z             = z;
                    e.rotation      = rotation;
                    e.intensity     = intensity;
                    e.flags.value   = 0;
                    e.modelIndex    = getModelIndex(e.type);
                    e.controller    = NULL;
                    return i;
                }
            return -1;
        }

        void entityRemove(int entityIndex) {
            entities[entityIndex].type       = Entity::NONE;
            entities[entityIndex].controller = NULL;
        }

        int getNextRoom(int floorIndex) const {
            if (!floorIndex) return NO_ROOM;
            FloorData *fd = &floors[floorIndex];
        // floor data always in this order and can't be less than uint16 x 3
            if (fd->cmd.func == FloorData::FLOOR)   fd += 2; // skip floor slant info
            if (fd->cmd.func == FloorData::CEILING) fd += 2; // skip ceiling slant info
            if (fd->cmd.func == FloorData::PORTAL)  return (++fd)->data;
            return NO_ROOM;
        }

        Room::Sector& getSector(int roomIndex, int x, int z, int &dx, int &dz) const {
            ASSERT(roomIndex >= 0 && roomIndex < roomsCount);

            if (isFlipped && rooms[roomIndex].alternateRoom > -1)
                roomIndex = rooms[roomIndex].alternateRoom;

            Room &room = rooms[roomIndex];

            int sx = x - room.info.x;
            int sz = z - room.info.z;

            sx = clamp(sx, 0, room.xSectors * 1024 - 1);
            sz = clamp(sz, 0, room.zSectors * 1024 - 1);

            dx = sx % 1024;
            dz = sz % 1024;
            sx /= 1024;
            sz /= 1024;

            return room.sectors[sx * room.zSectors + sz];
        }

        Room::Sector& getSector(int roomIndex, int x, int z, int &sectorIndex) {
            ASSERT(roomIndex >= 0 && roomIndex < roomsCount);
            Room &room = rooms[roomIndex];
            x -= room.info.x;
            z -= room.info.z;
            x /= 1024;
            z /= 1024;
            return room.sectors[sectorIndex = (x * room.zSectors + z)];
        }

        Room::Sector* getSector(int &roomIndex, int x, int y, int z) const {
            ASSERT(roomIndex >= 0 && roomIndex <= roomsCount);

            Room::Sector *sector = NULL;

        // check horizontal
            while (1) { // Let's Rock!
                TR::Room &room = rooms[roomIndex];

                int sx = (x - room.info.x) >> 10;
                int sz = (z - room.info.z) >> 10;

                if (sz <= 0 || sz >= room.xSectors - 1) {
                    sx = clamp(sx, 0, room.xSectors - 1);
                    sz = clamp(sz, 1, room.zSectors - 2);
                } else
                    sx = clamp(sx, 0, room.xSectors - 1);

                sector = room.sectors + sx * room.zSectors + sz;

                int nextRoom = getNextRoom(sector->floorIndex);
                if (nextRoom == NO_ROOM)
                    break;

                roomIndex = nextRoom;
            };

        // check vertical
            while (sector->roomAbove != NO_ROOM && y < sector->ceiling * 256) {
                TR::Room &room = rooms[roomIndex = sector->roomAbove];
                sector = room.sectors + (x - room.info.x) / 1024 * room.zSectors + (z - room.info.z) / 1024;
            }

            while (sector->roomBelow != NO_ROOM && y >= sector->floor * 256) {
                TR::Room &room = rooms[roomIndex = sector->roomBelow];
                sector = room.sectors + (x - room.info.x) / 1024 * room.zSectors + (z - room.info.z) / 1024;
            }

            return sector;
        }

        void getFloorInfo(int roomIndex, int x, int y, int z, FloorInfo &info) const {
            int dx, dz;
            Room::Sector &s = getSector(roomIndex, x, z, dx, dz);

            info.roomFloor    = 256 * s.floor;
            info.roomCeiling  = 256 * s.ceiling;
            info.floor        = info.roomFloor;
            info.ceiling      = info.roomCeiling;
            info.slantX       = 0;
            info.slantZ       = 0;
            info.roomNext     = NO_ROOM;
            info.roomBelow    = s.roomBelow;
            info.roomAbove    = s.roomAbove;
            info.floorIndex   = s.floorIndex;
            info.boxIndex     = s.boxIndex;
            info.lava         = false;
            info.trigger      = Trigger::ACTIVATE;
            info.trigCmdCount = 0;

            if (s.floor == NO_FLOOR) 
                return;

            Room::Sector *sBelow = &s;
            while (sBelow->roomBelow != NO_ROOM) sBelow = &getSector(sBelow->roomBelow, x, z, dx, dz);
            info.floor = 256 * sBelow->floor;

            parseFloorData(info, sBelow->floorIndex, dx, dz);

            if (info.roomNext == NO_ROOM) {
                Room::Sector *sAbove = &s;
                while (sAbove->roomAbove != NO_ROOM) sAbove = &getSector(sAbove->roomAbove, x, z, dx, dz);
                if (sAbove != sBelow) {
                    info.ceiling = 256 * sAbove->ceiling;
                    parseFloorData(info, sAbove->floorIndex, dx, dz);
                }
            } else {
                int tmp = info.roomNext;
                getFloorInfo(tmp, x, y, z, info);
                info.roomNext = tmp;
            }


        // entities collide
            if (info.trigCmdCount) {
                int sx = x / 1024;
                int sz = z / 1024;
                int dx = x % 1024;
                int dz = z % 1024;

                for (int i = 0; i < info.trigCmdCount; i++) {
                    FloorData::TriggerCommand cmd = info.trigCmd[i];
                    if (cmd.action == Action::CAMERA_SWITCH) {
                        i++;
                        continue;
                    }
                    if (cmd.action != Action::ACTIVATE) continue;
                    
                    Entity &e = entities[cmd.args];
                    if (!e.flags.collision) continue;

                    switch (e.type) {
                        case Entity::TRAP_DOOR_1 :
                        case Entity::TRAP_DOOR_2 : {
                            int dirX, dirZ;
                            e.getAxis(dirX, dirZ);

                            int ex = e.x / 1024;
                            int ez = e.z / 1024;
                            if ((ex == sx && ez == sz) || (ex + dirX == sx && ez + dirZ == sz)) {
                                if (e.y >= y - 128 && e.y < info.floor)
                                    info.floor = e.y;
                                if (e.y  < y - 128 && e.y > info.ceiling)
                                    info.ceiling = e.y + 256;
                            }
                            break;
                        }
                        case Entity::TRAP_FLOOR  : {
                            if (sx != e.x / 1024 || sz != e.z / 1024) 
                                break;
                            int ey = e.y - 512;
                            if (ey >= y - 128 && ey < info.floor)
                                info.floor = ey;
                            if (ey  < y - 128 && ey > info.ceiling)
                                info.ceiling = ey;
                            break;
                        }
                        case Entity::DRAWBRIDGE  : {
                            if (e.flags.active != TR::ACTIVE) continue;
                            int dirX, dirZ;
                            e.getAxis(dirX, dirZ);
                            int ex = e.x / 1024;
                            int ez = e.z / 1024;

                            if ((ex - dirX * 1 == sx && ez - dirZ * 1 == sz) ||
                                (ex - dirX * 2 == sx && ez - dirZ * 2 == sz)) {
                                int ey = e.y;
                                if (ey >= y - 128 && ey < info.floor)
                                    info.floor = ey;
                                if (ey  < y - 128 && ey > info.ceiling)
                                    info.ceiling = ey + 256;
                            }
                            break;
                        }
                        case Entity::BRIDGE_0    : 
                        case Entity::BRIDGE_1    : 
                        case Entity::BRIDGE_2    : {
                            if (sx != e.x / 1024 || sz != e.z / 1024) 
                                break;

                            int s = (e.type == Entity::BRIDGE_1) ? 1 :
                                    (e.type == Entity::BRIDGE_2) ? 2 : 0;

                            int ey = e.y, sx = 0, sz = 0; 

                            if (s > 0) {
                                switch (e.rotation.value / 0x4000) { // get slantXZ by direction
                                    case 0 : sx =  s; break;
                                    case 1 : sz = -s; break;
                                    case 2 : sx = -s; break;
                                    case 3 : sz =  s; break;
                                }

                                ey -= sx * (sx > 0 ? (dx - 1024) : dx) >> 2;
                                ey -= sz * (sz > 0 ? (dz - 1024) : dz) >> 2;
                            }

                            if (y - 128 <= ey) {
                                info.floor  = ey;
                                info.slantX = sx;
                                info.slantZ = sz;
                            }
                            if (ey  < y - 128)
                                info.ceiling = ey + 64;
                            break;
                        }

                        default : ;
                    }
                }
            }
        }

        void parseFloorData(FloorInfo &info, int floorIndex, int dx, int dz) const {
            if (!floorIndex) return;

            FloorData *fd = &floors[floorIndex];
            FloorData::Command cmd;

            do {
                cmd = (*fd++).cmd;
                
                switch (cmd.func) {

                    case FloorData::PORTAL  :
                        info.roomNext = (*fd++).data;
                        break;

                    case FloorData::FLOOR   : // floor & ceiling
                    case FloorData::CEILING : { 
                        FloorData::Slant slant = (*fd++).slant;
                        int sx = (int)slant.x;
                        int sz = (int)slant.z;
                        if (cmd.func == FloorData::FLOOR) {
                            info.slantX = sx;
                            info.slantZ = sz;
                            info.floor -= sx * (sx > 0 ? (dx - 1024) : dx) >> 2;
                            info.floor -= sz * (sz > 0 ? (dz - 1024) : dz) >> 2;
                        } else {
                            info.ceiling -= sx * (sx < 0 ? (dx - 1024) : dx) >> 2; 
                            info.ceiling += sz * (sz > 0 ? (dz - 1024) : dz) >> 2; 
                        }
                        break;
                    }

                    case FloorData::TRIGGER :  {
                        info.trigger        = (Trigger)cmd.sub;
                        info.trigCmdCount   = 0;
                        info.trigInfo       = (*fd++).triggerInfo;
                        FloorData::TriggerCommand trigCmd;
                        do {
                            ASSERT(info.trigCmdCount < MAX_TRIGGER_COMMANDS);
                            trigCmd = (*fd++).triggerCmd; // trigger action
                            info.trigCmd[info.trigCmdCount++] = trigCmd;
                        } while (!trigCmd.end);
                        break;
                    }

                    case FloorData::LAVA :
                        info.lava = true;
                        break;

                    default : LOG("unknown func: %d\n", cmd.func);
                }

            } while (!cmd.end);

        }


    }; // struct Level
}

#endif
