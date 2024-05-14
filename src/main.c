/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaratej <cgaratej@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:02:18 by cgaratej          #+#    #+#             */
/*   Updated: 2024/05/14 17:50:01 by cgaratej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//ps lf || ps lp id
//kill -9
#include "../includes/pipex.h"

int	main(int argc, char **argv, char **env)
{
	int		p_fd[2];
	pid_t	pid;
	int		status;

	if (argc != 5)
		print_error("./pipex file1 cmd cmd file2\n", 0, 2);
	if (pipe(p_fd) == -1)
		print_error("error in pipe", 1, 2);
	pid = fork();
	
}
