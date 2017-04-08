/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akpenou <akpenou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 16:11:17 by akpenou           #+#    #+#             */
/*   Updated: 2017/04/08 21:35:16 by akpenou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <scop.h>

int		main(int ac, char **av)
{
	t_infos	infos;
	t_meta			meta;

	if (ac != 2)
		return (0);
	meta = parser(av[1]);
	infos = create_window();
	infos.vao = load_vao(meta);
	print_array(meta.vertex, "vertex");
	print_array(meta.face, "face");
	infos.shader_program = load_shader_program();
	infos = load_mvc(meta, infos);
	wait_event(infos, meta);
	return (0);
}
