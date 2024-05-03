#ifndef TEAR_COUNTER_H
#define TEAR_COUNTER_H

#include <toBeSorted/counters/counter.h>

class TearCounter : public Counter {
public:
    TearCounter();
    /* 8016E0A0 */ ~TearCounter() {}
    virtual u16 getMax() override;
};

/* 80575628 */ extern TearCounter tear_counter;

#endif
