#ifndef STREAM_MANAGER_H
#define STREAM_MANAGER_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <iostream>
#include <fstream>

class BaseStreamManager
{
public:
    explicit BaseStreamManager();
    virtual ~BaseStreamManager();

    virtual bool initialize();
    virtual bool start();
    virtual bool stop();
private:

};


#endif
