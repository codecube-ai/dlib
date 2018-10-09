#ifndef JETSON_STREAM_MANAGER_H
#define JETSON_STREAM_MANAGER_H

#include "stream_manager.h"

#include "Error.h"
#include "Thread.h"

#include <Argus/Argus.h>
#include <EGLStream/EGLStream.h>
#include <EGLStream/NV/ImageNativeBuffer.h>

#include <NvEglRenderer.h>
#include <NvJpegEncoder.h>

using namespace Argus;
using namespace EGLStream;

class JetsonStreamManager : public BaseStreamManager
{
public:
    JetsonStreamManager();
    ~JetsonStreamManager();

    bool initialize();

private:
    Size2D<uint32_t> m_preview_size;
    Size2D<uint32_t> m_capture_size;
    NvEglRenderer *m_renderer;
    OutputStream* m_stream;
    int m_dmabuf;
    UniqueObj<FrameConsumer> m_consumer;

    bool processV4L2Fd(int32_t fd, uint64_t frameNumber);
};

#endif
