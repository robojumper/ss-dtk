#include <toBeSorted/counters/counter.h>
#include <toBeSorted/counters/extra_wallet_counter.h>

/* 80575640 */ ExtraWalletCounter extra_wallet_counter;

/* 8016E260 */ ExtraWalletCounter::ExtraWalletCounter(): Counter(0x1fc) { }
/* 8016E280 */ u16 ExtraWalletCounter::getMax() {
    return 3;
}
