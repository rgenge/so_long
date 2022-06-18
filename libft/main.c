#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <bsd/string.h>

#include "ft_strncmp.c"
#include "ft_strlen.c"
#include "ft_strchr.c"
#include "ft_strrchr.c"
#include "ft_strdup.c"
#include "ft_strlcpy.c"
#include "ft_strlcat.c"
#include "ft_strnstr.c"
#include "ft_memcmp.c"
#include "ft_memset.c"
#include "ft_memcpy.c"
#include "ft_memmove.c"
#include "ft_memchr.c"
#include "ft_bzero.c"
#include "ft_calloc.c"
#include "ft_atoi.c"
#include "ft_substr.c"
#include "ft_strjoin.c"
#include "ft_strmapi.c"
#include "ft_striteri.c"
#include "ft_strtrim.c"
#include "ft_itoa.c"
#include "ft_putnbr_fd.c"
#include "ft_isalnum.c"
#include "ft_split.c"
#include "get_next_line.c"

int main()
{
	printf ("ft_strncmp \n" );
	printf ("ft %d | ", ft_strncmp("test\200", "test\0", 6));
	printf ("noft %d \n" , strncmp("test\200", "test\0", 6));

	printf ("ft_strlen \n" );
	printf ("%ld \n", ft_strlen("123456789"));

	printf ("ft_strchr \n" );
	printf ("ft %s | ", ft_strchr ("tripouille", 0));
	printf("noft %s\n", strchr("tripouille",0));

	printf ("ft_strrchr \n" );
	printf ("ft %s | ", ft_strrchr ("a5aaa5aa", 0));
	printf("noft %s\n", strrchr("a5aaa5aa", 0));

	printf ("ft_strdup \n" );
	printf ("ft %s | ", ft_strdup("\0"));
	printf ("noft %s \n" , strdup("\0"));

//	char string[] = "coucou";
    char buffer[10] ="AAAAAAAAAA";
//	char stringx[] = "coucou";
    char bufferx[10] = "AAAAAAAAAA";
	printf ("ft_strlcpy \n" );
	printf ("ft %ld buffer: %s | ", ft_strlcpy(buffer, "", 42) ,buffer );
	printf ("noft %ld  bufferx: %s \n" , strlcpy(bufferx,"" , 42), bufferx);

	char dest[30]; memset(dest, 0, 30);
	char * src = (char *)"AAAAAAAAA";
	dest[0] = 'B';
	char destx[30]; memset(destx, 0, 30);
	char * srcx = (char *)"AAAAAAAAA";
	destx[0] = 'B';
	printf ("ft_strlcat \n" );
//	ft_strlcat(dest, src, 0);
//	strlcat(destx, srcx , 0);
	printf ("ft  dest:%ld %s | ",ft_strlcat(dest, src, 15), dest );
	printf ("noft   destx:%ld %s \n" ,strlcat(destx, srcx , 15),  destx);

	char *src1 = "bc";
    char *dest1 = "aaabcabcd";
	char *src2 = "bc";
    char *dest2 = "aaabcabcd";
	printf ("ft_strnstr \n" );
//	ft_strnstr(dest1, src1, 10);
//	strnstr(dest2, src2 , 10);
	printf ("ft  dest1: %s %s %s | ", dest1 , ft_strnstr(dest1, src1, 10) ,dest1 );
	printf ("noft   dest2: %s %s %s \n" ,  dest2 ,strnstr(dest2, src2 , 10)  ,dest2);

	printf ("ft_memcmp \n" );
	printf ("ft %d | ", ft_memcmp("ta9 ", "ta5 ", 10));
	printf ("noft %d \n" , memcmp("ta9 ", "ta5 " , 10));

	char mset[] = "aaaa";
	printf ("ft_memset \n" );
	puts(ft_memset(mset, 'b', 2));
	puts(memset(mset, 'b', 2));

	char mcpy[10] ;
	char mcpyd[] ="olatr";
	printf ("ft_memcpy \n" );
	puts(ft_memcpy(mcpy, mcpyd, 3));
	puts(memcpy(mcpy, mcpyd, 3));

	char mmove[20] ;
	char mmoved[] ="movera";
	printf ("ft_memmove \n" );
	puts(ft_memmove(mmove, mmoved, 2));
	printf ("noft_memmove \n" );
	puts(memmove(mmove, mmoved, 2));

	char sResult[] = {67, 67, 68, 68, 69, 0, 45};
	char sResult2[] = {67, 67, 68, 68, 69, 0, 45};
	printf ("ft %s | ", (char*)ft_memmove(sResult + 1, sResult, 2));
	printf ("noft %s \n" , (char*)memmove(sResult2 + 1, sResult2, 2));

	char mchr[] = "ola meu tio" ;
	char mchrd[] ="m";
	printf ("ft_memchr \n" );
	puts(ft_memchr(mchr, *mchrd, 8));
	puts(memchr(mchr, *mchrd, 8));

	char mbzero[50] = "this is a test";
	bzero(mbzero,3);
	puts(mbzero);
	char mbzero2[50] = "this is a test";
	ft_bzero(mbzero2, 3);
	puts(mbzero2);

	printf ("ft_calloc \n" );
	char *c = ft_calloc(5, 5);
	printf ("ft %s | ",c);
	char *d = calloc(5, 5);
	printf("noft %s\n", d);

	printf ("ft_atoi \n" );
    printf("ft %d ", ft_atoi(""));
    printf(" %d\n", ft_atoi("\e475"));
    printf("no ft %d", atoi(""));
    printf(" %d\n", atoi("\e475"));

	char sub[] = "tripo";
	printf ("ft_substr \n" );
	printf("ft %s\n", ft_substr(sub, 100,1));

	char join[] = "tripo";
	char join2[] = "42";
	printf ("ft_strjoin \n" );
	printf("ft %s\n", ft_strjoin(join, join2));


	char my_func(unsigned int i, char mapi)
	{
	printf("My inner function: index = %d and %c\n", i, mapi);
	return mapi - 32;
	}
	char mapi[10] = "hey";
	printf("The result is %s\n", mapi);
	char *result = ft_strmapi(mapi, my_func);
	printf("The result is %s\n", result);

	void my_func2(unsigned int i,char *stri)
	{
		i=0;
		stri[i] = stri[i] - 32;
		i++;
	}
	char stri[10] = "hey";
	printf("The result is %s\n", stri);
	ft_striteri(stri, my_func2);
	printf("The result is %s\n", stri);


	char *s1 ="123 acb";
//	char *sx = "Hello \t  Please\n Trim me !";
	printf("%s\n", ft_strtrim(s1, "acb"));

	int itoa = -1005 ;
	printf("The result is %s\n", ft_itoa(itoa));

	int nbr = -2147483648 ;
	ft_putnbr_fd(nbr, 1);

	int aln = '\n' ;
	ft_isalnum(aln);
	printf("isalnum %d\n", ft_isalnum(aln));

  //  char test[] = "\njrS58VHQ    \n      p70fL       Kx2sRP0So3E4rC9  \n nebpv3J5ousO84Pa1HjUQOImUhjwZpGn    \n \n   X28iT7Ap9   DIYAF9ZSpKcs0Rcv\n uzO\n        \nZ7zjEeonALOKQF5xq \n   \nQxp0b1ufFKGJ \n2n8R9zUvZEtOwmqf\n    ";
	char test[] = "Tripouille ";

	char **arr = ft_split(test ,' ');
	int i = 0;
	while (arr[i] != 0)
	{
	    printf("[%s]\n", arr[i]);
	    ++i;
	}



	return (0);
}
