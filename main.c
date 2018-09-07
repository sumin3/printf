#include "holberton.h"
#include <stdio.h>
int main()
{
	char *str;
	int count = 0, num = 23;
	char a ='\0';

	str = "On February 6, 2018, SpaceX launched its Falcon Heavy rocket into space to much fanfare. Never one to misjudge the importance of well-timed publicity, SpaceX founder Elon Musk attached his cherry-red Tesla Roadster to the rocket and shot it into orbit. Images of the car, manned by an intrepid space-exploring mannequin dubbed Starman, were beamed around the world to delighted audiences";

	count = _printf("num %d %c %s\n", num, a, str);
	printf("count %d\n", count);
	return 0;
}
