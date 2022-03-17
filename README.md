# Wstęp do programowania w C w systemach wbudowanych

## Zadanie 1

Napisz program który po uruchomieniu wyświeli twoje imię i nazwisko.
Skompiluj go za pomocą `gcc` i uruchom z terminala.

```c
$ ./a.out
Przemysław Czarnota
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
error: too many arguments
$ echo $?
1
```

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

## Zadanie 5

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

## Zadanie 6

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

## Zadanie 7

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

## Zadanie 8

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

## Zadanie 9

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
