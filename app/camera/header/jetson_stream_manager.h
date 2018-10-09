#ifndef JETSON_STREAM_MANAGER_H
#define JETSON_STREAM_MANAGER_H

#include "stream_manager.h"


class JetsonStreamManager : public BaseStreamManager
{
public:
    JetsonStreamManager();
    ~JetsonStreamManager();

    bool initialize();

private:

    bool processV4L2Fd(int32_t fd, uint64_t frameNumber);
};

#endif
