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

int main(int argc, char* argv[])
{
  char group;
  int pid = atoi(argv[0]);
  
  group = getgroup(pid);
  printf("> process pid=%d is of group=%c\n", pid, group);
  
  group = (char) atoi(argv[1]);
  printf("changing group to '%c'...\n", group);
  setgroup(pid, group);
  
  group = getgroup(pid);
  printf("> process pid=%d is now of group=%c\n", pid, group);
  return 0;
}