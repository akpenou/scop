/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akpenou <akpenou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 14:31:05 by akpenou           #+#    #+#             */
/*   Updated: 2017/04/05 14:37:58 by akpenou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

# include <stdlib.h>

typedef struct			s_lst
{
	struct s_lst		*next;
	void				*data;
}						t_lst;

int			lstlen(t_lst *lst);
t_lst		*push_front(void *data, t_lst **lst);

#endif
