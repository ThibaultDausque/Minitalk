/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdausque <tdausque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 15:18:39 by tdausque          #+#    #+#             */
/*   Updated: 2025/01/01 17:30:55 by tdausque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/minitalk.h"

char	*g_message;

void	clean_up(int nb)
{
	(void) nb;
	if (g_message)
	{
		free(g_message);
		g_message = NULL;
	}
	exit(0);
}

char	*ft_strjoin_c(char *message, char c)
{
	int		i;
	int		len;
	char	*str;

	if (!message)
		return (NULL);
	len = ft_strlen(message);
	str = (char *)malloc((len + 2) * sizeof(char));
	if (!str)
	{
		free(message);
		return (NULL);
	}
	i = 0;
	while (message[i])
	{
		str[i] = message[i];
		i++;
	}
	str[i] = c;
	i++;
	str[i] = '\0';
	free(message);
	message = NULL;
	return (str);
}

void	handle_signal(int sign)
{
	static char	c;
	static int	count_bits;

	if (!g_message)
		return ;
	c <<= 1;
	if (sign == SIGUSR1)
		c |= 1;
	count_bits++;
	if (count_bits == 8)
	{
		if (c == '\0')
		{
			ft_printf("%s\n", g_message);
			free(g_message);
			g_message = NULL;
			g_message = ft_strdup("");
		}
		else
			g_message = ft_strjoin_c(g_message, c);
		c = 0;
		count_bits = 0;
	}
}

int	main(void)
{
	int		pid;

	g_message = ft_strdup("");
	pid = getpid();
	ft_printf("Server PID: [%d]\n", pid);
	signal(SIGUSR1, handle_signal);
	signal(SIGUSR2, handle_signal);
	signal(SIGINT, clean_up);
	while (1)
		pause();
	return (0);
}
