/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akpenou <akpenou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 15:31:07 by akpenou           #+#    #+#             */
/*   Updated: 2017/04/12 00:04:00 by akpenou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <camera.h>
#include <window.h>

t_matrix	*m_projection(float near, float far, float fov, float aspect)
{
	t_matrix	*projection;
	float		range;

	projection = matrix_create(4, 4);
	printf("near %f, far %f, fov %f, aspect %f\n", near, far, fov, aspect);
	range = tan(fov * DEG_TO_RAD * 0.5) * near;
	projection->data[mpos(*projection, 0, 0)] = near / (range * aspect);
	projection->data[mpos(*projection, 1, 1)] = near / range;
	projection->data[mpos(*projection, 2, 2)] = -(far + near) / (far - near);
	projection->data[mpos(*projection, 2, 3)] = -(2 * far * near) /
														(far - near);
	projection->data[mpos(*projection, 3, 2)] = -1;
	matrix_print(*projection);
	return (projection);
}

t_matrix	*m_translation(t_vec3 move)
{
	t_matrix	*translation;

	translation = matrix_id(4);
	translation->data[mpos(*translation, 0, 3)] = move.x;
	translation->data[mpos(*translation, 1, 3)] = move.y;
	translation->data[mpos(*translation, 2, 3)] = move.z;
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

t_vec4		quaternion(t_vec3 input)
{
	t_vec4	quat;
	float	t[6];

	t[0] = cos(input.z * 0.5);
	t[1] = sin(input.z * 0.5);
	t[2] = cos(input.x * 0.5);
	t[3] = sin(input.x * 0.5);
	t[4] = cos(input.y * 0.5);
	t[5] = sin(input.y * 0.5);
	quat.x = t[0] * t[2] * t[4] + t[1] * t[3] * t[5];
	quat.y = t[0] * t[3] * t[4] - t[1] * t[2] * t[5];
	quat.z = t[0] * t[2] * t[5] + t[1] * t[3] * t[4];
	quat.w = t[1] * t[2] * t[4] - t[0] * t[3] * t[5];
	return (quat);
}
