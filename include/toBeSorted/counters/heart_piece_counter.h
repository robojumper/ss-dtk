#include <toBeSorted/counters/counter.h>

class HeartPieceCounter : public Counter {
public:
    HeartPieceCounter() : Counter(0x1ea) {}
    /* 8016ce80 */ ~HeartPieceCounter() {}
    virtual s32 checkedAdd(s32 num);
    /* 8016d9a0 */ virtual u16 getMax();
};
