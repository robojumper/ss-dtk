#ifndef RUPEE_COUNTER_H
#define RUPEE_COUNTER_H

#include <toBeSorted/counters/counter.h>

class RupeeCounter : public Counter {
public:
    RupeeCounter();
    /* 8016DEF0 */ ~RupeeCounter() {}
    virtual u16 getMax() override;
};

/* 80575610 */ extern RupeeCounter rupee_counter;

#endif
