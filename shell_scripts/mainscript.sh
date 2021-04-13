#!/bin/sh

printf "\033[0;31mLoading ammo...\033[0m"
printf "\n"
printf "\033[0;33m━╤デ╦︻\033[0;36m(▀̿̿Ĺ̯̿̿▀̿ ̿)\033[0m"
printf "\n"
bash shell_scripts/import_debugs.sh
bash shell_scripts/parse_file.sh shell_scripts/test_ft_printf.c
############################
#read -p "Do you want to test for Mandatory or Bonus? [m/b] " -n 1 -r
#echo	# (optional) move to a new line
#if [[ ! $REPLY =~ ^[mMbB]$ ]]
#then
#	make fclean
#	exit 1
#fi
#if [[ $REPLY =~ ^[mM]$ ]]
#then
#
#fi
#if [[ $REPLY =~ ^[bB]$ ]]
#then
#
#fi
printf "\033[0;31mAiming...\033[0m"
printf "\n"
printf "\033[0;36m( ´-ω･)\033[0;33m︻┻┳══━一一			\033[0;32mYour ft_printf ヽ(•‿•)ノ\033[0m"
printf "\033[0m\n"

#printf "\033[0;32m(⌐▨_▨)\033[0"
#printf "\033[0;31m( ✖╭╮✖ )\033[0"