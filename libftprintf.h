/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccakir <ccakir@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 17:28:08 by ccakir            #+#    #+#             */
/*   Updated: 2025/06/25 17:28:08 by ccakir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdarg.h>
# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>

void	ft_putstr_fd(char *str, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(unsigned char c, int fd);
int		ft_printf(const char *format, ...);
char	*lower_hexa_printer(unsigned int n);
char	*higher_hexa_printer(int n);
#endif
