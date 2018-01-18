/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecott <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 09:38:39 by alecott           #+#    #+#             */
/*   Updated: 2018/01/17 14:42:55 by alecott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <wchar.h>
# include <stddef.h>

typedef struct		s_list
{
	char			*content;
	char			*flags;
	char			*width;
	char			*precision;
	char			*length;
	char			spec;
}					t_list;

int					ft_printf(const char *format, ...);
void				ft_putchar(char c);
void				ft_putnbr(int n);
void				ft_putstr(char const *s);
int					ft_putwstr(wchar_t const *s, int i);
int					ft_strlen(const char *str);
int					ft_atoi(const char *str);
void				*ft_memalloc(size_t size);
void				ft_bzero(void *s, size_t n);
void				*ft_memset(void *s, int c, size_t len);
char				*ft_uitoa_base(uintmax_t nbr, int base);
char				*ft_llitoa_base(long long nbr, int base);
char				*ft_strcapitalize(char *str);
int					ft_conv_char(t_list *l, va_list ap, int i);
int					ft_conv_string(t_list *l, va_list ap, int i);
int					ft_conv_int(t_list *l, va_list ap, int i);
int					ft_conv_octal(t_list *l, va_list ap, int i);
int					ft_newblock(const char *format, t_list *l,
		va_list ap, int i);
int					ft_isspec(t_list *l, va_list ap);
t_list				*ft_lstalloc(t_list *l);
char				*ft_strjoin(const char *s1, const char *s2);
int					ft_working(t_list *l, va_list ap, int i);
int					ft_strequ(const char *s1, const char *s2);
int					ft_strchr(const char *s, char c);
char				*ft_strupper(char *str);
int					ft_putwchar(wchar_t wc, int i);
char				*ft_width(char *str, t_list *l, char *flag);
char				*ft_precision(char *str, t_list *l);
void				ft_memdel(void **ap);
void				ft_strdel(char **as);
char				*ft_strdup(const char *s);
void				*ft_memalloc(size_t size);

#endif
