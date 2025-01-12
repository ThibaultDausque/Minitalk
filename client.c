/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdausque <tdausque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 15:18:36 by tdausque          #+#    #+#             */
/*   Updated: 2025/01/01 17:16:23 by tdausque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/minitalk.h"

void	send_signal(int pid, char c)
{
	int		i;
	int		n;

	i = 0;
	while (i < 8)
	{
		if (((c >> (7 - i)) & 1) == 1)
			n = kill(pid, SIGUSR1);
		else if (((c >> (7 - i)) & 1) == 0)
			n = kill(pid, SIGUSR2);
		usleep(600);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*message;
	int		i;

	(void) argv;
	i = 0;
	if (argc != 3)
	{
		ft_printf("Error\n");
		return (0);
	}
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
		return (0);
	message = argv[2];
	while (argv[2][i])
	{
		send_signal(pid, argv[2][i]);
		i++;
	}
	send_signal(pid, '\0');
	return (0);
}
