#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

int EXIT = 1;//退出控制变量
typedef struct STU
{
	char arrStuNum[20];
	char arrStuName[20];
	int iStuScore;
	struct STU* pNext;
}STUNODE;

STUNODE* g_pHead = NULL;
STUNODE* g_pEnd = NULL;

int g_restoreMSGNum = 0;
STUNODE* restoreMSG[100];


//添加学生信息
void addStuMSG(char arrStuNum[20], char arrStuName[20], int iStuScore);

//从链表头部添加学生信息节点
void addStuMSGHead(char arrStuNum[20], char arrStuName[20], int iStuScore);

//在指定学号后面插入学生信息
void addStuMSGtoAnywhere(char searchMSG[20], char arrStuNum[20], char arrStuName[20], int iStuScore);

//打印查看学生信息
void showStuMSG();

//打印指令表
void showOrder();

//清空链表
void freeMSG();

//按学号/姓名查找学生信息
void searchStuMSG(char searchMSG[20]);

//用学号查找指定学生信息节点
STUNODE* searchStuMSGbyNum(char searchMSG[20]);

//修改指定学生的信息
void fixStuMSG(STUNODE* pTarget, char arrStuNum[20], char arrStuName[20], int iStuScore);

//以学号的方式删除指定学生信息节点
void deleteStuMSG(STUNODE* pTarget);

//将学生信息写入文件
void saveStuMSGtoFile();

//读取文件学生信息
void readStuMSG();

//备份学生信息
void backupStuMSG();

//恢复删除的学生信息
void restoreStuMSG();


int main(void)
{
	int iOrder = -1;
	char arrStuNum[20] = { '\0' };
	char arrStuName[20] = { '\0' };
	int iStuScore = 0;
	char searchMSG[20] = { '\0' };

	readStuMSG();//读入文件学生数据

	while (EXIT)
	{
		showOrder();
		printf("请输入指令:_\b");
		scanf("%d", &iOrder);

		switch (iOrder)
		{
		case 1:
			printf("请输入学生学号:");
			scanf("%s", arrStuNum);
			printf("请输入学生姓名:");
			scanf("%s", arrStuName);
			printf("请输入学生分数:__\b\b");
			scanf("%d", &iStuScore);
			//添加学生信息
			addStuMSG(arrStuNum, arrStuName, iStuScore);
			system("CLS");
			break;

		case 2:
			printf("请输入学生学号:");
			scanf("%s", arrStuNum);
			printf("请输入学生姓名:");
			scanf("%s", arrStuName);
			printf("请输入学生分数:__\b\b");
			scanf("%d", &iStuScore);
			//头添加学生信息
			addStuMSGHead(arrStuNum, arrStuName, iStuScore);
			system("CLS");
			break;

		case 3:
			printf("请输入要查找的学生的\"学号/姓名\"");
			scanf("%s", searchMSG);
			searchStuMSG(searchMSG);
			break;

		case 4:
			printf("请输入要插入的位置:");
			scanf("%s", searchMSG);
			printf("请输入插入学生学号:");
			scanf("%s", arrStuNum);
			printf("请输入学生姓名:");
			scanf("%s", arrStuName);
			printf("请输入学生成绩:");
			scanf("%d", &iStuScore);
			addStuMSGtoAnywhere(searchMSG, arrStuNum, arrStuName, iStuScore);
				break;

		case 5:
			printf("请输入要修改的学生信息的学号:");
			scanf("%s", searchMSG);
			printf("请输入修改后的学号:");
			scanf("%s", arrStuNum);
			printf("请输入修改后的姓名:");
			scanf("%s", arrStuName);
			printf("请输入修改后的成绩:");
			scanf("%d", &iStuScore);
			fixStuMSG(searchStuMSGbyNum(searchMSG), arrStuNum, arrStuName, iStuScore);
			break;

		case 6:
			saveStuMSGtoFile();
			break;

		case 7:
			printf("请输入需要删除的学生学号:");
			scanf("%s", searchMSG);
			deleteStuMSG(searchStuMSGbyNum(searchMSG));
			break;

		case 8:
			restoreStuMSG();
			break;

		case 9:
			system("CLS");
			printf("学生信息:\n");
			//打印学生信息
			printf("--------------------------------------------------\n");
			showStuMSG();
			printf("--------------------------------------------------\n按任意键返回主菜单");
			if (_getch())
			{
				system("CLS");
				break;
			}
		case 0://退出系统
			if (EXIT == 1)
			{
				EXIT = 0;
			}
			if (EXIT == -1)
			{
				printf("学生信息还未保存，如不保存请输入0，如需返回请输入1返回\n\n\t\t\t\t\t\t");
				scanf("%d", &EXIT);
				system("CLS");
			}
			break;

		default:
			system("CLS");
			printf("\n\n\n\n\n\n\n\n指令有误，请按任意键返回主菜单");
			_getch();
			system("CLS");
		}
	}

	freeMSG();
	return 0;
}


//打印指令表
void showOrder()
{
	printf("********************学生管理系统********************\n");
	printf("*******************本系统操作指令*******************\n");
	printf("***           ①、增加一个学生信息(尾添加)       ***\n");
	printf("***           ②、增加一个学生信息(头添加)       ***\n");
	printf("***           ③、查找指定学生的信息(姓名/学号)  ***\n");
	printf("***           ④、在指定学号后面插入学生信息     ***\n");
	printf("***           ⑤、修改指定学生的信息             ***\n");
	printf("***           ⑥、保存学生的信息到文件中         ***\n");
	printf("***           ⑦、删除指定学生的信息             ***\n");
	printf("***           ⑧、恢复删除的学生的信息           ***\n");
	printf("***           ⑨、显示所有学生的信息             ***\n");
	printf("***           〇、退出系统                       ***\n");
}

//添加学生信息
void addStuMSG(char arrStuNum[20], char arrStuName[20], int iStuScore)
{
	if (NULL == arrStuNum || NULL == arrStuName || iStuScore < 0)
	{
		printf("输入错误，按任意键返回主菜单");
		_getch();
		return;
	}
	STUNODE* pTemp = malloc(sizeof(STUNODE));
	strcpy(pTemp->arrStuNum, arrStuNum);
	strcpy(pTemp->arrStuName, arrStuName);
	pTemp->iStuScore = iStuScore;
	pTemp->pNext = NULL;

	if (NULL == g_pHead)
	{
		g_pHead = pTemp;
		g_pEnd = pTemp;
	}
	else
	{
		g_pEnd->pNext = pTemp;
		g_pEnd = pTemp;
	}
	EXIT = -1;
}

//从链表头部添加学生信息节点
void addStuMSGHead(char arrStuNum[20], char arrStuName[20], int iStuScore)
{
	if (NULL == arrStuNum || NULL == arrStuName || iStuScore < 0)
	{
		printf("输入错误，按任意键返回主菜单");
		_getch();
		return;
	}
	STUNODE* pTemp = malloc(sizeof(STUNODE));
	strcpy(pTemp->arrStuNum, arrStuNum);
	strcpy(pTemp->arrStuName, arrStuName);
	pTemp->iStuScore = iStuScore;
	pTemp->pNext = g_pHead;
	g_pHead = pTemp;

	if (NULL == g_pEnd)
	{
		g_pEnd = g_pHead;
	}
	EXIT = -1;
}

//打印查看学生信息
void showStuMSG()
{
	STUNODE* pTemp;
	pTemp = g_pHead;
	while (pTemp)
	{
		printf("学号：%s    姓名：%s    成绩：%d\n", pTemp->arrStuNum, pTemp->arrStuName, pTemp->iStuScore);
		pTemp = pTemp->pNext;
	}
}

//清空链表
void freeMSG()
{
	STUNODE* pTemp = NULL;
	while (g_pHead)
	{
		pTemp = g_pHead;
		g_pHead = g_pHead->pNext;
		free(pTemp);
	}
}

//按学号/姓名查找学生信息
void searchStuMSG(char searchMSG[20])
{
	STUNODE* pTemp = malloc(sizeof(STUNODE));
	pTemp = g_pHead;
	while (pTemp)
	{
		if (!strcmp(pTemp->arrStuNum, searchMSG) || !strcmp(pTemp->arrStuName, searchMSG))
		{
			system("CLS");
			printf("\n\n\n\n\n\n\n-----------------------------------\n");
			printf("学号：%s    姓名：%s    成绩：%d\n", pTemp->arrStuNum, pTemp->arrStuName, pTemp->iStuScore);
			printf("-----------------------------------\n找到此学生信息,请按任意键返回主菜单");
			_getch();
			system("CLS");
			return;
		}
		pTemp = pTemp->pNext;
	}
	system("CLS");
	printf("\n\n\n\n\n\n\n[没有找到此学生信息]\n");
	printf("请按任意键返回主菜单");
	_getch();
	system("CLS");
}

//在指定学号后面插入学生信息
void addStuMSGtoAnywhere(char searchMSG[20], char arrStuNum[20], char arrStuName[20], int iStuScore)
{
	STUNODE* pTarget = g_pHead;

	while (pTarget)
	{
		if (!strcmp(pTarget->arrStuNum, searchMSG))
		{
			STUNODE* pTemp = malloc(sizeof(STUNODE));
			strcpy(pTemp->arrStuNum, arrStuNum);
			strcpy(pTemp->arrStuName, arrStuName);
			pTemp->iStuScore = iStuScore;
			pTemp->pNext = pTarget->pNext;
			pTarget->pNext = pTemp;
			system("CLS");
			printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t[插入成功,请按任意键返回主菜单]");
			_getch();
			system("CLS");
			return;
		}
		pTarget = pTarget->pNext;
	}
	system("CLS");
	printf("\n\n\n\n\n\n\n\n[插入位置出错,请按任意键返回主菜单]");
	_getch();
	system("CLS");
	EXIT = -1;
}

//用学号查找指定学生信息节点
STUNODE* searchStuMSGbyNum(char searchMSG[20])
{
	STUNODE* pTarget = g_pHead;

	while (pTarget)
	{
		if (!strcmp(pTarget->arrStuNum, searchMSG))
		{
			return pTarget;
		}
		pTarget = pTarget->pNext;
	}
	return NULL;
}

//修改指定学生的信息
void fixStuMSG(STUNODE* pTarget, char arrStuNum[20], char arrStuName[20], int iStuScore)
{
	if (pTarget == NULL)
	{
		system("CLS");
		printf("\n\n\n\n\n\n\n\n\n【没有找到此学号，无法修改，按任意键返回主菜单】");
		_getch();
		system("CLS");
		return;
	}
	else
	{
		strcpy(pTarget->arrStuNum, arrStuNum);
		strcpy(pTarget->arrStuName, arrStuName);
		pTarget->iStuScore = iStuScore;
		system("CLS");
		printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\t【修改成功，请按任意键返回主菜单】");
		_getch();
		system("CLS");
	}
	EXIT = -1;
}

//以学号的方式删除指定学生信息节点
void deleteStuMSG(STUNODE* pTarget)
{
	if (pTarget == NULL)
	{
		system("CLS");
		printf("\n\n\n\n\n\n\n\n\n\t\t\t\t【没有与学号对应的学生，请按任意键返回主菜单】");
		_getch();
		system("CLS");
		return;
	}
	//只有一个节点
	if (g_pHead == g_pEnd)
	{
		g_restoreMSGNum++;
		backupStuMSG();
		free(g_pHead);
		g_pHead = NULL;
		g_pEnd = NULL;
		system("CLS");
		printf("\n\n\n\n\n\n\n\n\t\t\t\t已删除指定学号学生信息，按任意键返回主菜单");
		_getch();
		system("CLS");
		EXIT = -1;
		return;
	}
	//有两个节点
	if (g_pHead->pNext == g_pEnd)
	{
		if (g_pHead == pTarget)//删除头
		{
			g_restoreMSGNum++;
			backupStuMSG();
			free(g_pHead);
			g_pHead = g_pEnd;
			system("CLS");
			printf("\n\n\n\n\n\n\n\n\t\t\t\t已删除指定学号学生信息，按任意键返回主菜单");
			_getch();
			system("CLS");
			EXIT = -1;
			return;
		}
		if (g_pEnd == pTarget)//删除尾
		{
			g_restoreMSGNum++;
			backupStuMSG();
			free(g_pEnd);
			g_pEnd = g_pHead;
			g_pHead->pNext = NULL;
			system("CLS");
			printf("\n\n\n\n\n\n\n\n\t\t\t\t已删除指定学号学生信息，按任意键返回主菜单");
			_getch();
			system("CLS");
			EXIT = -1;
			return;
		}
	}
	//有多个节点时
	STUNODE* pTemp = g_pHead;
	//当学生学号是头节点时
	if (g_pHead == pTarget)
	{
		g_restoreMSGNum++;
		backupStuMSG();
		g_pHead = g_pHead->pNext;
		free(pTarget);
		system("CLS");
		printf("\n\n\n\n\n\n\n\n\t\t\t\t已删除指定学号学生信息，按任意键返回主菜单");
		_getch();
		system("CLS");
		EXIT = -1;
		return;
	}
	while (pTemp)//学生学号不是头节点时
	{
		if (pTemp->pNext == pTarget)
		{
			g_restoreMSGNum++;
			backupStuMSG();
			pTemp->pNext = pTemp->pNext->pNext;
			free(pTarget);
			g_pEnd = pTemp;
			system("CLS");
			printf("\n\n\n\n\n\n\n\n\t\t\t\t已删除指定学号学生信息，按任意键返回主菜单");
			_getch();
			system("CLS");
			EXIT = -1;
			return;
		}
		pTemp = pTemp->pNext;
	}
}

//将学生信息写入文件
void saveStuMSGtoFile()
{
	if (g_pHead == NULL)//检查当前程序是否有学生信息
	{
		printf("【当前程序没有学生信息，无法写入，请按任意键继续】");
		_getch();
		system("CLS");
		return;
	}

	STUNODE* pTemp = g_pHead;
	FILE* pFile;
	char strBuf[30] = { '\0' };


	pFile = fopen("MSG.dat", "w");
	while (pTemp)
	{

		//写入学号
		strcpy(strBuf, pTemp->arrStuNum);
		fwrite(strBuf, 1, strlen(strBuf), pFile);
		fwrite(".", 1, strlen("."), pFile);
		//写入姓名
		strcpy(strBuf, pTemp->arrStuName);
		fwrite(strBuf, 1, strlen(strBuf), pFile);
		fwrite(".", 1, strlen("."), pFile);
		//写入成绩
		_itoa(pTemp->iStuScore, strBuf, 10);
		fwrite(strBuf, 1, strlen(strBuf), pFile);
		fwrite("\n", 1, strlen("\n"), pFile);

		pTemp = pTemp->pNext;//指向下一个学生节点
	}
	fclose(pFile);
	printf("保存成功，请按任意键继续");
	_getch();
	system("CLS");
	EXIT = 1;
}

//读取文件学生信息
void readStuMSG()
{
	FILE* pFile = fopen("MSG.dat", "r");
	if (pFile == NULL)//第一次运行没有MSG.dat  直接跳过
	{
		return;
	}
	char memory[5] = { '\0' };//信息单个读取暂存空间
	char MSG[40] = { '\0' };  //文件每行数据暂存空间
	char arrStuNum[20] = { '\0' };//学生学号信息储存空间
	char arrStuName[20] = { '\0' };//学生姓名信息储存空间
	char arrStuScore[10] = { '\0' };//学生成绩信息储存空间
	int iStuScore = 0;//学生成绩字符串转换为整型储存空间
	while (!feof(pFile))
	{
		int j = 0, i = 0;
		memory[0] = '\0';
		for (int i = 0; i < 40; i++)//读取完一行后  清空数组
		{
			MSG[i] = '\0';
		}
		for (int i = 0; memory[0] != '\n'; i++)//将学生数据读入MSG
		{
			fread(memory, 1, 1, pFile);
			strcat(MSG, memory);
			if (memory[0] == '\0')//整个文件读取完  跳出函数
			{
				return;
			}
		}
		for (i = 0; MSG[i] != '.'; i++)//写入学生学号
		{
			arrStuNum[i] = MSG[i];
		}
		for (i = i + 1; MSG[i] != '.'; i++)//写入学生姓名
		{
			arrStuName[j++] = MSG[i];
		}
		j = 0;
		for (i = i + 1; MSG[i] != '\n'; i++)//写入学生成绩
		{
			arrStuScore[j++] = MSG[i];
		}
		iStuScore = atoi(arrStuScore);//转换成绩数据类型
		addStuMSG(arrStuNum, arrStuName, iStuScore);//创建学生信息链表
	}
}

//备份学生信息
void backupStuMSG()
{
	STUNODE* pTemp = g_pHead;
	STUNODE* backupTemp = malloc(sizeof(STUNODE));
	STUNODE* backup = malloc(sizeof(STUNODE));
	int i = 0;
	while (pTemp)
	{
			if (i == 0)
			{
				restoreMSG[g_restoreMSGNum - 1] = backup;
				i = 1;
				strcpy(backup->arrStuNum, pTemp->arrStuNum);
				strcpy(backup->arrStuName, pTemp->arrStuName);
				backup->iStuScore = pTemp->iStuScore;
				pTemp = pTemp->pNext;//避免重复读入相同信息
			}
			if (i == 1)
			{
				backupTemp = malloc(sizeof(STUNODE));
				backup->pNext = backupTemp;

				strcpy(backupTemp->arrStuNum, pTemp->arrStuNum);
				strcpy(backupTemp->arrStuName, pTemp->arrStuName);
				backupTemp->iStuScore = pTemp->iStuScore;

				backup = backupTemp;
			}

			pTemp = pTemp->pNext;
	}
	backupTemp->pNext = NULL;

}

//恢复删除的学生信息
void restoreStuMSG()
{
	int i = 0;
	int iOrder = -1;
	STUNODE* pTemp = malloc(sizeof(STUNODE));
	if (restoreMSG[0] == NULL)
	{
		printf("当前还没有删除的学生信息,请按任意键继续");
		_getch();
		system("CLS");
		return;
	}
	for (i = 0; restoreMSG[i] != NULL; i++)
	{
		printf("%d\n", i + 1);
	}
	printf("请问需要恢复哪一张学生信息表:");
	scanf("%d", &iOrder);

	//strcpy(pTemp->arrStuNum, restoreMSG[iOrder - 1]->arrStuNum);
	//strcpy(pTemp->arrStuName, restoreMSG[iOrder - 1]->arrStuName);
	//pTemp->iStuScore = restoreMSG[iOrder - 1]->iStuScore;
	//pTemp->pNext = restoreMSG[iOrder - 1]->pNext;


	while (1)
	{
		pTemp = restoreMSG[iOrder - 1];
		setbuf(stdin, NULL);
		system("CLS");
		printf("\t此表学生信息如下:\n");
		printf("--------------------------------------------------\n");
		while (pTemp)
		{
			printf("学号：%s    姓名：%s    成绩：%d\n", pTemp->arrStuNum, pTemp->arrStuName, pTemp->iStuScore);
			pTemp = pTemp->pNext;

		}
		printf("--------------------------------------------------\n");
		printf("是否恢复此表？此操作不可逆！\n");
		printf("\t\tY or N\n\t\t");
		char c;
		scanf("%c", &c);
		if (c == 'Y' || c == 'y')
		{
			g_pHead = restoreMSG[iOrder - 1];
			pTemp = g_pHead;
			while (pTemp)
			{
				if (pTemp->pNext == NULL)
				{
					g_pEnd = pTemp;
				}
				pTemp = pTemp->pNext;
			}
			system("CLS");
			printf("\n\n\n\n\n\n\n\n\t\t\t\t\t[恢复成功！请按任意键返回主菜单]");
			_getch();
			system("CLS");
			return;
		}
		else if (c == 'N' || c == 'n')
		{
			system("CLS");
			printf("\n\n\n\n\n\n\n\n\t\t\t\t\t[已取消，按任意键返回主菜单]");
			_getch();
			system("CLS");
			return;
		}
		else
		{
			printf("\n\n\n\n\n\n\n\n\t\t\t\t\t[输入有误，请按任意键后重新输入]");
			_getch();
		}
	}

}
