#ifndef SCHEDULING_GROUP_CALLS_H
#define SCHEDULING_GROUP_CALLS_H

#include <stdio.h>
#include <stdlib.h>
#include <lib.h>

char getgroup(int pid)
{
  message m;
  m.m1_i1 = pid;
  return _syscall(MM, GETSCHEDGROUP, &m);
}

void setgroup(int pid, char group)
{
  message m;
  m.m1_i1 = pid;
  m.m1_i2 = group;
  _syscall(MM, SETSCHEDGROUP, &m);
}

#endif //SCHEDULING_GROUP_CALLS_H
