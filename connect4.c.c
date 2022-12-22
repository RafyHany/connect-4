#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <windows.h>

//main functions

int main_menu(void);
void time_passed(time_t start_time);
int computer_turn(int width);
void pvp();
void pvc();

void main()
{
    switch (main_menu())
    {
        case 0 : pvp();
          break ;
        //case 1 : pvc()
          break ;
    }
    time_t start_time=time(NULL);
         srand(time(NULL));


}


// comp turn


int computer_turn(int width)
{
 int computer_choice=rand()%width+1;
 return computer_choice;
}



// the main menu

void gotoxy(int x,int y)
{
    COORD coord = {0,0};
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void draw_the_box(int p , int h , int f , int g)
{
    int i ;
    gotoxy(f,g);
    printf("%c",201);
    for( i = 0 ; i < p ; i++)
        printf("%c",205);
    printf("%c",187);
    gotoxy(f,g);
    for(int j = 0 ; j < h-2 ; j++)
    {
        gotoxy(f,g+1+j);
        printf("%c",186);
        for( i = 0 ; i < p ; i++)
           printf("%c",32);
        printf("%c",186);
    }

    gotoxy(f,g+h-1);
    printf("%c",200);
    for( i = 0 ; i < p ; i++)
        printf("%c",205);
    printf("%c",188);
}

void ShowConsoleCursor(int showFlag){
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag;
    SetConsoleCursorInfo(out, &cursorInfo);
}


int main_menu(void)
{
    // basic printing
    ShowConsoleCursor(0);
    draw_the_box(30,6,39,11);
    int pos = 0 ;
    char c ;
    do{
    HANDLE console_color = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(console_color , 15 );


    gotoxy(40,12);printf(" 1) Start a new game          ");
    gotoxy(40,13);printf(" 2) Load a game               ");
    gotoxy(40,14);printf(" 3) Top players               ");
    gotoxy(40,15);printf(" 4) Quit                      ");
    printf("\n");


        switch(pos)
        {
            case 0 : SetConsoleTextAttribute(console_color , 240 );
                    gotoxy(40,12);printf(" 1) Start a new game          ");
                    break ;
            case 1 : SetConsoleTextAttribute(console_color , 240 );
                    gotoxy(40,13);printf(" 2) Load a game               ");
                    break ;
            case 2 : SetConsoleTextAttribute(console_color , 240 );
                    gotoxy(40,14);printf(" 3) Top players               ");
                    break ;
            case 3 : SetConsoleTextAttribute(console_color , 240 );
                    gotoxy(40,15);printf(" 4)Quit                       ");
                    break ;
        }

        c = getch();
        if(c == 80)
        {
            pos = (++pos) % 4;
        }
        else if(c == 72)
        {
            pos--;
            if (pos == -1 ) pos = 3;
        }
    }while( c != 13);
    printf("\n");


    // after choosing
    HANDLE console_color = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(console_color , 15 );

    if (pos == 0)

     {   gotoxy(39,19);
     system("cls");
        draw_the_box(30,8,39,11);
     do{
    HANDLE console_color = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(console_color , 15 );


    gotoxy(40,12);printf(" 1) Start a new game          ");
    gotoxy(40,13);printf("   i) player vs player        ");
    gotoxy(40,14);printf("   ii)player vs comp          ");
    gotoxy(40,15);printf(" 2) Load a game               ");
    gotoxy(40,16);printf(" 3) Top players               ");
    gotoxy(40,17);printf(" 4) Quit                      ");
    printf("\n");


        switch(pos)
        {
            case 0 : SetConsoleTextAttribute(console_color , 240 );
                    gotoxy(40,13);printf("   i) player vs player        ");
                    break ;
            case 1 : SetConsoleTextAttribute(console_color , 240 );
                    gotoxy(40,14);printf("   ii)player vs comp          ");
                    break ;
        }

        c = getch();
        if(c == 80)
        {
            pos = (++pos) % 2;
        }
        else if(c == 72)
        {
            pos--;
            if (pos == -1) pos = 1;
        }
    }while( c != 13);
    printf("\n\n\n\n");

    SetConsoleTextAttribute(console_color , 15 );

    return pos ;

}

}


// print time passed


void time_passed(time_t start_time)
{
    time_t current_time;
    int seconds,minutes,hours;
    current_time=time(NULL);
    seconds=(current_time-start_time);
    hours=(seconds/3600);
    minutes=(seconds%3600)/60;
    seconds=(seconds%3600)%60;
    printf("Time passed:%02d:%02d:%02d\n",hours,minutes,seconds);
}


// THE GAME

void the_game(int d, int e)
{

    for(int i = 0 ; i < d ; i++){
        for( int j = 0 ; j < e ; j++){
            draw_the_box(4,3,30 + 6*j,9 + i*3);
        }
    }

}


void make_array(int a[] , int p , int h)
{
    for(int i = 0 ; i < p ; i++)
        a[i]=h;
}


void fill(int f , int g , int c )
{
    HANDLE console_color = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(console_color , c );
    int i ;
    gotoxy(f,g);
    printf("    ");
}

void play(int a[] , int n,int c)
{
    HANDLE console_color = GetStdHandle(STD_OUTPUT_HANDLE);
    while(n < 0 || n > 7){
        gotoxy(30,7);printf("ENTER A VALID INPUT");
        gotoxy(35,8);scanf("%d",&n);

    }
    while(a[n] == 0){
        gotoxy(30,7);printf("ENTER A VALID INPUT");
        gotoxy(35,8);scanf("%d",&n);

    }
        fill(25+6*n , 7+3*a[n] , c);
        SetConsoleTextAttribute(console_color , 15 );
        a[n]-- ;
}

void pvp(void)
{
    system("cls");
    the_game(6,7);
    int q ;int n ;
    int a[8];
    make_array(a,8,6);
    for(int i = 0 ; i < 6*7 ; i++)
    {
        q = i % 2 ;
        if ( q == 0){
            gotoxy(35,6);printf("player 1 turn");
            gotoxy(35,8);scanf("%d",&n);
            play(a,n,BACKGROUND_RED);
        }
        else{
            gotoxy(35,6);printf("player 2 turn");
             gotoxy(35,8);scanf("%d",&n);
            play(a,n,BACKGROUND_GREEN);
        }
    }
    printf("\n");
}


