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
	FILE *best = NULL;//��߷����ļ�ָ��
	int bestBuffer = 0;
	if ((best = fopen("best.bin", "r")) == NULL)//����ļ�Ϊ��  �����ļ���д����߷���0
	{
		best = fopen("best.bin", "a");
		fwrite(&bestBuffer, 4, 1, best);
		fclose(best);
	}
	else//����ļ���Ϊ��  ��ȡ��߷���д����߷��������ڴ�  ����߷�����ʾ����
	{
		//best = fopen("best.bin", "a");
		fread(&bestBuffer, 4, 1, best);
		fclose(best);
	}


	int Die = 0, die = 0;
	int num = 0;//����
	int SnakeHead[3] = { 10,30,1 };//��ͷ����
	int SnakeBody[100][3] = { {10,32,1},{10,34,1} };//��ʼ����������
	int SnakeLong = 3;
	int RealSnakeLong = 2;
	int SnakeLieRecord[6] = { 0 };
	int Food = 0;//ʳ�����
	int FoodX, FoodY;
	int i, j;//ѭ�����Ʊ���
    char SnakeBackground[20][44] = { "������������������������������������������\n",
									 "��                                      ��\n",
									 "��                                      ��\n",
									 "��                                      ��\n",
									 "��                                      ��\n",
									 "��                                      ��\n",
									 "��                                      ��\n",
									 "��                                      ��\n",
									 "��                                      ��\n",
									 "��                                      ��\n",
									 "��                                      ��\n",
									 "��                                      ��\n",
									 "��                                      ��\n",
									 "��                                      ��\n",
									 "��                                      ��\n",
									 "��                                      ��\n",
									 "��                                      ��\n",
									 "��                                      ��\n",
									 "��                                      ��\n",
									 "������������������������������������������", };

	//��һ����
	printf("\n\n\t\t\t\t    ��̰���ߡ�");
	printf("\n\n\t\t\t\t����������ʼ��Ϸ");
	_getch();
	while (1)
	{

		//���̿����ߵķ���
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

		//����ʳ��(����)
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
					strncpy(&SnakeBackground[FoodX][FoodY], "��", 2);
					Food = 1;
					break;
				}
				else
				{
					continue;
				}
			}
			else
			{		//��ֹʳ�ﱻ�߸��Ǻ����ʧ  ������ʧ�����´�ӡ
				strncpy(&SnakeBackground[FoodX][FoodY], "��", 2);
				break;
			}
		}

		//���������
		strncpy(&SnakeBackground[SnakeHead[0]][SnakeHead[1]], "��", 2);
		strncpy(&SnakeBackground[SnakeBody[0][0]][SnakeBody[0][1]], "��", 2);
		strncpy(&SnakeBackground[SnakeBody[1][0]][SnakeBody[1][1]], "��", 2);
		//��������������
		for (RealSnakeLong = 2; RealSnakeLong < SnakeLong - 1; RealSnakeLong++)
		{
			strncpy(&SnakeBackground[SnakeBody[RealSnakeLong][0]][SnakeBody[RealSnakeLong][1]], "��", 2);
		}

		//�ж���ײ����
		for (j = 3; j < SnakeLong; j++)
		{
			if (SnakeHead[0] == SnakeBody[j][0] && SnakeHead[1] == SnakeBody[j][1])
			{
				goto over;
			}
		}

		//��ʳ���߱䳤
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
		//�ж���߷���
		if (num > bestBuffer)
		{
			bestBuffer = num;
		}
		//��ӡ��Ϸ����
		system("cls");
		for (i = 0; i < 20; i++)
		{
			printf("%s", SnakeBackground[i]);
		}
		printf("\n\t\t\t\t\t����:%d", num);
		printf("\n\t\t\t\t\t��߷���:%d", bestBuffer);

		//�������
		strncpy(&SnakeBackground[SnakeHead[0]][SnakeHead[1]], "  ", 2);
		strncpy(&SnakeBackground[SnakeBody[0][0]][SnakeBody[0][1]], "  ", 2);
		strncpy(&SnakeBackground[SnakeBody[1][0]][SnakeBody[1][1]], "  ", 2);
		for (RealSnakeLong = 2; RealSnakeLong < SnakeLong - 1; RealSnakeLong++)
		{
					strncpy(&SnakeBackground[SnakeBody[RealSnakeLong][0]][SnakeBody[RealSnakeLong][1]], "  ", 2);
		}

		//���������ͷ
		SnakeLieRecord[0] = SnakeBody[0][0];
		SnakeLieRecord[1] = SnakeBody[0][1];
		SnakeLieRecord[2] = SnakeBody[0][2];
		SnakeBody[0][0] = SnakeHead[0];
		SnakeBody[0][1] = SnakeHead[1];
		SnakeBody[0][2] = SnakeHead[2];
		for (j = 1; j < SnakeLong; j++)//����������� j=1�ӵ�һ������ʼ  SnakeLong�������ĳ���
		{								//��¼��β�˷����Ա��������µ�����
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




		//�߶�����  ���ж���ײ�߽�
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



		//�ж�����
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
	printf("\n\n\n\t\t\t\t\n\n\t\t\t\t��Ϸ����!\n");






	system("pause");
	return 0;
}
