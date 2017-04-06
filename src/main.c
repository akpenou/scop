/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akpenou <akpenou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 16:11:17 by akpenou           #+#    #+#             */
/*   Updated: 2017/04/06 16:16:37 by akpenou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <scop.h>

int		main(int ac, char **av)
{
	t_meta_system	meta_system;
	t_meta			meta;

	if (ac != 2)
		return (0);
	meta = parser(av[1]);
	meta_system = create_window();
	print_meta(meta);
	return (0);
}
