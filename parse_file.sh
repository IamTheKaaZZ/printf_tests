#!/usr/bin/sh

######################################
############# VARIABLES ##############
######################################

FILENAME="$1"
THIS_SCRIPT=$(basename $0)
OUTPUTFILE="output_line_parse.log"

D_CONVERSIONS="d_i_conversions.log"
D_CONV_M="d_i_conv_mand.log"
D_CONV_BHL="d_i_conv_bonus_hl.log"
D_CONV_BFL="d_i_conv_bonus_flags.log"

X_CONVERSIONS="x_conversions.log"
X_CONV_M="x_conv_mand.log"
X_CONV_BHL="x_conv_bonus_hl.log"
X_CONV_BFL="x_conv_bonus_flags.log"

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
| sed 's|;||g' > logs/$OUTPUTFILE
}

######################################
function get_d_conv_lines
{
grep "[- +#.*0-9].*[di]\]" logs/$OUTPUTFILE \
| awk 'NR==1, NR==100 {print $0}' \
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

rm logs/$D_CONVERSIONS
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
