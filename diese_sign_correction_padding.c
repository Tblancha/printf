#include "ft_printf.h"

char
	*correction_precision_padding_flag_zero(t_info_data *data)
{
	if (data->flag & PRECISION)
	{
		if (data->precision < data->len_arg)
		{
			while (*data->arg_str == '0')
			{
				data->arg_str += 1;
				data->len_arg--;
				if (data->padding > 0)
					data->padding++;
			}
		}
	}
	return (data->arg_str);
}

void
	handler_signe_or_flag_plus(t_buff *buff,t_info_data *data)
{
	static int	check = 0;

	if (((data->flag & PLUS) && (data->flag & ZERO) && check == 0)
	|| ((data->flag & PLUS) && check == 1 && !(data->flag & ZERO)))
	{
		if (data->sign == 1)
			ft_putchar_buff(buff, '-');
		else
			ft_putchar_buff(buff, '+');
		check += 9;
	}
	else if ((data->type == 8 || data->type == 6) && check == 1)
	{
		if (data->sign == 1)
			ft_putchar_buff(buff, '-');
	}
	else if (check == 0 && (data->flag & ZERO))
		if (data->sign == 1)
		{
			ft_putchar_buff(buff, '-');
			++check;
		}
	++check;
}

void
	prefix_router(t_buff *buff, t_info_data *data)
{
	if ((data->arg_str[0] == 0 || data->arg_str[0] == '0')
			&& (data->type != TYPE_O && data->type != TYPE_P))
		return ;
	if (data->type == TYPE_X_MAJ)
		ft_putstr_buff(buff, "0X");
	else if (data->type == TYPE_X_MIN || data->type == TYPE_P)
		ft_putstr_buff(buff, "0x");
	else if (data->type == TYPE_O)
	{
		if (data->arg_str[0] != '0')
			ft_putchar_buff(buff, '0');
	}
}