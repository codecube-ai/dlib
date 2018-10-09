#include "stream_manager.h"

BaseStreamManager::BaseStreamManager()
{
    printf("BaseStreamManager printf 12312213131231\n");
}

BaseStreamManager::~BaseStreamManager()
{
    printf("BaseStreamManager destroy in\n");
}

bool BaseStreamManager::initialize()
{
    printf("BaseStreamManager initialize in\n");

    return true;
}

bool BaseStreamManager::start()
{
    printf("BaseStreamManager start in\n");
    return true;
}

bool BaseStreamManager::stop()
{
    printf("BaseStreamManager stop in\n");
    return true;
}
