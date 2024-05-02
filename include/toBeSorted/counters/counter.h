#ifndef COUNTER_H
#define COUNTER_H

#include <common.h>

class Counter {
public:
    Counter(u16 id): counterId(id) {}
    virtual ~Counter() {};
    /* 8016cc40 */ virtual s32 checkedAdd(s32 num) {
        s32 uncommitted = getUncommittedValue();
        s32 max = getMax();
        s32 result = uncommitted + num;
        if (result < 0) {
            setValue(0);
        } else if (result < max) {
            setValue(result);
        } else {
            setValue(max);
        }

        if (result < 0) {
            return result;
        }

        return result <= max ? 0 : (result - max);
    }
    virtual u16 getCommittedValue() {
        return 0;
    }
    virtual u16 getMax() = 0;
    virtual u16 getUncommittedValue() {
        return 0;
    }
    virtual void setValue(u16 num) {
        return;
    }

    u16 counterId;
};

s32 increaseCounter(u16 counterIdx, s32 value);
s32 getCounterByIndex(u16 counterIdx);
s32 getMaxItemCount(u16 counterIdx);


#endif COUNTER_H
