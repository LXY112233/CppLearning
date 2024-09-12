//
// Created by 11328 on 2024/9/9.
//

#pragma once
#include <iostream>
#include "worker.h"

using namespace std;

//继承自Worker抽象基类
class Employee :public Worker
{
public:
    Employee(int id, string name, int dId);

    void showInfo();
    string getDeptName();
};