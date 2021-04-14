#!/bin/sh

######################################
############# VARIABLES ##############
######################################
ARGUMENT="$1"

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

TEST_M_C="tests/test_mand_c.c"
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
        sed "s|&|$LINE|g" $TEST_M_C \
		> temp_test.c
		exit 0
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

if [[ $1 = mand* ]]
then
	if [[ $1 = *c ]]
	then
		FILENAME=logs/$C_CONV_M
		while_read_LINE_FD
	fi
elif [[ $1 = *bonus* ]]
then
	echo Bonus
else
	exit 1
fi