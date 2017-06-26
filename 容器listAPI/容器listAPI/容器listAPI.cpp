#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include <list>

//==============测试类==============//
#include <string>
class Person
{
private:
	string name;
	int age;
public:
	Person(string n = "abc", int a = 0)
	{
		name = n;
		age = a;
	}

	string GetName()
	{
		return name;
	}

	int GetAge()
	{
		return age;
	}

	void PrintInfomation()
	{
		std::cout << "name = " << name << ", age = " << age << endl;
	}

	bool operator==(const Person & obj)
	{
		return (this->age == obj.age) && (this->name == obj.name);
	}


	bool operator>(const Person & obj)
	{
		return this->age > obj.age;
	}

	bool operator<(const Person & obj)
	{
		return this->age < obj.age;
	}
};

bool uppertolow(Person & p1, Person & p2)
{
	return p1 > p2;
}

//==============测试函数==============//
void test1()
{
	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);
	Person p5("eee", 50);

	//初始化
	/*
	list<T> lstT;//list采用采用模板类实现,对象的默认构造形式：
	list(beg,end);//构造函数将[beg, end)区间中的元素拷贝给本身。
	list(n,elem);//构造函数将n个elem拷贝给本身。
	list(const list &lst);//拷贝构造函数。
	*/
	list<Person> li1;		//默认构造
	list<Person> li2 = li1;	//拷贝
	list<Person> li3(li2);

	//插入
	li1.push_back(p1);
	li1.push_front(p2);
	li1.insert(li1.begin(), p3);
	li1.insert(li1.end(), 3, p4);
	li1.push_back(p5);
	list<Person> li4(li1.begin(), li1.end());
	for (auto i : li4)
	{
		i.PrintInfomation();
	}
	cout << "==============" << endl;
	list<Person> li5(3, p1);
	list<Person> li6 = { p1, p2, p3, p4, p5 };///////////////
	for (auto i : li6)
	{
		i.PrintInfomation();
	}
	cout << "==============" << endl;
	li3.insert(li3.begin(), li1.begin(), li1.end());
	for (auto i : li3)
	{
		i.PrintInfomation();
	}
	cout << "==============" << endl;

	//赋值
	/*
	assign(beg, end);//将[beg, end)区间中的数据拷贝赋值给本身。
	assign(n, elem);//将n个elem拷贝赋值给本身。
	list& operator=(const list &lst);//重载等号操作符
	swap(lst);//将lst与本身的元素互换。
	*/
	li3 = li1;

	//大小
	/*
	size();//返回容器中元素的个数
	empty();//判断容器是否为空
	resize(num);//重新指定容器的长度为num，
	若容器变长，则以默认值填充新位置。
	如果容器变短，则末尾超出容器长度的元素被删除。
	resize(num, elem);//重新指定容器的长度为num，
	若容器变长，则以elem值填充新位置。
	如果容器变短，则末尾超出容器长度的元素被删除。
	*/
	cout << li3.size() << endl;

	//存取 删除
	/*
	push_back(elem);//在容器尾部加入一个元素
	pop_back();//删除容器中最后一个元素
	push_front(elem);//在容器开头插入一个元素
	pop_front();//从容器开头移除第一个元素
	insert(pos,elem);//在pos位置插elem元素的拷贝，返回新数据的位置。
	insert(pos,n,elem);//在pos位置插入n个elem数据，无返回值。
	insert(pos,beg,end);//在pos位置插入[beg,end)区间的数据，无返回值。
	clear();//移除容器的所有数据
	erase(beg,end);//删除[beg,end)区间的数据，返回下一个数据的位置。
	erase(pos);//删除pos位置的数据，返回下一个数据的位置。
	remove(elem);//删除容器中所有与elem值匹配的元素。
	front();//返回第一个元素。
	back();//返回最后一个元素。
	*/
	Person a = li1.back();
	a.PrintInfomation();
	li1.pop_back();
	Person b = li1.back();
	b.PrintInfomation();
	Person c = li1.front();
	c.PrintInfomation();
	li1.pop_front();

	//反排序
	/*
	reverse();//反转链表，比如lst包含1,3,5元素，运行此方法后，lst就包含5,3,1元素。
	sort(); //list排序
	*/
	cout << "==============" << endl;
	for (list<Person>::iterator i = li1.begin(); i != li1.end(); ++i)
	{
		i->PrintInfomation();
	}
	cout << "==============" << endl;
	li1.reverse();
	for (list<Person>::iterator i = li1.begin(); i != li1.end(); ++i)
	{
		i->PrintInfomation();
	}
	cout << "==============" << endl;
	for (list<Person>::reverse_iterator i = li1.rbegin(); i != li1.rend(); ++i)
	{
		i->PrintInfomation();
	}
	cout << "==============" << endl;

	//删除
	cout << "=======删除=======" << endl;
	li1.erase(li1.begin());
	for (list<Person>::reverse_iterator i = li1.rbegin(); i != li1.rend(); ++i)
	{
		i->PrintInfomation();
	}
	cout << "==============" << endl;
	li1.erase(li1.begin(), li1.begin()++);
	for (list<Person>::reverse_iterator i = li1.rbegin(); i != li1.rend(); ++i)
	{
		i->PrintInfomation();
	}
}

void test2()
{
	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);
	Person p5("eee", 50);
	list<Person> li6 = { p1, p2, p3, p4, p5 };
	li6.sort(uppertolow);	//重载函数，默认升序排列，降序需要自己写重载函数
	for (auto i : li6)
	{
		i.PrintInfomation();
	}
	list<Person> li, li7;
	/*
	push_back(elem);//在容器尾部加入一个元素
	pop_back();//删除容器中最后一个元素
	push_front(elem);//在容器开头插入一个元素
	pop_front();//从容器开头移除第一个元素
	insert(pos,elem);//在pos位置插elem元素的拷贝，返回新数据的位置。
	insert(pos,n,elem);//在pos位置插入n个elem数据，无返回值。
	insert(pos,beg,end);//在pos位置插入[beg,end)区间的数据，无返回值。
	clear();//移除容器的所有数据
	erase(beg,end);//删除[beg,end)区间的数据，返回下一个数据的位置。
	erase(pos);//删除pos位置的数据，返回下一个数据的位置。
	remove(elem);//删除容器中所有与elem值匹配的元素。
	*/

	li6.remove(Person("ccc", 30));	//重载==，参数需要加const
	list<Person>::iterator it = li6.begin();
	it = li6.erase(++li6.begin());
	it->PrintInfomation();
	cout << "==============" << endl;
	li6.erase(++li6.begin(), --li6.end());
	for (auto i : li6)
	{
		i.PrintInfomation();
	}
	cout << "==============" << endl;
	li6.clear();
	cout << li6.empty() << endl;

	li6.resize(6, p1);
	cout << li6.size() << endl;
	li.assign(++li6.begin(), --li6.end());
	li7.assign(3, p2);
	li.swap(li7);
}
//==============主函数==============//
int main(void)
{
	//test1();
	test2();
	cout << "Compelete" << endl;
	return 0;
}
