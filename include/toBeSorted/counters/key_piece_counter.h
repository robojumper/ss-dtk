#ifndef KEY_PIECE_COUNTER_H
#define KEY_PIECE_COUNTER_H

#include <toBeSorted/counters/counter.h>

class KeyPieceCounter : public Counter {
public:
    KeyPieceCounter();
    /* 8016E1A0 */ ~KeyPieceCounter() {}
    virtual u16 getMax() override;
};

/* 80575638 */ extern KeyPieceCounter key_piece_counter;

#endif
