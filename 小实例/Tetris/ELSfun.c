#include"ELS.h"

char g_arrSet[18][10] = { 0 };
extern char g_arrChooseSquare[4][4] = { 0 };
extern int g_nline = 0;
extern int g_nlist = 0;
extern int g_squareID = -1;
int g_nScore = 0;
int g_MostScore = 0;
char g_arrScore[3][10];
SOCKET ServerSocket;
extern int ctrl;




void OnPaint(HDC hDc)
{
	HDC CompatibleDC = CreateCompatibleDC(hDc);//创建兼容DC
	HBITMAP CompatibleBitMap = CreateCompatibleBitmap(hDc, 500, 750);//创建位图  相当于创建一张纸

	//关联DC与位图
	SelectObject(CompatibleDC, CompatibleBitMap);

	paintsquare(CompatibleDC);//画方块
	ShowScore(CompatibleDC);//显示分数
	ShowMostScore(CompatibleDC);//显示最高分数
	ShowScoreLine(CompatibleDC);//显示全球排行榜
	ShowIdea(CompatibleDC);//显示操作提示

	//传递DC到屏幕
	BitBlt(hDc, 10, 10, 485, 720, CompatibleDC, 10, 10, SRCCOPY);


	//释放兼容DC
	DeleteObject(CompatibleBitMap);
	DeleteDC(CompatibleDC);
}


//显示操作提示
void ShowIdea(HDC CompatibleDC)
{
	//TODO
}


//第一次进入程序需要执行的放入此函数
void OnCreate()
{
	srand((unsigned int)time(NULL));
	ReadMostScore();
	ChooseSquare();
	InsertSquare();
}

//画方块
void paintsquare(HDC CompatibleDC)
{	//循环控制变量
	int i = 0,
		j = 0;

	Rectangle(CompatibleDC, 10, 10, 410, 730);  //x轴 = 400 10个40*40的方块填满X轴  y轴14个40*40方块

	for (i = 0; i < 18; i++)
	{
		for (j = 0; j < 10; j++)
		{
			if (1 == g_arrSet[i][j])
			{
				HBRUSH hPink = CreateSolidBrush(RGB(255, 176, 216));//创建颜色画刷
				HBRUSH OldBrush = SelectObject(CompatibleDC,hPink);//关联DC

				Rectangle(CompatibleDC, j * 40 + 10, i * 40 + 10, j * 40 + 40 + 10, i * 40 + 40 + 10);

				SelectObject(CompatibleDC, OldBrush);//还原基本画刷
				DeleteObject(hPink);//释放object
			}
			if (2 == g_arrSet[i][j])
			{
				HBRUSH hBlue = CreateSolidBrush(RGB(89, 89, 255));//创建颜色画刷
				HBRUSH OldBrush = SelectObject(CompatibleDC, hBlue);//关联DC

				Rectangle(CompatibleDC, j * 40 + 10, i * 40 + 10, j * 40 + 40 + 10, i * 40 + 40 + 10);

				SelectObject(CompatibleDC, OldBrush);
				DeleteObject(hBlue);
			}
		}
	}
}

//将随机方块放进主数组
void InsertSquare()
{
	int i = 0,
		j = 0;

	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (1 == g_arrChooseSquare[i][j])
			{
				g_arrSet[i][j + 3] = g_arrChooseSquare[i][j];
			}
		}
	}
}

//按回车开始游戏
int OnReturn(HWND hWnd)
{
	HDC hDc = GetDC(hWnd);//获取DC
	SetTimer(hWnd, TIMER1, 1000, NULL);

	SquareDown();//一按回车让他直接下落并直接打印一次方块  这样感觉起来更好
	OnPaint(hDc);//打印方块

	ReleaseDC(hWnd, hDc);//释放DC
	return 0;
}

//方块下落
void SquareDown()
{
	int i = 0,
		j = 0;

	for (i = 17; i > -1; i--)
	{
		for (j = 0; j < 10; j++)
		{
			if (g_arrSet[i][j] == 1)
			{
				g_arrSet[i + 1][j] = g_arrSet[i][j];
				g_arrSet[i][j] = 0;
			}
		}
	}
	g_nline++;
}

//收到WM_TIMER时调用
void OnTimer(HWND hWnd)
{
	HDC hDc = GetDC(hWnd);//获取DC

	//if CanSquareDown == 1  说明方块下落到了底部
	if (CanSquareDown() == 1)
	{
		SquareDown();//方块下落
	}
	else//产生新的方块
	{
		arrSet1To2();////把主数组里的1变成2  防止方块不下落
		BreakSquare();//满一行消除方块
		OnPaint(hDc);
		if (1 == GameOver(hWnd))
		{
			KillTimer(hWnd, TIMER1);
			sendScore();//发送分数给服务器
			SaveMostScore();//保存最高分到本地
			exit(0);
		}
		ChooseSquare();//随机选择方块
		InsertSquare();//随机方块放进主数组
	}

	OnPaint(hDc);//方块下落后  把方块画到程序上

	ReleaseDC(hWnd, hDc);//释放DC
}

//方块是否可以下落
int CanSquareDown()
{
	for (int i = 0; i < 10; i++)
	{
		if (g_arrSet[17][i] == 1)
		{
			return 0;
		}
	}
	for (int i = 17; i > -1; i--)
	{
		for (int j = 0; j < 10; j++)
		{
			if (g_arrSet[i][j] == 1)
			{
				if (g_arrSet[i + 1][j] == 2)
				{
					return 0;
				}
			}
		}
	}
	return 1;
}

//把主数组里的1变成2  防止方块不下落
void arrSet1To2()
{
	for (int i = 0; i < 18; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (g_arrSet[i][j] == 1)
			{
				g_arrSet[i][j] = 2;
			}
		}
	}
}

//方块左移算法
void MoveLeft()
{
	for (int i = 0; i < 18; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (1 == g_arrSet[i][j])
			{
				g_arrSet[i][j - 1] = 1;
				g_arrSet[i][j] = 0;
			}
		}
	}
	g_nlist--;
}

//判断是否可以左移
int CanMoveLeft()
{
	for (int i = 0; i < 18; i++)
	{
		if (1 == g_arrSet[i][0])
		{
			return 0;
		}
	}
	for (int i = 0; i < 18; i++)   //这里不能用if (2 == g_arrSet[i][j] && 1 == g_arrSet[i][j + 1])
	{							   //因为紧贴右边边框的方块==2时,j+1下标就会变成[?][10]
		for (int j = 0; j < 10; j++)//越界后[?][10]这个值有可能时1  最终符合if  导致不能左移
		{
			if (1 == g_arrSet[i][j] && 2 == g_arrSet[i][j - 1])
			{
				return 0;
			}		//if (1 == g_arrSet[i][j] && 2 == g_arrSet[i][j - 1])可以用
		}			//1是下落的方块  靠近最左侧边框  j-1越出边框  就算是2  符合if也没关系
	}				//因为下落的方块靠在最左侧边框  是不允许左移的  所以这个操作影响不大
	return 1;
}

//向左移动
void OnLeft(HWND hWnd)
{
	if (1 == CanMoveLeft())
	{
		HDC hDc = GetDC(hWnd);//获取DC
		MoveLeft();//向左移动
		OnPaint(hDc);//画图
		ReleaseDC(hWnd, hDc);//释放DC
	}
}

//方块右移
void OnRight(HWND hWnd)
{
	if (1 == CanMoveRight())
	{
		HDC hDc = GetDC(hWnd);
		MoveRight();
		OnPaint(hDc);
		ReleaseDC(hWnd, hDc);
	}

}
//方块右移算法
void MoveRight()
{
	for (int i = 17; i > -1; i--)
	{
		for (int j = 9; j > -1; j--)
		{
			if (1 == g_arrSet[i][j])
			{
				g_arrSet[i][j + 1] = 1;
				g_arrSet[i][j] = 0;
			}
		}
	}
	g_nlist++;
}
//判断是否可以右移
int CanMoveRight()
{
	for (int i = 0; i < 18; i++)
	{
		if (1 == g_arrSet[i][9])
		{
			return 0;
		}
	}
	for (int i = 0; i < 18; i++)			//这里与左移同理  只是反过来而已
	{
		for (int j = 0; j < 10; j++)
		{
			if (1 == g_arrSet[i][j] && 2 == g_arrSet[i][j + 1])
			{
				return 0;
			}
		}
	}
	return 1;
}


//方块按下键加速下落
void OnDown(HWND hWnd)
{
	OnTimer(hWnd);
}


//方块变形主函数
void ChangeSquare(HWND hWnd)
{
	HDC hDc = GetDC(hWnd);
	switch (g_squareID)
	{
	//3*3方块变形
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
	case 10:
	case 11:
	case 12:
	case 13:
	case 14:
	case 22:
	case 23:
	case 26:
	case 27:
		if (1 == CanSquareChange())
		{
			ChangeSimpleSquare();
		}
		break;
	//长条形变形
	case 0:
	case 16:
	case 17:
	case 18:
	case 24:
	case 25:
		if (1 == CanLongSquare())
		{
			ChangeLongSquare();
		}
		break;
	//正方形不用变形
	case 15:
	case 19:
	case 20:
	case 21:
		return;
	}
	OnPaint(hDc);
	ReleaseDC(hWnd, hDc);
}

//3*3方块变形
void ChangeSimpleSquare()
{
	char arrSimpleSquare[3][3] = { 0 };
	int n = 2;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			arrSimpleSquare[i][j] = g_arrSet[i + g_nline][j + g_nlist];
		}
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			g_arrSet[i + g_nline][j + g_nlist] = arrSimpleSquare[n--][i];
		}
		n = 2;
	}
}


//3*3方块是否可以变形
int CanSquareChange()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (2 == g_arrSet[i + g_nline][j + g_nlist])
			{
				return 0;
			}
		}
	}

	if (g_nlist < 0 || (g_nlist + 2) > 9)
	{
		return 0;
	}
	if (g_nline > 15)
	{
		return 0;
	}

	return 1;
}

//长条变形
void ChangeLongSquare()
{
	if (g_arrSet[g_nline][g_nlist - 1] == 1 && g_arrSet[g_nline][g_nlist + 1] == 1)
	{
		if (g_arrSet[g_nline][g_nlist + 2] == 1)
		{
			//清零
			g_arrSet[g_nline][g_nlist - 1] = 0;
			g_arrSet[g_nline][g_nlist + 1] = 0;
			g_arrSet[g_nline][g_nlist + 2] = 0;
			//赋值  变形
			g_arrSet[g_nline - 1][g_nlist] = 1;
			g_arrSet[g_nline + 1][g_nlist] = 1;
			g_arrSet[g_nline + 2][g_nlist] = 1;
		}
	}
	else if (g_arrSet[g_nline - 1][g_nlist] == 1 && g_arrSet[g_nline + 1][g_nlist] == 1)
	{
		if (g_arrSet[g_nline + 2][g_nlist] == 1)
		{
			g_arrSet[g_nline - 1][g_nlist] = 0;
			g_arrSet[g_nline + 1][g_nlist] = 0;
			g_arrSet[g_nline + 2][g_nlist] = 0;
			//赋值  变形
			g_arrSet[g_nline][g_nlist - 1] = 1;
			g_arrSet[g_nline][g_nlist + 1] = 1;
			g_arrSet[g_nline][g_nlist + 2] = 1;
		}
	}
}

//判断长条是否可以变形
int CanLongSquare()
{
	if (g_arrSet[g_nline - 1][g_nlist] == 2 || g_arrSet[g_nline + 1][g_nlist] == 2 || g_arrSet[g_nline + 2][g_nlist] == 2)
	{
			return 0;
	}
	if (g_arrSet[g_nline][g_nlist - 1] == 2 || g_arrSet[g_nline][g_nlist + 1] == 2 || g_arrSet[g_nline][g_nlist + 2] == 2)
	{
			return 0;
	}
	if (g_nlist < 1 || g_nlist > 7)
	{
		return 0;
	}
	if (g_nline > 15 || g_nline < 1)
	{
		return 0;
	}
	return 1;
}

//消除方块
void BreakSquare()
{
	int i = 0;
	int j = 0;
	int nSum = 0;

	for (i = 17; i > -1; i--)
	{
		for (j = 0; j < 10; j++)
		{
			nSum += g_arrSet[i][j];
		}

		if (20 == nSum)//满一行就消除
		{
			for (j = 0; j < 10; j++)
			{
				g_arrSet[i][j] = 0;
			}
			g_nScore++;

			for (i; i > -1; i--)//消除后让编号为2的方块下落一格
			{
				for (j = 0; j < 10; j++)
				{
					if (2 == g_arrSet[i][j])
					{
						g_arrSet[i + 1][j] = g_arrSet[i][j];
						g_arrSet[i][j] = 0;
					}
				}
			}
			i = 18;//一行以上  连在一起的需要消除   就需要把i重置到最底下  不然会消除不完
		}
		nSum = 0;//重置消除计数
	}
}


//显示分数
void ShowScore(HDC CompatibleDC)
{
	char arrScore[10] = { '\0' };

	_itoa(g_nScore, arrScore, 10);
	Rectangle(CompatibleDC, 410, 10, 495, 730);
	Rectangle(CompatibleDC, 413, 260, 492, 400);
	Rectangle(CompatibleDC, 415, 330, 490, 398);
	TextOut(CompatibleDC, 420, 340, "分数", (int)strlen("分数"));
	TextOut(CompatibleDC, 420, 370, arrScore, (int)strlen(arrScore));
}

//显示最高分
void ShowMostScore(HDC CompatibleDC)
{
	char arrMostScore[10] = { 0 };

	_itoa(g_MostScore, arrMostScore, 10);
	Rectangle(CompatibleDC, 415, 262, 490, 330);
	TextOut(CompatibleDC, 420, 270, "最高分数", (int)strlen("最高分数"));
	TextOut(CompatibleDC, 420, 300, arrMostScore, (int)strlen(arrMostScore));
}



//游戏结束
int GameOver(HWND hWnd)
{
	for (int i = 0; i < 10; i++)
	{
		if (2 == g_arrSet[0][i])
		{
			MessageBox(hWnd, "游戏结束", "提示", MB_OK);
			return 1;
		}
	}
	return 0;
}

//记录最高分
void SaveMostScore()
{
	if (g_nScore > g_MostScore)
	{
		char arrSaveMostScore[10] = { 0 };
		FILE* pFile = fopen("C:\\Program Files\\date.els", "w");

		g_nScore = ((((g_nScore * 10) - 413) * 3) + 413);

		_itoa(g_nScore, arrSaveMostScore, 10);

		fwrite(arrSaveMostScore, 1, 10, pFile);

		fclose(pFile);
	}
}

//读取最高分
void ReadMostScore()
{
	char arrMostScore[10] = { 0 };
	FILE* pFile = fopen("C:\\Program Files\\date.els", "r");

	if (NULL == pFile)
	{
		return;
	}

	fread(arrMostScore, 1, 10, pFile);
	g_MostScore = atoi(arrMostScore);

	g_MostScore = ((((g_MostScore - 413) / 3) + 413) / 10);

	fclose(pFile);
}


//连接服务器
void connectServer(HWND hWnd)
{
	WSADATA WSAdata;
	WSAStartup(MAKEWORD(2, 2), &WSAdata);

	if (2 != LOBYTE(WSAdata.wVersion) || 2 != HIBYTE(WSAdata.wVersion))
	{
		MessageBox(hWnd, "连接服务器失败,排行榜不可用", "错误", MB_OK);
	}

	ServerSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (ServerSocket == INVALID_SOCKET)
	{
		MessageBox(hWnd, "连接服务器失败,排行榜不可用", "错误", MB_OK);
	}

	SOCKADDR_IN sockaddr;
	sockaddr.sin_family = AF_INET;
	sockaddr.sin_port = htons(3658);
	sockaddr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
	if (SOCKET_ERROR == connect(ServerSocket, (SOCKADDR*)&sockaddr, sizeof(sockaddr)))
	{
		MessageBox(hWnd, "连接服务器失败,排行榜不可用", "错误", MB_OK);
	}

	GetScoreLine(ServerSocket);
}

//拿到排行榜
void GetScoreLine(SOCKET ServerSocket)
{
	char buf[30] = { '\0' };
	recv(ServerSocket, buf, 30, 0);
	int j = 0,
		n = 0;
	for (int i = 0; i < 30; i++)
	{
		if (buf[i] == '\0')
		{
			break;
		}
		if (buf[i] != '.')
		{
			g_arrScore[j][n++] = buf[i];
		}
		else
		{
			j++;
			n = 0;
			continue;
		}
	}
}

//显示排行榜
void ShowScoreLine(HDC CompatibleDC)
{
	//TextOut(CompatibleDC, 415, 20, "周排行前三", (int)strlen("周排行前三"));
	//Rectangle(CompatibleDC, 413, 38, 492, 202);
	//Rectangle(CompatibleDC, 415, 40, 490, 200);
	TextOut(CompatibleDC, 415, 50, "本周最高分", (int)strlen("本周最高分"));//429
	Rectangle(CompatibleDC, 420, 70, 485, 90);//第一名框
	//TextOut(CompatibleDC, 429, 100, "第二名", (int)strlen("第二名"));
	//Rectangle(CompatibleDC, 420, 120, 485, 140);//第二名框
	//TextOut(CompatibleDC, 429, 150, "第三名", (int)strlen("第三名"));
	//Rectangle(CompatibleDC, 420, 170, 485, 190);//第三名框

	////将分数放进框中
	TextOut(CompatibleDC, 436, 73, g_arrScore[0], (int)strlen(g_arrScore[0]));//第一名
	//TextOut(CompatibleDC, 436, 123, g_arrScore[1], (int)strlen(g_arrScore[1]));//第二名
	//TextOut(CompatibleDC, 436, 173, g_arrScore[2], (int)strlen(g_arrScore[2]));//第三名

}

//发送分数给服务器
void sendScore()
{
	char buf[30] = { '\0' };
	_itoa(g_nScore, buf, 10);
	send(ServerSocket, buf, sizeof(buf), 0);
}

//释放socket和关闭网络库
void freeNetwork()
{
	closesocket(ServerSocket);
	WSACleanup();
}
