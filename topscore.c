#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <ctype.h>
     typedef struct
    {
        char name[30];
        int score ;
    } information;


void end_of_game(int score1,int score2);
 void conver_to_lower(char name []);
 void merge(information arr[], int l, int m, int r);
 void mergeSort(information arr[],int l, int r);
void Top_players(int number_of_top);



int main()
{
end_of_game(21,2);
Top_players(5);

    return 0;
}

void end_of_game(int score1,int score2)
{
    if (score1==score2){
        printf("Ooops A Draw,No Winner,NO Loser!!");
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






// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
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

    // Copy the remaining elements
    // of L[], if there are any
    while (i < n1) {
        arr[k].score = L[i].score;
        strcpy(arr[k].name,L[i].name);
        i++;
        k++;
    }

    // Copy the remaining elements of
    // R[], if there are any
    while (j < n2)
    {
        arr[k].score = R[j].score;
        strcpy(arr[k].name,R[j].name);
        j++;
        k++;
    }
}

// l is for left index and r is
// right index of the sub-array
// of arr to be sorted
void mergeSort(information arr[],int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids
        // overflow for large l and h
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
     if((file3=fopen("Topscores.binary","r"))==NULL);
     {
         printf("Error in file!!");
         return;
     }
    while (fread(&top_players[x],sizeof(information),1,file3))x++;
   // mergeSort(top_players,0,x-1);
    if(x-1>number_of_top)
    {
      for(int i=x-1;i>x-1-number_of_top;--i)
        printf(" %-5d %-30s\n",top_players[x].score,top_players[x].name);}
    else{
      for(int i=x-1;i>=0;--i)
        printf(" %-5d %-30s\n",top_players[x].score,top_players[x].name);
        }
    fclose(file3);
}





