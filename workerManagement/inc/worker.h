//
// Created by 11328 on 2024/9/9.
//

#pragma once

#include <iostream>
#include <string>

using namespace std;

//抽象基类，这个类里面有纯虚函数
class Worker
{
public:
    virtual void showInfo() = 0;
    virtual string getDeptName() = 0;

    int m_ID;
    string m_Name;
    int m_DeptID;
};