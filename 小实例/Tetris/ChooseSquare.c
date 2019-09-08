#include"ELS.h"

extern char g_arrChooseSquare[4][4];
extern int g_nline;
extern int g_nlist;
extern int g_squareID;
//产生随机方块
void ChooseSquare()
{
	int i = rand()%29;
	g_squareID = i;//取得方块形状ID

	switch (i)
	{
	case 0://长条形
		g_arrChooseSquare[0][0] = 1, g_arrChooseSquare[0][1] = 1, g_arrChooseSquare[0][2] = 1, g_arrChooseSquare[0][3] = 1;
		g_arrChooseSquare[1][0] = 0, g_arrChooseSquare[1][1] = 0, g_arrChooseSquare[1][2] = 0, g_arrChooseSquare[1][3] = 0;
		g_arrChooseSquare[2][0] = 0, g_arrChooseSquare[2][1] = 0, g_arrChooseSquare[2][2] = 0, g_arrChooseSquare[2][3] = 0;
		g_arrChooseSquare[3][0] = 0, g_arrChooseSquare[3][1] = 0, g_arrChooseSquare[3][2] = 0, g_arrChooseSquare[3][3] = 0;
		g_nline = 0;
		g_nlist = 4;
		break;
	case 1://7形
		g_arrChooseSquare[0][0] = 1, g_arrChooseSquare[0][1] = 1, g_arrChooseSquare[0][2] = 1, g_arrChooseSquare[0][3] = 0;
		g_arrChooseSquare[1][0] = 0, g_arrChooseSquare[1][1] = 0, g_arrChooseSquare[1][2] = 1, g_arrChooseSquare[1][3] = 0;
		g_arrChooseSquare[2][0] = 0, g_arrChooseSquare[2][1] = 0, g_arrChooseSquare[2][2] = 0, g_arrChooseSquare[2][3] = 0;
		g_arrChooseSquare[3][0] = 0, g_arrChooseSquare[3][1] = 0, g_arrChooseSquare[3][2] = 0, g_arrChooseSquare[3][3] = 0;
		g_nline = 0;
		g_nlist = 3;
		break;
	case 2://7形
		g_arrChooseSquare[0][0] = 0, g_arrChooseSquare[0][1] = 1, g_arrChooseSquare[0][2] = 1, g_arrChooseSquare[0][3] = 1;
		g_arrChooseSquare[1][0] = 0, g_arrChooseSquare[1][1] = 1, g_arrChooseSquare[1][2] = 0, g_arrChooseSquare[1][3] = 0;
		g_arrChooseSquare[2][0] = 0, g_arrChooseSquare[2][1] = 0, g_arrChooseSquare[2][2] = 0, g_arrChooseSquare[2][3] = 0;
		g_arrChooseSquare[3][0] = 0, g_arrChooseSquare[3][1] = 0, g_arrChooseSquare[3][2] = 0, g_arrChooseSquare[3][3] = 0;
		g_nline = 0;
		g_nlist = 4;
		break;
	case 3://2形
		g_arrChooseSquare[0][0] = 0, g_arrChooseSquare[0][1] = 1, g_arrChooseSquare[0][2] = 1, g_arrChooseSquare[0][3] = 0;
		g_arrChooseSquare[1][0] = 0, g_arrChooseSquare[1][1] = 0, g_arrChooseSquare[1][2] = 1, g_arrChooseSquare[1][3] = 1;
		g_arrChooseSquare[2][0] = 0, g_arrChooseSquare[2][1] = 0, g_arrChooseSquare[2][2] = 0, g_arrChooseSquare[2][3] = 0;
		g_arrChooseSquare[3][0] = 0, g_arrChooseSquare[3][1] = 0, g_arrChooseSquare[3][2] = 0, g_arrChooseSquare[3][3] = 0;
		g_nline = 0;
		g_nlist = 4;
		break;
	case 4://2形
		g_arrChooseSquare[0][0] = 0, g_arrChooseSquare[0][1] = 1, g_arrChooseSquare[0][2] = 1, g_arrChooseSquare[0][3] = 0;
		g_arrChooseSquare[1][0] = 1, g_arrChooseSquare[1][1] = 1, g_arrChooseSquare[1][2] = 0, g_arrChooseSquare[1][3] = 0;
		g_arrChooseSquare[2][0] = 0, g_arrChooseSquare[2][1] = 0, g_arrChooseSquare[2][2] = 0, g_arrChooseSquare[2][3] = 0;
		g_arrChooseSquare[3][0] = 0, g_arrChooseSquare[3][1] = 0, g_arrChooseSquare[3][2] = 0, g_arrChooseSquare[3][3] = 0;
		g_nline = 0;
		g_nlist = 3;
		break;
	case 5://2形
		g_arrChooseSquare[0][0] = 0, g_arrChooseSquare[0][1] = 1, g_arrChooseSquare[0][2] = 0, g_arrChooseSquare[0][3] = 0;
		g_arrChooseSquare[1][0] = 0, g_arrChooseSquare[1][1] = 1, g_arrChooseSquare[1][2] = 1, g_arrChooseSquare[1][3] = 0;
		g_arrChooseSquare[2][0] = 0, g_arrChooseSquare[2][1] = 0, g_arrChooseSquare[2][2] = 1, g_arrChooseSquare[2][3] = 0;
		g_arrChooseSquare[3][0] = 0, g_arrChooseSquare[3][1] = 0, g_arrChooseSquare[3][2] = 0, g_arrChooseSquare[3][3] = 0;
		g_nline = 0;
		g_nlist = 4;
		break;
	case 6://2形
		g_arrChooseSquare[0][0] = 0, g_arrChooseSquare[0][1] = 0, g_arrChooseSquare[0][2] = 1, g_arrChooseSquare[0][3] = 0;
		g_arrChooseSquare[1][0] = 0, g_arrChooseSquare[1][1] = 1, g_arrChooseSquare[1][2] = 1, g_arrChooseSquare[1][3] = 0;
		g_arrChooseSquare[2][0] = 0, g_arrChooseSquare[2][1] = 1, g_arrChooseSquare[2][2] = 0, g_arrChooseSquare[2][3] = 0;
		g_arrChooseSquare[3][0] = 0, g_arrChooseSquare[3][1] = 0, g_arrChooseSquare[3][2] = 0, g_arrChooseSquare[3][3] = 0;
		g_nline = 0;
		g_nlist = 4;
		break;
	case 7://7形
		g_arrChooseSquare[0][0] = 0, g_arrChooseSquare[0][1] = 1, g_arrChooseSquare[0][2] = 1, g_arrChooseSquare[0][3] = 0;
		g_arrChooseSquare[1][0] = 0, g_arrChooseSquare[1][1] = 0, g_arrChooseSquare[1][2] = 1, g_arrChooseSquare[1][3] = 0;
		g_arrChooseSquare[2][0] = 0, g_arrChooseSquare[2][1] = 0, g_arrChooseSquare[2][2] = 1, g_arrChooseSquare[2][3] = 0;
		g_arrChooseSquare[3][0] = 0, g_arrChooseSquare[3][1] = 0, g_arrChooseSquare[3][2] = 0, g_arrChooseSquare[3][3] = 0;
		g_nline = 0;
		g_nlist = 4;
		break;
	case 8://7形
		g_arrChooseSquare[0][0] = 0, g_arrChooseSquare[0][1] = 1, g_arrChooseSquare[0][2] = 1, g_arrChooseSquare[0][3] = 0;
		g_arrChooseSquare[1][0] = 0, g_arrChooseSquare[1][1] = 1, g_arrChooseSquare[1][2] = 0, g_arrChooseSquare[1][3] = 0;
		g_arrChooseSquare[2][0] = 0, g_arrChooseSquare[2][1] = 1, g_arrChooseSquare[2][2] = 0, g_arrChooseSquare[2][3] = 0;
		g_arrChooseSquare[3][0] = 0, g_arrChooseSquare[3][1] = 0, g_arrChooseSquare[3][2] = 0, g_arrChooseSquare[3][3] = 0;
		g_nline = 0;
		g_nlist = 4;
		break;
	case 9://7形
		g_arrChooseSquare[0][0] = 0, g_arrChooseSquare[0][1] = 1, g_arrChooseSquare[0][2] = 0, g_arrChooseSquare[0][3] = 0;
		g_arrChooseSquare[1][0] = 0, g_arrChooseSquare[1][1] = 1, g_arrChooseSquare[1][2] = 1, g_arrChooseSquare[1][3] = 1;
		g_arrChooseSquare[2][0] = 0, g_arrChooseSquare[2][1] = 0, g_arrChooseSquare[2][2] = 0, g_arrChooseSquare[2][3] = 0;
		g_arrChooseSquare[3][0] = 0, g_arrChooseSquare[3][1] = 0, g_arrChooseSquare[3][2] = 0, g_arrChooseSquare[3][3] = 0;
		g_nline = 0;
		g_nlist = 4;
		break;
	case 10://7形
		g_arrChooseSquare[0][0] = 0, g_arrChooseSquare[0][1] = 0, g_arrChooseSquare[0][2] = 1, g_arrChooseSquare[0][3] = 0;
		g_arrChooseSquare[1][0] = 1, g_arrChooseSquare[1][1] = 1, g_arrChooseSquare[1][2] = 1, g_arrChooseSquare[1][3] = 0;
		g_arrChooseSquare[2][0] = 0, g_arrChooseSquare[2][1] = 0, g_arrChooseSquare[2][2] = 0, g_arrChooseSquare[2][3] = 0;
		g_arrChooseSquare[3][0] = 0, g_arrChooseSquare[3][1] = 0, g_arrChooseSquare[3][2] = 0, g_arrChooseSquare[3][3] = 0;
		g_nline = 0;
		g_nlist = 3;
		break;
	case 11://土形
		g_arrChooseSquare[0][0] = 0, g_arrChooseSquare[0][1] = 1, g_arrChooseSquare[0][2] = 0, g_arrChooseSquare[0][3] = 0;
		g_arrChooseSquare[1][0] = 1, g_arrChooseSquare[1][1] = 1, g_arrChooseSquare[1][2] = 1, g_arrChooseSquare[1][3] = 0;
		g_arrChooseSquare[2][0] = 0, g_arrChooseSquare[2][1] = 0, g_arrChooseSquare[2][2] = 0, g_arrChooseSquare[2][3] = 0;
		g_arrChooseSquare[3][0] = 0, g_arrChooseSquare[3][1] = 0, g_arrChooseSquare[3][2] = 0, g_arrChooseSquare[3][3] = 0;
		g_nline = 0;
		g_nlist = 3;
		break;
	case 12://土形
		g_arrChooseSquare[0][0] = 0, g_arrChooseSquare[0][1] = 1, g_arrChooseSquare[0][2] = 1, g_arrChooseSquare[0][3] = 1;
		g_arrChooseSquare[1][0] = 0, g_arrChooseSquare[1][1] = 0, g_arrChooseSquare[1][2] = 1, g_arrChooseSquare[1][3] = 0;
		g_arrChooseSquare[2][0] = 0, g_arrChooseSquare[2][1] = 0, g_arrChooseSquare[2][2] = 0, g_arrChooseSquare[2][3] = 0;
		g_arrChooseSquare[3][0] = 0, g_arrChooseSquare[3][1] = 0, g_arrChooseSquare[3][2] = 0, g_arrChooseSquare[3][3] = 0;
		g_nline = 0;
		g_nlist = 4;
		break;
	case 13://土形
		g_arrChooseSquare[0][0] = 0, g_arrChooseSquare[0][1] = 0, g_arrChooseSquare[0][2] = 1, g_arrChooseSquare[0][3] = 0;
		g_arrChooseSquare[1][0] = 0, g_arrChooseSquare[1][1] = 1, g_arrChooseSquare[1][2] = 1, g_arrChooseSquare[1][3] = 0;
		g_arrChooseSquare[2][0] = 0, g_arrChooseSquare[2][1] = 0, g_arrChooseSquare[2][2] = 1, g_arrChooseSquare[2][3] = 0;
		g_arrChooseSquare[3][0] = 0, g_arrChooseSquare[3][1] = 0, g_arrChooseSquare[3][2] = 0, g_arrChooseSquare[3][3] = 0;
		g_nline = 0;
		g_nlist = 4;
		break;
	case 14://土形
		g_arrChooseSquare[0][0] = 0, g_arrChooseSquare[0][1] = 1, g_arrChooseSquare[0][2] = 0, g_arrChooseSquare[0][3] = 0;
		g_arrChooseSquare[1][0] = 0, g_arrChooseSquare[1][1] = 1, g_arrChooseSquare[1][2] = 1, g_arrChooseSquare[1][3] = 0;
		g_arrChooseSquare[2][0] = 0, g_arrChooseSquare[2][1] = 1, g_arrChooseSquare[2][2] = 0, g_arrChooseSquare[2][3] = 0;
		g_arrChooseSquare[3][0] = 0, g_arrChooseSquare[3][1] = 0, g_arrChooseSquare[3][2] = 0, g_arrChooseSquare[3][3] = 0;
		g_nline = 0;
		g_nlist = 4;
		break;
	case 15://正方形
		g_arrChooseSquare[0][0] = 0, g_arrChooseSquare[0][1] = 1, g_arrChooseSquare[0][2] = 1, g_arrChooseSquare[0][3] = 0;
		g_arrChooseSquare[1][0] = 0, g_arrChooseSquare[1][1] = 1, g_arrChooseSquare[1][2] = 1, g_arrChooseSquare[1][3] = 0;
		g_arrChooseSquare[2][0] = 0, g_arrChooseSquare[2][1] = 0, g_arrChooseSquare[2][2] = 0, g_arrChooseSquare[2][3] = 0;
		g_arrChooseSquare[3][0] = 0, g_arrChooseSquare[3][1] = 0, g_arrChooseSquare[3][2] = 0, g_arrChooseSquare[3][3] = 0;
		g_nline = 0;
		g_nlist = 4;
		break;
	case 16://长条形
		g_arrChooseSquare[0][0] = 0, g_arrChooseSquare[0][1] = 1, g_arrChooseSquare[0][2] = 0, g_arrChooseSquare[0][3] = 0;
		g_arrChooseSquare[1][0] = 0, g_arrChooseSquare[1][1] = 1, g_arrChooseSquare[1][2] = 0, g_arrChooseSquare[1][3] = 0;
		g_arrChooseSquare[2][0] = 0, g_arrChooseSquare[2][1] = 1, g_arrChooseSquare[2][2] = 0, g_arrChooseSquare[2][3] = 0;
		g_arrChooseSquare[3][0] = 0, g_arrChooseSquare[3][1] = 1, g_arrChooseSquare[3][2] = 0, g_arrChooseSquare[3][3] = 0;
		g_nline = 1;
		g_nlist = 4;
		break;
	case 17://长条形
		g_arrChooseSquare[0][0] = 1, g_arrChooseSquare[0][1] = 1, g_arrChooseSquare[0][2] = 1, g_arrChooseSquare[0][3] = 1;
		g_arrChooseSquare[1][0] = 0, g_arrChooseSquare[1][1] = 0, g_arrChooseSquare[1][2] = 0, g_arrChooseSquare[1][3] = 0;
		g_arrChooseSquare[2][0] = 0, g_arrChooseSquare[2][1] = 0, g_arrChooseSquare[2][2] = 0, g_arrChooseSquare[2][3] = 0;
		g_arrChooseSquare[3][0] = 0, g_arrChooseSquare[3][1] = 0, g_arrChooseSquare[3][2] = 0, g_arrChooseSquare[3][3] = 0;
		g_nline = 0;
		g_nlist = 4;
		break;
	case 18://长条形
		g_arrChooseSquare[0][0] = 0, g_arrChooseSquare[0][1] = 1, g_arrChooseSquare[0][2] = 0, g_arrChooseSquare[0][3] = 0;
		g_arrChooseSquare[1][0] = 0, g_arrChooseSquare[1][1] = 1, g_arrChooseSquare[1][2] = 0, g_arrChooseSquare[1][3] = 0;
		g_arrChooseSquare[2][0] = 0, g_arrChooseSquare[2][1] = 1, g_arrChooseSquare[2][2] = 0, g_arrChooseSquare[2][3] = 0;
		g_arrChooseSquare[3][0] = 0, g_arrChooseSquare[3][1] = 1, g_arrChooseSquare[3][2] = 0, g_arrChooseSquare[3][3] = 0;
		g_nline = 1;
		g_nlist = 4;
		break;
	case 19://正方形
		g_arrChooseSquare[0][0] = 0, g_arrChooseSquare[0][1] = 1, g_arrChooseSquare[0][2] = 1, g_arrChooseSquare[0][3] = 0;
		g_arrChooseSquare[1][0] = 0, g_arrChooseSquare[1][1] = 1, g_arrChooseSquare[1][2] = 1, g_arrChooseSquare[1][3] = 0;
		g_arrChooseSquare[2][0] = 0, g_arrChooseSquare[2][1] = 0, g_arrChooseSquare[2][2] = 0, g_arrChooseSquare[2][3] = 0;
		g_arrChooseSquare[3][0] = 0, g_arrChooseSquare[3][1] = 0, g_arrChooseSquare[3][2] = 0, g_arrChooseSquare[3][3] = 0;
		g_nline = 0;
		g_nlist = 4;
		break;
	case 20://正方形
		g_arrChooseSquare[0][0] = 0, g_arrChooseSquare[0][1] = 1, g_arrChooseSquare[0][2] = 1, g_arrChooseSquare[0][3] = 0;
		g_arrChooseSquare[1][0] = 0, g_arrChooseSquare[1][1] = 1, g_arrChooseSquare[1][2] = 1, g_arrChooseSquare[1][3] = 0;
		g_arrChooseSquare[2][0] = 0, g_arrChooseSquare[2][1] = 0, g_arrChooseSquare[2][2] = 0, g_arrChooseSquare[2][3] = 0;
		g_arrChooseSquare[3][0] = 0, g_arrChooseSquare[3][1] = 0, g_arrChooseSquare[3][2] = 0, g_arrChooseSquare[3][3] = 0;
		g_nline = 0;
		g_nlist = 4;
		break;
	case 21://正方形
		g_arrChooseSquare[0][0] = 0, g_arrChooseSquare[0][1] = 1, g_arrChooseSquare[0][2] = 1, g_arrChooseSquare[0][3] = 0;
		g_arrChooseSquare[1][0] = 0, g_arrChooseSquare[1][1] = 1, g_arrChooseSquare[1][2] = 1, g_arrChooseSquare[1][3] = 0;
		g_arrChooseSquare[2][0] = 0, g_arrChooseSquare[2][1] = 0, g_arrChooseSquare[2][2] = 0, g_arrChooseSquare[2][3] = 0;
		g_arrChooseSquare[3][0] = 0, g_arrChooseSquare[3][1] = 0, g_arrChooseSquare[3][2] = 0, g_arrChooseSquare[3][3] = 0;
		g_nline = 0;
		g_nlist = 4;
		break;
	case 22://7形
		g_arrChooseSquare[0][0] = 0, g_arrChooseSquare[0][1] = 0, g_arrChooseSquare[0][2] = 1, g_arrChooseSquare[0][3] = 0;
		g_arrChooseSquare[1][0] = 0, g_arrChooseSquare[1][1] = 0, g_arrChooseSquare[1][2] = 1, g_arrChooseSquare[1][3] = 0;
		g_arrChooseSquare[2][0] = 0, g_arrChooseSquare[2][1] = 1, g_arrChooseSquare[2][2] = 1, g_arrChooseSquare[2][3] = 0;
		g_arrChooseSquare[3][0] = 0, g_arrChooseSquare[3][1] = 0, g_arrChooseSquare[3][2] = 0, g_arrChooseSquare[3][3] = 0;
		g_nline = 0;
		g_nlist = 4;
		break;
	case 23://7形
		g_arrChooseSquare[0][0] = 0, g_arrChooseSquare[0][1] = 1, g_arrChooseSquare[0][2] = 0, g_arrChooseSquare[0][3] = 0;
		g_arrChooseSquare[1][0] = 0, g_arrChooseSquare[1][1] = 1, g_arrChooseSquare[1][2] = 0, g_arrChooseSquare[1][3] = 0;
		g_arrChooseSquare[2][0] = 0, g_arrChooseSquare[2][1] = 1, g_arrChooseSquare[2][2] = 1, g_arrChooseSquare[2][3] = 0;
		g_arrChooseSquare[3][0] = 0, g_arrChooseSquare[3][1] = 0, g_arrChooseSquare[3][2] = 0, g_arrChooseSquare[3][3] = 0;
		g_nline = 0;
		g_nlist = 4;
		break;
	case 24://长条形
		g_arrChooseSquare[0][0] = 1, g_arrChooseSquare[0][1] = 1, g_arrChooseSquare[0][2] = 1, g_arrChooseSquare[0][3] = 1;
		g_arrChooseSquare[1][0] = 0, g_arrChooseSquare[1][1] = 0, g_arrChooseSquare[1][2] = 0, g_arrChooseSquare[1][3] = 0;
		g_arrChooseSquare[2][0] = 0, g_arrChooseSquare[2][1] = 0, g_arrChooseSquare[2][2] = 0, g_arrChooseSquare[2][3] = 0;
		g_arrChooseSquare[3][0] = 0, g_arrChooseSquare[3][1] = 0, g_arrChooseSquare[3][2] = 0, g_arrChooseSquare[3][3] = 0;
		g_nline = 0;
		g_nlist = 4;
		break;
	case 25://长条形
		g_arrChooseSquare[0][0] = 0, g_arrChooseSquare[0][1] = 1, g_arrChooseSquare[0][2] = 0, g_arrChooseSquare[0][3] = 0;
		g_arrChooseSquare[1][0] = 0, g_arrChooseSquare[1][1] = 1, g_arrChooseSquare[1][2] = 0, g_arrChooseSquare[1][3] = 0;
		g_arrChooseSquare[2][0] = 0, g_arrChooseSquare[2][1] = 1, g_arrChooseSquare[2][2] = 0, g_arrChooseSquare[2][3] = 0;
		g_arrChooseSquare[3][0] = 0, g_arrChooseSquare[3][1] = 1, g_arrChooseSquare[3][2] = 0, g_arrChooseSquare[3][3] = 0;
		g_nline = 1;
		g_nlist = 4;
		break;
	case 26://2形
		g_arrChooseSquare[0][0] = 0, g_arrChooseSquare[0][1] = 1, g_arrChooseSquare[0][2] = 1, g_arrChooseSquare[0][3] = 0;
		g_arrChooseSquare[1][0] = 1, g_arrChooseSquare[1][1] = 1, g_arrChooseSquare[1][2] = 0, g_arrChooseSquare[1][3] = 0;
		g_arrChooseSquare[2][0] = 0, g_arrChooseSquare[2][1] = 0, g_arrChooseSquare[2][2] = 0, g_arrChooseSquare[2][3] = 0;
		g_arrChooseSquare[3][0] = 0, g_arrChooseSquare[3][1] = 0, g_arrChooseSquare[3][2] = 0, g_arrChooseSquare[3][3] = 0;
		g_nline = 0;
		g_nlist = 3;
		break;
	case 27://2形
		g_arrChooseSquare[0][0] = 0, g_arrChooseSquare[0][1] = 1, g_arrChooseSquare[0][2] = 1, g_arrChooseSquare[0][3] = 0;
		g_arrChooseSquare[1][0] = 0, g_arrChooseSquare[1][1] = 0, g_arrChooseSquare[1][2] = 1, g_arrChooseSquare[1][3] = 1;
		g_arrChooseSquare[2][0] = 0, g_arrChooseSquare[2][1] = 0, g_arrChooseSquare[2][2] = 0, g_arrChooseSquare[2][3] = 0;
		g_arrChooseSquare[3][0] = 0, g_arrChooseSquare[3][1] = 0, g_arrChooseSquare[3][2] = 0, g_arrChooseSquare[3][3] = 0;
		g_nline = 0;
		g_nlist = 4;
		break;
	case 28://长条
		g_arrChooseSquare[0][0] = 0, g_arrChooseSquare[0][1] = 1, g_arrChooseSquare[0][2] = 0, g_arrChooseSquare[0][3] = 0;
		g_arrChooseSquare[1][0] = 0, g_arrChooseSquare[1][1] = 1, g_arrChooseSquare[1][2] = 0, g_arrChooseSquare[1][3] = 0;
		g_arrChooseSquare[2][0] = 0, g_arrChooseSquare[2][1] = 1, g_arrChooseSquare[2][2] = 0, g_arrChooseSquare[2][3] = 0;
		g_arrChooseSquare[3][0] = 0, g_arrChooseSquare[3][1] = 1, g_arrChooseSquare[3][2] = 0, g_arrChooseSquare[3][3] = 0;
		g_nline = 1;
		g_nlist = 4;
		break;
	}
}

//长条6
//7形8  左右方向各一半
//2形6  左右方向各一半
//土形4
//正方形6
