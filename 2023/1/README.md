# Wstęp do programowania w C w systemach wbudowanych

## Szkielet programu

Program typu "Witaj świecie" można napisać w języku C w następujący sposób:

```c
/* Wklejenie zawartości pliku naglówkowego stdio.h, potrzebne aby skorzystać
   z funkcji printf(). */
#include <stdio.h>

/* Definicja funkcji main() - funkcji wywoływanej
   jako pierwszej po uruchomieniu programu */
int main(void)
{
    /* Wywołanie funkcji printf() z ciągiem znaków "Hello world\n"
       podanym jako pierwszy argument */
    printf("Hello world\n");

    /* Zwrócenie kodu błędu do systemu operacyjnego.
       Kod 0 oznacza, że nie wystąpił żaden błąd */
    return 0;
}
```

## Kompilacja programu

Kod źródłowy umieszczony w pliku `plik.c` można skompilować za pomocą kompilatora GCC.
W tym celu należy wpisać w terminalu:
```bash
$ gcc plik.c -o nazwa
```

W ten sposób kod źródłowy zostanie przekształcony w plik wykonywalny o nazwie
`nazwa`. Można go uruchomić w następujący sposób:

```bash
$ ./nazwa
Hello world
```

## Zadanie 1

Napisz program który po uruchomieniu wyświeli **twoje** imię i nazwisko.
Skompiluj go za pomocą `gcc` i uruchom z terminala.

```c
$ ./twojprogram
Jan Kowalski
```

# Zmienne i typy danych

## Zmienne - deklaracja i inicjalizacja

Zmienne reprezentują komórki pamięci w których przechowywane są dane.

```c
#include <stdio.h>

int main(void)
{
    int apples = 10;

    unsigned int oranges;
    oranges = 10;

    return 0;
}
```

## Zmienne - wykonywanie obliczeń
Zmienne wykorzystujemy do tego aby zapisywać wyniki obliczeń.

```c
#include <stdio.h>

int main(void)
{
    int birth_year = 1993;
    int current_year = 2023;
    int age = current_year - birth_year;
    printf("wiek to: %d\n", age);

    float time = 10.0f;
    float distance = 5.0f;
    float speed = distance / time;
    printf("szybkosc to %f\n", speed);

    return 0;
}
```

## Wypisywanie wartości zmiennych

Do wypisywania zmiennych służy funkcja printf. Jako pierwszy argument przyjmuje
ona "format string", który określa typy zmiennych i miejsca, w których zostaną
one wypisane.

```c
int temperature = -10;
printf("temperatura: %d\n", temperatura);

unsigned int money = 10000;
printf("bilans konta: %u\n", money);

float interest_rate = 0.08f;
printf("oprocentowanie: %f\n", interest_rate);

printf("temperatura %d bilans %u oprocentowanie %f\n", temperature,
       interest_rate, money);
```

## Zadanie 2

Napisz program, który dla prostokąta o bokach 57 i 13:

- wyświetli jego pole
- wyświetli jego obwód
- wyświetli długość jego przekątnej

## Zmienne - sekcja danych, bss i stos

Zmienne mogą być zadeklarowana w różnych obszarach pamięci:

```c
int global_x = 34; // zmienna zinicjalizowana w sekcji danych

int global_y; // zmienna w sekcji BSS - zainicjalizowana 0

int main(void)
{
    int x; // zmienna na stosie - początkowa wartość niezdefiniowana
    static int y; // zmienna w sekcji BSS
    static int z = 32; // zmienna w sekcji danych

    return 0
}
```

## Typy danych - liczby całkowite

Typ zmiennej określa zbiór wartości jaki może ona przyjmować oraz określa jej rozmiar
w pamięci. 

```c
#include <stdio.h>

int main(void)
{
    char a = 'X';              // dokładnie 1 bajt [-127; 127]
    short b = -30000;          // minimum 2 bajty  [-32767; 32767]
    int c = 30000;             // minimum 2 bajty  [-32767; 32767]
    long d = -3000000;         // minimum 4 bajty  [-2147483648; 2147483647]
    long long e = 32147483648; // minimum 8 bajtów [-9223372036854775807; 9223372036854775807]

    printf("%c %d %d %l %ll", a, b, c, d, e);

    return 0;
}
```

## Typy danych - liczby całkowite bez znaku

Dodanie słowa `unsigned` to nazwy typu liczby całkowitej powoduje, że będzie ona
przechowywać tylko dodatnie wartości.

```c
#include <stdio.h>

int main(void)
{
    unsigned char a = 234;             // dokładnie 1 bajt [0; 255]
    unsigned short b = 60000;          // minimum 2 bajty  [0; 65536]
    unsigned int c = 60000;            // minimum 2 bajty  [0; 65536]
    unsigned long d = 70000;           // minimum 4 bajty  [0; 4294967295]
    unsigned long long e = 4294967295; // minimum 8 bajtów [0; 18446744073709551615]

    printf("%u %u %u %lu %llu\n", a, b, c, d, e);

    return 0;
}
```

## Typy danych - liczby zmiennoprzecinkowe

```c
#include <stdio.h>

int main(void)
{
    float a = 0.121371f;
    double b = 0.2132;

    printf("%f %d\n", a, b);

    return 0;
}
```

## Typy danych - inne

Do przechowywania wartości logicznych można wykorzystać `bool`, natomiast do
przechowywania rozmiarów `size_t`.

```c
#include <stdbool.h> // potrzebny dla bool
#include <stddef.h>  // potrzebny dla size_t

int main(void)
{
    bool a = true; // dokładnie 1 bajt {false, true}
    size_t b = 0;  // tyle bajtów, ile potrzeba do zapisania rozmiaru dowolnego obiektu

    printf("%d %zu\n", a, b);

    return 0;
}
```

## Zadanie 3

Napisz program który wypisze rozmiary następujących typów danych:

- `char`, `unsigned char`
- `short`, `unsigned short`
- `int`, `unsigned int`
- `long`, `unsigned int`
- `long long`, `unsigned int`
- `bool`, `size_t`

Sprawdzić rozmiar zmiennej można za pomocą operatora `sizeof()`. Operator `sizeof()`
zwraca wartość typu `size_t`, do której wypisania należy użyć specyfikatora `%zu`.

```c
printf("%zu\n", sizeof(char));
```

# Instrukcje warunkowe

## Instrukcja `if`

Jedną z podstawowych instrukcji służących do sterowania programem jest `if`.

```c
if (wyrazenie) {
    printf("prawda\n");   // wykona się gdy wyrażenie to prawda, czyli wartość różna od zera 
} else {
    printf("fałsz\n");    // wykona się gdy wyrażenie to fałsz, czyli wartość równa zero
}
```
```c
int b = 0;
if (b) {
    printf("foo\n");      // nie wykona się, ponieważ b jest fałszem
}                         // "else" jest opcjonalne

if (b >= 0)               // gdy jest tylko jedna instrukcja, można pominąć {}
    printf("baz\n");      
else if (b == -1)         // możemy zagnieżdzać "if", w celu obsługi kilku przypadków
    printf("bad\n");
else if (b == -2)
    printf("bak\n");          
else
    printf("bax\n");

```
## Instrukcja `if` - przykład - rzut monetą
Przykład programu symulującego rzut monetą:
```c
#include <stdio.h>   // printf()
#include <stdlib.h>  // rand()
#include <time.h>    // time()

int main(void)
{
    srand(time(NULL));     // ustawiamy ziarno dla generatora liczb losowych
    int number = rand();   // rand() zwraca wartość od 0 do RAND_MAX (przynajmniej 32767)
    if (number % 2)        // jeżeli reszta z dzielenia przez 2 jest rózna od 0
        printf("heads\n");
    else
        printf("tails\n");
    return 0;
}
```

```
$ ./coin_toss
heads
$ ./coin_toss
tails
```

## Instrukcja `switch`

Instrukcja `switch` pozwala na selekcję gałęzi kodu w zależności od wartości wyrażenia.

```c
int option = 1;
switch (day) {
case 0:
    printf("option 0\n");
    break;
case 1:
    printf("option 1\n");
    break;
case 2:
    printf("option 2\n");
    break;
default:
    printf("default\n");
    break;
}
```
```bash
$ ./program
option 1
```

## Instrukcja `switch` - słowo kluczowe `break`

Switch powoduje przeskok do etykiety `case` dla odpowiedniej wartości.
Jeżeli nie użyjemy `break`, wykonywanie będzie miało miejsce dalej.

```c
int option = 1;
switch (day) {
case 0:
    printf("option 0\n");
case 1:
    printf("option 1\n");
case 2:
    printf("option 2\n");
default:
    printf("default\n");
}
```
```bash
$ ./program
option 1
option 2
default
```

## Instrukcja `switch` vs `if`

Porównanie instrukcji `switch` z `if`:

```c
int animal = 1;
switch (animal) {
case 0:
    printf("dog\n");
    break;
case 1:
    printf("cat\n");
    break;
case 2:
    printf("rabbit\n");
    break;
}
```

```c
int animal = 1;
if (animal == 0)
    printf("dog\n");
else if (animal == 1)
    printf("cat\n");
else if (animal == 2)
    printf("rabbit\n");
```

## Zadanie 4

Napisz program symulujący rzut kostką sześcienną. Przykład działania:

```bash
$ ./cube

 *


$ ./cube
* *
* *
* *

$ ./cube
* *
 * 
* *

```

# Wczytywanie wejścia

## Funkcja scanf()

Funkcja `scanf()` pozwala na odczytywanie danych ze standardowego wejścia

```c
#include <stdio.h>

int main(void)
{
    int age;

    printf("Ile masz lat?: ");
    scanf("%d", &age);
    printf("Masz %d lat!\n");

    return 0;
}
```

```bash
$ ./program
Ile masz lat?: 29
Masz 29 lat!
```

## Funkcja scanf() - format

Funkcja `scanf()` odczytuje standardowe wejście zgodnie z "formatem" podanym
jako pierwszy argument. Przykładowe wejście:
```
xyz   abc 1 2
```
```c
scanf("xyz   abc %d %d", &x, &y); // x = 1, y = 2
```
```c
scanf("xyz abc %d %d", &x, &y);   // x = 1, y = 2 (biały znak oznacza "jeden lub więcej")
```
```c
scanf("xyz abc%d%d", &x, &y);     // x = 1, y = 2 (% ignoruje biała znaki wystepujące przed)
```
```c
scanf("xyzabc %d %d", &x, &y);    // x = ?, y = ? (nie dopasowaliśmy spacji po xyz)
```
```c
scanf("xyz abc %d%d", &x, &y);    // x = ?, y = ? (nie dopasowaliśmy spacji po xyz)
```

## Funkcja scanf() - wartość zwracana

Funkcja `scanf()` zwraca liczbę poprawnie przypisanych zmiennych.

```c
#include <stdio.h>

int main(void)
{
    int age;

    printf("Ile masz lat?: ");
    if (scanf("%d", &age) != 1)
        return -1;
    printf("Masz %d lat!\n");

    return 0;
}
```

## Zadanie 5

Napisz program który wczytuje 3 zmienne: liczbę, znak działania (-, +, /, *) i drugą liczbę
i zwraca wynik.

```bash
$ ./program
1
+
2
3

```
# Pętle

## Pętla `while`

Pętle pozwalają na kilkukrotne wykonanie tego samego kawałka kodu, dopóki
warunek pętli jest spełniony.

```c
int i = 0;
while (i < 10) {        // wykonuj instrukcje dopóki i < 10
    printf("%d", i);
    i++;
}
printf("\n");
```

```bash
$ ./program
0123456789
```

## Pętla `for`

Pętla `for` pozwala na iterację ograniczoną.

```c
int i;

// i = 0  jest wykonywane najpierw
// i < 9  jest wykonywane przed każdą iteracją pętli
// i += 1 jest wykonywane po każdej iteracji pętli
for (i = 0; i < 10; i += 1) {
    printf("%d", i);
}
```

Przykład: Wypisanie liczb od 10 do 1
```c
for (int j = 10; j > 0; --j)
    printf("%d", j);
```

## Instrukcja `break`

Instrukcja `break` przerywa wykonywania pętli.

```c
// Wczytuj kolejne liczby tak długo jak odczytana wartość jest liczbą
while (1) {
    int number;
    int ret = scanf("%d", &number);
    if (ret != 1)
        break;
}
```

## Instrukcja `continue`

Instrukcja `continue` powoduje przeskok do następnej iteracji pętli

```c
// Wypisz tylko parzyste liczby
for (int i = 0; i < 10; ++i) {
    if (i % 2)
        continue;
    printf("%d\n", i);
}
```

## Zadanie 6

Napisz program który odczytuje dwie liczby - wysokość i szerokość.
Program powinien narysować prostokąt o zadanej wysokości i szerokości.

```bash
$ ./rect
3
5
*****
*****
*****
```

# Funkcje

## Funkcje

Funkcje pozwalają na podział programu na mniejsze "podprogramy", co ułatwia jego zrozumienie
oraz pozwala wykorzystywać wielokrotnie podobne kawałki kodu.

```c
int factorial(int n)
{
    int value = 1;
    for (int i = 1; i <= n; ++i)
        value = value * i;
    return value;
}

int main(void)
{
    int n = factorial(4);
    printf("%d\n", n);
    return 0;
}
```

```bash
$ ./prog
24
```

## Funkcje - definicja i deklaracja

Deklaracja funkcji (typ zwracany, nazwa + argumenty), może być napisana odrębnie od
definicji, co pozwala jej użyć zanim została zdefiniowana.

```c
void print_version(int major, int minor, int patch); // Deklaracja

void print_name_with_version(void)
{
    printf("useless program ");
    print_version(1, 0, 1);
    printf("\n");
}

void print_version(int major, int minor, int patch) // Definicja
{
    printf("v%d.%d.%d", major, minor, patch);
}

int main(void)
{
    print_name_with_version(); // useless program v1.0.1
    return 0;
}
```

## Zadanie 7

Połącz 3 poprzednie programy (prostokąt, kalkulator, kostka) w jeden. Wykorzystaj
funkcje.

```
$ ./supertool
Witaj użytkowniku. Co chcesz zrobić?

1) Uruchom "prostokąt"
2) Uruchom "kalkulator"
3) Uruchom "kostka"
twój wybór > 1
Wybrałeś "kostka"

* *
* *
* *

Witaj użytkowniku. Co chcesz zrobić?

1) Uruchom "prostokąt"
2) Uruchom "kalkulator"
3) Uruchom "kostka"
```

