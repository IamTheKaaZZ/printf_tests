#!/bin/sh

######################################
############# VARIABLES ##############
######################################
ARGUMENT="$1"

COUNT=1

C_CONV_M="c_conv_mand.log"
C_CONV_PERCENT="percent_conv.log"
C_CONV_PERCENT_B="percent_conv_b.log"
C_CONV_BHL="c_conv_bonus_hl.log"
C_CONV_BFL="c_conv_bonus_flags.log"

S_CONV_M="s_conv_mand.log"
S_CONV_BHL="s_conv_bonus_hl.log"
S_CONV_BFL="s_conv_bonus_flags.log"

D_CONV_M="d_i_conv_mand.log"
D_CONV_BHL="d_i_conv_bonus_hl.log"
D_CONV_BFL="d_i_conv_bonus_flags.log"

U_CONV_M="u_conv_mand.log"
U_CONV_BHL="u_conv_bonus_hl.log"
U_CONV_BFL="u_conv_bonus_flags.log"

X_CONV_M="x_conv_mand.log"
X_CONV_BHL="x_conv_bonus_hl.log"
X_CONV_BFL="x_conv_bonus_flags.log"

P_CONVERSIONS="p_conversions.log"

TEST_M="tests/test_main.c"
TEST_M_PERC="tests/test_mand_Percent.c"
TEST_M_S="tests/test_mand_s.c"
TEST_M_D="tests/test_mand_d.c"
TEST_M_U="tests/test_mand_u.c"
TEST_M_X="tests/test_mand_x.c"
TEST_M_P="tests/test_mand_p.c"
######################################
function while_read_LINE_FD
{
exec 3<&0
exec 0< $FILENAME
while read LINE
do
		printf "\nTEST $COUNT \033[0;33m－－－＝＝＝＝ \033[0;32mﾍ(ﾟρﾟ)ﾉ~\033[0;0m \n\n"
		printf "\nTEST $COUNT: " >> Results.log
		((COUNT=COUNT+1))
        sed "s|&|$LINE|g" $TEST_M \
		> temp_test.c
		make test
		bash shell_scripts/compare_results.sh ./result.log
        :
done
exec 0<&3
}
######################################
######################################
########### START OF MAIN ############
######################################

# Test the Input

# Looking for exactly one parameter
(( $# == 1 )) || exit 1

printf "\033[0;31mPREPARE YOURSELF!\033[0;0m \n"
printf "\033[0;36m(⌐▀͡ ̯ʖ▀)\033[0;33m︻┻┳══━一一\033[0;0m \n\n"

if [[ $1 = mand* || $1 = *bonus* ]]
then
	if [[ $1 = *c ]]
	then
		FILENAME=logs/$C_CONV_M
		printf "\033[1;32mTEST for %%c\033[0;0m"
		sleep 3
		echo "TEST for %c" >> Results.log
		while_read_LINE_FD
		sed "/Output: OK Return Value: OK /d" < Results.log >> finalresults.log
		rm -f Results.log
	elif [[ $1 = *Percent ]]
	then
		FILENAME=logs/$C_CONV_PERCENT
		printf "\033[1;32mTEST for %%\033[0;0m"
		sleep 3
		echo "TEST for %%" >> Results.log
		while_read_LINE_FD
		sed "/Output: OK Return Value: OK /d" < Results.log >> finalresults.log
		rm -f Results.log
	elif [[ $1 = *s ]]
	then
		FILENAME=logs/$S_CONV_M
		printf "\033[1;32mTEST for %%s\033[0;0m"
		sleep 3
		echo "TEST for %s" >> Results.log
		while_read_LINE_FD
		sed "/Output: OK Return Value: OK /d" < Results.log >> finalresults.log
		rm -f Results.log
	elif [[ $1 = *d ]]
	then
		FILENAME=logs/$D_CONV_M
		printf "\033[1;32mTEST for %%d and %%i\033[0;0m"
		sleep 3
		echo "TEST for %d and %i" >> Results.log
		while_read_LINE_FD
		sed "/Output: OK Return Value: OK /d" < Results.log >> finalresults.log
		rm -f Results.log
	elif [[ $1 = *u ]]
	then
		FILENAME=logs/$U_CONV_M
		printf "\033[1;32mTEST for %%u\033[0;0m"
		sleep 3
		echo "TEST for %u" >> Results.log
		while_read_LINE_FD
		sed "/Output: OK Return Value: OK /d" < Results.log >> finalresults.log
		rm -f Results.log
	elif [[ $1 = *x ]]
	then
		FILENAME=logs/$X_CONV_M
		printf "\033[1;32mTEST for %%x and %%X\033[0;0m"
		sleep 3
		echo "TEST for %x and %X" >> Results.log
		while_read_LINE_FD
		sed "/Output: OK Return Value: OK /d" < Results.log >> finalresults.log
		rm -f Results.log
	elif [[ $1 = *p ]]
	then
		FILENAME=logs/$P_CONVERSIONS
		printf "\033[1;32mTEST for %%p\033[0;0m"
		sleep 3
		echo "TEST for %p" >> Results.log
		while_read_LINE_FD
		sed "/Output: OK Return Value: OK /d" < Results.log >> finalresults.log
		rm -f Results.log
	fi
else
	exit 1
fi
printf "\n \033[0;31mReloading...\033[0;0m \n"
printf "\033[0;33m━╤デ╦︻\033[0;36m(▀̿̿Ĺ̯̿̿▀̿ ̿)\033[0;0m \n\n"
