#include "ft_printf.h"

void	ignore_flag(t_info_data *data, int flag)
{
	if (data->flag & flag)
		data->flag = (data->flag ^ flag);
}

void	ignore_flag_priority(t_info_data *data, int strong, int weak)
{
	if (data->flag & strong)
		ignore_flag(data, weak);
}

void	ignore_flag_for_none(t_info_data *data)
{
	ignore_flag(data, DIESE);
	ignore_flag(data, PLUS);
	ignore_flag(data, SPACE);
	ignore_flag(data, PRECISION);
}

void	ignore_flag_for_p(t_info_data *data)
{
	ignore_flag(data, PLUS);
	ignore_flag(data, SPACE);
	ignore_flag(data, ZERO);
	ignore_flag(data, DIESE);
	data->flag = (data->flag | DIESE);
}