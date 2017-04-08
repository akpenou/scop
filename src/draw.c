/* ************************************************************************** */ /*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akpenou <akpenou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 10:21:43 by akpenou           #+#    #+#             */
/*   Updated: 2017/04/08 16:05:45 by akpenou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <draw.h>

void	draw(t_meta meta, t_infos infos)
{
	int		err;

	glUseProgram (infos.shader_program);
	glUniformMatrix4fv(infos.proj_idx, 1, GL_FALSE, infos.projection->data);
	glUniformMatrix4fv(infos.view_idx, 1, GL_FALSE, infos.view->data);
	glBindVertexArray(infos.vao);
	//glDrawElements(GL_TRIANGLES, meta.face->nb_elem * 3, GL_UNSIGNED_INT, 0);
	glDrawElementsBaseVertex(GL_TRIANGLES, meta.face->nb_elem * 3, GL_UNSIGNED_INT, 0, 0);
	//glDrawArrays(GL_TRIANGLES, 0, 3);
	//glBindVertexArray(infos.vao);
	if ((err = glGetError()))
	{
		printf("GL %s, l: %d failed: %x\n", __func__, __LINE__, err);
		exit(-1);
		ft_error("");
	}
}

t_infos	load_mvc(t_infos infos)
{
	infos.proj_idx = glGetUniformLocation(infos.shader_program, "proj");
	infos.view_idx = glGetUniformLocation(infos.shader_program, "view");
	infos.projection = m_projection(0.1f, 100.0f, 67, (float)WIN_WIDTH / (float)WIN_HEIGTH);
	infos.cam_pos = vec3_create(0, 0, 0);
	infos.cam_rot = vec3_create(0, 0, 0);
	infos.view = m_translation(vec3_create(0, 0, 0));
	return (infos);
}

t_infos	move_cam(t_infos infos)
{
	t_vec4	quat;
	t_vec3	cam;

	if (infos.events.type == SDL_KEYDOWN)
	{
		if (infos.events.key.keysym.sym == SDLK_LEFT)
			infos.cam_pos.x -= infos.elapsed_time;
		if (infos.events.key.keysym.sym == SDLK_RIGHT)
			infos.cam_pos.x += infos.elapsed_time;
		if (infos.events.key.keysym.sym == SDLK_PAGEDOWN)
			infos.cam_pos.z -= infos.elapsed_time;
		if (infos.events.key.keysym.sym == SDLK_PAGEUP)
			infos.cam_pos.z += infos.elapsed_time;
		if (infos.events.key.keysym.sym == SDLK_DOWN)
			infos.cam_pos.y -= infos.elapsed_time;
		if (infos.events.key.keysym.sym == SDLK_UP)
			infos.cam_pos.y += infos.elapsed_time;
		if (infos.events.key.keysym.sym == SDLK_z)
			infos.cam_rot.x -= infos.elapsed_time;
		if (infos.events.key.keysym.sym == SDLK_a)
			infos.cam_rot.x += infos.elapsed_time;
		if (infos.events.key.keysym.sym == SDLK_x)
			infos.cam_rot.y -= infos.elapsed_time;
		if (infos.events.key.keysym.sym == SDLK_s)
			infos.cam_rot.y += infos.elapsed_time;
		if (infos.events.key.keysym.sym == SDLK_c)
			infos.cam_rot.z -= infos.elapsed_time;
		if (infos.events.key.keysym.sym == SDLK_d)
			infos.cam_rot.z += infos.elapsed_time;
		printf("cam pos (%f, %f, %f)\n", infos.cam_pos.x, infos.cam_pos.y, infos.cam_pos.z);
		printf("cam rot (%f, %f, %f)\n", infos.cam_rot.x, infos.cam_rot.y, infos.cam_rot.z);
		free(infos.view->data);
		free(infos.view);
		cam = infos.cam_rot;
		// quat = quaternion(vec4_create(1.0f, cam.x * DEG_TO_RAD, cam.y * DEG_TO_RAD, cam.z * DEG_TO_RAD));
		quat = quaternion(vec4_create(1.0f, cam.x, cam.y, cam.z));
		infos.translation = m_translation(infos.cam_pos);
		infos.rotation = m_rotation(quat);
		// infos.view = matrix_mult(*infos.translation, *infos.rotation);
		infos.view = matrix_mult(*infos.rotation, *infos.translation);
		free(infos.translation->data);
		free(infos.translation);
		free(infos.rotation->data);
		free(infos.rotation);
	}
	return (infos);
}