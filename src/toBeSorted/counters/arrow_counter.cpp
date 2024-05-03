#include <toBeSorted/counters/counter.h>
#include <toBeSorted/counters/arrow_counter.h>

/* 80575618 */ ArrowCounter arrow_counter;

/* 8016DFE0 */ ArrowCounter::ArrowCounter() : Counter(0x1f2) {}
/* 8016E000 */ u16 ArrowCounter::getMax() {
    return 20;
}
