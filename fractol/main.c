#include "fractol.h"

int	main(int argc, char **argv)
{
	t_fractal	fractal;

	if (argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10))
	{
		fractal.name = argv[1];
		fractal.julia_x = 0;
		fractal.julia_y = 0;
	}
	else if (argc == 4 && !ft_strncmp(argv[1], "julia", 5))
	{
		fractal.name = argv[1];
		fractal.julia_x = atodbl(argv[2]);
		fractal.julia_y = atodbl(argv[3]);
	}
	else
	{
		putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	fractal_init(&fractal);
	fractal_render(&fractal);
	mlx_loop(fractal.mlx_connection);
}
