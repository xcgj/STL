#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#include <vector>
#include <iterator>

using namespace std;

//==============动物抽象==============//

class ANIMAL
{
public:
	//纯虚函数
	virtual void yell() = 0;
	//虚析构函数
	virtual ~ANIMAL() {}
};

//==============动物具体类==============//

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

//==============动物园类==============//

#if 0
//容器实现
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
	//初始化
	zoo()
	{
		size = 0;
		for (int i = 0; i < 10; i++)
		{
			ani[i] = NULL;
		}
	}

	//加成员
	void push(ANIMAL * an)
	{
		if (10 == size)
		{
			return;
		}
		ani[size++] = an;
	}

	//遍历成员
	void ergodic()
	{
		for (int i = 0; i < size; i++)
		{
			ani[i]->yell();
		}
	}

	//删除成员
	void del()
	{
		delete(ani[size - 1]);
		ani[size - 1] = NULL;
		size--;
	}

	//清空
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
