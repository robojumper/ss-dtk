#include <toBeSorted/counters/counter.h>

class ArrowCounter : public Counter {
public:
    ArrowCounter();
    ~ArrowCounter() {}
    virtual u16 getMax() override;
};

ArrowCounter arrow_counter;

ArrowCounter::ArrowCounter(): Counter(0x1f2) { }
u16 ArrowCounter::getMax() {
    return 20;
}
