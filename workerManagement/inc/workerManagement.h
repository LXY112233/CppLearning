//
// Created by 11328 on 2024/9/7.
//

/*
 * 与用户的沟通菜单界面
 * 对职工增删改查的操作
 * 与文件的读写交互
 */

#pragma once

#include <iostream>
#include <string>

#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

#include <fstream>
#define FILENAME "empFile.txt"


using namespace std;

class WorkerManager
{
public:
    WorkerManager();

    ~WorkerManager();

    void showMenu();

    void exitSystem();

    void addEmp();

    void save();

    int getEmpNum();

    void initEmp();

    void showEmp();

    void deleteEmp();

    int isExist(int id);

    int isExistByName(string name);

    void modifyEmp();

    void searchEmp();

    void sortEmp();

    void clearFile();

    //保存 职工人数
    int m_EmpNum;

    //保存 职工数组指针
    Worker ** m_EmpArray;

    //文件是否为空
    bool m_FileIsEmpty;

};


