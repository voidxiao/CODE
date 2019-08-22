#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include <time.h>



int main(void)
{

	srand((unsigned int)time(NULL));
	FILE *best = NULL;//最高分数文件指针
	int bestBuffer = 0;
	if ((best = fopen("best.bin", "r")) == NULL)//如果文件为空  创建文件并写入最高分数0
	{
		best = fopen("best.bin", "a");
		fwrite(&bestBuffer, 4, 1, best);
		fclose(best);
	}
	else//如果文件不为空  读取最高分数写入最高分数储存内存  让最高分数显示出来
	{
		//best = fopen("best.bin", "a");
		fread(&bestBuffer, 4, 1, best);
		fclose(best);
	}


	int Die = 0, die = 0;
	int num = 0;//分数
	int SnakeHead[3] = { 10,30,1 };//蛇头控制
	int SnakeBody[100][3] = { {10,32,1},{10,34,1} };//初始化两节蛇身
	int SnakeLong = 3;
	int RealSnakeLong = 2;
	int SnakeLieRecord[6] = { 0 };
	int Food = 0;//食物控制
	int FoodX, FoodY;
	int i, j;//循环控制变量
    char SnakeBackground[20][44] = { "█████████████████████\n",
									 "█                                      █\n",
									 "█                                      █\n",
									 "█                                      █\n",
									 "█                                      █\n",
									 "█                                      █\n",
									 "█                                      █\n",
									 "█                                      █\n",
									 "█                                      █\n",
									 "█                                      █\n",
									 "█                                      █\n",
									 "█                                      █\n",
									 "█                                      █\n",
									 "█                                      █\n",
									 "█                                      █\n",
									 "█                                      █\n",
									 "█                                      █\n",
									 "█                                      █\n",
									 "█                                      █\n",
									 "█████████████████████", };

	//第一界面
	printf("\n\n\t\t\t\t    《贪吃蛇》");
	printf("\n\n\t\t\t\t点击任意键开始游戏");
	_getch();
	while (1)
	{

		//键盘控制蛇的方向
		if (GetAsyncKeyState('W') && SnakeHead[2] != 2)
		{
			SnakeHead[2] = 5;
		}
		if (GetAsyncKeyState('S') && SnakeHead[2] != 5)
		{
			SnakeHead[2] = 2;
		}
		if (GetAsyncKeyState('A') && SnakeHead[2] != 3)
		{
			SnakeHead[2] = 1;
		}
		if (GetAsyncKeyState('D') && SnakeHead[2] != 1)
		{
			SnakeHead[2] = 3;
		}

		//放置食物(星星)
		while (1)
		{
		step1:
			if (Food == 0)
			{
				FoodX = rand() % 18 + 1;
				FoodY = rand() % 19 + 2;
				if (FoodX % 2 == 0 && FoodY % 2 == 0)
				{
					for (i = 1; i < SnakeLong; i++)
					{
						if (FoodX == SnakeHead[0] && FoodY == SnakeHead[1])
						{
							goto step1;
						}
						if (FoodX == SnakeBody[i][0] && FoodY == SnakeBody[i][1])
						{
							goto step1;
						}
					}
					strncpy(&SnakeBackground[FoodX][FoodY], "☆", 2);
					Food = 1;
					break;
				}
				else
				{
					continue;
				}
			}
			else
			{		//防止食物被蛇覆盖后而消失  让它消失后重新打印
				strncpy(&SnakeBackground[FoodX][FoodY], "☆", 2);
				break;
			}
		}

		//放置蛇起点
		strncpy(&SnakeBackground[SnakeHead[0]][SnakeHead[1]], "█", 2);
		strncpy(&SnakeBackground[SnakeBody[0][0]][SnakeBody[0][1]], "█", 2);
		strncpy(&SnakeBackground[SnakeBody[1][0]][SnakeBody[1][1]], "█", 2);
		//放置蛇增长部分
		for (RealSnakeLong = 2; RealSnakeLong < SnakeLong - 1; RealSnakeLong++)
		{
			strncpy(&SnakeBackground[SnakeBody[RealSnakeLong][0]][SnakeBody[RealSnakeLong][1]], "█", 2);
		}

		//判断蛇撞蛇身
		for (j = 3; j < SnakeLong; j++)
		{
			if (SnakeHead[0] == SnakeBody[j][0] && SnakeHead[1] == SnakeBody[j][1])
			{
				goto over;
			}
		}

		//吃食物蛇变长
		if (SnakeBody[SnakeLong - 2][2] == 1)
		{
			if (SnakeHead[0] == FoodX && SnakeHead[1] == FoodY)
			{
				SnakeBody[SnakeLong - 1][0] = SnakeBody[SnakeLong - 2][0];
				SnakeBody[SnakeLong - 1][1] = SnakeBody[SnakeLong - 2][1] + 2;
				SnakeLong++;
				Food = 0;
				num++;
			}
		}
		if (SnakeBody[SnakeLong - 2][2] == 2)
		{
			if (SnakeHead[0] == FoodX && SnakeHead[1] == FoodY)
			{
				SnakeBody[SnakeLong - 1][0] = SnakeBody[SnakeLong - 2][0] - 1;
				SnakeBody[SnakeLong - 1][1] = SnakeBody[SnakeLong - 2][1];
				SnakeLong++;
				Food = 0;
				num++;
			}
		}
		if (SnakeBody[SnakeLong - 2][2] == 3)
		{
			if (SnakeHead[0] == FoodX && SnakeHead[1] == FoodY)
			{
				SnakeBody[SnakeLong - 1][0] = SnakeBody[SnakeLong - 2][0];
				SnakeBody[SnakeLong - 1][1] = SnakeBody[SnakeLong - 2][1] - 2;
				SnakeLong++;
				Food = 0;
				num++;
			}
		}
		if (SnakeBody[SnakeLong - 2][2] == 5)
		{
			if (SnakeHead[0] == FoodX && SnakeHead[1] == FoodY)
			{
				SnakeBody[SnakeLong - 1][0] = SnakeBody[SnakeLong - 2][0] + 1;
				SnakeBody[SnakeLong - 1][1] = SnakeBody[SnakeLong - 2][1];
				SnakeLong++;
				Food = 0;
				num++;
			}
		}
		//判断最高分数
		if (num > bestBuffer)
		{
			bestBuffer = num;
		}
		//打印游戏画面
		system("cls");
		for (i = 0; i < 20; i++)
		{
			printf("%s", SnakeBackground[i]);
		}
		printf("\n\t\t\t\t\t分数:%d", num);
		printf("\n\t\t\t\t\t最高分数:%d", bestBuffer);

		//清除残留
		strncpy(&SnakeBackground[SnakeHead[0]][SnakeHead[1]], "  ", 2);
		strncpy(&SnakeBackground[SnakeBody[0][0]][SnakeBody[0][1]], "  ", 2);
		strncpy(&SnakeBackground[SnakeBody[1][0]][SnakeBody[1][1]], "  ", 2);
		for (RealSnakeLong = 2; RealSnakeLong < SnakeLong - 1; RealSnakeLong++)
		{
					strncpy(&SnakeBackground[SnakeBody[RealSnakeLong][0]][SnakeBody[RealSnakeLong][1]], "  ", 2);
		}

		//蛇身跟着蛇头
		SnakeLieRecord[0] = SnakeBody[0][0];
		SnakeLieRecord[1] = SnakeBody[0][1];
		SnakeLieRecord[2] = SnakeBody[0][2];
		SnakeBody[0][0] = SnakeHead[0];
		SnakeBody[0][1] = SnakeHead[1];
		SnakeBody[0][2] = SnakeHead[2];
		for (j = 1; j < SnakeLong; j++)//蛇身跟着蛇身 j=1从第一节蛇身开始  SnakeLong是蛇最大的长度
		{								//记录最尾端方向以便于生成新的蛇身
			SnakeLieRecord[3] = SnakeBody[j][0];
			SnakeLieRecord[4] = SnakeBody[j][1];
			SnakeLieRecord[5] = SnakeBody[j][2];
			SnakeBody[j][0] = SnakeLieRecord[0];
			SnakeBody[j][1] = SnakeLieRecord[1];
			SnakeBody[j][2] = SnakeLieRecord[2];
			SnakeLieRecord[0] = SnakeLieRecord[3];
			SnakeLieRecord[1] = SnakeLieRecord[4];
			SnakeLieRecord[2] = SnakeLieRecord[5];
		}




		//蛇动起来  并判断蛇撞边界
		if (SnakeHead[2] == 1)
		{
			if (SnakeHead[1] == 2)
			{
				Die++;
			}
			else
			{
				Die = 0;
			}
			if (SnakeHead[1] != 2)
			{
				SnakeHead[1] = SnakeHead[1] - 2;
			}
		}
		if (SnakeHead[2] == 3)
		{
			if (SnakeHead[1] == 38)
			{
				Die++;
			}
			else
			{
				Die = 0;
			}
			if (SnakeHead[1] != 38)
			{
				SnakeHead[1] = SnakeHead[1] + 2;
			}
		}
		if (SnakeHead[2] == 5)
		{
			if (SnakeHead[0] == 1)
			{
				Die++;
			}
			else
			{
				Die = 0;
			}
			if (SnakeHead[0] != 1)
			{
				SnakeHead[0] = SnakeHead[0] - 1;
			}
		}
		if (SnakeHead[2] == 2)
		{
			if (SnakeHead[0] == 18)
			{
				Die++;
			}
			else
			{
				Die = 0;
			}
			if (SnakeHead[0] != 18)
			{
				SnakeHead[0] = SnakeHead[0] + 1;
			}
		}



		//判断死亡
		if (Die == 2)
		{
			goto over1;
		}

		Sleep(300);
	}
over1:
over:
	if (bestBuffer <= num)
	{
		best = fopen("best.bin", "w");
		fwrite(&num, 4, 1, best);
		fclose(best);
	}
	system("cls");
	printf("\n\n\n\t\t\t\t\n\n\t\t\t\t游戏结束!\n");






	system("pause");
	return 0;
}
