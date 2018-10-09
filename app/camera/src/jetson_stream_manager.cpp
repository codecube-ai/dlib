#include "jetson_stream_manager.h"

#include "Error.h"
#include "Thread.h"

#include <Argus/Argus.h>
#include <EGLStream/EGLStream.h>
#include <EGLStream/NV/ImageNativeBuffer.h>

#include <NvEglRenderer.h>
#include <NvJpegEncoder.h>

using namespace Argus;
using namespace EGLStream;

int m_dmabuf = -1;
Size2D<uint32_t> m_preview_size(640, 480);
Size2D<uint32_t> m_capture_size(1920, 1080);
NvEglRenderer *m_renderer;
OutputStream* m_stream;
UniqueObj<FrameConsumer> m_consumer;


JetsonStreamManager::JetsonStreamManager() : BaseStreamManager()
{
    printf("JetsonStreamManager 1111\n");
}

JetsonStreamManager::~JetsonStreamManager()
{
    printf("JetsonStreamManager destroy in\n");
}

bool JetsonStreamManager::initialize()
{
    //BaseStreamManager::initialize();

    UniqueObj<OutputStream> captureStream;

    // Create the CameraProvider object and get the core interface.
    UniqueObj<CameraProvider> cameraProvider = UniqueObj<CameraProvider>(CameraProvider::create());
    ICameraProvider *iCameraProvider = interface_cast<ICameraProvider>(cameraProvider);
    if (!iCameraProvider)
    {
        printf("Failed to create CameraProvider\n");
        return false;
    }

    // Get the camera devices.
    std::vector<CameraDevice*> cameraDevices;
    iCameraProvider->getCameraDevices(&cameraDevices);
    if (cameraDevices.size() == 0)
    {
        printf("No cameras available\n");
        return false;
    }

    ICameraProperties *iCameraProperties = interface_cast<ICameraProperties>(cameraDevices[0]);
    if (!iCameraProperties)
    {
        printf("Failed to get ICameraProperties interface\n");
        return false;
    }

    // Create the capture session using the first device and get the core interface.
    UniqueObj<CaptureSession> captureSession(
            iCameraProvider->createCaptureSession(cameraDevices[0]));
    ICaptureSession *iCaptureSession = interface_cast<ICaptureSession>(captureSession);
    if (!iCaptureSession)
    {
        printf("Failed to get ICaptureSession interface\n");
        return false;
    }

    // Create the OutputStream.
    printf("Creating output stream\n");
    UniqueObj<OutputStreamSettings> streamSettings(iCaptureSession->createOutputStreamSettings());
    IOutputStreamSettings *iStreamSettings = interface_cast<IOutputStreamSettings>(streamSettings);
    if (!iStreamSettings)
    {
        printf("Failed to get IOutputStreamSettings interface\n");
        return false;
    }

    iStreamSettings->setPixelFormat(PIXEL_FMT_YCbCr_420_888);
    iStreamSettings->setEGLDisplay(m_renderer->getEGLDisplay());
    iStreamSettings->setResolution(m_capture_size);
    captureStream = (UniqueObj<OutputStream>)iCaptureSession->createOutputStream(streamSettings.get());

    m_stream = captureStream.get();
    // Create the FrameConsumer.
    m_consumer = UniqueObj<FrameConsumer>(FrameConsumer::create(m_stream));
    if (!m_consumer)
    {
        printf("Failed to create FrameConsumer\n");
        return false;
    }

    IStream *iStream = interface_cast<IStream>(m_stream);
    IFrameConsumer *iFrameConsumer = interface_cast<IFrameConsumer>(m_consumer);

    // Wait until the producer has connected to the stream.
    printf("Waiting until producer is connected...\n");
    if (iStream->waitUntilConnected() != STATUS_OK)
    {
        printf("Stream failed to connect.\n");
        return false;
    }
    printf("Producer has connected; continuing.\n");

    while (true)
    {
        // Acquire a frame.
        UniqueObj<Frame> frame(iFrameConsumer->acquireFrame());
        IFrame *iFrame = interface_cast<IFrame>(frame);
        if (!iFrame)
            break;

        // Get the IImageNativeBuffer extension interface.
        NV::IImageNativeBuffer *iNativeBuffer =
            interface_cast<NV::IImageNativeBuffer>(iFrame->getImage());
        if (!iNativeBuffer)
        {
            printf("IImageNativeBuffer not supported by Image.\n");
            return false;
        }

        // If we don't already have a buffer, create one from this image.
        // Otherwise, just blit to our buffer.
        if (m_dmabuf == -1)
        {
            m_dmabuf = iNativeBuffer->createNvBuffer(iStream->getResolution(),
                                                     NvBufferColorFormat_YUV420,
                                                     NvBufferLayout_BlockLinear);
            if (m_dmabuf == -1)
            {
                printf("\tFailed to create NvBuffer\n");
                return false;
            }
        }
        else if (iNativeBuffer->copyToNvBuffer(m_dmabuf) != STATUS_OK)
        {
            printf("Failed to copy frame to NvBuffer.\n");
            return false;
        }

        // Process frame.
        this->processV4L2Fd(m_dmabuf, iFrame->getNumber());
    }

    printf("Done.\n");


    return true;
}

bool JetsonStreamManager::processV4L2Fd(int32_t fd, uint64_t frameNumber)
{
    return true;
}
