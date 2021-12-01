# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/08 10:32:48 by bcosters          #+#    #+#              #
#    Updated: 2021/12/01 11:20:58 by bcosters         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -*- MakeFile for Printf tests -*-

# -*- Variable definitions -*-

#	Project sources/objects/headers

TEST	= temp_test.c
RESULTS = Results.log
FINAL	= finalresults.log

HEAD	= shell_scripts/simple_debugs.h ../ft_printf.h ../include/ft_printf.h ../includes/ft_printf.h ../incl/ft_printf.h

LIB		= debugs.a
LIBHEAD	= simple_debugs.h
SCRIPTDIR	= shell_scripts/
LOGDIR	= $(SCRIPTDIR)logs/

NAME	= test

# Compiler stuff

CC		= gcc

CFLAGS 	= -Wall -Wextra -Werror -I.. -I$(HEAD)

NOFLAG	= -Wno-format -Wno-unused-parameter -Wno-unused-variable

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

$(RESULTS):
			touch $(RESULTS)

test:		$(RESULTS)
			@${CC} ${CFLAGS} ${NOFLAG} ../libftprintf.a ${LIB} ${TEST} -o ${NAME}
			@./${NAME} > result.log
			@rm -f ${NAME}
end:
			@echo "$(ENDC)If there were any $(RED)KO's$(ENDC), check the $(LPURP)$(FINAL)$(ENDC) file for the logs of the tests"

.PHONY:		clean

clean:
	@rm -f ${LIB} ${LIBHEAD}
	@rm -rf ${LOGDIR} ${NAME} ${TEST} ${RESULTS} result.log

fclean:		clean
	@rm -f ${wildcard tests/*mand*} ${wildcard tests/*bonus*}
	@rm -f ${FINAL}


re:			fclean all