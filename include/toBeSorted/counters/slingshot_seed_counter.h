#ifndef SLINGSHOT_SEED_COUNTER_H
#define SLINGSHOT_SEED_COUNTER_H

#include <toBeSorted/counters/counter.h>

class SlingshotSeedCounter : public Counter {
public:
    SlingshotSeedCounter();
    /* 8016E120 */ ~SlingshotSeedCounter() {}
    virtual u16 getMax() override;
};

/* 80575630 */ extern SlingshotSeedCounter slingshot_seed_counter;

#endif
