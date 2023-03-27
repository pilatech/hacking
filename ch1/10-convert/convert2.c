#include <stdio.h>
#include <stdlib.h>

void usage(char *program_name) {
printf("Usage: %s <message> <# of time to repeat>\n", program_name);
exit(1);
}

int main(int argc, char *argv[]) {
int i, count;

// if (argc < 3) // if fewer than 3 args used
//	usage(argv[0]); // display usage message and exit
count = atoi(argv[2]); // conver the 2nd arg into an int
printf("Repeating %d times..\n", count);

for (i = 0; i < count; i++)
	printf("%3d - %s\n", i + 1, argv[1]); // print the 1st arg
}
