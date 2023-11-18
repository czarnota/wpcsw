#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int main(void)
{
	const int rock = 0;
	const int paper = 1;
	const int scissors = 2;

	srand(time(NULL));

	int p1 = rand() % 3;
	int p2 = rand() % 3;

	if (p1 == rock)
		printf("p1: rock\n");
	if (p1 == paper)
		printf("p1: paper\n");
	if (p1 == scissors)
		printf("p1: scissors\n");

	if (p2 == rock)
		printf("p2: rock\n");
	if (p2 == paper)
		printf("p2: paper\n");
	if (p2 == scissors)
		printf("p2: scissors\n");

	if (p1 == p2) {
		printf("result: draw\n");
		return 0;
	}

	if (p1 == rock) {
		if (p2 == scissors)
			printf("winner: p1\n");
		else
			printf("winner: p2\n");
	}
	if (p1 == paper) {
		if (p2 == rock)
			printf("winner: p1\n");
		else
			printf("winner: p2\n");
	}
	if (p1 == scissors) {
		if (p2 == paper)
			printf("winner: p1\n");
		else
			printf("winner: p2\n");
	}

	return 0;
}
