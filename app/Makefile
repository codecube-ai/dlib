
DEBUG=1

DECECTOR_APP := cc_face_detector

CC=gcc
CPP=g++
NVCC=nvcc
AR=ar

COMMON= -I./header

ifeq ($(DEBUG), 1)
IF_DEBUG=-O0 -g
endif

DETECTOR_CPPFLAGS+=$(IF_DEBUG)

DECECTOR_SRCS := \
	$(wildcard src/*.cpp)

DECECTOR_OBJS = $(DECECTOR_SRCS:.cpp=.o)


detector: $(DECECTOR_APP)

%.o: %.cpp
	@echo "Compiling: $<"
	$(CPP) $(COMMON) $(DETECTOR_CPPFLAGS) -c $< -o $@

$(DECECTOR_APP): $(DECECTOR_OBJS)
	@echo "Linking: $@"
	$(CPP) $(COMMON) -o $@ $(DECECTOR_OBJS) $(DETECTOR_CPPFLAGS)

clean:
	@rm -rf $(DECECTOR_APP) $(DECECTOR_OBJS)
