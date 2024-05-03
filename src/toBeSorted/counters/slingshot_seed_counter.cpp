#include <toBeSorted/counters/counter.h>
#include <toBeSorted/counters/slingshot_seed_counter.h>

/* 80575630 */ SlingshotSeedCounter slingshot_seed_counter;

/* 8016E160 */ SlingshotSeedCounter::SlingshotSeedCounter() : Counter(0x1ed) {}
/* 8016E180 */ u16 SlingshotSeedCounter::getMax() {
    return 20;
}
