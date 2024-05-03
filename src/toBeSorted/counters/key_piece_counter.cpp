#include <toBeSorted/counters/counter.h>
#include <toBeSorted/counters/key_piece_counter.h>

/* 80575638 */ KeyPieceCounter key_piece_counter;

/* 8016E1E0 */ KeyPieceCounter::KeyPieceCounter() : Counter(0x1f9) {}
/* 8016E200 */ u16 KeyPieceCounter::getMax() {
    return 5;
}
