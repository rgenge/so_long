#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <bsd/string.h>
#include "ft_lstsize.c"
#include "ft_lstnew.c"
#include "ft_lstlast.c"
#include "ft_lstadd_front.c"

int main(void)
{

	char	new[] = "lorem ipsum dolor sit";
//	char	new2[] = "this is my name";

	t_list	*elem;

	elem = ft_lstnew((void *)new);
	printf("\nname : %p\ncontent : %s\n", elem->content, (char *)elem->content);

	char	last[] = "test";

	t_list	*elem1;
	t_list	*elem2;
	t_list	*elem3;
	t_list	*elem4;
	t_list	*elem5;
	t_list	*elem6;
	t_list	*elem7;
	t_list	*ret;

	if(!(elem1 = malloc(sizeof(t_list))))
		return (0);
	if(!(elem2 = malloc(sizeof(t_list))))
		return (0);
	if(!(elem3 = malloc(sizeof(t_list))))
		return (0);
	if(!(elem4 = malloc(sizeof(t_list))))
		return (0);
	if(!(elem5 = malloc(sizeof(t_list))))
		return (0);
	if(!(elem6 = malloc(sizeof(t_list))))
		return (0);
	if(!(elem7 = malloc(sizeof(t_list))))
		return (0);

	elem1->next = elem2;
	elem2->next = elem3;
	elem3->next = elem4;
	elem4->next = elem5;
	elem5->next = elem6;
	elem6->next = NULL;
	ft_lstadd_front(&elem7, elem6);

	elem6->content = (void *)last;
	ret = ft_lstlast(elem1);
	printf("\n last %s\n", (char *)ret->content);
	printf("\n%d\n", ft_lstsize(elem1));


	return (0);
}






































































