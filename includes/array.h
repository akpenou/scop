/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akpenou <akpenou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 13:48:55 by akpenou           #+#    #+#             */
/*   Updated: 2017/04/06 14:39:26 by akpenou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_H
# define ARRAY_H

# include <matrix.h>
# include <stdlib.h>

typedef union	u_array
{
	t_ivec4		*ivec4;
	t_vec4		*vec4;
	t_ivec3		*ivec3;
	t_vec3		*vec3;
	void		*ptr;
}				t_array_u;

typedef enum	e_array
{
	IVEC4,
	VEC4,
	IVEC3,
	VEC3
}				t_array_e;

typedef struct	s_array
{
	uint32_t	nb_elem;
	uint32_t	size_elem;
	uint32_t	size;
	uint32_t	max_size;
	uint32_t	max_elem;
	t_array_e	type;
	t_array_u	tab;
}					t_array;

t_array			*array_pushback(t_array *tab, union u_array elem, int free_);
t_array			*array_create(unsigned int nb_elem, enum e_array type);
void			print_array(t_array *tab, char *prefix);
void			print_meta_array(t_array *tab, char *prefix);

#endif
