#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <windows.h>
//globals

#define MAX   6*7
int stack_play[MAX];
int top = -1;
int h = 6 ;
int w = 7 ;

//main functions

int main_menu(void);
void time_passed(time_t start_time);
int computer_turn(int width);
int pvp();
int pvc();
void horizontal_check(int*score,int width_input,int heigh_input,int width,int heigh,int a[][width]);
void vertical_check(int*score,int width_input,int heigh_input,int width,int heigh,int a[][width]);
void diagonal_45_check(int*score,int width_input,int heigh_input,int width,int heigh,int a[][width]);
void diagonal_135_check(int*score,int width_input,int heigh_input,int width,int heigh,int a[][width]);
void check_score(int* score,int width_input,int heigh_input,int width,int heigh,int a[][width]);
void push(int n);
int pop ();
int undo(int a[] );
int redo(int a [] , int w , int c , int score , int undos , int b[][7]);


int main()
{
    switch (main_menu())
    {
        case 0 : if (pvp()){
          main();
          }
          break ;
        case 1 : if (pvc()){
          main();
          }
          break ;
      /*case 2 : loadgame(1);
          break;
        case 3 : loadgame(2);
          break;
        case 4 : loadgame(3);
          break;
        case 5 ; return 0;*/
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
        gotoxy(0+6*k,8);printf(" %d ",k);
    }
    for(int i = 0 ; i < h ; i++){
        for( int j = 0 ; j < w ; j++){
            draw_the_box(4,3,5 + 6*j,9 + i*3);
        }
    }

}


void make_array(int a[] , int w , int h)
{
    for(int i = 0 ; i < w ; i++)
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

    while(n < 0 || n > w ||a[n]==0)
    {
        gotoxy(35,4);printf("ENTER A VALID INPUT");
        gotoxy(35,5);scanf("%d",&n);
        n = n-1 ;
        gotoxy(35,4);printf("                   \n            ");

    }

        fill((6*(n+1)) , 7+(3*a[n]) , c);
        SetConsoleTextAttribute(console_color , 15 );
        a[n]-- ;
        return n ;
}



int pvp(void)
{
    system("cls");
    int h = 6 , w = 7 , undos = 0 ;
    the_game(h,w);
    draw_the_box(19,6,1,0);
    gotoxy(2,1);printf("to undo enter -> u ");
    gotoxy(2,2);printf("to redo enter -> r ");
    gotoxy(2,3);printf("to save enter -> s ");
    gotoxy(2,4);printf("to quit enter -> q ");
    int q ;int score1 = 0 , score2 = 0 ;int n = 0 ;
    char in[100];char op ;
    int a[w];
    int b[h][w];
    make_array(a,w,h);
    for(int i = 0 ; i < h ; i++){
         for(int j = 0 ; j < w ; j++){
            b[i][j] = 0 ;
         }
    }
    time_t start_time=time(NULL);
    int i = 0;
    while(i < w*h)
    {
        q = i % 2 ;
        if ( q == 0){
            gotoxy(35,2); time_passed(start_time);
            gotoxy(35,3);printf("player 1 turn");
            gotoxy(35,1);printf("p1 score : %d  -  p2 score : %d",score1,score2);
            gotoxy(35,0);printf("p1 moves : %d  -  p2 moves : %d",i/2,i/2);
            gotoxy(35,5);fgets(in,100,stdin);
            if(atoi(in) != 0 ){
            n = atoi(in);
            n = n - 1 ;
            n = play(a,n,w,BACKGROUND_RED);
            push(n);
            gotoxy(35,5);printf("                 ");
            b[a[n]][n] = 1 ;
            check_score(&score1,n,a[n],w,h,b);
            i++;
            undos = 0 ;
            }
            else
            {
                op = in[0] ;
                switch(op)
                {
                    case 'u' : if(undo(a)){
                       i-- ;
                       b[a[stack_play[top]]][stack_play[top]] = 0 ;
                       undos++ ;
                    }
                       break ;
                    case 'r' : if(redo(a,w,BACKGROUND_RED,score1,undos,b)){
                       i++;
                       b[a[stack_play[top]]][stack_play[top]] = 1 ;
                       undos--;
                    }
                      break;
                    case 's' : printf("save");
                      break;
                    case 'q' : return 6 ;
                    break;
                }
            }
        }
        else{
            gotoxy(35,2); time_passed(start_time);
            gotoxy(35,3);printf("player 2 turn");
            gotoxy(35,1);printf("p1 score : %d  -  p2 score : %d",score1,score2);
            gotoxy(35,0);printf("p1 moves : %d  -  p2 moves : %d",(i/2)+1,i/2);
            gotoxy(35,5);fgets(in,100,stdin);
            if(atoi(in) != 0 ){
            n = atoi(in);
            n = n-1 ;
            n = play(a,n,w,BACKGROUND_GREEN);
            push(n);
            gotoxy(35,5);printf("                 ");
            b[a[n]][n] = -1 ;
            check_score(&score2,n,a[n],w,h,b);
            i++;
            undos = 0 ;
            }
             else
            {
                op = in[0] ;
                switch(op)
                {
                    case 'u' : if(undo(a)){
                       i-- ;
                       b[a[stack_play[top]]][stack_play[top]] = 0 ;
                       undos++ ;
                    }
                      break ;
                    case 'r' : if(redo(a,w,BACKGROUND_GREEN,score2,undos,b)){
                       i++;
                       b[a[stack_play[top]]][stack_play[top]] = -1 ;
                       undos-- ;
                    }
                      break;
                    case 's' : printf("save");
                      break;
                    case 'q' : return 6 ;
                      break;
                }
            }
        }
    }
    printf("\n");
        return 6 ;
}

int pvc(void)
{
    system("cls");
    int h = 6 , w = 7 ; int p , undos = 0 ;
    the_game(h,w);
    draw_the_box(19,6,1,0);
    gotoxy(2,1);printf("to undo enter -> u ");
    gotoxy(2,2);printf("to redo enter -> r ");
    gotoxy(2,3);printf("to save enter -> s ");
    gotoxy(2,4);printf("to quit enter -> q ");
    int q , n , score1 = 0 , score2 = 0 ;
    int a[w];
    char in[100];char op ;
    make_array(a,w,h);
    int b[h][w];
    for(int i = 0 ; i < h ; i++){
         for(int j = 0 ; j < w ; j++){
            b[i][j] = 0 ;
         }
    }
    time_t start_time=time(NULL);
    int i = 0 ;
    while(i < w*h)
    {
        q = i % 2 ;
        if ( q == 0){
            gotoxy(35,2); time_passed(start_time);
            gotoxy(35,3);printf("player 1 turn");
            gotoxy(35,1);printf("p1 score : %d  -  p2 score : %d",score1,score2);
            gotoxy(35,0);printf("p1 moves : %d  -  p2 moves : %d",i/2,i/2);
            gotoxy(35,5);fgets(in,100,stdin);
            if(atoi(in) != 0 ){
            n = atoi(in);
            n = n-1 ;
            n = play(a,n,w,BACKGROUND_RED);
            push(n);
            gotoxy(35,5);printf("                 ");
            b[a[n]][n] = 1 ;
            check_score(&score1,n,a[n],w,h,b);
            i++;
            undos = 0;
            }
            else
            {
                op = in[0] ;
                switch(op)
                {
                     case 'u' :if( undo(a)){
                      i-- ;
                      b[a[stack_play[top]]][stack_play[top]] = 0 ;
                     }
                      if(undo(a)){
                      i-- ;
                      b[a[stack_play[top]]][stack_play[top]] = 0 ;
                      undos++ ;
                      }
                      break ;
                    case 'r' : if(redo(a,w,BACKGROUND_RED,score1,undos,b)){
                       i++;
                       b[a[stack_play[top]]][stack_play[top]] = 1 ;
                       }
                       if(redo(a,w,BACKGROUND_GREEN,score2,undos,b)){
                       b[a[stack_play[top]]][stack_play[top]] = 1 ;
                       i++;
                       undos--;
                       }
                      break;
                    case 's' : printf("save");
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
            gotoxy(35,0);printf("p1 moves : %d  -  p2 moves : %d",i/2,i/2);
             do
             {
              n = computer_turn(w-1);
             }while(a[n] == 0  );
            n = play(a,n,w,BACKGROUND_GREEN);
            push(n);
            b[a[n]][n] = -1 ;
            check_score(&score2,n,a[n],w,h,b);
            i++;
        }
    }
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
 if(width_input-2>=0&&heigh_input+2<=heigh&&width_input+1<=width&&heigh_input-1>=0)
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

int undo(int a[])
{
    if(isempty()){
        gotoxy(35,4);printf("NO MORE UNDO     ");
        return 0 ;
    }
    int var = pop() ;
    a[var]++;
    fill((6*(var+1)) , 7+(3*a[var]) , 15);
    return 1 ;
}

int redo(int a [] , int w , int c , int score , int undos ,int b[][7])
{
    if(isfull() || undos <= 0){
        gotoxy(35,4);printf("NO MORE REDO     ");
        return 0 ;
        }
     else{
    play(a,stack_play[++top],w,c);
    check_score(&score,stack_play[top],a[stack_play[top]],w,h,b);
    return 1 ;
}

}
