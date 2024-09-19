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
    T * pAddress; //ָ��ָ��������ٵ���ʵ����

    int m_Capacity; //��������

    int m_Size; //�����С

public:
    //�вι���
    MyArray(int capacity)
    {
        cout << "MyArray���вι���ĵ���" << endl;
        this->m_Capacity = capacity;    //��������������м���Ԫ��
        this->m_Size = 0;   //�ߴ磺��ǰ�Ѿ������˼���Ԫ��
        this->pAddress = new T[this->m_Capacity];
    }

    ~MyArray()
    {
        cout << "MyArray�����������ĵ���" << endl;
        if(this->pAddress != NULL)
        {
            delete [] this->pAddress;
            this->pAddress = NULL;
        }
    }

    //�������죬��������ΪMyArray���͵�arr��ע��Ҫ�����봫�루���Ḵ�Ƴ�����ĸ���������const����arr�����޸�
    MyArray(const MyArray& arr)
    {
        cout << "MyArray�Ŀ�������ĵ���" << endl;
        this->m_Capacity = arr.m_Capacity;
        this->m_Size = arr.m_Size;

        //this->pAddress = arr.pAddress;
        //����ָ����� Ҫ������� Ҫ���¿�������
        this->pAddress = new T[arr.m_Capacity];
        //���ٿռ�󣬻�Ҫ��arr�����е�����ȫ���ù���
        for (int i = 0; i < this->m_Size; ++i) {
            this->pAddress[i] = arr.pAddress[i];
        }
    }

    //����operator = ��ֹǳ����
    MyArray& operator=(const MyArray& arr)
    {
        cout << "MyArray��operator=�ĵ���" << endl;

        //���ж�ԭ���Ķ������Ƿ������ݣ��о����ͷŵ�
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

    //β�巨���������������value
    void Push_Back(const T& value)
    {
        if(this->m_Capacity == this->m_Size)
        {
            return;
        }

        this->pAddress[this->m_Size] = value;
        this->m_Size++;
    }

    //βɾ��
    void Pop_Back()
    {
        //���ж�����������û��Ԫ�أ�û�о�ֱ�ӷ���
        if(this->m_Size == 0)
        {
            return;
        }

        this->m_Size--;
    }

    //ͨ���±������������е�Ԫ��
    T& operator[](const int index)
    {
        return this->pAddress[index];
    }

    //������������
    int getCapacity()
    {
        return this->m_Capacity;
    }

    //���������С
    int getSize()
    {
        return this->m_Size;
    }
};