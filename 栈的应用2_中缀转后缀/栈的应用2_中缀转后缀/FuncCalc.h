#pragma once

typedef int(*TELL)(char c);

//������
int IsLeftBracket(char c);

//������
int IsRightBracket(char c);

//��������
int IsPrio(char c);

//����
int IsDigit(char c);