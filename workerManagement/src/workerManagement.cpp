//
// Created by 11328 on 2024/9/7.
//

#include "../inc/workerManagement.h"

WorkerManager::WorkerManager() {

    ifstream ifs;
    ifs.open(FILENAME, ios::in);

    //文件不存在
    if (!ifs.is_open())
    {
        cout << "文件不存在" << endl;
        this->m_EmpNum = 0;
        this->m_EmpArray = NULL;
        this->m_FileIsEmpty = true;

        ifs.close();
        return;
    }

    //文件存在，没有数据
    char ch;
    ifs >> ch;
    if(ifs.eof())
    {
        cout << "文件为空" << endl;
        this->m_EmpNum = 0;
        this->m_EmpArray = NULL;
        this->m_FileIsEmpty = true;

        ifs.close();
        return;
    }

    //文件存在，有数据，读到指针数组中
    this->m_EmpNum = this->getEmpNum();
    cout << "职工人数为" << this->m_EmpNum << endl;

    this->m_EmpArray = new Worker * [this->m_EmpNum];
    this->initEmp();
}

WorkerManager::~WorkerManager() {
    //m_EmpArray保存的数据是new出来的，开辟在堆区，堆区数据手动开辟手动释放
    if(this->m_EmpArray != NULL)
    {
        for (int i = 0; i < this->m_EmpNum; ++i)
        {
            if(this->m_EmpArray[i] != NULL)
            {
                delete this->m_EmpArray[i];
            }
        }
        delete [] this->m_EmpArray;
        this->m_EmpArray = NULL;
    }
}

void WorkerManager::showMenu() {
    cout << "************************************" << endl;
    cout << "******* 欢迎使用职工管理系统 *******" << endl;
    cout << "********** 0.退出管理系统 **********" << endl;
    cout << "********** 1.增加职工信息 **********" << endl;
    cout << "********** 2.显示职工信息 **********" << endl;
    cout << "********** 3.删除离职职工 **********" << endl;
    cout << "********** 4.修改职工信息 **********" << endl;
    cout << "********** 5.查找职工信息 **********" << endl;
    cout << "********** 6.按照编号排序 **********" << endl;
    cout << "********** 7.清空所有文档 **********" << endl;
    cout << "************************************" << endl;
    cout << endl;
}

void WorkerManager::exitSystem() {
    cout << "欢迎下次使用" << endl;
    system("pause");
    exit(0);
}

void WorkerManager::addEmp() {

    cout << "请输入添加职工的数量" << endl;
    int addNum = 0;

    cin >> addNum;
    if(addNum > 0)
    {
        //计算新的数组的size
        int newSize = this->m_EmpNum + addNum;
        //开辟新空间
        Worker ** newSpace = new Worker * [newSize];
        //将原来的数据拷贝到新空间
        if(this->m_EmpArray != NULL)
        {
            for (int i = 0; i < this->m_EmpNum; ++i) {
                newSpace[i] = this->m_EmpArray[i];
            }
        }
        //添加新数据
        for (int i = 0; i < addNum; ++i)
        {
            int id;
            string name;
            int dSelect;

            cout << "请输入第 " << i+1 << " 个新职工的编号：" << endl;
            bool idInputFlag = true;
            while(idInputFlag)
            {
                cin >> id;
                if(this->isExist(id) == -1) //不存在此员工，这个id可以用
                {
                    idInputFlag = false;
                }
                else
                {
                    cout << "职工编号重复，请换新编号" << endl;
                }
            }

            cout << "请输入第 " << i+1 << " 个新职工的姓名：" << endl;
            bool nameInputFlag = true;
            while(nameInputFlag)
            {
                cin >> name;
                if(this->isExistByName(name) == -1) //不存在此员工，这个名字可以用
                {
                    nameInputFlag = false;
                }
                else
                {
                    cout << "职工姓名重复，请换新编号" << endl;
                }
            }

            cout << "请选择第 " << i+1 << " 个新职工的岗位：" << endl;
            cout << "1、普通职工 2、经理 3、老板" << endl;
            worker_FLAG:
            cin >> dSelect;

            Worker * worker = NULL;
            switch (dSelect) {
                case 1:
                    worker = new Employee(id,name,1);
                    break;
                case 2:
                    worker = new Manager(id,name,2);
                    break;
                case 3:
                    worker = new Boss(id,name,3);
                    break;
                default:
                    cout << "输入有误 请重新输入岗位的数字" << endl;
                    goto worker_FLAG;
            }

            //将创建的职工保存到数组中
            newSpace[this->m_EmpNum + i] = worker;
        }

        //释放原来的空间
        delete [] this->m_EmpArray;
        //更改新空间的指向
        this->m_EmpArray = newSpace;
        //更新新的职工人数
        this->m_EmpNum = newSize;

        //保存到文件中
        this->save();

        cout << "成功添加" << addNum << "名新职工" << endl;
    }
    else
    {
        cout << "输入有误" << endl;
    }

    system("pause");
    system("cls");
}

void WorkerManager::save() {

    ofstream ofs;
    ofs.open(FILENAME, ios::out);

    for (int i = 0; i < this->m_EmpNum; ++i) {
        ofs << this->m_EmpArray[i]->m_ID << " "
            << this->m_EmpArray[i]->m_Name << " "
            << this->m_EmpArray[i]->m_DeptID << endl;
    }

    ofs.close();

    this->m_FileIsEmpty = false;
}

int WorkerManager::getEmpNum() {
    ifstream ifs;
    ifs.open(FILENAME,ios::in);

    int id;
    string name;
    int dId;

    int num = 0;

    while(ifs>>id && ifs>>name && ifs>> dId)
    {
        num++;
    }

    return num;
}

void WorkerManager::initEmp() {
    ifstream ifs;
    ifs.open(FILENAME, ios::in);

    int id;
    string name;
    int dId;

    int index = 0;

    while(ifs >> id && ifs >> name && ifs >> dId)
    {
        Worker * worker = NULL;
        if(dId == 1)
            worker = new Employee(id,name,dId);
        else if(dId == 2)
            worker = new Manager(id,name,dId);
        else if(dId == 3)
            worker = new Boss(id,name,dId);

        this->m_EmpArray[index] = worker;

        index++;
    }

    ifs.close();
}

void WorkerManager::showEmp() {
    if(this->m_FileIsEmpty == true)
        cout << "文件不存在或为空" << endl;
    else
    {
        for (int i = 0; i < this->m_EmpNum; ++i) {
            this->m_EmpArray[i]->showInfo();
        }
    }
    system("pause");
    system("cls");
}

//放入员工的编号，返回员工在数组中的位置，若返回了-1，代表没有找到这个编号的员工
int WorkerManager::isExist(int id){
    int index = -1;

    for (int i = 0; i < this->m_EmpNum; ++i) {
        if (this->m_EmpArray[i]->m_ID == id)
        {
            index = i;
            break;
        }
    }

    return index;
}

//放入员工的名字，返回员工在数组中的位置，若返回了-1，代表没有找到这个名字的员工
int WorkerManager::isExistByName(string name){
    int index = -1;

    for (int i = 0; i < this->m_EmpNum; ++i) {
        if (this->m_EmpArray[i]->m_Name == name)
        {
            index = i;
            break;
        }
    }

    return index;
}

void WorkerManager::deleteEmp() {
    if(this->m_FileIsEmpty == true)
    {
        cout << "文件不存在，没有职工" << endl;
    }
    else
    {
        cout << "请输入要删除的职工编号" << endl;
        int id;
        cin >> id;

        int index = this->isExist(id);

        if(index != -1) //职工存在
        {
            //数据前移，进行覆盖
            for (int i = index; i < this->m_EmpNum; ++i)
            {
                this->m_EmpArray[i] = this->m_EmpArray[i+1];
            }

            this->m_EmpNum--;

            //数据重新保存到文件中
            this->save();

            cout << "删除成功" << endl;
        }
        else //职工不存在
        {
            cout << "删除失败，未找到职工" << endl;
        }
    }
    system("pause");
    system("cls");
}

void WorkerManager::modifyEmp() {
    if(this->m_FileIsEmpty == true)
    {
        cout << "文件不存在或为空" << endl;
    }
    else
    {
        cout << "请输入要修改的员工编号" << endl;
        int id;
        cin >> id;
        int index = this->isExist(id);
        if(index != -1) //员工存在，可以修改
        {
            //先释放掉这个位置上的数据
            delete this->m_EmpArray[index];

            int new_id = 0;
            string new_name = " ";
            int new_dId = 0;

            cout << "查到编号为: " << id << "的职工，请输入新的职工编号" << endl;
            cin >> new_id;
            cout << "请输入新姓名" << endl;
            cin >> new_name;
            cout << "请输入岗位" << endl;
            cout << "1、普通职工 2、经理 3、老板" << endl;
            cin >> new_dId;

            Worker * worker = NULL;
            switch (new_dId)
            {
                case 1:
                    worker = new Employee(new_id, new_name, new_dId);
                    break;
                case 2:
                    worker = new Manager(new_id, new_name, new_dId);
                    break;
                case 3:
                    worker = new Boss(new_id, new_name, new_dId);
                    break;
                default:
                    break;
            }

            this->m_EmpArray[index] = worker;

            this->save();

            cout << "修改成功" << endl;
        }
        else
        {
            cout << "未找到此职工，修改失败" << endl;
        }
    }
    system("pause");
    system("cls");
}

void WorkerManager::searchEmp() {
    if(this->m_FileIsEmpty == true)
    {
        cout << "文件为空，没有员工" << endl;
    }
    else
    {
        cout << "请输入要查找员工的方式 1、编号查找 2、姓名查找" << endl;
        int waySelect = 0;

        bool waySelectFlag = true;
        while(waySelectFlag)
        {
            cin >> waySelect;
            if(waySelect == 1)  //编号查找
            {
                waySelectFlag = false;

                cout << "请输入要查找的职工的编号" << endl;
                int id_input;
                cin >> id_input;
                int id_index = this->isExist(id_input);
                if(id_index != -1) //找到了
                {
                    this->m_EmpArray[id_index]->showInfo();
                }
                else
                {
                    cout << "未找到此姓名的职工" << endl;
                }
            }
            else if(waySelect == 2)  //姓名查找
            {
                waySelectFlag = false;

                cout << "请输入要查找的职工的姓名" << endl;
                string name_input;
                cin >> name_input;
                int indexByName = this->isExistByName(name_input);
                if( indexByName != -1)
                {
                    this->m_EmpArray[indexByName]->showInfo();
                }
                else
                {
                    cout << "未找到此姓名的职工" << endl;
                }
            }
            else
            {
                cout << "方式选择错误，请重新输入" << endl;
                waySelectFlag = true;
            }
        }
    }
    system("pause");
    system("cls");
}

//使用选择排序算法，对员工的进行编号排序
void WorkerManager::sortEmp() {
    if(this->m_FileIsEmpty == true)
    {
        cout << "文件不存在，没有员工" << endl;
        system("pause");
        system("cls");
    }
    else
    {
        cout << "请选择升序或降序 1、升序 2、降序" << endl;
        int sortSelect = 0;
        bool sortSelectFLAG = true;
        while(sortSelectFLAG)
        {
            cin >> sortSelect;
            if(sortSelect == 1 || sortSelect ==2)
            {
                sortSelectFLAG = false;

                //选择排序算法
                for (int i = 0; i < this->m_EmpNum; ++i)
                {
                    int minOrMax = i;
                    for (int j = i+1; j < this->m_EmpNum; ++j) {
                        if(sortSelect == 1) //升序
                        {
                            if(this->m_EmpArray[minOrMax]->m_ID > this->m_EmpArray[j]->m_ID)
                            {
                                minOrMax = j;
                            }
                        }
                        if(sortSelect == 2) //降序
                        {
                            if(this->m_EmpArray[minOrMax]->m_ID < this->m_EmpArray[j]->m_ID)
                            {
                                minOrMax = j;
                            }
                        }
                    }
                    if(i != minOrMax)
                    {
                        Worker * temp = m_EmpArray[i];
                        m_EmpArray[i] = m_EmpArray[minOrMax];
                        m_EmpArray[minOrMax] = temp;
                    }
                }
            }
            else
            {
                cout << "输入有误，请重新选择" << endl;
                sortSelectFLAG = true;
            }
        }
        cout << "排序成功，排序后的结果为" << endl;
        this->save();
        this->showEmp();
    }
}

void WorkerManager::clearFile() {

    cout << "确认清空? 1、确认 2、返回" << endl;

    int inputSelect = 0;
    bool inputSelectFLAG = true;

    while(inputSelectFLAG)
    {
        cin >> inputSelect;
        if(inputSelect == 1 || inputSelect ==2)
        {
            inputSelectFLAG = false;
            if(inputSelect == 1) {
                //打开模式为ios::trunc，如果存在，删除文件并重新创建
                ofstream ofs(FILENAME, ios::trunc);
                ofs.close();

                if (this->m_EmpArray != NULL) {
                    for (int i = 0; i < this->m_EmpNum; ++i) {
                        if (this->m_EmpArray[i] != NULL) {
                            delete this->m_EmpArray[i];
                        }
                    }
                    this->m_EmpNum = 0;
                    delete[] this->m_EmpArray;
                    this->m_EmpArray = NULL;
                    this->m_FileIsEmpty = true;
                }

                cout << "清除成功" << endl;
            }
        }
        else
        {
            cout << "输入有误，请重新输入" << endl;
            inputSelectFLAG = true;
        }
    }

    system("pause");
    system("cls");
}
