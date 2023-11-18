#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define ARRAY_SIZE(x) (sizeof(x) / sizeof(*(x)))

const char *cities[] = {
	"Sukhumi", "Kabul", "Tirana", "Algiers", "Luanda", "Yerevan", "Oranjestad",
	"Georgetown", "Canberra", "Vienna", "Baku", "Nassau", "Manama", "Dhaka", "Bridgetown",
	"Minsk", "Brussels", "Belmopan", "Hamilton", "Thimphu", "Sucre", "Sarajevo", "Gaborone",
	"Sofia", "Ouagadougou", "Bujumbura", "Ottawa", "Praia", "Bangui", "Santiago", "Beijing",
	"Moroni", "Avarua", "Zagreb", "Havana", "Willemstad", "Nicosia", "Prague", "Yamoussoukro",
	"Kinshasa", "Copenhagen", "Djibouti", "Roseau", "Dili", "Quito", "Cairo", "Malabo", "Asmara",
	"Tallinn", "Stanley", "Tórshavn", "Palikir", "Suva", "Helsinki", "Paris", "Cayenne", "Papeete",
	"Libreville", "Banjul", "Tbilisi", "Berlin", "Accra", "Gibraltar", "Athens", "Nuuk", "Conakry",
	"Bissau", "Georgetown", "Tegucigalpa", "Budapest", "Reykjavík", "Jakarta", "Tehran", "Baghdad",
	"Dublin", "Douglas", "Jerusalem", "Rome", "Kingston", "Tokyo", "Amman", "Astana", "Nairobi",
	"Tarawa", "Pristina", "Kuwait City", "Bishkek", "Vientiane", "Riga", "Beirut", "Maseru", "Monrovia",
	"Tripoli", "Vaduz", "Vilnius", "Luxembourg", "Skopje", "Antananarivo", "Lilongwe", "Bamako", "Valletta",
	"Majuro", "Nouakchott", "Port Louis", "Chisinau", "Monaco", "Ulaanbaatar", "Podgorica", "Plymouth",
	"Rabat", "Maputo", "Naypyidaw", "Stepanakert", "Windhoek", "Yaren", "Kathmandu", "Amsterdam", "Wellington",
	"Managua", "Niamey", "Abuja", "Alofi", "Kingston", "Pyongyang", "Nicosia", "Belfast", "Saipan", "Oslo",
	"Muscat", "Islamabad", "Ngerulmud", "Jerusalem", "Lima", "Manila", "Adamstown", "Warsaw", "Lisbon",
	"Doha", "Taipei", "Brazzaville", "Bucharest", "Moscow", "Kigali", "Gustavia", "Jamestown", "Basseterre",
	"Castries", "Marigot", "Kingstown", "Apia", "Riyadh", "Edinburgh", "Dakar", "Belgrade", "Victoria",
	"Freetown", "Singapore", "Philipsburg", "Bratislava", "Ljubljana", "Honiara", "Mogadishu", "Hargeisa",
	"Pretoria", "Grytviken", "Seoul", "Tskhinvali", "Juba", "Madrid", "Khartoum", "Paramaribo", "Mbabane",
	"Stockholm", "Bern", "Damascus", "Dushanbe", "Dodoma", "Bangkok", "Tiraspol", "Tunis", "Ankara",
	"Ashgabat", "Funafuti", "Kampala", "Kyiv", "Abu Dhabi", "London", "Washington", "Montevideo", "Tashkent",
	"Vatican", "Caracas", "Hanoi", "Cardiff", "Lusaka", "Harare",
};

const char *choice(const char **cities, size_t cities_len)
{
	return cities[rand() % cities_len];
}

void strtolower(char *s)
{
	size_t len = strlen(s);
	for (size_t i = 0; i < len; ++i) {
		int c = tolower(s[i]);
		if (c == EOF)
			continue;
		s[i] = (char)c;
	}
}

void draw_hangman(int mistakes)
{
	if (mistakes == 0) {
		printf("  .----.  \n");
		printf("       |  \n");
		printf("       |  \n");
		printf("       |  \n");
		printf("      / \\ \n");
	}
	if (mistakes == 1) {
		printf("  .----.  \n");
		printf("  O    |  \n");
		printf("       |  \n");
		printf("       |  \n");
		printf("      / \\ \n");
	}
	if (mistakes == 2) {
		printf("  .----. \n");
		printf("  O    | \n");
		printf("   \\   | \n");
		printf("       | \n");
		printf("      / \\\n");
	}
	if (mistakes == 3) {
		printf("  .----. \n");
		printf("  O    | \n");
		printf("  |\\   | \n");
		printf("       | \n");
		printf("      / \\\n");
	}
	if (mistakes == 4) {
		printf("  .----. \n");
		printf("  O    | \n");
		printf(" /|\\   | \n");
		printf("       | \n");
		printf("      / \\\n");
	}
	if (mistakes == 5) {
		printf("  .----. \n");
		printf("  O    | \n");
		printf(" /|\\   | \n");
		printf(" /     | \n");
		printf("      / \\\n");
	}
	if (mistakes == 6) {
		printf("  .----. \n");
		printf("  O    |\n");
		printf(" /|\\   |\n");
		printf(" / \\   |\n");
		printf("      / \\\n");
	}
	if (mistakes == 6) {
		printf("  .----. \n");
		printf("  O    |\n");
		printf(" /|\\   |\n");
		printf(" / \\   |\n");
		printf("      / \\\n");
	}
}

int main(void)
{
	srand(time(NULL));
	rand();
	rand();

	const char *chosen = choice(cities, ARRAY_SIZE(cities));
	size_t chosen_len = strlen(chosen);
	char buf[64] = {0};
	int mistakes = 0;
	const int max_mistakes = 6;

	memset(buf, '_', strlen(chosen));

	while (1) {
		draw_hangman(mistakes);

		printf("\n");
		printf("%s\n", buf);
		printf("\n");
		printf(">>> ");

		char line[64];
		if (!fgets(line, sizeof(line), stdin))
			return 1;

		size_t len = strlen(line);
		if (len == 0)
			return 1;

		line[len - 1] = 0;
		len--;

		strtolower(line);

		if (len == 1) {
			bool found = false;
			for (size_t i = 0; i < chosen_len; ++i) {
				if (chosen[i] == line[0]) {
					buf[i] = line[0];
					found = true;
				}
			}

			if (!found)
				mistakes++;
		}

		if (len > 1) {
			if (strcmp(line, chosen) == 0)
				snprintf(buf, sizeof(buf), "%s", chosen);
			else
				mistakes++;
		}

		if (mistakes == max_mistakes) {
			draw_hangman(mistakes);
			printf("You lost! (%s)\n", chosen);
			break;
		}

		if (strcmp(buf, chosen) == 0) {
			draw_hangman(mistakes);
			printf("You won! (%s)\n", chosen);
			break;
		}

	}

	return 0;
}
