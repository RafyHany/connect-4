

typedef struct{
int WIDTH;
int HEIGHT;
int HIGHTSCORES;
} game;
game parameter;

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
    char conf_2[]="</Configurations>",width_2[]="</Width>",height_2[]="</Height>",highscores_2[]="</Heighscore>";
    int i=0,start_con,end_con,start_w,end_w,start_h,end_h,start_hs,end_hs;
    FILE *file;
    if((file= fopen(path, "r"))==NULL){
        error_path++;
        xml_files();
        return;
    }
    while((ch=fgetc(file))!=EOF){
        if(ch!=' '&&ch!='\n'&&ch!='\t'){           //IGNORING ANY SPACES OR TABS OR BREAKING LINE
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
    for(int p=0,j=start_w+7;j<end_w;++j,++p)
    width[p]=file_without_space[j];
    width[end_w]='\0';



    start_h=our_strstr(height_1,file_without_space);
    end_h=our_strstr(height_2,file_without_space);
    int size_hig=end_h-start_h+1;

        if(start_h==-1||end_h==-1||end_h<start_h||end_h>end_con||start_h<start_con){
            error_path++;
            return xml_files() ;
        }
    char heigh[size_hig];
       for(int h=0,v=start_h+8;v<end_h;++v,++h)
         heigh[h]=file_without_space[v];
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
         highscores[p]=file_without_space[j];
      highscores[end_hs]='\0';



   if(atoi(heigh)<4||atoi(width)<4||atoi(highscores)<4)
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
