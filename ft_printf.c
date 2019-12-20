#include "ft_printf.h"

static void
	init_struct_buff(t_buff *buff)
{
	buff->index = 0;
	buff->len = 0;
	ft_bzero(buff->buffer, BUFF_SIZE_2);
}

int
	ft_printf(const char *format, ...)
{
	char			*str;
	t_buff			buff;
	va_list			arg;
	t_info_data		data;

	if (!format)
	{
		ft_putstr("Usage: ft_printf(\"Put a string here\")");
		return (0);
	}
	str = (char *)format;
	va_start(arg, format);
	init_struct_buff(&buff);
	while (*str)
	{
		if (*str != '%')
		{
			ft_putchar_buff(&buff, *str);
			str++;
		}
		else
		{
			str++;
			parse_percent(&data, &str);
			if (data.flag & ETOILE)
				data.padding = (int)va_arg(arg, int);
			if (data.type == TYPE_NONE || data.type == TYPE_PERCENT)
			{

			}
			else
			{
				dispatch_type(data.type)(arg, &buff, &data);
			}
			/*
			ft_putstr("\n\ntype = ");
			ft_putnbr(data.type);
			ft_putstr("\nflag = ");
			ft_putnbr(data.flag);
			ft_putstr("\nconversion = ");
			ft_putnbr(data.conversion);
			ft_putstr("\npadding = ");
			ft_putnbr(data.padding);
			ft_putstr("\nprecision = ");
			ft_putnbr(data.precision);
			ft_putstr("\n");
			*/
		}
	}
	flush_buff(&buff);
/*	ft_putstr("\nret = ");
	ft_putnbr(buff.len);
*/
	return (buff.len);
}