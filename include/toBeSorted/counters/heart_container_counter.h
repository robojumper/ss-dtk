#include <toBeSorted/counters/counter.h>

class HeartContainerCounter : public Counter {
public:
    HeartContainerCounter(): Counter(0x1ea) { }
    /* 8016ce80 */ ~HeartContainerCounter() {}
    /* 8016d9a0 */ virtual u16 getMax();
};
