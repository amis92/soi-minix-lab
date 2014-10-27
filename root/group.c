#include <stdlib.h>
#include <lib.h>
#include <stdio.h>

int getprocnr ( int pid )
{
	message msg;
	msg.m1_i1 = pid;
	return ( _syscall(MM, 50, &msg) );
}

int getgroupnr ( int pid )
{
	message msg;
	msg.m1_i1 = pid;
	return ( _syscall(MM, 57, &msg) );
}

void setgroupnr ( int pid, int groupnr )
{
	message msg;
	msg.m1_i1 = pid;
	msg.m1_i2 = groupnr;
	( _syscall(MM, 58, &msg) );
	return;
}

#define PROC_TAB_HEADER "PID  syscallPID preGROUP_SET postGROUP_SET\n"
#define PROC_TAB_TEMPLATE "%3d %11d %12d %13d\n"

int main ( int argc, char* argv [] )
{
	int procnr, procgroup;
	int pid = atoi( argv[1] );
	procnr = getprocnr( pid );
	procgroup = getgroupnr ( pid );
	setgroupnr( pid, 2 );
	printf(PROC_TAB_HEADER);
	printf(PROC_TAB_TEMPLATE, pid, procnr, procgroup, getgroupnr( pid ));
	return 0;
}

