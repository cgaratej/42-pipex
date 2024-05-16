/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaratej <cgaratej@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 14:25:05 by cgaratej          #+#    #+#             */
/*   Updated: 2024/05/16 12:57:34 by cgaratej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <sys/wait.h> //wait
# include <unistd.h> //fork
# include <stdlib.h> //malloc
# include <stdio.h> //perror
# include <fcntl.h> //Opne
# include "../libft/libft.h"
# include "../libft/get_next_line/get_next_line.h"

void	print_error(char *str, int per, int ex);
int		open_file(char *file, int infile);
char	*get_path(char *cmd, char **env);
void	free_paths(char **path);

#endif