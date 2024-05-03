#include <toBeSorted/counters/counter.h>
#include <toBeSorted/counters/counters.h>
#include <toBeSorted/counters/small_key_counter.h>
#include <toBeSorted/counters/pouch_expansion_counter.h>


class HeartPieceCounter : public Counter {
public:
    HeartPieceCounter() : Counter(0x1ea) {}
    /* 8016ce80 */ ~HeartPieceCounter() {}
    virtual s32 checkedAdd(s32 num);
    /* 8016d9a0 */ virtual u16 getMax();
};

class HeartContainerCounter : public Counter {
public:
    HeartContainerCounter(): Counter(0x1ea) { }
    /* 8016ce80 */ ~HeartContainerCounter() {}
    /* 8016d9a0 */ virtual u16 getMax();
};


SmallKeyCounter small_key_counter;
PouchExpansionCounter pouch_expansion_counter;
HeartPieceCounter heart_piece_counter;

int HeartPieceCounter::checkedAdd(s32 num) {
    if (num > 0) {
        s32 uncommitted = getUncommittedValue();
        s32 newCount = uncommitted + num;
        setValue(newCount % 4);
    }
    return 0;
}

HeartContainerCounter heart_container_counter;

Counters::Counters() {
    ITEM_COUNTERS[6] = &small_key_counter;
    ITEM_COUNTERS[7] = &pouch_expansion_counter;
    ITEM_COUNTERS[8] = &heart_piece_counter;
    ITEM_COUNTERS[9] = &heart_container_counter;
}

Counters Counters::sInstance;

s32 Counters::increaseCounter(u16 counterIdx, s32 value) {
    return Counters::sInstance.ITEM_COUNTERS[counterIdx]->checkedAdd(value);
}

s32 Counters::getCounterByIndex(u16 counterIdx) {
    return Counters::sInstance.ITEM_COUNTERS[counterIdx]->getCommittedValue();
}

s32 Counters::getMaxItemCount(u16 counterIdx) {
    return Counters::sInstance.ITEM_COUNTERS[counterIdx]->getMax();
}

u16 HeartContainerCounter::getMax() {
    return 18;
};

u16 HeartPieceCounter::getMax() {
    return 4;
};

u16 PouchExpansionCounter::getMax() {
    return 7;
};

u16 SmallKeyCounter::getMax() {
    return 15;
};
