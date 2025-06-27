#include <stdio.h>
#include "libftprintf.h"
int main()
{
	void *c;
	char *cc;

	c = malloc(sizeof(char) * 5);
	cc = (char *)c;
	cc = "caner";
	ft_printf("u: %u \n d: %d \n i: %i \n", -4, -4, -4);
	ft_printf("caner %d de %s' %c yapiyor.::::::\\\\\\00000000 %%", 42, "ft_printf", 'i');
	ft_printf("\nft%%x: %x\n", 255);
	ft_printf("\n%%p: %p\n", cc);
	printf("\n%%p: %p\n", cc);

}
