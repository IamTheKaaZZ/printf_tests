/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 11:47:35 by bcosters          #+#    #+#             */
/*   Updated: 2021/04/14 09:41:13 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../simple_debugs.h"
#include "../../ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main()
{
	int		ret1;
	int		ret2;
	char	*string = "That's a nice string you got there...";
	char	*ptrnull = NULL;

	ret1 = printf("[%c]", 0);
	printf("\n");
	ret2 = ft_printf("[%c]", 0);
	printf("\n");
	if (ret1 == ret2)
		printf("OK");
	else
		printf("KO");
	check_leaks();
}
