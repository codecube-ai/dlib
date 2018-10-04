
DEBUG=1

DECECTOR_APP := cc_face_detector

CC=gcc
CPP=g++
NVCC=nvcc
AR=ar
ARFLAGS=rcs

COMMON= -I./header
DETECTOR_ALIB=libccdetector.a
DETECTOR_SLIB=libccdetector.so

ifeq ($(DEBUG), 1)
IF_DEBUG=-O0 -g
endif

DETECTOR_CPPFLAGS+=$(IF_DEBUG)
DETECTOR_CPPFLAGS+=-fPIC

DECECTOR_SRCS := \
	$(wildcard src/*.cpp)

DECECTOR_OBJS = $(DECECTOR_SRCS:.cpp=.o)


all: $(DETECTOR_SLIB) $(DETECTOR_ALIB) $(DECECTOR_APP)

detector_so: $(DETECTOR_SLIB)

detector_a: $(DETECTOR_ALIB)

$(DETECTOR_SLIB): $(DECECTOR_OBJS)
	$(CPP) $(COMMON) -shared -o $@ $(DECECTOR_OBJS) $(DETECTOR_CPPFLAGS)

$(DETECTOR_ALIB): $(DECECTOR_OBJS)
	$(AR) $(ARFLAGS) $@ $^

%.o: %.cpp
	@echo "Compiling: $<"
	$(CPP) $(COMMON) $(DETECTOR_CPPFLAGS) -c $< -o $@

$(DECECTOR_APP): $(DECECTOR_OBJS)
	@echo "Linking: $@"
	$(CPP) $(COMMON) -o $@ $(DECECTOR_OBJS) $(DETECTOR_CPPFLAGS)

clean:
	@rm -rf $(DECECTOR_APP) $(DECECTOR_OBJS) $(DETECTOR_SLIB) $(DETECTOR_ALIB)
