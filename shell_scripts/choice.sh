#!/bin/sh

read -p "Do you want to test for Mandatory or Bonus? [m/b] " -n 1 -r
echo	# (optional) move to a new line
if [[ $REPLY =~ ^[mM]$ ]]
then
	cp tests/test_main.c tests/test_mand_c.c
	bash shell_scripts/configure_tests.sh mand_c
	cp tests/test_main.c tests/test_mand_Percent.c
	cp tests/test_main.c tests/test_mand_s.c
	cp tests/test_main.c tests/test_mand_d.c
	cp tests/test_main.c tests/test_mand_u.c
	cp tests/test_main.c tests/test_mand_x.c
	cp tests/test_main.c tests/test_mand_p.c
elif [[ $REPLY =~ ^[bB]$ ]]
then
	exit 0
else
	make fclean && exit 1
fi