//
// Created by 11328 on 2024/9/9.
//

#include <iostream>
#include "../inc/boss.h"

Boss::Boss(int id, std::string name, int dId) {
    this->m_ID = id;
    this->m_Name = name;
    this->m_DeptID = dId;
}

void Boss::showInfo(){
    cout << "职工编号: " << this->m_ID << "\t"
         << "职工姓名: " << this->m_Name << "\t"
         << "职工岗位: " << this->getDeptName() << "\t"
         << "岗位职责: 管理公司所有事务" << endl;
}

string Boss::getDeptName(){
    return string("老板");
}