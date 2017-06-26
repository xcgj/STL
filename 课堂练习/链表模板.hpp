#pragma once

#include <iostream>
#include <string>
using namespace std;

//==============�û���������==============//
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

//==============��������==============//
template <typename I, typename S>
class PRINT
{
public:
	void operator()(DATA<I, S> * data)
	{
		cout << "���֣�" << data->GetName() << "�����䣺" << data->GetAge() << endl;
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

//==============����ڵ�==============//

template<typename T>
class LinkNode
{
public:
	T * data;
	LinkNode * next;
};

//==============���������==============//

template<typename T, typename I, typename S>
class List
{
public:

//==============��ʼ��==============//
	List()
	{
		size = 0;
		head.next = NULL;
	}
//==============����==============//
	void Insert(T * data, int pos)
	{
		//�ж�λ�úϷ�
		if (pos < 0 || pos > size)
		{
			pos = size;
		}
		
		//�½��ڵ�
		LinkNode<T> * tmp = new LinkNode<T>;
		tmp->data = data;
		tmp->next = NULL;

		//���Ҳ���λ��
		LinkNode<T> * pCur = &head;//ͷ�ڵ�
		for (int i = 0; i < pos; i++)
		{
			pCur = pCur->next;
		}
		tmp->next = pCur->next;
		pCur->next = tmp;

		size++;
	}

//==============ɾ��==============//
	void Delpos(int pos)
	{
		//�жϿ���
		//if (0 == size){return;}

		//�ж�λ�úϷ�
		if (pos < 0 || pos >= size)
		{
			return;
		}

		//����λ��
		LinkNode<T> * pCur = &head;//ͷ�ڵ�
//Ҫ��pCur��ָ���λ���Ǵ�ɾ���ڵ��ǰһ��λ�ã�����ֱ��next���沢Խ����ɾ���ڵ�
		for (int i = 0; i < pos; i++)
		{
			pCur = pCur->next;
		}

		//ɾ��Ԫ��
		LinkNode<T> * tmp = pCur->next;
		pCur->next = tmp->next;
		delete tmp;
		tmp = NULL;

		size--;
	}

//==============����==============//
	//��Ҫ�û�����ص�����/�º���/����������жԶ���Ĵ�ӡ����
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

//==============��������==============//
	template <typename CALLBACK>
	void Sort(CALLBACK com)
	{
		LinkNode<T> * pCur = &head;//�׽ڵ�
		LinkNode<T> * tmp = NULL;
		LinkNode<T> * p = NULL;

		if (NULL == pCur->next)//ͷ�ڵ㣬���ж�Ϊѭ���ĳ�ʼ��׼��
		{
			return;
		}
		for (pCur = pCur->next; pCur->next != NULL;)
		{
			if (com(pCur->next->data, pCur->data))//����
			{
				tmp = pCur->next;
				
				p = &head;
				for (; (p->next != pCur) && com(p->next->data, tmp->data); p = p->next)
				{
					//�˳�ʱ��ָ��ָ���λ�����ڴ�����ڵ��ǰһ���ڵ�λ��
				}

				//����ɽڵ�
				pCur->next = tmp->next;
				//�����½ڵ�
				tmp->next = p->next;
				p->next = tmp;				
			}
			else
			{
				pCur = pCur->next;
			}
		}
	}

//==============����==============//
	void Reverse()
	{
		if (size <= 1)
		{
			return;
		}

		LinkNode<T> * pPre = head.next;//��
		LinkNode<T> * pCur = pPre->next;//2
		LinkNode<T> * pNex = NULL;

		while (NULL != pCur)
		{
			pNex = pCur->next;
			pCur->next = pPre;
			pPre = pCur;
			pCur = pNex;
		}

		pCur = head.next;//��
		head.next = pPre;//����

		pCur->next = NULL;//��β
	}

//==============���==============//
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