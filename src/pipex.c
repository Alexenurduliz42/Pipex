/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahiguera <ahiguera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:20:33 by ahiguera          #+#    #+#             */
/*   Updated: 2024/01/10 18:08:37 by ahiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

/* 
pid
fork
waitpid
(getpid)
(getppid)

execve

pipe
open
dup
dup2
close

perror
strerror
*/

int	main(void)
{
	int		fd[2];
	pid_t	pid;

	pipe(fd);
	pid = fork();
	if (pid == -1)
	{
		perror("error en el proceso");
	}
	else if (pid == 0)
	{
		printf("caso 1, hijo: %d \n", getpid());
		sleep(100);
	}
	else
	{
		printf("caso 2, padre: %d \n", getpid());
		sleep(100);
	}
}
