/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akpenou <akpenou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 09:55:15 by akpenou           #+#    #+#             */
/*   Updated: 2017/04/11 10:41:41 by akpenou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_H
# define TEXTURE_H

# include <bmp.h>
# include <window.h>

typedef struct			s_texture
{
	unsigned int		width;
	unsigned int		height;
	unsigned int		bits;
	unsigned int		size;
	t_array				image;
}						t_texture;

void	load_texture(t_texture texture, t_infos infos);

#endif
