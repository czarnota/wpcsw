# Wstęp do programowania w C w systemach wbudowanych

## Zadanie 1

Napisz program który po uruchomieniu wyświeli twoje imię i nazwisko.
Skompiluj go za pomocą `gcc` i uruchom z terminala.

```c
$ ./a.out
Jan Kowalski
```

## Rozwiązanie 1

```c
#include <stdio.h>

int main(void)
{
	printf("Jan Kowalski\n"); 
	return 0;
}
```

Znak `\n` to znak nowej linii (czyli "enter").

Następnie:

```console
$ gcc main.c -o imieinazwisko
$ ./imieinazwisko
Jak Kowalski
```

## Zadanie 2

Napisz program który przyjmuje 2 argumenty: imie i nazwisko, a następnie
je wyświetla. 

```c
$ ./a.out Przemyslaw Czarnota
Przemyslaw Czarnota
$ echo $?
0
```

Podanie niepoprawnej liczby argumentów, powinno skutkować
wyświetleniem błędu na standardowy strumień błędów oraz zwróceniem
kodu błędu różnego od 0.

```
$ ./a.out Za duzo argumentow >/dev/null
error: wrong number of arguments
$ echo $?
1
```

## Rozwiązanie 2

```c
#include <stdio.h>

int main(int argc, char **argv)
{
	if (argc != 3) {
		fprintf(stderr, "error: wrong number of arguments\n");
		return 1;
	}

	printf("%s %s\n", argv[1], argv[2]);
	return 0;
}
```

Gdy uruchamiamy `./program Jan Kowalski`, system operacyjny jako drugi argument
funkcji `main()` przekazuje następującą tablicę ciągów znaków:

```c
char *argv[] = { "./program", "Jan", "Kowalski" };
```

Warto zauważyć że wywołanie systemowe `execvp` przyjmuje podobny argument :)

## Zadanie 3

Napisz program, który będzie odczytywał ze standardowego wejścia
liczby do momentu wystąpienia wejścia, które nie jest liczbą lub
końca strumienia i na końcu wyświetli ich średnią arytmetyczną.

```c
$ ./a.out
1
2
3            <--- tu wcisnąłem Ctrl-d
2.000000
```

Przydatne funkcje:

- `scanf()` - odczytuje zmienne ze standardowego wejścia

Skrót klawiaturowy `Ctrl-d`, powoduje wysłanie znaku końca pliku.

## Rozwiązanie 3

```c
#include <stdio.h>

int main(void)
{
	int sum = 0;
	int count = 0;

	while (1) {
		int number;

		int num = scanf("%d", &number);
		if (num != 1)
			break;
		sum += number;
		count++;
	}

	printf("%f\n", (float)sum / count);
	return 0;
}
```

## Rozwiązanie 3 - alternatywne

```c
#include <stdio.h>

int main(void)
{
	int sum = 0, count = 0, number;

	while (scanf("%d", &number) == 1) {
		sum += number;
		count++;
	}

	printf("%f\n", (float)sum / count);
	return 0;
}
```

## Zadanie 4

Napisz program, który będzie odczytywał liczby ze standardowego wejścia
i wypisze je w odwrotnej kolejności.

```c
$ seq 1 3 | ./a.out
3
2
1
```

Program powinien działać maksymalnie dla 4096 liczb całkowitych.
Dalsze liczby są odrzucane.

Do rozwiązania będzie potrzebne wykorzystanie tablicy. Na przykład
```c
int tablica[4096];
```

## Rozwiązanie 4

```c
#include <stdio.h>

int main(void)
{
	int numbers[4096];
	int count = 0;
	int number;
	/* Dopóki liczby są na standardowym wejściu */
	while (1 == scanf("%d", &number)) {
		if (count >= 4096)
			break;
		numbers[count] = number;
		count++;
	}

	for (int i = count - 1; i >= 0; --i)
		printf("%d\n", numbers[i]);

	return 0; 
}
```

## Zadanie 5

Napisz program który wyświetli wszystkie argumenty przekazane do programu
```c
$ ./a.out a b d e foo bar
a
b
d
e
foo
bar
```

## Zadanie 6

Napisz program, który będzie odczytywał ze standardowego wejścia
liczby do momentu wystąpienia wejścia, które nie jest liczbą lub
końca strumienia i na końcu wyświetli najmniejszą liczbę. Program powinien
też działać dla liczb ujemnych.

```c
$ ./a.out
1
-2
2
-1
-2            <--- tu wcisnąłem Ctrl-d co powoduje wyświetlenie wyniku
```

Przydatne funkcje:

- `scanf()` - odczytuje zmienne ze standardowego wejścia

## Zadanie 7

Rozwiń program z poprzedniego zadania, tak aby działał
dla dowolnej ilości liczb.

Przydatne funkcje:

- `malloc()` - alokuje pamięć
- `realloc()` - realokuje pamięć
- `free()` - zwalnia pamięć
- `memcpy()` - kopiuje dane

Sprawdź czy nie ma wycieków pamięci:

```console
$ valgrind --leak-check=full --show-leak-kinds=all ./program
```

```
$ gcc main.c -fsanitize=address -o program
$ ./program
```

## Zadanie 8

Napisz funkcję która będzie sortować tablicę liczb typu `int` algorytmem
sortowania bąbelkowego. Pseudokod:
```
sort(items, len) {
    for (i = 0; i < len - 1; j++) {
        for (j = 0; j < len - 1 - i; j++) {
            if (items[j] > items[j + 1])
                swap(items[j], items[j + 1]);
        }
    }
}
```

Wykorzystanie:

```c
int n[] = {8, 3, 4, 5, 6, 7, 8};
sort(n, 7);
```

## Zadanie 9

Napisz funkcję która będzie sortować tablicę liczby typu `float` algorytmem
sortowania bąbelkowego. Dodaj do niej parametr określający porządek sortowania.

```c
void sort_float(float *items, unsigned int len, bool reversed);
```

Wykorzystanie:

```c
float n[] = {8.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f};
sort_float(n, 7, false);
```

## Zadanie 10

Zdefiniuj makro `ARRAY_SIZE()`, które pozwoli obliczać liczbę elementów
w tablicy w trakcie kompilacji (jeżeli rozmiar jest znany w trakcie kompilacji)

```c
int n[] = {8, 3, 4, 5, 6, 7, 8};
sort(n, ARRAY_SIZE(n));
```

```c
float n[] = {8.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f};
sort_float(n, ARRAY_SIZE(n));
```

Przydatny operator:

- `sizeof(x)` - podaje rozmiar wyrażenia

## Zadanie 11

Napisz generyczną funkcję `sort()`, która może posortować tablicę
dowolnego typu:

```c
void sort(void *ptr, unsigned int count, unsigned int element_size,
          int (*comparator)(const void *a, const void *b));
```

```c
int compare_double(const void *__a, const void *__b)
{
    const double *a = __a, *b == __b;
    if (a == b)
        return 0;
    return a < b ? -1 : 1;
}
```

```c
double items[] = { 2.0f, 8.0f, -1.0f, 3.0f };
sort(items, ARRAY_SIZE(items), sizeof(items[0]), compare_double);
```
Funkcja powinna dawać taki sam efekt jak `qsort()`.

