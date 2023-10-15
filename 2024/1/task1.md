# Przeliczanie pomiędzy systemem szesnastkowym i dziesiętnym

Celem zadania jest implementacja prostego narzędzia konsolowego do
przeliczania liczb z systemu dziesiętnego na szesnastkowy i odwrotnie.

# Przykład działania - konwersja z systemu szesnastkowego na binarny

Jeżeli użytkownik poda jako pierwszy argument do programu ciąg znaków zaczynający
się od liter `0x`, oznacza to, że podana liczba jest zapisana w formacie
szesnastkowym i program wypisze jej wartość zapisaną w formacie dziesiętnym.

```bash
$ ./program 0x1
1
```
```bash
$ ./program 0xeaa
3754
```

# Przykład działania - konwersja z systemu binarnego na szesnastkowy

Jeżeli użytkownik poda jako pierwszy argument do programu ciąg znaków nie zaczynający
się od liter `0x`, oznacza to, że podana liczba jest zapisana w formacie
dziesiętnym i program wypisze jej wartość zapisaną w formacie szesnastkowym.

```bash
$ ./program 1
0x1
```

```bash
$ ./program 3754
0xeaa
```

# Przykład działania - błąd

Jeżeli użytkownik poda jako pierwszy argument do programu ciąg znaków nie
będący liczbą w formacie szesnastkowym ani w formacie dziesiętnym to program
powinien wypisać błąd na standardowy strumień błędów

```
$ ./program sdflksgdkgdsfbklgsdklbkfjd
error: not a number
```

# Przykład działania - brak argumentów

Jeżeli użytkownik nie poda argumentów, to program powinien wypisać pomoc.

```
$ ./program
usage: program NUMBER
```

# Wskazówki

- Argument przekazany do programu można odczytać używając sygnatury funkcji main:
  `int main(int argc, char **argv)`, gdzie `argc` oznacza liczbę argumentów przekazanych
  do programu, `argv[0]` to nazwa programu, natomiast `argv[1]` to pierwszy argument
- Do wypisywania liczb w formacie szesnastkowym można użyć specyfikatora `%x` w funkcji `printf()`
- Do odczytywania liczba w formacie szesnastkowym można użyć specyfikatora `%x` dla funkcji `sscanf()`
- Do wypisywania błędu na standardowy strumień błędów można użyć `fprintf(stderr, "tresc bledu")`
