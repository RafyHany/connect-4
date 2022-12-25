#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <windows.h>
//globals



//main functions

int main_menu(void);
void time_passed(time_t start_time);
int computer_turn(int width);
void pvp();
void pvc();
void horizontal_check(int*score,int width_input,int heigh_input,int width,int heigh,int a[][width]);
void vertical_check(int*score,int width_input,int heigh_input,int width,int heigh,int a[][width]);
void diagonal_45_check(int*score,int width_input,int heigh_input,int width,int heigh,int a[][width]);
void diagonal_135_check(int*score,int width_input,int heigh_input,int width,int heigh,int a[][width]);
void check_score(int* score,int width_input,int heigh_input,int width,int heigh,int a[][width]);
void push(int*top,int temp_stack[], int index);
int pop (int*top,int temp_stack[]);
void undo(int undo_stack[],int*top_undo,int redo_stack[],int*top_redo,int a[],int b[][sizeof(a)-1],int *score );

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

    while(n <= 0 || n > w ||a[n]==0)
    {
        gotoxy(35,4);printf("ENTER A VALID INPUT");
        gotoxy(35,5);scanf("%d",&n);
        gotoxy(35,4);printf("                   \n            ");

    }

        fill((6*n) , 7+(3*a[n]) , c);
        SetConsoleTextAttribute(console_color , 15 );
        a[n]-- ;
        return n ;
}



void pvp(void)
{
    system("cls");
    int h = 6 , w = 7 ;
    the_game(h,w);
    draw_the_box(19,5,1,0);
    gotoxy(2,1);printf("for undo enter -> u");
    gotoxy(2,2);printf("for redo enter -> r");
    gotoxy(2,3);printf("for save enter -> s");
    int q ;int score1 = 0 , score2 = 0 ;int n = 0 ;
    char in[100];char op ;
    int a[w+1];
    int b[h][w];
     int top_undo = -1 , top_redo = -1 ;
int undo_stack[6*7] ,  redo_stack[6*7] ;
    make_array(a,w+1,h);
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
            gotoxy(35,5);fgets(in,100,stdin);
            if(atoi(in) != 0 ){
            n = atoi(in);
            n = play(a,n,w,BACKGROUND_RED);
            push(&top_undo , undo_stack , n);
            gotoxy(35,5);printf("                 ");
            b[a[n]][n] = 1 ;
            check_score(&score1,n,a[n],w,h,b);
            gotoxy(35,1);printf("p1 score : %d  -  p2 score : %d",score1,score2);
            i++;
            }
            else
            {
                op = in[0] ;
                switch(op)
                {
                    case 'u' : undo(undo_stack,&top_undo,redo_stack,& top_redo,a,b,&score1);
                      i = i-2;
                      break ;
                    case 'r' : printf("redo");
                      break;
                    case 's' : printf("save");
                      break;
                }
            }
        }
        else{
            gotoxy(35,2); time_passed(start_time);
            gotoxy(35,3);printf("player 2 turn");
            gotoxy(35,5);fgets(in,100,stdin);
            if(atoi(in) != 0 ){
            n = atoi(in);
            n = play(a,n,w,BACKGROUND_GREEN);
            push(&top_undo , undo_stack , n);
            gotoxy(35,5);printf("                 ");
            b[a[n]][n] = -1 ;
            check_score(&score2,n,a[n],w,h,b);
            gotoxy(35,1);printf("p1 score : %d  -  p2 score : %d",score1,score2);
            i++;
            }
             else
            {
                op = in[0] ;
                switch(op)
                {
                    case 'u' : undo(undo_stack,&top_undo,redo_stack,& top_redo,a,b,&score2);
                      i = i - 2 ;
                      break ;
                    case 'r' : printf("redo");
                      break;
                    case 's' : printf("save");
                      break;
                }
            }
        }
    }
    printf("\n");

}

void pvc(void)
{
    system("cls");
    int h = 6 , w = 7 ; int p ;
    the_game(h,w);
    draw_the_box(19,5,1,0);
    gotoxy(2,1);printf("for undo enter -> u");
    gotoxy(2,2);printf("for redo enter -> r");
    gotoxy(2,3);printf("for save enter -> s");
    int q , n , score1 = 0 , score2 = 0 ;
    int a[w+1];
    char in[100];char op ;
    make_array(a,w+1,h);
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

            gotoxy(35,5);fgets(in,100,stdin);

            if(atoi(in) != 0 ){
            n = atoi(in);
            n = play(a,n,w,BACKGROUND_RED);
            gotoxy(35,5);printf("                 ");
            b[a[n]][n] = 1 ;
            check_score(&score1,n,a[n],w,h,b);
            gotoxy(35,1);printf("p1 score : %d  -  p2 score : %d",score1,score2);
            i++;
            }
            else
            {
                op = in[0] ;
                switch(op)
                {
                    case 'u' : printf("undo");
                      break ;
                    case 'r' : printf("redo");
                      break;
                    case 's' : printf("save");
                      break;
                }
            }
        }
        else{
            gotoxy(35,2); time_passed(start_time);
            gotoxy(35,3);printf("computer turn");
             do
             {
              n = computer_turn(w);
             }while(a[n] == 0  );
            gotoxy(35,5);printf("%d",n);
            n = play(a,n,w,BACKGROUND_GREEN);
            b[a[n]][n] = -1 ;
            check_score(&score2,n,a[n],w,h,b);
            gotoxy(35,1);printf("p1 score : %d  -  comp score : %d",score1,score2);
            i++;
        }
    }
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


void push(int*top,int temp_stack[], int index)
{
    ++(*top);
    temp_stack[*top]=index;
}

int pop (int*top,int temp_stack[])
{
 int out_element = temp_stack[*top];
 --(*top);
 return out_element;
}

void undo(int undo_stack[],int*top_undo,int redo_stack[],int*top_redo,int a[],int b[][sizeof(a)-1],int *score )
{
    int score_new = 0,col,out_element,w;
    w=sizeof(a)-1;
    col=undo_stack[*(top_undo)];
    check_score(&score_new,col,a[col],w,a[0],b);
    *score = *score - score_new;
    out_element=pop(top_undo,undo_stack);
    push(top_redo,redo_stack,out_element);
    b[a[col]][col-1]=0;
    fill(6*col,7+(3*a[col]),15);
    ++a[col];
}

