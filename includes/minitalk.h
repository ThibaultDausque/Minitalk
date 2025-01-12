/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdausque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 14:57:10 by tdausque          #+#    #+#             */
/*   Updated: 2025/01/03 13:40:39 by tdausque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include "../lib/libft.h"
# include "../ft_printf/ft_printf.h"
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>

void	send_signal(int pid, char c);
void	clean_up(int nb);
char	*ft_strjoin_c(char *message, char c);
void	handle_signal(int sign);
#endif
