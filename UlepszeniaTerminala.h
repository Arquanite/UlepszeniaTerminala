#ifndef UTERM
#define UTERM
#ifdef _WIN32
#include <windows.h>
#include <conio.h>
#else
#include <sys/ioctl.h>
#include <termios.h>
#include <sys/types.h>
#endif
#include <unistd.h>
#include <iostream>

enum KlawiszeSpecjalne{
    #ifdef _WIN32
    Enter = 13,
    Backspace = 8,
    #else
    Enter = 10,
    Backspace = 127,
    #endif
    Spacja = 32
};
enum Kolor{
    #ifdef _WIN32
    Czarny = 0,
    Czerwony = 12,
    Zielony = 10,
    Zolty = 14,
    Niebieski = 9,
    Rozowy = 13,
    Blekitny = 11,
    Bialy = 15
    #else
    Czarny = 30,
    Czerwony = 31,
    Zielony = 32,
    Zolty = 33,
    Niebieski = 34,
    Rozowy = 35,
    Blekitny = 36,
    Bialy = 37
    #endif
};

struct XY{
    int x = 0;
    int y = 0;
};
void Poczekaj(int milisekundy);

void UstawKolor(int Kolor = Bialy, int KolorTla = Czarny);

void UstawKursor(int x, int y);
void UstawKursor(XY Polozenie);

XY RozmiarKonsoli();

void Wyczysc();

char Znak();

void ZmienTryb(bool tryb);
#endif
