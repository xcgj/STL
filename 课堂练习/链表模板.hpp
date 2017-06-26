#pragma once

#include <iostream>
#include <string>
using namespace std;

//==============用户数据类型==============//
template <typename I, typename S>
class DATA
{
private:
	I age;
	S name;
public:
	DATA(){}

	DATA(I a, S n)
	{
		age = a;
		name = n;
	}

	I GetAge()
	{
		return age;
	}

	S GetName()
	{
		return name;
	}
};

//==============函数对象==============//
template <typename I, typename S>
class PRINT
{
public:
	void operator()(DATA<I, S> * data)
	{
		cout << "名字：" << data->GetName() << "，年龄：" << data->GetAge() << endl;
	}
};

template <typename I, typename S>
class COMPARE
{
public:
	int operator()(DATA<I, S> * data1, DATA<I, S> * data2)
	{
		return data1->GetAge() > data2->GetAge() ? 1 : 0 ;
	}
};

//==============定义节点==============//

template<typename T>
class LinkNode
{
public:
	T * data;
	LinkNode * next;
};

//==============定义表属性==============//

template<typename T, typename I, typename S>
class List
{
public:

//==============初始化==============//
	List()
	{
		size = 0;
		head.next = NULL;
	}
//==============插入==============//
	void Insert(T * data, int pos)
	{
		//判断位置合法
		if (pos < 0 || pos > size)
		{
			pos = size;
		}
		
		//新建节点
		LinkNode<T> * tmp = new LinkNode<T>;
		tmp->data = data;
		tmp->next = NULL;

		//查找插入位置
		LinkNode<T> * pCur = &head;//头节点
		for (int i = 0; i < pos; i++)
		{
			pCur = pCur->next;
		}
		tmp->next = pCur->next;
		pCur->next = tmp;

		size++;
	}

//==============删除==============//
	void Delpos(int pos)
	{
		//判断空链
		//if (0 == size){return;}

		//判断位置合法
		if (pos < 0 || pos >= size)
		{
			return;
		}

		//查找位置
		LinkNode<T> * pCur = &head;//头节点
//要求pCur所指向的位置是待删除节点的前一个位置，这样直接next保存并越过待删除节点
		for (int i = 0; i < pos; i++)
		{
			pCur = pCur->next;
		}

		//删除元素
		LinkNode<T> * tmp = pCur->next;
		pCur->next = tmp->next;
		delete tmp;
		tmp = NULL;

		size--;
	}

//==============遍历==============//
	//需要用户传入回调函数/仿函数/函数对象进行对对象的打印操作
	template <typename CALLBACK>
	void Ergodic(CALLBACK pri)
	{
		//cout << typeid(pri).name() << endl;
		LinkNode<T> * pCur = &head;
		for (int i = 0; i < size; i++)
		{
			pCur = pCur->next;
			pri(pCur->data);
		}
	}

//==============插入排序==============//
	template <typename CALLBACK>
	void Sort(CALLBACK com)
	{
		LinkNode<T> * pCur = &head;//首节点
		LinkNode<T> * tmp = NULL;
		LinkNode<T> * p = NULL;

		if (NULL == pCur->next)//头节点，此判断为循环的初始化准备
		{
			return;
		}
		for (pCur = pCur->next; pCur->next != NULL;)
		{
			if (com(pCur->next->data, pCur->data))//降序
			{
				tmp = pCur->next;
				
				p = &head;
				for (; (p->next != pCur) && com(p->next->data, tmp->data); p = p->next)
				{
					//退出时，指针指向的位置是在待插入节点的前一个节点位置
				}

				//处理旧节点
				pCur->next = tmp->next;
				//连接新节点
				tmp->next = p->next;
				p->next = tmp;				
			}
			else
			{
				pCur = pCur->next;
			}
		}
	}

//==============逆置==============//
	void Reverse()
	{
		if (size <= 1)
		{
			return;
		}

		LinkNode<T> * pPre = head.next;//首
		LinkNode<T> * pCur = pPre->next;//2
		LinkNode<T> * pNex = NULL;

		while (NULL != pCur)
		{
			pNex = pCur->next;
			pCur->next = pPre;
			pPre = pCur;
			pCur = pNex;
		}

		pCur = head.next;//首
		head.next = pPre;//改首

		pCur->next = NULL;//改尾
	}

//==============清除==============//
	~List()
	{
		LinkNode<T> * pCur = head.next;
		LinkNode<T> * tmp = NULL;
		while (NULL != pCur)
		{
			tmp = pCur;
			pCur = pCur->next;
			delete tmp;
		}
		size = 0;
	}

protected:
private:
	int size;
	LinkNode<T> head;
};