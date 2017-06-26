#include <iostream>
#include <queue>
using namespace std;

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

	Person & operator=(const Person &  obj)
	{
		this->age = obj.age;
		this->name = obj.name;
		return *this;
	}
};

//==============测试文件==============//
void test()
{
	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);
	Person p5("eee", 50);
	//初始化
	/*
	queue<T> queT;//queue采用模板类实现，queue对象的默认构造形式：
	queue(const queue &que);//拷贝构造函数
	*/
	queue<Person> v1;		//默认构造
	queue<Person> v2(v1);	//拷贝构造
	queue<Person> v3 = v2;

	//插入
	v1.push(p1);
	v1.push(p2);
	v1.push(p3);
	v1.push(p4);
	v1.push(p5);

	//赋值
	//queue& operator=(const queue &que);//重载等号操作符
	v2 = v1;

	//存取
	/*
	push(elem);//往队尾添加元素
	pop();//从队头移除第一个元素
	back();//返回最后一个元素
	front();//返回第一个元素
	*/
	Person a = v2.back();	//队尾
	Person b = v2.front();	//队头
	a.PrintInfomation();
	b.PrintInfomation();
	//大小
	/*
	empty();//判断队列是否为空
	size();//返回队列的大小
	*/
	cout << "大小 = " << v2.size() << endl;

	//删除
	v1.pop();	//队头出队
	v3.swap(v1);
}
//队列不能随机访问，不能遍历，没有迭代器
//==============主函数==============//
int main(void)
{
	test();

	return 0;
}