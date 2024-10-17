/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c		                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ****** <******@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 12:33:17 by ******           #+#    #+#              */
/*   Updated: 2024/10/11 13:09:41 by ******           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

static int	ft_check_extension(const char *argv);

void ft_print_params(t_game *game)
{
	printf(GREEN"\nNorth Wall: %s\n", game->walls.north);
	printf("South Wall: %s\n", game->walls.south);
	printf("East Wall: %s\n", game->walls.east);
	printf("West Wall: %s\n", game->walls.west);
	printf("Floor Color: %i %i %i\n", game->walls.floor.r, game->walls.floor.g, game->walls.floor.b);
	printf("Ceiling Color: %i %i %i\n"RESET"\n", game->walls.ceiling.r, game->walls.ceiling.g, game->walls.ceiling.b);
}

void ft_print_map(t_game *game)
{
	int i = 0;
	int j = 0;
	while (i <= game->map.allocated_rows - 2)
	{
		j = 0;
		while (game->map.coords[i][j].type != '\n')
		{
			printf("%c", game->map.coords[i][j].type);
			j++;
		}
		printf("\n");
		i++;
	}
	i = 0;
	while (i <= game->map.allocated_rows - 2)
	{
		j = 0;
		while (game->map.coords[i][j].type != '\n')
		{
			printf("(%i | %i) ", game->map.coords[i][j].x, game->map.coords[i][j].y);
			j++;
		}
		printf("\n");
		i++;
	}
	printf("\n");
	printf("Point Zero: C(%i | %i)\n\n", game->map.point_zero->x, game->map.point_zero->y);
	printf("Top Left: (%i | %i)\n", game->map.top_l->x, game->map.top_l->y);
	printf("Top Right: (%i | %i)\n", game->map.top_r->x, game->map.top_r->y);
	printf("Bottom Left: (%i | %i)\n", game->map.bottom_l->x, game->map.bottom_l->y);
	printf("Bottom Right: (%i | %i)\n", game->map.bottom_r->x, game->map.bottom_r->y);
	ft_print_params(game);
}

int main(int argc, char **argv)
{
	t_game	game;
	
	ft_set_zero(&game);
	if (argc != 2)
		print_error("Error\nWrong number of arguments!\n", &game, 1);
	if (!(ft_check_extension(argv[1])))
	{
		printf("Wrong file extension!\n");
		exit(1);
	}
	ft_map_parsing(argv[1], &game); //doesnt need if and exit because the error print fucntion exits
	// if (argc == 2 && ft_check_extension(argv[1]))
	// {
	ft_print_map(&game);	//just for testing purposes
	ft_init_game(&game);
	mlx_loop(game.mlx.mlx);
	ft_free_map(&game, 0);	//0 is the return value to save lines (you can put the function into return statement that way)//not sure if this is even nessecary tbh
	return (0);
}

static int	ft_check_extension(const char *argv)
{
	char	*ext;

	ext = ft_strrchr(argv, '.');
	if (ext)
		return (ft_strcmp(ext, ".cub") == 0);
	return (0);
}
