void push(int*top,int temp_stack[], int index)
{
    ++(*top);
    temp_stack[*top]=index;
}

int pop (int*top,int temp_stack)
{
 int out_element=temp_stack[*top];
 --(*top);
 return out_element;
}

void undo(int undo_stack[],int*top_undo,int redo_stack[],int*top_redo,int a[],int b[],int *score )
{
    int score_new=0,col,out_element,w;
    w=sizeof(a)/sizeof(a[0])-1;
    col=undo_stack[*(top_undo)]-1;
    check_score(&score_new,col,a[col],w,a[0],b[][w]);
    *score=*score-*score_new;
    out_element=pop(*top_undo,undo_stack);
    push(*top_redo,redo_stack,out_element);
    b[a[col][col-1]=0;
    ++a[col];
}
