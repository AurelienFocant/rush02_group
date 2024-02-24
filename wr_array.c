
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main (int argc, char **argv)
{
	int fd;
	char c;
	int index;
	char key[1000][1000];
	char value[1000];
	int i;
	int j;


	fd = open(argv[1], O_RDONLY);

	j = 0;

	while ((index = read(fd, &c, 1)))
	{
		if (c != ':')
		{
			if (c != ' ')
			{
				value[j] = c;
				j++;
			}
		}
	}




/*	i = 0;
	while (i < 31)
	{
		printf("%s", key[i]);
		i++;
	}
	i = 0;
	while (i < 31)
	{*/
		printf("%s", value);
	//	i++;
//	}
	return 0;
}

