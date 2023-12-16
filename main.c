#include <stdio.h>
#include <fcntl.h>
# include "get_next_line.h"
int main()
{
	int fd = open("test.txt", O_RDONLY);
	char *texto;
	if (fd == -1)
		return (1);
	texto = get_next_line(fd);
while (texto != NULL && texto)
	{
		printf("%s", texto);
		free(texto);
		texto = get_next_line(fd);
	}
	free(texto);
	return (0);
}