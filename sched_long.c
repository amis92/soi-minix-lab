#include <stdio.h>
#include <stdlib.h>
#include <lib.h>

#include "scheduling.h"


#define TRUE 1


int main(int argc, char* argv[])
{
  pid_t pid = getpid();
  char group;
  int index, result;
  result = 1;
  
  if (argc != 2)
  {
    printf("> Usage: %s <sched group:A/B/C>\n", argv[0]);
    return 0;
  }
  
  
  group = getgroup(pid);
  printf("> Process pid=%d (this) is of group '%c'\n", pid, group);
  
  group = argv[1][0];
  if (group <'A' || group > 'C')
  {
    printf("> Invalid group code. Only A,B or C is allowed\n");
    return 0;
  }
  
  
  printf("> Changing group to '%c'...\n", group);
  setgroup(pid, group);
  
  group = getgroup(pid);
  printf("> Process pid=%d (this) is now of group '%c'\n", pid, group);
  
  while (TRUE)
  {
    result = result * index;
    index = result % index;
  }
  return 0;
}