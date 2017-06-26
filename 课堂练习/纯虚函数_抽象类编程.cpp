#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#include <vector>
#include <iterator>

using namespace std;

//==============�������==============//

class ANIMAL
{
public:
	//���麯��
	virtual void yell() = 0;
	//����������
	virtual ~ANIMAL() {}
};

//==============���������==============//

class cat : public ANIMAL
{
public:
	void yell()
	{
		cout << "cat" << endl;
	}
};

class bird : public ANIMAL
{
public:
	void yell()
	{
		cout << "bird" << endl;
	}
};

class hourse : public ANIMAL
{
public:
	void yell()
	{
		cout << "hourse" << endl;
	}
};

//==============����԰��==============//

#if 0
//����ʵ��
class zoo
{
public:
	void show()
	{
		for (vector<ANIMAL>::iterator it; it != v.end(); it++)
		{
			it->yell();
		}
	}

	void push(ANIMAL * anim)
	{
		v.push_back(anim);
	}
private:
	vector<ANIMAL> v;
};
#endif

class zoo
{
public:
	//��ʼ��
	zoo()
	{
		size = 0;
		for (int i = 0; i < 10; i++)
		{
			ani[i] = NULL;
		}
	}

	//�ӳ�Ա
	void push(ANIMAL * an)
	{
		if (10 == size)
		{
			return;
		}
		ani[size++] = an;
	}

	//������Ա
	void ergodic()
	{
		for (int i = 0; i < size; i++)
		{
			ani[i]->yell();
		}
	}

	//ɾ����Ա
	void del()
	{
		delete(ani[size - 1]);
		ani[size - 1] = NULL;
		size--;
	}

	//���
	~zoo()
	{
		for (int i = 0; i < size; i++)
		{
			if (NULL != ani[i])
			{
				delete(ani[i]);
				ani[i] = NULL;
			}
		}
		size = 0;
	}
private:
	ANIMAL * ani[10];
	int size;;
};

int main(void)
{
	zoo * z = new zoo;

	z->push(new cat);
	z->push(new bird);
	z->push(new cat);
	z->push(new hourse);
	z->push(new bird);

	z->del();

	z->ergodic();

	delete z;
	z = NULL;

	cout << "Compelete" << endl;
	return 0;
}
