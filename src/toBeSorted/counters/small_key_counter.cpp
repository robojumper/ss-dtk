#include <toBeSorted/counters/small_key_counter.h>
#include <toBeSorted/file_manager.h>
#include <toBeSorted/flag_space.h>
#include <toBeSorted/unk_flag_stuff.h>

extern "C" UnkFlagDefinition lbl_80511AF0[];

class DungeonflagManager;
extern DungeonflagManager *lbl_80575404;

class DungeonflagManager {
public:
    bool mShouldCommit;
    u16 mStageIndex;
    UnkFlagStuff *mFlagStuff;
    FlagSpace mFlagSpace;

    static u16 sDungeonFlags[8];
    // static DungeonflagManager *sInstance;

    void copyFromSave(s16 flag);
    void copyFromSave(u16 flagIndex);
    void setCommitFlag(u16 flag);
    DungeonflagManager();
    void setupFlagStuff();
    void setToValue(u16 flag, u16 value);
    void setFlag(u16 flag);
    u16 getDungeonFlag(u16 flag);
    bool doCommit();
};

/* 8016cda0 */ u16 SmallKeyCounter::getCommittedValue() {
    DungeonflagManager *dMgr = lbl_80575404;
    FileManager *mgr = FileManager::sInstance;
    u16 offset = dMgr->mStageIndex * 8;
    return dMgr->mFlagStuff->getCounterOrFlag(counterId, mgr->getDungeonFlagsConst() + offset, 8);
}

/*  */ u16 SmallKeyCounter::getUncommittedValue() {
    return lbl_80575404->getDungeonFlag(counterId);
}

/*  */ void SmallKeyCounter::setValue(u16 value) {
    lbl_80575404->setToValue(counterId, value);
}
