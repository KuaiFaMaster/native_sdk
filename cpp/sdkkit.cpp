#include "SdkkitJniHelper.h"
#include "sdkkit.h"

#include <jni.h>
#include <iostream>
#include <map>

using namespace std;

#ifdef __ANDROID__
#include <android/log.h>
#endif


#define  LOG_TAG    "SDKKIT"
#define  LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG,LOG_TAG,__VA_ARGS__)
#define  LOGE(...)  __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)

#ifdef HJR_USE_LUA_SDK

static lua_State* s_sdkkit_L;

void initLuaFrame(lua_State* L)
{
    s_sdkkit_L = L;
    lua_register(L, "sdkkit_login", sdkkit_login);
    lua_register(L, "sdkkit_logout", sdkkit_logout);
    lua_register(L, "sdkkit_pay", sdkkit_pay);
    lua_register(L, "sdkkit_userCenter", sdkkit_userCenter);
    lua_register(L, "sdkkit_getOrderInfo", sdkkit_getOrderInfo);
    lua_register(L, "sdkkit_exitGame", sdkkit_exitGame);
    lua_register(L, "sdkkit_getCurrentLoginedUserInfo", sdkkit_getCurrentLoginedUserInfo);

    lua_register(L, "sdkkit_onEnterGame", sdkkit_onEnterGame);
    lua_register(L, "sdkkit_onLogin", sdkkit_onLogin);
    lua_register(L, "sdkkit_onPay", sdkkit_onPay);
    lua_register(L, "sdkkit_onUpgrade", sdkkit_onUpgrade);
    lua_register(L, "sdkkit_onCreateRole", sdkkit_onCreateRole);
    lua_register(L, "sdkkit_onButtonClick", sdkkit_onButtonClick);
    lua_register(L, "sdkkit_onServerRoleInfo", sdkkit_onServerRoleInfo);
}

#endif //HJR_USE_LUA_SDK

// void SDKKitPlateformCallBackImplWrapper_initCallBack(int retStatus, std::string retMessage)
// {
//     LOGD("call SDKKitPlateformCallBackImplWrapper_initCallBack");
// }
//
// void SDKKitPlateformCallBackImplWrapper_loginCallBack(int retStatus, std::string s_retMessage, std::string s_loginUserId, std::string s_loginUserName, std::string s_loginAuthToken, std::string s_loginOpenId, int s_flag)
// {
//     LOGD("call c/lua SDKKitPlateformCallBackImplWrapper_loginCallBack");
//     #ifdef HJR_USE_LUA_SDK
//     //////m_fflua_ptr->call<void>("SDKKitPlateformCallBackImplWrapper_loginCallBack", retStatus, s_retMessage, s_loginUserId, s_loginUserName, s_loginAuthToken, s_loginOpenId, s_flag);
//     lua_getglobal(s_sdkkit_L, "SDKKitPlateformCallBackImplWrapper_loginCallBack");
//     lua_pushnumber(s_sdkkit_L, retStatus);
//     lua_pushstring(s_sdkkit_L, s_retMessage.c_str());
//     lua_pushstring(s_sdkkit_L, s_loginUserId.c_str());
//     lua_pushstring(s_sdkkit_L, s_loginUserName.c_str());
//     lua_pushstring(s_sdkkit_L, s_loginAuthToken.c_str());
//     lua_pushstring(s_sdkkit_L, s_loginOpenId.c_str());
//     lua_pushnumber(s_sdkkit_L, s_flag);
//
//     int iError = lua_pcall(s_sdkkit_L, 7, 0, 0);
//     if(iError)
//     {
//         std::cout << "pcall FAILED"
//              << lua_tostring(s_sdkkit_L, -1)
//              << iError
//              << std::endl;
//     }
//
//     #endif
// }
//
// void SDKKitPlateformCallBackImplWrapper_logoutCallBack(int retStatus, std::string s_retMessage)
// {
//     LOGD("call c/lua SDKKitPlateformCallBackImplWrapper_logoutCallBack");
//     #ifdef HJR_USE_LUA_SDK
//     //////m_fflua_ptr->call<void>("SDKKitPlateformCallBackImplWrapper_logoutCallBack", retStatus, s_retMessage);
//     lua_getglobal(s_sdkkit_L, "SDKKitPlateformCallBackImplWrapper_logoutCallBack");
//     lua_pushnumber(s_sdkkit_L, retStatus);
//     lua_pushstring(s_sdkkit_L, s_retMessage.c_str());
//
//     int iError = lua_pcall(s_sdkkit_L, 2, 0, 0);
//     if(iError)
//     {
//         std::cout << "pcall FAILED"
//              << lua_tostring(s_sdkkit_L, -1)
//              << iError
//              << std::endl;
//     }
//
//     #endif
// }
//
// void SDKKitPlateformCallBackImplWrapper_payCallBack(int retStatus, std::string s_retMessage, std::string s_payKitOrderId)
// {
//     LOGD("call c/lua SDKKitPlateformCallBackImplWrapper_payCallBack");
//     #ifdef HJR_USE_LUA_SDK
//     ////m_fflua_ptr->call<void>("SDKKitPlateformCallBackImplWrapper_payCallBack", retStatus, s_retMessage, s_payKitOrderId);
//     lua_getglobal(s_sdkkit_L, "SDKKitPlateformCallBackImplWrapper_payCallBack");
//     lua_pushnumber(s_sdkkit_L, retStatus);
//     lua_pushstring(s_sdkkit_L, s_retMessage.c_str());
//     lua_pushstring(s_sdkkit_L, s_payKitOrderId.c_str());
//
//     int iError = lua_pcall(s_sdkkit_L, 3, 0, 0);
//     if(iError)
//     {
//         std::cout << "pcall FAILED"
//              << lua_tostring(s_sdkkit_L, -1)
//              << iError
//              << std::endl;
//     }
//
//     #endif
// }
//
// void SDKKitPlateformCallBackImplWrapper_getOrderResultCallBack(int retStatus, std::string s_retMessage, std::string s_orderStatus)
// {
//     LOGD("call c/lua SDKKitPlateformCallBackImplWrapper_getOrderResultCallBack");
//     #ifdef HJR_USE_LUA_SDK
//     ////m_fflua_ptr->call<void>("SDKKitPlateformCallBackImplWrapper_getOrderResultCallBack", retStatus, s_retMessage, s_orderStatus);
//     lua_getglobal(s_sdkkit_L, "SDKKitPlateformCallBackImplWrapper_getOrderResultCallBack");
//     lua_pushnumber(s_sdkkit_L, retStatus);
//     lua_pushstring(s_sdkkit_L, s_retMessage.c_str());
//     lua_pushstring(s_sdkkit_L, s_orderStatus.c_str());
//
//     int iError = lua_pcall(s_sdkkit_L, 3, 0, 0);
//     if(iError)
//     {
//         std::cout << "pcall FAILED"
//              << lua_tostring(s_sdkkit_L, -1)
//              << iError
//              << std::endl;
//     }
//     #endif
// }
//
// void SDKKitPlateformCallBackImplWrapper_exitGameCallBack(int retStatus, std::string s_retMessage)
// {
//     LOGD("call c/lua SDKKitPlateformCallBackImplWrapper_exitGameCallBack");
//     #ifdef HJR_USE_LUA_SDK
//     ////m_fflua_ptr->call<void>(, retStatus, s_retMessage);
//     lua_getglobal(s_sdkkit_L, "SDKKitPlateformCallBackImplWrapper_exitGameCallBack");
//     lua_pushnumber(s_sdkkit_L, retStatus);
//     lua_pushstring(s_sdkkit_L, s_retMessage.c_str());
//
//     int iError = lua_pcall(s_sdkkit_L, 2, 0, 0);
//     if(iError)
//     {
//         std::cout << "pcall FAILED"
//              << lua_tostring(s_sdkkit_L, -1)
//              << iError
//              << std::endl;
//     }
//     #endif
// }


//////////////////////////////////////////////
#ifdef HJR_USE_LUA_SDK
int sdkkit_login(lua_State *L)
#else
int sdkkit_login()
#endif
{
    LOGD("sdkkit  login");

	//函数信息结构体
    sdkkit::JniMethodInfo minfo;

    bool isHave = sdkkit::JniHelper::getStaticMethodInfo(minfo,/*sdkkit::JniMethodInfo的引用*/
                                                 "org/apache/sdknative/SDKKitPlateformBusinessImplWrapper",/*类的路径*/
                                                 "login",/*函数名*/
                                                 "()V");/*函数类型简写*/
    if (isHave)
    {
        //CallStaticVoidMethod调用java函数，并把返回值赋值给activityObj
        minfo.env->CallStaticVoidMethod(minfo.classID, minfo.methodID);
    }
    return 0;
}

#ifdef HJR_USE_LUA_SDK
int sdkkit_logout(lua_State *L)
#else
int sdkkit_logout()
#endif
{
    LOGD("sdkkit  logout");
	//函数信息结构体
    sdkkit::JniMethodInfo minfo;
    bool isHave = sdkkit::JniHelper::getStaticMethodInfo(minfo,/*sdkkit::JniMethodInfo的引用*/
                                                 "org/apache/sdknative/SDKKitPlateformBusinessImplWrapper",/*类的路径*/
                                                 "logout",/*函数名*/
                                                 "()V");/*函数类型简写*/

    if (isHave)
    {
        //CallStaticVoidMethod调用java函数，并把返回值赋值给activityObj
        minfo.env->CallStaticVoidMethod(minfo.classID, minfo.methodID);
    }
    return 0;
}

#ifdef HJR_USE_LUA_SDK
int sdkkit_pay(lua_State *L)
{
    int payAmount = luaL_checknumber(L, 1);

    const char *productId = luaL_checkstring(L, 2);
    const char *productName = luaL_checkstring(L, 3);
    const char *payProductNum = luaL_checkstring(L, 4);
    const char *payOrderId = luaL_checkstring(L, 5);
    const char *payProductDesc = luaL_checkstring(L, 6);
    const char *extInfo = luaL_checkstring(L, 7);
#else
int sdkkit_pay(int payAmount, const char *productId, const char *productName, const char *payProductNum, const char *payOrderId, const char *payProductDesc, const char *extInfo)
{
#endif

    LOGD("sdkkit  pay");
    sdkkit::JniMethodInfo minfo;
    bool isHave = sdkkit::JniHelper::getStaticMethodInfo(minfo,/*sdkkit::JniMethodInfo的引用*/
                                                 "org/apache/sdknative/SDKKitPlateformBusinessImplWrapper",/*类的路径*/
                                                 "pay",/*函数名*/
                                                 "(ILjava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V");/*函数类型简写*/

    if (isHave)
    {
        jint j_payAmount = payAmount;
        jstring j_productId = minfo.env->NewStringUTF(productId);
        jstring j_productName = minfo.env->NewStringUTF(productName);
        jstring j_payProductNum = minfo.env->NewStringUTF(payProductNum);
        jstring j_payOrderId = minfo.env->NewStringUTF(payOrderId);
        jstring j_payProductDesc = minfo.env->NewStringUTF(payProductDesc);
        jstring j_extInfo = minfo.env->NewStringUTF(extInfo);

        //CallStaticVoidMethod调用java函数，并把返回值赋值给activityObj
        minfo.env->CallStaticVoidMethod(minfo.classID, minfo.methodID, j_payAmount,
            j_productId, j_productName, j_payProductNum, j_payOrderId, j_payProductDesc, j_extInfo);
    }
    return 0;
}

#ifdef HJR_USE_LUA_SDK
int sdkkit_userCenter(lua_State *L)
#else
int sdkkit_userCenter()
#endif
{
    LOGD("sdkkit  userCenter");
	//函数信息结构体
    sdkkit::JniMethodInfo minfo;
    bool isHave = sdkkit::JniHelper::getStaticMethodInfo(minfo,/*sdkkit::JniMethodInfo的引用*/
                                                 "org/apache/sdknative/SDKKitPlateformBusinessImplWrapper",/*类的路径*/
                                                 "userCenter",/*函数名*/
                                                 "()V");/*函数类型简写*/

    if (isHave)
    {
        //CallStaticVoidMethod调用java函数，并把返回值赋值给activityObj
        minfo.env->CallStaticVoidMethod(minfo.classID, minfo.methodID);
    }
    return 0;
}

#ifdef HJR_USE_LUA_SDK
int sdkkit_getOrderInfo(lua_State *L)
{
    const char* payOrderId = luaL_checkstring(L, 1);
#else
int sdkkit_getOrderInfo(const char* payOrderId)
{
#endif
    LOGD("sdkkit  getOrderInfo %s", payOrderId);
	//函数信息结构体
    sdkkit::JniMethodInfo minfo;
    bool isHave = sdkkit::JniHelper::getStaticMethodInfo(minfo,/*sdkkit::JniMethodInfo的引用*/
                                                 "org/apache/sdknative/SDKKitPlateformBusinessImplWrapper",/*类的路径*/
                                                 "getOrderInfo",/*函数名*/
                                                 "(Ljava/lang/String;)V");/*函数类型简写*/

    if (isHave)
    {
        jstring id = minfo.env->NewStringUTF(payOrderId);
        //CallStaticVoidMethod调用java函数，并把返回值赋值给activityObj
        minfo.env->CallStaticVoidMethod(minfo.classID, minfo.methodID, id);
    }
    return 0;
}


#ifdef HJR_USE_LUA_SDK
int sdkkit_exitGame(lua_State *L)
#else
int sdkkit_exitGame()
#endif
{
    LOGD("sdkkit  exitGame");
	//函数信息结构体
    sdkkit::JniMethodInfo minfo;
    bool isHave = sdkkit::JniHelper::getStaticMethodInfo(minfo,/*sdkkit::JniMethodInfo的引用*/
                                                 "org/apache/sdknative/SDKKitPlateformBusinessImplWrapper",/*类的路径*/
                                                 "exitGame",/*函数名*/
                                                 "()V");/*函数类型简写*/

    if (isHave)
    {
        //CallStaticVoidMethod调用java函数，并把返回值赋值给activityObj
        minfo.env->CallStaticVoidMethod(minfo.classID, minfo.methodID);
    }
    return 0;
}

#ifdef HJR_USE_LUA_SDK
int sdkkit_getCurrentLoginedUserInfo(lua_State *L)
#else
std::string sdkkit_getCurrentLoginedUserInfo()
#endif
{
    LOGD("sdkkit  getCurrentLoginedUserInfo");
    //函数信息结构体
    sdkkit::JniMethodInfo minfo;
    bool isHave = sdkkit::JniHelper::getStaticMethodInfo(minfo,/*sdkkit::JniMethodInfo的引用*/
                                                 "org/apache/sdknative/SDKKitPlateformBusinessImplWrapper",/*类的路径*/
                                                 "getCurrentLoginedUserInfo",/*函数名*/
                                                 "()V");/*函数类型简写*/

    if (isHave)
    {
        //CallStaticVoidMethod调用java函数，并把返回值赋值给activityObj
        jstring result = static_cast<jstring>(minfo.env->CallObjectMethod(minfo.classID, minfo.methodID));
        // // TODO 调用lua
        std::string s_retstr = sdkkit::JniHelper::jstring2string(result);

#ifdef HJR_USE_LUA_SDK
        lua_pushstring(L, s_retstr.c_str());
        LOGD("sdkkit  getCurrentLoginedUserInfo: %s", s_retstr.c_str());
        return 1;
#else
        return s_retstr;
#endif
    }

#ifdef HJR_USE_LUA_SDK
    lua_pushstring(L, "");
    return 1;
#else
    return "";
#endif
}


/////////////////////////////////////////////////////////
#ifdef HJR_USE_LUA_SDK
int sdkkit_onEnterGame(lua_State *L)
{
    const char* roleId = luaL_checkstring(L, 1);
    const char* roleName = luaL_checkstring(L, 2);
    const char* roleLevel = luaL_checkstring(L, 3);
    const char* serverId = luaL_checkstring(L, 4);
    const char* serverName = luaL_checkstring(L, 5);
#else
int sdkkit_onEnterGame(const char* roleId, const char* roleName, const char* roleLevel, const char* serverId, const char* serverName)
{
#endif

    LOGD("sdkkit  onEnterGame");
    //函数信息结构体
    sdkkit::JniMethodInfo minfo;
    bool isHave = sdkkit::JniHelper::getStaticMethodInfo(minfo,/*sdkkit::JniMethodInfo的引用*/
                                                 "org/apache/sdknative/SDKKitPlatformCollectionsImplWrapper",/*类的路径*/
                                                 "onEnterGame",/*函数名*/
                                                 "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V");/*函数类型简写*/

    if (isHave)
    {
        jstring j_roleId = minfo.env->NewStringUTF(roleId);
        jstring j_roleName = minfo.env->NewStringUTF(roleName);
        jstring j_roleLevel = minfo.env->NewStringUTF(roleLevel);
        jstring j_serverId = minfo.env->NewStringUTF(serverId);
        jstring j_serverName = minfo.env->NewStringUTF(serverName);
        //CallStaticVoidMethod调用java函数，并把返回值赋值给activityObj
        minfo.env->CallStaticVoidMethod(minfo.classID, minfo.methodID, j_roleId, j_roleName, j_roleLevel, j_serverId, j_serverName);
    }
    return 0;
}

#ifdef HJR_USE_LUA_SDK
int sdkkit_onLogin(lua_State *L)
{
    const char* userId = luaL_checkstring(L, 1);
    const char* serverId = luaL_checkstring(L, 2);
#else
int sdkkit_onLogin(const char* userId, const char* serverId)
{
#endif

    LOGD("sdkkit  onLogin");
   //函数信息结构体
    sdkkit::JniMethodInfo minfo;
    bool isHave = sdkkit::JniHelper::getStaticMethodInfo(minfo,/*sdkkit::JniMethodInfo的引用*/
                                                 "org/apache/sdknative/SDKKitPlatformCollectionsImplWrapper",/*类的路径*/
                                                 "onLogin",/*函数名*/
                                                 "(Ljava/lang/String;Ljava/lang/String;)V");/*函数类型简写*/

    if (isHave)
    {
        jstring j_userId = minfo.env->NewStringUTF(userId);
        jstring j_serverId = minfo.env->NewStringUTF(serverId);
        //CallStaticVoidMethod调用java函数，并把返回值赋值给activityObj
        minfo.env->CallStaticVoidMethod(minfo.classID, minfo.methodID, j_userId, j_serverId);
    }
    return 0;
}

#ifdef HJR_USE_LUA_SDK
int sdkkit_onPay(lua_State *L)
{
    int amount = luaL_checknumber(L, 1);
    const char* orderNumber = luaL_checkstring(L, 2);
    const char* productDesc = luaL_checkstring(L, 3);
#else
int sdkkit_onPay(int amount, const char* orderNumber, const char* productDesc)
{
#endif
    //函数信息结构体
    sdkkit::JniMethodInfo minfo;
    bool isHave = sdkkit::JniHelper::getStaticMethodInfo(minfo,/*sdkkit::JniMethodInfo的引用*/
                                                 "org/apache/sdknative/SDKKitPlatformCollectionsImplWrapper",/*类的路径*/
                                                 "onPay",/*函数名*/
                                                 "(ILjava/lang/String;Ljava/lang/String;)V");/*函数类型简写*/

    if (isHave)
    {
        jint j_amount = amount;
        jstring j_orderNumber = minfo.env->NewStringUTF(orderNumber);
        jstring j_productDesc = minfo.env->NewStringUTF(productDesc);
        //CallStaticVoidMethod调用java函数，并把返回值赋值给activityObj
        minfo.env->CallStaticVoidMethod(minfo.classID, minfo.methodID, j_amount,
            j_orderNumber, j_productDesc);
    }
    return 0;
}

#ifdef HJR_USE_LUA_SDK
int sdkkit_onUpgrade(lua_State *L)
{
    const char* roleLevel = luaL_checkstring(L, 1);
#else
int sdkkit_onUpgrade(const char* roleLevel)
{
#endif
    LOGD("sdkkit  onUpgrade");
    //函数信息结构体
    sdkkit::JniMethodInfo minfo;
    bool isHave = sdkkit::JniHelper::getStaticMethodInfo(minfo,/*sdkkit::JniMethodInfo的引用*/
                                                 "org/apache/sdknative/SDKKitPlatformCollectionsImplWrapper",/*类的路径*/
                                                 "onUpgrade",/*函数名*/
                                                 "(Ljava/lang/String;)V");/*函数类型简写*/

    if (isHave)
    {
        jstring j_roleLevel = minfo.env->NewStringUTF(roleLevel);
        //CallStaticVoidMethod调用java函数，并把返回值赋值给activityObj
        minfo.env->CallStaticVoidMethod(minfo.classID, minfo.methodID, j_roleLevel);
    }
    return 0;
}

#ifdef HJR_USE_LUA_SDK
int sdkkit_onServerRoleInfo(lua_State *L)
{
    const char* roleId = luaL_checkstring(L, 1);
    const char* roleName = luaL_checkstring(L, 2);
    int roleLevel = luaL_checknumber(L, 3);
    const char* serverId = luaL_checkstring(L, 4);
    const char* serverName = luaL_checkstring(L, 5);
    const char* rolePartyName = luaL_checkstring(L, 6);
    const char* roleVipLevel = luaL_checkstring(L, 7);
#else
int sdkkit_onServerRoleInfo(const char* roleId, const char* roleName, int roleLevel, const char* serverId, const char* serverName, const char* rolePartyName, const char* roleVipLevel)
{
#endif
    LOGD("sdkkit  onServerRoleInfo");
   //函数信息结构体
    sdkkit::JniMethodInfo minfo;
    bool isHave = sdkkit::JniHelper::getStaticMethodInfo(minfo,/*sdkkit::JniMethodInfo的引用*/
                                                 "org/apache/sdknative/SDKKitPlatformCollectionsImplWrapper",/*类的路径*/
                                                 "onServerRoleInfo",/*函数名*/
                                                 "(Ljava/lang/String;Ljava/lang/String;ILjava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V");/*函数类型简写*/

    if (isHave)
    {
        jstring j_roleId = minfo.env->NewStringUTF(roleId);
        jstring j_roleName = minfo.env->NewStringUTF(roleName);
        jint j_roleLevel = roleLevel;
        jstring j_serverId = minfo.env->NewStringUTF(serverId);
        jstring j_serverName = minfo.env->NewStringUTF(serverName);
        jstring j_rolePartyName = minfo.env->NewStringUTF(rolePartyName);
        jstring j_roleVipLevel = minfo.env->NewStringUTF(roleVipLevel);
        //CallStaticVoidMethod调用java函数，并把返回值赋值给activityObj
        minfo.env->CallStaticVoidMethod(minfo.classID, minfo.methodID, j_roleId,
            j_roleName, roleLevel, j_serverId, j_serverName, j_rolePartyName, j_roleVipLevel);
    }
    return 0;
}

#ifdef HJR_USE_LUA_SDK
int sdkkit_onButtonClick(lua_State *L)
{
    const char* userId = luaL_checkstring(L, 1);
    const char* buttonName = luaL_checkstring(L, 2);
#else
int sdkkit_onButtonClick(const char* userId, const char* buttonName)
{
#endif
    LOGD("sdkkit  onButtonClick");
    //函数信息结构体
    sdkkit::JniMethodInfo minfo;
    bool isHave = sdkkit::JniHelper::getStaticMethodInfo(minfo,/*sdkkit::JniMethodInfo的引用*/
                                                 "org/apache/sdknative/SDKKitPlatformCollectionsImplWrapper",/*类的路径*/
                                                 "onButtonClick",/*函数名*/
                                                 "(Ljava/lang/String;Ljava/lang/String;)V");/*函数类型简写*/

    if (isHave)
    {
        jstring j_userId = minfo.env->NewStringUTF(userId);
        jstring j_buttonName = minfo.env->NewStringUTF(buttonName);
        //CallStaticVoidMethod调用java函数，并把返回值赋值给activityObj
        minfo.env->CallStaticVoidMethod(minfo.classID, minfo.methodID, j_userId, j_buttonName);
    }
    return 0;
}

#ifdef HJR_USE_LUA_SDK
int sdkkit_onCreateRole(lua_State *L)
{
    const char* roleId = luaL_checkstring(L, 1);
    const char* roleName = luaL_checkstring(L, 2);
    const char* serverId = luaL_checkstring(L, 3);
    const char* serverName = luaL_checkstring(L, 4);
#else
int sdkkit_onCreateRole(const char* roleId, const char* roleName, const char* serverId, const char* serverName)
{
#endif
    LOGD("sdkkit  onCreateRole");
   //函数信息结构体
    sdkkit::JniMethodInfo minfo;
    bool isHave = sdkkit::JniHelper::getStaticMethodInfo(minfo,/*sdkkit::JniMethodInfo的引用*/
                                                 "org/apache/sdknative/SDKKitPlatformCollectionsImplWrapper",/*类的路径*/
                                                 "onCreateRole",/*函数名*/
                                                 "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V");/*函数类型简写*/

    if (isHave)
    {
        jstring j_roleId = minfo.env->NewStringUTF(roleId);
        jstring j_roleName = minfo.env->NewStringUTF(roleName);
        jstring j_serverId = minfo.env->NewStringUTF(serverId);
        jstring j_serverName = minfo.env->NewStringUTF(serverName);
        //CallStaticVoidMethod调用java函数，并把返回值赋值给activityObj
        minfo.env->CallStaticVoidMethod(minfo.classID, minfo.methodID, j_roleId, j_roleName,
            j_serverId, j_serverName);
    }

}


#ifdef __cplusplus
extern "C" {
#endif
/**
 * 初始化回调
 * @param retStatus
 * @param retMessage
 */
JNIEXPORT void JNICALL Java_org_apache_sdknative_SDKKitPlateformCallBackImplWrapper_initCallBackJni(JNIEnv * env, jobject arg, jint retStatus, jstring retMessage)
{
    LOGD("Java_org_apache_sdknative_SDKKitPlateformCallBackImplWrapper_initCallBack");
    std::string s_retMessage = sdkkit::JniHelper::jstring2string(retMessage);
    LOGD("Java_org_apache_sdknative_SDKKitPlateformCallBackImplWrapper_initCallBack %s", s_retMessage.c_str());
    //LOGD(retStatus)
    //  LOGD(retMessage);
    SDKKitPlateformCallBackImplWrapper_initCallBack(retStatus, s_retMessage);
}

/**
 * 登录回调
 * @param response
 * @param retStatus
 * @param retMessage
 */
JNIEXPORT void JNICALL Java_org_apache_sdknative_SDKKitPlateformCallBackImplWrapper_loginCallBackJni(JNIEnv * env, jobject arg, jint retStatus,
            jstring retMessage, jstring loginUserId, jstring loginUserName,
            jstring loginAuthToken, jstring loginOpenId,jboolean switchUserFlag)
{
    LOGD("Java_org_apache_sdknative_SDKKitPlateformCallBackImplWrapper_loginCallBack");
    std::string s_retMessage = sdkkit::JniHelper::jstring2string(retMessage);
    std::string s_loginUserId = sdkkit::JniHelper::jstring2string(loginUserId);
    std::string s_loginUserName = sdkkit::JniHelper::jstring2string(loginUserName);
    std::string s_loginAuthToken = sdkkit::JniHelper::jstring2string(loginAuthToken);
    std::string s_loginOpenId = sdkkit::JniHelper::jstring2string(loginOpenId);
    int flag = (switchUserFlag==JNI_TRUE ? 1 : 0);
    SDKKitPlateformCallBackImplWrapper_loginCallBack(retStatus, s_retMessage, s_loginUserId, s_loginUserName, s_loginAuthToken, s_loginOpenId, flag);

}

/**
 * 注销回调
 * @param response
 * @param retStatus
 * @param retMessage
 */
JNIEXPORT void JNICALL Java_org_apache_sdknative_SDKKitPlateformCallBackImplWrapper_logoutCallBackJni(JNIEnv * env, jobject arg, jint retStatus, jstring retMessage)
{
    LOGD("Java_org_apache_sdknative_SDKKitPlateformCallBackImplWrapper_logoutCallBack");
    std::string s_retMessage = sdkkit::JniHelper::jstring2string(retMessage);

    SDKKitPlateformCallBackImplWrapper_logoutCallBack(retStatus, s_retMessage);
}

//  /**
//   * 切换账户回调
//   * @param response
//   * @param retStatus
//   * @param retMessage
//   */
//  void switchAccountCallBack(SDKKitResponse response, int retStatus,String retMessage);

/**
 * 支付回调
 * @param response
 * @param retStatus
 * @param retMessage
 */
JNIEXPORT void JNICALL Java_org_apache_sdknative_SDKKitPlateformCallBackImplWrapper_payCallBackJni(JNIEnv * env, jobject arg, jint retStatus, jstring retMessage,
            jstring payKitOrderId)
{
    LOGD("Java_org_apache_sdknative_SDKKitPlateformCallBackImplWrapper_payCallBack");
    std::string s_retMessage = sdkkit::JniHelper::jstring2string(retMessage);
    std::string s_payKitOrderId = sdkkit::JniHelper::jstring2string(payKitOrderId);

    SDKKitPlateformCallBackImplWrapper_payCallBack(retStatus, s_retMessage, s_payKitOrderId);
}

//  void kitCenterCallBack(SDKKitResponse response, int retStatus,String retMessage);
//
//
//  void userCenterCallBack(SDKKitResponse response, int retStatus,String retMessage);

/**
 * 获取订单最终结果
 * @param response
 * @param retStatus
 * @param retMessage
 */
JNIEXPORT void JNICALL Java_org_apache_sdknative_SDKKitPlateformCallBackImplWrapper_getOrderResultCallBackJni(JNIEnv * env, jobject arg, jstring orderStatus, jint retStatus, jstring retMessage)
{
    LOGD("Java_org_apache_sdknative_SDKKitPlateformCallBackImplWrapper_getOrderResultCallBack");
    std::string s_retMessage = sdkkit::JniHelper::jstring2string(retMessage);
    std::string s_orderStatus = sdkkit::JniHelper::jstring2string(orderStatus);

    SDKKitPlateformCallBackImplWrapper_getOrderResultCallBack(retStatus, s_retMessage, s_orderStatus);

}

/**
 * 退出游戏
 * @param retStatus
 * @param retMessage
 */
JNIEXPORT void JNICALL Java_org_apache_sdknative_SDKKitPlateformCallBackImplWrapper_exitGameCallBackJni(JNIEnv * env, jobject arg, jint retStatus, jstring retMessage)
{
    LOGD("Java_org_apache_sdknative_SDKKitPlateformCallBackImplWrapper_exitGameCallBack");
    std::string s_retMessage = sdkkit::JniHelper::jstring2string(retMessage);
    LOGD("Java_org_apache_sdknative_SDKKitPlateformCallBackImplWrapper_exitGameCallBack %s", s_retMessage.c_str());
    SDKKitPlateformCallBackImplWrapper_exitGameCallBack(retStatus, s_retMessage);
}

#ifdef HJR_USE_LUA_SDK
jint JNI_OnLoad(JavaVM* vm, void* reserved)
{
  sdkkit::JniHelper::setJavaVM(vm);
}
#endif

JNIEXPORT void JNICALL Java_org_apache_sdknative_SDKKitPlatformJniHelper_nativeSetContextJni(JNIEnv * env, jobject thiz, jobject context)
 {
    LOGD("Java_org_apache_sdknative_SDKKitPlatformJniHelper_nativeSetContextJni");
    static JavaVM* jvm;
    int status = env->GetJavaVM(&jvm);

    if(status != 0) {
        LOGE("getJavaVM error!!!!!");
    }

    sdkkit::JniHelper::setJavaVM(jvm);

    sdkkit::JniHelper::setClassLoaderFrom(context);
}

#ifdef __cplusplus
}
#endif
