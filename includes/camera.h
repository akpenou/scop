/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akpenou <akpenou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 15:31:09 by akpenou           #+#    #+#             */
/*   Updated: 2017/04/07 17:56:29 by akpenou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# define DEG_TO_RAD (2.0 * M_PI) / 360.0

# include <matrix.h>
# include <math.h>

t_matrix	*m_projection(float near, float far, float fov, float aspect);
t_matrix	*m_translation(t_vec3 move);
t_matrix	*m_rotation(t_vec4 q);
t_vec4		quaternion(t_vec4 input);

#endif
