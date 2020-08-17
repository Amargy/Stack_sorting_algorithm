/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amargy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 12:00:26 by amargy            #+#    #+#             */
/*   Updated: 2020/03/10 12:02:13 by amargy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		walk_along_arg2(char *arg, t_ps *p)
{
	int number_count;

	number_count = 0;
	if (arg[p->i] >= '0' && arg[p->i] <= '9')
	{
		p->start_number = p->find_minus == 1 ? p->i - 1 : p->i;
		p->find_number = 1;
	}
	while (arg[p->i] != '\0' && (arg[p->i] >= '0' && arg[p->i] <= '9'))
	{
		p->i++;
		number_count++;
	}
	if (number_count - 1 > 10)
		return (-1);
	while (arg[p->i] == ' ')
		p->i++;
	if ((!(ft_isdigit(arg[p->i])) && arg[p->i] != '\0' && arg[p->i] != '-')
	|| !p->find_number)
		return (-1);
	if (arg[p->i] == '\0' && number_count == 0)
		return (0);
	return (p->i);
}

int		walk_along_arg_and_check_long_long(char *arg, t_ps *p)
{
	while (arg[p->i] == ' ')
		p->i++;
	if (arg[p->i] == '-')
	{
		if (ft_isdigit(arg[p->i + 1]))
		{
			p->i++;
			p->find_minus = 1;
		}
		else
			return (-1);
	}
	return (walk_along_arg2(arg, p));
}

int		pars_arg(char *arg, t_ps *p)
{
	int tmp;

	tmp = 0;
	while ((tmp = walk_along_arg_and_check_long_long(arg, p)))
	{
		if (tmp == -1)
			return (0);
		if (tmp == 0)
			break ;
		if (!(check_overflow_and_take_numb(arg,
		p, p->i_last)))
			return (0);
		if (p->tmp_stack[p->i_last] > p->max)
			p->max = p->tmp_stack[p->i_last];
		p->i_last++;
		p->find_minus = 0;
	}
	return (1);
}
