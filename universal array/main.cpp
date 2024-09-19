#include <iostream>
#include <string>
#include "inc/MyArray.hpp"

using namespace std;

void test01()
{
    //ʹ���вι���ȥ����һ������5������arr1
    MyArray<int> arr1(5);

    //ʹ�ÿ�������ȥ����һ������arr2
    MyArray<int> arr2(arr1);

    //ʹ���вι���ȥ����һ������100������arr3
    MyArray<int> arr3(100);
    //���������arr1��ֵ��arr3
    arr3 = arr1;
}

void test02()
{
    MyArray<int> arr4(5);

    for (int i = 0; i < 5; ++i) {
        arr4.Push_Back(i);
    }

    for (int i = 0; i < arr4.getSize(); ++i) {
        cout << arr4[i] << endl;
    }

    cout << "�����ͳߴ�" << endl;
    cout << arr4.getCapacity() << endl;
    cout << arr4.getSize() << endl;

    cout << "βɾ��" << endl;
    arr4.Pop_Back();
    for (int i = 0; i < arr4.getSize(); ++i) {
        cout << arr4[i] << endl;
    }

    cout << "�����ͳߴ�" << endl;
    cout << arr4.getCapacity() << endl;
    cout << arr4.getSize() << endl;
}

int main() {

//    test01();

    test02();

    return 0;
}
