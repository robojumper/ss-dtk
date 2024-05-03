#ifndef ARROW_COUNTER_H
#define ARROW_COUNTER_H

#include <toBeSorted/counters/counter.h>


class ArrowCounter : public Counter {
public:
    ArrowCounter();
    /* 8016DFA0 */ ~ArrowCounter() {}
    virtual u16 getMax() override;
};

/* 80575618 */ extern ArrowCounter arrow_counter;

#endif
