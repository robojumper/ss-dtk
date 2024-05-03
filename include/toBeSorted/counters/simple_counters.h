#ifndef SIMPLE_COUNTERS_H
#define SIMPLE_COUNTERS_H

#include <toBeSorted/counters/counter.h>

class PouchExpansionCounter : public Counter {
public:
    PouchExpansionCounter() : Counter(0x1ea) {}
    /* 8016ce80 */ ~PouchExpansionCounter() {}
    /* 8016d9a0 */ virtual u16 getMax() override;
};

class HeartPieceCounter : public Counter {
public:
    HeartPieceCounter() : Counter(0x1e0) {}
    /* 8016cec0 */ ~HeartPieceCounter() {}
    /* 8016d990 */ virtual u16 getMax() override;
    /* 8016cf00 */ virtual s32 checkedAdd(s32 num) override;
};

class HeartContainerCounter : public Counter {
public:
    HeartContainerCounter() : Counter(0x1fd) {}
    /* 8016cf90 */ ~HeartContainerCounter() {}
    /* 8016d980 */ virtual u16 getMax() override;
};

class FaronGrasshopperCounter : public Counter {
public:
    FaronGrasshopperCounter() : Counter(0x1b9) {}
    /* 8016cfd0 */ ~FaronGrasshopperCounter() {}
    /* 8016d970 */ virtual u16 getMax() override;
};

class WoodlandRhinoBeetleCounter : public Counter {
public:
    WoodlandRhinoBeetleCounter() : Counter(0x1ba) {}
    /* 8016d010 */ ~WoodlandRhinoBeetleCounter() {}
    /* 8016d950 */ virtual u16 getMax() override;
};

class DekuHornetCounter : public Counter {
public:
    DekuHornetCounter() : Counter(0x1bb) {}
    /* 8016d050 */ ~DekuHornetCounter() {}
    /* 8016d960 */ virtual u16 getMax() override;
};

class SkyloftMantisCounter : public Counter {
public:
    SkyloftMantisCounter() : Counter(0x1bc) {}
    /* 8016d090 */ ~SkyloftMantisCounter() {}
    /* 8016d940 */ virtual u16 getMax() override;
};

class VolcanicLadybugCounter : public Counter {
public:
    VolcanicLadybugCounter() : Counter(0x1bd) {}
    /* 8016d0d0 */ ~VolcanicLadybugCounter() {}
    /* 8016d930 */ virtual u16 getMax() override;
};

class BlessedButterflyCounter : public Counter {
public:
    BlessedButterflyCounter() : Counter(0x1be) {}
    /* 8016d110 */ ~BlessedButterflyCounter() {}
    /* 8016d920 */ virtual u16 getMax() override;
};

class LanayruAntCounter : public Counter {
public:
    LanayruAntCounter() : Counter(0x1bf) {}
    /* 8016d150 */ ~LanayruAntCounter() {}
    /* 8016d910 */ virtual u16 getMax() override;
};

class SandCicadaCounter : public Counter {
public:
    SandCicadaCounter() : Counter(0x1c0) {}
    /* 8016d190 */ ~SandCicadaCounter() {}
    /* 8016d900 */ virtual u16 getMax() override;
};

class GerudoDragonflyCounter : public Counter {
public:
    GerudoDragonflyCounter() : Counter(0x1c1) {}
    /* 8016d1d0 */ ~GerudoDragonflyCounter() {}
    /* 8016d8f0 */ virtual u16 getMax() override;
};

class EldinRollerCounter : public Counter {
public:
    EldinRollerCounter() : Counter(0x1c2) {}
    /* 8016d210 */ ~EldinRollerCounter() {}
    /* 8016d8e0 */ virtual u16 getMax() override;
};

class SkyStagBeetleCounter : public Counter {
public:
    SkyStagBeetleCounter() : Counter(0x1c3) {}
    /* 8016d250 */ ~SkyStagBeetleCounter() {}
    /* 8016d8d0 */ virtual u16 getMax() override;
};

class StarryFireflyCounter : public Counter {
public:
    StarryFireflyCounter() : Counter(0x1c4) {}
    /* 8016d290 */ ~StarryFireflyCounter() {}
    /* 8016d8c0 */ virtual u16 getMax() override;
};

class HornetLarvaeCounter : public Counter {
public:
    HornetLarvaeCounter() : Counter(0x1a5) {}
    /* 8016d2d0 */ ~HornetLarvaeCounter() {}
    /* 8016d8b0 */ virtual u16 getMax() override;
};

class BirdFeatherCounter : public Counter {
public:
    BirdFeatherCounter() : Counter(0x1a6) {}
    /* 8016d310 */ ~BirdFeatherCounter() {}
    /* 8016d8a0 */ virtual u16 getMax() override;
};

/** TIIIMM!! */
class TumbleweedCounter : public Counter {
public:
    TumbleweedCounter() : Counter(0x1a7) {}
    /* 8016d350 */ ~TumbleweedCounter() {}
    /* 8016d890 */ virtual u16 getMax() override;
};

class LizardTailCounter : public Counter {
public:
    LizardTailCounter() : Counter(0x1a8) {}
    /* 8016d390 */ ~LizardTailCounter() {}
    /* 8016d880 */ virtual u16 getMax() override;
};

class EldinOreCounter : public Counter {
public:
    EldinOreCounter() : Counter(0x1a9) {}
    /* 8016d3d0 */ ~EldinOreCounter() {}
    /* 8016d870 */ virtual u16 getMax() override;
};

class AncientFlowerCounter : public Counter {
public:
    AncientFlowerCounter() : Counter(0x1aa) {}
    /* 8016d410 */ ~AncientFlowerCounter() {}
    /* 8016d860 */ virtual u16 getMax() override;
};

class AmberRelicCounter : public Counter {
public:
    AmberRelicCounter() : Counter(0x1ab) {}
    /* 8016d450 */ ~AmberRelicCounter() {}
    /* 8016d850 */ virtual u16 getMax() override;
};

class DuskRelicCounter : public Counter {
public:
    DuskRelicCounter() : Counter(0x1ac) {}
    /* 8016d490 */ ~DuskRelicCounter() {}
    /* 8016d840 */ virtual u16 getMax() override;
};

class JellyBlobCounter : public Counter {
public:
    JellyBlobCounter() : Counter(0x1ad) {}
    /* 8016d4d0 */ ~JellyBlobCounter() {}
    /* 8016d830 */ virtual u16 getMax() override;
};

class MonsterClawCounter : public Counter {
public:
    MonsterClawCounter() : Counter(0x1ae) {}
    /* 8016d510 */ ~MonsterClawCounter() {}
    /* 8016d820 */ virtual u16 getMax() override;
};

class MonsterHornCounter : public Counter {
public:
    MonsterHornCounter() : Counter(0x1af) {}
    /* 8016d550 */ ~MonsterHornCounter() {}
    /* 8016d810 */ virtual u16 getMax() override;
};

class OrnamentalSkullCounter : public Counter {
public:
    OrnamentalSkullCounter() : Counter(0x1b0) {}
    /* 8016d590 */ ~OrnamentalSkullCounter() {}
    /* 8016d800 */ virtual u16 getMax() override;
};

class EvilCrystalCounter : public Counter {
public:
    EvilCrystalCounter() : Counter(0x1b1) {}
    /* 8016d5d0 */ ~EvilCrystalCounter() {}
    /* 8016d7f0 */ virtual u16 getMax() override;
};

class BlueBirdFeatherCounter : public Counter {
public:
    BlueBirdFeatherCounter() : Counter(0x1b2) {}
    /* 8016d610 */ ~BlueBirdFeatherCounter() {}
    /* 8016d7e0 */ virtual u16 getMax() override;
};

class GoldenSkullCounter : public Counter {
public:
    GoldenSkullCounter() : Counter(0x1b3) {}
    /* 8016d650 */ ~GoldenSkullCounter() {}
    /* 8016d7d0 */ virtual u16 getMax() override;
};

class GoddessPlumeCounter : public Counter {
public:
    GoddessPlumeCounter() : Counter(0x1b4) {}
    /* 8016d690 */ ~GoddessPlumeCounter() {}
    /* 8016d7c0 */ virtual u16 getMax() override;
};

class GratitudeCrystalCounter : public Counter {
public:
    GratitudeCrystalCounter() : Counter(0x1f6) {}
    /* 8016d6d0 */ ~GratitudeCrystalCounter() {}
    /* 8016d7b0 */ virtual u16 getMax() override;
};

#endif
