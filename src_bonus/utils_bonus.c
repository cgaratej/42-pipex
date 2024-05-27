/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaratej <cgaratej@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:00:50 by cgaratej          #+#    #+#             */
/*   Updated: 2024/05/27 11:45:14 by cgaratej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

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

int	open_file(char *file, int option, char *file2)
{
	int	fd;
	int	fd_i;

	if (option)
	{
		fd_i = open(file2, O_RDONLY, 0777);
		fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
		if (access(file2, R_OK))
		{
			if (fd_i == -1)
				print_error("error open file", 1, 2);
			print_error("permission denied\n", 0, 126);
		}
		if (dup2(fd_i, STDIN_FILENO) == -1)
			print_error("error failed to redirect stdin", 1, 2);
		close(fd_i);
	}
	else
		fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd == -1)
		print_error("error open file", 1, 2);
	return (fd);
}

void	free_paths(char **path)
{
	int	i;

	i = 0;
	while (path[i])
	{
		free(path[i]);
		i++;
	}
	free(path);
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
		free(path);
		if (!access(path_final, X_OK | F_OK))
			return (path_final);
		free(path_final);
		i++;
	}
	free_paths(path_list);
	return (cmd);
}
