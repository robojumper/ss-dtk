#include <toBeSorted/counters/counter.h>
#include <toBeSorted/counters/extra_wallet_counter.h>

ExtraWalletCounter extra_wallet_counter;

ExtraWalletCounter::ExtraWalletCounter(): Counter(0x1fc) { }
u16 ExtraWalletCounter::getMax() {
        return 3;
}
