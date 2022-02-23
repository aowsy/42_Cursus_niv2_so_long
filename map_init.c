/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelforg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:18:58 by mdelforg          #+#    #+#             */
/*   Updated: 2022/02/23 13:35:23 by mdelforg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_map_size(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

char	**ft_str_in_tab(char *str, char **map)
{
	int		i;
	int		size_map;
	char	**new_map;

	size_map = ft_map_size(map);
	new_map = (char **)malloc(sizeof(char *) * (size_map + 2));
	if (!new_map)
		ft_error_tab_str("malloc error", str, map);
	i = 0;
	while (i < size_map)
	{
		new_map[i] = ft_strdup(map[i]);
		if (!new_map[i])
			ft_error_tab_str("malloc error", str, map);
		i++;
	}
	new_map[i] = ft_strdup(str);
	if (!new_map[i])
		ft_error_tab_str("malloc error", str, map);
	new_map[i + 1] = NULL;
	return (new_map);
}

char	**ft_create_map(int fd)
{
	char	*str;
	char	**map;

	map = (char **)malloc(sizeof(char *) * 1);
	if (!map)
		ft_error("malloc error");
	map[0] = NULL;
	str = get_next_line(fd);
	if (!str)
		ft_error_tab_str("empty file", NULL, map);
	while (str)
	{
		map = ft_str_in_tab(str, map);
		free(str);
		str = get_next_line(fd);
	}
	free(str);
	return (map);
}

char	**ft_map_init(char *file)
{
	char	**map;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_error("wrong fd");
	map = ft_create_map(fd);
	close(fd);
	ft_map_check(map);
	return (map);
}
