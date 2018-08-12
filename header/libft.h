/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetruse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 09:18:45 by mpetruse          #+#    #+#             */
/*   Updated: 2018/08/06 11:51:53 by mpetruse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include "ft_printf.h"
# define FALSE 0
# define TRUE 1
# define BUFF_SIZE 9999
# define FDS 65535
# define COLOR(s,n)			ft_putstr(s), (format += n)
# define PF_RED				"\033[31m"
# define PF_GREEN			"\033[32m\033[1m"
# define PF_YELLOW			"\033[33m\033[1m"
# define PF_BLUE			"\033[34m\033[1m"
# define PF_PURPLE			"\033[35m\033[1m"
# define PF_CYAN			"\033[36m\033[1m"
# define PF_EOC				"\033[37m\033[0m"
# define MAX(a, b)			b & ((a - b) >> 31) | a & (~(a - b) >> 31)
# define MIN(a, b)			a & ((a - b) >> 31) | b & (~(a - b) >> 31)
# define ABS(a)				(a < 0) ? -a : a

typedef int			t_bool;

void				*ft_memset(void *dst, int data, size_t len);
void				ft_bzero(void *dst, size_t len);
void				*ft_memcpy(void *dst, const void *src, size_t len);
void				*ft_memccpy(void *dst, const void *src, int c, size_t len);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *src, int c, size_t len);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *s1);
size_t				ft_nstrlen(const char *s1, size_t maxlen);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t len);
size_t				ft_strlcat(char *dst, const char *src, size_t len);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *s1, const char *s2);
char				*ft_strnstr(const char *s1, const char *s2, size_t len);
void				ft_strrev(char *s);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t len);
int					ft_atoi(const char *str);
int					ft_isalpha(int chr);
int					ft_isdigit(int chr);
int					ft_isalnum(int chr);
int					ft_isascii(int chr);
int					ft_isprint(int chr);
int					ft_toupper(int chr);
int					ft_tolower(int chr);
size_t				ft_min(size_t a, size_t b);
size_t				ft_max(size_t a, size_t b);
void				ft_swap(int *a, int *b);
void				ft_count_digits(char a);
void				ft_countdown(char a);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *s));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t len);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_multistrjoin(int c, ...);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				**ft_strsplitwith(char *s, char *seps, size_t *count);
int					ft_strprefix(const char *str, const char *prefix);
int					ft_strsuffix(const char *str, const char *suffix);
char				*ft_itoa(int n);
char				*ft_utoa(unsigned int n, char const *base);
void				ft_putchar(char c);
void				ft_putnchar(int len, char c);
void				ft_putwchar(wchar_t c);
void				ft_putstr(char const *s);
void				ft_putnstr(char const *s, size_t strlen);
void				ft_putwstr(wchar_t const *s);
void				ft_putnwstr(wchar_t const *s, size_t strlen);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putnbrbase(uintmax_t n, char *base);
void				ft_putchar_fd(char c, int fd);
void				ft_putwchar_fd(wchar_t c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putnstr_fd(char const *s, size_t strlen, int fd);
void				ft_putstr_free(char const *s);
void				ft_putwstr_fd(wchar_t const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void*, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstlink(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_lstrev(t_list **alst);
size_t				ft_lstcount(t_list *lst);
t_list          	*ft_lstswap(t_list *lst1, t_list *lst2);
char				*ft_itoa_base_for_uint(unsigned long long value,
					int base, char c);
char				*ft_itoaf(uintmax_t n);
char				*ft_get_binary(unsigned char octet);
int					ft_wcharlen(wchar_t wc);

int					get_next_line(const int fd, char **line);

#endif
