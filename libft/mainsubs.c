#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "ft_split.c"
#include "ft_substr.c"
#include "ft_strlen.c"
#include "ft_strchr.c"
#include "get_next_line.c"
int main(void)
{

	int fd;
	char *c ;

	fd = open("ola.txt", O_RDONLY);

	c = get_next_line(fd);
	printf("%s\n", c);
	free(c);
	c = get_next_line(fd);
	printf("%s\n", c);
	free(c);
	c = get_next_line(fd);
	printf("%s\n", c);
	free(c);
	c = get_next_line(fd);
	printf("%s\n", c);
	free(c);

}



