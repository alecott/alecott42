#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int		main(int argc, char **argv)
{
	int fd;
	char *line;
	int ret;

	fd = open(argv[1], O_RDONLY);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		printf("%d - ", ret);
		printf("%s\n", line);
	}
	printf("END = %d", ret);
	free(line);
	while (1);
	return (0);
}
