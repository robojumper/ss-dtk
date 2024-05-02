#include <toBeSorted/counters/counter.h>


class RupeeCounter : public Counter {
public:
    RupeeCounter();
    ~RupeeCounter() {}
    virtual u16 getMax() override;
};

struct WalletStruct {
    u32 flag;
    u16 capacity;
};

const struct WalletStruct wallet_definitions[4] = {
    {0x6c, 500},
    {0x6d, 1000},
    {0x6e, 5000},
    {0x6f, 9000},
};

// TODO set up item flag manager
extern "C" void *lbl_80575400;
extern "C" u16 fn_800BF5E0(void *data, u16 flag);

u16 getBaseCapacity() {
    int i = 0;
    WalletStruct tmp[4] = { wallet_definitions[0], wallet_definitions[1], wallet_definitions[2], wallet_definitions[3] };
    const WalletStruct *wallet = &tmp[3];
    for (; i < 4; i++, wallet--) {
        if (fn_800BF5E0(lbl_80575400, wallet->flag)) {
            return wallet->capacity;
        }
    }
    return 300;
}

u16 getExtraWalletCapacity() {
    return 300 * getCounterByIndex(0x27);
}


RupeeCounter rupee_counter;

RupeeCounter::RupeeCounter() : Counter(0x1f5) {}

u16 RupeeCounter::getMax() {
    return (getBaseCapacity() + getExtraWalletCapacity());
}
