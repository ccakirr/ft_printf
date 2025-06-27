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

#include "libftprintf.h"

static void	ft_putnbru_fd(int n, int fd)
{
	unsigned long	nbr;
	char	c;

	nbr = n;
	if (nbr >= 10)
		ft_putnbr_fd (nbr / 10, fd);
	c = (nbr % 10) + '0';
	write (fd, &c, 1);
}

static char	*putptr(unsigned int	ptr)
{
	char			*res;
	unsigned int	tmp;
	int				size;
	char			*chared;
	int				i;
	int				j;

	tmp = ptr;
	size = 0;
	i = 0;
	j = 2;
	while(tmp)
	{
		tmp = tmp / 10;
		size++;
	}
	res = malloc(sizeof(char) * (size + 2));
	res[0] = '0';
	res[1] = 'x';
	chared = lower_hexa_printer(ptr);
	while(chared[++i])
	{
		res[j] = chared[i];
		j++;
	}
	return (res);
}

static void	formatter(char type, va_list args)
{
	if (type == 'c')
		ft_putchar_fd((char)va_arg(args, int), 1);
	else if (type == 'd')
		ft_putnbr_fd(va_arg(args, int), 1);
	else if (type == 's')
		ft_putstr_fd(va_arg(args, char *), 1);
	else if (type == 'i')
		ft_putnbr_fd(va_arg(args, int), 1);
	else if (type == 'u')
		ft_putnbru_fd(va_arg(args, unsigned int), 1);
	else if (type == '%')
		ft_putchar_fd('%', 1);
	else if (type == 'x')
		ft_putstr_fd(lower_hexa_printer(va_arg(args, unsigned int)), 1);
	else if (type == 'X')
		ft_putstr_fd(higher_hexa_printer(va_arg(args, unsigned int)), 1);
	else if (type == 'p')
		ft_putstr_fd(lower_hexa_printer(va_arg(args, void *)), 1);
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
