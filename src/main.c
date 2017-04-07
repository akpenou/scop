/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akpenou <akpenou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 16:11:17 by akpenou           #+#    #+#             */
/*   Updated: 2017/04/07 10:53:54 by akpenou          ###   ########.fr       */
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
	meta_system.vao = load_vao(meta);
	print_array(meta.face, "face");
	meta_system.shader_program = load_shader_program();
	wait_event(meta_system, meta);
	return (0);
}
