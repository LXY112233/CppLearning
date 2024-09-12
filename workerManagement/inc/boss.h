//
// Created by 11328 on 2024/9/9.
//

#pragma once

#include <iostream>
#include "worker.h"
using namespace std;

class Boss :public Worker
{
public:
    Boss(int id, string name, int dId);

    void showInfo();
    string getDeptName();
};

