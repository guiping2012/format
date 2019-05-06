#include "format.h"

CTwin::CTwin()
{
    //lpToken = NULL;
    //rpToken = NULL;
    start = -1;
    end = -1;
}

int CTwin::getStartIndex()
{
    return start;
}
int CTwin::getEndIndex()
{
    return end;
}
bool CTwin::hasStart()
{
    return start >= 0;
}
bool CTwin::hasEnd()
{
    return end >= 0;
}
void CTwin::setStartIndex(int index)
{
    start = index;
}
void CTwin::setEndIndex(int index)
{
    end = index;
}
