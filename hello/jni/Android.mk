LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE:=hello

LOCAL_SRC_FILES:=main.cpp

LOCAL_CFLAGS += -Os -fvisibility=hidden

LOCAL_LDLIBS:= -llog

# LOCAL_LDFLAGS:= -Wl,--exclude-libs=libgcc.a
LOCAL_LDFLAGS:= -Wl,--version-script=$(LOCAL_PATH)/libhello.map

include $(BUILD_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE:=test_time

LOCAL_SRC_FILES:=test_time.c

LOCAL_CFLAGS += -Os -fvisibility=hidden

LOCAL_LDLIBS:= -llog

# LOCAL_LDFLAGS:= -Wl,--exclude-libs=libgcc.a
LOCAL_LDFLAGS:= -Wl,--version-script=$(LOCAL_PATH)/libhello.map

include $(BUILD_EXECUTABLE)