#include "ft_printf.h"
#include <stdio.h>
#include <libc.h>

int main(void)
{
	// setbuf(stdout, NULL);
	// close(1);
	// int og = printf("[%d%s\t\r]", 42, "string");
	// printf("\n%d\n", og);
	// int xx = ft_printf("[%d%s\t\r]", 42, "string");
	// printf("\n%d\n", xx);
	// fprintf(stderr, "%d %d\n", xx, og);
	// ft_printf("[--% d % d ]\n", -1, -1);
	// printf("[%.-25s]\n", "test");
	// printf("[%05c]\n", 'c');
	// t_flags flags;
	// memset(&flags, -1, sizeof(flags));
	// printf("%d", flags.minus);
	// printf("%d", flags.plus);
	// printf("[%.-10d]\n", 42);
	// printf("[%x]\n", 42);

	int og = printf("%7.5s", "bombastic");
	printf("[%d]\n", og);
	// sleep(2);
	int xx = ft_printf("%7.5s", "bombastic");
	printf("[%d]\n", xx);

	// og =    printf(">---<%8.30s>---<", "");
	// printf("[%d]\n", og);
	// sleep(2);
	// xx = ft_printf(">---<%8.30s>---<", "");
	// printf("[%d]\n", xx);

	// og =    printf(" %-6s ", "test");
	// printf("[%d]\n", og);
	// sleep(2);
	// xx = ft_printf(" %-6s ", "test");
	// printf("[%d]\n", xx);

	// og =    printf("%s", (char *)NULL);
	// printf("[%d]\n", og);
	// sleep(2);
	// xx = ft_printf("%s", (char *)NULL);
	// printf("[%d]\n", xx);

	// og =    printf(" %-2c ", '0');
	// printf("[%d]\n", og);
	// sleep(2);
	// xx = ft_printf(" %-2c ", '0');
	// printf("[%d]\n", xx);

	// og =    printf("%5%");
	// printf("[%d]\n", og);
	// sleep(2);
	// xx = ft_printf("%5%");
	// printf("[%d]\n", xx);

	// og =    printf("%23s", NULL);
	// printf("[%d]\n", og);
	// sleep(2);
	// xx = ft_printf("%23s", NULL);
	// printf("[%d]\n", xx);

	// og =    printf("%.s", NULL);
	// printf("[%d]\n", og);
	// sleep(2);
	// xx = ft_printf("%.s", NULL);
	// printf("[%d]\n", xx);

	// og = printf("%5s", "goes over");
	// printf("[%d]\n", og);
	//// sleep(2);
	// xx = ft_printf("%5s", "goes over");
	// printf("[%d]\n", xx);

	// og = printf("%-7.5s", "tubular");
	// printf("[%d]\n", og);
	//  sleep(2);
	// xx = ft_printf("%-7.5s", "tubular");
	// printf("[%d]\n", xx);

	 og =    printf("%07i", -54);
	 printf("[%d]\n", og);
	//sleep(2);
	 xx = ft_printf("%07i", -54);
	 printf("[%d]\n", xx);

	 og =    printf("%.6i", -35);
	 printf("[%d]\n", og);
	//sleep(2);+
	 xx = ft_printf("%.6i", -35);
	 printf("[%d]\n", xx);

	 og =    printf("%8.5i", 34);
	 printf("[%d]\n", og);
	//sleep(2);+
	 xx = ft_printf("%8.5i", 34);
	 printf("[%d]\n", xx);

	 og =    printf("%0.6i", -3);
	 printf("[%d]\n", og);
	//sleep(2);+
	 xx = ft_printf("%0.6i", -3);
	 printf("[%d]\n", xx);

	 og =    printf("%0.06i", -3);
	 printf("[%d]\n", og);
	//sleep(2);+
	 xx = ft_printf("%0.06i", -3);
	 printf("[%d]\n", xx);

	 og =    printf("%.06i", -3);
	 printf("[%d]\n", og);
	//sleep(2);+
	 xx = ft_printf("%.06i", -3);
	 printf("[%d]\n", xx);

	 og =    printf("%.100d", INT_MIN);
	 printf("[%d]\n", og);
	//sleep(2);+
	 xx = ft_printf("%.100d", INT_MIN);
	 printf("[%d]\n", xx);

	 og =    printf("%05i", 43);
	 printf("[%d]\n", og);
	//sleep(2);+
	 xx = ft_printf("%05i", 43);
	 printf("[%d]\n", xx);

	og = printf("%10.5i", -216);
	printf("[%d]\n", og);
	// sleep(2);+
	xx = ft_printf("%10.5i", -216);
	printf("[%d]\n", xx);

	 og =    printf("%8.1i", -8473);
	 printf("[%d]\n", og);
	//sleep(2);+
	 xx = ft_printf("%8.1i", -8473);
	 printf("[%d]\n", xx);

	 og =    printf("%07i", -54);
	 printf("[%d]\n", og);
	//sleep(2);+
	 xx = ft_printf("%07i", -54);
	 printf("[%d]\n", xx);

	 og =    printf("\\!/%44.2d\\!/", -376107280);
	 printf("[%d]\n", og);
	//sleep(2);+
	 xx = ft_printf("\\!/%44.2d\\!/", -376107280);
	 printf("[%d]\n", xx);

	 og =    printf("42%42.48d42", -1897837568);
	 printf("[%d]\n", og);
	//sleep(2);+
	 xx = ft_printf("42%42.48d42", -1897837568);
	 printf("[%d]\n", xx);

	 og =    printf("^.^/%12.11d^.^/", -1515721216);
	 printf("[%d]\n", og);
	//sleep(2);+
	 xx = ft_printf("^.^/%12.11d^.^/", -1515721216);
	 printf("[%d]\n", xx);

	 og =    printf(">------------<% 2.55d>------------<", 0);
	 printf("[%d]\n", og);
	//sleep(2);+
	 xx = ft_printf(">------------<% 2.55d>------------<", 0);
	 printf("[%d]\n", xx);



	 og =    printf(">------------<% 12.42d>------------<", 0);
	 printf("[%d]\n", og);
	//sleep(2);+
	 xx = ft_printf(">------------<% 12.42d>------------<", 0);
	 printf("[%d]\n", xx);

	 og =    printf("%.d, %.d, %.d, %.d, %.d, %.d, %.d, %.d", 0, 5, -1, -10, 100, -1862, INT_MIN, 
INT_MAX);
	 printf("[%d]\n", og);
	//sleep(2);+
	 xx = ft_printf("%.d, %.d, %.d, %.d, %.d, %.d, %.d, %.d", 0, 5, -1, -10, 100, -1862, INT_MIN, 
INT_MAX);
	 printf("[%d]\n", xx);


	 og =    printf(">------------<% 13.20d>------------<", -1119194703);
	 printf("[%d]\n", og);
	//sleep(2);+
	 xx = ft_printf(">------------<% 13.20d>------------<", -1119194703);
	 printf("[%d]\n", xx);

	 og =    printf("%-8.5i", 34);
	 printf("[%d]\n", og);
	//sleep(2);+
	 xx = ft_printf("%-8.5i", 34);
	 printf("[%d]\n", xx);

	 og =    printf("!% 5.2d!", -1598884606);
	 printf("[%d]\n", og);
	//sleep(2);+
	 xx = ft_printf("!% 5.2d!", -1598884606);
	 printf("[%d]\n", xx);



}

// flag '.' : -with 's' > precision prints that many chars
//	+
//	#
//	' '
//	0
//	n
//	-
//	.