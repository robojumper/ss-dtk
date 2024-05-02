#include <toBeSorted/counters/counter.h>

class ExtraWalletCounter : public Counter {
public:
    ExtraWalletCounter();
    ~ExtraWalletCounter() {}
    virtual u16 getMax() override;
};

extern ExtraWalletCounter extra_wallet_counter;
