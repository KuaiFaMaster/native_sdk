LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := lua_sdkkit

LOCAL_MODULE_FILENAME := liblua_sdkkit

LOCAL_LDLIBS := -llog

LOCAL_SRC_FILES :=  SdkkitJniHelper.cpp \
					sdkkit.cpp

LOCAL_C_INCLUDES := $(LOCAL_PATH) \
					$(LOCAL_PATH)/lua \


LOCAL_CXXFLAGS += -fexceptions -fPIC

include $(BUILD_STATIC_LIBRARY)

#LOCAL_ALLOW_UNDEFINED_SYMBOLS := true
#include $(BUILD_SHARED_LIBRARY)
