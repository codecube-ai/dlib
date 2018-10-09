include Rules.mk


CAMERA_LIB := ../lib/libcamera.a

ARGUS_UTILS_DIR := $(TOP_DIR)/argus/samples/utils

COMMON= -I./header
ARFLAGS=rcs

SRCS := \
	src/stream_manager.cpp \
	src/jetson_stream_manager.cpp \
	$(wildcard $(CLASS_DIR)/*.cpp) \
	$(ARGUS_UTILS_DIR)/Thread.cpp

OBJS := $(SRCS:.cpp=.o)

CPPFLAGS += \
	-I"$(ARGUS_UTILS_DIR)"

LDFLAGS += \
	-lnveglstream_camconsumer -largus

all: $(CAMERA_LIB)

$(CLASS_DIR)/%.o: $(CLASS_DIR)/%.cpp
	$(AT)$(MAKE) -C $(CLASS_DIR)

%.o: %.cpp
	@echo "Compiling: $<"
	$(CPP) $(COMMON) $(CPPFLAGS) -c $< -o $@ -g

$(CAMERA_LIB): $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

# $(CAMERA_LIB): $(OBJS)
# 	@echo "Linking: $@"
# 	$(CPP) $(COMMON) -o $@ $(OBJS) $(CPPFLAGS) $(LDFLAGS) $(DARKNET_LIB)

clean:
	$(AT)rm -rf $(CAMERA_LIB) $(OBJS)

test: $(OBJS)
	@echo $(SRCS)
