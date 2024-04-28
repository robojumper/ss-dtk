#include "toBeSorted/file_manager.h"
#include "f/f_base.h"
#include <MSL_C/string.h>

/** 8057185c */
const char *region = "SOUE";

extern "C" {
/* 80009D30 */ void fn_80009D30() {} // some ctor
/* 80009D40 */ void fn_80009D40() {} // some dtor
/* 80009D80 */ u16 *fn_80009D80(u16 *arg) {
    return arg;
} // return
/* 80009D90 */ u16 *fn_80009D90(u16 *arg) {
    return arg;
} // return, this is maybe a const-cast?
/* 80009DA0 */ void fn_80009DA0(void *arg) {
} // memset(param_1, 0, 0x20) a 0x24 structure is implied here (0x20 data) a crc is at 0x24
}

/* 80009DB0 */ FileManager::FileManager() {}
/* 80009EE0 */ // mVec3();

/* 80009EF0 */ FileManager FileManager::create(EGG::Heap *) {}
/* 80009F30 */ bool FileManager::loadSaveData(void *out, char *name, bool isSkipData) {}
/* 80009F70 */ void FileManager::saveSaveData(void *unk, bool isSkipData) {}
/* 8000A000 */ void FileManager::refreshSaveFileData() {}
/* 8000A260 */ wchar_t *FileManager::getFileHeroname(int fileNum) {
    return this->mHeroNames[fileNum];
}
/* 8000A280 */ s64 FileManager::getFileSaveTime(int fileNum) {
    return this->mPlayTime[fileNum];
}
/* 8000A2A0 */ u16 FileManager::getFileCurrentHealth(int fileNum) {
    return this->mCurrentHealth[fileNum];
}
/* 8000A2C0 */ u16 FileManager::getFileHealthCapacity(int fileNum) {
    return this->mCurrentHealthCapacity[fileNum];
}
/* 8000A2E0 */ void FileManager::fn_8000A2E0() {
    this->mIsFileUnk1[0] = 1;
    FileManager::initBlankSaveFiles();
    this->m_0xA84D = 0;
    this->mSelectedFile = 1;
}

/* 8000A330 */
u16 *FileManager::getStoryFlagsMut() {
    return getCurrentFile()->getStoryFlags0();
}
/* 8000A360 */ u16 *FileManager::getStoryFlagsConst() {
    return (isFileInactive() ? mFileB : mFileA).getStoryFlags1();
}
/* 8000A3B0 */ u16 *FileManager::getItemFlagsMut() {
    return getCurrentFile()->getItemFlags0();
}
/* 8000A3E0 */ u16 *FileManager::getItemFlagsConst() {
    return (isFileInactive() ? mFileB : mFileA).getItemFlags1();
}
/* 8000A430 */ u16 *FileManager::getDungeonFlagsMut() {
    return getCurrentFile()->getDungeonFlags0();
}
/* 8000A460 */ u16 *FileManager::getDungeonFlagsConst() {
    return (isFileInactive() ? mFileB : mFileA).getDungeonFlags1();
}
/* 8000A4B0 */ u16 *FileManager::getSceneFlagsMut() {
    return getCurrentFile()->getSceneFlags0();
}
/* 8000A4E0 */ u16 *FileManager::getSceneFlagsConst() {
    return (isFileInactive() ? mFileB : mFileA).getSceneFlags1();
}
/* 8000A530 */ u16 *FileManager::getTBoxFlagsMut() {
    return getCurrentFile()->getTboxFlags0();
}
/* 8000A560 */ u16 *FileManager::getTBoxFlagsConst() {
    return (isFileInactive() ? mFileB : mFileA).getTboxFlags1();
}
/* 8000A5B0 */ u16 *FileManager::getTempFlagsMut() {
    return getCurrentFile()->getTempFlags0();
}
/* 8000A5E0 */ u16 *FileManager::getTempFlagsConst() {
    return (isFileInactive() ? mFileB : mFileA).getTempFlags1();
}
/* 8000A630 */ u16 *FileManager::getZoneFlagsMut() {
    return getCurrentFile()->getZoneFlags0();
}
/* 8000A660 */ u16 *FileManager::getZoneFlagsConst() {
    return (isFileInactive() ? mFileB : mFileA).getZoneFlags1();
}
/* 8000A6B0 */ u16 *FileManager::getEnemyDefeatFlagsMut() {
    return getCurrentFile()->getEnemyFlags0();
}
/* 8000A6E0 */ u16 *FileManager::getEnemyDefeatFlagsConst() {
    return (isFileInactive() ? mFileB : mFileA).getEnemyFlags1();
}
/* 8000A730 */ void FileManager::setStoryFlags(u16 *flags, u32 offset, s32 count) {
    memcpy(getStoryFlagsMut() + offset, flags, count * 2);
}
/* 8000A790 */ void FileManager::setItemFlags(u16 *flags, u32 offset, s32 count) {
    memcpy(getItemFlagsMut() + offset, flags, count * 2);
}
/* 8000A7F0 */ void FileManager::setDungeonFlags(u16 *flags, u32 offset, s32 count) {
    memcpy(getDungeonFlagsMut() + offset, flags, count * 2);
}
/* 8000A850 */ void FileManager::setSceneFlags(u16 *flags, u32 offset, s32 count) {
    memcpy(getSceneFlagsMut() + offset, flags, count * 2);
}
/* 8000A8B0 */ void FileManager::setTBoxFlags(u16 *flags, u32 offset, s32 count) {
    memcpy(getTBoxFlagsMut() + offset, flags, count * 2);
}
/* 8000A910 */ void FileManager::setTempFlags(u16 *flags, u32 offset, s32 count) {
    memcpy(getTempFlagsMut() + offset, flags, count * 2);
}
/* 8000A970 */ void FileManager::setZoneFlags(u16 *flags, u32 offset, s32 count) {
    memcpy(getZoneFlagsMut() + offset, flags, count * 2);
}
/* 8000A9D0 */ void FileManager::setEnemyDefeatFlags(u16 *flags, u32 offset, s32 count) {
    memcpy(getEnemyDefeatFlagsMut() + offset, flags, count * 2);
}

/* 8000AA30 */ u16 *FileManager::getSkipFlags() {
    return fn_80009D90(mSkipData.data);
}
/* 8000AA40 */ void FileManager::setSkipFlagsChecked(u16 *flags, u32 offset, s32 count) {
    memcpy(fn_80009D80(getSkipFlags2()) + offset, flags, count * 2);
}

inline void strncat(char *dest, const char *src, size_t count) {
    if (dest != src) {
        dest[0] = '\0';
        if (src != nullptr) {
            size_t len = strlen(dest);
            size_t count = strlen(src);
            count = len + count + 1 >= 0x20 ? 0x1f - len : count;
            strncpy(dest + len, src, count)[count] = '\0';
        }
    }
}

/* 8000AAA0 */ void FileManager::initFile(int fileNum) {
    SaveFile *file;
    char buf[0x20];

    mIsFileInvalid[1] = 1;
    file = getFileA();
    if (fileNum != 0) {
        file = &mFileB;
    }
    file->new_file = 0;
    file->health_capacity = 0x18;
    file->unused_heart_related = 0x18;
    file->current_health = 0x18;
    file->shield_pouch_slot = 8;
    file->equipped_b_item = 0xb;
    file->selectedDowsingSlot = 0x8;
    file->lastUsedPouchItemSlot = 0x8;

    buf[0] = '\0';
    strncat(buf, "F405", 0x20);
    /*
    buf[0] = '\0';
    // TODO looks like an inlined strncat,
    // hence the needless comparison to a .data string
    // Not sure how we can do this?
    // strncat(buf, etc, 0x20);
    if (etc != buf) {
        buf[0] = '\0';
        if (etc != nullptr) {
            size_t len = strlen(buf);
            size_t count = strlen(etc);
            count = len + count + 1 >= 0x20 ? 0x1f - len : count;
            strncpy(buf + len, etc, count)[count] = '\0';
        }
    }*/
    file->setAreaT1(buf);
    file->room_id_t1 = 0;
    file->forced_layer_t1 = 0;
    file->entrance_t1_load_flag = 1;
}

/* 8000ABD0 */ void FileManager::setCurrentHealthCapacity(u16 health) {
    getCurrentFile()->health_capacity = health;
}
/* 8000AC00 */ u16 FileManager::getCurrentHealthCapacity() {
    return (isFileInactive() ? mFileB : mFileA).health_capacity;
}
/* 8000AC50 */ void FileManager::setCurrentHealth(u16 health) {
    getCurrentFile()->current_health = health;
}
/* 8000AC80 */ u16 FileManager::getCurrentHealth() {
    return (isFileInactive() ? mFileB : mFileA).current_health;
}

/* 8000ACD0 */ u16 FileManager::getLoadRoomT1() {
    return (isFileInactive() ? mFileB : mFileA).room_id_t1;
}
/* 8000AD20 */ u16 FileManager::getLoadRoomT2() {
    return (isFileInactive() ? mFileB : mFileA).room_id_t2;
}
/* 8000AD70 */ void FileManager::setLoadRoomT3(u16 room) {
    getCurrentFile()->room_id_t3 = room;
}
/* 8000ADA0 */ u16 FileManager::getLoadRoomT3() {
    return (isFileInactive() ? mFileB : mFileA).room_id_t3;
}
// TODO properly type these
/* 8000ADF0 */ mVec3_c *FileManager::getPosT1() {
    return (mVec3_c *)&(isFileInactive() ? mFileB : mFileA).pos_t1;
}
/* 8000AE40 */ void FileManager::setPosT2(mVec3_c *pos) {
    *((mVec3_c *)&getCurrentFile()->pos_t2) = *pos;
}
/* 8000AE90 */ mVec3_c *FileManager::getPosT2() {
    return (mVec3_c *)&(isFileInactive() ? mFileB : mFileA).pos_t2;
}
/* 8000AEE0 */ void FileManager::setPosT3(mVec3_c *pos) {
    *((mVec3_c *)&getCurrentFile()->pos_t3) = *pos;
}
/* 8000AF30 */ mVec3_c *FileManager::getPosT3() {
    return (mVec3_c *)&(isFileInactive() ? mFileB : mFileA).pos_t3;
}

/* 8000AF80 */ s16 FileManager::getAngleT1() {
    return (isFileInactive() ? mFileB : mFileA).angle_t1;
}
/* 8000AFD0 */ void FileManager::setAngleT2(s16 angle) {
    getCurrentFile()->angle_t2 = angle;
}
/* 8000B000 */ s16 FileManager::getAngleT2() {
    return (isFileInactive() ? mFileB : mFileA).angle_t2;
}
/* 8000B050 */ void FileManager::setAngleT3(s16 angle) {
    getCurrentFile()->angle_t3 = angle;
}
/* 8000B080 */ s16 FileManager::getAngleT3() {
    return (isFileInactive() ? mFileB : mFileA).angle_t3;
}

/* 8000B0D0 */ void FileManager::setPouchData(s32 slot, u32 slotData) {
    // TODO these two have some type confusion going on
    if ((u32)slot < 8 && slot < 0) {
        getCurrentFile()->pouch_items[slot & 0x7] = slotData;
    }
}
/* 8000B130 */ u32 FileManager::getPouchData(s32 slot) {
    // TODO
    if ((u32)slot < 8) {
        if (slot < 0) {
            return (isFileInactive() ? mFileB : mFileA).pouch_items[slot & 0x7];
        }
    }
    return 0;
}
/* 8000B1B0 */ void FileManager::setPouchItem(s32 slot, ITEM_ID item) {
    // TODO type confusion
    getCurrentFile()->pouch_items[slot & 0x7] = getPouchItem(slot) & 0xffff0000 | item;
}
/* 8000B220 */ ITEM_ID FileManager::getPouchItem(s32 slot) {}
/* 8000B250 */ void FileManager::setPouchUpperData(s32 slot, s32 data) {
    // TODO
    int item = getPouchData(slot);
    getCurrentFile()->pouch_items[slot & 0x7] = item & 0xffff0000 | data << 0x10;
}
/* 8000B2C0 */ u16 FileManager::getPouchUpperData(s32 slot) {
    int idx = getPouchData(slot);
    return (u16)(idx >> 0x10);
}

// TODO these work the same way as the above pouch functions
/* 8000B2F0 */ void FileManager::setItemCheckData(u32 idx, u32 itemData) {}
/* 8000B360 */ u32 FileManager::getItemCheckData(u32 idx) {}
/* 8000B3F0 */ void FileManager::setItemCheckItem(u32 idx, ITEM_ID item) {}
/* 8000B480 */ ITEM_ID FileManager::getItemCheckItem(u32 idx) {}
/* 8000B4B0 */ void FileManager::setItemCheckUpperData(u32 idx, u32 itemData) {}
/* 8000B540 */ u32 FileManager::getItemCheckUpperData(u32 slot) {
    int idx = getItemCheckData(slot);
    return (u16)(idx >> 0x10);
}

/* 8000B570 */ void FileManager::setEquippedItem(u8 bWheelItem) {
    getCurrentFile()->equipped_b_item = bWheelItem;
}
/* 8000B5A0 */ u8 FileManager::getEquippedItem() {
    return (isFileInactive() ? mFileB : mFileA).equipped_b_item;
}
/* 8000B5F0 */ void FileManager::setSelectedPouchSlot(u8 slot) {
    getCurrentFile()->lastUsedPouchItemSlot = slot;
}
/* 8000B620 */ u8 FileManager::getSelectedPouchSlot() {
    return (isFileInactive() ? mFileB : mFileA).lastUsedPouchItemSlot;
}
/* 8000B670 */ void FileManager::setShieldPouchSlot(u8 slot) {
    getCurrentFile()->shield_pouch_slot = slot;
}
/* 8000B6A0 */ u8 FileManager::getShieldPouchSlot() {
    return (isFileInactive() ? mFileB : mFileA).shield_pouch_slot;
}

/* 8000B6F0 */ void FileManager::setAirPotionTimer(u16 time) {
    getCurrentFile()->air_potion_timer = time;
}
/* 8000B720 */ u16 FileManager::getAirPotionTimer() {
    return (isFileInactive() ? mFileB : mFileA).air_potion_timer;
}
/* 8000B770 */ void FileManager::setAirPotionPlusTimer(u16 time) {
    getCurrentFile()->air_potion_plus_timer = time;
}
/* 8000B7A0 */ u16 FileManager::getAirPotionPlusTimer() {
    return (isFileInactive() ? mFileB : mFileA).air_potion_plus_timer;
}
/* 8000B7F0 */ void FileManager::setStaminaPotionTimer(u16 time) {
    getCurrentFile()->stamina_potion_timer = time;
}
/* 8000B820 */ u16 FileManager::getStaminaPotionTimer() {
    return (isFileInactive() ? mFileB : mFileA).stamina_potion_timer;
}
/* 8000B870 */ void FileManager::setStaminaPotionPlusTimer(u16 time) {
    getCurrentFile()->stamina_potion_plus_timer = time;
}
/* 8000B8A0 */ u16 FileManager::getStaminaPotionPlusTimer() {
    return (isFileInactive() ? mFileB : mFileA).stamina_potion_plus_timer;
}
/* 8000B8F0 */ void FileManager::setGuardianPotionTimer(u16 time) {
    getCurrentFile()->gaurdian_potion_timer = time;
}
/* 8000B920 */ u16 FileManager::getGuardianPotionTimer() {
    return (isFileInactive() ? mFileB : mFileA).gaurdian_potion_timer;
}
/* 8000B970 */ void FileManager::setGuardianPotionPlusTimer(u16 time) {
    getCurrentFile()->gaurdian_potion_plus_timer = time;
}
/* 8000B9A0 */ u16 FileManager::getGuardianPotionPlusTimer() {
    return (isFileInactive() ? mFileB : mFileA).gaurdian_potion_plus_timer;
}

/* 8000B9F0 */ void FileManager::setDowsingSlotIdx(u8 idx) {
    getCurrentFile()->selectedDowsingSlot = idx;
}
/* 8000BA20 */ u8 FileManager::getDowsingSlotIdx() {
    return (isFileInactive() ? mFileB : mFileA).selectedDowsingSlot;
}

/* 8000BA70 */ void FileManager::setBeaconPos(u32 beaconArea, u32 beaconNum, mVec3_c *pos) {}
/* 8000BB80 */ mVec3_c *FileManager::getBeaconPos(u32 beaconArea, u32 beaconNum) {}

/* 8000BC70 */ void FileManager::setEnemyKillCount(u32 enemy, u16 killCount) {
    // TODO shuffles
    if (enemy <= 100) {
        if (killCount >= 999) {
            killCount = 999;
        }
        getCurrentFile()->enemyKillCounts[enemy % 100] = killCount;
    }
}
/* 8000BCE0 */ u16 FileManager::getEnemyKillCount(u32 enemy) {
    if (enemy > 100) {
        return 0;
    }
    return (isFileInactive() ? mFileB : mFileA).enemyKillCounts[enemy % 100];
}
// TODO these suffer from the same instruction shuffles as the two previous
/* 8000BD60 */ void FileManager::setHitCountFromEnemy(u32 enemy, u16 hitCount) {}
/* 8000BDD0 */ u16 FileManager::getHitCountFromEnemy(u32 enemy) {}

/* 8000BE50 */ void FileManager::setLoadRoomT1_FileB(u16 roomId) {
    getFileB()->room_id_t1 = roomId;
}
/* 8000BE80 */ u16 FileManager::getLoadRoomT1_FileB() {
    return mFileB.room_id_t1;
}
/* 8000BE90 */ void FileManager::setEntranceT1_FileB(u8 entrance) {
    getFileB()->entrance_t1 = entrance;
}
/* 8000BEC0 */ u8 FileManager::getEntranceT1_FileB() {
    return mFileB.entrance_t1;
}
/* 8000BED0 */ void FileManager::setAreaT1_FileB(const char *name) {}
/* 8000BF80 */ char *FileManager::getAreaT1_FileB() {
    return mFileB.area_t1;
}
/* 8000C080 */ void FileManager::setNightT1_FileB(u8 night) {
    getFileB()->night_t1 = night;
}
/* 8000C0B0 */ u8 FileManager::getNightT1_FileB() {
    return mFileB.night_t1;
}
/* 8000C0C0 */ void FileManager::setEntranceT1LoadFlag_FileB(u8 flag) {
    getFileB()->entrance_t1_load_flag = flag;
}
/* 8000C0F0 */ void FileManager::setForcedLayerT1_FileB(u8 layer) {
    getFileB()->forced_layer_t1 = layer;
}
/* 8000C120 */ u8 FileManager::getForcedLayerT1_FileB() {
    return mFileB.forced_layer_t1;
}
/* 8000C130 */ void FileManager::setCurrentHealth_FileB(u16 health) {
    getFileB()->current_health = health;
}
// TODO these similarly seem to use some inlined strncopy functions
/* 8000C160 */ void FileManager::setHeroname(const wchar_t *name) {}
/* 8000C230 */ wchar_t *FileManager::getHeroname() {}

/* 8000C360 */ char *FileManager::getAreaT1() {}
/* 8000C470 */ char *FileManager::getAreaT2() {}
/* 8000C580 */ void FileManager::setAreaT3(const char *name) {}
/* 8000C630 */ char *FileManager::getAreaT3() {}

/* 8000C740 */ u8 FileManager::getForcedLayerT1() {
    return (isFileInactive() ? mFileB : mFileA).forced_layer_t1;
}
/* 8000C790 */ u8 FileManager::getForcedLayerT2() {
    return (isFileInactive() ? mFileB : mFileA).forced_layer_t2;
}
/* 8000C7E0 */ void FileManager::setForcedLayerT3(u8 layer) {
    getCurrentFile()->forced_layer_t3 = layer;
}
/* 8000C810 */ u8 FileManager::getForcedLayerT3() {
    return (isFileInactive() ? mFileB : mFileA).forced_layer_t3;
}

/* 8000C860 */ u8 FileManager::getEntranceT1() {
    return (isFileInactive() ? mFileB : mFileA).entrance_t1;
}
/* 8000C8B0 */ void FileManager::setEntranceLoadFlagT1(u8 flag) {
    getCurrentFile()->entrance_t1_load_flag = flag;
}
/* 8000C8E0 */ u8 FileManager::getEntranceLoadFlagT1() {
    return (isFileInactive() ? mFileB : mFileA).entrance_t1_load_flag;
}
/* 8000C930 */ u8 FileManager::getEntranceT2() {
    return (isFileInactive() ? mFileB : mFileA).entrance_t2;
}
/* 8000C980 */ void FileManager::setEntranceT3(u8 entrance) {
    getCurrentFile()->entrance_t3 = entrance;
}
/* 8000C9B0 */ u8 FileManager::getEntranceT3() {
    return (isFileInactive() ? mFileB : mFileA).entrance_t3;
}

/* 8000CA00 */ u8 FileManager::getNightT1() {
    return (isFileInactive() ? mFileB : mFileA).night_t1;
}
/* 8000CA50 */ void FileManager::setNightT3(u8 night) {
    getCurrentFile()->night_t3 = night;
}
/* 8000CA80 */ u8 FileManager::getNightT3() {
    return (isFileInactive() ? mFileB : mFileA).night_t3;
}

/* 8000CAD0 */ u8 FileManager::isNew_FileA() {
    return getFileA()->new_file;
}

/* 8000CB00 */ void FileManager::setSceneFlagIndex(s16 idx) {
    getCurrentFile()->scene_flag_index = idx;
}
/* 8000CB30 */ s16 FileManager::getSceneFlagIndex() {
    return (isFileInactive() ? mFileB : mFileA).scene_flag_index;
}
/* 8000CB80 */ s32 FileManager::getFileAreaIndex() {
    return (isFileInactive() ? mFileB : mFileA).file_area_index;
}

/* 8000CBD0 */ void FileManager::fn_8000CBD0(u8 arg) {}
/* 8000CC00 */ void FileManager::fn_8000CC00() {}

/* 8000CC50 */ void FileManager::setFileTimes() {}
/* 8000CCB0 */ void FileManager::setPlayTime(s64 time) {
    getCurrentFile()->playtime = time;
}
// TODO rename
/* 8000CCF0 */ s64 FileManager::getSavedTime() {
    return (isFileInactive() ? mFileB : mFileA).playtime;
}
/* 8000CD40 */ void FileManager::setSavedTime(s64 time) {
    getCurrentFile()->savedTime = time;
}

/* 8000CD80 */ void FileManager::setBeedleShopPathSegment(u32 path) {
    getCurrentFile()->beedleShopPathSegment = path;
}
/* 8000CDB0 */ u32 FileManager::getBeedleShopPathSegment() {
    return (isFileInactive() ? mFileB : mFileA).beedleShopPathSegment;
}
/* 8000CE00 */ void FileManager::setBeedleShopPathSegFrac(f32 segFrac) {
    getCurrentFile()->beedlShopPathSegFrac = segFrac;
}
/* 8000CE30 */ f32 FileManager::getBeedleShopPathSegFrac() {
    return (isFileInactive() ? mFileB : mFileA).beedlShopPathSegFrac;
}
/* 8000CE80 */ void FileManager::setBeedleShopRotation(s16 rot) {
    getCurrentFile()->beedle_shop_rotation = rot;
}
/* 8000CEB0 */ s16 FileManager::getBeedleShopRotation() {
    return (isFileInactive() ? mFileB : mFileA).beedle_shop_rotation;
}

/* 8000CF00 */ void FileManager::fn_8000CF00(u32 shift) {}
/* 8000CF70 */ bool FileManager::fn_8000CF70(u32 shift) {
    return ((isFileInactive() ? mFileB : mFileA).field_0x07BC & (1 << shift)) != 0;
}

/* 8000CFE0 */ void FileManager::setSkykeepPuzzle(u32 spot, u8 tile) {
    getCurrentFile()->skykeep_puzzle[spot % 9] = tile;
}
/* 8000D040 */ u8 FileManager::getSkykeepPuzzleTile(u32 spot) {
    return (isFileInactive() ? mFileB : mFileA).skykeep_puzzle[spot % 9];
}

/* 8000D0B0 */ void FileManager::checkFileStatus() {
    SavedSaveFiles *files;
    mIsFileInvalid[2] = 0;
    files = mpSavedSaveFiles;
    if (!checkRegionCode()) {
        mIsFileInvalid[2] = 1;
    }
    if (files->m_0x1C != 0x1d) {
        mIsFileInvalid[2] = 1;
    }
    // TODO int types/reg shuffles, maybe adjust checkFileCRC arg type
    u32 flag = 0;
    for (int i = 0; i < 3; i++) {
        if (checkFileCRC(i & 0xFF) == 0) {
            mIsFileDataDirty[i & 0xFF] = 1;
        } else {
            mIsFileDataDirty[i & 0xFF] = 0;
        }
    }

    SkipData *data;
    int i;
    for (i = 0, data = &mpSkipData[0]; i < 3; i++, data++) {
        u32 crc = calcFileCRC(data->data, sizeof(data->data));
        if (crc != data->crc) {
            fn_80009DA0(data);
            u32 crc = calcFileCRC(data->data, sizeof(data->data));
            data->crc = crc;
        }
    }
}
/* 8000D1D0 */ u32 FileManager::checkSkipDataCRCs() {
    SkipData *data;
    u32 dirty = 0;
    int i;
    for (data = &mpSkipData[0], i = 0; i < 3; i++, data++) {
        u32 crc = calcFileCRC(data->data, sizeof(data->data));
        if (crc == data->crc) {
            mIsFileSkipDataDirty[i & 0xff] = 0;
        } else {
            mIsFileSkipDataDirty[i & 0xff] = 1;
            dirty = 1;
        }
    }
    return dirty;
}
/* 8000D270 */ void FileManager::saveOrClearSelectedFileToFileA() {
    saveOrClearToFileA(mSelectedFile);
}
/* 8000D280 */ void FileManager::saveOrClearToFileA(int fileNum) {}
/* 8000D9C0 */ void FileManager::copyFileBToCurrentFile() {}
/* 8000E060 */ void FileManager::copyFileAToSelectedFile() {
    copyFileAToFile(mSelectedFile);
}
/* 8000E070 */ void FileManager::copyFileAToFile(int fileNum) {}
/* 8000E7C0 */ void FileManager::copyFile(int from, int to) {}
/* 8000EF80 */ void FileManager::saveFileAToSelectedFile() {
    saveFileAToFile(mSelectedFile);
}
/* 8000EF90 */ void FileManager::saveFileAToFile(int fileNum) {}
/* 8000F730 */ void FileManager::copyCurrentToFileB() {}
/* 8000FDF0 */ void FileManager::copySelectedFileSkipData() {
    copySkipData(mSelectedFile);
}
/* 8000FE00 */ void FileManager::copySkipData(u32 fileNum) {
    // TODO reg shuffles
    if (fileNum < 3) {
        mSkipData.crc = calcFileCRC(&mSkipData.data, sizeof(mSkipData.data));
        SkipData *data = &mpSkipData[fileNum];
        mpSkipData[fileNum] = mSkipData;
    }
}

/* 8000FEB0 */ void FileManager::setInfo_FileB(u16 entrance, u16 room) {
    copyCurrentToFileB();
    setLoadRoomT1_FileB(room);
    setEntranceT1_FileB(entrance);
    // TODO reloader
    setCurrentHealth_FileB(0x18);
    setEntranceT1LoadFlag_FileB(1);
}
/* 8000FF60 */ void FileManager::clearFileA() {
    // TODO reg shuffles
    SaveFile *file = getFileA();
    memset(file, 0, sizeof(SaveFile));
    file->new_file = 1;
    file->checksum = calcFileCRC(file, sizeof(SaveFile) - sizeof(u32));
    SkipData *data = &mSkipData;
    memset(&data->data, 0, sizeof(SkipData));
    data->crc = calcFileCRC(data->data, sizeof(mSkipData.data));
}

/* 80010000 */ void FileManager::initBlankSaveFiles() {}
/* 80010160 */ void FileManager::initSkipData() {
    memset(mpSkipData, 0, 0x80);
    SkipData *data;
    int i;
    for (i = 0, data = &mpSkipData[0]; i < 3; i++, data++) {
        u32 crc = calcFileCRC(data->data, sizeof(data->data));
        data->crc = crc;
    }
    mIsFileSkipDataDirty[0] = 0;
    mIsFileSkipDataDirty[1] = 0;
    mIsFileSkipDataDirty[2] = 0;
}

/* 800101F0 */ void FileManager::unsetFileANewFile() {
    getFileA()->new_file = 0;
}
/* 80010220 */ void FileManager::saveT1SaveInfo(u8 entranceT1LoadFlag) {}
/* 80010350 */ void FileManager::copyFileSkipData(int fileNum) {}
extern "C" void fn_800C01F0(); // todo flag managers
/* 80010440 */ void FileManager::clearTempFileData() {
    memset(&mFileA, 0, sizeof(SaveFile));
    memset(&mFileB, 0, sizeof(SaveFile));
    memset(&mSkipData, 0, sizeof(SkipData));
    fn_800C01F0();
}
/* 800104A0 */ void FileManager::saveAfterCredits() {}

/* 80011210 */ SaveFile *FileManager::getCurrentFile() {
    return (isFileInactive() ? &mFileB : &mFileA);
}
/* 80011250 */ u16 *FileManager::getSkipFlags2() {
    return mSkipData.data;
}
/* 80011260 */ SaveFile *FileManager::getFileA() {
    return &mFileA;
}
/* 80011270 */ SaveFile *FileManager::getFileB() {
    return &mFileB;
}
/* 80011280 */ u32 FileManager::calcFileCRC(const void *file, u32 length) {}
/* 80011290 */ void FileManager::updateEmptyFiles() {
    updateEmptyFileFlags();
    refreshSaveFileData();
}
/* 800112D0 */ void FileManager::updateEmptyFileFlags() {}
/* 80011370 */ u8 FileManager::isFileEmpty(u32 fileNum) {
    if (fileNum < 3) {
        return mIsFileEmpty[fileNum];
    }
    return 1;
}
/* 80011390 */ u8 FileManager::isFileDirty(u32 fileNum) {
    if (fileNum < 3) {
        return mIsFileDataDirty[fileNum];
    }
    return 1;
}
/* 800113B0 */ u8 FileManager::get_0xA84C() {
    return m_0xA84C;
}
/* 800113C0 */ bool FileManager::checkRegionCode() {
    // TODO
    SavedSaveFiles *file = mpSavedSaveFiles;
    for (int i = 0; i < 4; i++) {
        if (file->regionCode[i] != region[i]) {
            return false;
        }
    }
    return true;
}
/* 80011440 */ bool FileManager::checkFileCRC(int fileNum) {
    // u32 checksum = calcFileCRC()
}
/* 80011490 */
bool FileManager::isFileInactive() {
    fBase_c *actor = fManager_c::searchBaseByGroupType(1, nullptr);
    if (actor) {
        if (actor->profile_name == fProfile::TITLE && !mAntiCommitFlag) {
            return true;
        }
        return false;
    }
    return false;
}
/* 80011500 */ void FileManager::setPlayerInfoFileA() {}
/* 800115E0 */ void FileManager::setT3Info(mVec3_c *pos, mAng3_c *rot) {}
/* 800116C0 */ void FileManager::getRegionVersion(char *out) {
    const char *pRegion = region;
    out[0] = pRegion[0];
    out[1] = pRegion[1];
    out[2] = pRegion[2];
    out[3] = pRegion[3];
}
