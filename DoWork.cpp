#include "DoWork.h"

DoWork::DoWork(QObject *parent)
    : QObject{parent}
{
    res = 1;
}

void DoWork::myworkerfunction()
{
    res = 2;
}
