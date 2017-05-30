/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_ocp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoupleu <acoupleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 19:04:28 by acoupleu          #+#    #+#             */
/*   Updated: 2017/05/09 17:13:17 by acoupleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_ocp	init_ocp(void)
{
	t_ocp	ocp;

	ocp.param1 = '\0';
	ocp.param2 = '\0';
	ocp.param3 = '\0';
	return (ocp);
}

int		ocp_param1(t_ocp *result, int ocp)
{
	if (ocp - 192 >= 0)
	{
		result->param1 = 'I';
		ocp -= 192;
	}
	else if (ocp - 128 >= 0)
	{
		result->param1 = 'D';
		ocp -= 128;
	}
	else if (ocp - 64 >= 0)
	{
		result->param1 = 'R';
		ocp -= 64;
	}
	return (ocp);
}

int		ocp_param2(t_ocp *result, int ocp)
{
	if (ocp - 48 >= 0)
	{
		result->param2 = 'I';
		ocp -= 48;
	}
	else if (ocp - 32 >= 0)
	{
		result->param2 = 'D';
		ocp -= 32;
	}
	else if (ocp - 16 >= 0)
	{
		result->param2 = 'R';
		ocp -= 16;
	}
	return (ocp);
}

void	ocp_param3(t_ocp *result, int ocp)
{
	if (ocp - 12 >= 0)
	{
		result->param3 = 'I';
		ocp -= 12;
	}
	else if (ocp - 8 >= 0)
	{
		result->param3 = 'D';
		ocp -= 8;
	}
	else if (ocp - 4 >= 0)
	{
		result->param3 = 'R';
		ocp -= 4;
	}
}

t_ocp	ocp_master(int ocp)
{
	t_ocp result;

	result = init_ocp();
	ocp = ocp_param1(&result, ocp);
	ocp = ocp_param2(&result, ocp);
	ocp_param3(&result, ocp);
	return (result);
}
