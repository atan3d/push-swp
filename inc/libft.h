/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:     :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh <najeuneh@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 15:51:04 by najeuneh          #+#    #+#             */
/*   Updated: 2024/04/04 18:34:07 by najeuneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include "push_swap.h"
#include "ft_printf.h"

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

int			ft_toupper(int c);
int			ft_tolower(int c);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strrchr(const char *s, int c);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
size_t		ft_strlen(const char *s);
size_t		ft_strlcpy(char *restrict dst, \
			const char *restrict src, size_t dstsize);
size_t		ft_strlcat(char *restrict dst, \
			const char *restrict src, size_t dstsize);
char		*ft_strchr(const char *s, int c);
void		*ft_memset(void *b, int c, size_t len);
void		*ft_memmove(void *dst, const void *src, size_t len);
void		*ft_memcpy(void *restrict dst, const void *restrict src, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_isprint(int c);
int			ft_isdigit(int c);
int			ft_isascii(int c);
int			ft_isalpha(int c);
int			ft_isalnum(int c);
void		*ft_calloc(size_t count, size_t size);
void		ft_bzero(void *s, size_t n);
long long	ft_atoi(const char *str);
char		*ft_strdup(const char *s1);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_itoa(int n);
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char const *s, char c);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
//LISTE CHAINER
void		ft_lstadd_front(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void*));
void		ft_lstclear(t_list **lst, void (*del)(void*));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list		*ft_lstlast(t_list *lst);
t_list		*ft_lstnew(void *content);
//DOUBLE LISTE CHAINER
t_node		*dl_lstnew(long long nbr);
void		dl_lstadd_front(t_stack *a, long long nbr);
void		dl_lstdelfront(t_stack *a);
void		dl_lstdelback(t_stack *a);
void		dl_lstadd_back(t_stack *a, long long nbr);
int			dl_lstsize(t_stack *stack);