#!/usr/bin/sh

######################################
############# VARIABLES ##############
######################################

FILENAME="$1"
THIS_SCRIPT=$(basename $0)
OUTPUTFILE="output_line_parse.log"

C_CONVERSIONS="c_conversions.log"
C_CONV_M="c_conv_mand.log"
C_CONV_PERCENT="percent_conv.log"
C_CONV_PERCENT_B="percent_conv_b.log"
C_CONV_BHL="c_conv_bonus_hl.log"
C_CONV_BFL="c_conv_bonus_flags.log"

S_CONVERSIONS="s_conversions.log"
S_CONV_M="s_conv_mand.log"
S_CONV_BHL="s_conv_bonus_hl.log"
S_CONV_BFL="s_conv_bonus_flags.log"

D_CONVERSIONS="d_i_conversions.log"
D_CONV_M="d_i_conv_mand.log"
D_CONV_BHL="d_i_conv_bonus_hl.log"
D_CONV_BFL="d_i_conv_bonus_flags.log"

U_CONVERSIONS="u_conversions.log"
U_CONV_M="u_conv_mand.log"
U_CONV_BHL="u_conv_bonus_hl.log"
U_CONV_BFL="u_conv_bonus_flags.log"

X_CONVERSIONS="x_conversions.log"
X_CONV_M="x_conv_mand.log"
X_CONV_BHL="x_conv_bonus_hl.log"
X_CONV_BFL="x_conv_bonus_flags.log"

P_CONVERSIONS="p_conversions.log"

######################################
############# FUNCTIONS ##############
######################################

function usage
{
printf "\nUSAGE: $THIS_SCRIPT  file_to_process\n"
printf "OR - To send the output to a different file use: "
printf "\n$THIS_SCRIPT  file_to_process  > output_file_name 2>&1 \n"
exit 1
}
######################################
function while_read_LINE_FD
{
exec 3<&0
exec 0< $FILENAME
while read LINE
do
        $LINE > awk '/printf/ {print}'
        :
done
exec 0<&3
}
######################################
function get_printf_statements
{
awk '/retval/ {print substr($0, index($0, $3))}' $FILENAME \
| awk 'NR==2, NR==509 {print $0}' \
| sed 's|, retval||g' \
| sed 's| = \|%d\|||g' \
| sed 's| = \[%d\]||g' \
| sed 's|ft_printf||g' \
| sed 's|;||g' | sed "s|]..|]|g" \
| sed '190,191d' \
> logs/$OUTPUTFILE

}
######################################
function get_d_conv_lines
{
grep "[- +#.*0-9].*[di]\]" logs/$OUTPUTFILE \
| awk 'NR==1, NR==100 {print $0}' \
| sed "s|\".*\[|\"[|g" \
> logs/$D_CONVERSIONS


grep "[hl].*[di]" logs/$D_CONVERSIONS \
> logs/$D_CONV_BHL

grep "[- +#].*[di]" logs/$D_CONVERSIONS \
| sed '1,29d' \
| sed '27,38d' \
| sed '34,47d' \
> logs/$D_CONV_BFL

sed -n -e 1,9p -e 30,31p -e 34p -e 37p -e 46,48p -e 57,81p -e 84,97p logs/$D_CONVERSIONS \
> logs/$D_CONV_M

#rm logs/$D_CONVERSIONS
}
######################################
function get_x_conv_lines
{
grep "[- +#.*0-9].*[xX]\]" logs/$OUTPUTFILE \
> logs/$X_CONVERSIONS

grep "[hl].*[xX]" logs/$X_CONVERSIONS \
> logs/$X_CONV_BHL

sed 's/[di]/x/g' logs/$D_CONV_M \
> logs/$X_CONV_M
sed 's/[di]/X/g' logs/$D_CONV_M \
>> logs/$X_CONV_M
sed -n '66,69p' logs/$X_CONVERSIONS \
>> logs/$X_CONV_M

grep "#" logs/$X_CONVERSIONS \
> logs/$X_CONV_BFL
#rm logs/$X_CONVERSIONS
}
######################################
function get_u_conv_lines
{
grep "[- +#.*0-9].*u\]" logs/$OUTPUTFILE \
| sed -n '1,3p' > logs/$U_CONV_M
grep "[- +#.*0-9].*u\]" logs/$OUTPUTFILE \
| sed '1,3d' > logs/$U_CONV_BHL
sed 's/[di]/u/g' logs/$D_CONV_M \
>> logs/$U_CONV_M
sed 's/[di]/u/g' logs/$D_CONV_BFL \
> logs/$U_CONV_BFL
}
######################################
function get_c_perc_conv_lines
{
grep "[- +#.*0-9].*c" logs/$OUTPUTFILE \
| sed '43,49d' \
> logs/$C_CONVERSIONS

sed 's/[di]/c/g' logs/$D_CONV_M \
| sed 's/1000000/48/g' \
| sed 's/42/48/g' \
| sed 's/-42/48/g' \
| sed 's/-48/48/g' \
| sed 's/INT_M[AI][XN]/126/g' \
| sed 's/U126/126/g' \
| sed 's/ 1)/ 69)/g' \
| sed 's/ 1,/ 69,/g' \
| sed 's/ -[0-9].*)/ 69)/g' \
| sed '24 s/, 69/, -5, 69/' \
| sed '25 s/, 69/, -20, 69/' \
| sed '32 s/, 69/, 0, 69/' \
| sed '18,19 s/, 69/, 5, 69/' \
| sed '54,55d' \
> logs/$C_CONV_M
sed -n '1,2p' logs/$C_CONVERSIONS >> logs/$C_CONV_M

grep "lc" logs/$C_CONVERSIONS > logs/$C_CONV_BHL
sed -n '3,42p' logs/$C_CONVERSIONS > logs/$C_CONV_BFL

sed -n '250,252p' logs/$OUTPUTFILE > logs/$C_CONV_PERCENT
sed -e '1,9d; 29,30d; 54,55d;' logs/$C_CONV_M \
| sed 's/c\]/%\]/g' \
| sed 's/, 69//g' \
| sed 's/, 48//g' \
| sed 's/, 126//g' \
>> logs/$C_CONV_PERCENT

sed -e 's/c\]/%\]/g; s/, [-0-9].*/)/g' logs/$C_CONV_BFL > logs/$C_CONV_PERCENT_B
#rm logs/$C_CONVERSIONS
}
######################################
function get_s_conv_lines
{
grep "[- +#.*0-9].*s" logs/$OUTPUTFILE \
| sed '39,57d' \
> logs/$S_CONVERSIONS

sed -n -e '1,3p; 12,38p;' logs/$S_CONVERSIONS > logs/$S_CONV_M
sed -n '3,11p' logs/$S_CONVERSIONS > logs/$S_CONV_BFL
sed -n '39,44p' logs/$S_CONVERSIONS > logs/$S_CONV_BHL
#rm logs/$S_CONVERSIONS
}
######################################
function get_p_conv_lines
{
sed -n '309,310p' logs/$OUTPUTFILE \
| sed 's|STRING.*\[|STRING = \%s, ADDRESS = \[|g' \
> logs/$P_CONVERSIONS
sed -n '1p' logs/$P_CONVERSIONS | sed 's/%p/%0p/g' >> logs/$P_CONVERSIONS
sed -n '1p' logs/$P_CONVERSIONS | sed 's/%p/%-p/g' >> logs/$P_CONVERSIONS
sed -n '1p' logs/$P_CONVERSIONS | sed 's/%p/% p/g' >> logs/$P_CONVERSIONS
sed -n '1p' logs/$P_CONVERSIONS | sed 's/%p/%+p/g' >> logs/$P_CONVERSIONS
sed -n '1p' logs/$P_CONVERSIONS | sed 's/%p/%#p/g' >> logs/$P_CONVERSIONS
sed -n '1p' logs/$P_CONVERSIONS | sed 's/%p/%#0- +p/g' >> logs/$P_CONVERSIONS
sed -n '1p' logs/$P_CONVERSIONS | sed 's/%p/%42p/g' >> logs/$P_CONVERSIONS
sed -n '1p' logs/$P_CONVERSIONS | sed 's/%p/%.42p/g' >> logs/$P_CONVERSIONS
sed -n '1p' logs/$P_CONVERSIONS | sed 's/%p/%42.42p/g' >> logs/$P_CONVERSIONS
}
######################################
########### START OF MAIN ############
######################################

# Test the Input

# Looking for exactly one parameter
(( $# == 1 )) || usage

# Does the file exist as a regular file?
[[ -f $1 ]] || usage

mkdir -p logs/
get_printf_statements
get_d_conv_lines
get_x_conv_lines
get_u_conv_lines
get_c_perc_conv_lines
get_s_conv_lines
get_p_conv_lines
#rm logs/$OUTPUTFILE
