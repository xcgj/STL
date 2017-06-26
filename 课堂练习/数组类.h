#pragma once

//template <typename T>
class myArray
{
	//������ ����<<
	friend std::ostream & operator<<(std::ostream & , myArray &);
public:
	//Ĭ���в�
	myArray(int cap = 20);
	//��������
	myArray(const myArray &);
	//����
	~myArray();
	//��ֵ������=
	myArray & operator=(const  myArray &);
	//����[]
	int & operator[](int index);//���Ǻ�������ֵ����ֵ
	//����<<
	myArray & operator<<(const int &);
	//��������
	bool operator()(myArray &);
	//����
	void pushback(const int &);
	//ɾ��
	void pop();
	//���С
	int size();
private:
	int *array;
	int msize;//��С
	int mcapacity;//����
};

