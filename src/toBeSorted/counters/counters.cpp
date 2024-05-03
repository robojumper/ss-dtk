#include <toBeSorted/counters/counter.h>
#include <toBeSorted/counters/small_key_counter.h>
#include <toBeSorted/counters/arrow_counter.h>
#include <toBeSorted/counters/rupee_counter.h>
#include <toBeSorted/counters/bomb_counter.h>
#include <toBeSorted/counters/tear_counter.h>
#include <toBeSorted/counters/key_piece_counter.h>
#include <toBeSorted/counters/slingshot_seed_counter.h>
#include <toBeSorted/counters/extra_wallet_counter.h>
#include <toBeSorted/counters/simple_counters.h>
#include <toBeSorted/counters/counters.h>


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

class Counters {
public:
    Counters() {

        ITEM_COUNTERS[0] = &rupee_counter;
        ITEM_COUNTERS[1] = &arrow_counter;
        ITEM_COUNTERS[2] = &bomb_counter;
        ITEM_COUNTERS[3] = &key_piece_counter;

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


        ITEM_COUNTERS[4] = &tear_counter;
        ITEM_COUNTERS[5] = &slingshot_seed_counter;

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
        ITEM_COUNTERS[19] = &eldin_ore_counter;
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

// TODO: It is extremely suspicious that these generate in the
// exact inverse order of the dtors and the same order of the vtables

/* 8016d7b0 */ u16 GratitudeCrystalCounter::getMax() {
    return 127;
};

/* 8016d7c0 */ u16 GoddessPlumeCounter::getMax() {
    return 99;
};

/* 8016d7d0 */ u16 GoldenSkullCounter::getMax() {
    return 99;
};

/* 8016d7e0 */ u16 BlueBirdFeatherCounter::getMax() {
    return 99;
};

/* 8016d7f0 */ u16 EvilCrystalCounter::getMax() {
    return 99;
};

/* 8016d800 */ u16 OrnamentalSkullCounter::getMax() {
    return 99;
};

/* 8016d810 */ u16 MonsterHornCounter::getMax() {
    return 99;
};

/* 8016d820 */ u16 MonsterClawCounter::getMax() {
    return 99;
};

/* 8016d830 */ u16 JellyBlobCounter::getMax() {
    return 99;
};

/* 8016d840 */ u16 DuskRelicCounter::getMax() {
    return 99;
};

/* 8016d850 */ u16 AmberRelicCounter::getMax() {
    return 99;
};

/* 8016d860 */ u16 AncientFlowerCounter::getMax() {
    return 99;
};

/* 8016d870 */ u16 EldinOreCounter::getMax() {
    return 99;
};

/* 8016d880 */ u16 LizardTailCounter::getMax() {
    return 99;
};

/* 8016d890 */ u16 TumbleweedCounter::getMax() {
    return 99;
};

/* 8016d8a0 */ u16 BirdFeatherCounter::getMax() {
    return 99;
};

/* 8016d8b0 */ u16 HornetLarvaeCounter::getMax() {
    return 99;
};

/* 8016d8c0 */ u16 StarryFireflyCounter::getMax() {
    return 99;
};

/* 8016d8d0 */ u16 SkyStagBeetleCounter::getMax() {
    return 99;
};

/* 8016d8e0 */ u16 EldinRollerCounter::getMax() {
    return 99;
};

/* 8016d8f0 */ u16 GerudoDragonflyCounter::getMax() {
    return 99;
};

/* 8016d900 */ u16 SandCicadaCounter::getMax() {
    return 99;
};

/* 8016d910 */ u16 LanayruAntCounter::getMax() {
    return 99;
};

/* 8016d920 */ u16 BlessedButterflyCounter::getMax() {
    return 99;
};

/* 8016d930 */ u16 VolcanicLadybugCounter::getMax() {
    return 99;
};

/* 8016d940 */ u16 SkyloftMantisCounter::getMax() {
    return 99;
};

/* 8016d950 */ u16 DekuHornetCounter::getMax() {
    return 99;
};

/* 8016d960 */ u16 WoodlandRhinoBeetleCounter::getMax() {
    return 99;
};

/* 8016d970 */ u16 FaronGrasshopperCounter::getMax() {
    return 99;
}

/* 8016d980 */ u16 HeartContainerCounter::getMax() {
    return 24;
}

/* 8016d990 */ u16 HeartPieceCounter::getMax() {
    return 3;
}

/* 8016D9A0 */ u16 PouchExpansionCounter::getMax() {
    return 7;
}

/* 8016D9B0 */ u16 SmallKeyCounter::getMax() {
    return 15;
};
