/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 11:47:35 by bcosters          #+#    #+#             */
/*   Updated: 2021/04/14 10:44:12 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simple_debugs.h"
#include "../include/ft_printf.h"
#include <stdio.h>
#include <limits.h>
#include <unistd.h>

int	main()
{
	int		ret1;
	int		ret2;
	char	*string = "That's a nice string you got there...";
	char	*ptrnull = NULL;

	ret1 = printf&;
	ret2 = ft_printf&;
	write(1, "\n", 1);
	if (ret1 == ret2)
		printf("\nOK");
	else
		printf("\nKO");
	check_leaks();
}