#include<stdio.h>
int main()
{
    char symbol[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
    board(symbol);


    int option;
    printf("Press 1 to play game with computer\nPress 0 to exit\n");
    scanf("%d",&option);

        if(option==1)
        {
            Input(symbol);

        }
        else if(option==0)
            {
                exit(0);
            }



}
void Input(char symbol[][3])
{
    char choice;
    int r,c;
      for(int i=0;i<9;i+2)
        {

            printf("Enter Position (row,column) :\n");
            scanf("%d",&r);
            scanf("%d",&c);
            if(symbol[r][c]=='1' || symbol[r][c]=='2' || symbol[r][c]=='3' || symbol[r][c]=='4' || symbol[r][c]=='5' || symbol[r][c]=='6' || symbol[r][c]=='7' || symbol[r][c]=='8' || symbol[r][c]=='9')

            {
                symbol[r][c]= 'X';
                int c= winCheck(symbol);
            if(c==1)
            {
                printf("You win");
            }



            }
            board(symbol);
            ComputerInput(symbol);
        }

}
void ComputerInput(char symbol[][3])
{
    int r,c;
    r=rand()%3;
    c=rand()%3;
    if(symbol[r][c]=='1' || symbol[r][c]=='2' || symbol[r][c]=='3' || symbol[r][c]=='4' || symbol[r][c]=='5' || symbol[r][c]=='6' || symbol[r][c]=='7' || symbol[r][c]=='8' || symbol[r][c]=='9')
    {
        symbol[r][c]='0';
        board(symbol);
        winCheck(symbol);
            int c= winCheck(symbol);
            if(c==1)
            {
                printf("Computer wins");
            }
    }

}


int winCheck(char symbol[3][3])
{
    int Dcheck,rDcheck,rowCheck,columnCheck,finalCheck;
    int i=0;
    int j=0;
    while(i<2)//checking diagonal
    {
        if (symbol[i][j]==symbol[i+1][j+1])
            Dcheck=1;
        else if(symbol[i][j]!=symbol[i+1][j+1])
        {
            Dcheck=0;
            break;
        }
        i++;j++;
    }

    i=0;j=2;
    while(i<2)//Check Reverse Diagonal
    {
        if (symbol[i][j]==symbol[i+1][j-1])
            rDcheck=1;
        else if(symbol[i][j]!=symbol[i+1][j+1])
        {
            rDcheck=0;
            break;
        }
        i++;j--;
    }

    for(i=0; i<3; i++){  // checking rows
    if(symbol[i][0]==symbol[i][1] && symbol[i][0]==symbol[i][2])
    {
        rowCheck =1;
    }
    else
    {
        rowCheck=0;
    }

  }

  for(i=0; i<3; i++){  // checking columns
    if(symbol[0][i]==symbol[1][i] && symbol[0][i]==symbol[2][i])
    {
        columnCheck=1;

    }
    else
    {
         columnCheck=0;
    }
         }
    //Final Check
    if (Dcheck==1||rDcheck==1||rowCheck==1||columnCheck==1)
    {
        finalCheck=1;
    }
    else
    {
        finalCheck =0;
    }


    return finalCheck;
}

void board(char symbol[][3])
{
    system("cls");
    printf("\n\n\tTic Tac Toe\n\n");

    printf("Player  (X)  -  Computer (O)\n\n\n");


    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", symbol[0][0], symbol[0][1], symbol[0][2]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", symbol[1][0], symbol[1][1], symbol[1][2]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", symbol[2][0],symbol[2][1],symbol[2][2]);

    printf("     |     |     \n\n");



}
