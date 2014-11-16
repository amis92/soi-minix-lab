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
  int pid = atoi(argv[1]);
  
  if (argc != 3)
  {
    printf("> Usage: %s <app_pid> <new_group:A/B/C>\n", argv[0]);
    return 0;
  }
  
  group = getgroup(pid);
  printf("> Process pid=%d is of group '%c'\n", pid, group);
  
  group = argv[2][0];
  if (group <'A' || group > 'C')
  {
    printf("> Invalid group code. Only A,B or C is allowed\n");
    return 0;
  }
  
  printf("> Changing group to '%c'...\n", group);
  setgroup(pid, group);
  
  group = getgroup(pid);
  printf("> Process pid=%d is now of group '%c'\n", pid, group);
  return 0;
}