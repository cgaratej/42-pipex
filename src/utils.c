/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaratej <cgaratej@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:00:50 by cgaratej          #+#    #+#             */
/*   Updated: 2024/05/15 16:25:47 by cgaratej         ###   ########.fr       */
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

int	open_file(char *file, int infile)
{
	int	fd;

	if (infile)
	{
		fd = open(file, O_RDONLY, 0644);
		if (access(file, R_OK))
		{
			if (fd == -1)
				print_error("infile", 1, 1);
			print_error("permission denied\n", 0, 126);
		}
	}
	else
	{
		fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (access(file, W_OK))
		{
			if (fd == -1)
				print_error("outfile", 1, 1);
			print_error("permission denied\n", 0, 126);
		}
	}
	return (fd);
}

static char	*get_env(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (!ft_strncmp(env[i], "PATH=", 5))
			return (env[i] + 5);
		i++;
	}
	return (NULL);
}

char	*get_path(char *cmd, char **env)
{
	int		i;
	char	**path_list;
	char	*path;
	char	*path_final;

	i = 0;
	path_list = ft_split(get_env(env), ':');
	if (!path_list)
		print_error("command not found\n", 0, 127);
	while (path_list[i])
	{
		path = ft_strjoin(path_list[i], "/");
		if (!path)
			print_error("command not found\n", 0, 127);
		path_final = ft_strjoin(path, cmd);
		if (!path_final)
			print_error("command not found\n", 0, 127);
		ft_putstr_fd(path_final, 0);
		ft_putchar_fd('\n', 0);
		i++;
	}
	return (NULL);
}
