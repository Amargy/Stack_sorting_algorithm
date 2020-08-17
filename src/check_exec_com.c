/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_exec_com.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amargy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 16:01:26 by amargy            #+#    #+#             */
/*   Updated: 2020/02/27 19:17:05 by amargy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		com_valid_and_write(t_ps *p)
{
	create_com_node(p);
	p->tmp_c = p->c;
	while (get_next_line(0, &p->cur_com) > 0)
	{
		if (p->gnl_sec_iter != 0)
			create_com_node(p);
		if (cur_com_valid(p->cur_com))
		{
			p->tmp_c->com = ft_strdup(p->cur_com);
			if (p->cur_com != NULL)
			{
				free(p->cur_com);
				p->cur_com = NULL;
			}
		}
		else
			return (0);
		p->ifnocom = 1;
		p->gnl_sec_iter++;
	}
	p->tmp_c = NULL;
	return (1);
}

int		cur_com_valid(char *cur_com)
{
	if (!(ft_strcmp(cur_com, "sa")))
		return (1);
	else if (!(ft_strcmp(cur_com, "sb")))
		return (1);
	else if (!(ft_strcmp(cur_com, "ss")))
		return (1);
	else if (!(ft_strcmp(cur_com, "pa")))
		return (1);
	else if (!(ft_strcmp(cur_com, "pb")))
		return (1);
	else if (!(ft_strcmp(cur_com, "ra")))
		return (1);
	else if (!(ft_strcmp(cur_com, "rb")))
		return (1);
	else if (!(ft_strcmp(cur_com, "rr")))
		return (1);
	else if (!(ft_strcmp(cur_com, "rra")))
		return (1);
	else if (!(ft_strcmp(cur_com, "rrb")))
		return (1);
	else if (!(ft_strcmp(cur_com, "rrr")))
		return (1);
	return (0);
}

void	execute_command(t_ps *p, char *cur_com)
{
	if (!(ft_strcmp(cur_com, "sa")))
		exec_sa_sb(p->top_a, p->a, p->i_last);
	else if (!(ft_strcmp(cur_com, "sb")))
		exec_sa_sb(p->top_b, p->b, p->i_last);
	else if (!(ft_strcmp(cur_com, "ss")))
		exec_ss(p);
	else if (!(ft_strcmp(cur_com, "pa")))
		exec_pa_pb(p, "b");
	else if (!(ft_strcmp(cur_com, "pb")))
		exec_pa_pb(p, "a");
	else if (!(ft_strcmp(cur_com, "ra")))
		exec_ra_rb(p->top_a, p->a, p->i_last);
	else if (!(ft_strcmp(cur_com, "rb")))
		exec_ra_rb(p->top_b, p->b, p->i_last);
	else if (!(ft_strcmp(cur_com, "rr")))
		exec_rr(p);
	else if (!(ft_strcmp(cur_com, "rra")))
		exec_rra_rrb(p->top_a, p->a, p->i_last);
	else if (!(ft_strcmp(cur_com, "rrb")))
		exec_rra_rrb(p->top_b, p->b, p->i_last);
	else if (!(ft_strcmp(cur_com, "rrr")))
		exec_rrr(p);
}
