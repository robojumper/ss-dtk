#include <toBeSorted/counters/counter.h>

class KeyPieceCounter : public Counter {
public:
    KeyPieceCounter();
    ~KeyPieceCounter() {}
    virtual u16 getMax() override;
};

KeyPieceCounter key_piece_counter;

KeyPieceCounter::KeyPieceCounter(): Counter(0x1f9) { }
u16 KeyPieceCounter::getMax() {
    return 5;
}
