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

void	print_all(t_game *game)
{
	int j, i = 0;
	while (i <= game->map.allocated_rows - 2)
	{
		j = 0;
		while (game->map.coords[i][j].type != '\n')
		{
			if (game->map.coords[i][j].x < 0)
				printf("(%i|", game->map.coords[i][j].x);
			else
				printf("(%i |", game->map.coords[i][j].x);
			if (game->map.coords[i][j].y < 0)
				printf("%i)", game->map.coords[i][j].y);
			else 
				printf(" %i)", game->map.coords[i][j].y);
			j++;
		}
		printf("\n");
		i++;
	}
}
void	print_playable_field(t_game *game)
{
	int j, i = 0;
	while (i <= game->map.allocated_rows - 2)
	{
		j = 0;
		while (game->map.coords[i][j].type != '\n')
		{
			if (game->map.coords[i][j].x < 0 || game->map.coords[i][j].y < 0 \
				|| game->map.coords[i][j].y == game->map.allocated_rows - 3 \
					|| game->map.coords[i][j].x == game->map.map_length)
			{
				j++; 
				continue ;
			}
			printf("(%i |", game->map.coords[i][j].x);
			printf(" %i)", game->map.coords[i][j].y);
			j++;
		}
		printf("\n");
		i++;
	}
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
	print_playable_field(game);
	i = 0;
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
