#include <toBeSorted/counters/counter.h>

class GoddessChestsOpenedCounter : public Counter {
public:
    GoddessChestsOpenedCounter();
    ~GoddessChestsOpenedCounter();
    virtual u16 getCommittedValue() override;
    virtual u16 getMax() override;
    virtual u16 getUncommittedValue() override;
    virtual void setValue(u16 num) override;
};


// This TU is a bit messed up - currently we define the static before the dtor
// so that __sinit_ registers the global dtor. But in the original binary the dtor
// is nontrivial, almost as if this class owned another object, and the constructor
// stores the item ID as a word, not a half word? But the vtable
// uses the same Counter::checkedAdd implementation, so idk what's up

GoddessChestsOpenedCounter goddess_chests_opened_counter;

u16 GoddessChestsOpenedCounter::getCommittedValue() {

}

// TODO set up story flag manager

u16 GoddessChestsOpenedCounter::getUncommittedValue() {
    
}

void GoddessChestsOpenedCounter::setValue(u16 num) {
    
}

GoddessChestsOpenedCounter::GoddessChestsOpenedCounter() : Counter(0x43f) {}
GoddessChestsOpenedCounter::~GoddessChestsOpenedCounter() {}

u16 GoddessChestsOpenedCounter::getMax() {
    return 27;
}
