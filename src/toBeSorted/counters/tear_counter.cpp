#include <toBeSorted/counters/counter.h>
#include <toBeSorted/counters/tear_counter.h>

/* 80575628 */ TearCounter tear_counter;

/* 8016E0E0 */ TearCounter::TearCounter(): Counter(0x1f4) { }
/* 8016E100 */ u16 TearCounter::getMax() {
    return 15;
}
