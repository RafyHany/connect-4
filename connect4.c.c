#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <ctype.h>

#define MAX 1000
typedef struct
{
char name[30];
int score ;
} information;


typedef struct{
int WIDTH;
int HEIGHT;
int HIGHTSCORES;
} game;
game parameter;

//main functions

int main_menu(void);
void time_passed(time_t start_time);
int computer_turn(int width);
int pvp(int w , int h,int undos,int score1,int score2,int turn,int a[MAX],int b[MAX][MAX]);
int pvc(int w , int h,int undos,int score1,int score2,int turn,int a[MAX],int b[MAX][MAX]);
void horizontal_check(int*score,int width_input,int heigh_input,int width,int heigh,int a[][width]);
void vertical_check(int*score,int width_input,int heigh_input,int width,int heigh,int a[][width]);
void diagonal_45_check(int*score,int width_input,int heigh_input,int width,int heigh,int a[][width]);
void diagonal_135_check(int*score,int width_input,int heigh_input,int width,int heigh,int a[][width]);
void check_score(int* score,int width_input,int heigh_input,int width,int heigh,int a[][width]);
void push(int n);
int pop ();
int undo(int a[] , int size);
int redo(int a [] , int w , int c , int score , int undos , int b[][MAX],int size);
void xml_files();
int our_strstr(char s1[],char s2[]);
void save(char mode  , int score1 , int score2 , int a[] , int b[][MAX] , int i , int save_no, int w  , int h );
void make_array(int a[] , int w , int h);
int loadgame(int game_no) ;
void end_of_game(int score1,int score2);
 void conver_to_lower(char name []);
 void merge(information arr[], int l, int m, int r);
 void mergeSort(information arr[],int l, int r);
void Top_players(int number_of_top);




//globals
int w , h , number_of_top ;

int stack_play[MAX];
int top = -1;

int main()
{
    xml_files();
    w = parameter.WIDTH ,  h = parameter.HEIGHT ,number_of_top = parameter.HIGHTSCORES ;
    int a[w];
    make_array(a,w,h);
    int b[h][w];
    for(int i = 0 ; i < h ; i++){
         for(int j = 0 ; j < w ; j++){
            b[i][j] = 0 ;
         }
    }
    switch (main_menu())
    {
        case 0 : if (pvp(w,h,0,0,0,0,a,b)){
          main();
          }
          break ;
        case 1 : if (pvc(w,h,0,0,0,0,a,b)){
          main();
          }
          break ;
        case 2 : if(loadgame(1)){
         main() ;
        };
          break;
        case 3 :  if(loadgame(2)){
         main() ;
        };
          break;
        case 4 :  if(loadgame(3)){
         main() ;
        };
          break;
        case 7 : return 0 ;
        break;

        case 8 : Top_players(number_of_top);
        char c ;
        c = getch();
        while (c != 27)
        {
            c = getch();
        }
        main();

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
    system("cls");
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
        SetConsoleTextAttribute(console_color , 15 );

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

     {   pos = 0 ;
         gotoxy(39,19);
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
        SetConsoleTextAttribute(console_color , 15 );


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
         else if(c == 27)
        {
            SetConsoleTextAttribute(console_color , 15 );
            main();
        }
    }while( c != 13);
    printf("\n\n\n\n");

    SetConsoleTextAttribute(console_color , 15 );

    return pos ;

}
    else if (pos == 1)


     {    pos = 0;
         gotoxy(39,19);
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
        SetConsoleTextAttribute(console_color , 15 );

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
        else if(c == 27)
        {
            SetConsoleTextAttribute(console_color , 15 );
            main();
        }
    }while( c != 13);
    printf("\n\n\n\n");

    SetConsoleTextAttribute(console_color , 15 );

    return (pos+2) ;

}

   else if(pos == 2 )
   {
       system("cls");
       return 8 ;
   }


   else if(pos == 3){
    return  7 ;
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
        gotoxy(0+6*k,8);printf(" %d ",k);
    }
    for(int i = 0 ; i < h ; i++){
        for( int j = 0 ; j < w ; j++){
            draw_the_box(4,3,5 + 6*j,9 + i*3);
        }
    }

}

void the_game2(int h, int w)
{
    for(int k = 1 ; k < w+1 ; k++ ){
        gotoxy(-1+4*k,8);printf(" %d ",k);
    }
    for(int i = 0 ; i < h ; i++){
        for( int j = 0 ; j < w ; j++){
            draw_the_box(2,3,3 + 4*j,9 + i*3);
        }
    }

}

void the_game3(int h, int w)
{
    printf("\n\n\n\n\n\n\n\n\n\n");
    printf("\n");
    for(int i = 0 ; i < h ; i++){
        for (int j = 0 ; j < w+1 ; j++){
            printf("%c  ",186);
        }
         printf("\n");
        for (int j = 0 ; j < w ; j++){
            printf("%c%c%c",205,205,205);
        }
        printf("\n");
    }
}

void make_array(int a[] , int w , int h)
{
    for(int i = 0 ; i < w ; i++)
        a[i] = h ;
}


void fill(int f , int g , int c ,int size)
{
    HANDLE console_color = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(console_color , c );
    if (size == 1){
    gotoxy(f,g);
    printf("    ");}
    if(size == 2){
       gotoxy(f,g);
    printf("  ");
    }
    if(size == 3){
       gotoxy(f,g);
    printf("  ");
    }
}

int play(int a[] ,int n, int w,int c,int size)
{
    HANDLE console_color = GetStdHandle(STD_OUTPUT_HANDLE);

    char in[100] ;

    while(n < 0 || n > w ||a[n]==0)
    {
        gotoxy(35,4);printf("ENTER A VALID INPUT                          ");
         gotoxy(35,5);printf("            ");
        gotoxy(35,5);fgets(in,100,stdin);
        if(atoi(in) != 0 ){
        n = atoi(in) ;
        n = n-1 ;
        }
        gotoxy(35,4);printf("                                      ");
    }

        if (size == 1){
        fill((6*(n+1)) , 7+(3*a[n]) , c , size);
        }
        if(size == 2){
            fill((4*(n+1)) , 7+(3*a[n]) , c , size);
        }
        if(size == 3){
            fill((3*(n))+1 , 9+(2*a[n]) , c , size);
        }
        SetConsoleTextAttribute(console_color , 15 );
        a[n]-- ;
        return n ;
}



int pvp(int w , int h, int undos,int score1,int score2,int turn,int a[w],int b[h][w])
{
    system("cls");
    int  save_no ;
    HANDLE console_color = GetStdHandle(STD_OUTPUT_HANDLE);
    int size = 0 ;
    if (w <= 19){
    the_game(h,w);
    size = 1 ;
    }
    else if(w < 30){
        the_game2(h,w);
        size = 2 ;
    }
    else
    {
        the_game3(h,w);
        size = 3 ;
    }
    draw_the_box(19,6,1,0);
    gotoxy(2,1);printf("to undo enter -> u ");
    gotoxy(2,2);printf("to redo enter -> r ");
    gotoxy(2,3);printf("to save enter -> s ");
    gotoxy(2,4);printf("to quit enter -> q ");
    for(int k = 0 ; k < h ; k++){
         for(int j = 0 ; j < w ; j++){
             if( b[k][j] == 1 ){
                fill(6*(j+1),7+(3*(k+1)),BACKGROUND_RED,size);
             }

         else if( b[k][j] == -1 ){
                fill(6*(j+1),7+(3*(k+1)),BACKGROUND_GREEN,size);
             }
         }
    }
    SetConsoleTextAttribute(console_color , 15 );
    int q ;int n = 0 ;
    char in[100];char op ;
    int temp_score=0;
    time_t start_time=time(NULL);
    while(turn < w*h)
    {
        q = turn % 2 ;
        if ( q == 0){
            gotoxy(35,2); time_passed(start_time);
            gotoxy(35,3);printf("player 1 turn");
            gotoxy(35,1);printf("p1 score : %d  -  p2 score : %d  ",score1,score2);
            gotoxy(35,0);printf("p1 moves : %d  -  p2 moves : %d  ",turn/2,turn/2);
            gotoxy(35,5);printf("                          ");
            gotoxy(35,5);fgets(in,100,stdin);
            if(atoi(in) != 0 ){
            n = atoi(in);
            n = n - 1 ;
            n = play(a,n,w,BACKGROUND_RED,size);
            push(n);
            gotoxy(35,5);printf("                 ");
            b[a[n]][n] = 1 ;
            check_score(&score1,n,a[n],w,h,b);
            turn++;
            undos = 0 ;
            }
            else
            {
                op = in[0] ;
                switch(op)
                {
                    case 'u' :
                        check_score(&temp_score,stack_play[top],a[stack_play[top]],w,h,b);
                       score2 -= temp_score;
                       b[a[stack_play[top]]][stack_play[top]] = 0 ;
                       if(score1 < 0 ){
                        score1 = 0 ;
                       }
                       if(score2 < 0 ){
                        score2 = 0 ;
                       }
                        if(undo(a,size)){
                       turn-- ;
                       undos++ ;
                       gotoxy(35,1);printf("p1 score : %d  -  p2 score : %d  ",score1,score2);

                    }
                     temp_score=0;
                       break ;
                    case 'r' : if(redo(a,w,BACKGROUND_RED,score1,undos,b,size)){
                       turn++;
                       b[a[stack_play[top]]][stack_play[top]] = 1 ;
                     check_score(&score1,stack_play[top],a[stack_play[top]],w,h,b);
                       undos--;
                    }
                      break;
                    case 's' :
                        gotoxy(35,4);printf("ENTER THE NUMBER OF THE SAVING SLOT FROM 1:3 ");
                        scanf("%d",&save_no);
                        while(save_no < 1 || save_no > 3){
                            gotoxy(35,4);printf("          BROOO !!! I SAID FROM 1:3       ");
                             scanf("%d",&save_no);
                        }
                        save('p',score1,score2,a,b,turn,save_no,w,h);
                         gotoxy(35,4);printf("                                                     ");
                      break;
                    case 'q' : return 6 ;
                    break;
                }
            }
        }
        else{
            gotoxy(35,2); time_passed(start_time);
            gotoxy(35,3);printf("player 2 turn");
            gotoxy(35,1);printf("p1 score : %d  -  p2 score : %d  ",score1,score2);
            gotoxy(35,0);printf("p1 moves : %d  -  p2 moves : %d  ",(turn/2)+1,turn/2);
            gotoxy(35,5);printf("                            ");
            gotoxy(35,5);fgets(in,100,stdin);
            if(atoi(in) != 0 ){
            n = atoi(in);
            n = n-1 ;
            n = play(a,n,w,BACKGROUND_GREEN,size);
            push(n);
            gotoxy(35,5);printf("                 ");
            b[a[n]][n] = -1 ;
            check_score(&score2,n,a[n],w,h,b);
            turn++;
            undos = 0 ;
            }
             else
            {
                op = in[0] ;
                switch(op)
                {
                    case 'u' :
                        check_score(&temp_score,stack_play[top],a[stack_play[top]],w,h,b);
                       score1 -= temp_score;
                       b[a[stack_play[top]]][stack_play[top]] = 0 ;
                       if(score1 < 0 ){
                        score1 = 0 ;
                       }
                       if(score2 < 0 ){
                        score2 = 0 ;
                       }
                        if(undo(a,size)){
                       turn-- ;
                       undos++ ;
                       gotoxy(35,1);printf("p1 score : %d  -  p2 score : %d  ",score1,score2);
                    }
                     temp_score=0;
                      break ;
                    case 'r' : if(redo(a,w,BACKGROUND_GREEN,score2,undos,b,size)){
                       turn++;

                       b[a[stack_play[top]]][stack_play[top]] = -1 ;
                        check_score(&score2,stack_play[top],a[stack_play[top]],w,h,b);
                       undos-- ;
                    }
                      break;
                    case 's' :
                        gotoxy(35,4);printf("ENTER THE NUMBER OF THE SAVING SLOT FROM 1:3 ");
                        scanf("%d",&save_no);
                        while(save_no < 1 || save_no > 3){
                            gotoxy(35,4);printf("         BROOO !!! I SAID FROM 1:3       ");
                               scanf("%d",&save_no);
                        }
                        save('p',score1,score2,a,b,turn,save_no,w,h);
                         gotoxy(35,4);printf("                                                     ");
                      break;
                    case 'q' : return 6 ;
                      break;
                }
            }
        }
    }
    printf("\n");
    end_of_game(score1,score2);

        return 6 ;
}

int pvc(int w , int h , int undos,int score1,int score2,int turn,int a[w],int b[h][w])
{
    system("cls");
    HANDLE console_color = GetStdHandle(STD_OUTPUT_HANDLE);
    int save_no ;
    int size = 0;
    int temp_score ;
       if (w <= 19){
    the_game(h,w);
    size = 1 ;
    }
    else if(w <30){
        the_game2(h,w);
        size = 2 ;
    }
    else
    {
        the_game3(h,w);
        size = 3 ;
    }
    the_game(h,w);
    for(int k = 0 ; k < h ; k++){
         for(int j = 0 ; j < w ; j++){
             if( b[k][j] == 1 ){
                fill(6*(j+1),7+(3*(k+1)),BACKGROUND_RED,size);
             }

         else if( b[k][j] == -1 ){
                fill(6*(j+1),7+(3*(k+1)),BACKGROUND_GREEN,size);
             }
         }
    }
    SetConsoleTextAttribute(console_color , 15 );
    draw_the_box(19,6,1,0);
    gotoxy(2,1);printf("to undo enter -> u ");
    gotoxy(2,2);printf("to redo enter -> r ");
    gotoxy(2,3);printf("to save enter -> s ");
    gotoxy(2,4);printf("to quit enter -> q ");
    int q , n ;
    char in[100];char op ;
    time_t start_time=time(NULL);
    while(turn < w*h)
    {
        q = turn % 2 ;
        if ( q == 0){
            gotoxy(35,2); time_passed(start_time);
            gotoxy(35,3);printf("player 1 turn");
            gotoxy(35,1);printf("p1 score : %d  -  p2 score : %d",score1,score2);
            gotoxy(35,0);printf("p1 moves : %d  -  p2 moves : %d",turn/2,turn/2);
            gotoxy(35,5);printf("                       ");
            gotoxy(35,5);fgets(in,100,stdin);
            if(atoi(in) != 0 ){
            n = atoi(in);
            n = n-1 ;
            n = play(a,n,w,BACKGROUND_RED,size);
            push(n);
            gotoxy(35,5);printf("                 ");
            b[a[n]][n] = 1 ;
            check_score(&score1,n,a[n],w,h,b);
            turn++;
            undos = 0;
            }
            else
            {
                op = in[0] ;
                switch(op)
                {
                     case 'u' :
                         check_score(&temp_score,stack_play[top],a[stack_play[top]],w,h,b);
                       score2-=temp_score;
                         b[a[stack_play[top]]][stack_play[top]] = 0 ;
                         if(score1 < 0 ){
                        score1 = 0 ;
                       }
                       if(score2 < 0 ){
                        score2 = 0 ;
                       }
                        if(undo(a,size)){
                       turn-- ;

                    }
                    temp_score=0;
                    check_score(&temp_score,stack_play[top],a[stack_play[top]],w,h,b);
                       score1-=temp_score;
                     b[a[stack_play[top]]][stack_play[top]] = 0 ;
                     if(score1 < 0 ){
                        score1 = 0 ;
                       }
                       if(score2 < 0 ){
                        score2 = 0 ;
                       }
                        if(undo(a,size)){
                       turn-- ;
                       undos++ ;

                    }
                    temp_score=0;
                      break ;
                    case 'r' : if(redo(a,w,BACKGROUND_RED,score1,undos,b,size)){
                       turn++;
                       b[a[stack_play[top]]][stack_play[top]] = 1 ;
                       }
                       if(redo(a,w,BACKGROUND_GREEN,score2,undos,b,size)){
                       b[a[stack_play[top]]][stack_play[top]] = 1 ;
                       turn++;
                       undos--;
                       }
                      break;
                    case 's' :
                        gotoxy(35,4);printf("ENTER THE NUMBER OF THE SAVING SLOT FROM 1:3 ");
                        scanf("%d",&save_no);
                        while(save_no < 1 || save_no > 3){
                            gotoxy(35,4);printf("          BROOO !!! I SAID FROM 1:3       ");
                            scanf("%d",&save_no);
                        }
                         save('c',score1,score2,a,b,turn, save_no,w,h);

                     gotoxy(35,4);printf("                                                     ");
                      break;
                    case 'q' : return 6;
                    break;
                }
            }
        }
        else{
            gotoxy(35,2); time_passed(start_time);
            gotoxy(35,3);printf("computer turn");
            gotoxy(35,1);printf("p1 score : %d  -  p2 score : %d",score1,score2);
            gotoxy(35,0);printf("p1 moves : %d  -  p2 moves : %d",turn/2,turn/2);
             do
             {
              n = computer_turn(w-1);
             }while(a[n] == 0  );
            n = play(a,n,w,BACKGROUND_GREEN,size);
            push(n);
            b[a[n]][n] = -1 ;
            check_score(&score2,n,a[n],w,h,b);
            turn++;
        }
    }
    end_of_game(score1,score2);

    return 6 ;
}
void horizontal_check(int*score,int width_input,int heigh_input,int width,int heigh,int a[][width]) //check horizontal row
{

   int found=1 ;
   if(width_input+3<=width)
   {
   for(int i=width_input+1;i<=width_input+3;++i) //to check if there is 3 in right
      {
       if(a[heigh_input][width_input]!=a[heigh_input][i])
          {
              found=0;
              break;
          }

      }
    if(found==1)
        (*score)++;
    found=1;
   }
   if(width_input-3>=0)
   {
      for(int i=width_input-3;i<=width_input-1;++i)//to check if there is 3 in left
       {
        if(a[heigh_input][width_input]!=a[heigh_input][i])
          {
              found=0;
              break;
          }
       }
    if(found==1)
        (*score)++;
    found=1;
   }
   if(width_input-2>=0&&width_input+1<=width)
   {
      for(int i=width_input-2;i<=width_input+1;++i) //to check if there is 2 in left and 1 in right
       {
        if(a[heigh_input][width_input]!=a[heigh_input][i])
          {
              found=0;
              break;
          }
       }
    if(found==1)
        (*score)++;
    found=1;
   }
   if(width_input-1>=0&&width_input+2<=width)
   {
      for(int i=width_input-1;i<=width_input+2;++i) //to check if there is 1 in left and 2 in right
       {
        if(a[heigh_input][width_input]!=a[heigh_input][i])
          {
              found=0;
              break;
          }
       }
    if(found==1)
        (*score)++;
   }
}

void vertical_check(int*score,int width_input,int heigh_input,int width,int heigh,int a[][width]) // to check if there is 3 below
{
  int found=1;
  for(int i=heigh_input+1;i<=heigh_input+3;++i)
        {
        if((a[heigh_input][width_input]!=a[i][width_input])||(heigh_input+3>=heigh))
         {
            found=0;
            break;
         }
        }
    if(found==1)
        (*score)++;
}
void diagonal_45_check(int*score,int width_input,int heigh_input,int width,int heigh,int a[][width]) // to check 45 diagonal
{
  int found=1;
  if(width_input+3<=width&&heigh_input-3>=0)
  {

  for(int i=heigh_input-1,j=width_input+1;i>=heigh_input-3,j<=width_input+3;--i,++j) //to check 3 in right 45 diagonal
        {

        if(a[heigh_input][width_input]!=a[i][j])
         {
            found=0;
            break;
         }
        }
    if(found==1)
        (*score)++;
    found=1;

  }
 if(width_input-3>=0&&heigh_input+3<=heigh)
 {
  for(int i=heigh_input+1,j=width_input-1;i<=heigh_input+3,j>=width_input-3;++i,--j)  //to check 3 in left 45 diagonal
        {

        if(a[heigh_input][width_input]!=a[i][j])
         {
            found=0;
            break;
         }
        }
    if(found==1)
        (*score)++;
    found=1;

 }
 if(width_input-1>=0&&heigh_input+1<=heigh&&width_input+2<=width&&heigh_input-2>=0 )
 {
  for(int i=heigh_input+1,j=width_input-1;i>=heigh_input-2,j<=width_input+2;--i,++j)  //to check 1 in left 45 diagonal and 2 in right 45 diagonal
        {

        if(a[heigh_input][width_input]!=a[i][j])
         {
            found=0;
            break;
         }
        }
    if(found==1)
        (*score)++;
    found=1;
 }
 if(width_input-2>=0&&heigh_input+2<heigh&&width_input+1<width&&heigh_input-1>=0)
 {
    for(int i=heigh_input+2,j=width_input-2;i>=heigh_input-1,j<=width_input+1;--i,++j)  //to check 2 in left 45 diagonal and 1 in right 45 diagonal
        {

        if(a[heigh_input][width_input]!=a[i][j])
         {
            found=0;
            break;
         }
        }
    if(found==1)
        (*score)++;
 }

}
void diagonal_135_check(int*score,int width_input,int heigh_input,int width,int heigh,int a[][width]) //to check diagonal 135
{
    int found=1;
    if(heigh_input-3>=0&&width_input-3>=0)
    {
       for(int i=heigh_input-1,j=width_input-1;i>=heigh_input-3,j>=width_input-3;--i,--j) //to check 3 left 135 diagonal
        {

        if(a[heigh_input][width_input]!=a[i][j])
         {
            found=0;
            break;
         }
        }
     if(found==1)
        (*score)++;
     found=1;
    }
      if(heigh_input+3<=heigh&&width_input+3<=width)
    {
       for(int i=heigh_input+1,j=width_input+1;i<=heigh_input+3,j<=width_input+3;++i,++j) //to check 3 right 135 diagonal
        {

        if(a[heigh_input][width_input]!=a[i][j])
         {
            found=0;
            break;
         }
        }
    if(found==1)
        (*score)++;
    found=1;
    }
   if(heigh_input-2>=0&&width_input-2>=0&&heigh_input+1<=heigh&&width_input+1<=width)
   {
    for(int i=heigh_input+1,j=width_input+1;i>=heigh_input-2,j>=width_input-2;--i,--j)//to check 2 left 1 right 135 diagonal
        {

        if(a[heigh_input][width_input]!=a[i][j])
         {
            found=0;
            break;
         }
        }
      if(found==1)
        (*score)++;
      found=1;
   }
   if(heigh_input-1>=0&&width_input-1>=0&&heigh_input+2<=heigh&&width_input+2<=width)
   {
    for(int i=heigh_input+2,j=width_input+2;i>=heigh_input-1,j>=width_input-1;--i,--j) //to check 1 left 2 right 135 diagonal
        {

        if(a[heigh_input][width_input]!=a[i][j])
         {
            found=0;
            break;
         }
        }
    if(found==1)
        (*score)++;
   }

}
void check_score(int*score,int width_input,int heigh_input,int width,int heigh,int a[][width])
{
   horizontal_check(score,width_input,heigh_input,width,heigh,a);
   vertical_check(score,width_input,heigh_input,width,heigh,a);
   diagonal_45_check(score,width_input,heigh_input,width,heigh,a);
   diagonal_135_check(score,width_input,heigh_input,width,heigh,a);
}


int isempty()
{
    if(top == -1)
        return 1 ;
    else
        return 0 ;
}

int isfull()
{
    if(top == MAX - 1)
        return 1 ;
    else
        return 0 ;
}

int pop()
{
    if(isempty())
        return 0;
    else{
        return stack_play[top--];
    }
}

void push(int move )
{
    if(isfull())
        return ;
    else{
        top++;
        stack_play[top] = move ;
    }
}

int undo(int a[],int size)
{
    if(isempty()){
        gotoxy(35,4);printf("NO MORE UNDO     ");
        return 0 ;
    }
    int var = pop() ;
    a[var]++;
    if(size == 1){
    fill((6*(var+1)) , 7+(3*a[var]) , 15 , size);
    }
    else if ( size == 2){
        fill((4*(var+1)) , 7+(3*a[var]) , 15 , size);
    }
     else if ( size == 3){
        fill(((3*var)+1) , 9+(2*a[var]) , 15 , size);
    }
    return 1 ;
}

int redo(int a [] , int w , int c , int score , int undos ,int b[][w],int size)
{
    if(isfull() || undos <= 0){
        gotoxy(35,4);printf("NO MORE REDO     ");
        return 0 ;
        }
     else{
    play(a,stack_play[++top],w,c,size);
    check_score(&score,stack_play[top],a[stack_play[top]],w,h,b);
    return 1 ;
}

}
void xml_files()
{
    static int error_path=0;char path[200]={'0'};
    if(error_path==0)
       strcpy(path,"parameter.xml");
       else
       {
           if(error_path<=3)
           {
           printf("Error in configration file,please Enter the path:");
           gets(path);
           }else{ //DEFAULT VALUES
              parameter.WIDTH=7;
              parameter.HEIGHT=9;
              parameter.HIGHTSCORES=10;
              return ;
       }
       }
    char ch,file_without_space[500]= {'0'},conf_1[]="<Configurations>",width_1[]="<Width>",height_1[]="<Height>",highscores_1[]="<Highscores>";
    char conf_2[]="</Configurations>",width_2[]="</Width>",height_2[]="</Height>",highscores_2[]="</Highscores>";
    int i=0,start_con,end_con,start_w,end_w,start_h,end_h,start_hs,end_hs;
    FILE *file;
    if((file= fopen(path, "r"))==NULL){
        error_path++;
        xml_files();
        return;
    }
    int tags_bords;
    while((ch=fgetc(file))!=EOF){
        if(ch=='<')
         tags_bords=0;
        if(ch=='>')
        tags_bords=1;

        if(ch!=' '&&ch!='\n'&&ch!='\t'&&tags_bords==1){           //IGNORING ANY SPACES OR TABS OR BREAKING LINE
            file_without_space[i]=ch;
            i++;
        }
        else  if(tags_bords==0){
            file_without_space[i]=ch;
            i++;
        }

    }
    file_without_space[i]='\0';
    fclose(file);

    start_con=our_strstr(conf_1,file_without_space);
    end_con=our_strstr(conf_2,file_without_space);
    if(start_con==-1||end_con==-1||end_con<start_con){
            error_path++;
            return xml_files() ;
    }

    start_w=our_strstr(width_1,file_without_space);
    end_w=our_strstr(width_2,file_without_space);
    int size_wid=end_w-start_w+1;

        if(start_w==-1||end_w==-1||end_w<start_w||end_w>end_con||start_w<start_con){
            error_path++;
            return xml_files() ;
        }
    char width[size_wid];
    for(int p=0,j=start_w+7;j<end_w;++j,++p){
    if(isalpha(file_without_space[j]))
    {
            error_path++;
            return xml_files() ;
    }
    width[p]=file_without_space[j];
    }
    width[end_w]='\0';



    start_h=our_strstr(height_1,file_without_space);
    end_h=our_strstr(height_2,file_without_space);
    int size_hig=end_h-start_h+1;

        if(start_h==-1||end_h==-1||end_h<start_h||end_h>end_con||start_h<start_con){
            error_path++;
            return xml_files() ;
        }
    char heigh[size_hig];
       for(int h=0,v=start_h+8;v<end_h;++v,++h){
    if(isalpha(file_without_space[v]))
    {
            error_path++;
            return xml_files() ;
    }
         heigh[h]=file_without_space[v];

         }
        heigh[end_h]='\0';



    start_hs=our_strstr(highscores_1,file_without_space);
    end_hs=our_strstr(highscores_2,file_without_space);
    int size_hs=end_hs-start_hs+1;

        if(start_hs==-1||end_hs==-1||end_hs<start_hs||end_hs>end_con||start_hs<start_con){
            error_path++;
            return xml_files() ;
        }

    char highscores[size_hs];
       for(int p=0,j=start_hs+12;j<end_hs;++j,++p)
       {
    if(isalpha(file_without_space[j]))
    {
            error_path++;
            return xml_files() ;
    }
         highscores[p]=file_without_space[j];
       }
      highscores[end_hs]='\0';



   if(atoi(heigh)<4||atoi(width)<4||atoi(highscores)<1)
    {
                error_path++;
            return xml_files() ;
    }
     parameter.WIDTH=atoi(width);
     parameter.HEIGHT=atoi(heigh);
     parameter.HIGHTSCORES=atoi(highscores);
}



int our_strstr(char s1[],char s2[]){
    int counter=-1,i=0;
    while(s2[i]!='\0'){
        int j=0;
        if(s2[i]==s1[j]){
            int k=i;
            while(s2[k]==s1[j] && s1[j]!='\0'){
                k++;
                j++;
            }
            if(s1[j]=='\0'){
                counter=i;
            }
        }
        i++;
    }
    return counter;
}

void save(char mode  , int score1 , int score2 , int a[] , int b[][w] , int turn , int save_no, int w , int h)
{
    FILE *saved ;
    switch(save_no){
          case 1 : saved = fopen("game","wb");
                 break ;
          case 2 : saved = fopen("game2","wb");
                 break ;
          case 3 : saved = fopen("game3","wb");
                 break ;
    }
    fwrite(&w,sizeof(w),1,saved);
    fwrite(&h,sizeof(h),1,saved);
    fwrite(&mode,sizeof(mode),1,saved);
    fwrite(&score1,sizeof(score1),1,saved);
    fwrite(&score2,sizeof(score2),1,saved);
    fwrite(&turn,sizeof(turn),1,saved);
    fwrite(&top,sizeof(top),1,saved);
    fwrite(stack_play,sizeof(stack_play[0]),MAX,saved);
    fwrite(a,sizeof(a[0]),w,saved);
    fwrite(b,sizeof(b[0][0]),w*h,saved);

    fclose(saved);

}

int loadgame(int game_no)
{
    FILE *load ;
    switch(game_no){
           case 1 : load = fopen("game","rb");
               break ;
           case 2 : load = fopen("game2","rb");
               break ;
           case 3 : load = fopen("game3","rb");
               break ;
    }

     if(load == NULL ){
        printf("ERROR LOADING THE FILE");
        return ;
     }

    char mode ; int w , h ,undos ,  score1 ,  score2 ,  a[w] ,  b[h][w] ,  turn ;

    fread(&w,sizeof(w),1,load);
    fread(&h,sizeof(h),1,load);
    fread(&mode,sizeof(mode),1,load);
    fread(&score1,sizeof(score1),1,load);
    fread(&score2,sizeof(score2),1,load);
    fread(&turn,sizeof(turn),1,load);
    fread(&top,sizeof(top),1,load);
    fread(stack_play,sizeof(stack_play[0]),MAX,load);
    fread(a,sizeof(a[0]),w,load);
    fread(b,sizeof(b[0][0]),w*h,load);

    fclose(load);


    if(mode == 'p')
    {
        pvp(w,h,undos,score1,score2,turn,a,b);
    }
    if(mode == 'c')
    {
        pvc(w,h,undos,score1,score2,turn,a,b);
    }

}
void end_of_game(int score1,int score2)
{
    if (score1==score2){
        printf("Ooops A Draw,No Winner,NO Loser!!");
        Sleep(5000);
        return ;}

    information player;
    if(score1>score2)
    {
        printf("Winner Winner Chicken Dinner , congratulation player1!!\n please enter your name : ");
        fgets(player.name,30,stdin);
        conver_to_lower(player.name);
        player.score=score1;
    }else{
        printf("Winner Winner Chicken Dinner , congratulation player2!!\n please enter your name : ");
        fgets(player.name,30,stdin);
        conver_to_lower(player.name);
        player.score=score2;
    }
    information top_players[100];
    FILE *file;

       int number_of_saves=0,identically=0;
    if((file=fopen("Topscores.binary","rb"))==NULL)
    {
        printf("Error in top score file!!!");
        return ;
    }

    while ( fread(&top_players[number_of_saves],sizeof(information),1,file))
    {

        if(!(strcmp(player.name,top_players[number_of_saves].name)))
           {
               if (player.score>=top_players[number_of_saves].score)
                   top_players[number_of_saves].score=player.score;
                identically=1;
           }
           number_of_saves++;

    }
    if(identically==0)
    {
        strcpy(top_players[number_of_saves].name,player.name);
        top_players[number_of_saves].score=player.score;
        number_of_saves++;
   }

    fclose(file);
     mergeSort(top_players,0,number_of_saves-1);

   FILE *file2;
   if((file2=fopen("Topscores.binary","wb"))==NULL)
    {
        printf("Error in top score file!!!");
        return ;
    }
    for(int i=0;i<number_of_saves;++i)
            fwrite(&top_players[i],sizeof(information),1,file2);

     fclose(file2);

}
 void conver_to_lower(char name [])
 {
     int i=0;
     while(name[i]!='\0')
     {
         name[i]=tolower(name[i]);
         ++i;
     }
 }

void merge(information arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Create temp arrays
    information L[n1], R[n2];
    // Copy data to temp arrays
    // L[] and R[]
    for (i = 0; i < n1; i++)
    {
        L[i].score = arr[l + i].score;
        strcpy(L[i].name,arr[l+i].name);
    }
    for (j = 0; j < n2; j++)
    {
        R[j].score = arr[m + 1 + j].score;
        strcpy(R[j].name,arr[m+1+j].name);
    }
    // Merge the temp arrays back
    // into arr[l..r]
    // Initial index of first subarray
    i = 0;

    // Initial index of second subarray
    j = 0;

    // Initial index of merged subarray
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i].score <= R[j].score)
        {
            arr[k].score = L[i].score;
            strcpy(arr[k].name,L[i].name);
            i++;
        }
        else
        {
            arr[k].score = R[j].score;
            strcpy(arr[k].name,R[j].name);
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k].score = L[i].score;
        strcpy(arr[k].name,L[i].name);
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k].score = R[j].score;
        strcpy(arr[k].name,R[j].name);
        j++;
        k++;
    }
}

void mergeSort(information arr[],int l, int r)
{
    if (l < r)
    {

        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}
void Top_players(int number_of_top)
{
      information top_players[100];
         int x=0;
     FILE * file3;
    if((file3=fopen("Topscores.binary","rb"))==NULL)
    {
        printf("Error in top score file!!!");
        return ;
    }

    while (fread(&top_players[x],sizeof(information),1,file3))x++;
   mergeSort(top_players,0,x-1);
    if(x-1>=number_of_top)
    {
      for(int i=x-1;i>x-1-number_of_top;--i)
        printf(" %-5d %-35s\n",top_players[i].score,top_players[i].name);}
    else{
      for(int i=x-1;i>=0;--i)
        printf(" %-5d %-35s\n",top_players[i].score,top_players[i].name);
        }
    fclose(file3);
}




