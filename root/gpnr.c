
#include <lib.h>
#include <errno.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>


void
main( void )
{
	int ind, p, n;
	message msg;

	n = 1;
	msg.m1_i1=n;
	ind = _syscall( MM, GETPROCNR, &msg );
	if( ind < 0 )
		printf( "Nie ma..\n" );
	else
		printf( "id = %d ma indeks [ %d ]\n", n, ind );
}
