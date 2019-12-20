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
				ft_putstr("PAS ENCORE FAIT\n");
			}
			else
				dispatch_type(data.type)(arg, &buff, &data);
		}
	}
	flush_buff(&buff);
	return (buff.len);
}