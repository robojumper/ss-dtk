#include <toBeSorted/counters/counter.h>
#include <toBeSorted/counters/bomb_counter.h>

/* 80575620 */ BombCounter bomb_counter;

/* 8016E060 */ BombCounter::BombCounter(): Counter(0x1f3) { }
/* 8016E080 */ u16 BombCounter::getMax() {
    return 10;
}
