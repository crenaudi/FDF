#include "fdf.h"

void	is_error(int i)
{
	if (i == -1)
	{
		perror("Error ");
		exit(EXIT_FAILURE);
	}
	if (i == 0)
		exit(EXIT_SUCCESS);
}