/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaratej <cgaratej@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 14:25:05 by cgaratej          #+#    #+#             */
/*   Updated: 2024/05/14 17:54:36 by cgaratej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <sys/wait.h> //wait
# include <unistd.h> //fork
# include <stdlib.h> //malloc
# include <fcntl.h>
# include "../libft/libft.h"
# include "../libft/get_next_line/get_next_line.h"

void	print_error(char *str, int per, int ex);

#endif