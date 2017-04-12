/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akpenou <akpenou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 14:11:36 by akpenou           #+#    #+#             */
/*   Updated: 2017/04/12 11:33:10 by akpenou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include <GL/glew.h>
# include <SDL2/SDL.h>
# include <OpenGL/gl.h>
# include <stdio.h>
# include <stdlib.h>

void	ft_error(char *message);
void	ft_gl_error(char *file, char *function, int line);

#endif
