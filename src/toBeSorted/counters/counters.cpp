#include <toBeSorted/counters/counter.h>
#include <toBeSorted/counters/extra_wallet_counter.h>

// TODO: This code should look very differently
// The main problems here are:
// * __sinit_ doesn't use relocations for individual counter vtables,
//   but instead a single relocation from which the vtables are offset
// * We get a Counter vtable that doesn't seem to exist in the original
//   binary
// * The original code almost certainly used a single class to expose
//   the increaseCounter/... functions

class SmallKeyCounter : public Counter {
public:
    SmallKeyCounter(): Counter(0xf) { }
    ~SmallKeyCounter() {}
    virtual u16 getCommittedValue();
    virtual u16 getMax() override;
    virtual u16 getUncommittedValue();
    virtual void setValue(u16 num);
};

class PouchExpansionCounter : public Counter {
public:
    PouchExpansionCounter(): Counter(0x1ea) { }
    /* 8016ce80 */ ~PouchExpansionCounter() {}
    /* 8016d9a0 */ virtual u16 getMax() override;
};

class HeartPieceCounter : public Counter {
public:
    HeartPieceCounter(): Counter(0x1e0) { }
    /* 8016cec0 */ ~HeartPieceCounter() {}
    /* 8016d990 */ virtual u16 getMax() override;
    /* 8016cf00 */ virtual s32 checkedAdd(s32 num) override;
};

class HeartContainerCounter : public Counter {
public:
    HeartContainerCounter(): Counter(0x1fd) { }
    /* 8016cf90 */ ~HeartContainerCounter() {}
    /* 8016d980 */ virtual u16 getMax() override;
};

class FaronGrasshopperCounter : public Counter {
public:
    FaronGrasshopperCounter(): Counter(0x1b9) { }
    /* 8016cfd0 */ ~FaronGrasshopperCounter() {}
    /* 8016d970 */ virtual u16 getMax() override;
};

class WoodlandRhinoBeetleCounter : public Counter {
public:
    WoodlandRhinoBeetleCounter(): Counter(0x1ba) { }
    /* 8016d010 */ ~WoodlandRhinoBeetleCounter() {}
    /* 8016d950 */ virtual u16 getMax() override;
};

class DekuHornetCounter : public Counter {
public:
    DekuHornetCounter(): Counter(0x1bb) { }
    /* 8016d050 */ ~DekuHornetCounter() {}
    /* 8016d960 */ virtual u16 getMax() override;
};

class SkyloftMantisCounter : public Counter {
public:
    SkyloftMantisCounter(): Counter(0x1bc) { }
    /* 8016d090 */ ~SkyloftMantisCounter() {}
    /* 8016d940 */ virtual u16 getMax() override;
};

class VolcanicLadybugCounter : public Counter {
public:
    VolcanicLadybugCounter(): Counter(0x1bd) { }
    /* 8016d0d0 */ ~VolcanicLadybugCounter() {}
    /* 8016d930 */ virtual u16 getMax() override;
};

class BlessedButterflyCounter : public Counter {
public:
    BlessedButterflyCounter(): Counter(0x1be) { }
    /* 8016d110 */ ~BlessedButterflyCounter() {}
    /* 8016d920 */ virtual u16 getMax() override;
};

class LanayruAntCounter : public Counter {
public:
    LanayruAntCounter(): Counter(0x1bf) { }
    /* 8016d150 */ ~LanayruAntCounter() {}
    /* 8016d910 */ virtual u16 getMax() override;
};

class SandCicadaCounter : public Counter {
public:
    SandCicadaCounter(): Counter(0x1c0) { }
    /* 8016d190 */ ~SandCicadaCounter() {}
    /* 8016d900 */ virtual u16 getMax() override;
};

class GerudoDragonflyCounter : public Counter {
public:
    GerudoDragonflyCounter(): Counter(0x1c1) { }
    /* 8016d1d0 */ ~GerudoDragonflyCounter() {}
    /* 8016d8f0 */ virtual u16 getMax() override;
};

class EldinRollerCounter : public Counter {
public:
    EldinRollerCounter(): Counter(0x1c2) { }
    /* 8016d210 */ ~EldinRollerCounter() {}
    /* 8016d8e0 */ virtual u16 getMax() override;
};

class SkyStagBeetleCounter : public Counter {
public:
    SkyStagBeetleCounter(): Counter(0x1c3) { }
    /* 8016d250 */ ~SkyStagBeetleCounter() {}
    /* 8016d8d0 */ virtual u16 getMax() override;
};

class StarryFireflyCounter : public Counter {
public:
    StarryFireflyCounter(): Counter(0x1c4) { }
    /* 8016d290 */ ~StarryFireflyCounter() {}
    /* 8016d8c0 */ virtual u16 getMax() override;
};

class HornetLarvaeCounter : public Counter {
public:
    HornetLarvaeCounter(): Counter(0x1a5) { }
    /* 8016d2d0 */ ~HornetLarvaeCounter() {}
    /* 8016d8b0 */ virtual u16 getMax() override;
};

class BirdFeatherCounter : public Counter {
public:
    BirdFeatherCounter(): Counter(0x1a6) { }
    /* 8016d310 */ ~BirdFeatherCounter() {}
    /* 8016d8a0 */ virtual u16 getMax() override;
};

/** TIIIMM!! */
class TumbleweedCounter : public Counter {
public:
    TumbleweedCounter(): Counter(0x1a7) { }
    /* 8016d350 */ ~TumbleweedCounter() {}
    /* 8016d890 */ virtual u16 getMax() override;
};

class LizardTailCounter : public Counter {
public:
    LizardTailCounter(): Counter(0x1a8) { }
    /* 8016d390 */ ~LizardTailCounter() {}
    /* 8016d880 */ virtual u16 getMax() override;
};

class EldinOreCounter : public Counter {
public:
    EldinOreCounter(): Counter(0x1a9) { }
    /* 8016d3d0 */ ~EldinOreCounter() {}
    /* 8016d870 */ virtual u16 getMax() override;
};

class AncientFlowerCounter : public Counter {
public:
    AncientFlowerCounter(): Counter(0x1aa) { }
    /* 8016d410 */ ~AncientFlowerCounter() {}
    /* 8016d860 */ virtual u16 getMax() override;
};

class AmberRelicCounter : public Counter {
public:
    AmberRelicCounter(): Counter(0x1ab) { }
    /* 8016d450 */ ~AmberRelicCounter() {}
    /* 8016d850 */ virtual u16 getMax() override;
};

class DuskRelicCounter : public Counter {
public:
    DuskRelicCounter(): Counter(0x1ac) { }
    /* 8016d490 */ ~DuskRelicCounter() {}
    /* 8016d840 */ virtual u16 getMax() override;
};

class JellyBlobCounter : public Counter {
public:
    JellyBlobCounter(): Counter(0x1ad) { }
    /* 8016d4d0 */ ~JellyBlobCounter() {}
    /* 8016d830 */ virtual u16 getMax() override;
};

class MonsterClawCounter : public Counter {
public:
    MonsterClawCounter(): Counter(0x1ae) { }
    /* 8016d510 */ ~MonsterClawCounter() {}
    /* 8016d820 */ virtual u16 getMax() override;
};

class MonsterHornCounter : public Counter {
public:
    MonsterHornCounter(): Counter(0x1af) { }
    /* 8016d550 */ ~MonsterHornCounter() {}
    /* 8016d810 */ virtual u16 getMax() override;
};

class OrnamentalSkullCounter : public Counter {
public:
    OrnamentalSkullCounter(): Counter(0x1b0) { }
    /* 8016d590 */ ~OrnamentalSkullCounter() {}
    /* 8016d800 */ virtual u16 getMax() override;
};

class EvilCrystalCounter : public Counter {
public:
    EvilCrystalCounter(): Counter(0x1b1) { }
    /* 8016d5d0 */ ~EvilCrystalCounter() {}
    /* 8016d7f0 */ virtual u16 getMax() override;
};

class BlueBirdFeatherCounter : public Counter {
public:
    BlueBirdFeatherCounter(): Counter(0x1b2) { }
    /* 8016d610 */ ~BlueBirdFeatherCounter() {}
    /* 8016d7e0 */ virtual u16 getMax() override;
};

class GoldenSkullCounter : public Counter {
public:
    GoldenSkullCounter(): Counter(0x1b3) { }
    /* 8016d650 */ ~GoldenSkullCounter() {}
    /* 8016d7d0 */ virtual u16 getMax() override;
};

class GoddessPlumeCounter : public Counter {
public:
    GoddessPlumeCounter(): Counter(0x1b4) { }
    /* 8016d690 */ ~GoddessPlumeCounter() {}
    /* 8016d7c0 */ virtual u16 getMax() override;
};

class GratitudeCrystalCounter : public Counter {
public:
    GratitudeCrystalCounter(): Counter(0x1f6) { }
    /* 8016d6d0 */ ~GratitudeCrystalCounter() {}
    /* 8016d7b0 */ virtual u16 getMax() override;
};


u16 SmallKeyCounter::getCommittedValue() {

}
u16 SmallKeyCounter::getUncommittedValue() {
    
}
void SmallKeyCounter::setValue(u16 num) {
    
}

SmallKeyCounter small_key_counter;
PouchExpansionCounter pouch_expansion_counter;
HeartPieceCounter heart_piece_counter;

/* 8016cf00 */ s32 HeartPieceCounter::checkedAdd(s32 num) {
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
        // 2, 5
        ITEM_COUNTER_MANAGERS[24] = &tumbleweed_counter;
        ITEM_COUNTER_MANAGERS[25] = &lizard_tail_counter;
        ITEM_COUNTER_MANAGERS[26] = &eldin_ore_counter;
        ITEM_COUNTER_MANAGERS[27] = &ancient_flower_counter;
        ITEM_COUNTER_MANAGERS[28] = &amber_relic_counter;
        ITEM_COUNTER_MANAGERS[29] = &dusk_relic_counter;
        ITEM_COUNTER_MANAGERS[30] = &jelly_blob_counter;
        ITEM_COUNTER_MANAGERS[31] = &monster_claw_counter;
        ITEM_COUNTER_MANAGERS[32] = &monster_horn_counter;
        ITEM_COUNTER_MANAGERS[33] = &ornamental_skull_counter;
        ITEM_COUNTER_MANAGERS[34] = &evil_crystal_counter;
        ITEM_COUNTER_MANAGERS[35] = &blue_bird_feather_counter;
        ITEM_COUNTER_MANAGERS[36] = &golden_skull_counter;
        ITEM_COUNTER_MANAGERS[37] = &goddess_plume_counter;

        // 3, 4

        ITEM_COUNTER_MANAGERS[6] = &small_key_counter;
        ITEM_COUNTER_MANAGERS[7] = &pouch_expansion_counter;
        ITEM_COUNTER_MANAGERS[10] = &faron_grasshopper_counter;
        ITEM_COUNTER_MANAGERS[11] = &woodland_rhino_beetle_counter;
        ITEM_COUNTER_MANAGERS[12] = &deku_hornet_counter;
        ITEM_COUNTER_MANAGERS[13] = &skyloft_mantis_counter;
        ITEM_COUNTER_MANAGERS[14] = &volcanic_ladybug_counter;
        ITEM_COUNTER_MANAGERS[15] = &blessed_butterfly_counter;
        ITEM_COUNTER_MANAGERS[16] = &lanayru_ant_counter;
        ITEM_COUNTER_MANAGERS[17] = &sand_cicada_counter;
        ITEM_COUNTER_MANAGERS[18] = &gerudo_dragonfly_counter;
        ITEM_COUNTER_MANAGERS[19] = &eldin_ore_counter;
        ITEM_COUNTER_MANAGERS[20] = &sky_stag_beetle_counter;
        ITEM_COUNTER_MANAGERS[21] = &starry_firefly_counter;
        ITEM_COUNTER_MANAGERS[22] = &hornet_larvae_counter;
        ITEM_COUNTER_MANAGERS[23] = &bird_feather_counter;

        ITEM_COUNTER_MANAGERS[38] = &gratitude_crystal_counter;
        ITEM_COUNTER_MANAGERS[39] = &extra_wallet_counter;
    }

    Counter *ITEM_COUNTER_MANAGERS[40];
    /*
    static s32 increaseCounter(u16 counterIdx, s32 value);
    static s32 getCounterByIndex(u16 counterIdx);
    static s32 getMaxItemCount(u16 counterIdx);
    */
};

Counters counters;

s32 increaseCounter(u16 counterIdx, s32 value) {
    counters.ITEM_COUNTER_MANAGERS[counterIdx]->checkedAdd(value);
}

s32 getCounterByIndex(u16 counterIdx) {
    return counters.ITEM_COUNTER_MANAGERS[counterIdx]->getCommittedValue();
}

s32 getMaxItemCount(u16 counterIdx) {
    return counters.ITEM_COUNTER_MANAGERS[counterIdx]->getMax();
}

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
    return 0xf;
};

// static Counter *ITEM_COUNTER_MANAGERS[40];

// TODO this is in .bss, so it ought to be
// zero-initialized, but how does the automatically generated __sinit
// manage to write the values then?
/*
static Counter *ITEM_COUNTER_MANAGERS[40] = {
    0, // rupee
    0, // arrow
    0, // bomb
    0, // tear
    0, // seed
    0, // key piece
    &small_key_counter,
    0, // pouch expansion
    0, // heart piece
    0, // heart container
    0, // faron hopper
    0, // woodland rhino
    0, // deku hornet
    &skyloft_mantis_counter,
    &volcanic_ladybug_counter,
    0, // 🙏 butterfly
    0, // lanayru ant
    0, // sand cicada
    0, // gerudo dragonfly
    0, // eldin roller
    0, // sky stag
    0, // starry firefly
    0, // hornet lavae
    0, // bird feather
    0, // tim
    0, // lizard tail
    0, // eldin ore
    0, // ancient flower
    0, // amber relic
    0, // dusk relic
    0, // jelly blob
    0, // monster claw
    0, // monster horn
    0, // skull
    0, // evil crystal
    0, // blue bird feather
    0, // golden skull
    &goddess_plume_counter,
    &gratitude_crystal_counter,
    &extra_wallet_counter,
};
*/
