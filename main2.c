#include "ft_printf.h"
#include <stdio.h>
#include <wchar.h>
#include <locale.h>

#define NULL  __DARWIN_NULL
#define __DARWIN_NULL ((void *)0)

int 	main (void)
{
	char c = 'r';
	char *str = "dede";
	int 	nbr = 4444444;
	setlocale(LC_ALL, "");
	wchar_t myChar1 = L'Ω';
	long	long_max;
	unsigned long	ulong_max;

	long_max = -9223372036854775808;
	ulong_max = 18446744073709551615;

	// printf("/*******************************************************   TEST D d i   ***************************************************/\n");
	// printf("|%012d| |%%| |%D| |% i| |%-05d%%| |%+4d| |%9.6d| |%#-09.0d| |%12d|\n", nbr, 5, -4, 8, 3, 32, 15, -21);
	// ft_printf("|%012d| |%%| |%D| |% i| |%-05d%%| |%+4d| |%9.6d| |%#-09.0d| |%12d|\n", nbr, 5, -4, 8, 3, 32, 15, -21);

	// printf("\n|%+3ld| |%-#3.6hd| |%0.0jd| |%+06.12hhd| |%-07lld| |%#-7.3zd|\n", 5, 676, 8, 123456789, -543, 9876);
	// ft_printf("|%+3ld| |%-#3.6hd| |%0.0jd| |%+06.12hhd| |%-07lld| |%#-7.3zd|\n", 5, 676, 8, 123456789, -543, 9876);

	// printf("\n|%+3lD| |%-#3.6hD| |%0.0jD| |%+06.12hhD| |%-07llD| |%#-7.3zD|\n", -435, -676, -47478, -123456789, -543, -9876);
	// ft_printf("|%+3lD| |%-#3.6hD| |%0.0jD| |%+06.12hhD| |%-07llD| |%#-7.3zD|\n", -435, -676, -47478, -123456789, -543, -9876);


	// printf("\n\n/****************************************************   TEST c   *******************************************************/\n");
	// printf("%d\n", printf("|%+05.12c| |%+ 4c| |%13c| |%-07c| |%012c| |%#1c|\n", c, 'a', 'b', 'c', 'd', 'e'));
	// ft_printf("%d\n", ft_printf("|%+05.12c| |%+ 4c| |%13c| |%-07c| |%012c| |%#1c|\n", c, 'a', 'b', 'c', 'd', 'e'));

	// printf("|%+3lc| |%-#3.6hc| |%0.0jc| |%+06.12hhc| |%-07llc| |%#-7.3zc|\n", 'a', 'b', 'c', 'd', 'e', 'f');
	// ft_printf("|%+3lc| |%-#3.6hc| |%0.0jc| |%+06.12hhc| |%-07llc| |%#-7.3zc|\n", 'a', 'b', 'c', 'd', 'e', 'f');


	// printf("\n\n/*******************************************************   TEST s   *****************************************************/\n");
	// printf("%d\n", printf("|%#0.2s| |%3s| |%04s| |%-04s| |%+011s| |%07.2s| |%-8.4s|\n", "salut", "42", "32", "wq", "43", "salut", "123456789"));
	// ft_printf("%d\n", ft_printf("|%#0.2s| |%3s| |%04s| |%-04s| |%+011s| |%07.2s| |%-8.4s|\n", "salut", "42", "32", "wq", "43", "salut", "123456789"));
	// 	printf("%d\n", printf("|%#0.2s| |%3s| |%04s| |%-04s| |%+011s| |%07.2s| |%-8.4s|\n", "salut", "42", "32", "wq", "43", "salut", "123456789"));

	// printf("%d\n", printf("|%3s| \n", "42"));
	// ft_printf("%d\n", ft_printf("|%3s| \n", "42"));


	// printf("|%-#3.6hs| |%0.0js| |%+06.12hhs| |%-07lls| |%#-7.3zs|\n", "qwerty", "qwerty", "qwerty", "qwerty", "qwerty");
	// ft_printf("|%-#3.6hs| |%0.0js| |%+06.12hhs| |%-07lls| |%#-7.3zs|\n", "qwerty", "qwerty", "qwerty", "qwerty", "qwerty");


	// printf("\n\n/******************************************************   TEST x X   ****************************************************/\n");
	// printf("%d\n", printf("|%#x|%x|%x|%x|%x|%x|%x|\n", 1, 4, 10, 100, 1000, 10000, 99999999));
	// ft_printf("%d\n", ft_printf("|%#x|%x|%x|%x|%x|%x|%x|\n", 1, 4, 10, 100, 1000, 10000, 99999999));
	// printf("%d\n", printf("|%#X|%X|%X|%X|%X|%X|%X|\n", 1, 4, 10, 100, 1000, 10000, 99999999));
	// ft_printf("%d\n", ft_printf("|%#X|%X|%X|%X|%X|%X|%X|\n", 1, 4, 10, 100, 1000, 10000, 99999999));
	// printf("%d\n", printf("|%x| |%#08x| |%#-08x| |%#x| |%#08.0X| |%#-06x| |%++++++-0-++++06X| |%9.6x|\n", 4, 43, 23, 954, 971, 34, 31, 23));
	// ft_printf("%d\n", ft_printf("|%x| |%#08x| |%#-08x| |%#x| |%#08.0X| |%#-06x| |%++++++-0-++++06X| |%9.6x|\n", 4, 43, 23, 954, 971, 34, 31, 23));

	// printf("%d\n", printf("|%+3lx| |%8hhx| |%-#3.6hx| |%0.0jx| |%+06.12hhx| |%-07llx| |%#-7.3zx|\n", 5, 7843 ,43, 548, 123456789, 123, 9876));
	// ft_printf("%d\n", ft_printf("|%+3lx| |%8hhx| |%-#3.6hx| |%0.0jx| |%+06.12hhx| |%-07llx| |%#-7.3zx|\n", 5, 7843 ,43, 548, 123456789, 123, 9876));

	// printf("%d\n", printf("|%+3lX| |%-#3.6hX| |%0.0jX| |%+06.12hhX| |%-07llX| |%#-7.3zX|\n", -435, -676, -47478, -123456789, -543, -9876));
	// ft_printf("%d\n", ft_printf("|%+3lX| |%-#3.6hX| |%0.0jX| |%+06.12hhX| |%-07llX| |%#-7.3zX|\n", -435, -676, -47478, -123456789, -543, -9876));


	// printf("%d\n", printf("%x%x%x%x%x\n", 1, 100, 999, 42, 999988888));
	// ft_printf("%d\n", ft_printf("%x%x%x%x%x\n", 1, 100, 999, 42, 999988888));

	// printf("%d\n", printf("|%.0x|\n", 0));
	// ft_printf("%d\n", ft_printf("|%.0x|\n", 0));


	// printf("\n\n/******************************************************   TEST u U   ******************************************************/\n");
	// printf("%d\n", printf("|%012u| |%09U| |%#-05u| |% .20u| |%-09.5u| |%+11u|\n", nbr, +21, 5, -4, 8, 3));
	// ft_printf("%d\n", ft_printf("|%012u| |%09U| |%#-05u| |% .20u| |%-09.5u| |%+11u|\n", nbr, +21, 5, -4, 8, 3));

	// printf("\n|%+3lu| |%-#3.6hu| |%0.0ju| |%+06.12hhu| |%-07llu| |%#-7.3zu|\n", 5, 63, 8, 123456789, 543, 9876);
	// ft_printf("|%+3lu| |%-#3.6hu| |%0.0ju| |%+06.12hhu| |%-07llu| |%#-7.3zu|\n", 5, 63, 8, 123456789, 543, 9876);

	// printf("\n|%+3lU| |%-#3.6hU| |%0.0jU| |%+06.12hhU| |%-07llU| |%#-7.3zU|\n", -435, -676, -47478, -123456789, -543, -876);
	// ft_printf("|%+3lU| |%-#3.6hU| |%0.0jU| |%+06.12hhU| |%-07llU| |%#-7.3zU|\n", -435, -676, -47478, -123456789, -543, -876);


	// printf("\n\n/*****************************************************   TEST o O   ******************************************************/\n");
	// printf("|% o| |%#-.4o| |%012o| |%-#6o| |%+06.4o| |%-4o| |%#-5.11o|\n", 10, 12, 21, 11, 12, 5, 54);
	// ft_printf("|% o| |%#-.4o| |%012o| |%-#6o| |%+06.4o| |%-4o| |%#-5.11o|\n", 10, 12, 21, 11, 12, 5, 54);

 // 	printf("%d\n", printf("%o%o%o%o%o\n", 1, 100, 999, 42, 999988888));
 // 	ft_printf("%d\n", ft_printf("%o%o%o%o%o\n", 1, 100, 999, 42, 999988888));


	// printf("%d\n", printf("%O%O%O%O%O\n", 1, 100, 999, 42, 999988888));
	// ft_printf("%d\n", ft_printf("%O%O%O%O%O\n", 1, 100, 999, 42, 999988888));


	// printf("\n|%+3lo| |%-#3.6ho| |%0.0jo| |%+06.12hho| |%-07llo| |%#-7.3zo|\n", 5, 6764343, 8, 123456789, 543, 9876);
	// ft_printf("|%+3lo| |%-#3.6ho| |%0.0jo| |%+06.12hho| |%-07llo| |%#-7.3zo|\n", 5, 6764343, 8, 123456789, 543, 9876);

	// printf("\n|%+3lO| |%-#3.6hO| |%0.0jO| |%+06.12hhO| |%-07llO| |%#-7.3zO|\n", -435, -676, -47478, -123456789, -543, -9876);
	// ft_printf("|%+3lO| |%-#3.6hO| |%0.0jO| |%+06.12hhO| |%-07llO| |%#-7.3zO|\n", -435, -676, -47478, -123456789, -543, -9876);


	// printf("\n\n/******************************************************   TEST P   ******************************************************/\n");
	// printf("|%p| |%016p| |%-16p| |%14.4p| |%p|\n", str, str, str, nbr, c);
	// ft_printf("|%p| |%016p| |%-16p| |%14.4p| |%p|\n", str, str, str, nbr, c);

	// printf("|%14.4p|\n", nbr);
	// ft_printf("|%14.4p|\n", nbr);

	// printf("|%14p|\n", nbr);
	// ft_printf("|%14p|\n", nbr);

	// printf("\n|%+3lp| |%-#3.6hp| |%0.0jp| |%+06.12hhp| |%-07llp| |%#-7.3zp|\n", str, nbr, c, c, nbr, str);
	// ft_printf("|%+3lp| |%-#3.6hp| |%0.0jp| |%+06.12hhp| |%-07llp| |%#-7.3zp|\n", str, nbr, c, c, nbr, str);


	// printf("\n\n/*****************************************************    TEST C S    *****************************************************/\n");
	// printf("%d\n", printf("|%-8C| |%#0 9lc| |%S|\n", myChar1, L'ℜ', L"ο Δικαιοπολις"));
	// ft_printf("%d\n", ft_printf("|%-8C| |%#0 9lc| |%S|\n", myChar1, L'ℜ', L"ο Δικαιοπολις"));
	// printf("%d\n", printf("|%lc|\n", 'a'));
	// ft_printf("%d\n", ft_printf("|%lc|\n", 'a'));

	// printf("\n\n/******************************************************   TEST WTF   ******************************************************/\n");
	// printf("|%xoxoxoxo| |%0000000000000x| |%-7llllllllllllx| |%#hhhhhhhhhhx| |%#----######-######08.0X| |%#-###-----#0++ #####9.8o| |%++++++-0-+++  +++----06X|\n", 43, -54, 95, 9, 532, 467349478438, -555);
	// ft_printf("|%xoxoxoxo| |%0000000000000x| |%-7llllllllllllx| |%#hhhhhhhhhhx| |%#----######-######08.0X| |%#-###-----#0++ #####9.8o| |%++++++-0-+++  +++----06X|\n", 43, -54, 95, 9, 532, 467349478438, -555);


	// printf("\n\n/******************************************************   TEST NULL   ******************************************************/\n");

	// printf("%d\n", printf("|%-10d| |%c| |%s| |%u| |%C| |%p|\n", NULL, NULL, NULL, NULL, NULL, 0));
	// ft_printf("%d\n", ft_printf("|%-10d| |%c| |%s| |%u| |%C| |%p|\n", NULL, NULL, NULL, NULL, NULL, 0));

	// printf("\n\n/******************************************************   VALEUR RETOUR   ******************************************************/\n");


	// printf("%d\n", printf("\n|%+3lx| |%8hhx| |%-#3.6hx| |%0.0jx| |%+06.12hhx| |%-07llx| |%#-7.3zx|\n", 5, 7843 ,43, 548, 123456789, 123, 9876));
	// ft_printf("%d\n", ft_printf("\n|%+3lx| |%8hhx| |%-#3.6hx| |%0.0jx| |%+06.12hhx| |%-07llx| |%#-7.3zx|\n", 5, 7843 ,43, 548, 123456789, 123, 9876));

	// printf("%d\n", printf("|%p| |%016p| |%-16p|\n", str, str, nbr));
	// ft_printf("%d\n", ft_printf("|%p| |%016p| |%-16p|\n", str, str, nbr));

	// printf("%d\n", printf("|%xoxoxoxo| |%0000000000000x| |%-7llllllllllllx| |%#hhhhhhhhhhx| |%#----######-######08.0X| |%#-###-----#0++ #####9.8o| |%++++++-0-+++  +++----06X|\n", 43, -54, 95, 9, 532, 467349478438, -555));
	// ft_printf("%d\n", ft_printf("|%xoxoxoxo| |%0000000000000x| |%-7llllllllllllx| |%#hhhhhhhhhhx| |%#----######-######08.0X| |%#-###-----#0++ #####9.8o| |%++++++-0-+++  +++----06X|\n", 43, -54, 95, 9, 532, 467349478438, -555));

	// printf("%d\n", printf("|%#o| |%#-.4o| |%012o| |%-#6o| |%+06.4o| |%-4o| |%#-5.11o|\n", 10, 12, 21, 11, 12, 5, 54));
	// ft_printf("%d\n", ft_printf("|%#o| |%#-.4o| |%012o| |%-#6o| |%+06.4o| |%-4o| |%#-5.11o|\n", 10, 12, 21, 11, 12, 5, 54));

	printf("\n\n/******************************************************   TEST MOULITEST   ******************************************************/\n");

	// printf("\n**** 0 *****\n");

	// printf("%d\n", printf("|%5%|\n", c));
	// ft_printf("%d\n", ft_printf("|%5%|\n"));

	// printf("\n**** 1 *****\n");

	// printf("%d\n", printf("|%-5%|\n"));
	// ft_printf("%d\n", ft_printf("|%-5%|\n"));

	// printf("\n**** 2 *****\n");

	// printf("%d\n", printf("|%.0%|\n"));
	// ft_printf("%d\n", ft_printf("|%.0%|\n"));

	// printf("\n***** 3 ****\n");

	// printf("%d\n", printf("%   %", "test"));
	// ft_printf("%d\n", ft_printf("%   %", "test"));


	// printf("\n**** 1 *****\n");

	// printf("%d\n", printf("%#x\n", 0));
	// ft_printf("%d\n", ft_printf("%#x\n", 0));

	// printf("\n**** 2 *****\n");

	// printf("%d\n", printf("%X\n", 0));
	// ft_printf("%d\n", ft_printf("%X\n", 0));

	// printf("\n**** 3 *****\n");

	// printf("%d\n", printf("%x\n", 0));
	// ft_printf("%d\n", ft_printf("%x\n", 0));


	// printf("\n**** 4 *****\n");

	// printf("%d\n", printf("%x", str));
	// ft_printf("%d\n", ft_printf("%x", str));

	// printf("\n**** 5 *****\n");

	// printf("%d\n", printf("%o\n", 0));
	// ft_printf("%d\n", ft_printf("%o\n", 0));

	// printf("\n**** 5 *****\n");

	// printf("%d\n", printf("@moulitest: %#.x, %#.0x", 0, 0));
	// ft_printf("%d\n", ft_printf("@moulitest: %#.x, %#.0x", 0, 0));

	// printf("\n***** 6 ****\n");

	// printf("%d\n", printf("@moulitest: %.x, %.0x", 0, 0));
	// ft_printf("%d\n", ft_printf("@moulitest: %.x, %.0x", 0, 0));

	// printf("\n***** 7 ****\n");

	// printf("%d\n", printf("@moulitest: %5.x, %5.0x", 0, 0));
	// ft_printf("%d\n", ft_printf("@moulitest: %5.x, %5.0x", 0, 0));

	// printf("\n**** 6 ***** %%03.2d, 0 \n");

	// printf("%d\n", printf("%03.2d\n", 0));
	// ft_printf("%d\n", ft_printf("%03.2d\n", 0));

	// printf("\n**** 7 ***** %%.d, %%.0d, 0, 0 \n");

	// printf("%d\n", printf("@moulitest: %.d, %.0d\n", 0, 0));
	// ft_printf("%d\n", ft_printf("@moulitest: %.d, %.0d\n", 0, 0));

	// printf("\n**** 8 ***** %%5.d, %%5.0d, 0, 0\n");

	// printf("%d\n", printf("@moulitest: %5.d, %5.0d\n", 0, 0));
	// ft_printf("%d\n", ft_printf("@moulitest: %5.d, %5.0d\n", 0, 0));




	// printf("\n**** 8 *****\n");

	// printf("%d\n", printf("@moulitest: %s", NULL));
	// ft_printf("%d\n", ft_printf("@moulitest: %s", NULL));

	// printf("\n**** 9 *****\n");

	// printf("%d\n", printf("%.2c", NULL));
	// ft_printf("%d\n", ft_printf("%.2c", NULL));

	// printf("\n***** 10 ****\n");

	// printf("%d\n", printf("@moulitest: %c", 0));
	// ft_printf("%d\n", ft_printf("@moulitest: %c", 0));

	// printf("\n***** 11 ****\n");

	// printf("%d\n", printf("%2c", 0));
	// ft_printf("%d\n", ft_printf("%2c", 0));

	// printf("\n**** 12 *****\n");

	// printf("%d\n", printf("null %c and text", 0));
	// ft_printf("%d\n", ft_printf("null %c and text", 0));

	// printf("\n***** 13 ****\n");

	// printf("%d\n", printf("% c\n", 0));
	// ft_printf("%d\n", ft_printf("% c\n", 0));

	// printf("\n**** 14 *****\n");

	// printf("%d\n", printf("@moulitest: %.o, %.0o\n", 0, 0));
	// ft_printf("%d\n", ft_printf("@moulitest: %.o, %.0o\n", 0, 0));

	// printf("\n**** 15 *****\n");

	// printf("%d\n", printf("@moulitest: %5.o, %5.0o\n", 0, 0));
	// ft_printf("%d\n", ft_printf("@moulitest: %5.o, %5.0o\n", 0, 0));

	// printf("\n**** 16 *****\n");

	// printf("%d\n", printf("@moulitest: %#.o, %#.0o\n", 0, 0));
	// ft_printf("%d\n", ft_printf("@moulitest: %#.o, %#.0o\n", 0, 0));

	// printf("\n***** 17 ****\n");

	// printf("%d\n", printf("%d is one\n", 1));
	// ft_printf("%d\n", ft_printf("%d is one\n", 1));

	// printf("\n***** 18 ****\n");

	// printf("%d\n", printf("% d\n", -42));
	// ft_printf("%d\n", ft_printf("% d\n", -42));

	// printf("\n**** 19 *****\n");

	// printf("%d\n", printf("%+ d", 42));
	// ft_printf("%d\n", ft_printf("%+ d", 42));

	// printf("\n**** 20 *****\n");

	// printf("%d\n", printf("%  +d", 42));
	// ft_printf("%d\n", ft_printf("%  +d", 42));

	// printf("\n***** 21 ****\n");

	// printf("%d\n", printf("% +d", -42));
	// ft_printf("%d\n", ft_printf("% +d", -42));

	// printf("\n**** 22 *****\n");

	// printf("%d\n", printf("%+ d", -42));
	// ft_printf("%d\n", ft_printf("%+ d", -42));

//OKOKOKOKOK

	// printf("\n**** 23 *****\n");

	// printf("%d\n", printf("%0+d\n", 42));
	// ft_printf("%d\n", ft_printf("%0+d\n", 42));

	// printf("\n**** 20 *****\n");

	// printf("%d\n", printf("%5d\n", -42));
	// ft_printf("%d\n", ft_printf("%5d\n", -42));

	// printf("\n**** 21 *****\n");

	// printf("%d\n", printf("%05d\n", -42));
	// ft_printf("%d\n", ft_printf("%05d\n", -42));

	// printf("\n**** 22 *****\n");

	// printf("%d\n", printf("%0+5d\n", -42));
	// ft_printf("%d\n", ft_printf("%0+5d\n", -42));

	// printf("\n**** 23 *****\n");

	// printf("%d\n", printf("%0+12d\n", 42));
	// ft_printf("%d\n", ft_printf("%0+12d\n", 42));

	// printf("\n**** 23 BIS*****\n");

	// printf("%d\n", printf("%+5d\n", 42));
	// ft_printf("%d\n", ft_printf("%+5d\n", 42));

	// printf("\n***** 24 ****\n");

	// printf("\n%d\n", printf("%5d\n", 42));
	// ft_printf("\n%d\n", ft_printf("%5d\n", 42));

	// printf("\n**** 25 *****\n");

	// printf("\n%d\n", printf("%-5d\n", -42));
	// ft_printf("\n%d\n", ft_printf("%-5d\n", -42));

	// printf("\n**** 26 *****\n");

	// printf("\n%d\n", printf("%-05d\n", -42));
	// ft_printf("\n%d\n", ft_printf("%-05d\n", -42));

	// printf("\n**** 26 *****\n");

	// printf("\n%d\n", printf("%#8x", 42));
	// ft_printf("\n%d\n", ft_printf("%#8x", 42));

	// printf("\n**** 26 *****\n");

	// printf("\n%d\n", printf("%#08x", 42));
	// ft_printf("\n%d\n", ft_printf("%#08x", 42));

	// printf("\n**** 26 *****\n");

	// printf("\n%d\n", printf("%#8x", 42));
	// ft_printf("\n%d\n", ft_printf("%#8x", 42));

	// printf("\n**** 27 *****\n");

	// printf("\n%d\n", printf("%+10.5d", 4242));
	// ft_printf("\n%d\n", ft_printf("%+10.5d", 4242));

	// printf("\n**** 27 *****\n");

	// printf("\n%d\n", printf("%-+10.5d", 4242));
	// ft_printf("\n%d\n", ft_printf("%-+10.5d", 4242));

	// printf("\n**** 28 *****\n");

	// printf("%d\n", printf("@moulitest: %.10d\n", -42));
	// ft_printf("%d\n", ft_printf("@moulitest: %.10d\n", -42));


	// printf("\n**** 29 *****\n");

	// printf("\n**** a *****\n");

	// printf("%d\n", printf("@moulitest: %.d\n", 42));
	// ft_printf("%d\n", ft_printf("@moulitest: %.d\n", 42));

	// printf("\n**** b *****\n");

	// 	printf("%d\n", printf("@moulitest: %.0d\n", 43));
	// ft_printf("%d\n", ft_printf("@moulitest: %.0d\n", 43));

	// printf("\n**** b *****\n");

	// printf("%d\n", printf("@moulitest: %.d, %.0d\n", 42, 43));
	// ft_printf("%d\n", ft_printf("@moulitest: %.d, %.0d\n", 42, 43));

	// printf("\n***** 30 ****\n");

	// printf("%d\n", printf("@moulitest: %.d, %.0d", 0, 0));
	// ft_printf("%d\n", ft_printf("@moulitest: %.d, %.0d", 0, 0));

	// printf("\n**** 31 *****\n");

	// printf("%d\n", printf("@moulitest: %5.d, %5.0d", 0, 0));
	// ft_printf("%d\n", ft_printf("@moulitest: %5.d, %5.0d", 0, 0));

	// printf("\n**** 32 *****\n");

	// printf("%d\n", printf("%hU\n", "4294967296"));
	// ft_printf("%d\n", ft_printf("%hU\n", "4294967296"));

	printf("\n********************************  MOULITEST ********************************************\n");

// 	printf("%d\n", printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c \
// %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\
// %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",
// ' ', '!', '"', '#', '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-',
// '.', '/', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ':', ';',
// '<', '=', '>', '?', '@', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
// 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W',
// 'X', 'Y', 'Z', '[', '\\', ']', '^', '_', '`', 'a', 'b', 'c', 'd', 'e',
// 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's',
// 't', 'u', 'v', 'w', 'x', 'y', 'z', '{', '|', '}'));
// 	ft_printf("%d\n", ft_printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c \
// %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\
// %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",
// ' ', '!', '"', '#', '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-',
// '.', '/', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ':', ';',
// '<', '=', '>', '?', '@', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
// 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W',
// 'X', 'Y', 'Z', '[', '\\', ']', '^', '_', '`', 'a', 'b', 'c', 'd', 'e',
// 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's',
// 't', 'u', 'v', 'w', 'x', 'y', 'z', '{', '|', '}'));


	// printf("\n**** 1 min_width_c(t_test *test) *****\n");

	// printf("%d\n", printf("{%3c}", 0));
	// ft_printf("%d\n", ft_printf("{%3c}", 0));

	// printf("\n**** 2 pZero_5MinWidth(t_test *test) *****\n");

	// printf("%d\n", printf("{%5p}", 0));
	// ft_printf("%d\n", ft_printf("{%5p}", 0));


	// printf("\n**** 3 pZero_minus15MinWidth(t_test *test) *****\n");

	// printf("%d\n", printf("{%-15p}", 0));
	// ft_printf("%d\n", ft_printf("{%-15p}", 0));


	// printf("\n**** 4 pZero_minus13MinWidth(t_test *test) *****\n");

	// printf("%d\n", printf("{%-13p}", &strlen));
	// ft_printf("%d\n", ft_printf("{%-13p}", &strlen));


	// printf("\n**** 5 pZero_minus12MinWidth(t_test *test) *****\n");

	// printf("%d\n", printf("{%-12p}", &strlen));
	// ft_printf("%d\n", ft_printf("{%-12p}", &strlen));


	// printf("\n**** 6 invalidConvSpec_withMinWith(t_test *test) *****\n");

	// printf("%d\n", printf("{%10R}"));
	// ft_printf("%d\n", ft_printf("{%10R}"));

	// printf("\n**** %%.u, %%.0u, 0, 0 *****\n");

	// printf("%d\n", printf("%.u, %.0u", 0, 0));
	// ft_printf("%d\n", ft_printf("%.u, %.0u", 0, 0));

	// printf("\n**** %s %C %d %p %x %% %S", "bonjour ", L'該', 42, &free, 42, L"لحم خنزير *****\n");

	// printf("%d\n", printf("%s %C %d %p %x %% %S\n", "bonjour ", L'該', 42, &free, 42, L"لحم خنزير"));
	// ft_printf("%d\n", ft_printf("%s %C %d %p %x %% %S\n", "bonjour ", L'該', 42, &free, 42, L"لحم خنزير"));

	// printf("%S", L"該لحم خنزير");
	// ft_printf("%S", L"該لحم خنزير");
	// printf("%d\n", printf("%s %C %d %p %x %c", "bonjour ", L'該', 42, &free, 42, 'm'));
	// ft_printf("%d\n", ft_printf("%s %C %d %p %x %c", "bonjour ", L'該', 42, &free, 42, 'm'));

	// printf("\n**** %s%d%p%%%S%D%i%o%O%u%U%x%X%c%C,bonjour, 42, &c, L暖炉, long_max, 42, 42, 42, 100000, ulong_max, 42, 42, c, L플 ******\n");


	// printf("%d\n", printf("%s%d%p%%%S%D%i%o%O%u%U%x%X%c%C","bonjour", 42, &c, L"暖炉", long_max, 42, 42, 42, 100000, ulong_max, 42, 42, 'c', L'플'));
	// ft_printf("%d\n", ft_printf("%s%d%p%%%S%D%i%o%O%u%U%x%X%c%C","bonjour", 42, &c, L"暖炉", long_max, 42, 42, 42, 100000, ulong_max, 42, 42, 'c', L'플'));

	// printf("\n**** {%% c}, 0*****\n");

	// printf("%d\n", printf("{% c}\n", 0));
	// ft_printf("%d\n", ft_printf("{% c}\n", 0));

	// printf("\n**** {%% C}, 0 *****\n");

	// printf("%d\n", printf("{% C}\n", 0));
	// ft_printf("%d\n", ft_printf("{% C}\n", 0));

	// printf("\n**** %% *****\n");

	// printf("%d\n", printf("%"));
	// ft_printf("%d\n", ft_printf("%"));

	// printf("\n**** %% Zoooo *****\n");

	// printf("%d\n", printf("% Zoooo\n"));
	// ft_printf("%d\n", ft_printf("% Zoooo\n"));

	// printf("\n**** {%%}*****\n");

	// printf("%d\n", printf("{%}\n"));
	// ft_printf("%d\n", ft_printf("{%}\n"));

	// printf("\n**** {%% C}, 0 *****\n");

	// printf("%d\n", printf("{% C}\n", 0));
	// ft_printf("%d\n", ft_printf("{% C}\n", 0));


	// printf("\n**** %%.0p, %%.p, 0, 0 *****\n");

	// printf("%d\n", printf("%.0p, %.p", 0, 0));
	// ft_printf("%d\n", ft_printf("%.0p, %.p", 0, 0));

	// printf("\n**** %%.5p, 0 *****\n");

	// printf("%d\n", printf("%.5p", 0));
	// ft_printf("%d\n", ft_printf("%.5p", 0));

	// printf("\n**** %%2.9p, 1234 *****\n");

	// printf("%d\n", printf("%2.9p", 1234));
	// ft_printf("%d\n", ft_printf("%2.9p", 1234));

	// printf("\n**** %%.4p\n, 1234 *****\n");

	// printf("%d\n", printf("%.4p\n", 1234));
	// ft_printf("%d\n", ft_printf("%.4p\n", 1234));

	// printf("\n**** %%2.9p, 1234567 *****\n");

	// printf("%d\n", printf("%2.9p", 1234567));
	// ft_printf("%d\n", ft_printf("%2.9p", 1234567));

	// printf("\n**** %%hhC, %hhC, 0, L'米' *****\n");

	// printf("%d\n", printf("%hhC, %hhC", 0, L'米'));
	// ft_printf("%d\n", ft_printf("%hhC, %hhC", 0, L'米'));

	// printf("\n**** {%% 03d}, 0 *****\n");

	// printf("%d\n", printf("{% 03d}", 0));
	// ft_printf("%d\n", ft_printf("{% 03d}", 0));

	// printf("\n**** {%% 3.2d}, 0 *****\n");

	// printf("%d\n", printf("{% 3.2d}", 0));
	// ft_printf("%d\n", ft_printf("{% 3.2d}", 0));


	// printf("\n**** {%%03.2d}, 0 *****\n");

	// printf("%d\n", printf("{%03.2d}", 0));
	// ft_printf("%d\n", ft_printf("{%03.2d}", 0));


	printf("\n**** %%4.s, 42 *****\n");

	printf("%d\n", printf("%4.s\n", "42"));
	ft_printf("%d\n", ft_printf("%4.s\n", "42"));

	printf("\n**** %%.4S, L我是一只猫。 *****\n");

	printf("%d\n", printf("%.4S\n", L"我是一只猫。"));
	ft_printf("%d\n", ft_printf("%.4S\n", L"我是一只猫。"));


	printf("\n**** %%15.4S, L 我是一只猫。 *****\n");

	printf("%d\n", printf("%15.4S\n", L"我是一只猫。"));
	ft_printf("%d\n", ft_printf("%15.4S\n", L"我是一只猫。"));

	printf("\n**** %%4.15S, L我是一只猫。  *****\n");

	printf("%d\n", printf("%4.15S", L"我是一只猫。"));
	ft_printf("%d\n", ft_printf("%4.15S", L"我是一只猫。"));


	//"{%-15Z}", 123)

	ft_putstr("\n\n\nCOMPILATION OK FUCK YEAH\n\n\n");
	return (0);

}
