#include <unistd.h>
#include <stdarg.h>

void	print_hex(unsigned int x, int *len)
{
	char	hex[17] = "0123456789abcdef";
	if (x >= 16)
	{
		print_hex(x / 16, len);
		print_hex(x % 16, len);
	}
	if (x < 16)
	{
		write(1, &hex[x], 1);
		*len = *len + 1;
	}
}

void    print_num(int n, int *len)
{
        char	c;

        if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		*len = *len + 11;
		return ;
	}
	if (n < 0)
         {
                  write (1, "-", 1);
                  *len = *len + 1;
                  n = n * (-1);
                  print_num(n, len);
          }
          else if (n > 9)
          {
                  print_num(n / 10, len);
                  print_num(n % 10, len);
          }
          else
          {
                  c = n + '0';
                  write(1, &c, 1);
                  *len = *len + 1;
          }
}

void	print_str(char *str, int *len)
{
	int	i = 0;

	if (!str)
		str = "(null)";
	while (str[i])
		i++;
	write(1, str, i);
	*len = *len + i;
}

int	ft_printf(const char *str, ...)
{
	va_list args;
	int	i = 0;
	int	len = 0;

	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == 'd')
				print_num(va_arg(args, long long), &len);
			if (str[i] == 's')
				print_str(va_arg(args, char *), &len);
			if (str[i] == 'x')
				print_hex(va_arg(args, unsigned int), &len);
		}
		else
		{
			len++;
			write(1, &str[i], 1);
		}
		i++;
	}
	va_end(args);
	return (len);
}
/*
#include <stdio.h>

int	main(void)
{
	int	i;

	ft_printf("%s\n", "toto");
	ft_printf("Magic %s is %d", "number", 42);
	ft_printf("Hexadecimal for %d is %x\n", 42, 42);
	i = ft_printf("%d %d %d %d\n", -1, 0, 123456789, 2147483648);
	printf("%d\n", printf("%d %d %d %ld\n", -1, 0, 123456789, 2147483648));
	printf ("%d\n", i);
	ft_printf("%s %s %s %s\n", "hello", "", "23", NULL);
	ft_printf("%x %x %x %x %x\n", 53467, 777, 67, 12345675, 61);
	printf("%x %x %x %x %x\n", 53467, 777, 67, 12345675, 61);
}*/
