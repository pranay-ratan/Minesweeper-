//Project Introduction - Minesweeper is a game which we will play on a square board, and we must click on the board on the cells which do not have a mine. And obviously we don’t know where mines are.
//So, we will be taking input from the user and if a cell where a mine is present is clicked then we lose and the final score will be displayed to the user, else we are still in the game.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define size 10 // defining the size as a macro to prevent hard coding
int a[size][size]; // 2D array to store the dimensions of the board (i.e size x size )
int score=0; // to keep track of score of the user
int result=0; // to keep track of equivalence between coordinates
int x_coor, y_coor;// to take the x and y co-ordinates from user
struct queue
{
    int x;
    int y; // to take the x and y co-ordinates from user
    struct queue *next;
};
struct queuepointers
{
    struct queue *front;
    struct queue *rear;
}
c, m, b; // front and rear pointers for queue of coordinates, mines and bonus
struct queue coor; // queue to store the x and y co-ordinates given by user
struct queue mine; // queue to store the x and y co-ordinates of the mines
struct queue bonus; // queue to store the x and y co-ordinates of the bonus points
void print(); // to print the board after each user input
void random_no_generator(int);
void insert(int, int, int); // to insert the coordinates with mines and bonus into the queues
int traverse(); // to traverse the queues to check for repetition in user input & coordinates with mines and bonus
int unique_mine_coor_counter();
int main()
{
    int i,j;
    for(i=0; i<size ; i++) // for creating the board before starting the game
    {
        for(j=0; j<size ; j++)
        a[i][j]=0;
    }
    random_no_generator(20); // to generate random coordinates of the mines and bonus
    print();
    while(1)
    {
        A:
        printf("\n\nEnter x-coordinate (vertical,from 0 to 9): "); // taking the x-coordinate from the user
        scanf("%d",&x_coor);
        if(x_coor<0 || x_coor>9) // checking whether the x-coordinate is within the range
    {
        printf("Please enter coordinates within the specified range.\n");
        goto A;
    }
    B:
    printf("Enter y-coordinate (horizontal,from 0 to 9): "); // taking the y-coordinate from the user
    scanf("%d",&y_coor);
    if(y_coor<0 || y_coor>9) // checking whether the y-coordinate is within the range
    {
        printf("Please enter coordinates within the specified range.\n");
        goto B;
    }
    if(traverse(1)==2) // checking for repetition
    {
        printf("Cannot repeat the coordinates.\n");
        goto A;
    }
    insert(x_coor,y_coor,1); // inserting x & y-coordinate entered by user in the queue coor
    if(traverse(2)==2) // checking for mines
    {
        a[x_coor][y_coor]=3;
        print();
        printf("Stepped on mine,\nGame over :(\nScore: %d \n",score);
        return 0;
    }
    if(traverse(3)==2) // checking for bonus and incrementing score by 2
    {
        score+=2;
        printf("Bonus :)");
        a[x_coor][y_coor]=2;
        print();
    }
    else // incrementing score by 1
    {
        score+=1;
        a[x_coor][y_coor]=1;
        print();
    }
    if(score==((size*size) - unique_mine_coor_counter())) // max score= 100 - non_mine_coordinates
    printf("You have won the game!!!!\nscore: %d",score);
    }
}
void print()
{
    int i,j;
    printf("\n\n");
    printf(" "); // for allignment while displaying the board
    for(i=0; i<size ; i++)
    printf("%d ",i);
    printf("\n\n");
    for(i=0; i<size ; i++)
    {
        printf("%d ",i);
        if(i<size) // for allignment while displaying the board
        printf(" ");
        for(j=0; j<size ; j++)
        printf("%d ",a[i][j]);
        printf("\n");
    }
}
void random_no_generator(int count) // // to generate 20 (i.e count) random coordinates of the mines and bonus
{
    int i,j,flag=0;
    int num_x, num_y;
    srand(time(NULL)); // to get different random numbers during each execution
    for(j=1;j<=2;j++)
    {
        if(j==1)
        flag=2; // indicates insertion into the mine queue
        else
        flag=3; // indicates insertion into the bonus queue
        for (i=0; i<count; i++)
        {
            num_x= rand() % 10;// generates random numbers in a range of 0 to 9
            num_y= rand() % 10;
            insert(num_x,num_y,flag);
        }
    }
}
void insert(int x_value, int y_value, int flag)
{
    struct queue *newnode;
    newnode=(struct queue*)malloc(sizeof(struct queue));
    newnode->x=x_value;
    newnode->y=y_value;
    newnode->next=NULL;
    switch(flag)
    {
        case 1: // insert coordinates entered by user into coor queue
        if(c.front==NULL) // check for empty queue
        {
            c.front=newnode; // assigning front and rear pointers to first newnode
            c.rear=newnode;
        }
        else
        {
            c.rear->next=newnode; // assigning rear pointer to rest of the newnodes being inserted
            c.rear=newnode;
        }
        coor.x=newnode->x; // inserting newnode in queue
        coor.y=newnode->y;
        break;
        case 2: // insert coordinates of mines
        if(m.front==NULL)
        {
            m.front=newnode;
            m.rear=newnode;
        }
        else
        {
            m.rear->next=newnode;
            m.rear=newnode;
        }
        mine.x=newnode->x;
        mine.y=newnode->y;
        break;
        case 3: // insert coordinates of bonus
        if(b.front==NULL)
        {
            b.front=newnode;
            b.rear=newnode;
        }
        else
        {
            b.rear->next=newnode;
            b.rear=newnode;
        }
    bonus.x=newnode->x;
    bonus.y=newnode->y;
    break;
    }
}
int traverse(int t)
{
    struct queue *temp1;
    if(t==1)
    temp1=c.front; // assigning front node of coor to temp1
    else if(t==2)
    temp1=m.front; // assigning front node of mine to temp1
    else
    temp1=b.front; // assigning front node of bonus to temp1
    while(temp1!=NULL) // loop for traversel, until temp1 reaches the last node of the queue
    {
        result=0;
        if(temp1->x==x_coor)
        result+=1;
        if(temp1->y==y_coor)
        result+=1;
        if(result==2)
        return result; // result=2 is returned if coordinates match
        temp1=temp1->next;
    }
    return result;// result=0 or 1 is returned if coordinates do not match
}
int unique_mine_coor_counter()
{
    int i = 0;
    struct queue *temp1=m.front;
    struct queue *temp2;
    temp1=temp1->next; // to assign temp1 to the second node of mine queue
    while(temp1!=NULL) // running till temp1 reaches last node of mine
    {
        temp2=m.front; // assigning temp2 to the first node of mine queue
        while(temp2!=temp1) // to run the loop until temp2 reaches temp1
        {
            result=0;
            if(temp2->x==temp1->x)
            result+=1;
            if(temp2->y==temp1->y)
            result+=1;
            if(result==2)
        {
            i+=1; // incrementing c if a mine coordinate is repeating
            result=0; // re-initialising result to 0, to check for repetition in rest of the nodes
        }
        temp2=temp2->next;
        }
        temp1=temp1->next;
    }
    return (20-i);
}