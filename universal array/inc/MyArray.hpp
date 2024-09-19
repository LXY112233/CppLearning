//
// Created by 11328 on 2024/9/14.
//

#pragma once

#include <iostream>
#include <string>

using namespace std;

template <class T>
class MyArray
{
private:
    T * pAddress; //指针指向堆区开辟的真实数据

    int m_Capacity; //数组容量

    int m_Size; //数组大小

public:
    //有参构造
    MyArray(int capacity)
    {
        cout << "MyArray的有参构造的调用" << endl;
        this->m_Capacity = capacity;    //容量：这个数组有几个元素
        this->m_Size = 0;   //尺寸：当前已经容纳了几个元素
        this->pAddress = new T[this->m_Capacity];
    }

    ~MyArray()
    {
        cout << "MyArray的析构函数的调用" << endl;
        if(this->pAddress != NULL)
        {
            delete [] this->pAddress;
            this->pAddress = NULL;
        }
    }

    //拷贝构造，函数参数为MyArray类型的arr，注意要用引入传入（不会复制出多余的副本），且const保护arr不被修改
    MyArray(const MyArray& arr)
    {
        cout << "MyArray的拷贝构造的调用" << endl;
        this->m_Capacity = arr.m_Capacity;
        this->m_Size = arr.m_Size;

        //this->pAddress = arr.pAddress;
        //对于指针变量 要进行深拷贝 要重新开辟数据
        this->pAddress = new T[arr.m_Capacity];
        //开辟空间后，还要把arr数组中的数据全部拿过来
        for (int i = 0; i < this->m_Size; ++i) {
            this->pAddress[i] = arr.pAddress[i];
        }
    }

    //重载operator = 防止浅拷贝
    MyArray& operator=(const MyArray& arr)
    {
        cout << "MyArray的operator=的调用" << endl;

        //先判断原来的堆区上是否有数据，有就先释放掉
        if(this->pAddress != NULL)
        {
            delete [] this->pAddress;
            this->pAddress = NULL;
            this->m_Capacity = 0;
            this->m_Size = 0;
        }

        this->m_Capacity = arr.m_Capacity;
        this->m_Size = arr.m_Size;
        this->pAddress = new T[arr.m_Capacity];

        for (int i = 0; i < this->m_Capacity; ++i) {
            this->pAddress[i] = arr.pAddress[i];
        }

        return *this;
    }

    //尾插法，在数组的最后放入value
    void Push_Back(const T& value)
    {
        if(this->m_Capacity == this->m_Size)
        {
            return;
        }

        this->pAddress[this->m_Size] = value;
        this->m_Size++;
    }

    //尾删法
    void Pop_Back()
    {
        //先判断数组里面有没有元素，没有就直接返回
        if(this->m_Size == 0)
        {
            return;
        }

        this->m_Size--;
    }

    //通过下标来访问数组中的元素
    T& operator[](const int index)
    {
        return this->pAddress[index];
    }

    //返回数组容量
    int getCapacity()
    {
        return this->m_Capacity;
    }

    //返回数组大小
    int getSize()
    {
        return this->m_Size;
    }
};