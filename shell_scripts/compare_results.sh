#!/bin/sh



######################################
########### START OF MAIN ############
######################################

# Test the Input

# Looking for exactly one parameter
(( $# == 1 )) || exit 1

COMP_OUT=$(head -n 2 $1 | uniq -c)
COMP_RET=$(tail -n 1 $1 | uniq -c)

if [[ $COMP_OUT = *2* ]]
then
	printf "\033[0;0m Output:	\033[0;32mOK	(⌐▨_▨)\033[0;0m \n"
	printf "Output: OK " >> Results.log
else
	echo "Output:			KO	( ✖╭╮✖ )" >> Results.log
	sed -n '27p' temp_test.c >> Results.log
	printf "\033[0;0m Output:	\033[0;31mKO	( ✖╭╮✖ )\033[0;0m \n"
fi
if [[ $COMP_RET = *OK ]]
then
	printf "\033[0;0m Return Value:	\033[0;32mOK	(⌐▨_▨)\033[0;0m \n"
	printf "Return Value: OK " >> Results.log
else
	echo "Return Value:	KO	( ✖╭╮✖ )" >> Results.log
	sed -n '27p' temp_test.c >> Results.log
	printf "\033[0;0m Return Value:	\033[0;31mKO	( ✖╭╮✖ )\033[0;0m \n"
fi