#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <deque>
#include <string>
using namespace std;

//==============�û��Զ���������==============//
class Person
{
private:
	int age;
	string name;
public:
	Person()
	{

	}
	Person(int a, string n)
	{
		age = a;
		name = n;
	}
	void Prnt()
	{
		cout << name << " " << age << endl;
	}
};

void dequeAPI()
{
	Person p1(10, "aa");
	Person p2(20, "bb");
	Person p3(30, "cc");
	Person p4(40, "dd");
	Person p5(50, "ee");
//==============����==============//
	/*
	deque<T> deqT;//Ĭ�Ϲ�����ʽ
	deque(beg, end);//���캯����[beg, end)�����е�Ԫ�ؿ���������
	deque(n, elem);//���캯����n��elem����������
	deque(const deque &deq);//�������캯����
	*/
	deque<Person> d1;
	deque<Person> d2(d1.begin(), d1.end());
	deque<Person> d3(3, p5);
	deque<Person> d4 = d3;
	deque<Person> d5(d4);
//==============����ɾ��==============//
	/*
	push_back(elem);//������β�����һ������
	push_front(elem);//������ͷ������һ������
	insert(pos,elem);//��posλ�ò���һ��elemԪ�صĿ��������������ݵ�λ�á�
	insert(pos,n,elem);//��posλ�ò���n��elem���ݣ��޷���ֵ��
	insert(pos,beg,end);//��posλ�ò���[beg,end)��������ݣ��޷���ֵ��
	*/
	d1.push_back(p1);
	d1.push_front(p2);
	d1.insert(d1.begin() + 1, p3);
	d1.insert(d1.begin(), 2, p4);
	d1.insert(d1.begin() + 2, d3.begin(), d3.begin() + 1);
	for (deque<Person>::iterator i = d1.begin(); i != d1.end(); ++i)
	{
		i->Prnt();
	}
//=============ɾ��===============//
	/*
	pop_back();//ɾ���������һ������
	pop_front();//ɾ��������һ������
	clear();//�Ƴ���������������
	erase(beg,end);//ɾ��[beg,end)��������ݣ�������һ�����ݵ�λ�á�
	erase(pos);//ɾ��posλ�õ����ݣ�������һ�����ݵ�λ�á�
	*/
	d2 = d1;
	d2.pop_back();
	d2.pop_front();
	d2.erase(d2.begin() + 1);
	d2.erase(d2.end() - 2, d2.end());
	d2.clear();
//==============��ѯ==============//
	/*
	at(idx);//��������idx��ָ�����ݣ����idxԽ�磬�׳�out_of_range��
	operator[];//��������idx��ָ�����ݣ����idxԽ�磬���׳��쳣��ֱ�ӳ���
	front();//���ص�һ�����ݡ�
	back();//�������һ������
	*/
	d1.at(1);
	d1[2];
	d1.front();
	d1.back();
//==============��ֵ==============//
	/*
	assign(beg, end);//��[beg, end)�����е����ݿ�����ֵ������
	assign(n, elem);//��n��elem������ֵ������
	deque& operator=(const deque &deq); //���صȺŲ����� 
	swap(deq);// ��deq�뱾���Ԫ�ػ���
	*/
	d2.assign(d1.begin() + 1, d1.end());
	d3.assign(3, p3);
	d4 = d2;
	d3.swap(d2);
//==============��С==============//
	/*
	deque.size();//����������Ԫ�صĸ���
	deque.empty();//�ж������Ƿ�Ϊ��
	deque.resize(num);//����ָ�������ĳ���Ϊnum,�������䳤������Ĭ��ֵ�����λ�á����������̣���ĩβ�����������ȵ�Ԫ�ر�ɾ����
	deque.resize(num, elem); //����ָ�������ĳ���Ϊnum,�������䳤������elemֵ�����λ��,���������̣���ĩβ�����������ȵ�Ԫ�ر�ɾ����
	*/
	d1.size();
	d1.empty();
	d1.resize(10);
	d1.resize(20, p2);
}

int main(void)
{
	dequeAPI();

	cout << "Compelete" << endl;
	return 0;
}
