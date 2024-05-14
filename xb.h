/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xb.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abderrahim <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 15:25:18 by abderrahim        #+#    #+#             */
/*   Updated: 2024/05/14 09:49:40 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef XB_H
# define XB_H

# include <stdarg.h>
# include <stddef.h>

typedef struct s_stack_node
{
	int					value;
	struct s_stack_node	*next;
}	t_stack_node;

typedef struct s_stack
{
	t_stack_node	*head;
	int				length;
}	t_stack;

typedef void			(*t_stack_lambda_iter)(int, t_stack_node*);
typedef t_stack_node	*(*t_stack_lambda_map)(int, t_stack_node*);

void			stack_foreach(t_stack *stack, t_stack_lambda_iter lambda);
t_stack			*stack_map(t_stack *src, t_stack_lambda_map lambda);
t_stack			*stack_new_empty(void);
t_stack			*stack_new_from_array(int *list, int len);
t_stack_node	**stack_getref(t_stack *stack, int index);
t_stack_node	*stack_get(t_stack *stack, int index);
t_stack_node	*stack_get_last(t_stack *stack);
t_stack_node	*stack_pop_head(t_stack *stack);
t_stack_node	*stack_pop_tail(t_stack *stack);
void			stack_push_head(t_stack *stack, t_stack_node *node);
void			stack_push_tail(t_stack *stack, t_stack_node *node);
void			stack_reverse(t_stack *stack);
void			stack_free(t_stack *stack);
void			stack_print(t_stack *stack, char *label);

t_stack_node	*stack_node_new(int value);
int				stack_node_length(t_stack_node	*node);
void			stack_node_swap(t_stack_node **a, t_stack_node **b);

int				xb_strlen(const char *s);
int				xb_arrlen(void **array);

int				xb_strcmp(const char *lhs, const char *rhs);
int				xb_strncmp(const char *lhs, const char *rhs);

char			*xb_strcat(char	*dst, const char *src);
char			*xb_strncat(char *dst, const char *src, int count);

char			*xb_strcpy(char *dst, const char *src);
char			*xb_strncpy(char *dst, const char *src, int src_len);

int				xb_strpos(const char *hay, char needle);
int				xb_strnpos(const char *hay, char needle, int count);

int				xb_strhas(const char *hay, char needle);
int				xb_strnhas(const char *hay, char needle, int count);

char			*xb_strdup(const char *src);
char			*xb_strjoin(const char *lhs, const char *rhs);
char			*xb_strslice(const char *src, int offset, int length);

char			**xb_strsplit(const char *src, char c);

char			*xb_sprintf(const char *format, ...);
char			*xb_vsprintf(const char *format, va_list args);

void			xb_free(int count, ...);
void			xb_free_list(int count, void **list);
void			*xb_bzero(void *area, int count);
void			*xb_memset(void *area, char byte, int count);

/* TODOS:
	char			*xb_readfd(int fd);
	char			*xb_readline(int fd);
	char			**xb_split_char(const char *s, char delimiter);
	char			**xb_split_str(const char *s, const char *delimiter);
*/
#endif
