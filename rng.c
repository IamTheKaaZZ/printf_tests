/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rng.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 11:45:31 by bcosters          #+#    #+#             */
/*   Updated: 2021/04/09 11:57:06 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

//
// returns random integer from 1 to lim (Bill's generator)
//
int rand3(int lim, long seed)
{
        static long a = 3;
		a += seed;

        a = (((a * 214013L + 2531011L) >> 16) & 32767);

        return ((a % lim) + 1);
}

int	main()
{
	long	i = 1;
	printf("Random number = %d\n", rand3(100, i));
	printf("Random number = %d\n", rand3(100, i));
	printf("Random number = %d\n", rand3(100, i));
	printf("Random number = %d\n", rand3(100, i));
	printf("Random number = %d\n", rand3(100, i));
	printf("Random number = %d\n", rand3(100, i));
	printf("Random number = %d\n", rand3(100, i++));
	printf("Random number = %d\n", rand3(100, i));
	printf("Random number = %d\n", rand3(100, i));
	printf("Random number = %d\n", rand3(100, i));
	printf("Random number = %d\n", rand3(100, i));
	printf("Random number = %d\n", rand3(100, i));
	printf("Random number = %d\n", rand3(100, i));
	printf("Random number = %d\n", rand3(100, i++));
	printf("Random number = %d\n", rand3(100, i));
	printf("Random number = %d\n", rand3(100, i));
	printf("Random number = %d\n", rand3(100, i));
	printf("Random number = %d\n", rand3(100, i));
	printf("Random number = %d\n", rand3(100, i));
	printf("Random number = %d\n", rand3(100, i));
	printf("Random number = %d\n", rand3(100, i++));
	printf("Random number = %d\n", rand3(100, i));
	printf("Random number = %d\n", rand3(100, i));
	printf("Random number = %d\n", rand3(100, i));
	printf("Random number = %d\n", rand3(100, i));
	printf("Random number = %d\n", rand3(100, i));
	printf("Random number = %d\n", rand3(100, i));
	printf("Random number = %d\n", rand3(100, i++));
	printf("Random number = %d\n", rand3(100, i));
	printf("Random number = %d\n", rand3(100, i));
	printf("Random number = %d\n", rand3(100, i));
	printf("Random number = %d\n", rand3(100, i));
	printf("Random number = %d\n", rand3(100, i));
	printf("Random number = %d\n", rand3(100, i));
	printf("Random number = %d\n", rand3(100, i++));
	printf("Random number = %d\n", rand3(100, i));
	printf("Random number = %d\n", rand3(100, i));
	printf("Random number = %d\n", rand3(100, i));
	printf("Random number = %d\n", rand3(100, i));
	printf("Random number = %d\n", rand3(100, i));
	printf("Random number = %d\n", rand3(100, i));
}