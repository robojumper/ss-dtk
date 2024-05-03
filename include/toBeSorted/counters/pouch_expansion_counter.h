#include <toBeSorted/counters/counter.h>

class PouchExpansionCounter : public Counter {
public:
    PouchExpansionCounter(): Counter(0x1ea) { }
    /* 8016ce80 */ ~PouchExpansionCounter() {}
    /* 8016d9a0 */ virtual u16 getMax();
};
