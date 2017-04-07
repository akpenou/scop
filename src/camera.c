/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akpenou <akpenou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 15:31:07 by akpenou           #+#    #+#             */
/*   Updated: 2017/04/07 19:12:21 by akpenou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <camera.h>

/*
** Projection matrix
** [Sx,  0,  0,  0]
** [ 0, Sy,  0,  0]
** [ 0,  0, Sz, Pz]
** [ 0,  0, -1,  0]
**
** Sx = (2 * near) / (range * aspect + range + aspect) = near / (range * aspect)
** Sy = near / range
** Sz = =(far + near) / (far - near)
** Pz = -(2 * far * near) / (far - near)
** range = tan(fov * 0.5) * near
*/

t_matrix	*m_projection(float near, float far, float fov, float aspect)
{
	t_matrix	*projection;
	float		range;

	projection = matrix_create(4, 4);
	range = tan(fov * DEG_TO_RAD * 0.5) * near;
	projection->data[mpos(*projection, 0, 0)] = near / (range * aspect);
	projection->data[mpos(*projection, 1, 1)] = near / range;
	projection->data[mpos(*projection, 2, 2)] = -(far + near) / (far - near);
	projection->data[mpos(*projection, 3, 2)] = -(2 * far * near) / (far - near);
	projection->data[mpos(*projection, 2, 3)] = -1;
	return (projection);
}

t_matrix	*m_translation(t_vec3 move)
{
	t_matrix	*translation;

	translation = matrix_id(4);
	translation->data[mpos(*translation, 3, 0)] = move.x;
	translation->data[mpos(*translation, 3, 1)] = move.y;
	translation->data[mpos(*translation, 3, 2)] = move.z;
	return (translation);
}

t_matrix	*m_rotation(t_vec4 q)
{
	t_matrix	*rotation;

	rotation = matrix_id(4);
	rotation->data[mpos(*rotation, 0, 0)] = 1 - 2 * q.z * q.z - 2 * q.w * q.w;
	rotation->data[mpos(*rotation, 1, 0)] = 2 * q.y * q.z - 2 * q.x * q.w;
	rotation->data[mpos(*rotation, 2, 0)] = 2 * q.y * q.w + 2 * q.x * q.z;

	rotation->data[mpos(*rotation, 0, 1)] = 2 * q.y * q.z + 2 * q.x * q.w;
	rotation->data[mpos(*rotation, 1, 1)] = 1 - 2 * q.y * q.y - 2 * q.w * q.w;
	rotation->data[mpos(*rotation, 2, 1)] = 2 * q.z * q.w - 2 * q.x * q.y;

	rotation->data[mpos(*rotation, 0, 2)] = 2 * q.y * q.w - 2 * q.x * q.z;
	rotation->data[mpos(*rotation, 1, 2)] = 2 * q.z * q.w + 2 * q.x * q.y;
	rotation->data[mpos(*rotation, 2, 2)] = 1 - 2 * q.y * q.y - 2 * q.z * q.z;
	return (rotation);
}

t_vec4		quaternion(t_vec4 input)
{
	t_vec4	quaternion;
	float	sin_theta;
	float	norm;

	sin_theta = sin(input.x / 2.0);
	norm = sqrt(input.x * input.x + input.y * input.y + input.z * input.z);
	quaternion.x = cos(input.x / 2.0) / norm;
	quaternion.y = sin_theta * input.y / norm;
	quaternion.z = sin_theta * input.z / norm;
	quaternion.w = sin_theta * input.w / norm;
	return (quaternion);
}
