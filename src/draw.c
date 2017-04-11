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
	glUniformMatrix4fv(infos.center_idx, 1, GL_FALSE, infos.center->data);
	glUniformMatrix4fv(infos.rot_idx, 1, GL_FALSE, infos.rotation->data);
	glUniform1f(infos.fade_idx, infos.current_fade);
	glBindVertexArray(infos.vao);
	glDrawElementsBaseVertex(GL_TRIANGLES, meta.face->nb_elem * 3, GL_UNSIGNED_INT, 0, 0);
	if ((err = glGetError()))
	{
		printf("GL %s, l: %d failed: %x\n", __func__, __LINE__, err);
		exit(-1);
	}
}

t_infos	load_mvc(t_meta meta, t_infos infos)
{
	int		err;
	t_vec3	cam;

	cam = infos.cam_rot;
	load_texture(load_bmp("../textures/water.bmp"), infos);
	infos.proj_idx = glGetUniformLocation(infos.shader_program, "proj");
	infos.view_idx = glGetUniformLocation(infos.shader_program, "view");
	infos.center_idx = glGetUniformLocation(infos.shader_program, "center");
	infos.rot_idx = glGetUniformLocation(infos.shader_program, "obj_rot");
	infos.fade_idx = glGetUniformLocation(infos.shader_program, "fade");
	infos.projection = m_projection(0.1f, 100.0f, 67, (float)WIN_WIDTH / (float)WIN_HEIGTH);
	infos.fade = 0;
	infos.current_fade = 0.0f;
	infos.cam_pos = vec3_create(0, 0, 0);
	infos.cam_rot = vec3_create(0, 0, 0);
	infos.view = m_translation(vec3_create(0, 0, 0));
	infos.center = m_translation(meta.center);
	infos.rotation = m_rotation(quaternion(cam));
	if ((err = glGetError()))
	{
		printf("GL %s, l: %d failed: %x\n", __func__, __LINE__, err);
		exit(-1);
	}
	return (infos);
}

float	update_fade(float current_fade, int fade)
{
	if (fade && current_fade < 1.0f)
		current_fade += 0.01f;
	if (!fade && current_fade > 0.0f)
		current_fade -= 0.01f;
	return (current_fade);
}

t_infos	move_cam(t_infos infos)
{
	infos.cam_rot.y += infos.elapsed_time * 10 * DEG_TO_RAD;
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
		if (infos.events.key.keysym.sym == SDLK_c)
			infos.fade = infos.fade ? 0 : 1;
		printf("cam pos (%f, %f, %f)\n", infos.cam_pos.x, infos.cam_pos.y, infos.cam_pos.z);
		printf("cam rot (%f, %f, %f)\n", infos.cam_rot.x, infos.cam_rot.y, infos.cam_rot.z);
	}
	free(infos.view->data);
	free(infos.view);
	free(infos.rotation->data);
	free(infos.rotation);
	infos.view = m_translation(infos.cam_pos);
	infos.rotation = m_rotation(quaternion(infos.cam_rot));
	infos.current_fade = update_fade(infos.current_fade, infos.fade);
	return (infos);
}
