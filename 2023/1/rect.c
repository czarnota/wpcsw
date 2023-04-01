#include <stdio.h>
#include <stdint.h>

int main(void)
{
	int w;
	if (scanf("%d", &w) != 1)
		return 1;

	int h;
	if (scanf("%d", &h) != 1)
		return 1;

	for (int row = 0; row < h; ++row) {
		for (int column = 0; column < w; ++column) {
			printf("*");
		}
		printf("\n");
	}

	return 0;
}
