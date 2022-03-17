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

