/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akpenou <akpenou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 10:21:57 by akpenou           #+#    #+#             */
/*   Updated: 2017/04/08 13:38:47 by akpenou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include <load_param.h>

void	draw(t_meta meta, t_infos infos);
t_infos	load_mvc(t_infos infos);
t_infos	move_cam(t_infos infos);

#endif
