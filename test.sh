#!bin/sh
echo ""
echo ">starting process with priority A (tickets no=5)"
./sched_long A &
echo ""
echo ">starting process with priority B (tickets no=10)"
./sched_long B &
echo ""
echo ">starting process with priority C (tickets no=2)"
./sched_long C &
echo ""
