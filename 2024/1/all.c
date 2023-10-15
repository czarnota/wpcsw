#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int calc(void)
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


int dice(void)
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

int rect(void)
{
	int a;
	int b;

	printf("width: ");
	if (scanf("%d", &a) != 1) {
		printf("bad width\n");
		return 1;
	}
	if (a < 0) {
		printf("bad width\n");
		return 1;
	}

	printf("height: ");
	if (scanf("%d", &b) != 1) {
		printf("bad height\n");
		return 1;
	}
	if (b < 0) {
		printf("bad height\n");
		return 1;
	}

	for (int i = 0; i < b; ++i) {
		for (int j = 0; j < a; ++j) {
			printf("*");
		}
		printf("*\n");
	}

	return 0;
}


int main(void)
{
	while (1) {
		char d;
		printf("a. kalkulator\n");
		printf("b. kostka\n");
		printf("c. prostokat\n");
		printf("Podaj opcje: \n");
		if (scanf(" %c", &d) != 1) {
			continue;
		}

		if (d == 'a') {
			calc();
		}

		if (d == 'b') {
			dice();
		}

		if (d == 'c') {
			rect();
		}

	}

	return 0;
}

