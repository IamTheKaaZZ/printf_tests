# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/08 10:32:48 by bcosters          #+#    #+#              #
#    Updated: 2021/04/13 15:41:38 by bcosters         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -*- MakeFile for Printf tests -*-

# -*- Variable definitions -*-

#	Project sources/objects/headers

TEST	= test_main.c

HEAD	= shell_scripts/simple_debugs.h ../ft_printf.h

LIB		= debugs.a
LIBHEAD	= simple_debugs.h
SCRIPTDIR	= shell_scripts/
LOGDIR	= logs/

NAME	= test_

# Compiler stuff

CC		= gcc

CFLAGS 	= -Wall -Wextra -Werror

NOFLAG	= -Wno-format

# Shell scripts

IMPORT	= import_debugs.sh
YESNO	= yesno.sh
MAIN	= mainscript.sh
CHOICE	= choice.sh


# COLOURS!!!!!

RED		= \033[0;31m
GREEN	= \033[0;32m
LGREEN	= \033[1;32m
ORANGE	= \033[0;33m
YELLOW	= \033[1;33m
LPURP	= \033[1;35m
CYAN	= \033[0;36m
ENDC	= \033[0m

# -*- Rules -*-
#target: dependencies
#	action

#	Normal rules

all:		start debugs choice end #b

#Welcome message
start:
			@echo "Welcome to $(LGREEN)PRINTF TESTER$(ENDC): $(YELLOW)RAPID FIRE $(LPURP)EDITION$(ENDC)"
			@echo "The builtin tester checks for $(CYAN)memory leaks$(ENDC)."
			@echo "Do you want to $(GREEN)start$(ENDC) the $(RED)FUN$(ENDC)?"
			@bash $(SCRIPTDIR)$(YESNO)
			@echo

#Import debugs
debugs:
			@bash $(SCRIPTDIR)$(MAIN)
			@echo

#	MANDATORY
choice:
			@bash $(SCRIPTDIR)$(CHOICE)
			@echo

end:
			@echo "$(ENDC)If there were any $(RED)KO's$(ENDC), check the $(LPURP)deepthought$(ENDC) folder for the logs of the tests"
			@echo "$(YELLOW)YOUR RESULT:$(ENDC) test1.log, $(CYAN)INTENDED OUTPUT:$(ENDC) test1output.log"

.PHONY:		clean

clean:
	@rm -f ${LIB} ${LIBHEAD}
	@rm -rf ${LOGDIR}

fclean:		clean
	@rm -f ${wildcard tests/*mand*} ${wildcard tests/*bonus*}

re:			fclean all