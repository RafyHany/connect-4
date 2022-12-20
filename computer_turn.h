




//srand(time(NULL)); //this line must be added to main and not in fn

int computer_turn(int width)
{
 int computer_choice=rand()%width+1;
 return computer_choice;
}
