#include <stdio.h>

int main(void)
{
	int a;
	char c;
	int b;

	if (scanf("%d", &a) != 1) {
		printf("calc: bad number\n");
		return 1;
	}
	if (scanf(" %c", &c) != 1) {
		printf("calc: bad operation\n");
		return 1;
	}
	if (scanf("%d", &b) != 1) {
		printf("calc: bad number\n");
		return 1;
	}

	if (c == '+') {
		printf("%d\n", a + b);
		return 0;
	}
	if (c == '-') {
		printf("%d\n", a - b);
		return 0;
	}
	if (c == '*') {
		printf("%d\n", a * b);
		return 0;
	}
	if (c == '/') {
		if (!b) {
			printf("calc: can't divide by zero\n");
			return 1;
		}

		float result = (float)a / b;
		printf("%f\n", result);
		return 0;
	}

	return 0;
}


