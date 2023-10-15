#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	srand(time(NULL));

	int n = rand() % 6;

	if (n == 0) {
		printf("   \n");
		printf(" * \n");
		printf("   \n");
		return 0;
	}
	if (n == 1) {
		printf("*  \n");
		printf("   \n");
		printf("  *\n");
		return 0;
	}
	if (n == 2) {
		printf("*  \n");
		printf(" * \n");
		printf("  *\n");
		return 0;
	}
	if (n == 3) {
		printf("* *\n");
		printf("   \n");
		printf("* *\n");
		return 0;
	}
	if (n == 4) {
		printf("* *\n");
		printf(" * \n");
		printf("* *\n");
		return 0;
	}
	if (n == 5) {
		printf("* *\n");
		printf("* *\n");
		printf("* *\n");
		return 0;
	}

	return 0;
}
