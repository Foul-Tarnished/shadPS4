// SPDX-FileCopyrightText: Copyright 2024 shadPS4 Emulator Project
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "common/types.h"
#include "core/libraries/rtc/rtc.h"

namespace Core::Loader {
class SymbolsResolver;
}

namespace Libraries::NpTrophy {

extern std::string game_serial;

constexpr int ORBIS_NP_TROPHY_FLAG_SETSIZE = 128;
constexpr int ORBIS_NP_TROPHY_FLAG_BITS_SHIFT = 5;

constexpr int ORBIS_NP_TROPHY_GAME_TITLE_MAX_SIZE = 128;
constexpr int ORBIS_NP_TROPHY_GAME_DESCR_MAX_SIZE = 1024;
constexpr int ORBIS_NP_TROPHY_GROUP_TITLE_MAX_SIZE = 128;
constexpr int ORBIS_NP_TROPHY_GROUP_DESCR_MAX_SIZE = 1024;
constexpr int ORBIS_NP_TROPHY_NAME_MAX_SIZE = 128;
constexpr int ORBIS_NP_TROPHY_DESCR_MAX_SIZE = 1024;
constexpr int ORBIS_NP_TROPHY_NUM_MAX = 128;

constexpr int ORBIS_NP_TROPHY_INVALID_HANDLE = -1;
constexpr int ORBIS_NP_TROPHY_INVALID_CONTEXT = -1;
constexpr int ORBIS_NP_TROPHY_INVALID_TROPHY_ID = -1;

typedef int32_t OrbisNpTrophyHandle;
typedef int32_t OrbisNpTrophyContext;
typedef int32_t OrbisNpTrophyId;
typedef uint32_t OrbisNpTrophyFlagMask;

struct OrbisNpTrophyFlagArray {
    OrbisNpTrophyFlagMask
        flag_bits[ORBIS_NP_TROPHY_FLAG_SETSIZE >> ORBIS_NP_TROPHY_FLAG_BITS_SHIFT];
};

void ORBIS_NP_TROPHY_FLAG_ZERO(OrbisNpTrophyFlagArray* p);
void ORBIS_NP_TROPHY_FLAG_SET(int32_t trophyId, OrbisNpTrophyFlagArray* p);
void ORBIS_NP_TROPHY_FLAG_SET_ALL(OrbisNpTrophyFlagArray* p);
void ORBIS_NP_TROPHY_FLAG_CLR(int32_t trophyId, OrbisNpTrophyFlagArray* p);
bool ORBIS_NP_TROPHY_FLAG_ISSET(int32_t trophyId, OrbisNpTrophyFlagArray* p);

struct OrbisNpTrophyData {
    size_t size;
    OrbisNpTrophyId trophyId;
    bool unlocked;
    uint8_t reserved[3];
    Rtc::OrbisRtcTick timestamp;
};

typedef int32_t OrbisNpTrophyGrade;
constexpr int ORBIS_NP_TROPHY_GRADE_UNKNOWN = 0;
constexpr int ORBIS_NP_TROPHY_GRADE_PLATINUM = 1;
constexpr int ORBIS_NP_TROPHY_GRADE_GOLD = 2;
constexpr int ORBIS_NP_TROPHY_GRADE_SILVER = 3;
constexpr int ORBIS_NP_TROPHY_GRADE_BRONZE = 4;

typedef int32_t OrbisNpTrophyGroupId;
constexpr int ORBIS_NP_TROPHY_BASE_GAME_GROUP_ID = -1;
constexpr int ORBIS_NP_TROPHY_INVALID_GROUP_ID = -2;

struct OrbisNpTrophyDetails {
    size_t size;
    OrbisNpTrophyId trophyId;
    OrbisNpTrophyGrade trophyGrade;
    OrbisNpTrophyGroupId groupId;
    bool hidden;
    uint8_t reserved[3];
    char name[ORBIS_NP_TROPHY_NAME_MAX_SIZE];
    char description[ORBIS_NP_TROPHY_DESCR_MAX_SIZE];
};

struct OrbisNpTrophyGameData {
    size_t size;
    uint32_t unlockedTrophies;
    uint32_t unlockedPlatinum;
    uint32_t unlockedGold;
    uint32_t unlockedSilver;
    uint32_t unlockedBronze;
    uint32_t progressPercentage;
};

struct OrbisNpTrophyGameDetails {
    size_t size;
    uint32_t numGroups;
    uint32_t numTrophies;
    uint32_t numPlatinum;
    uint32_t numGold;
    uint32_t numSilver;
    uint32_t numBronze;
    char title[ORBIS_NP_TROPHY_GAME_TITLE_MAX_SIZE];
    char description[ORBIS_NP_TROPHY_GAME_DESCR_MAX_SIZE];
};

struct OrbisNpTrophyGroupData {
    size_t size;
    OrbisNpTrophyGroupId groupId;
    uint32_t unlockedTrophies;
    uint32_t unlockedPlatinum;
    uint32_t unlockedGold;
    uint32_t unlockedSilver;
    uint32_t unlockedBronze;
    uint32_t progressPercentage;
    uint8_t reserved[4];
};

struct OrbisNpTrophyGroupDetails {
    size_t size;
    OrbisNpTrophyGroupId groupId;
    uint32_t numTrophies;
    uint32_t numPlatinum;
    uint32_t numGold;
    uint32_t numSilver;
    uint32_t numBronze;
    char title[ORBIS_NP_TROPHY_GROUP_TITLE_MAX_SIZE];
    char description[ORBIS_NP_TROPHY_GROUP_DESCR_MAX_SIZE];
};

int PS4_SYSV_ABI sceNpTrophyAbortHandle(OrbisNpTrophyHandle handle);
int PS4_SYSV_ABI sceNpTrophyCaptureScreenshot();
int PS4_SYSV_ABI sceNpTrophyConfigGetTrophyDetails();
int PS4_SYSV_ABI sceNpTrophyConfigGetTrophyFlagArray();
int PS4_SYSV_ABI sceNpTrophyConfigGetTrophyGroupArray();
int PS4_SYSV_ABI sceNpTrophyConfigGetTrophyGroupDetails();
int PS4_SYSV_ABI sceNpTrophyConfigGetTrophySetInfo();
int PS4_SYSV_ABI sceNpTrophyConfigGetTrophySetInfoInGroup();
int PS4_SYSV_ABI sceNpTrophyConfigGetTrophySetVersion();
int PS4_SYSV_ABI sceNpTrophyConfigGetTrophyTitleDetails();
int PS4_SYSV_ABI sceNpTrophyConfigHasGroupFeature();
s32 PS4_SYSV_ABI sceNpTrophyCreateContext(OrbisNpTrophyContext* context, int32_t user_id,
                                          uint32_t service_label, uint64_t options);
s32 PS4_SYSV_ABI sceNpTrophyCreateHandle(OrbisNpTrophyHandle* handle);
int PS4_SYSV_ABI sceNpTrophyDestroyContext(OrbisNpTrophyContext context);
s32 PS4_SYSV_ABI sceNpTrophyDestroyHandle(OrbisNpTrophyHandle handle);
int PS4_SYSV_ABI sceNpTrophyGetGameIcon(OrbisNpTrophyContext context, OrbisNpTrophyHandle handle,
                                        void* buffer, size_t* size);
int PS4_SYSV_ABI sceNpTrophyGetGameInfo(OrbisNpTrophyContext context, OrbisNpTrophyHandle handle,
                                        OrbisNpTrophyGameDetails* details,
                                        OrbisNpTrophyGameData* data);
int PS4_SYSV_ABI sceNpTrophyGetGroupIcon(OrbisNpTrophyContext context, OrbisNpTrophyHandle handle,
                                         OrbisNpTrophyGroupId groupId, void* buffer, size_t* size);
int PS4_SYSV_ABI sceNpTrophyGetGroupInfo(OrbisNpTrophyContext context, OrbisNpTrophyHandle handle,
                                         OrbisNpTrophyGroupId groupId,
                                         OrbisNpTrophyGroupDetails* details,
                                         OrbisNpTrophyGroupData* data);
int PS4_SYSV_ABI sceNpTrophyGetTrophyIcon(OrbisNpTrophyContext context, OrbisNpTrophyHandle handle,
                                          OrbisNpTrophyId trophyId, void* buffer, size_t* size);
int PS4_SYSV_ABI sceNpTrophyGetTrophyInfo(OrbisNpTrophyContext context, OrbisNpTrophyHandle handle,
                                          OrbisNpTrophyId trophyId, OrbisNpTrophyDetails* details,
                                          OrbisNpTrophyData* data);
s32 PS4_SYSV_ABI sceNpTrophyGetTrophyUnlockState(OrbisNpTrophyContext context,
                                                 OrbisNpTrophyHandle handle,
                                                 OrbisNpTrophyFlagArray* flags, u32* count);
int PS4_SYSV_ABI sceNpTrophyGroupArrayGetNum();
int PS4_SYSV_ABI sceNpTrophyIntAbortHandle();
int PS4_SYSV_ABI sceNpTrophyIntCheckNetSyncTitles();
int PS4_SYSV_ABI sceNpTrophyIntCreateHandle();
int PS4_SYSV_ABI sceNpTrophyIntDestroyHandle();
int PS4_SYSV_ABI sceNpTrophyIntGetLocalTrophySummary();
int PS4_SYSV_ABI sceNpTrophyIntGetProgress();
int PS4_SYSV_ABI sceNpTrophyIntGetRunningTitle();
int PS4_SYSV_ABI sceNpTrophyIntGetRunningTitles();
int PS4_SYSV_ABI sceNpTrophyIntGetTrpIconByUri();
int PS4_SYSV_ABI sceNpTrophyIntNetSyncTitle();
int PS4_SYSV_ABI sceNpTrophyIntNetSyncTitles();
int PS4_SYSV_ABI sceNpTrophyNumInfoGetTotal();
int PS4_SYSV_ABI sceNpTrophyRegisterContext(OrbisNpTrophyContext context,
                                            OrbisNpTrophyHandle handle, uint64_t options);
int PS4_SYSV_ABI sceNpTrophySetInfoGetTrophyFlagArray();
int PS4_SYSV_ABI sceNpTrophySetInfoGetTrophyNum();
int PS4_SYSV_ABI sceNpTrophyShowTrophyList(OrbisNpTrophyContext context,
                                           OrbisNpTrophyHandle handle);
int PS4_SYSV_ABI sceNpTrophySystemAbortHandle();
int PS4_SYSV_ABI sceNpTrophySystemBuildGroupIconUri();
int PS4_SYSV_ABI sceNpTrophySystemBuildNetTrophyIconUri();
int PS4_SYSV_ABI sceNpTrophySystemBuildTitleIconUri();
int PS4_SYSV_ABI sceNpTrophySystemBuildTrophyIconUri();
int PS4_SYSV_ABI sceNpTrophySystemCheckNetSyncTitles();
int PS4_SYSV_ABI sceNpTrophySystemCheckRecoveryRequired();
int PS4_SYSV_ABI sceNpTrophySystemCloseStorage();
int PS4_SYSV_ABI sceNpTrophySystemCreateContext();
int PS4_SYSV_ABI sceNpTrophySystemCreateHandle();
int PS4_SYSV_ABI sceNpTrophySystemDbgCtl();
int PS4_SYSV_ABI sceNpTrophySystemDebugLockTrophy();
int PS4_SYSV_ABI sceNpTrophySystemDebugUnlockTrophy();
int PS4_SYSV_ABI sceNpTrophySystemDestroyContext();
int PS4_SYSV_ABI sceNpTrophySystemDestroyHandle();
int PS4_SYSV_ABI sceNpTrophySystemDestroyTrophyConfig();
int PS4_SYSV_ABI sceNpTrophySystemGetDbgParam();
int PS4_SYSV_ABI sceNpTrophySystemGetDbgParamInt();
int PS4_SYSV_ABI sceNpTrophySystemGetGroupIcon();
int PS4_SYSV_ABI sceNpTrophySystemGetLocalTrophySummary();
int PS4_SYSV_ABI sceNpTrophySystemGetNextTitleFileEntryStatus();
int PS4_SYSV_ABI sceNpTrophySystemGetProgress();
int PS4_SYSV_ABI sceNpTrophySystemGetTitleFileStatus();
int PS4_SYSV_ABI sceNpTrophySystemGetTitleIcon();
int PS4_SYSV_ABI sceNpTrophySystemGetTitleSyncStatus();
int PS4_SYSV_ABI sceNpTrophySystemGetTrophyConfig();
int PS4_SYSV_ABI sceNpTrophySystemGetTrophyData();
int PS4_SYSV_ABI sceNpTrophySystemGetTrophyGroupData();
int PS4_SYSV_ABI sceNpTrophySystemGetTrophyIcon();
int PS4_SYSV_ABI sceNpTrophySystemGetTrophyTitleData();
int PS4_SYSV_ABI sceNpTrophySystemGetTrophyTitleIds();
int PS4_SYSV_ABI sceNpTrophySystemGetUserFileInfo();
int PS4_SYSV_ABI sceNpTrophySystemGetUserFileStatus();
int PS4_SYSV_ABI sceNpTrophySystemIsServerAvailable();
int PS4_SYSV_ABI sceNpTrophySystemNetSyncTitle();
int PS4_SYSV_ABI sceNpTrophySystemNetSyncTitles();
int PS4_SYSV_ABI sceNpTrophySystemOpenStorage();
int PS4_SYSV_ABI sceNpTrophySystemPerformRecovery();
int PS4_SYSV_ABI sceNpTrophySystemRemoveAll();
int PS4_SYSV_ABI sceNpTrophySystemRemoveTitleData();
int PS4_SYSV_ABI sceNpTrophySystemRemoveUserData();
int PS4_SYSV_ABI sceNpTrophySystemSetDbgParam();
int PS4_SYSV_ABI sceNpTrophySystemSetDbgParamInt();
int PS4_SYSV_ABI sceNpTrophyUnlockTrophy(OrbisNpTrophyContext context, OrbisNpTrophyHandle handle,
                                         OrbisNpTrophyId trophyId, OrbisNpTrophyId* platinumId);
int PS4_SYSV_ABI Func_149656DA81D41C59();
int PS4_SYSV_ABI Func_9F80071876FFA5F6();
int PS4_SYSV_ABI Func_F8EF6F5350A91990();
int PS4_SYSV_ABI Func_FA7A2DD770447552();

void RegisterlibSceNpTrophy(Core::Loader::SymbolsResolver* sym);
} // namespace Libraries::NpTrophy