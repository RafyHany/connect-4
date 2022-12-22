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

int main()
{
    switch (main_menu())
    {
        case 0 : pvp();
          break ;
        case 1 : pvc();
          break ;
      /*case 2 : loadgame(1);
          break;
        case 3 : loadgame(2);
          break;
        case 4 : loadgame(3);
          break;*/
    }
         srand(time(NULL));

         return 0 ;
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
    gotoxy(40,13);printf("   i)  player vs player       ");
    gotoxy(40,14);printf("   ii) player vs comp         ");
    gotoxy(40,15);printf(" 2) Load a game               ");
    gotoxy(40,16);printf(" 3) Top players               ");
    gotoxy(40,17);printf(" 4) Quit                      ");
    printf("\n");


        switch(pos)
        {
            case 0 : SetConsoleTextAttribute(console_color , 240 );
                    gotoxy(40,13);printf("   i)  player vs player       ");
                    break ;
            case 1 : SetConsoleTextAttribute(console_color , 240 );
                    gotoxy(40,14);printf("   ii) player vs comp         ");
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
    if (pos == 1)

     {   gotoxy(39,19);
     system("cls");
        draw_the_box(30,9,39,11);
     do{
    HANDLE console_color = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(console_color , 15 );


    gotoxy(40,12);printf(" 1) Start a new game          ");
    gotoxy(40,13);printf(" 2) Load a game               ");
    gotoxy(40,14);printf("   i)   game 1                ");
    gotoxy(40,15);printf("   ii)  game 2                ");
    gotoxy(40,16);printf("   iii) game 3                ");
    gotoxy(40,17);printf(" 3) Top players               ");
    gotoxy(40,18);printf(" 4) Quit                      ");
    printf("\n");


        switch(pos)
        {
            case 0 : SetConsoleTextAttribute(console_color , 240 );
                    gotoxy(40,14);printf("   i)   game 1                ");
                    break ;
            case 1 : SetConsoleTextAttribute(console_color , 240 );
                    gotoxy(40,15);printf("   ii)  game 2                ");
                    break ;
            case 2 : SetConsoleTextAttribute(console_color , 240 );
                    gotoxy(40,16);printf("   iii) game 3                ");
                    break ;
        }

        c = getch();
        if(c == 80)
        {
            pos = (++pos) % 3;
        }
        else if(c == 72)
        {
            pos--;
            if (pos == -1) pos = 2;
        }
    }while( c != 13);
    printf("\n\n\n\n");

    SetConsoleTextAttribute(console_color , 15 );

    return (pos+2) ;

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

void the_game(int h, int w)
{
    for(int k = 1 ; k < w+1 ; k++ ){
        gotoxy(25+6*k,8);printf(" %d ",k);
    }
    for(int i = 0 ; i < h ; i++){
        for( int j = 0 ; j < w ; j++){
            draw_the_box(4,3,30 + 6*j,9 + i*3);
        }
    }

}


void make_array(int a[] , int p , int h)
{
    for(int i = 0 ; i < p ; i++)
        a[i] = h ;
}


void fill(int f , int g , int c )
{
    HANDLE console_color = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(console_color , c );
    int i ;
    gotoxy(f,g);
    printf("    ");
}

int play(int a[] ,int n, int w,int c)
{
    HANDLE console_color = GetStdHandle(STD_OUTPUT_HANDLE);

    while(n <= 0 || n > w ||a[n]==0)
    {
        gotoxy(35,4);printf("ENTER A VALID INPUT");
        gotoxy(35,5);scanf("%d",&n);
        gotoxy(35,4);printf("                   \n            ");

    }

        fill(25+(6*n) , 7+(3*a[n]) , c);
        SetConsoleTextAttribute(console_color , 15 );
        a[n]-- ;
        return n ;
}



void pvp(void)
{
    system("cls");
    int h = 6 , w = 7 ;
    the_game(h,w);
    int q ;int n ;
    int a[w+1];
    int b[h][w];
    make_array(a,w+1,h);
    for(int i = 0 ; i < h ; i++){
         for(int j = 0 ; j < w ; j++){
            b[i][j] = 0 ;
         }
    }
    time_t start_time=time(NULL);
    for(int i = 0 ; i < w*h ; i++)
    {
        q = i % 2 ;
        if ( q == 0){
            gotoxy(35,2); time_passed(start_time);
            gotoxy(35,3);printf("player 1 turn");
            gotoxy(35,5);scanf("%d",&n);
            n = play(a,n,w,BACKGROUND_RED);
            gotoxy(35,5);printf("                 ");
            b[n-1][a[n]] = 1 ;
        }
        else{
            gotoxy(35,2); time_passed(start_time);
            gotoxy(35,3);printf("player 2 turn");
             gotoxy(35,5);scanf("%d",&n);
            n = play(a,n,w,BACKGROUND_GREEN);
            gotoxy(35,5);printf("                 ");
            b[n-1][a[n]] = -1 ;
        }
    }
    printf("\n");
}

void pvc(void)
{
    system("cls");
    int h = 6 , w = 7 ;
    the_game(h,w);
    int q ;int n ;
    int a[w+1];
    make_array(a,w+1,h);
    int b[h][w];
    for(int i = 0 ; i < h ; i++){
         for(int j = 0 ; j < w ; j++){
            b[i][j] = 0 ;
         }
    }
    for(int i = 0 ; i < w*h ; i++)
    {
        q = i % 2 ;
        if ( q == 0){
            gotoxy(35,3);printf("player 1 turn");
            gotoxy(35,5);scanf("%d",&n);
            n = play(a,n,w,BACKGROUND_RED);
            gotoxy(35,5);printf("    ");
            b[n-1][a[n]] = 1 ;
        }
        else{
            gotoxy(35,3);printf("computer turn");
             do
             {
            n = computer_turn(w+1);
             }while(a[n] == 0);
             gotoxy(35,5);printf("%d",n);
            n = play(a,n,w,BACKGROUND_GREEN);
             b[n-1][a[n]] = -1 ;
        }
    }
    printf("\n");
}


