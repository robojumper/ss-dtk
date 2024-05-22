#include <common.h>
#include <d/a/d_a_base.h>

struct dynAcTODO {
    void *(*create)();
    u16 executeOrder;
    u16 drawOrder;
    u32 baseProperties;
    u32 defaultFlags;
};

class d_t : public dAcBase_c {
public:
    virtual ~d_t() {}
};

class d_t_tackle : public d_t {
public:
    d_t_tackle() {}
    virtual int create() override;
    virtual int doDelete() override;
    virtual int draw() override;
    virtual int actorExecute() override;
    virtual ~d_t_tackle() {}
};

void *create() {
    d_t_tackle *result = new d_t_tackle();
    return result;
}

dynAcTODO lbl_472_data_0 = { create, 0x0210, 0x0241, 0, 0 };


int d_t_tackle::create() {
    return 1;
}

int d_t_tackle::doDelete() {
    return 1;
}

int d_t_tackle::actorExecute() {
    return 1;
}

int d_t_tackle::draw() {
    return 1;
}
