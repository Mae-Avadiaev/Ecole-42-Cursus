#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

int	ft_strlen(char *c);
char	*ft_strcpy(char *destination, const char *source);
int	ft_strcmp(const char *s1, const char *s2);
int	ft_write(int handle, void *buf, int count);
int	ft_read(int fd, void *buf, unsigned int count);
char 	*ft_strdup(char *c);

// gcc main.c -L. -lasm

int main(void)
{
	printf("----------ft_strlen----------\n");

	printf("%d\n", ft_strlen(""));
	printf("%d\n", ft_strlen("All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy"));

	printf("----------ft_strcpy----------\n");

	char *a = malloc(1 * sizeof(char));
	char *b = malloc(2346 * sizeof(char));
	printf("%s\n", ft_strcpy(a, ""));
	printf("%s\n", ft_strcpy(b, "All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy"));
	free(a);
	free(b);

	printf("----------ft_strcmp----------\n");

	printf("%d\n", ft_strcmp("", ""));
	printf("%d\n", ft_strcmp("", "Shining"));
	printf("%d\n", ft_strcmp("Shining", ""));
	printf("%d\n", ft_strcmp("Shining", "Shining"));
	printf("%d\n", ft_strcmp("Jack", "Wendy"));

	printf("----------ft_write----------\n");
	
	ft_write(1, "Here's Johnny!\n", 15);
	int fd = open("Stanley.txt", O_WRONLY | O_CREAT);
	ft_write(fd, "Here's Johnny!\n", 15);
	fd = -1;
	ft_write(fd, "Here's Johnny!\n", 15);
	fd = 42;
	ft_write(fd, "Here's Johnny!\n", 15);
	
	printf("----------ft_read----------\n");
	
	char	c[1980];
	char	d[1980];
	char	e[1980];
	char	f[1980];

	ft_read(1, c, 1980);
	printf("%s\n", c);
	fd = open("fact.txt", O_RDONLY);
	ft_read(fd, d, 1980);
	printf("%s\n", d);
	fd = -1;
	printf("%d\n", ft_read(fd, e, 1980));
	fd = 42;
	printf("%d\n", ft_read(fd, f, 1980));
	
	//printf("%s\n", ft_strdup(a));
	
	printf("----------ft_strdup----------\n");
	
	printf("%s\n", ft_strdup(""));
	printf("%s\n", ft_strdup("All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy \
				All work and no play makes Jack a dull boy"));
	return (0);
}
