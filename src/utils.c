/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaratej <cgaratej@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:00:50 by cgaratej          #+#    #+#             */
/*   Updated: 2024/05/14 17:29:36 by cgaratej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	print_error(char *str, int per, int ex)
{
	if (per)
	{
		perror(str);
		exit(EXIT_FAILURE);
	}
	else
	{
		ft_putstr_fd(str, 2);
		exit(ex);
	}
}
