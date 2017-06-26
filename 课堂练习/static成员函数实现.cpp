#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Person {
public:
	//��ͨ��Ա�������Է���static��non-static��Ա����
	void changeParam1(int param) {
		mParam = param;
		sNum = param;
	}
	//��̬��Ա����ֻ�ܷ���static��Ա����
	static void changeParam2(int param);
	void test()
	{
		changeParam2(1);//��ͨ��Ա�������þ�̬��Ա����
	}

	void func()const 
	{
		cout << mParam << endl;
		mParam = 1;
	}
private:
	static void changeParam3(int param) {
		//mParam = param; //�޷�����
		sNum = param;
	}
public:
	int mParam;
	static int sNum;
};

//��̬��Ա���������ʼ��
int Person::sNum = 0;

void Person::changeParam2(int param)
{
	//mParam = param; //�޷�����
	sNum = param;
}

int main() {

	//1. ����ֱ�ӵ���
	Person::changeParam2(100);

	//2. ͨ���������
	Person p;
	p.changeParam2(200);

	//3. ��̬��Ա����Ҳ�з���Ȩ��
	//Person::changeParam3(100); //�����޷�����˽�о�̬��Ա����
	//Person p1;
	//p1.changeParam3(200);
	return EXIT_SUCCESS;
}