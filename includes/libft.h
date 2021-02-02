/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiahechaichi <sofiahechaichi@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 15:42:43 by sohechai          #+#    #+#             */
/*   Updated: 2021/02/02 11:32:43 by sofiahechai      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef _LIBFT_H
# define _LIBFT_H
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>
# include <string.h>


/*
** libft
*/

int		ft_strcmp(char *s1, char *s2);
int		ft_strlen(const char *s);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isascii(int c);
int		ft_isalnum(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_atoi(const char *str);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memccpy(void *dest, const void *src, int c, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strchr(const char *s, int c);
char	*ft_strcat(char *dest, char *src);
char	*ft_strrchr(const char *s, int c);
char	*ft_strnstr(const char *s1, const char *s2, size_t len);
char	*ft_strdup(const char *src);
char	**ft_split(char const *s, char c);

/*
** ft_printf
*/

typedef struct		s_printf
{
	unsigned long	p;
	long			u;
	int				i;
	int				j;
	int				count;
	int				len;
	int				length_star;
	int				length_dot;
	int				length_field;
	int				d;
	int				x;
	char			c;
	char			*s;
	char			*strp;
	char			*itoap;
	char			*tmp;
	char			*stock;
	char			*strx;
	char			*itoanb;
}					t_printf;

void				ft_putnbr(long long n, t_printf *st);
void				ft_putnbrforzero(int n, t_printf *st);
void				ft_putnbrforu(int n, t_printf *st);
void				ft_fieldcompletep(t_printf *st);
void				ft_putchar(char c, t_printf *st);
void				ft_printsimpleflag
					(t_printf *st, va_list ap, const char *fmt);
void				ft_free_s(t_printf *st);
void				ft_stock_arg(const char *fmt, t_printf *st, va_list ap);
void				ft_fieldisnegp(t_printf *st);
void				ft_fielddotp2(t_printf *st);
void				ft_stock_diux(const char *fmt, t_printf *st, va_list ap);
void				ft_starnext(t_printf *st, const char *fmt);
void				ft_star(t_printf *st, const char *fmt, va_list ap);
void				ft_starpisneg(t_printf *st);
void				ft_putzeropisneg(t_printf *st);
void				ft_stardot(const char *fmt, t_printf *st, va_list ap);
void				ft_dot(const char *fmt, t_printf *st, va_list ap);
void				ft_number(const char *fmt, t_printf *st, va_list ap);
void				ft_putpercent(t_printf *st, const char *fmt);
void				ft_putxmaj(t_printf *st, const char *fmt, va_list ap);
void				ft_zero(const char *fmt, t_printf *st, va_list ap);
void				ft_putdot(t_printf *st, const char *fmt, va_list ap);
void				ft_dotpercent(t_printf *st, const char *fmt);
void				ft_dotx(t_printf *st, const char *fmt, va_list ap);
void				ft_dotu(t_printf *st, const char *fmt, va_list ap);
void				ft_dotd(t_printf *st, const char *fmt, va_list ap);
void				ft_dots(t_printf *st, const char *fmt, va_list ap);
void				ft_dotp(t_printf *st, const char *fmt, va_list ap);
void				ft_put(t_printf *st, const char *fmt, va_list ap);
void				ft_putstar(t_printf *st, const char *fmt, va_list ap);
void				ft_starpercent(t_printf *st, const char *fmt);
void				ft_starxmaj(t_printf *st, const char *fmt, va_list ap);
void				ft_starx(t_printf *st, const char *fmt, va_list ap);
void				ft_stari(t_printf *st, const char *fmt, va_list ap);
void				ft_staru(t_printf *st, const char *fmt, va_list ap);
void				ft_stard(t_printf *st, const char *fmt, va_list ap);
void				ft_starp(t_printf *st, const char *fmt, va_list ap);
void				ft_stars(t_printf *st, const char *fmt, va_list ap);
void				ft_starc(t_printf *st, const char *fmt, va_list ap);
void				ft_putfielddot(const char *fmt, t_printf *st, va_list ap);
void				ft_putzerodot(const char *fmt, t_printf *st, va_list ap);
void				ft_putzerodotd(t_printf *st, const char *fmt, va_list ap);
void				ft_putzerodotu(t_printf *st, const char *fmt, va_list ap);
void				ft_putzeroisnegu(t_printf *st);
void				ft_putzerodotu(t_printf *st, const char *fmt, va_list ap);
void				ft_putzeroisposx(t_printf *st);
void				ft_putzeroisnegx(t_printf *st);
void				ft_putzeroisposu(t_printf *st);
void				ft_putzerodotx(t_printf *st, const char *fmt, va_list ap);
void				ft_fieldisnegd(t_printf *st);
void				ft_fielddotx2(t_printf *st);
void				ft_fieldisposx(t_printf *st);
void				ft_fielddotpercent
					(t_printf *st, const char *fmt, va_list ap);
void				ft_fielddotx(t_printf *st, const char *fmt, va_list ap);
void				ft_fielddotu(t_printf *st, const char *fmt, va_list ap);
void				ft_fielddotd(t_printf *st, const char *fmt, va_list ap);
void				ft_fielddotc(t_printf *st, const char *fmt, va_list ap);
void				ft_fielddots(t_printf *st, const char *fmt, va_list ap);
void				ft_fielddotp(t_printf *st, const char *fmt, va_list ap);
void				ft_fieldisnegs(t_printf *st);
void				ft_fieldisposp(t_printf *st);
void				ft_putzero(const char *fmt, t_printf *st, va_list ap);
void				ft_putzerod(t_printf *st, const char *fmt, va_list ap);
void				ft_putzerou(t_printf *st, const char *fmt, va_list ap);
void				ft_putzeroi(t_printf *st, const char *fmt, va_list ap);
void				ft_putzerox(t_printf *st, const char *fmt, va_list ap);
void				ft_putzerop(t_printf *st, const char *fmt, va_list ap);
void				ft_putzeropercent(t_printf *st, const char *fmt);
void				ft_zerodot(const char *fmt, t_printf *st, va_list ap);
void				ft_flagpercent(t_printf *st, const char *fmt);
void				ft_flagc(t_printf *st, va_list ap, const char *fmt);
void				ft_flags(t_printf *st, va_list ap, const char *fmt);
void				ft_flagp(t_printf *st, va_list ap, const char *fmt);
void				ft_flagd(t_printf *st, va_list ap, const char *fmt);
void				ft_flagi(t_printf *st, va_list ap, const char *fmt);
void				ft_flagu(t_printf *st, va_list ap, const char *fmt);
void				ft_flagx(t_printf *st, va_list ap, const char *fmt);
void				ft_flagxmaj(t_printf *st, va_list ap, const char *fmt);
void				ft_putspaces(t_printf *st);
void				ft_fieldisposd(t_printf *st);
void				ft_fieldisnegx(t_printf *st);
void				ft_fieldisnegu(t_printf *st);
void				ft_minus(const char *fmt, t_printf *st, va_list ap);
void				ft_minusstar(const char *fmt, t_printf *st, va_list ap);
void				ft_minusstardot(const char *fmt, t_printf *st, va_list ap);
void				ft_minusfielddot(const char *fmt, t_printf *st, va_list ap);
void				ft_minusfield(t_printf *st, const char *fmt, va_list ap);
void				putzeros(t_printf *st);
unsigned long		ft_strlenp(const char *s);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_printf(const char *fmt, ...);
int					ft_isflag(const char *fmt, t_printf *st);
int					ft_isflagplus1(const char *fmt, t_printf *st);
int					ft_isnbwithoutzero(const char *fmt, t_printf *st);
int					ft_strlen_int(long nb);
int					ft_strlen_int_u(long n);
int					ft_atoiwithst(const char *str, t_printf *st);
int					ft_isnb(const char *fmt, t_printf *st);
char				*ft_itoabase(long long n, char *base);
char				*ft_itoabasep(unsigned long n, char *base);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_putstr(char *str, t_printf *st);
char				*ft_putlenstr(char *str, int len, t_printf *st);
char				*ft_itoa(int n);
char				*ft_strdup(const char *src);

#endif
