#include <iostream>
#include <string>
#include "inc/MyArray.hpp"

using namespace std;

void test01()
{
    //使用有参构造去创建一个长度5的数组arr1
    MyArray<int> arr1(5);

    //使用拷贝构造去创建一个数组arr2
    MyArray<int> arr2(arr1);

    //使用有参构造去创建一个长度100的数组arr3
    MyArray<int> arr3(100);
    //用运算符将arr1赋值给arr3
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

    cout << "容量和尺寸" << endl;
    cout << arr4.getCapacity() << endl;
    cout << arr4.getSize() << endl;

    cout << "尾删后" << endl;
    arr4.Pop_Back();
    for (int i = 0; i < arr4.getSize(); ++i) {
        cout << arr4[i] << endl;
    }

    cout << "容量和尺寸" << endl;
    cout << arr4.getCapacity() << endl;
    cout << arr4.getSize() << endl;
}

int main() {

//    test01();

    test02();

    return 0;
}
