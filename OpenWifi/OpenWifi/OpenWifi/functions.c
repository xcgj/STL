#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//1：修改wifi名字和密码\n2：按前次设置启动wifi\n3：查看wifi名字和密码\n
//选项1
void choice1(void)
{
	char ssid[100] = { 0 };
	char key[100] = { 0 };
	char netssid[1024] = "netsh wlan set hostednetwork ssid=";
	char netkey[1024] = "netsh wlan set hostednetwork key=";
Err1:
	printf("请输入wifi名字(不要有空格)：\n");
	scanf("%s", ssid);
	printf("请输入wifi密码(不要有空格)：\n");
	scanf("%s", key);
	if (NULL == ssid || NULL == key)
	{
		printf("输入错误，请重新输入：\n");
		goto Err1;
	}

	printf("\n************************************\n\n");

	strcat(netssid, ssid);
	strcat(netkey, key);

	system("netsh wlan set hostednetwork mode=allow");
	system(netssid);
	system(netkey);
	system("netsh wlan start hostednetwork");

	printf("************************************\n");
	printf("* ssid:\t%s\n* key:\t%s\n", ssid, key);
	printf("************************************\n\n");
}

//选项2
void choice2(void)
{
	printf("\n************************************\n\n");

	system("netsh wlan set hostednetwork mode=allow");
	system("netsh wlan set hostednetwork ssid=xcgj");
	system("netsh wlan set hostednetwork key=xcgjxcgj");
	system("netsh wlan start hostednetwork");

	printf("************************************\n");
	printf("* ssid:\txcgj\n* key:\txcgjxcgj\n");
	printf("************************************\n\n");
}