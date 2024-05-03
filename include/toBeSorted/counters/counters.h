#ifndef COUNTERS_H
#define COUNTERS_H

#include <toBeSorted/counters/counter.h>
#include <toBeSorted/counters/small_key_counter.h>

class Counters {
public:
    Counters();

    static Counters sInstance;

    static s32 increaseCounter(u16 counterIdx, s32 value);
    static s32 getCounterByIndex(u16 counterIdx);
    static s32 getMaxItemCount(u16 counterIdx);

    Counter *ITEM_COUNTERS[40];
};


#endif
