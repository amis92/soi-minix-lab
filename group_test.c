#include <stdio.h>
#include <stdlib.h>

char getgroup(int pid)
{
  message m;
  m.m1_i1 = pid;
  return _syscall(SYS_GETSCHEDGROUP, &m, 0);
}

void setgroup(int pid, char group)
{
  message m;
  m.m1_i1 = pid;
  m.m1_i2 = group;
  _syscall(SYS_SETSCHEDGROUP, &m, 0);
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