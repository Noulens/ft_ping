/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waxxy <waxxy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 16:05:08 by tnoulens          #+#    #+#             */
/*   Updated: 2022/12/21 14:35:11 by waxxy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define DECIMAL "0123456789"
# define HEX "0123456789abcdef"
# define BINARY "01"
# define OCT "01234567"
# define TRUE 1
# define FALSE 0

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <fcntl.h>
# include <stdio.h>
# include <limits.h>
# include <stdint.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

/* Part 1 */
int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
size_t		ft_strlen(const char *s);
void		*ft_memset(void *s, int c, size_t n);
void		*ft_bzero(void *s, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t n);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
int			ft_toupper(int c);
int			ft_tolower(int c);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
char		*ft_strnstr(const char *big, const char *little, size_t len);
int			ft_atoi(const char *nptr);
void		*ft_calloc(size_t nmemb, size_t size);
char		*ft_strdup(const char *s);
/* Part 2 */
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char const *s, char c);
char		*ft_itoa(int n);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
/* Bonus */
t_list		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void*));
void		ft_lstclear(t_list *lst);
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
/* ft_printf */
int			ft_c(int c);
int			ft_s(char *p);
int			ft_p(void *p);
int			ft_di(int nbr);
int			ft_xupx(unsigned int nbr, char c);
char		*ft_uitoa(unsigned int nbr);
int			ft_printf(const char *format, ...);
int			ft_fc(int fd, int c);
int			ft_fs(int fd, char *p);
int			ft_fp(int fd, void *p);
int			ft_fdi(int fd, int nbr);
int			ft_fxupx(int fd, unsigned int nbr, char c);
int			ft_fprintf(int fd, const char *format, ...);
/* get_next_line */
char		*get_next_line(int fd);
size_t		ft_strlenb(const char *s);
char		*ft_strchrb(const char *s, int c);
void		*ft_callocb(size_t nmemb, size_t size);
void		ft_cpy(char *suf, char *p);
/* Other */
long		ft_atol(const char *nptr);
long long	ft_capped_atoll(const char *nptr, int *status);
int			ft_atoi_base(const char *str, int base);
void		ft_free_split(char **tofree);
size_t		ft_ptrlen(const char **ptr);
int			ft_isspace(char c);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_cmpchr(const char *s1, const char *s2, char c);
char		*ft_strjoinsep(char const *s1, char const *s2, char *sep);
float		ft_atof(const char *str);
double		ft_atod(const char *str);
void		ft_putfloat_fd(float x, int precision, int fd);
void        reverseEndianness(void *data, size_t size);
int         ft_ld(int nbr);
char        *ft_ltoa(long nbr);
void        ft_lstsort(t_list **begin_list, int (*cmp)());

#endif