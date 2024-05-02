#include <toBeSorted/counters/counter.h>

class TearCounter : public Counter {
public:
    TearCounter();
    ~TearCounter() {}
    virtual u16 getMax() override;
};

TearCounter tear_counter;

TearCounter::TearCounter(): Counter(0x1f4) { }
u16 TearCounter::getMax() {
    return 15;
}
