/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouger <trouger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 11:04:51 by trouger           #+#    #+#             */
/*   Updated: 2021/03/23 11:04:52 by trouger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new1;

	if (!(new1 = malloc(sizeof(t_list))))
		return (NULL);
	new1->content = content;
	new1->next = NULL;
	return (new1);
}
