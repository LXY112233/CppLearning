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
    cout << "ְ�����: " << this->m_ID << "\t"
         << "ְ������: " << this->m_Name << "\t"
         << "ְ����λ: " << this->getDeptName() << "\t"
         << "��λְ��: ����ϰ彻�������񣬲����·�����" << endl;
}

string Manager::getDeptName(){
    return string("����");
}