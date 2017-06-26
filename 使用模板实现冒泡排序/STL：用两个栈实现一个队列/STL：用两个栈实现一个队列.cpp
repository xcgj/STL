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
	//���
	void Push(const int& val)
	{
		//���s1
		while (s1.size())
		{
			s1.pop();
		}

		//�Ƚ�s2����s1
		while (s2.size())
		{
			s1.push(s2.top());
			s2.pop();
		}

		//s1 push
		s1.push(val);

		//s2�Ѿ�Ϊ�գ�s1����s2
		while (s1.size())
		{
			s2.push(s1.top());
			s1.pop();
		}
	}

	//����
	void Pop()
	{
		s2.pop();
	}

	//���ض���Ԫ��
	int& Front()
	{
		return s2.top();
	}

	//���ض�βԪ��
	int& Back()
	{
		//���s1
		while (s1.size())
		{
			s1.pop();
		}

		//s2����s1
		while (s2.size())
		{
			s1.push(s2.top());
			s2.pop();
		}

		//��β
		int a = s1.top();

		//s2����s1
		while (s1.size())
		{
			s2.push(s1.top());
			s1.pop();
		}

		return a;
	}
	//�ж϶����Ƿ�Ϊ��
	bool Empty()
	{
		return s2.empty();
	}
	//���ض��д�С
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

