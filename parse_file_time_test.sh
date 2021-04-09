#!/usr/bin/sh
#
# SCRIPT: 12_ways_to_parse.ksh.ksh
#
#
# REV: 1.2.A
#
# PURPOSE:  This script shows the different ways of reading
#       a file line by line.  Again there is not just one way
#       to read a file line by line and some are faster than
#       others and some are more intuitive than others.
#
# REV LIST:
#
#       03/15/2002 - Randy Michael
#       Set each of the while loops up as functions and the timing
#       of each function to see which one is the fastest.
#
#######################################################################
#
#       NOTE: To output the timing to a file use the following syntax:
#
#          12_ways_to_parse.ksh file_to_process  > output_file_name 2>&1
#
#       The actaul timing data is sent to standard error, file
#       descriptor (2), and the function name header is sent
#       to standard output, file descriptor (1).
#
#######################################################################
#
# set -n  # Uncomment to check command syntax without any execution
# set -x  # Uncomment to debug this script
#

FILENAME="$1"
TIMEFILE="/tmp/loopfile.out"
>$TIMEFILE
THIS_SCRIPT=$(basename $0)

######################################
function usage
{
printf "\nUSAGE: $THIS_SCRIPT  file_to_process\n"
printf "OR - To send the output to a file use: "
printf "\n$THIS_SCRIPT  file_to_process  > output_file_name 2>&1 \n"
exit 1
}
######################################
function while_read_LINE
{
cat $FILENAME | while read LINE
do
        echo "$LINE"
        :
done
}
######################################
function while_read_LINE_bottom
{
while read LINE
do
        echo "$LINE"
        :

done < $FILENAME
}
######################################
######################################
function while_read_LINE_FD
{
exec 3<&0
exec 0< $FILENAME
while read LINE
do
        echo "$LINE"
        :
done
exec 0<&3
}
######################################
########### START OF MAIN ############
######################################

# Test the Input

# Looking for exactly one parameter
(( $# == 1 )) || usage

# Does the file exist as a regular file?
[[ -f $1 ]] || usage

printf "\nStarting File Processing of each Method\n"

printf "Method 1:"
printf "\nfunction while_read_LINE\n" >> $TIMEFILE
printf "function while_read_LINE"
time while_read_LINE >> $TIMEFILE
printf "Method 2:"
printf "\nfunction while_read_LINE_bottom\n" >> $TIMEFILE
printf "function while_read_LINE_bottom"
time while_read_LINE >> $TIMEFILE
printf "Method 3:"
printf "\nfunction while_read_LINE_FD\n" >> $TIMEFILE
printf "function while_read_LINE_FD"
time while_read_LINE_FD >> $TIMEFILE