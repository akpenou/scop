/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akpenou <akpenou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 14:10:00 by akpenou           #+#    #+#             */
/*   Updated: 2017/04/12 11:28:10 by akpenou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <error.h>

void	ft_error(char *message)
{
	perror(message);
	exit(-1);
}

void	ft_gl_error(char *file, char *function, int line)
{
	int		err;

	if ((err = glGetError()))
	{
		printf("GL Error %d (file: %s, func: %s, line: %d)\n", err, file,
															function, line);
		exit(-1);
	}
}
