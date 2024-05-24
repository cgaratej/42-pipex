/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaratej <cgaratej@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:02:18 by cgaratej          #+#    #+#             */
/*   Updated: 2024/05/24 15:57:26 by cgaratej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	generate_pipe(char *cmd, char **env);
static void	exec_cmd(char *cmd, char **env);

int	main(int argc, char **argv, char **env)
{
	int		i;
	int		fd_i;
	int		fd_o;

	i = 2;
	if (argc < 5)
		print_error("./pipex file1 cmd cmd .. file2\n", 0, 2);
	fd_i = open_file(argv[1], 1);
	fd_o = open_file(argv[argc - 1], 0);
	while (i < argc - 2)
		generate_pipe(argv[i++], env);
	if (dup2(fd_o, STDOUT_FILENO) == -1)
		print_error("error failed to redirect stdout", 1, 2);
	exec_cmd(argv[argc - 1], env);
	close(fd_i);
	close(fd_o);
	return (0);
}

static void	generate_pipe(char *cmd, char **env)
{
	int		fd[2];
	pid_t	pid;
	int		status;

	if (pipe(fd) == -1)
		print_error("error in pipe", 1, 2);
	pid = fork();
	if (pid == -1)
		print_error("error in fork", 1, 2);
	if (!pid)
	{
		close(fd[0]);
		if (dup2(fd[1], STDOUT_FILENO) == -1)
			print_error("error failed to redirect stdout", 1, 2);
		exec_cmd(cmd, env);
	}
	wait(&status);
	if (pid)
	{
		close(fd[1]);
		if (dup2(fd[0], STDIN_FILENO) == -1)
			print_error("error failed to redirect stdin\n", 1, 2);
	}
}

static void	exec_cmd(char *cmd, char **env)
{
	char	**cmd_l;
	char	*path;

	cmd_l = ft_split(cmd, ' ');
	if (!cmd_l)
		print_error("command not found\n", 0, 127);
	path = get_path(cmd_l[0], env);
	if (execve(path, cmd_l, env) == -1)
	{
		free_paths(cmd_l);
		//ft_putstr_fd(cmd_l[0], 0);
		print_error(cmd_l[0], 0, 127);
	}
	free_paths(cmd_l);
}
