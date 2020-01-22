// 八個皇后.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <time.h>

using namespace std;

int main()
{
	const int row = 8;    //行
	const int column = 8; //列
	int chessNum = 1;//皇后數量
	int	checkerboard[row][column];//棋盤
	int rndRow;
	int rndColumn;
	int tempi;
	int tempj;
	int failTime=0;
	bool cleanRow = true;//判斷"行"是否有撞到皇后
	bool cleanColumn = true;//判斷"列"是否有撞到皇后
	bool cleanOblique = true;//判斷"斜"是否有撞到皇后
	unsigned seed;






	while (8>chessNum )
	{
		if (8>chessNum ) 
		{
			
			for (int i = 0; i < column; i++) { //棋盤歸零
				for (int j = 0; j < row; j++)
				{
					checkerboard[j][i] = 0;
				}
			}
#pragma region 使每次結果不一
			seed = (unsigned)time(NULL);
			srand(seed);
			rndRow = rand() % 8;
			rndColumn = rand() % 8;
			checkerboard[rndRow][rndColumn] = 1;
#pragma endregion
			chessNum = 1;
		}

		for (int i = 0; i < column; i++)//y軸
		{

			for (int j = 0; j < row; j++)//x軸
			{
				for (int r = 0; r < row; r++)		//判斷當前數值的"行"有無皇后(x軸)
				{
					cleanRow = true;
					cleanColumn = true;
					cleanOblique = true;
					if (checkerboard[r][i] == 1)
					{
						cleanRow = false;
						r = 0;
						break;
					}
				}
				/*
				if (!cleanRow)
				{
					break;
				}
				*/
				for (int c = 0; c < column; c++)		//判斷當前數值的"列"有無皇后(y軸)
				{
					if (checkerboard[j][c] == 1)
					{
						cleanColumn = false;
						c = 0;
						break;
					}
				}
#pragma region 檢查交叉
				tempi = i;
				tempj = j;
				while (cleanOblique)     //檢查右上
				{

					tempj++;
					tempi++;
					if (tempj == row || tempi == column)
					{
						break;
					}
					else if (checkerboard[tempj][tempi] == 1)
					{
						cleanOblique = false;
						break;
					}
				

				}
				tempi = i;
				tempj = j;
				while (cleanOblique) //檢查左下
				{

					tempj--;
					tempi--;
					if (tempj < 0 || tempi < 0)
					{
						break;
					}
					else if (checkerboard[tempj][tempi] == 1)
					{
						cleanOblique = false;
						break;
					}				
				}
				tempi = i;
				tempj = j;
				while (cleanOblique)//檢查右下
				{
					tempj++;
					tempi--;
					if (tempj == row || tempi < 0)
					{
						break;
					}
					else if (checkerboard[tempj][tempi] == 1)
					{
						cleanOblique = false;
						break;
					}
			
				}
				tempi = i;
				tempj = j;
				while (cleanOblique)//檢查左上
				{

					tempj--;
					tempi++;
					if (tempj < 0 || tempi == column)
					{
						break;
					}
					else if (checkerboard[tempj][tempi] == 1)
					{
						cleanOblique = false;
						break;
					}
				
				}
#pragma endregion
				if (cleanRow && cleanColumn && cleanOblique)
				{
					checkerboard[j][i] = 1;
					chessNum++;
					//break;
				}

			}
		}
		if (8>chessNum )
		{
			failTime++;
		}
	}
	for (int i = 0; i < column; i++)//輸出棋盤
	{
		for (int j = 0; j < row; j++)
		{
			if (j == row - 1)
			{
				cout << checkerboard[j][i] << "\n";
			}
			else {
				cout << checkerboard[j][i];
			}
		}
	}

	cout << "失敗:" << failTime << endl;

}

