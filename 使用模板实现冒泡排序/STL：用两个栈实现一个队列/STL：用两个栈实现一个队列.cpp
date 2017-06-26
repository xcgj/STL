#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
using namespace std;

class Queue
{
private:
	stack<int> s1;
	stack<int> s2;
public:
	//入队
	void Push(const int& val)
	{
		//清空s1
		while (s1.size())
		{
			s1.pop();
		}

		//先将s2倒入s1
		while (s2.size())
		{
			s1.push(s2.top());
			s2.pop();
		}

		//s1 push
		s1.push(val);

		//s2已经为空，s1倒入s2
		while (s1.size())
		{
			s2.push(s1.top());
			s1.pop();
		}
	}

	//出队
	void Pop()
	{
		s2.pop();
	}

	//返回队首元素
	int& Front()
	{
		return s2.top();
	}

	//返回队尾元素
	int& Back()
	{
		//清空s1
		while (s1.size())
		{
			s1.pop();
		}

		//s2倒入s1
		while (s2.size())
		{
			s1.push(s2.top());
			s2.pop();
		}

		//队尾
		int a = s1.top();

		//s2倒入s1
		while (s1.size())
		{
			s2.push(s1.top());
			s1.pop();
		}

		return a;
	}
	//判断队列是否为空
	bool Empty()
	{
		return s2.empty();
	}
	//返回队列大小
	int Size()
	{
		return s2.size();
	}
};

void test()
{
	Queue q;
	q.Push(1);
	q.Push(2);
	q.Push(3);

	cout << q.Front() << endl;
	cout << q.Back() << endl;
	cout << q.Size() << endl;

	q.Pop();
	q.Pop();
	q.Pop();

	cout << q.Empty() << endl;
}

int main(void)
{
	test();

	cout << "Compelete" << endl;
	return 0;
}

