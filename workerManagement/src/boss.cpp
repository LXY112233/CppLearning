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
    cout << "ְ�����: " << this->m_ID << "\t"
         << "ְ������: " << this->m_Name << "\t"
         << "ְ����λ: " << this->getDeptName() << "\t"
         << "��λְ��: ����˾��������" << endl;
}

string Boss::getDeptName(){
    return string("�ϰ�");
}