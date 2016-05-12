#include "UlepszeniaTerminala.h"

void UstawKolor(int Kolor, int KolorTla){
    #ifdef _WIN32
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Kolor + KolorTla*16);
    #else
    std::cout<<"\033["<<Kolor<<';'<<KolorTla+10<<'m';
    #endif

}

void UstawKursor(int x, int y){
    #ifdef _WIN32
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
    #else
    std::cout<<"\033["<<y+1<<';'<<x+1<<'H';
    #endif
}

void UstawKursor(XY Polozenie){
    #ifdef _WIN32
    COORD c;
    c.X = Polozenie.x;
    c.Y = Polozenie.y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
    #else
    std::cout<<"\033["<<Polozenie.y+1<<';'<<Polozenie.x+1<<'H';
    #endif
}

XY RozmiarKonsoli(){
    XY r;
    #ifdef _WIN32
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    r.x = csbi.srWindow.Bottom+1;
    r.y = csbi.srWindow.Right+1;
    #else
    winsize ws;
    ioctl(0, TIOCGWINSZ , &ws);
    r.x = ws.ws_col + 1;
    r.y = ws.ws_row + 1;
    #endif
    return r;
}

void Poczekaj(int milisekundy){
    usleep(milisekundy*1000);
}

void Wyczysc(){
    #ifdef _WIN32
    system("cls");
    #else
    std::cout<<"\033[2J";
    #endif
}

void ZmienTryb(bool tryb){
    #ifndef _WIN32
    static termios oldt, newt;
    if(tryb){
        tcgetattr( STDIN_FILENO, &oldt);
        newt = oldt;
        newt.c_lflag &= ~( ICANON | ECHO );
        tcsetattr( STDIN_FILENO, TCSANOW, &newt);
    } else
    tcsetattr( STDIN_FILENO, TCSANOW, &oldt);
    #endif
}

char Znak(){
    #ifdef _WIN32
    return getch();
    #else
    return getchar();
    #endif
}
