#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;
void test()
{
//==============����==============//
	/*
	string();//����һ���յ��ַ��� ����: string str;      
	string(const string& str);//ʹ��һ��string�����ʼ����һ��string����
	string(const char* s);//ʹ���ַ���s��ʼ��
	string(int n, char c);//ʹ��n���ַ�c��ʼ�� 
	*/
	string str1, str7, str8;
	string str2("aaa");
	string str3 = "bbb";
	string str4(3, 'c');
	string str5(str4);
	string str6 = str5;
	cout << "��ֵ" << endl << str1 << str2 << str3
		<< str4 << str5 << str6 << str7 << str8 << endl;
//==============��ֵ==============//
	/*
	string& operator=(const char* s);//char*�����ַ��� ��ֵ����ǰ���ַ���
	string& operator=(const string &s);//���ַ���s������ǰ���ַ���
	string& operator=(char c);//�ַ���ֵ����ǰ���ַ���
	string& assign(const char *s);//���ַ���s������ǰ���ַ���
	string& assign(const char *s, int n);//���ַ���s��ǰn���ַ�������ǰ���ַ���
	string& assign(const string &s);//���ַ���s������ǰ�ַ���
	string& assign(int n, char c);//��n���ַ�c������ǰ�ַ���
	string& assign(const string &s, int start, int n);//��s��start��ʼn���ַ���ֵ���ַ���
	*/
	str1 = str2;
	str2 = "abc";
	str3 = 'd';
	str4.assign("efg");
	str5.assign("hijaaa", 3);
	str6.assign(str1);
	str7.assign(3, 'b');
	str8.assign(str5, 2, 1);
	cout << "��ֵ" << endl << str1 << str2 << str3 
		<< str4 << str5 << str6 << str7 << str8 << endl;
//==============��ȡ�ַ�==============//
	/*
	char& operator[](int n);//ͨ��[]��ʽȡ�ַ�
	char& at(int n);//ͨ��at������ȡ�ַ�
	*/
	cout << "��ȡ�ַ�" << endl;
	try
	{
		//cout << str1[10] << endl;
		cout << str1.at(10) << endl;
	}
	catch (const std::exception& ex)
	{
		cout << "�±�Խ��" << endl;
	}
//==============ƴ��==============//
	/*
	string& operator+=(const string& str);//����+=������
	string& operator+=(const char* str);//����+=������
	string& operator+=(const char c);//����+=������
	string& append(const char *s);//���ַ���s���ӵ���ǰ�ַ�����β
	string& append(const char *s, int n);//���ַ���s��ǰn���ַ����ӵ���ǰ�ַ�����β
	string& append(const string &s);//ͬoperator+=()
	string& append(const string &s, int pos, int n);//���ַ���s�д�pos��ʼ��n���ַ����ӵ���ǰ�ַ�����β
	string& append(int n, char c);//�ڵ�ǰ�ַ�����β���n���ַ�c
	*/

	str1 = "0"; str2 = str3 = str4 = str5 = '0';
	str1 += "111";
	str1 += '5';
	str2 += str1;
	str3 = str1 + "222";
	str4 = str1 + str2;
	str5 = str1 + str1 + "333" + str1 + '4';
	cout << "ƴ��" << endl << str1 << " " << str2 << " " << str3
		<< " " << str4 << " " << str5 << " " << endl;

	str1 = "0"; str2 = str3 = str4 = str5 = '0';
	str1.append("aaa");
	str2.append("bbbccc", 3);
	str3.append(str1);
	str4.append(str2, 1, 2);
	str5.append(3, 'c');
	cout << "ƴ��" << endl << str1 << " " << str2 << " " << str3
		<< " " << str4 << " " << str5 << " " << endl;
//==============�����滻==============//
	/*
	int find(const string& str, int pos = 0) const; //����str��һ�γ���λ��,��pos��ʼ����
	int find(const char* s, int pos = 0) const;		//����s��һ�γ���λ��,��pos��ʼ����
	int find(const char* s, int pos, int n) const;  //��posλ�ò���s��ǰn���ַ���һ��λ��
	int find(const char c, int pos = 0) const;		//�����ַ�c��һ�γ���λ��
	int rfind(const string& str, int pos = npos) const;//����str���һ��λ��,��pos��ʼ����
	int rfind(const char* s, int pos = npos) const;	//����s���һ�γ���λ��,��pos��ʼ����
	int rfind(const char* s, int pos, int n) const;	//��pos����s��ǰn���ַ����һ��λ��
	int rfind(const char c, int pos = 0) const;		//�����ַ�c���һ�γ���λ��
	string& replace(int pos, int n, const string& str); //�滻��pos��ʼn���ַ�Ϊ�ַ���str
	string& replace(int pos, int n, const char* s); //�滻��pos��ʼ��n���ַ�Ϊ�ַ���s
	*/
	string str = "aabbccddaabbaaeeaa";
	//			  012345678901234567
	str1 = "aa";
	int a, b, c, d, e, f, g;
	a = str.find('b');
	b = str.find('b', 5);
	c = str.find("bb");
	d = str.find("bb", 5);
	e = str.find(str1);
	f = str.find(str1, 5);
	g = str.find("aecd", 5, 2);
	cout << "�����滻" << endl << a << " " << b << " " << c
		<< " " << d << " " << e << " "<< f << " " << g << " " << endl;
	a = str.rfind(str1);
	b = str.rfind(str1, 5);
	c = str.rfind("aa");
	d = str.rfind("aa", 5);
	e = str.rfind("abcd", 15, 2);
	f = str.rfind('g');
	g = str.rfind('a', 10);
	cout << a << " " << b << " " << c << " " << d << " " << 
		e << " " << f << " " << g << " " << endl;
	str2 = str.replace(5, 3, "jjjjjj");
	str3 = "kkkkkk";
	str4 = str.replace(5, 3, str3);//�滻3���ַ����������
	cout << str2 << " " << str4 << endl;
//==============�Ƚ�==============//
	/*
	compare������>ʱ���� 1��<ʱ���� -1��==ʱ���� 0��
	�Ƚ����ִ�Сд���Ƚ�ʱ�ο��ֵ�˳����Խǰ���ԽС��
	��д��A��Сд��aС��
	int compare(const string &s) const;//���ַ���s�Ƚ�
	int compare(const char *s) const;//���ַ���s�Ƚ�
	*/
	str1 = "bbb";
	str2 = "BBB";
	cout << "�Ƚ�" << endl;
	cout << str1.compare(str2) << str1.compare("ddd") << endl;
//==============�Ӵ�==============//
	/*
	string substr(int pos = 0, int n = npos) const;//������pos��ʼ��n���ַ���ɵ��ַ���
	*/
	str1 = str.substr(5, 3);
	cout << "�Ӵ�" << endl << str1 << endl;
//==============����ɾ��==============//
	/*
	string& insert(int pos, const char* s); //�����ַ���
	string& insert(int pos, const string& str); //�����ַ���
	string& insert(int pos, int n, char c);//��ָ��λ�ò���n���ַ�c
	string& erase(int pos, int n = npos);//ɾ����Pos��ʼ��n���ַ� 
	*/
	str1 = "11"; str2 = "22";
	str1.insert(1, "aa");
	str1.insert(2, str2);
	str1.insert(3, 2, 'b');
	cout << "����" << endl << str1 << endl;
	str1.erase(1, 2);
	cout << "ɾ��" << endl << str1 << endl;
//==============��c����ַ���ת��==============//
	//string ת char*
	const char * cstr = str1.c_str();
	//char* ת string 
	str2 = "aaa";
	cout << "ת��" << endl << cstr << str2 << endl;
}

int main(void)
{
	test();

	cout << "Compelete" << endl;
	return 0;
}
