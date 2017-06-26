#pragma once

//template <typename T>
class myArray
{
	//遍历， 重载<<
	friend std::ostream & operator<<(std::ostream & , myArray &);
public:
	//默认有参
	myArray(int cap = 20);
	//拷贝构造
	myArray(const myArray &);
	//析构
	~myArray();
	//赋值，重载=
	myArray & operator=(const  myArray &);
	//重载[]
	int & operator[](int index);//考虑函数返回值当左值
	//重载<<
	myArray & operator<<(const int &);
	//函数对象
	bool operator()(myArray &);
	//插入
	void pushback(const int &);
	//删除
	void pop();
	//查大小
	int size();
private:
	int *array;
	int msize;//大小
	int mcapacity;//容量
};

