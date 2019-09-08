#ifndef ELS
#define ELS

#define _CRT_SECURE_NO_WARNINGS
#include<Windows.h>
#include<time.h>
#include<stdio.h>
#include"resource.h"
#define TIMER1 1
#pragma comment(lib, "ws2_32.lib")



//第一次进入程序需要执行的放入此函数
void OnCreate();

//主画图函数
void OnPaint(HDC hDc);

//画方块
void paintsquare(HDC CompatibleDC);

//选择随机方块
void ChooseSquare();

//将随机方块放进主数组
void InsertSquare();

//按回车开始游戏
int OnReturn(HWND hWnd);

//方块下落
void SquareDown();

//收到WM_TIMER时调用
void OnTimer(HWND hWnd);

//方块是否可以下落
int CanSquareDown();

//把主数组里的1变成2  防止方块不下落
void arrSet1To2();


//方块左移算法
void MoveLeft();
//判断是否可以右移
int CanMoveLeft();
//方块向左移动
void OnLeft(HWND hWnd);


//方块右移
void OnRight(HWND hWnd);
//方块右移算法
void MoveRight();
//判断是否可以右移
int CanMoveRight();


//方块按下键加速下落
void OnDown(HWND hWnd);


//方块变形主函数
void ChangeSquare(HWND hWnd);
//3*3方块变形
void ChangeSimpleSquare();
//3*3方块是否可以变形
int CanSquareChange();
//长条变形
void ChangeLongSquare();
//判断长条是否可以变形
int CanLongSquare();


//消除方块
void BreakSquare();

//显示分数
void ShowScore(HDC CompatibleDC);

//游戏结束
int GameOver(HWND hWnd);

//记录最高分
void SaveMostScore();
//读取最高分
void ReadMostScore();
//显示最高分
void ShowMostScore(HDC CompatibleDC);

//显示操作提示
void ShowIdea(HDC CompatibleDC);


//连接服务器
void connectServer(HWND hWnd);
//拿到排行榜
void GetScoreLine(SOCKET ServerSocket);
//显示排行榜
void ShowScoreLine(HDC CompatibleDC);
//发送分数给服务器
void sendScore();
//释放socket和关闭网络库
void freeNetwork();

#endif // !1
