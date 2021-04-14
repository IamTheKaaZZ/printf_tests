#!/bin/sh

read -p "Do you want to test for Mandatory or Bonus? [m/b] " -n 1 -r
echo	# (optional) move to a new line
if [[ $REPLY =~ ^[mM]$ ]]
then
	bash shell_scripts/configure_tests.sh mand_c
	bash shell_scripts/configure_tests.sh mand_Percent
	bash shell_scripts/configure_tests.sh mand_s
	bash shell_scripts/configure_tests.sh mand_d
	bash shell_scripts/configure_tests.sh mand_u
	bash shell_scripts/configure_tests.sh mand_x
	bash shell_scripts/configure_tests.sh mand_p
	printf "\033[0;36m(⌐▀͡ ̯ʖ▀)\033[0;33m︻┻┳══━一一 *click* *click*\033[0;0m \n\n"
	printf "\033[0;36m(⌐▀͡ ̯ʖ▀)\033[0;31m Looks like I'm out of ammo...\033[0;0m \n\n"
	printf "\033[0;36m(▀̿̿Ĺ̯̿▀̿ ̿)\033[0;31m We will meet again next time...\033[0;0m \n"
	make clean
elif [[ $REPLY =~ ^[bB]$ ]]
then
	echo "Bonus is not done yet LOL"
	make fclean && exit 0
else
	make fclean && exit 1
fi