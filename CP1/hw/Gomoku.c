#include <stdio.h>
#pragma warning( disable : 4996 )
#include <stdbool.h>
//#include <stdlib.h>
//#include <string.h>

#define SIZE 190

int convert(char k)
{
	char myChar[19] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S' };
	int myInt[19]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};
	for (int i = 0; i < 19; i++)
	{
		if (myChar[i] == k)
		{
			return myInt[i];
		}
	}
}


bool inBoard(int x, int y)
{
	bool flag = true;
	if (x < 0 || x>18)
	{
		flag = false;
	}
	if (y < 0 || y>18)
	{
		flag = false;
	}
	return flag;
}


bool checkWin(int myBoard[SIZE][SIZE])
{
	bool win = false;
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (myBoard[i][j] == 0)
			{
				continue;
			}

            //水平
            int connect = 1;
            //左
            for (int k = j - 1; k >= 0; k--)
            {
                if (myBoard[i][k] != myBoard[i][j])    
                {
                    break;
                }
                else
                    connect++;
            }
            //右
            for (int k = j + 1; k < SIZE; k++)
            {
                if (myBoard[i][k] != myBoard[i][j])  
                {
                    break;
                }
                else
                    connect++;
            }
            //Win
            if (connect >= 5)
            {
                win = true;
                //return win;
            }

            //垂直
            connect = 1;
            //上方
            for (int k = i - 1; k >= 0; k--)
            {
                if (myBoard[k][j] != myBoard[i][j])    
                {
                    break;
                }
                else
                    connect++;
            }
            //下方
            for (int k = i + 1; k < SIZE; k++)
            {
                if (myBoard[k][j] != myBoard[i][j])   
                {
                    break;
                }
                else
                    connect++;
            }
            //Win
            if (connect >= 5)
            {
                win = true;
                //return win
             
            }

            //斜
            connect = 1;
            //左下
            int m = i + 1;
            for (int k = j - 1; k >= 0; k--)
            {
                if (m >= SIZE)    //左下方出界
                {
                    break;
                }
                if (myBoard[m][k] != myBoard[i][j])   
                {
                    break;
                }
                else
                    connect++;
                m++;
            }
            //右上
            m = i - 1;
            for (int k = i + 1; k < SIZE; k++)
            {
                if (m < 0)    //右上方出界
                {
                    break;
                }
                if (myBoard[m][k] != myBoard[i][j])   
                {
                    break;
                }
                else
                    connect++;
                m--;
            }
            //Win
            if (connect >= 5)
            {
                win = true;
                //return win;
            }
       
            connect = 1;
            //左上
            m = i - 1;
            for (int k = j - 1; k >= 0; k--)
            {
                if (m < 0)    //左上方出界
                {
                    break;
                }
                if (myBoard[m][k] != myBoard[i][j])    
                {
                    break;
                }
                else
                    connect++;
                m--;
            }
            //右下
            m = i + 1;
            for (int k = i + 1; k < SIZE; k++)
            {
                if (m >= SIZE)    //右下方出界
                {
                    break;
                }
                if (myBoard[m][k] != myBoard[i][j])    
                {
                    break;
                }
                else
                    connect++;
                m++;
            }
            //Win
            if (connect >= 5)
            {
                win = true;

            }



		}
	}
    return win;
}



bool checkWin2(int myBoard[190][190])
{
    for (int i = 0; i < 19; i++)
    {
        for (int j = 0; j < 19; j++)
        {
            if (myBoard[i][j] == 0)
                continue;
            else if 
                (
                (myBoard[i][j] == myBoard[i][j + 1] && myBoard[i][j] == myBoard[i][j + 2] && myBoard[i][j] == myBoard[i][j + 3] && myBoard[i][j] == myBoard[i][j + 4]) ||
                (myBoard[i][j] == myBoard[i + 1][j] && myBoard[i][j] == myBoard[i + 2][j] && myBoard[i + 3][j] == myBoard[i][j] && myBoard[i][j] == myBoard[i + 4][j]) ||
                (myBoard[i][j] == myBoard[i - 1][j + 1] && myBoard[i][j] == myBoard[i - 2][j + 2] && myBoard[i][j] == myBoard[i - 3][j + 3] && myBoard[i][j] == myBoard[i - 4][j + 4]) ||
                (myBoard[i][j] == myBoard[i + 1][j + 1] && myBoard[i][j] == myBoard[i + 2][j + 2] && myBoard[i][j] == myBoard[i + 3][j + 3] && myBoard[i][j] == myBoard[i + 4][j + 4])
                )
            {
                return true;
            }

        }
    }
    return false;
}





int main()
{
	int black[SIZE][SIZE];
	int white[SIZE][SIZE];

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			black[i][j] = 0;
			white[i][j] = 0;
		}
	}


	char X;
	int x, y;
	int step = 1;


	while(scanf(" %c %d ", &X, &y)!=EOF)
	{
		
		x = convert(X);

		x--; y--;

		if (inBoard(x,y) && black[x][y] ==0 && white[x][y] == 0)
		{
			black[x][y] = 1;
			step++;
            if (checkWin2(black))
            {
                printf("The winner is black.");
                return 0;
            }
		}
		else
		{
			printf("Invalid move at step %d.", step);
			return 0;
			//break;
		}
		




		scanf(" %c %d ", &X, &y);
		x = convert(X);
		x--; y--;

		if (inBoard(x, y) && white[x][y] == 0 && black[x][y] == 0)
		{
			white[x][y] = 1;
			step++;
            if (checkWin2(white))
            {
                printf("The winner is white.");
                return 0;
            }
		}
		else
		{
			printf("Invalid move at step %d.", step);
			return 0;
			//break;
		}


	}

    

    printf("The game is tie.");
    return 0;
 
}

