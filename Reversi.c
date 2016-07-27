#include<stdio.h>
#include<stdlib.h>

#define ROW 10
#define COL 10
void checkForBlack(int **);
void checkForWhite(int **);
void inputByBlack(int **);
void printGame(int **);
void computerMove(int **);
void bestComputerMove(int **);
int chooseMaximumTwo(int **,int tempRow , int tempCol);

//int m = 0;

int main()
{
    
    int **board = ( int ** )malloc( sizeof(int *) * ROW );
    
    for (int i=0; i<ROW; i++)
    {
        board[i] = ( int *)malloc(sizeof(int) * COL);
        
    }
    
    for( int i=0; i<ROW; i++ )
    {
        for( int j=0; j<COL; j++ )
        {
            board[i][j] = 0;
            if(i==4 && j==4)
            {
                board[i][j] = 2;
            }
            else if(i==4 && j==5)
            {
                board[i][j] = 1;
            }
            else if(i==5 && j==4)
            {
                board[i][j] = 1;
            }
            else if(i==5 && j==5)
            {
                board[i][j] = 2;
            }
        }
    }
    
    printGame(board);
    
    printf("\n 1 means Black \n 2 means White \n 3 means possible move\n ");
    printf("");
    
        int choice;
        printf("\nEnter (Black)1 or (white)2\n");
        scanf("%d",&choice);
        
        switch (choice) {
            case 1:
                printf("\nYou choose Black(1) & computer is white(2)\n");
                while (1) {
                    
                    checkForBlack(board);
                }
                
                break;
            case 2:
                printf("\nYou choose white(2) & computer is Black(1)\n");
                while (1) {
                     checkForWhite(board);
                }
               
                break;
            default:
                printf("Invalid choice");
                break;
              
        
        
    }
    return 0;
}
//possible moves for black
void checkForBlack(int **board)
{
    
    for(int i=0; i<ROW; i++)
    {
        for(int j=0; j<COL; j++)
        {
            if(board[i][j] == 1)
            {
                
                //for horizontal
                if(board[i][j-1] == 2 )
                {
                    board[i][j-2] = 3;
                }
                else if( board[i][j+1] == 2)
                {
                     board[i][j+2] = 3;
                }
                //for vertical
                if(board[i-1][j] == 2 )
                {
                    board[i-2][j] = 3;
                }
                else if( board[i+1][j] == 2 )
                {
                    board[i+2][j] = 3;
                }
                //for diagonal
                else if( board[i-1][j+1] == 2)
                {
                    board[i-2][j+2] = 3;
                }
                else if(board[i+1][j+1] == 2)
                {
                    board[i+2][j+2] = 3;

                }
                else if( board[i-1][j-1] == 2)
                {
                    board[i-2][j-2] = 3;
                }
                else if(board[i+1][j-1] == 2)
                {
                    board[i+2][j-2] = 3;
                }
                else
                {
                    board[i][j] = 0;
                }
                
            }
            
            
        }
       
    }
    //print updated board
    printGame(board);
    inputByBlack(board);
    
    
}
void inputByBlack(int **board)
{
    int locationRow,locationCol;
    for(int i=0; i<ROW; i++)
    {
        for(int j=0; j<COL; j++)
        {
            if(board[i][j] == 3)
            {
                printf("Possible moves at row %d and col %d\n",i,j);
        
            }
        }
        
    }
    printf("Enter Row\n");
    scanf("%d",&locationRow);
    printf("Enter Col\n");
    scanf("%d",&locationCol);
    int tempRow = locationRow;
    int tempCol = locationCol;
    //vertical downwards
    if(board[locationRow+1][locationCol] == 2)
    {
        while (board[locationRow][locationCol] != 1)
        {
        
            board[locationRow][locationCol] = 1;
        
            locationRow++;
        }
    }
        //vertical upwards
    else if(board[locationRow-1][locationCol] == 2)
    {
        locationRow = tempRow;
        locationCol = tempCol;

        while (board[locationRow][locationCol] != 1)
        {
            
            board[locationRow][locationCol] = 1;
            
            locationRow--;
        }
    }
    //horizontal left
    else if(board[locationRow][locationCol-1] == 2)
    {
        locationRow = tempRow;
        locationCol = tempCol;
        
        while (board[locationRow][locationCol] != 1)
        {
            
            board[locationRow][locationCol] = 1;
            
            locationCol--;
        }

    }
    
    
    
    //horizontal right
    else if(board[locationRow][locationCol+1] == 2)
    {
        locationRow = tempRow;
        locationCol = tempCol;
        
        while (board[locationRow][locationCol] != 1)
        {
            
            board[locationRow][locationCol] = 1;
            
            locationCol++;
        }
        
    }
    //diagonal
    else if(board[locationRow-1][locationCol+1] == 2)
    {
        locationRow = tempRow;
        locationCol = tempCol;
        
        while (board[locationRow][locationCol] != 1)
        {
            
            board[locationRow][locationCol] = 1;
            
            locationRow--;
            locationCol++;
        }
    }
    
   else if(board[locationRow+1][locationCol-1] == 2)
   {
       locationRow = tempRow;
       locationCol = tempCol;
       
       while (board[locationRow][locationCol] != 1)
       {
           
           board[locationRow][locationCol] = 1;
           
           locationRow++;
           locationCol--;
       }

   }
    
    
    else if(board[locationRow+1][locationCol+1] == 2)
    {
        locationRow = tempRow;
        locationCol = tempCol;
        
        while (board[locationRow][locationCol] != 1)
        {
            
            board[locationRow][locationCol] = 1;
            
            locationRow++;
            locationCol++;
        }

    }
    
    else if(board[locationRow-1][locationCol-1] == 2)
    {
        locationRow = tempRow;
        locationCol = tempCol;
        
        while (board[locationRow][locationCol] != 1)
        {
            
            board[locationRow][locationCol] = 1;
            
            locationRow--;
            locationCol--;
        }

    }
    
    for(int i=0; i<ROW; i++)
    {
        for(int j=0; j<COL; j++)
        {
            if(board[i][j] == 3)
            {
                board[i][j] = 0;
            }
        }
    }
    
    printGame(board);
    printf("\nComputer Move\n");
    computerMove(board);
    
    
    
}

void computerMove(int **board)
{
    
    int i=0,j=0;
    for(int i=0; i<ROW; i++)
    {
        for(int j=0; j<COL; j++)
        {
            if(board[i][j] == 2)
            {
                
                //for horizontal
                if(board[i][j-1] == 1 && j-2 >= 0 )
                {
                    board[i][j-2] = 3;
                }
                else if( board[i][j+1] == 1  && j+2 <= 9 )
                {
                    board[i][j+2] = 3;
                }
                //for vertical
                if(board[i-1][j] == 1 && i-2 >= 0 )
                {
                    board[i-2][j] = 3;
                }
                else if( board[i+1][j] == 1 && i+2 <= 9 )
                {
                    board[i+2][j] = 3;
                }
                //for diagonal
                else if( board[i-1][j+1] == 1 && i-2 >= 0 && j+2 <=9 )
                {
                    board[i-2][j+2] = 3;
                }
                else if(board[i+1][j+1] == 1 && i+2 <=9 && j+2 <=9 )
                {
                    printf("True");
                    board[i+2][j+2] = 3;
                    
                }
                else if( board[i-1][j-1] == 1 && i-2 >=0 && j-2 >=0 )
                {
                    board[i-2][j-2] = 3;
                }
                else if(board[i+1][j-1] == 1 && i+2 <= 9 && j-2 >=0 )
                {
                    board[i+2][j-2] = 3;
                }
                else
                {
                    printf("No moves left");
                }
                
            }
        }
    }
    
    bestComputerMove(board);
    
    
}

void bestComputerMove(int **board)
{
    
    int arrayScore[10];
    int tempScore = 0;
    int i=0,j=0;
    int tempRow,tempCol,currentScore,currentRow,CurrentCol;
   
    for( i=0; i<ROW; i++)
    {
        for( j=0; j<COL; j++)
        {
            
            if(board[i][j] == 3)
            {
                //store the best score
               currentScore = chooseMaximumTwo(board,i,j);
              
                if(tempScore < currentScore)
                {
                    tempScore = currentScore;
                    tempRow = i;
                    tempCol = j;
                }
                else if(tempScore == currentScore)
                {
                    tempScore = tempScore;
                    tempRow = tempRow;
                    tempCol = tempCol;
                }
                
                
            }
            
            
        }
       
    }
    printf("currentScore %d\n",tempScore);
    printf("temp row %d\n",tempRow);
    printf("temp col %d\n",tempCol);
    exit(1);
 
    currentRow = tempRow;
    CurrentCol = tempCol;
    
    if(board[currentRow+1][CurrentCol] == 1)
    {
        while (board[currentRow][CurrentCol] != 2)
        {
            
            board[currentRow][CurrentCol] = 2;
            
            currentRow++;
        }
    }
    //vertical upwards
    
    else if(board[currentRow-1][CurrentCol] == 1)
    {
        currentRow = tempRow;
        CurrentCol = tempCol;

        while (board[currentRow][CurrentCol] != 2)
        {
            
            board[currentRow][CurrentCol] = 2;
            
            currentRow--;
        }
    }
    //horizontal left
   
    else if(board[currentRow][CurrentCol-1] == 1)
    {
        currentRow = tempRow;
        CurrentCol = tempCol;

        
        while (board[currentRow][CurrentCol] != 2)
        {
            
            board[currentRow][CurrentCol] = 2;
            
            CurrentCol--;
        }
        
    }
    
    
    
    //horizontal right
   
    else if(board[currentRow][CurrentCol+1] == 1)
    {
        currentRow = tempRow;
        CurrentCol = tempCol;

        
        while (board[currentRow][CurrentCol] != 2)
        {
            
            board[currentRow][CurrentCol] = 2;
            
            CurrentCol++;
        }
        
    }
    //diagonal
   
    else if(board[currentRow-1][CurrentCol+1] == 1)
    {
        
        currentRow = tempRow;
        CurrentCol = tempCol;
        
        while (board[currentRow][CurrentCol] != 2)
        {
            
            board[currentRow][CurrentCol] = 2;
            
            currentRow--;
            CurrentCol++;
        }
    }
    
    
    else if(board[currentRow+1][CurrentCol-1] == 1)
    {
        currentRow = tempRow;
        CurrentCol = tempCol;
        
        while (board[currentRow][CurrentCol] != 2)
        {
            
            board[currentRow][CurrentCol] = 2;
            
            currentRow++;
            CurrentCol--;
        }
        
    }
    
   
    else if(board[currentRow+1][CurrentCol+1] == 1)
    {
        currentRow = tempRow;
        CurrentCol = tempCol;
        while (board[currentRow][CurrentCol] != 2)
        {
            
            board[currentRow][CurrentCol] = 2;
            
            currentRow++;
            CurrentCol++;
        }
        
    }
    
   
    else if(board[currentRow-1][CurrentCol-1] == 2)
    {
        currentRow = tempRow;
        CurrentCol = tempCol;
        while (board[currentRow][CurrentCol] != 1)
        {
            
            board[currentRow][CurrentCol] = 1;
            
            currentRow--;
            CurrentCol--;
        }
        
    }

    
    for(int i=0; i<ROW; i++)
    {
        for(int j=0; j<COL; j++)
        {
            if(board[i][j] == 3)
            {
                board[i][j] = 0;
            }
        }
    }
    printGame(board);
    
    
    
}

int chooseMaximumTwo(int **board,int tempRow , int tempCol)
{
    int locationRow = tempRow;
    int locationCol = tempCol;
    int count = 0;
    int arrayScore[20];
    int i=0,j=0;
    
   
    
    int **tempBoard = ( int ** )malloc( sizeof(int *) * ROW );
    
    for (int i=0; i<ROW; i++)
    {
        tempBoard[i] = ( int *)malloc(sizeof(int) * COL);
        
    }
    
    for( int i=0; i<ROW; i++ )
    {
        for( int j=0; j<COL; j++ )
        {
            tempBoard[i][j] = board[i][j];
            
        }
    }

    if(tempBoard[locationRow+1][locationCol] == 1 )
    {
        while (tempBoard[locationRow][locationCol] != 2  )
        {
            
            tempBoard[locationRow][locationCol] = 2;
           
            locationRow++;
            
        }
        
        
        
    }
    //vertical upwards
    else if(tempBoard[locationRow-1][locationCol] == 1)
    {
        locationRow = tempRow;
        locationCol = tempCol;
        
        while (tempBoard[locationRow][locationCol] != 2)
        {
            
            tempBoard[locationRow][locationCol] = 2;
            
            locationRow--;
        }
    }
    //horizontal left
    else if(tempBoard[locationRow][locationCol-1] == 1)
    {
        locationRow = tempRow;
        locationCol = tempCol;
        
        while (tempBoard[locationRow][locationCol] != 2)
        {
            
            tempBoard[locationRow][locationCol] = 2;
            
            locationCol--;
        }
        
    }
    
    
    
    //horizontal right
    else if(tempBoard[locationRow][locationCol+1] == 1)
    {
        locationRow = tempRow;
        locationCol = tempCol;
        
        while (tempBoard[locationRow][locationCol] != 2)
        {
            
            tempBoard[locationRow][locationCol] = 2;
            
            locationCol++;
        }
        
    }
    //diagonal
    else if(tempBoard[locationRow-1][locationCol+1] == 1)
    {
        locationRow = tempRow;
        locationCol = tempCol;
        
        while (tempBoard[locationRow][locationCol] != 2)
        {
            
            tempBoard[locationRow][locationCol] = 2;
            
            locationRow--;
            locationCol++;
        }
    }
    
    else if(tempBoard[locationRow+1][locationCol-1] == 1)
    {
        locationRow = tempRow;
        locationCol = tempCol;
        
        while (tempBoard[locationRow][locationCol] != 2)
        {
            
            tempBoard[locationRow][locationCol] = 2;
            
            locationRow++;
            locationCol--;
        }
        
    }
    
    
    else if(tempBoard[locationRow+1][locationCol+1] == 1)
    {
        locationRow = tempRow;
        locationCol = tempCol;
        
        while (tempBoard[locationRow][locationCol] != 2)
        {
            
            tempBoard[locationRow][locationCol] = 2;
            
            locationRow++;
            locationCol++;
        }
        
    }
    
    else if(tempBoard[locationRow-1][locationCol-1] == 1)
    {
        locationRow = tempRow;
        locationCol = tempCol;
        
        while (tempBoard[locationRow][locationCol] != 2)
        {
            
            tempBoard[locationRow][locationCol] = 2;
            
            locationRow--;
            locationCol--;
        }
        
    }
    
    for(i=0; i<ROW; i++)
    {
        for (j=0; j<COL; j++)
        {
            if(tempBoard[i][j] == 2)
            {
                count++;
            }
        }
    }
    
 return count;
    
}


//possible moves for white
void checkForWhite(int **board)
{
    for(int i=0; i<ROW; i++)
    {
        for(int j=0; j<COL; j++)
        {
            if(board[i][j] == 2)
            {
                
                //for horizontal
                if(board[i][j-1] == 1 )
                {
                    board[i][j-2] = 3;
                }
                else if( board[i][j+1] == 1)
                {
                    board[i][j+2] = 3;
                }
                //for vertical
                if(board[i-1][j] == 1 )
                {
                    board[i-2][j] = 3;
                }
                else if( board[i+1][j] == 1 )
                {
                    board[i+2][j] = 3;
                }
                //for diagonal
                else if( board[i-1][j+1] == 1)
                {
                    board[i-2][j+2] = 3;
                }
                else if(board[i+1][j+1] == 1)
                {
                    board[i+2][j+2] = 3;
                    
                }
                else if( board[i-1][j-1] == 1)
                {
                    board[i-2][j-2] = 3;
                }
                else if(board[i+1][j-1] == 1)
                {
                    board[i+2][j-2] = 3;
                }
                else
                {
                    board[i][j] = 0;
                }
                
            }
            
            
        }
        
    }
    //print updated board
    printGame(board);

}

void printGame(int **board)
{
    int i=0,j=0;
    for(i=0; i<ROW; i++)
    {
        for(j=0; j<COL; j++)
        {
            printf("%d",board[i][j]);
            printf("  ");
        }
        printf("\n");

    }
}




