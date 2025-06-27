/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccakir <ccakir@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 15:37:59 by ccakir            #+#    #+#             */
/*   Updated: 2025/06/05 15:37:59 by ccakir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putchar_fd(unsigned char c, int fd)
{
	write (fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	long	nbr;
	char	c;

	nbr = n;
	if (n < 0)
	{
		write (fd, "-", 1);
		nbr = nbr * -1;
	}
	if (nbr >= 10)
		ft_putnbr_fd (nbr / 10, fd);
	c = (nbr % 10) + '0';
	write (fd, &c, 1);
}

void	ft_putstr_fd(char *str, int fd)
{
	int	i;

	i = 0;
	while (str[i])
	{

		write (fd, &str[i], 1);
		i++;
	}
}
char	*lower_hexa_printer(unsigned int n)
{
	char		*res;
	char		*hex;
	int			len;
	unsigned int tmp;

	tmp = n;
	len = 0;
	hex = "0123456789abcdef";
	while (tmp)
	{
		tmp /= 16;
		len++;
	}
	res = malloc(len + 1);
	if (!res)
		return (NULL);
	res[len] = '\0';
	while (n)
	{
		res[--len] = hex[n % 16];
		n /= 16;
	}
	return (res);
}

char	*higher_hexa_printer(int n)
{
	char		*res;
	char		*hex;
	int			len;
	unsigned int tmp;

	tmp = n;
	hex = "0123456789ABCDEF";
	len = 0;
	while (tmp)
	{
		tmp /= 16;
		len++;
	}
	res = malloc(len + 1);
	if (!res)
		return (NULL);
	res[len] = '\0';
	while (n)
	{
		res[--len] = hex[n % 16];
		n /= 16;
	}
	return (res);
}
