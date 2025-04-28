#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int main()
{
	ft_printf("**********************\n     1 - char c   \n**********************\n\n");
	ft_printf("Subscenario: simple char + count\n");
	int orig = printf("OR char: print this %c\n", 'c');
	int ft = ft_printf("FT char: print this %c\n", 'c');
	printf("Original: %d \nFT version: %d\n\n", orig, ft);

	ft_printf("Subscenario: 2 consecutive chars + count\n");
	orig = printf("OR char: print this %c%c\n", 'c', 'h');
	ft = ft_printf("FT char: print this %c%c\n", 'c', 'h');
	printf("Original: %d \nFT version: %d\n\n", orig, ft);
	//ft = ft_printf("FT char: print this %c%c\n", 'c', 'h');

	ft_printf("\n**********************\n      2 - %%    \n**********************\n\n");
	ft_printf("Subscenario: simple %% + count\n");
	orig = printf("OR char: print this %%\n");
	ft = ft_printf("FT char: print this %%\n");
	printf("Original: %d \nFT version: %d\n\n", orig, ft);

	ft_printf("Subscenario: Only one %% + count\n");
	/*original -> warning: spurious trailing ‘%’ in format [-Wformat=] orig = printf("OR char: print this %");*/
	/*prints normally without % but count goes 30+ */
	//ft = ft_printf("FT char: print this %\n");
	printf("\nFT version: %d\n\n", ft);

	ft_printf("\n**********************\n     3 - str    \n**********************\n\n");
	ft_printf("Subscenario: 'sentence' str \n");
	ft = ft_printf("FT char: print this %s\n", "sentence");
	orig = printf("OR char: print this %s\n", "sentence");
	printf("\nOriginal: %d \nFT version: %d\n\n", orig, ft);

	ft_printf("Subscenario: 'empty' str \n");
	ft = ft_printf("FT char: print this %s\n", "");
	orig = printf("OR char: print this %s\n", "");
	printf("\nOriginal: %d \nFT version: %d\n\n", orig, ft);


	ft_printf("\n**********************\n    4 - nbr    \n**********************\n\n");
	ft_printf("Subscenario: -123 int \n");
	ft = ft_printf("FT char: print this %d\n", -123);
	orig = printf("OR char: print this %d\n", -123);
	printf("\nOriginal: %d \nFT version: %d\n\n", orig, ft);

	ft_printf("Subscenario: INT_MIN \n");
	ft = ft_printf("FT char: print this %d\n", INT_MIN);
	orig = printf("OR char: print this %d\n", INT_MIN);
	printf("\nOriginal: %d \nFT version: %d\n\n", orig, ft);

	ft_printf("Subscenario: INT_MAX \n");
	ft = ft_printf("FT char: print this %d\n", INT_MAX);
	orig = printf("OR char: print this %d\n", INT_MAX);
	printf("\nOriginal: %d \nFT version: %d\n\n", orig, ft);
	
	ft_printf("Subscenario: empty \n");
	//ft_printf("FT char: print this %d\n", " ");
	//orig = printf("OR char: print this %d\n" );
	//printf("FT version: %d\n\n", nft);


	ft_printf("**********************\n 5 - unsigned int \n**********************\n\n");
	ft_printf("Subscenario: unsigned int c or 99\n");
	orig = printf("OR char: print this %u\n", 'c');
	ft = ft_printf("FT char: print this %u\n", 'c');
	printf("Original: %d \nFT version: %u\n\n", orig, ft);

	unsigned int ui = 300;
	ft_printf("Subscenario: unsigned int 256 - over limit\n");
	orig = printf("OR char: print this %u\n", ui);
	ft = ft_printf("FT char: print this %u\n", ui);
	printf("Original: %d \nFT version: %u\n\n", orig, ft);

	ft_printf("\n**********************\n   6 - hexa    \n**********************\n\n");
	ft_printf("Subscenario: 123 heXa \n");
	ft = ft_printf("FT char: print this %X\n", 123);
	orig = printf("OR char: print this %X\n", 123);
	printf("\nOriginal: %d \nFT version: %d\n\n", orig, ft);

	ft_printf("Subscenario: 16010 hexa \n");
	ft = ft_printf("FT char: print this %x\n", 16010);
	orig = printf("OR char: print this %x\n", 16010);
	printf("\nOriginal: %d \nFT version: %d\n\n", orig, ft);

	ft_printf("\n**********************\n  7 - pointer  \n**********************\n\n");
	void *p = "abc";
	ft_printf("Subscenario: void *pointer variable \n");
	ft = ft_printf("FT char: print this %p\n", p);
	orig = printf("OR char: print this %p\n", p);
	printf("\nOriginal: %d \nFT version: %d\n\n", orig, ft);
}