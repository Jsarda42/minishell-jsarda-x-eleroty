/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perror.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarda <jsarda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 13:12:59 by jsarda            #+#    #+#             */
/*   Updated: 2024/06/28 10:44:36 by jsarda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	perror_handler(char *type)
{
	perror(type);
	exit(EXIT_FAILURE);
}

void	ft_error(char *message, char *err, int exit_status, t_minishell *data)
{
	if (err)
	{
		ft_putstr_fd(message, 2);
		ft_putendl_fd(err, 2);
	}
	else
		ft_putendl_fd(message, 2);
	data->exit_status = exit_status;
}
