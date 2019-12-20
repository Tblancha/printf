#include "ft_printf.h"

void		apply_precision_c(t_buff *buff, t_info_data *data)
{
	if (data->flag & PRECISION)
	{
		if (data->precision >= 1)
			ft_putchar_buff(buff, data->arg_int);
	}
	else
		ft_putchar_buff(buff, data->arg_int);
}

void		apply_precision_s(t_buff *buff, t_info_data *data)
{
	if (data->flag & PRECISION)
	{
		if (data->precision < data->len_arg)
			ft_putnstr_buff(buff, data->arg_str, data->precision);
		else
			ft_putstr_buff(buff, data->arg_str);
	}
	else
		ft_putstr_buff(buff, data->arg_str);
}

void		apply_precision_pdiouxxmaj(t_buff *buff, t_info_data *data)
{
	if (data->type == TYPE_O && (data->flag & DIESE))
		data->precision--;
	if (data->flag & PRECISION)
		if (data->precision > data->len_arg)
			ft_repeat_char_buff(buff, '0',
					(data->precision - data->len_arg));
	ft_putstr_buff(buff, data->arg_str);
}