/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelforg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:20:20 by mdelforg          #+#    #+#             */
/*   Updated: 2022/02/23 13:35:57 by mdelforg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_map_check_mid_edges(char **map)
{
	int	i;

	i = 1;
	while (map[i])
	{
		if (map[i][0] != '1' || map[i][ft_strlen(map[i]) - 1] != '1')
			ft_map_error("map needs to be enclosed by '1'", map);
		i++;
	}
	return ;
}

void	ft_map_check_edges(char **map)
{
	int	j;

	j = 0;
	while (map[0][j])
	{
		if (map[0][j] != '1')
			ft_map_error("map needs to be enclosed by '1'", map);
		j++;
	}
	j = 0;
	while (map[ft_map_size(map) - 1][j])
	{
		if (map[ft_map_size(map) - 1][j] != '1')
			ft_map_error("map needs to be enclosed by '1'", map);
		j++;
	}
	ft_map_check_mid_edges(map);
	return ;
}

void	ft_map_check_size(char **map)
{
	int	i;
	int	map_len;

	if (!(ft_map_size(map) < 3 || !(ft_strlen(map[0]) < 3)))
		ft_map_error("map size is too small", map);
	if (ft_map_size(map) > 47 || ft_strlen(map[0]) > 90)
		ft_map_error("map size too is large", map);
	map_len = ft_strlen(map[0]);
	i = 1;
	while (map[i])
	{
		if ((int)ft_strlen(map[i]) != map_len)
			ft_map_error("map must be rectangular", map);
		i++;
	}
	return ;
}

void	ft_map_check_char(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!ft_strchr(MAP_ARG, map[i][j]))
				ft_map_error("map has wrong character", map);
			j++;
		}
		i++;
	}
	return ;
}

void	ft_map_check(char **map)
{
	ft_map_check_char(map);
	ft_map_check_size(map);
	ft_map_check_edges(map);
	ft_map_check_elem(map);
}
