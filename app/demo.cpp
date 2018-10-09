#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <iostream>
#include <fstream>

#include "cc_common.h"
#include "cc_face_detector.h"
//#include "jetson_stream_manager.h"

using namespace std;

int main(int argc, char * argv[])
{

    CC_PRINT("Hello code cube \n");
    CCFaceDetector *de = new CCFaceDetector();
    de->test();

    delete de;

    // BaseStreamManager *streamManager = new JetsonStreamManager();
    //
    // streamManager->initialize();
    //
    // delete streamManager;

    return 0;
}
