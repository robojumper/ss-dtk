#ifndef BOMB_COUNTER_H
#define BOMB_COUNTER_H

#include <toBeSorted/counters/counter.h>

class BombCounter : public Counter {
public:
    BombCounter();
    /* 8016E020 */ ~BombCounter() {}
    virtual u16 getMax() override;
};

/* 80575620 */ extern BombCounter bomb_counter;

#endif
