#pragma once

typedef int(*TELL)(char c);

//左括号
int IsLeftBracket(char c);

//右括号
int IsRightBracket(char c);

//四则运算
int IsPrio(char c);

//数字
int IsDigit(char c);