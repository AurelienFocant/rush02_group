
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main (int argc, char **argv)
{
	int fd;
	char buf;
	int	char_read;
	char key[1000][1000];
	char value[1000][1000];
	int i;
	int j;


	fd = open( argv[1], O_RDONLY);

	i = 0;
	j = 0;
	while ((char_read = read(fd, &buf, 1)) && buf != ':' && buf != ' ')
	{
	//	j = 0;
	//	while (buf != ':')
		//	if(buf != ' ')
		//	{
				key[i][j] = buf;
				j++;
		//	}
//		key[i][j] = '\0';
	//	j = 0;
	//	while (buf != '\n')
	}
	key[i][j] = '\0';

	while ((char_read = read(fd, &buf, 1)) && buf != '\n' && buf != ' ')
	{

	//		if (buf != ' ')
	//		{
				value[i][j] = buf;
				j++;
	//		}
	//	value[i][j] = '\0';
	//	i++;
	}
	value[i][j] = '\0';

	i = 0;
	while (i < 31)
	{
		printf("%s", key[i]);
		i++;
	}

/*	while ((char_read = read(fd, buf, 1)))
	{
		while (buf[char_read] != ' ' && buf[char_read] != ':')
			{
				buf[char_read] = '\0';
				printf("%s", buf);
			}
	}

	while ((char_read = read(fd, &buf, 1)))
	{
	//	buf[char_read] = '\0';
		printf("%c", buf);
	}*/
	return 0;
}


