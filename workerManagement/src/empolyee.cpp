//
// Created by 11328 on 2024/9/9.
//

#include "../inc/employee.h"

Employee::Employee(int id, std::string name, int dId) {
    this->m_ID = id;
    this->m_Name = name;
    this->m_DeptID = dId;
}

void Employee::showInfo() {
    cout << "职工编号: " << this->m_ID << "\t"
         << "职工姓名: " << this->m_Name << "\t"
         << "职工岗位: " << this->getDeptName() << "\t"
         << "岗位职责: 完成经理交给的任务" << endl;
}

string Employee::getDeptName() {
    return string("员工");
}
