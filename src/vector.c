/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akpenou <akpenou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 11:49:12 by akpenou           #+#    #+#             */
/*   Updated: 2017/04/12 11:50:27 by akpenou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <matrix.h>

t_ivec4	ivec4_create(int x, int y, int z, int w)
{
	t_ivec4		vec;

	vec.x = x;
	vec.y = y;
	vec.z = z;
	vec.w = w;
	return (vec);
}

t_vec4	vec4_create(float x, float y, float z, float w)
{
	t_vec4		vec;

	vec.x = x;
	vec.y = y;
	vec.z = z;
	vec.w = w;
	return (vec);
}

t_ivec3	ivec3_create(int x, int y, int z)
{
	t_ivec3		vec;

	vec.x = x;
	vec.y = y;
	vec.z = z;
	return (vec);
}

t_vec3	vec3_create(float x, float y, float z)
{
	t_vec3		vec;

	vec.x = x;
	vec.y = y;
	vec.z = z;
	return (vec);
}
