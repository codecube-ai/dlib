#include "cc_face_detector.h"
#include "cc_common.h"

#include "../../dlib/dnn.h"
#include "../../dlib/clustering.h"
#include "../../dlib/string.h"
#include "../../dlib/image_io.h"
#include "../../dlib/image_processing/frontal_face_detector.h"

using namespace dlib;

CCFaceDetector::CCFaceDetector()
{
    printf("CCFaceDetector printf 123122131312131\n");
}

CCFaceDetector::~CCFaceDetector()
{
    printf("CCFaceDetector destroy in\n");
}

void CCFaceDetector::test()
{
    printf("CCFaceDetector test in\n");

    return;
}
