#include <toBeSorted/file_manager.h>
#include <toBeSorted/flag_space.h>
#include <toBeSorted/unk_flag_stuff.h>

#include <toBeSorted/counters/arrow_counter.h>
#include <toBeSorted/counters/bomb_counter.h>
#include <toBeSorted/counters/counter.h>
#include <toBeSorted/counters/counters.h>
#include <toBeSorted/counters/extra_wallet_counter.h>
#include <toBeSorted/counters/key_piece_counter.h>
#include <toBeSorted/counters/rupee_counter.h>
// clang-format off
// vtable order matters
#include <toBeSorted/counters/small_key_counter.h>
#include <toBeSorted/counters/simple_counters.h>
// clang-format on
#include <toBeSorted/counters/slingshot_seed_counter.h>
#include <toBeSorted/counters/tear_counter.h>

// TODO this file matches except for the __sinit_ statit initializer,
// where this version saves and loads more vtables per chunk

extern "C" UnkFlagDefinition lbl_80511AF0[];

class DungeonflagManager;
extern DungeonflagManager *lbl_80575404;

class DungeonflagManager {
public:
    bool mShouldCommit;
    u16 mStageIndex;
    UnkFlagStuff *mFlagStuff;
    FlagSpace mFlagSpace;

    static u16 sDungeonFlags[8];
    // static DungeonflagManager *sInstance;

    void copyFromSave(s16 flag);
    void copyFromSave(u16 flagIndex);
    void setCommitFlag(u16 flag);
    DungeonflagManager();
    void setupFlagStuff();
    void setToValue(u16 flag, u16 value);
    void setFlag(u16 flag);
    u16 getDungeonFlag(u16 flag);
    bool doCommit();
};

/* 8016cda0 */ u16 SmallKeyCounter::getCommittedValue() {
    DungeonflagManager *dMgr = lbl_80575404;
    FileManager *mgr = FileManager::sInstance;
    u16 offset = dMgr->mStageIndex * 8;
    return dMgr->mFlagStuff->getCounterOrFlag(counterId, mgr->getDungeonFlagsConst() + offset, 8);
}

/*  */ u16 SmallKeyCounter::getUncommittedValue() {
    return lbl_80575404->getDungeonFlag(counterId);
}

/*  */ void SmallKeyCounter::setValue(u16 value) {
    lbl_80575404->setToValue(counterId, value);
}


SmallKeyCounter small_key_counter;
PouchExpansionCounter pouch_expansion_counter;
HeartPieceCounter heart_piece_counter;
/* 8016cf00 */ int HeartPieceCounter::checkedAdd(s32 num) {
    if (num > 0) {
        s32 uncommitted = getUncommittedValue();
        s32 newCount = uncommitted + num;
        setValue(newCount % 4);
    }
    return 0;
}

HeartContainerCounter heart_container_counter;
FaronGrasshopperCounter faron_grasshopper_counter;
WoodlandRhinoBeetleCounter woodland_rhino_beetle_counter;
DekuHornetCounter deku_hornet_counter;
SkyloftMantisCounter skyloft_mantis_counter;
VolcanicLadybugCounter volcanic_ladybug_counter;
BlessedButterflyCounter blessed_butterfly_counter;
LanayruAntCounter lanayru_ant_counter;
SandCicadaCounter sand_cicada_counter;
GerudoDragonflyCounter gerudo_dragonfly_counter;
EldinRollerCounter eldin_roller_counter;
SkyStagBeetleCounter sky_stag_beetle_counter;
StarryFireflyCounter starry_firefly_counter;
HornetLarvaeCounter hornet_larvae_counter;
BirdFeatherCounter bird_feather_counter;
TumbleweedCounter tumbleweed_counter;
LizardTailCounter lizard_tail_counter;
EldinOreCounter eldin_ore_counter;
AncientFlowerCounter ancient_flower_counter;
AmberRelicCounter amber_relic_counter;
DuskRelicCounter dusk_relic_counter;
JellyBlobCounter jelly_blob_counter;
MonsterClawCounter monster_claw_counter;
MonsterHornCounter monster_horn_counter;
OrnamentalSkullCounter ornamental_skull_counter;
EvilCrystalCounter evil_crystal_counter;
BlueBirdFeatherCounter blue_bird_feather_counter;
GoldenSkullCounter golden_skull_counter;
GoddessPlumeCounter goddess_plume_counter;
GratitudeCrystalCounter gratitude_crystal_counter;
/*
Counter *ITEM_COUNTERS[40] = {
        &rupee_counter,
        &arrow_counter,
        &bomb_counter,
        &slingshot_seed_counter,
        &tear_counter,
        &key_piece_counter,
        &small_key_counter,
        &pouch_expansion_counter,
        &heart_piece_counter,
        &heart_container_counter,
        &faron_grasshopper_counter,
        &woodland_rhino_beetle_counter,
        &deku_hornet_counter,
        &skyloft_mantis_counter,
        &volcanic_ladybug_counter,
        &blessed_butterfly_counter,
        &lanayru_ant_counter,
        &sand_cicada_counter,
        &gerudo_dragonfly_counter,
        &eldin_roller_counter,
        &sky_stag_beetle_counter,
        &starry_firefly_counter,
        &hornet_larvae_counter,
        &bird_feather_counter,
};
*/

class Counters {
public:
    Counters() {
        ITEM_COUNTERS[0] = &rupee_counter;
        ITEM_COUNTERS[1] = &arrow_counter;
        ITEM_COUNTERS[2] = &bomb_counter;
        ITEM_COUNTERS[5] = &key_piece_counter;

        ITEM_COUNTERS[24] = &tumbleweed_counter;
        ITEM_COUNTERS[25] = &lizard_tail_counter;
        ITEM_COUNTERS[26] = &eldin_ore_counter;
        ITEM_COUNTERS[27] = &ancient_flower_counter;
        ITEM_COUNTERS[28] = &amber_relic_counter;
        ITEM_COUNTERS[29] = &dusk_relic_counter;
        ITEM_COUNTERS[30] = &jelly_blob_counter;
        ITEM_COUNTERS[31] = &monster_claw_counter;
        ITEM_COUNTERS[32] = &monster_horn_counter;
        ITEM_COUNTERS[33] = &ornamental_skull_counter;
        ITEM_COUNTERS[34] = &evil_crystal_counter;
        ITEM_COUNTERS[35] = &blue_bird_feather_counter;
        ITEM_COUNTERS[36] = &golden_skull_counter;
        ITEM_COUNTERS[37] = &goddess_plume_counter;

        ITEM_COUNTERS[3] = &slingshot_seed_counter;
        ITEM_COUNTERS[4] = &tear_counter;

        ITEM_COUNTERS[6] = &small_key_counter;
        ITEM_COUNTERS[7] = &pouch_expansion_counter;
        ITEM_COUNTERS[8] = &heart_piece_counter;
        ITEM_COUNTERS[9] = &heart_container_counter;

        ITEM_COUNTERS[10] = &faron_grasshopper_counter;
        ITEM_COUNTERS[11] = &woodland_rhino_beetle_counter;
        ITEM_COUNTERS[12] = &deku_hornet_counter;
        ITEM_COUNTERS[13] = &skyloft_mantis_counter;
        ITEM_COUNTERS[14] = &volcanic_ladybug_counter;
        ITEM_COUNTERS[15] = &blessed_butterfly_counter;
        ITEM_COUNTERS[16] = &lanayru_ant_counter;
        ITEM_COUNTERS[17] = &sand_cicada_counter;
        ITEM_COUNTERS[18] = &gerudo_dragonfly_counter;
        ITEM_COUNTERS[19] = &eldin_roller_counter;
        ITEM_COUNTERS[20] = &sky_stag_beetle_counter;
        ITEM_COUNTERS[21] = &starry_firefly_counter;
        ITEM_COUNTERS[22] = &hornet_larvae_counter;
        ITEM_COUNTERS[23] = &bird_feather_counter;

        ITEM_COUNTERS[38] = &gratitude_crystal_counter;
        ITEM_COUNTERS[39] = &extra_wallet_counter;
    }

    static Counters sInstance;

    Counter *ITEM_COUNTERS[40];
};

Counters Counters::sInstance;

s32 increaseCounter(u16 counterIdx, s32 value) {
    return Counters::sInstance.ITEM_COUNTERS[counterIdx]->checkedAdd(value);
}

s32 getCounterByIndex(u16 counterIdx) {
    return Counters::sInstance.ITEM_COUNTERS[counterIdx]->getCommittedValue();
}

s32 getMaxItemCount(u16 counterIdx) {
    return Counters::sInstance.ITEM_COUNTERS[counterIdx]->getMax();
}
