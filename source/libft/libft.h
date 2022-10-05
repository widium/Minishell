/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:51:09 by ebennace          #+#    #+#             */
/*   Updated: 2022/10/05 08:44:11 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdarg.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;

}t_list;

t_list			*ft_lstnew(void *content);
int				ft_lstsize(t_list *lst);
void			ft_lstadd_front(t_list **alst, t_list *new);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **alst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));

int				ft_isalpha(int i);
int				ft_isdigit(int n);
int				ft_isalnum(int a);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int ch);
int				ft_tolower(int ch);
int				ft_memcmp( const void *pointer1, const void *pointer2,
					size_t size );
int				ft_strncmp( const char *first, const char *second, size_t n);
int				same_str(char *first, char *second, int size);
int				same_str_index(char *first, char *second, int size, int index);
int				index_diff(char *first, char *second, int size);
int				ft_atoi( const char *str);
long long int	ft_atol(const char *str);

char			*ft_strchr(const char *str, int c);
char			*ft_strrchr(const char *str, int find);
char			*ft_strnstr(const char *str, const char *find, size_t len);
char			*ft_strdup( const char *source );
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strjoin_free_first(char *s1, char *s2);
char			*ft_strjoin_free_second(char *s1, char *s2);
char			*ft_strjoin_free_all(char *s1, char *s2);
char			*ft_strjoin_char(char *s1, char *s2, char c);
char			**ft_arrayjoin_str(char **array, char *str, int pos);
void			copy_dimensions(char **array, char **new_array, int y, int *i);
void			copy_str_in_array(char **new_array, int index, char *str);
char			**str_to_array(char *str);
char			**ft_arrayremove_str(char **array, int pos);
char			*ft_substr(char *s, int start, int len);
char			*ft_itoa(int n);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char const *s, char c);

void			ft_putendl_fd(char *s, int fd);
void			*ft_memset(void *str, int c, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
void			*ft_memcpy(void *destination, const void *source, size_t size );
void			ft_bzero(void *s, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_calloc(size_t elementCount, size_t elementSize );
void			ft_putchar_fd(char c, int fd);
void			count_putchar_fd(char c, int *count, int fd);
void			ft_putstr_fd(char *str, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_striteri(char *s, void (*f)(unsigned int, char*));

size_t			ft_strlcat(char *dest, const char *src, size_t size);
int				ft_strlen(const char *str);
int				len_array(char **array);
size_t			ft_strlcpy(char *dest, const char *src, size_t n);
char			*malloc_strcpy(char *ori);
char			*malloc_strcpy_index(char *ori, int len);
char			*malloc_substrcpy(char *origin, int start, int end);
char			*malloc_strcpy_after_index(char *ori, int index);
char			**malloc_strcpy_array(char **ori);
size_t			col_count(char **str);

char			*get_next_line(int fd);
char			*ft_separation(char **statik, int retour);
int				index_newline(char *buf);
void			ft_append(char **statik, char *buf, int retour);

int				ft_putchar(int c);
int				ft_putstr(char *str);
int				ft_putnbr(int n);
int				ft_putunbr(unsigned int nb);
int				ft_puthexa_max(unsigned int nb);
int				ft_puthexa_min(unsigned int nb);
int				ft_puthexa_long(unsigned long nb);
int				ft_check_format(const char *str, va_list liste, int i);
int				ft_printf(const char *str, ...);
int				ft_printf_fd(int fd, const char *str, ...);
int				ft_print(unsigned long nb, char *dest, char *alphabet, int i);

void			free_array(char **array);

#endif
