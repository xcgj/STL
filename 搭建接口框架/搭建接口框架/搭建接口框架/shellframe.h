#pragma once

#include "CommunicationInterface.h"


//建立框架初始化句柄，并发送、接收数据
int frame(SERE * set, char * inf_sent, int sent_len, char * inf_rece, int * rece_len);