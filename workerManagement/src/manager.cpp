//
// Created by 11328 on 2024/9/9.
//

#include "../inc/manager.h"

Manager::Manager(int id, std::string name, int dId) {
    this->m_ID = id;
    this->m_Name = name;
    this->m_DeptID = dId;
}

void Manager::showInfo(){
    cout << "职工编号: " << this->m_ID << "\t"
         << "职工姓名: " << this->m_Name << "\t"
         << "职工岗位: " << this->getDeptName() << "\t"
         << "岗位职责: 完成老板交给的任务，并且下发任务" << endl;
}

string Manager::getDeptName(){
    return string("经理");
}