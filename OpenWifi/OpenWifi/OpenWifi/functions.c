#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//1���޸�wifi���ֺ�����\n2����ǰ����������wifi\n3���鿴wifi���ֺ�����\n
//ѡ��1
void choice1(void)
{
	char ssid[100] = { 0 };
	char key[100] = { 0 };
	char netssid[1024] = "netsh wlan set hostednetwork ssid=";
	char netkey[1024] = "netsh wlan set hostednetwork key=";
Err1:
	printf("������wifi����(��Ҫ�пո�)��\n");
	scanf("%s", ssid);
	printf("������wifi����(��Ҫ�пո�)��\n");
	scanf("%s", key);
	if (NULL == ssid || NULL == key)
	{
		printf("����������������룺\n");
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

//ѡ��2
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