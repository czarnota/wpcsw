#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

struct character {
	char c;
	int x;
	int y;
	bool dead;
};

void character_move(struct character *ch, char dir)
{
	if (dir == 'w')
		ch->y = ch->y > 0 ? ch->y - 1 : ch->y;
	if (dir == 's')
		ch->y = ch->y < 4 ? ch->y + 1 : ch->y;
	if (dir == 'a')
		ch->x = ch->x > 0 ? ch->x - 1 : ch->x;
	if (dir == 'd')
		ch->x = ch->x < 4 ? ch->x + 1 : ch->x;
}

void character_random_move(struct character *c)
{
	int x = rand() % 5;
	if (x == 0)
		character_move(c, 'w');
	if (x == 1)
		character_move(c, 's');
	if (x == 2)
		character_move(c, 'a');
	if (x == 3)
		character_move(c, 'd');
}

bool all_dead(const struct character *c, size_t len)
{
	for (size_t i = 0; i < len; ++i)
		if (!c[i].dead)
			return false;
	return true;
}

#define MAP_W 5
#define MAP_H 5

struct frame {
    char cells[MAP_W][MAP_H];
};

void frame_clear(struct frame *frame)
{
	for (int i = 0; i < MAP_H; ++i) {
		for (int j = 0; j < MAP_W; ++j) {
			frame->cells[i][j] = '.';
		}
	}
}

void frame_add(struct frame *frame, struct character *ch)
{
	if (ch->dead)
		return;
	frame->cells[ch->y][ch->x] = ch->c;
}

void frame_draw(const struct frame *frame)
{
	printf("\n");
	for (int i = 0; i < MAP_H; ++i) {
		for (int j = 0; j < MAP_W; ++j) {
			printf("%c", frame->cells[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int main(void)
{
	struct character player = {'&', 0, 0, 0};

	struct character enemies[] = {
		{'x', 0, MAP_H - 1, 0},
		{'y', MAP_W - 1, 0, 0},
		{'z', MAP_W - 1, MAP_W - 1, 0},
	};

	while (1) {
		struct frame frame;
		frame_clear(&frame);

		for (size_t i = 0; i < sizeof(enemies) / sizeof(enemies[0]); ++i)
			frame_add(&frame, &enemies[i]);

		frame_add(&frame, &player);
		frame_draw(&frame);

		char c;
		if (scanf(" %c", &c) == 1)
			character_move(&player, c);


		for (size_t i = 0; i < sizeof(enemies) / sizeof(enemies[0]); ++i)
			character_random_move(&enemies[i]);

		for (size_t i = 0; i < sizeof(enemies) / sizeof(enemies[0]); ++i) {
			if (player.x == enemies[i].x && player.y == enemies[i].y &&
				!enemies[i].dead) {
				enemies[i].dead = true;
			}
		}

		if (all_dead(enemies, sizeof(enemies) / sizeof(enemies[0]))) {
			break;
		}
	}
}



