#ifndef SDK_KIT_H_
#define SDK_KIT_H_


//#define HJR_USE_LUA_SDK 1

#include <iostream>
#include <map>

#ifdef HJR_USE_LUA_SDK

extern "C" {
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}

void initLuaFrame(lua_State* ls);

#endif


//////////////////////////////////////////////

#ifdef HJR_USE_LUA_SDK
int sdkkit_login(lua_State *L);
#else
int sdkkit_login();
#endif

#ifdef HJR_USE_LUA_SDK
int sdkkit_logout(lua_State *L);
#else
int sdkkit_logout();
#endif

#ifdef HJR_USE_LUA_SDK
int sdkkit_pay(lua_State *L);
#else
int sdkkit_pay(int payAmount, const char *productId, const char *productName, const char *payProductNum, const char *payOrderId, const char *payProductDesc, const char *extInfo);
#endif

#ifdef HJR_USE_LUA_SDK
int sdkkit_userCenter(lua_State *L);
#else
int sdkkit_userCenter();
#endif

#ifdef HJR_USE_LUA_SDK
int sdkkit_getOrderInfo(lua_State *L);
#else
int sdkkit_getOrderInfo(const char* payOrderId);
#endif

#ifdef HJR_USE_LUA_SDK
int sdkkit_exitGame(lua_State *L);
#else
int sdkkit_exitGame();
#endif

#ifdef HJR_USE_LUA_SDK
int sdkkit_getCurrentLoginedUserInfo(lua_State *L);
#else
std::string sdkkit_getCurrentLoginedUserInfo();
#endif

//////////////////////////////////////////////
#ifdef HJR_USE_LUA_SDK
int sdkkit_onEnterGame(lua_State *L);
#else
int sdkkit_onEnterGame(const char* roleId, const char* roleName, const char* roleLevel, const char* serverId, const char* serverName);
#endif

#ifdef HJR_USE_LUA_SDK
int sdkkit_onLogin(lua_State *L);
#else
int sdkkit_onLogin(const char* userId, const char* serverId);
#endif

#ifdef HJR_USE_LUA_SDK
int sdkkit_onPay(lua_State *L);
#else
int sdkkit_onPay(int amount, const char* orderNumber, const char* productDesc);
#endif

#ifdef HJR_USE_LUA_SDK
int sdkkit_onUpgrade(lua_State *L);
#else
int sdkkit_onUpgrade(const char* roleLevel);
#endif

#ifdef HJR_USE_LUA_SDK
int sdkkit_onCreateRole(lua_State *L);
#else
int sdkkit_onCreateRole(const char* roleId, const char* roleName, const char* serverId, const char* serverName);
#endif

#ifdef HJR_USE_LUA_SDK
int sdkkit_onButtonClick(lua_State *L);
#else
int sdkkit_onButtonClick(const char* userId, const char* buttonName);
#endif

#ifdef HJR_USE_LUA_SDK
int sdkkit_onServerRoleInfo(lua_State *L);
#else
int sdkkit_onServerRoleInfo(const char* roleId, const char* roleName, int roleLevel, const char* serverId, const char* serverName, const char* rolePartyName, const char* roleVipLevel);
#endif

//////////////////////////////////////////////

void SDKKitPlateformCallBackImplWrapper_initCallBack(int retStatus, std::string retMessage);

void SDKKitPlateformCallBackImplWrapper_loginCallBack(int retStatus, std::string s_retMessage, std::string s_loginUserId, std::string s_loginUserName, std::string s_loginAuthToken, std::string s_loginOpenId, int s_flag);

void SDKKitPlateformCallBackImplWrapper_logoutCallBack(int retStatus, std::string s_retMessage);

void SDKKitPlateformCallBackImplWrapper_payCallBack(int retStatus, std::string s_retMessage, std::string s_payKitOrderId);

void SDKKitPlateformCallBackImplWrapper_getOrderResultCallBack(int retStatus, std::string s_retMessage, std::string s_orderStatus);

void SDKKitPlateformCallBackImplWrapper_exitGameCallBack(int retStatus, std::string s_retMessage);

//////////////////////////////////////////////

#endif
