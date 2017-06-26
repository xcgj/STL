#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "InterFace.h"
#include "functions.h"

#pragma comment(lib,"./OpenWifi.lib")

int main(void) 
{
	//初始化函数指针结构体
	CHO stru;
	INIT_choice(&stru, choice1, choice2);

	//按用户输入调用函数
	printf("按数字完成相应设置：\n\n");
	printf("1：设置wifi名字和密码\n2：按默认设置启动wifi\n\n选择：");
	int choice = 0;
	scanf("%d", &choice);
	if (1 != choice && 2 != choice)
	{
		printf("\n选择错误，程序退出\n\n");
		goto End;
	}

	//启动
	stru.a[choice - 1]();

	//后续连接
	printf("系统wifi开启设置成功，如手机未检测到wifi，请输入数字：1\n");
	getchar();//吃回车

	char state;
	state = getchar();
	if ('1' == state)
	{
		system("ncpa.cpl");
		printf("\n请按以下方法继续设置：\n请右键连接的网络 -> 属性 -> 共享 -> 勾选全部，选择“本地连接 *x”\n\n");
	}

End:
	system("pause");

	return 0;
}