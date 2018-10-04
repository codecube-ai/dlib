
DEBUG=1

DECECTOR_APP := cc_face_detector

CC=gcc
CPP=g++
NVCC=nvcc
AR=ar


ifeq ($(DEBUG), 1)
DETECTOR_OPTS=-O0 -g
endif

DETECTOR_CPPFLAGS+=$(DETECTOR_OPTS)

DECECTOR_SRCS := \
	cc_face_detector.cpp

DECECTOR_OBJS := $(DECECTOR_SRCS:.cpp=.o)



detector: $(DECECTOR_APP)

%.o: %.cpp cc_common.h
	@echo "Compiling: $<"
	$(CPP) $(DETECTOR_CPPFLAGS) -c $< -o $@

$(DECECTOR_APP): $(DECECTOR_OBJS)
	@echo "Linking: $@"
	$(CPP) -o $@ $(DECECTOR_OBJS) $(DETECTOR_CPPFLAGS)

clean:
	@rm -rf $(DECECTOR_APP) $(DECECTOR_OBJS)
