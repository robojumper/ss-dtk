#include <toBeSorted/counters/counter.h>

class SlingshotSeedCounter : public Counter {
public:
    SlingshotSeedCounter();
    ~SlingshotSeedCounter() {}
    virtual u16 getMax() override;
};

SlingshotSeedCounter slingshot_seed_counter;

SlingshotSeedCounter::SlingshotSeedCounter(): Counter(0x1ed) { }
u16 SlingshotSeedCounter::getMax() {
    return 20;
}
