/*
���ñ����㷨

�����㷨 ��������Ԫ��
@param beg ��ʼ������
@param end ����������
@param _callback  �����ص����ߺ�������
@return ��������
for_each(iterator beg, iterator end, _callback);

transform�㷨 ��ָ����������Ԫ�ذ��˵���һ������
ע�� : transform �����Ŀ�����������ڴ棬������Ҫ������ǰ������ڴ�
@param beg1 Դ������ʼ������
@param end1 Դ��������������
@param beg2 Ŀ��������ʼ������
@param _cakkback �ص��������ߺ�������
@return ����Ŀ������������
transform(iterator beg1, iterator end1, iterator beg2, _callbakc)


���ò����㷨

find�㷨 ����Ԫ��
@param beg ������ʼ������
@param end ��������������
@param value ���ҵ�Ԫ��
@return ���ز���Ԫ�ص�λ��
find(iterator beg, iterator end, value)

adjacent_find�㷨 ���������ظ�Ԫ��
@param beg ������ʼ������
@param end ��������������
@param  _callback �ص���������ν��(����bool���͵ĺ�������)
@return ��������Ԫ�صĵ�һ��λ�õĵ�����
adjacent_find(iterator beg, iterator end, _callback);

binary_search�㷨 ���ֲ��ҷ�
ע��: �����������в�����
@param beg ������ʼ������
@param end ��������������
@param value ���ҵ�Ԫ��
@return bool ���ҷ���true ����false
bool binary_search(iterator beg, iterator end, value);

find_if�㷨 ��������
@param beg ������ʼ������
@param end ��������������
@param  callback �ص���������ν��(����bool���͵ĺ�������)
@return bool ���ҷ���true ����false
bool find_if(iterator beg, iterator end, _callback);

count�㷨 ͳ��Ԫ�س��ִ���
@param beg ������ʼ������
@param end ��������������
@param  value�ص���������ν��(����bool���͵ĺ�������)
@return int����Ԫ�ظ���
size_t count(iterator beg, iterator end, value);

count_if�㷨 ͳ��Ԫ�س��ִ���
@param beg ������ʼ������
@param end ��������������
@param  callback �ص���������ν��(����bool���͵ĺ�������)
@return int����Ԫ�ظ���
size_t count_if(iterator beg, iterator end, _callback);




���������㷨

merge�㷨 ����Ԫ�غϲ������洢����һ������
@param beg1 ����1��ʼ������
@param end1 ����1����������
@param beg2 ����2��ʼ������
@param end2 ����2����������
@param dest  Ŀ��������ʼ������
merge(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest)

sort�㷨 ����Ԫ������
ע��:�������������������
@param beg ����1��ʼ������
@param end ����1����������
@param _callback �ص���������ν��(����bool���͵ĺ�������)
sort(iterator beg, iterator end, _callback)

sort�㷨 ��ָ����Χ�ڵ�Ԫ�������������
@param beg ������ʼ������
@param end ��������������
random_shuffle(iterator beg, iterator end)

reverse�㷨 ��תָ����Χ��Ԫ��
@param beg ������ʼ������
@param end ��������������
reverse(iterator beg, iterator end)




���ÿ������滻�㷨

copy�㷨 ��������ָ����Χ��Ԫ�ؿ�������һ������
@param beg ������ʼ������
@param end ��������������
@param dest Ŀ����������������
@return ����Ŀ�������ĵ�����
copy(iterator beg, iterator end, iterator dest)

replace�㷨 ��������ָ����Χ�ľ�Ԫ���޸�Ϊ��Ԫ��
@param beg ������ʼ������
@param end ��������������
@param oldvalue ��Ԫ��
@param newvalue ��Ԫ��
@return ����void
replace(iterator beg, iterator end, oldvalue, newvalue)

replace_if�㷨 ��������ָ����Χ����������Ԫ���滻Ϊ��Ԫ��
@param beg ������ʼ������
@param end ��������������
@param callback�����ص�����ν��(����Bool���͵ĺ�������)
@param newvalue ��Ԫ��
@return ����void
replace_if(iterator beg, iterator end, _callback, newvalue)

swap�㷨 ��������������Ԫ��
@param c1����1
@param c2����2
@return ����void
swap(container c1, container c2)



�������������㷨

accumulate�㷨 ��������Ԫ���ۼ��ܺ�
@param beg ������ʼ������
@param end ��������������
@param value�ۼ�ֵ
@return ����value
accumulate(iterator beg, iterator end, value)

fill�㷨 �����������Ԫ��
@param beg ������ʼ������
@param end ��������������
@param value t���Ԫ��
@return ����void
fill(iterator beg, iterator end, value)




���ü����㷨

set_intersection�㷨 ������set���ϵĽ���
ע��:�������ϱ�������������
@param beg1 ����1��ʼ������
@param end1 ����1����������
@param beg2 ����2��ʼ������
@param end2 ����2����������
@param dest  Ŀ��������ʼ������
@return Ŀ�����������һ��Ԫ�صĵ�������ַ
set_intersection(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest)

set_union�㷨 ������set���ϵĲ���
ע��:�������ϱ�������������
@param beg1 ����1��ʼ������
@param end1 ����1����������
@param beg2 ����2��ʼ������
@param end2 ����2����������
@param dest  Ŀ��������ʼ������
@return Ŀ�����������һ��Ԫ�صĵ�������ַ
set_union(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest)

set_difference�㷨 ������set���ϵĲ
ע��:�������ϱ�������������
@param beg1 ����1��ʼ������
@param end1 ����1����������
@param beg2 ����2��ʼ������
@param end2 ����2����������
@param dest  Ŀ��������ʼ������
@return Ŀ�����������һ��Ԫ�صĵ�������ַ
set_difference(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest)


*/

int main(void)
{
	return 0;
}
