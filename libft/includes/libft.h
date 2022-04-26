/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:49:51 by atenhune          #+#    #+#             */
/*   Updated: 2022/04/25 14:50:34 by atenhune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}	t_list;

typedef struct s_flags
{
	int		minus;
	int		plus;
	int		space;
	int		hashtag;
	int		zero;
	int		width;
	int		precision;
	int		dot;
	int		index_jump;
	int		negative;
	int		original_len;
	int		i;
	char	length[2];
	char	*str;
	char	spec;

}	t_flags;

char	*ft_strncpy(char *dst, const char *src, size_t len);
size_t	ft_strlen(const char *s);
int		ft_atoi(const char *str);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strdup(const char *s);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strcat(char *s1, const char *s2);
char	*ft_strncat(char *s1, const char*s2, size_t n);
size_t	ft_strlcat( char *dst, const char *src, size_t dstsize);
int		ft_isdigit(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isalnum(int c);
char	*ft_strstr(const char *haystack, const char *needle);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		ft_isprint(int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memccpy(void *dst, const void *src, int c, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	ft_putchar(char c);
void	ft_putstr(const char *s);
void	ft_putendl(const char *s);
void	ft_putnbr(int n);
char	*ft_itoa(int n);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(const char *s, int fd);
void	ft_putendl_fd(const char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strtrim(const char *s);
int		ft_strequ(const char *s1, const char *s2);
int		ft_strnequ(const char *s1, const char *s2, size_t n);
void	*ft_memalloc(size_t size);
char	*ft_strnew(size_t size);
void	ft_strclr(char *s);
void	ft_memdel(void **ap);
void	ft_strdel(char **as);
void	ft_striter(char *s, void (*f)(char *));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
char	*ft_strmap(const char *s, char (*f)(char));
char	*ft_strmapi(const char *s, char (*f)(unsigned int, char));
char	*ft_strsub(const char *s, unsigned int start, size_t len);
char	**ft_strsplit(const char *s, char c);
t_list	*ft_lstnew(const void *content, size_t content_size);
void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void	ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void	ft_lstadd(t_list **alst, t_list *new);
void	ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

char	*better_ft_itoa(unsigned long long int n, int space);
char	*better_ft_strnew(size_t size);
void	precision_catcher(const char *s, t_flags *flags, va_list args);
void	flag_catcher(const char *s, t_flags *flags);
void	length_helper(const char *s, t_flags *flags);
void	length_catcher(const char *s, t_flags *flags);
long long	signed_hh_converter(long long nbr, t_flags *flags);
unsigned long long	unsigned_hh_converter(unsigned long long nbr,
t_flags *flags);
char	*zero_flag_treatment(char *s, t_flags *flags);
char	*plus_flag_treatment(char *s, t_flags *flags);
char	*width_treatment(char *s, t_flags *flags);
char	*precision_treatment(char *s, t_flags *flags);
char	*minus_flag_treatment(char *s, t_flags *flags);
char	*space_flag_treatment(char *s, t_flags *flags);
char	*hashtag_flag_treatment(char *s, t_flags *flags);
char	*dot_for_strings(char *s, t_flags *flags);
char	*dot_for_numbers(char *s, t_flags *flags);
char	*dot_flag_treatment(char *s, t_flags *flags);
int		strlen_minus_space(char *s);
char	*if_negative(char *s, t_flags *flags);
void	flag_modifier(t_flags *flags);
char	*flag_trafficker(char *s, t_flags *flags);
int		flag_switcher(t_flags *flags);
int		float_width(t_flags *flags, int len);
int		float_rounder(long double nbr);
int		float_zero_precision(long double nbr, t_flags *flags);
long double	round_amount(t_flags *flags);
long double	is_there_need_to_round(t_flags *flags,
long double nbr, long double rounding);
int		float_printer(long double nbr, t_flags flags);
int		format_reader(const char *s, t_flags *flags, va_list args, int ret);
int		specifier_sorter(va_list args, char spec, t_flags flags);
int		index_counter(const char *s);
int		ft_printf(const char *str, ...);
void	print_putnbr(unsigned long long n);
int		max_space(t_flags *flags);
int		ull_len(unsigned long long nbr);
char	*pointer_addon(char *s, t_flags *flags, int i);
void	octal_creator(unsigned long long int nbr, t_flags *flags);
void	hex_creator(unsigned long long nbr, const char spec, t_flags *flags);
int		print_hex(unsigned long long nbr, const char spec, t_flags flags);
int		print_pointer(unsigned long long pointer, t_flags flags);
int		print_octal(unsigned long long int nbr, t_flags flags);
int		print_chars(int c, t_flags flags);
int		print_str(char *str, t_flags flags);
int		print_percent(char *str, t_flags flags);
int		print_signed_nbr(signed long long nbr, t_flags flags);
int		print_unsigned_nbr(unsigned long long nbr, t_flags flags);
int		specifiers(va_list args, const char spec, t_flags flags);
int		l_specifiers(va_list args, const char spec, t_flags flags);
int		ll_specifiers(va_list args, const char spec, t_flags flags);
void	wildcard_for_precision(t_flags *flags, va_list args);
void	wildcard_for_width(t_flags *flags, va_list args);

#endif
