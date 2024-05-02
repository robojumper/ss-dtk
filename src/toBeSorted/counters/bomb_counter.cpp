#include <toBeSorted/counters/counter.h>

class BombCounter : public Counter {
public:
    BombCounter();
    ~BombCounter() {}
    virtual u16 getMax() override;
};

BombCounter bomb_counter;

BombCounter::BombCounter(): Counter(0x1f3) { }
u16 BombCounter::getMax() {
    return 10;
}
