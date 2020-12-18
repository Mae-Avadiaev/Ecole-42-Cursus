/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 19:36:05 by mclown            #+#    #+#             */
/*   Updated: 2020/12/17 19:44:50 by mclown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "libft/libft.h"

struct	s_specifier {
	int		width;
	int		prec;
	char	filler;
	int		l_or_r;
	int		total;
};

# define ERROR -1
# define INT_MIN -2147483647 - 1

int		ft_printf(const char *string, ...);
int		mod_ft_putchar_fd(char c, int fd);
int		mod_ft_putnbr_fd(int n, int fd);
int		mod_ft_putstr_fd(char *s, int fd);
int		mod_ft_putnbr_hex_low_fd(unsigned long int n, int fd);
int		mod_ft_putnbr_hex_up_fd(unsigned long int n, int fd);
int		mod_ft_putptr_fd(void *ptr, int fd);
char	*ft_itoa_uns(unsigned int n);

void	ft_put_d(int n, struct s_specifier *sp);
void	ft_put_s(char *s, struct s_specifier *sp);
void	ft_put_c(char c, struct s_specifier *sp);
void	ft_put_u(unsigned int n, struct s_specifier *sp);
void	ft_put_x(unsigned int n, struct s_specifier *sp);
void	ft_put_x_up(unsigned int n, struct s_specifier *sp);
void	ft_put_p(void *ptr, struct s_specifier *sp);

int		parse_sp(const char *string, struct s_specifier *sp, va_list argptr);

int		count_symbols_hex(unsigned long int n);

#endif
