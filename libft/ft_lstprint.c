#include "libft.h"

void ft_lstprint(t_node *head) {
    t_node *current_node;

    current_node = head;
   	while ( current_node != NULL) {
        ft_putnbr_fd(current_node->num, 1);
        write(1, " ", 1);
        current_node = current_node->next;
    }
}