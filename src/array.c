/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akpenou <akpenou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 11:42:27 by akpenou           #+#    #+#             */
/*   Updated: 2017/04/11 18:59:56 by akpenou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <array.h>

t_array		*array_create(unsigned int nb_elem, enum e_array type)
{
	t_array		*tab;

	if (!(tab = (t_array *)malloc(sizeof(t_array))))
		return (NULL);
	tab->nb_elem = nb_elem;
	tab->type = type;
	if (type == IVEC4)
		tab->size_elem = sizeof(t_ivec4);
	else if (type == VEC4)
		tab->size_elem = sizeof(t_vec4);
	else if (type == VEC3)
		tab->size_elem = sizeof(t_vec3);
	else if (type == IVEC3)
		tab->size_elem = sizeof(t_ivec3);
	else
		return (NULL);
	tab->size = nb_elem * tab->size_elem;
	tab->max_elem = (nb_elem / 100 + 1) * 100;
	tab->max_size = tab->max_elem * tab->size_elem;
	if (!(tab->tab.ptr = (void *)malloc(tab->max_size)))
	{
		free(tab);
		return (NULL);
	}
	return (tab);
}

t_array		*array_pushback(t_array *tab, union u_array elem, int free_)
{
	if (tab->nb_elem >= tab->max_elem - 1)
	{
		tab->max_elem += 100;
		tab->max_size = tab->max_elem * tab->size_elem;
		if (!(tab->tab.ptr = (void *)realloc(tab->tab.ptr, tab->max_size)))
			return (NULL);
	}
	if (tab->type == IVEC4)
		tab->tab.ivec4[tab->nb_elem++] = *elem.ivec4;
	else if (tab->type == VEC4)
		tab->tab.vec4[tab->nb_elem++] = *elem.vec4;
	else if (tab->type == VEC3)
		tab->tab.vec3[tab->nb_elem++] = *elem.vec3;
	else if (tab->type == IVEC3)
		tab->tab.ivec3[tab->nb_elem++] = *elem.ivec3;
	else
		return (tab);
	tab->size = tab->nb_elem * tab->size_elem;
	if (free_)
		free(elem.ptr);
	return (tab);
}

t_array		*array_pushback_multi(t_array *tab, union u_array *elem, uint32_t nb_elem, int free_)
{
	t_array		*res;
	uint32_t	index;

	index = -1;
	res = tab;
	while (++index < nb_elem)
		res = array_pushback(res, elem[index], free_);
	return (res);
}

void		print_array(t_array *tab, char *prefix)
{
	const char	*types[] = {"IVEC4", "VEC4", "IVEC3", "VEC3"};
	uint32_t	i;

	i = -1;
	printf("array of %s:", prefix);
	printf("  (%u elements, %u size, %u max size, %s type)\n", tab->nb_elem, tab->size, tab->max_size, types[tab->type]);
	while (++i < tab->nb_elem)
	{
		printf("%3d ", i);
		if (tab->type == IVEC4)
			printf("[ %5.2d, %5.2d, %5.2d, %5.2d]\n", tab->tab.ivec4[i].x,
					tab->tab.ivec4[i].y, tab->tab.ivec4[i].z, tab->tab.ivec4[i].w);
		else if (tab->type == VEC4)
			printf("[ %5.2f, %5.2f, %5.2f, %5.2f]\n", tab->tab.vec4[i].x,
					tab->tab.vec4[i].y, tab->tab.vec4[i].z, tab->tab.vec4[i].w);
		else if (tab->type == VEC3)
			printf("[ %5.2f, %5.2f, %5.2f]\n", tab->tab.vec3[i].x,
					tab->tab.vec3[i].y, tab->tab.vec3[i].z);
		else if (tab->type == IVEC3)
			printf("[ %5d, %5d, %5d]\n", tab->tab.ivec3[i].x,
					tab->tab.ivec3[i].y, tab->tab.ivec3[i].z);
	}
}

void		print_meta_array(t_array *tab, char *prefix)
{
	const char	*types[] = {"IVEC4", "VEC4", "IVEC3", "VEC3"};

	printf("array of %s:", prefix);
	printf("  (%u elements, %u size, %u max size, %s type)\n", tab->nb_elem, tab->size, tab->max_size, types[tab->type]);
}
