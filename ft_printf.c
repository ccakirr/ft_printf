/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccakir <ccakir@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 17:48:00 by ccakir            #+#    #+#             */
/*   Updated: 2025/06/25 17:48:00 by ccakir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>
#include "libftprintf.h"

static void	ft_putnbru_fd(unsigned int n, int fd)
{
	unsigned long	nbr;
	char	c;

	nbr = n;
	if (nbr >= 10)
		ft_putnbr_fd (nbr / 10, fd);
	c = (nbr % 10) + '0';
	write (fd, &c, 1);
}

static void	formatter(char type, va_list args)
{
	if (type == 'c')
		ft_putchar_fd((char)va_arg(args, int), 1);
	if (type == 'd')
		ft_putnbr_fd(va_arg(args, int), 1);
	if (type == 's')
		ft_putstr_fd(va_arg(args, char *), 1);
	if (type == 'i')
		ft_putnbr_fd(va_arg(args, int), 1);
	if (type == 'u')
		ft_putnbru_fd(va_arg(args, unsigned int), 1);
	if (type == '%')
		ft_putchar_fd('%', 1);
}

int	ft_printf(const char *format, ...)
{
	int	i;
	va_list	args;

	i = 0;
	va_start(args, format);
	while(format[i])
	{
		if(format[i] == '%')
		{
			formatter(format[i + 1], args);
			i = i + 2;
			continue;
		}
		ft_putchar_fd(format[i], 1);
		i++;
	}
	va_end(args);
}
