#ifndef SMALL_KEY_COUNTER_H
#define SMALL_KEY_COUNTER_H

#include <toBeSorted/counters/counter.h>

class SmallKeyCounter : public Counter {
public:
    SmallKeyCounter() : Counter(0xf) {}
    virtual ~SmallKeyCounter() {}
    /* 8016d9b0 */ virtual u16 getMax() override {
        return 15;
    }
    virtual u16 getCommittedValue() override;
    virtual u16 getUncommittedValue() override;
    virtual void setValue(u16 num) override;
};

#endif
