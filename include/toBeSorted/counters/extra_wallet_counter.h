#ifndef EXTRA_WALLET_COUNTER_H
#define EXTRA_WALLET_COUNTER_H

#include <toBeSorted/counters/counter.h>

class ExtraWalletCounter : public Counter {
public:
    ExtraWalletCounter();
    /* 8016E220 */ ~ExtraWalletCounter() {}
    virtual u16 getMax() override;
};

/* 80575640 */ extern ExtraWalletCounter extra_wallet_counter;

#endif
