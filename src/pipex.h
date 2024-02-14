/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahiguera <ahiguera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 12:24:20 by ahiguera          #+#    #+#             */
/*   Updated: 2024/02/14 15:50:30 by ahiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include "../Libft_2.0/src/libft.h"

# define READ_FD	0
# define WRITE_FD	1

char	*pp_find_path(char *cmd, char **envp);
void	pp_execute(char *argv, char **envp);
char	*pp_rm_spaces(char *message);
void	pp_error(void);

#endif