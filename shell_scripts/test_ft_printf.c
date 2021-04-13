/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 15:44:38 by bcosters          #+#    #+#             */
/*   Updated: 2021/04/06 18:09:36 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../simple_debug/simple_debugs.h"
#include <float.h>

int	main()
{
	int	retval;

	retval = ft_printf("CONVERSION TESTS, retval = |%d|\n", retval);
	// %d == %i
	retval = ft_printf("\nNORMAL DECIMALS, retval = |%d|\n", retval);
	retval = ft_printf("NORMAL \'d\'\n\t[%d], retval = |%d|\n", 0, retval);
	retval = ft_printf("NORMAL \'d\'\n\t[%.d], retval = |%d|\n", 0, retval);
	retval = ft_printf("NORMAL \'d\'\n\t[%.d], retval = |%d|\n", 1, retval);
	retval = ft_printf("NORMAL \'d\'\n\t[%.d], retval = |%d|\n", 42, retval);
	retval = ft_printf("NORMAL \'d\'\n\t[%d], retval = |%d|\n", INT_MAX, retval);
	retval = ft_printf("NORMAL \'d\'\n\t[%d], retval = |%d|\n", INT_MIN, retval);
	retval = ft_printf("NORMAL \'i\'\n\t[%i], retval = |%d|\n", 0, retval);
	retval = ft_printf("NORMAL \'i\'\n\t[%i], retval = |%d|\n", INT_MAX, retval);
	retval = ft_printf("NORMAL \'i\'\n\t[%i], retval = |%d|\n", INT_MIN, retval);
	// %hd
	retval = ft_printf("\nSHORT DECIMALS, retval = |%d|\n", retval);
	retval = ft_printf("SHORT \'hd\'\n\t[%hd], retval = |%d|\n", 0, retval);
	retval = ft_printf("SHORT \'hd\'\n\t[%hd], retval = |%d|\n", SHRT_MAX, retval);
	retval = ft_printf("SHORT \'hd\'\n\t[%hd], retval = |%d|\n", SHRT_MIN, retval);
	retval = ft_printf("SHORT(OVERFLOW, retval) \'hd\'\n\t[%hd], retval = |%d|\n", SHRT_MAX + 1, retval);
	retval = ft_printf("SHORT(OVERFLOW, retval) \'hd\'\n\t[%hd], retval = |%d|\n", SHRT_MIN - 1, retval);
	// %hhd
	retval = ft_printf("\nSHORTCHAR DECIMALS, retval = |%d|\n", retval);
	retval = ft_printf("SHORTCHAR \'hhd\'\n\t[%hhd], retval = |%d|\n", 0, retval);
	retval = ft_printf("SHORTCHAR \'hhd\'\n\t[%hhd], retval = |%d|\n", SCHAR_MAX, retval);
	retval = ft_printf("SHORTCHAR \'hhd\'\n\t[%hhd], retval = |%d|\n", SCHAR_MIN, retval);
	retval = ft_printf("SHORTCHAR(OVERFLOW, retval) \'hhd\'\n\t[%hhd], retval = |%d|\n", SCHAR_MAX + 1, retval);
	retval = ft_printf("SHORTCHAR(OVERFLOW, retval) \'hhd\'\n\t[%hhd], retval = |%d|\n", SCHAR_MIN - 1, retval);
	// %ld
	retval = ft_printf("\nLONG DECIMALS, retval = |%d|\n", retval);
	retval = ft_printf("LONG \'ld\'\n\t[%ld], retval = |%d|\n", 0, retval);
	retval = ft_printf("LONG \'ld\'\n\t[%ld], retval = |%d|\n", LONG_MAX, retval);
	retval = ft_printf("LONG \'ld\'\n\t[%ld], retval = |%d|\n", LONG_MIN, retval);
	retval = ft_printf("LONG(OVERFLOW, retval) \'ld\'\n\t[%ld], retval = |%d|\n", LONG_MAX + 1, retval);
	retval = ft_printf("LONG(OVERFLOW, retval) \'ld\'\n\t[%ld], retval = |%d|\n", LONG_MIN - 1, retval);
	// %lld
	retval = ft_printf("\nLONG LONG DECIMALS, retval = |%d|\n", retval);
	retval = ft_printf("LONG LONG \'lld\'\n\t[%lld], retval = |%d|\n", 0, retval);
	retval = ft_printf("LONG LONG \'lld\'\n\t[%lld], retval = |%d|\n", LLONG_MAX, retval);
	retval = ft_printf("LONG LONG \'lld\'\n\t[%lld], retval = |%d|\n", LLONG_MIN, retval);
	retval = ft_printf("LONG LONG(OVERFLOW, retval) \'lld\'\n\t[%lld], retval = |%d|\n", LLONG_MAX + 1, retval);
	retval = ft_printf("LONG LONG(OVERFLOW, retval) \'lld\'\n\t[%lld], retval = |%d|\n", LLONG_MIN - 1, retval);
	// %u and variations
	retval = ft_printf("\nUNSIGNED DECIMALS, retval = |%d|\n", retval);
	retval = ft_printf("UINT \'u\'\n\t[%u], retval = |%d|\n", 0, retval);
	retval = ft_printf("UINT \'u\'\n\t[%u], retval = |%d|\n", UINT_MAX, retval);
	retval = ft_printf("UINT(-1, retval) \'u\'\n\t[%u], retval = |%d|\n", -1, retval);
	retval = ft_printf("SHORT UINT \'hu\'\n\t[%hu], retval = |%d|\n", 0, retval);
	retval = ft_printf("SHORT UINT \'hu\'\n\t[%hu], retval = |%d|\n", USHRT_MAX, retval);
	retval = ft_printf("SHORT UINT(-1, retval) \'hu\'\n\t[%hu], retval = |%d|\n", -1, retval);
	retval = ft_printf("UNSIGNED CHAR \'hhu\'\n\t[%hhu], retval = |%d|\n", 0, retval);
	retval = ft_printf("UNSIGNED CHAR \'hhu\'\n\t[%hhu], retval = |%d|\n", UCHAR_MAX, retval);
	retval = ft_printf("UNSIGNED CHAR(-1, retval) \'hhu\'\n\t[%hhu], retval = |%d|\n", -1, retval);
	retval = ft_printf("ULONG \'lu\'\n\t[%lu], retval = |%d|\n", 0, retval);
	retval = ft_printf("ULONG \'lu\'\n\t[%lu], retval = |%d|\n", ULONG_MAX, retval);
	retval = ft_printf("ULONG(-1, retval) \'lu\'\n\t[%lu], retval = |%d|\n", -1, retval);
	retval = ft_printf("ULONGLONG \'llu\'\n\t[%llu], retval = |%d|\n", 0, retval);
	retval = ft_printf("ULONGLONG \'llu\'\n\t[%llu], retval = |%d|\n", ULLONG_MAX, retval);
	retval = ft_printf("ULONGLONG(-1, retval) \'llu\'\n\t[%llu], retval = |%d|\n", -1, retval);
	// %hx
	retval = ft_printf("\nSHORT HEX LC, retval = |%d|\n", retval);
	retval = ft_printf("SHORT \'hx\'\n\t[%hx], retval = |%d|\n", 0, retval);
	retval = ft_printf("SHORT \'hx\'\n\t[%hx], retval = |%d|\n", SHRT_MAX, retval);
	retval = ft_printf("SHORT \'hx\'\n\t[%hx], retval = |%d|\n", SHRT_MIN, retval);
	retval = ft_printf("SHORT(OVERFLOW, retval) \'hx\'\n\t[%hx], retval = |%d|\n", SHRT_MAX + 1, retval);
	retval = ft_printf("SHORT(OVERFLOW, retval) \'hx\'\n\t[%hx], retval = |%d|\n", SHRT_MIN - 1, retval);
	// %hX
	retval = ft_printf("\nSHORT HEX UC, retval = |%d|\n", retval);
	retval = ft_printf("SHORT \'hX\'\n\t[%hX], retval = |%d|\n", 0, retval);
	retval = ft_printf("SHORT \'hX\'\n\t[%hX], retval = |%d|\n", SHRT_MAX, retval);
	retval = ft_printf("SHORT \'hX\'\n\t[%hX], retval = |%d|\n", SHRT_MIN, retval);
	retval = ft_printf("SHORT(OVERFLOW, retval) \'hx\'\n\t[%hX], retval = |%d|\n", SHRT_MAX + 1, retval);
	retval = ft_printf("SHORT(OVERFLOW, retval) \'hx\'\n\t[%hX], retval = |%d|\n", SHRT_MIN - 1, retval);
	// %hhx
	retval = ft_printf("\nSHORTCHAR HEX LC, retval = |%d|\n", retval);
	retval = ft_printf("SHORTCHAR \'hhx\'\n\t[%hhx], retval = |%d|\n", 0, retval);
	retval = ft_printf("SHORTCHAR \'hhx\'\n\t[%hhx], retval = |%d|\n", SCHAR_MAX, retval);
	retval = ft_printf("SHORTCHAR \'hhx\'\n\t[%hhx], retval = |%d|\n", SCHAR_MIN, retval);
	retval = ft_printf("SHORTCHAR(OVERFLOW, retval) \'hhx\'\n\t[%hhx], retval = |%d|\n", SCHAR_MAX + 1, retval);
	retval = ft_printf("SHORTCHAR(OVERFLOW, retval) \'hhx\'\n\t[%hhx], retval = |%d|\n", SCHAR_MIN - 1, retval);
	// %hhX
	retval = ft_printf("\nSHORTCHAR HEX UC, retval = |%d|\n", retval);
	retval = ft_printf("SHORTCHAR \'hhX\'\n\t[%hhX], retval = |%d|\n", 0, retval);
	retval = ft_printf("SHORTCHAR \'hhX\'\n\t[%hhX], retval = |%d|\n", SCHAR_MAX, retval);
	retval = ft_printf("SHORTCHAR \'hhX\'\n\t[%hhX], retval = |%d|\n", SCHAR_MIN, retval);
	retval = ft_printf("SHORTCHAR(OVERFLOW, retval) \'hhX\'\n\t[%hhX], retval = |%d|\n", SCHAR_MAX + 1, retval);
	retval = ft_printf("SHORTCHAR(OVERFLOW, retval) \'hhX\'\n\t[%hhX], retval = |%d|\n", SCHAR_MIN - 1, retval);
	// %lx
	retval = ft_printf("\nLONG HEX LC, retval = |%d|\n", retval);
	retval = ft_printf("LONG \'lx\'\n\t[%lx], retval = |%d|\n", 0, retval);
	retval = ft_printf("LONG \'lx\'\n\t[%lx], retval = |%d|\n", LONG_MAX, retval);
	retval = ft_printf("LONG \'lx\'\n\t[%lx], retval = |%d|\n", LONG_MIN, retval);
	retval = ft_printf("LONG(OVERFLOW, retval) \'lx\'\n\t[%lx], retval = |%d|\n", LONG_MAX + 1, retval);
	retval = ft_printf("LONG(OVERFLOW, retval) \'lx\'\n\t[%lx], retval = |%d|\n", LONG_MIN - 1, retval);
	// %lX
	retval = ft_printf("\nLONG HEX UC, retval = |%d|\n", retval);
	retval = ft_printf("LONG \'lX\'\n\t[%lX], retval = |%d|\n", 0, retval);
	retval = ft_printf("LONG \'lX\'\n\t[%lX], retval = |%d|\n", LONG_MAX, retval);
	retval = ft_printf("LONG \'lX\'\n\t[%lX], retval = |%d|\n", LONG_MIN, retval);
	retval = ft_printf("LONG(OVERFLOW, retval) \'lX\'\n\t[%lX], retval = |%d|\n", LONG_MAX + 1, retval);
	retval = ft_printf("LONG(OVERFLOW, retval) \'lX\'\n\t[%lX], retval = |%d|\n", LONG_MIN - 1, retval);
	// %llx
	retval = ft_printf("\nLONG LONG HEX LC, retval = |%d|\n", retval);
	retval = ft_printf("LONG LONG \'llx\'\n\t[%llx], retval = |%d|\n", 0, retval);
	retval = ft_printf("LONG LONG \'llx\'\n\t[%llx], retval = |%d|\n", LLONG_MAX, retval);
	retval = ft_printf("LONG LONG \'llx\'\n\t[%llx], retval = |%d|\n", LLONG_MIN, retval);
	retval = ft_printf("LONG LONG(OVERFLOW, retval) \'llx\'\n\t[%llx], retval = |%d|\n", LLONG_MAX + 1, retval);
	retval = ft_printf("LONG LONG(OVERFLOW, retval) \'llx\'\n\t[%llx], retval = |%d|\n", LLONG_MIN - 1, retval);
	// %llX
	retval = ft_printf("\nLONG LONG HEX UC, retval = |%d|\n", retval);
	retval = ft_printf("LONG LONG \'llX\'\n\t[%llX], retval = |%d|\n", 0, retval);
	retval = ft_printf("LONG LONG \'llX\'\n\t[%llX], retval = |%d|\n", LLONG_MAX, retval);
	retval = ft_printf("LONG LONG \'llX\'\n\t[%llX], retval = |%d|\n", LLONG_MIN, retval);
	retval = ft_printf("LONG LONG(OVERFLOW, retval) \'llX\'\n\t[%llX], retval = |%d|\n", LLONG_MAX + 1, retval);
	retval = ft_printf("LONG LONG(OVERFLOW, retval) \'llX\'\n\t[%llX], retval = |%d|\n", LLONG_MIN - 1, retval);

	retval = ft_printf("\nFLAG TESTS, retval = |%d|\n", retval);
	//FLAG COMBOS
	retval = ft_printf("**SINGLE FLAGS**, retval = |%d|\n", retval);
	retval = ft_printf("WIDTH(5, retval): ZERO FLAG\n\t[%0*i], retval = |%d|\n", 5, 1, retval);
	retval = ft_printf("WIDTH(5, retval): MIN FLAG\n\t[%-*i], retval = |%d|\n", 5, 1, retval);
	retval = ft_printf("WIDTH(5, retval): SPACE FLAG\n\t[% *i], retval = |%d|\n", 5, 1, retval);
	retval = ft_printf("WIDTH(5, retval): PLUS FLAG\n\t[%+*i], retval = |%d|\n", 5, 1, retval);
	retval = ft_printf("WIDTH(5, retval): CARDINAL FLAG (LC HEX, retval)\n\t[%#*x], retval = |%d|\n", 5, 1, retval);
	retval = ft_printf("WIDTH(5, retval): CARDINAL FLAG (UC HEX, retval)\n\t[%#*X], retval = |%d|\n", 5, 1, retval);

	//	ZERO COMBOS
	retval = ft_printf("\n**COMBOS WITH ZERO FLAG**, retval = |%d|\n", retval);
	retval = ft_printf("WIDTH(5, retval): && MIN FLAG\t== ZERO FLAG IGNORED!\n\t[%0-*i], retval = |%d|\n", 5, 1, retval);
	retval = ft_printf("WIDTH(5, retval): && SPACE FLAG\t== PREFIX THEN ADD ZEROS\n\t[%0 *i], retval = |%d|\n", 5, 1, retval);
	retval = ft_printf("WIDTH(5, retval): && PLUS FLAG\t== PREFIX THEN ADD ZEROS\n\t[%0+*i], retval = |%d|\n", 5, 1, retval);
	retval = ft_printf("WIDTH(5, retval): && CARDINAL FLAG (LC HEX, retval)\t== PREFIX THEN ADD ZEROS\n\t[%0#*x], retval = |%d|\n", 5, 1, retval);
	retval = ft_printf("WIDTH(5, retval): && CARDINAL FLAG (UC HEX, retval)\t== PREFIX THEN ADD ZEROS\n\t[%0#*X], retval = |%d|\n", 5, 1, retval);

	//	MIN COMBOS
	retval = ft_printf("\n**COMBOS WITH MIN FLAG**, retval = |%d|\n", retval);
	retval = ft_printf("WIDTH(5, retval): && ZERO FLAG\t== ZERO FLAG IGNORED!\n\t[%0-*i], retval = |%d|\n", 5, 1, retval);
	retval = ft_printf("WIDTH(5, retval): && SPACE FLAG\t== PREFIX THEN LEFT ALLIGN\n\t[%- *i], retval = |%d|\n", 5, 1, retval);
	retval = ft_printf("WIDTH(5, retval): && PLUS FLAG\t== PREFIX THEN LEFT ALLIGN\n\t[%-+*i], retval = |%d|\n", 5, 1, retval);
	retval = ft_printf("WIDTH(5, retval): && CARDINAL FLAG (LC HEX, retval)\t== PREFIX THEN LEFT ALLIGN\n\t[%-#*x], retval = |%d|\n", 5, 1, retval);
	retval = ft_printf("WIDTH(5, retval): && CARDINAL FLAG (UC HEX, retval)\t== PREFIX THEN LEFT ALLIGN\n\t[%-#*X], retval = |%d|\n", 5, 1, retval);

	//	SPACE COMBOS
	retval = ft_printf("\n**COMBOS WITH SPACE FLAG**, retval = |%d|\n", retval);
	retval = ft_printf("WIDTH(5, retval): && ZERO FLAG\t== PREFIX THEN ADD ZEROS\n\t[%0 *i], retval = |%d|\n", 5, 1, retval);
	retval = ft_printf("WIDTH(5, retval): && MIN FLAG\t== PREFIX THEN LEFT ALLIGN\n\t[%- *i], retval = |%d|\n", 5, 1, retval);
	retval = ft_printf("WIDTH(5, retval): && PLUS FLAG\t== SPACE FLAG IGNORED!\n\t[% +*i], retval = |%d|\n", 5, 1, retval);
	retval = ft_printf("WIDTH(5, retval): && CARDINAL FLAG (LC HEX, retval)\t== SPACE FLAG IGNORED!\n\t[% #*x], retval = |%d|\n", 5, 1, retval);
	retval = ft_printf("WIDTH(5, retval): && CARDINAL FLAG (UC HEX, retval)\t== SPACE FLAG IGNORED!\n\t[% #*X], retval = |%d|\n", 5, 1, retval);

	//	PLUS COMBOS
	retval = ft_printf("\n**COMBOS WITH PLUS FLAG**, retval = |%d|\n", retval);
	retval = ft_printf("WIDTH(5, retval): && MIN FLAG\t== PREFIX THEN LEFT ALLIGN\n\t[%+-*i], retval = |%d|\n", 5, 1, retval);
	retval = ft_printf("WIDTH(5, retval): && SPACE FLAG\t== SPACE FLAG IGNORED!\n\t[%+ *i], retval = |%d|\n", 5, 1, retval);
	retval = ft_printf("WIDTH(5, retval): && ZERO FLAG\t== PREFIX THEN ADD ZEROS\n\t[%0+*i], retval = |%d|\n", 5, 1, retval);
	retval = ft_printf("WIDTH(5, retval): && CARDINAL FLAG (LC HEX, retval)\t== SPACE FLAG IGNORED!\n\t[%+#*x], retval = |%d|\n", 5, 1, retval);
	retval = ft_printf("WIDTH(5, retval): && CARDINAL FLAG (UC HEX, retval)\t== SPACE FLAG IGNORED!\n\t[%+#*X], retval = |%d|\n", 5, 1, retval);

	//	CARDINAL COMBOS
	retval = ft_printf("\n**COMBOS WITH CARDINAL FLAG**, retval = |%d|\n", retval);
	retval = ft_printf("WIDTH(5, retval): (LC HEX, retval) && ZERO FLAG\t== PREFIX THEN ADD ZEROS\n\t[%0#*x], retval = |%d|\n", 5, 1, retval);
	retval = ft_printf("WIDTH(5, retval): (UC HEX, retval) && ZERO FLAG\t== PREFIX THEN ADD ZEROS\n\t[%0#*X], retval = |%d|\n", 5, 1, retval);
	retval = ft_printf("WIDTH(5, retval): (LC HEX, retval) && MIN FLAG\t== PREFIX THEN LEFT ALLIGN\n\t[%-#*x], retval = |%d|\n", 5, 1, retval);
	retval = ft_printf("WIDTH(5, retval): (UC HEX, retval) && MIN FLAG\t== PREFIX THEN LEFT ALLIGN\n\t[%-#*X], retval = |%d|\n", 5, 1, retval);
	retval = ft_printf("WIDTH(5, retval): (LC HEX, retval) && SPACE FLAG\t== SPACE FLAG IGNORED!\n\t[% #*x], retval = |%d|\n", 5, 1, retval);
	retval = ft_printf("WIDTH(5, retval): (UC HEX, retval) && SPACE FLAG\t== SPACE FLAG IGNORED!\n\t[% #*X], retval = |%d|\n", 5, 1, retval);
	retval = ft_printf("WIDTH(5, retval): (LC HEX, retval) && PLUS FLAG\t== PLUS FLAG IGNORED!\n\t[%+#*x], retval = |%d|\n", 5, 1, retval);
	retval = ft_printf("WIDTH(5, retval): (UC HEX, retval) && PLUS FLAG\t== PLUS FLAG IGNORED!\n\t[%+#*X], retval = |%d|\n", 5, 1, retval);
	retval = ft_printf("WIDTH(5, retval): (LC HEX, retval) && ZERO FLAG && MIN FLAG\t== PREFIX THEN LEFT ALLIGN\n\t[%0-#*x], retval = |%d|\n", 5, 1, retval);
	retval = ft_printf("WIDTH(5, retval): (UC HEX, retval) && ZERO FLAG && MIN FLAG\t== PREFIX THEN LEFT ALLIGN\n\t[%0-#*X], retval = |%d|\n", 5, 1, retval);
	retval = ft_printf("WIDTH(5, retval): (LC HEX, retval) && ZERO FLAG && SPACE FLAG\t== PREFIX THEN ADD ZEROS && SPACE IGNORED!\n\t[%0 #*x], retval = |%d|\n", 5, 1, retval);
	retval = ft_printf("WIDTH(5, retval): (UC HEX, retval) && ZERO FLAG && SPACE FLAG\t== PREFIX THEN ADD ZEROS && SPACE IGNORED!\n\t[%0 #*X], retval = |%d|\n", 5, 1, retval);
	retval = ft_printf("WIDTH(5, retval): (LC HEX, retval) && ZERO FLAG && PLUS FLAG\t== PREFIX THEN ADD ZEROS && PLUS IGNORED!\n\t[%0+#*x], retval = |%d|\n", 5, 1, retval);
	retval = ft_printf("WIDTH(5, retval): (UC HEX, retval) && ZERO FLAG && PLUS FLAG\t== PREFIX THEN ADD ZEROS && PLUS IGNORED!\n\t[%0+#*X], retval = |%d|\n", 5, 1, retval);
	//	WOMBO COMBOS
	retval = ft_printf("\n**ALL FLAG**, retval = |%d|\n", retval);
	retval = ft_printf("WIDTH(5, retval): (LC HEX, retval) && ALL FLAGS\t== ALL FLAGS IGNORED EXCEPT MINUS\n\t[%0#+- *x], retval = |%d|\n", 5, 1, retval);
	//WIDTH + FLAG COMBOS
	retval = ft_printf("\n**WIDTH + FLAG TESTS FOR NUMBERS**, retval = |%d|\n", retval);
	retval = ft_printf("WIDTH(5, retval):\n\t[%*i], retval = |%d|\n", 5, 1, retval);
	retval = ft_printf("WIDTH(05, retval) == WIDTH(5, retval)\n\t[%*i], retval = |%d|\n", 05, 1, retval);
	retval = ft_printf("WIDTH(5, retval) && ZERO FLAG\n\t[%0*i], retval = |%d|\n", 05, 1, retval);
	retval = ft_printf("WIDTH(5, retval) && SPACE FLAG\n\t[% *i], retval = |%d|\n", 05, 1, retval);
	retval = ft_printf("WIDTH(5, retval) && PLUS FLAG\n\t[%+*i], retval = |%d|\n", 05, 1, retval);
	retval = ft_printf("WIDTH(-5, retval) => MIN FLAG\n\t[%*i], retval = |%d|\n", -5, 1, retval);
	retval = ft_printf("WIDTH(-5, retval) => MIN FLAG\n\t[%*i], retval = |%d|\n", -05, 1, retval);
	retval = ft_printf("WIDTH(-5, retval) && ZERO FLAG => MIN FLAG && ZERO FLAG IGNORED\n\t[%0*i], retval = |%d|\n", -05, 1, retval);
	retval = ft_printf("WIDTH(-5, retval) && MIN FLAG => MIN FLAG\n\t[%-*i], retval = |%d|\n", -5, 1, retval);
	retval = ft_printf("WIDTH(-5, retval) && SPACE FLAG => MIN FLAG && SPACE FLAG\n\t[% *i], retval = |%d|\n", -5, 1, retval);
	retval = ft_printf("WIDTH(-5, retval) && PLUS FLAG => MIN FLAG && PLUS FLAG\n\t[%+*i], retval = |%d|\n", -5, 1, retval);

	retval = ft_printf("\n**WIDTH + FLAG TESTS FOR STRINGS**, retval = |%d|\n", retval);
	retval = ft_printf("WIDTH(5, retval):\n\t[%*s], retval = |%d|\n", 5, "LOL", retval);
	retval = ft_printf("WIDTH(05, retval) == WIDTH(5, retval)\n\t[%*s], retval = |%d|\n", 05, "LOL", retval);
	retval = ft_printf("WIDTH(5, retval) && ZERO FLAG\n\t[%0*s], retval = |%d|\n", 05, "LOL", retval);
	retval = ft_printf("WIDTH(5, retval) && SPACE FLAG\n\t[% *s], retval = |%d|\n", 05, "LOL", retval);
	retval = ft_printf("WIDTH(5, retval) && PLUS FLAG\n\t[%+*s], retval = |%d|\n", 05, "LOL", retval);
	retval = ft_printf("WIDTH(-5, retval) => MIN FLAG\n\t[%*s], retval = |%d|\n", -5, "LOL", retval);
	retval = ft_printf("WIDTH(-5, retval) => MIN FLAG\n\t[%*s], retval = |%d|\n", -05, "LOL", retval);
	retval = ft_printf("WIDTH(-5, retval) && ZERO FLAG => MIN FLAG && ZERO FLAG IGNORED\n\t[%0*s], retval = |%d|\n", -05, "LOL", retval);
	retval = ft_printf("WIDTH(-5, retval) && MIN FLAG => MIN FLAG\n\t[%-*s], retval = |%d|\n", -5, "LOL", retval);
	retval = ft_printf("WIDTH(-5, retval) && SPACE FLAG => MIN FLAG && SPACE FLAG IGNORED\n\t[% *s], retval = |%d|\n", -5, "LOL", retval);
	retval = ft_printf("WIDTH(-5, retval) && PLUS FLAG => MIN FLAG && PLUS FLAG IGNORED\n\t[%+*s], retval = |%d|\n", -5, "LOL", retval);

	//	WIDTH AND PRECISION TESTS
	retval = ft_printf("\n**WIDTH + PRECISION TESTS FOR NUMBERS**, retval = |%d|\n", retval);
	retval = ft_printf("PRECISION(5, retval) < AMOUNT OF DIGITS == NO PRECISION\n\t[%.*i], retval = |%d|\n", 5, 1000000, retval);
	retval = ft_printf("NEG PRECISION(-5, retval) == NO PRECISION\n\t[%.*i], retval = |%d|\n", -5, 1000000, retval);
	retval = ft_printf("NEG PRECISION(-20, retval) == NO PRECISION\n\t[%.*i], retval = |%d|\n", -20, 1000000, retval);
	retval = ft_printf("PRECISION(20, retval) > AMOUNT OF DIGITS == LEADING ZEROS ADDED\n\t[%.*i], retval = |%d|\n", 20, 1000000, retval);
	retval = ft_printf("PRECISION(20, retval) > AMOUNT OF DIGITS && MIN FLAG == LEADING ZEROS ADDED\n\t[%-.*i], retval = |%d|\n", 20, 1000000, retval);
	retval = ft_printf("WIDTH(20, retval) > PRECISION(5, retval) == NO PRECISION ONLY WIDTH HANDLED\n\t[%*.*i], retval = |%d|\n", 20, 5, 1000000, retval);
	retval = ft_printf("PRECISION(5, retval) < AMOUNT OF DIGITS == NO PRECISION\n\t[%.*i], retval = |%d|\n", 5, -1000000, retval);
	retval = ft_printf("NEG PRECISION(-5, retval) == NO PRECISION\n\t[%.*i], retval = |%d|\n", -5, -1000000, retval);
	retval = ft_printf("NEG PRECISION(-20, retval) == NO PRECISION\n\t[%.*i], retval = |%d|\n", -20, -1000000, retval);
	retval = ft_printf("PRECISION(20, retval) > AMOUNT OF DIGITS == LEADING ZEROS ADDED AFTER SIGN\n\t[%.*i], retval = |%d|\n", 20, -1000000, retval);
	retval = ft_printf("PRECISION(20, retval) > AMOUNT OF DIGITS && MIN FLAG == LEADING ZEROS ADDED AFTER SIGN\n\t[%-.*i], retval = |%d|\n", 20, -1000000, retval);
	retval = ft_printf("WIDTH(20, retval) > PRECISION(5, retval) == NO PRECISION ONLY WIDTH HANDLED\n\t[%*.*i], retval = |%d|\n", 20, 5, -1000000, retval);
	retval = ft_printf("[%-3.2d] [%10.42d], retval = |%d|\n", 0, 0, retval);
	retval = ft_printf("[%-3.2d] [%10.42d], retval = |%d|\n", 1, -1, retval);
	retval = ft_printf("[%.0d], retval = |%d|\n", 0, 0, retval);
	retval = ft_printf("[%.*d], retval = |%d|\n", -4, 0, retval);
	retval = ft_printf(" 0*[%-0*.10d]*0 0*[%-0*.0d]*0 |, retval = |%d|\n", 21, 1021, 21, -1011, retval);
	retval = ft_printf("0*[%0*.*d]*0 , retval = |%d|\n", 21, 10, -101, retval);
	retval = ft_printf("[%09.0d], retval = |%d|\n", UINT_MAX, retval);
	retval = ft_printf("[%011.1d], retval = |%d|\n", UINT_MAX, retval);
	retval = ft_printf("[%011.2d], retval = |%d|\n", UINT_MAX, retval);
	retval = ft_printf("[%7d], retval = |%d|\n", 42, retval);
	retval = ft_printf("[%-7d], retval = |%d|\n", 42, retval);
	retval = ft_printf("[%7d], retval = |%d|\n", -42, retval);
	retval = ft_printf("[%-7d], retval = |%d|\n", -42, retval);
	retval = ft_printf("[%09.1x], retval = |%d|\n", UINT_MAX, retval);
	retval = ft_printf("[%09.1X], retval = |%d|\n", UINT_MAX, retval);
	retval = ft_printf("[%09.2x], retval = |%d|\n", UINT_MAX, retval);
	retval = ft_printf("[%09.2X], retval = |%d|\n", UINT_MAX, retval);
	retval = ft_printf("%% *.5i 42 == [% *.5i], retval = |%d|\n", 4, 42, retval);
	retval = ft_printf("%% *.5i 42 == [% *.5i], retval = |%d|\n", 4, -42, retval);

	retval = ft_printf("\n**WIDTH + PRECISION TESTS FOR STRINGS**, retval = |%d|\n", retval);
	retval = ft_printf("PRECISION(5, retval) < STRLEN == PRECISION\n\t[%.*s], retval = |%d|\n", 5, "EEEEEEEEEEEEEEE", retval);
	retval = ft_printf("NEG PRECISION(-5, retval) == NO PRECISION\n\t[%.*s], retval = |%d|\n", -5, "EEEEEEEEEEEEEEE", retval);
	retval = ft_printf("NEG PRECISION(-20, retval) == NO PRECISION\n\t[%.*s], retval = |%d|\n", -20, "EEEEEEEEEEEEEEE", retval);
	retval = ft_printf("PRECISION(20, retval) > STRLEN == STRLEN IS MAX LIMIT\n\t[%.*s], retval = |%d|\n", 20, "EEEEEEEEEEEEEEE", retval);
	retval = ft_printf("WIDTH(20, retval) > PRECISION(5, retval) == BOTH PRECISION AND WIDTH HANDLED\n\t[%*.*s], retval = |%d|\n", 20, 5, "EEEEEEEEEEEEEEE", retval);
	retval = ft_printf("WIDTH(20, retval) > PRECISION(5, retval) == BOTH PRECISION AND WIDTH HANDLED && ZERO FLAG\n\t[%0*.*s], retval = |%d|\n", 20, 5, "EEEEEEEEEEEEEEE", retval);
	retval = ft_printf("PRECISION(5, retval) < STRLEN == PRECISION\n\t[%-.*s], retval = |%d|\n", 5, "EEEEEEEEEEEEEEE", retval);
	retval = ft_printf("NEG PRECISION(-5, retval) == NO PRECISION\n\t[%-.*s], retval = |%d|\n", -5, "EEEEEEEEEEEEEEE", retval);
	retval = ft_printf("NEG PRECISION(-20, retval) == NO PRECISION\n\t[%-.*s], retval = |%d|\n", -20, "EEEEEEEEEEEEEEE", retval);
	retval = ft_printf("PRECISION(20, retval) > STRLEN == STRLEN IS MAX LIMIT\n\t[%-.*s], retval = |%d|\n", 20, "EEEEEEEEEEEEEEE", retval);
	retval = ft_printf("WIDTH(20, retval) > PRECISION(5, retval) == BOTH PRECISION AND WIDTH HANDLED\n\t[%-*.*s], retval = |%d|\n", 20, 5, "EEEEEEEEEEEEEEE", retval);
	retval = ft_printf("[%3.3s%7.7s], retval = |%d|\n", "hello", "world", retval);
	retval = ft_printf("[%-*.*s], retval = |%d|\n", -10, -3, "Big oof", retval);
	retval = ft_printf("[%.s], retval = |%d|\n", "Big oof", retval);

	//	WIDTH AND PRECISION (IN PARSE) TESTS
	retval = ft_printf("\n**WIDTH + PRECISION TESTS FOR NUMBERS(IN PARSE)**, retval = |%d|\n", retval);
	retval = ft_printf("PRECISION(5, retval) < AMOUNT OF DIGITS == NO PRECISION\n\t[%.5i], retval = |%d|\n", 1000000, retval);
	retval = ft_printf("NEG PRECISION(-5, retval) == NO PRECISION\n\t[%.-5i], retval = |%d|\n", 1000000, retval);
	retval = ft_printf("NEG PRECISION(-20, retval) == NO PRECISION\n\t[%.-20i], retval = |%d|\n", 1000000, retval);
	retval = ft_printf("PRECISION(20, retval) > AMOUNT OF DIGITS == LEADING ZEROS ADDED\n\t[%.20i], retval = |%d|\n", 1000000, retval);
	retval = ft_printf("PRECISION(20, retval) > AMOUNT OF DIGITS && MIN FLAG == LEADING ZEROS ADDED\n\t[%-.20i], retval = |%d|\n", 1000000, retval);
	retval = ft_printf("WIDTH(20, retval) > PRECISION(5, retval) == NO PRECISION ONLY WIDTH HANDLED\n\t[%20.5i], retval = |%d|\n", 1000000, retval);
	retval = ft_printf("PRECISION(5, retval) < AMOUNT OF DIGITS == NO PRECISION\n\t[%.5i], retval = |%d|\n", -1000000, retval);
	retval = ft_printf("NEG PRECISION(-5, retval) == NO PRECISION\n\t[%.-5i], retval = |%d|\n", -1000000, retval);
	retval = ft_printf("NEG PRECISION(-20, retval) == NO PRECISION\n\t[%.-20i], retval = |%d|\n", -1000000, retval);
	retval = ft_printf("PRECISION(20, retval) > AMOUNT OF DIGITS == LEADING ZEROS ADDED AFTER SIGN\n\t[%.20i], retval = |%d|\n", -1000000, retval);
	retval = ft_printf("PRECISION(20, retval) > AMOUNT OF DIGITS && MIN FLAG == LEADING ZEROS ADDED AFTER SIGN\n\t[%-.20i], retval = |%d|\n", -1000000, retval);
	retval = ft_printf("WIDTH(20, retval) > PRECISION(5, retval) == NO PRECISION ONLY WIDTH HANDLED\n\t[%20.5i], retval = |%d|\n", -1000000, retval);
	retval = ft_printf("WIDTH(20, retval) == PRECISION(20, retval)\n\t[%20.20i], retval = |%d|\n", -1000000, retval);
	retval = ft_printf("WIDTH(5, retval) == PRECISION(5, retval)\n\t[%5.5i], retval = |%d|\n", -1000000, retval);

	retval = ft_printf("\n**WIDTH + PRECISION TESTS FOR STRINGS(IN PARSE)**, retval = |%d|\n", retval);
	retval = ft_printf("PRECISION(5, retval) < STRLEN == PRECISION\n\t[%.5s], retval = |%d|\n", "EEEEEEEEEEEEEEE", retval);
	retval = ft_printf("NEG PRECISION(-5, retval) == NO PRECISION\n\t[%.-5s], retval = |%d|\n", "EEEEEEEEEEEEEEE", retval);
	retval = ft_printf("NEG PRECISION(-20, retval) == NO PRECISION\n\t[%.-20s], retval = |%d|\n", "EEEEEEEEEEEEEEE", retval);
	retval = ft_printf("PRECISION(20, retval) > STRLEN == STRLEN IS MAX LIMIT\n\t[%.20s], retval = |%d|\n", "EEEEEEEEEEEEEEE", retval);
	retval = ft_printf("WIDTH(20, retval) > PRECISION(5, retval) == BOTH PRECISION AND WIDTH HANDLED\n\t[%20.5s], retval = |%d|\n", "EEEEEEEEEEEEEEE", retval);
	retval = ft_printf("WIDTH(20, retval) > PRECISION(5, retval) == BOTH PRECISION AND WIDTH HANDLED && ZERO FLAG\n\t[%020.5s], retval = |%d|\n", "EEEEEEEEEEEEEEE", retval);
	retval = ft_printf("PRECISION(5, retval) < STRLEN == PRECISION\n\t[%-.5s], retval = |%d|\n", "EEEEEEEEEEEEEEE", retval);
	retval = ft_printf("NEG PRECISION(-5, retval) == NO PRECISION\n\t[%-.-5s], retval = |%d|\n", "EEEEEEEEEEEEEEE", retval);
	retval = ft_printf("NEG PRECISION(-20, retval) == NO PRECISION\n\t[%-.-20s], retval = |%d|\n", "EEEEEEEEEEEEEEE", retval);
	retval = ft_printf("PRECISION(20, retval) > STRLEN == STRLEN IS MAX LIMIT\n\t[%-.20s], retval = |%d|\n", "EEEEEEEEEEEEEEE", retval);
	retval = ft_printf("WIDTH(20, retval) > PRECISION(5, retval) == BOTH PRECISION AND WIDTH HANDLED\n\t[%-20.5s], retval = |%d|\n", "EEEEEEEEEEEEEEE", retval);
	retval = ft_printf("WIDTH(20, retval) == PRECISION(20, retval)\n\t[%-20.20s], retval = |%d|\n", "EEEEEEEEEEEEEEE", retval);
	retval = ft_printf("WIDTH(5, retval) == PRECISION(5, retval)\n\t[%-5.5s], retval = |%d|\n", "EEEEEEEEEEEEEEE", retval);

	retval = ft_printf("\nEXTRA TESTS FOR CHARS, retval = |%d|\n", retval);
	retval = ft_printf("Percent Test = [%%], retval = |%d|\n", retval);
	retval = ft_printf("Percent Test = [%20%], retval = |%d|\n", retval);
	retval = ft_printf("Percent Test = [%20.5%], retval = |%d|\n", retval);
	retval = ft_printf("Edge case for char = [%-c%-c%c*], retval = |%d|\n", 1, '0', 0, retval);
	retval = ft_printf("Edge case for char = [ -%*c* -%-*c*], retval = |%d|\n", -2, 0, 2, 0, retval);

	retval = ft_printf("\nFLAG TESTS, retval = |%d|\n", retval);
	//FLAG COMBOS
	retval = ft_printf("**SINGLE FLAGS, retval = |%d|**\n", retval);
	retval = ft_printf("WIDTH(5, retval): ZERO FLAG\n\t[%0*c], retval = |%d|\n", 5, 48, retval);
	retval = ft_printf("WIDTH(5, retval): MIN FLAG\n\t[%-*c], retval = |%d|\n", 5, 48, retval);
	retval = ft_printf("WIDTH(5, retval): SPACE FLAG\n\t[% *c], retval = |%d|\n", 5, 48, retval);
	retval = ft_printf("WIDTH(5, retval): PLUS FLAG\n\t[%+*c], retval = |%d|\n", 5, 48, retval);
	retval = ft_printf("WIDTH(5, retval): CARDINAL FLAG (LC HEX, retval)\n\t[%#*x], retval = |%d|\n", 5, 48, retval);
	retval = ft_printf("WIDTH(5, retval): CARDINAL FLAG (UC HEX, retval)\n\t[%#*X], retval = |%d|\n", 5, 48, retval);

	//	ZERO COMBOS
	retval = ft_printf("\n**COMBOS WITH ZERO FLAG**, retval = |%d|\n", retval);
	retval = ft_printf("WIDTH(5, retval): && MIN FLAG\t== ZERO FLAG IGNORED!\n\t[%0-*c], retval = |%d|\n", 5, 48, retval);
	retval = ft_printf("WIDTH(5, retval): && SPACE FLAG\t== PREFIX THEN ADD ZEROS\n\t[%0 *c], retval = |%d|\n", 5, 48, retval);
	retval = ft_printf("WIDTH(5, retval): && PLUS FLAG\t== PREFIX THEN ADD ZEROS\n\t[%0+*c], retval = |%d|\n", 5, 48, retval);
	retval = ft_printf("WIDTH(5, retval): && CARDINAL FLAG (LC HEX, retval)\t== PREFIX THEN ADD ZEROS\n\t[%0#*c], retval = |%d|\n", 5, 48, retval);

	//	MIN COMBOS
	retval = ft_printf("\n**COMBOS WITH MIN FLAG**, retval = |%d|\n", retval);
	retval = ft_printf("WIDTH(5, retval): && ZERO FLAG\t== ZERO FLAG IGNORED!\n\t[%0-*c], retval = |%d|\n", 5, 48, retval);
	retval = ft_printf("WIDTH(5, retval): && SPACE FLAG\t== PREFIX THEN LEFT ALLIGN\n\t[%- *c], retval = |%d|\n", 5, 48, retval);
	retval = ft_printf("WIDTH(5, retval): && PLUS FLAG\t== PREFIX THEN LEFT ALLIGN\n\t[%-+*c], retval = |%d|\n", 5, 48, retval);
	retval = ft_printf("WIDTH(5, retval): && CARDINAL FLAG (LC HEX, retval)\t== PREFIX THEN LEFT ALLIGN\n\t[%-#*c], retval = |%d|\n", 5, 48, retval);

	//	SPACE COMBOS
	retval = ft_printf("\n**COMBOS WITH SPACE FLAG**, retval = |%d|\n", retval);
	retval = ft_printf("WIDTH(5, retval): && ZERO FLAG\t== PREFIX THEN ADD ZEROS\n\t[%0 *c], retval = |%d|\n", 5, 48, retval);
	retval = ft_printf("WIDTH(5, retval): && MIN FLAG\t== PREFIX THEN LEFT ALLIGN\n\t[%- *c], retval = |%d|\n", 5, 48, retval);
	retval = ft_printf("WIDTH(5, retval): && PLUS FLAG\t== SPACE FLAG IGNORED!\n\t[% +*c], retval = |%d|\n", 5, 48, retval);
	retval = ft_printf("WIDTH(5, retval): && CARDINAL FLAG (LC HEX, retval)\t== SPACE FLAG IGNORED!\n\t[% #*c], retval = |%d|\n", 5, 48, retval);

	//	PLUS COMBOS
	retval = ft_printf("\n**COMBOS WITH PLUS FLAG, retval = |%d|**\n", retval);
	retval = ft_printf("WIDTH(5, retval): && MIN FLAG\t== PREFIX THEN LEFT ALLIGN\n\t[%+-*c], retval = |%d|\n", 5, 48, retval);
	retval = ft_printf("WIDTH(5, retval): && SPACE FLAG\t== SPACE FLAG IGNORED!\n\t[%+ *c], retval = |%d|\n", 5, 48, retval);
	retval = ft_printf("WIDTH(5, retval): && ZERO FLAG\t== PREFIX THEN ADD ZEROS\n\t[%0+*c], retval = |%d|\n", 5, 48, retval);
	retval = ft_printf("WIDTH(5, retval): && CARDINAL FLAG (LC HEX, retval)\t== SPACE FLAG IGNORED!\n\t[%+#*c], retval = |%d|\n", 5, 48, retval);

	retval = ft_printf("\nFLAG TESTS, WIDTH IN PARSE, retval = |%d|\n", retval);
	//FLAG COMBOS
	retval = ft_printf("**SINGLE FLAGS, retval = |%d|**\n", retval);
	retval = ft_printf("WIDTH(5, retval): ZERO FLAG\n\t[%05c], retval = |%d|\n", 48, retval);
	retval = ft_printf("WIDTH(5, retval): MIN FLAG\n\t[%-5c], retval = |%d|\n", 48, retval);
	retval = ft_printf("WIDTH(5, retval): SPACE FLAG\n\t[% 5c], retval = |%d|\n", 48, retval);
	retval = ft_printf("WIDTH(5, retval): PLUS FLAG\n\t[%+5c], retval = |%d|\n", 48, retval);
	retval = ft_printf("WIDTH(5, retval): CARDINAL FLAG (LC HEX, retval)\n\t[%#5x], retval = |%d|\n", 48, retval);
	retval = ft_printf("WIDTH(5, retval): CARDINAL FLAG (UC HEX, retval)\n\t[%#5X], retval = |%d|\n", 48, retval);

	//	ZERO COMBOS
	retval = ft_printf("\n**COMBOS WITH ZERO FLAG**, retval = |%d|\n", retval);
	retval = ft_printf("WIDTH(5, retval): && MIN FLAG\t== ZERO FLAG IGNORED!\n\t[%0-5c], retval = |%d|\n", 48, retval);
	retval = ft_printf("WIDTH(5, retval): && SPACE FLAG\t== PREFIX THEN ADD ZEROS\n\t[%0 5c], retval = |%d|\n", 48, retval);
	retval = ft_printf("WIDTH(5, retval): && PLUS FLAG\t== PREFIX THEN ADD ZEROS\n\t[%0+5c], retval = |%d|\n", 48, retval);
	retval = ft_printf("WIDTH(5, retval): && CARDINAL FLAG (LC HEX, retval)\t== PREFIX THEN ADD ZEROS\n\t[%0#5c], retval = |%d|\n", 48, retval);

	//	MIN COMBOS
	retval = ft_printf("\n**COMBOS WITH MIN FLAG**, retval = |%d|\n", retval);
	retval = ft_printf("WIDTH(5, retval): && ZERO FLAG\t== ZERO FLAG IGNORED!\n\t[%0-5c], retval = |%d|\n", 48, retval);
	retval = ft_printf("WIDTH(5, retval): && SPACE FLAG\t== PREFIX THEN LEFT ALLIGN\n\t[%- 5c], retval = |%d|\n", 48, retval);
	retval = ft_printf("WIDTH(5, retval): && PLUS FLAG\t== PREFIX THEN LEFT ALLIGN\n\t[%-+5c], retval = |%d|\n", 48, retval);
	retval = ft_printf("WIDTH(5, retval): && CARDINAL FLAG (LC HEX, retval)\t== PREFIX THEN LEFT ALLIGN\n\t[%-#5c], retval = |%d|\n", 48, retval);

	//	SPACE COMBOS
	retval = ft_printf("\n**COMBOS WITH SPACE FLAG**, retval = |%d|\n", retval);
	retval = ft_printf("WIDTH(5, retval): && ZERO FLAG\t== PREFIX THEN ADD ZEROS\n\t[%0 5c], retval = |%d|\n", 48, retval);
	retval = ft_printf("WIDTH(5, retval): && MIN FLAG\t== PREFIX THEN LEFT ALLIGN\n\t[%- 5c], retval = |%d|\n", 48, retval);
	retval = ft_printf("WIDTH(5, retval): && PLUS FLAG\t== SPACE FLAG IGNORED!\n\t[% +5c], retval = |%d|\n", 48, retval);
	retval = ft_printf("WIDTH(5, retval): && CARDINAL FLAG (LC HEX, retval)\t== SPACE FLAG IGNORED!\n\t[% #5c], retval = |%d|\n", 48, retval);

	//	PLUS COMBOS
	retval = ft_printf("\n**COMBOS WITH PLUS FLAG, retval = |%d|**\n", retval);
	retval = ft_printf("WIDTH(5, retval): && MIN FLAG\t== PREFIX THEN LEFT ALLIGN\n\t[%+-5c], retval = |%d|\n", 48, retval);
	retval = ft_printf("WIDTH(5, retval): && SPACE FLAG\t== SPACE FLAG IGNORED!\n\t[%+ 5c], retval = |%d|\n", 48, retval);
	retval = ft_printf("WIDTH(5, retval): && ZERO FLAG\t== PREFIX THEN ADD ZEROS\n\t[%0+5c], retval = |%d|\n", 48, retval);
	retval = ft_printf("WIDTH(5, retval): && CARDINAL FLAG (LC HEX, retval)\t== SPACE FLAG IGNORED!\n\t[%+#5c], retval = |%d|\n", 48, retval);

	// POINTERS
	char	*string = "This is a nice string and a pointer to boot!";
	void	*ptrnull = NULL;
	retval = ft_printf("POINTERS: STRING\t\"%s\"\nADDRESS:\t[%p], retval = |%d|\n", string, string, retval);
	retval = ft_printf("POINTERS: STRING\t\"%s\"\nADDRESS:\t[%p], retval = |%d|\n", ptrnull, ptrnull, retval);

	// BONUS TESTS
	retval = ft_printf("[% -03.d], retval = |%d|\n", 0, retval);
	retval = ft_printf("[%+-03.d], retval = |%d|\n", 0, retval);
	retval = ft_printf("[%+5.0d], retval = |%d|\n", 0, retval);
	retval = ft_printf("[%#-03.x], retval = |%d|\n", 0, retval);
	retval = ft_printf("[%#-03x], retval = |%d|\n", 0, retval);
	retval = ft_printf("[%#-03.2x], retval = |%d|\n", 0, retval);
	retval = ft_printf("[%#x], retval = |%d|\n", 0, retval);
	retval = ft_printf("[%#X], retval = |%d|\n", 0, retval);
	retval = ft_printf("[%#2X], retval = |%d|\n", 0, retval);

	// n conversion
	int	n;
	retval = ft_printf("I have printed %n[%d] chars so far... oh wait it's actually %n[%d] but my retval = [%d]\n", &n, n, &n, n, retval);
	retval = ft_printf("n is [%d], retval = |%d|\n", n, retval);
	short	nsh;
	retval = ft_printf("I have printed %hn[%d] chars so far... oh wait it's actually %hn[%d] but my retval = [%d]\n", &nsh, nsh, &nsh, nsh, retval);
	retval = ft_printf("n is [%hd], retval = |%d|\n", nsh, retval);
	char	nch;
	retval = ft_printf("I have printed %hhn[%d] chars so far... oh wait it's actually %hhn[%d] but my retval = [%d]\n", &nch, nch, &nch, nch, retval);
	retval = ft_printf("n is [%hhd], retval = |%d|\n", nch, retval);
	long	nl;
	retval = ft_printf("I have printed %ln[%d] chars so far... oh wait it's actually %ln[%d] but my retval = [%d]\n", &nl, nl, &nl, nl, retval);
	retval = ft_printf("n is [%ld], retval = |%d|\n", nl, retval);
	t_ll	nll;
	retval = ft_printf("I have printed %lln[%d] chars so far... oh wait it's actually %lln[%d] but my retval = [%d]\n", &nll, nll, &nll, nll, retval);
	retval = ft_printf("n is [%lld], retval = |%d|\n", nll, retval);
	//EDGE
	retval = ft_printf("I have printed %n[%d] chars so far... oh wait it's actually %n[%d] but my retval = [%d]\n", (void *)0, 0, (void *)0, 0, retval);
	retval = ft_printf("n is [%d], retval = |%d|\n", 0, retval);

	// WIDE BOIS
	retval = ft_printf("WIDE CHAR = [%lc], retval = [%d]\n", L'E', retval);
	retval = ft_printf("WIDE CHAR = [%5lc], retval = [%d]\n", L'E', retval);
	retval = ft_printf("WIDE CHAR = [%-5lc], retval = [%d]\n", L'E', retval);
	retval = ft_printf("WIDE STRING = [%ls], retval = [%d]\n", L"A very wide boi", retval);
	retval = ft_printf("WIDE STRING = [%ls], retval = [%d]\n", NULL, retval);
	retval = ft_printf("WIDE STRING = [%20ls], retval = [%d]\n", L"A very wide boi", retval);
	retval = ft_printf("WIDE STRING = [%-20ls], retval = [%d]\n", L"A very wide boi", retval);
	retval = ft_printf("WIDE STRING = [%20.6ls], retval = [%d]\n", L"A very wide boi", retval);
	retval = ft_printf("WIDE STRING = [%-20.6ls], retval = [%d]\n", L"A very wide boi", retval);

	// f conversion
	retval = ft_printf("NORMAL \'f\'\n\t[%f], retval = |%d|\n", 0.0, retval);
	retval = ft_printf("NORMAL \'f\'\n\t[%f], retval = |%d|\n", -0, retval);
	retval = ft_printf("NORMAL \'f\'\n\t[%f], retval = |%d|\n", 1.0/0.0, retval);
	retval = ft_printf("NORMAL \'f\'\n\t[%f], retval = |%d|\n", 42.42, retval);
	retval = ft_printf("NORMAL \'f\'\n\t[%f], retval = |%d|\n", 1.5, retval);
	retval = ft_printf("NORMAL \'f\'\n\t[%f], retval = |%d|\n", 23.375094499, retval);
	retval = ft_printf("NORMAL \'f\'\n\t[%f], retval = |%d|\n", 23.00041, retval);
	retval = ft_printf("NORMAL \'f\'\n\t[%f], retval = |%d|\n", 3.9999999, retval);
	retval = ft_printf("NORMAL \'f\'\n\t[%.0f], retval = |%d|\n", 42.55555555, retval);
	retval = ft_printf("NORMAL \'f\'\n\t[%.1f], retval = |%d|\n", 42.55555555, retval);
	retval = ft_printf("NORMAL \'f\'\n\t[%.5f], retval = |%d|\n", 42.55555555, retval);
	retval = ft_printf("NORMAL \'f\'\n\t[%.6f], retval = |%d|\n", 42.55555555, retval);
	retval = ft_printf("NORMAL \'f\'\n\t[%.7f], retval = |%d|\n", 42.55555555, retval);
	retval = ft_printf("NORMAL \'f\'\n\t[%.10f], retval = |%d|\n", 42.55555555555, retval);
	retval = ft_printf("NORMAL \'f\'\n\t[%f], retval = |%d|\n", 42424242.42424242424242 , retval);
	retval = ft_printf("NORMAL \'f\'\n\t[%.f], retval = |%d|\n", 42424242.42424242424242 , retval);
	retval = ft_printf("NORMAL \'f\'\n\t[%.2f], retval = |%d|\n", 42424242.42424242424242 , retval);
	retval = ft_printf("NORMAL \'f\'\n\t[%f], retval = |%d|\n", -42424242.42424242424242 , retval);
	retval = ft_printf("NORMAL \'f\'\n\t[%.f], retval = |%d|\n", -42424242.42424242424242 , retval);
	retval = ft_printf("NORMAL \'f\'\n\t[%.2f], retval = |%d|\n", -42424242.42424242424242 , retval);
	retval = ft_printf("TREATED AS DOUBLE (PREC > 6) \'f\'\n\t[%.21f], retval = |%d|\n", -42424242.42424242424242 , retval);
	retval = ft_printf("TREATED AS DOUBLE (PREC > 6) \'lf\'\n\t[%.20lf], retval = |%d|\n", -42424242.42424242424242 , retval);
	retval = ft_printf("TREATED AS DOUBLE (PREC > 6) \'f\'\n\t[%.21f], retval = |%d|\n", 42424242.42424242424242 , retval);
	retval = ft_printf("TREATED AS DOUBLE (PREC > 6) \'lf\'\n\t[%.20lf], retval = |%d|\n", 42424242.42424242424242 , retval);
	retval = ft_printf("NORMAL \'f\'\n\t[%10.0f], retval = |%d|\n", 42.55555555, retval);
	retval = ft_printf("NORMAL \'f\'\n\t[%10.1f], retval = |%d|\n", 42.55555555, retval);
	retval = ft_printf("NORMAL \'f\'\n\t[%010.1f], retval = |%d|\n", -42.55555555, retval);
	retval = ft_printf("NORMAL \'f\'\n\t[%+10.1f], retval = |%d|\n", -42.55555555, retval);
	retval = ft_printf("NORMAL \'f\'\n\t[% 10.1f], retval = |%d|\n", -42.55555555, retval);
	retval = ft_printf("NORMAL \'f\'\n\t[%010.1f], retval = |%d|\n", 42.55555555, retval);
	retval = ft_printf("NORMAL \'f\'\n\t[%+10.1f], retval = |%d|\n", 42.55555555, retval);
	retval = ft_printf("NORMAL \'f\'\n\t[% 10.1f], retval = |%d|\n", 42.55555555, retval);
	retval = ft_printf("NORMAL \'f\'\n\t[%-10.1f], retval = |%d|\n", 42.55555555, retval);
	retval = ft_printf("NORMAL \'f\'\n\t[%-10.1f], retval = |%d|\n", -42.55555555, retval);
	retval = ft_printf("NORMAL \'f\'\n\t[%-10.*f], retval = |%d|\n", -1, -42.55555555, retval);

	// NOT IN SUBJECT
	// %ho
	retval = ft_printf("\nSHORT OCTAL, retval = |%d|\n", retval);
	retval = ft_printf("SHORT \'ho\'\n\t[%ho], retval = |%d|\n", 0, retval);
	retval = ft_printf("SHORT \'ho\'\n\t[%ho], retval = |%d|\n", SHRT_MAX, retval);
	retval = ft_printf("SHORT \'ho\'\n\t[%ho], retval = |%d|\n", SHRT_MIN, retval);
	retval = ft_printf("SHORT(OVERFLOW, retval) \'ho\'\n\t[%ho], retval = |%d|\n", SHRT_MAX + 1, retval);
	retval = ft_printf("SHORT(OVERFLOW, retval) \'ho\'\n\t[%ho], retval = |%d|\n", SHRT_MIN - 1, retval);
	// %hho
	retval = ft_printf("\nSHORTCHAR OCTAL, retval = |%d|\n", retval);
	retval = ft_printf("SHORTCHAR \'hho\'\n\t[%hho], retval = |%d|\n", 0, retval);
	retval = ft_printf("SHORTCHAR \'hho\'\n\t[%hho], retval = |%d|\n", SCHAR_MAX, retval);
	retval = ft_printf("SHORTCHAR \'hho\'\n\t[%hho], retval = |%d|\n", SCHAR_MIN, retval);
	retval = ft_printf("SHORTCHAR(OVERFLOW, retval) \'hho\'\n\t[%hho], retval = |%d|\n", SCHAR_MAX + 1, retval);
	retval = ft_printf("SHORTCHAR(OVERFLOW, retval) \'hho\'\n\t[%hho], retval = |%d|\n", SCHAR_MIN - 1, retval);
	// %lo
	retval = ft_printf("\nLONG OCTAL, retval = |%d|\n", retval);
	retval = ft_printf("LONG \'lo\'\n\t[%lo], retval = |%d|\n", 0, retval);
	retval = ft_printf("LONG \'lo\'\n\t[%lo], retval = |%d|\n", LONG_MAX, retval);
	retval = ft_printf("LONG \'lo\'\n\t[%lo], retval = |%d|\n", LONG_MIN, retval);
	retval = ft_printf("LONG(OVERFLOW, retval) \'lo\'\n\t[%lo], retval = |%d|\n", LONG_MAX + 1, retval);
	retval = ft_printf("LONG(OVERFLOW, retval) \'lo\'\n\t[%lo], retval = |%d|\n", LONG_MIN - 1, retval);
	// %llo
	retval = ft_printf("\nLONG LONG OCTAL, retval = |%d|\n", retval);
	retval = ft_printf("LONG LONG \'llo\'\n\t[%llo], retval = |%d|\n", 0, retval);
	retval = ft_printf("LONG LONG \'llo\'\n\t[%llo], retval = |%d|\n", LLONG_MAX, retval);
	retval = ft_printf("LONG LONG \'llo\'\n\t[%llo], retval = |%d|\n", LLONG_MIN, retval);
	retval = ft_printf("LONG LONG(OVERFLOW, retval) \'llo\'\n\t[%llo], retval = |%d|\n", LLONG_MAX + 1, retval);
	retval = ft_printf("LONG LONG(OVERFLOW, retval) \'llo\'\n\t[%llo], retval = |%d|\n", LLONG_MIN - 1, retval);
	// EXTRA
	retval = ft_printf("[%09.1o], retval = |%d|\n", UINT_MAX, retval);
	retval = ft_printf("[%09.2o], retval = |%d|\n", UINT_MAX, retval);
	retval = ft_printf("[%#-03.o], retval = |%d|\n", 0, retval);
	retval = ft_printf("[%#-03o], retval = |%d|\n", 0, retval);
	retval = ft_printf("[%#-03.2o], retval = |%d|\n", 0, retval);
	retval = ft_printf("[%#o], retval = |%d|\n", 0, retval);
	retval = ft_printf("[%#2o], retval = |%d|\n", 0, retval);

	check_leaks();
	return (0);
}
