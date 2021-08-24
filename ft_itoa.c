#include "libft.h"

static int	intlen(int	nb)
{
	int	len;

	len = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		nb *= -1;
		len++;
	}
	while (nb)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int	n)
{
	char	*res;
	int		len;
	long	nb;

	len = intlen(n);
	nb = n;
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (0);
	res[len--] = 0;
	if (!nb)
		res[len] = 0;
	if (nb < 0)
	{
		res[0] = '-';
		nb *= -1;
	}
	while (nb != 0)
	{
		res[len--] = (nb % 10) + '0';
		nb /= 10;
	}
	 return (res);
}

//Intlen counts length of the integer, if n < 0, len++ = 1 for the '-' sign.
//Convert to long so it can handle min int.
