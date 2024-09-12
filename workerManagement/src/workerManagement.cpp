//
// Created by 11328 on 2024/9/7.
//

#include "../inc/workerManagement.h"

WorkerManager::WorkerManager() {

    ifstream ifs;
    ifs.open(FILENAME, ios::in);

    //�ļ�������
    if (!ifs.is_open())
    {
        cout << "�ļ�������" << endl;
        this->m_EmpNum = 0;
        this->m_EmpArray = NULL;
        this->m_FileIsEmpty = true;

        ifs.close();
        return;
    }

    //�ļ����ڣ�û������
    char ch;
    ifs >> ch;
    if(ifs.eof())
    {
        cout << "�ļ�Ϊ��" << endl;
        this->m_EmpNum = 0;
        this->m_EmpArray = NULL;
        this->m_FileIsEmpty = true;

        ifs.close();
        return;
    }

    //�ļ����ڣ������ݣ�����ָ��������
    this->m_EmpNum = this->getEmpNum();
    cout << "ְ������Ϊ" << this->m_EmpNum << endl;

    this->m_EmpArray = new Worker * [this->m_EmpNum];
    this->initEmp();
}

WorkerManager::~WorkerManager() {
    //m_EmpArray�����������new�����ģ������ڶ��������������ֶ������ֶ��ͷ�
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
    cout << "******* ��ӭʹ��ְ������ϵͳ *******" << endl;
    cout << "********** 0.�˳�����ϵͳ **********" << endl;
    cout << "********** 1.����ְ����Ϣ **********" << endl;
    cout << "********** 2.��ʾְ����Ϣ **********" << endl;
    cout << "********** 3.ɾ����ְְ�� **********" << endl;
    cout << "********** 4.�޸�ְ����Ϣ **********" << endl;
    cout << "********** 5.����ְ����Ϣ **********" << endl;
    cout << "********** 6.���ձ������ **********" << endl;
    cout << "********** 7.��������ĵ� **********" << endl;
    cout << "************************************" << endl;
    cout << endl;
}

void WorkerManager::exitSystem() {
    cout << "��ӭ�´�ʹ��" << endl;
    system("pause");
    exit(0);
}

void WorkerManager::addEmp() {

    cout << "���������ְ��������" << endl;
    int addNum = 0;

    cin >> addNum;
    if(addNum > 0)
    {
        //�����µ������size
        int newSize = this->m_EmpNum + addNum;
        //�����¿ռ�
        Worker ** newSpace = new Worker * [newSize];
        //��ԭ�������ݿ������¿ռ�
        if(this->m_EmpArray != NULL)
        {
            for (int i = 0; i < this->m_EmpNum; ++i) {
                newSpace[i] = this->m_EmpArray[i];
            }
        }
        //���������
        for (int i = 0; i < addNum; ++i)
        {
            int id;
            string name;
            int dSelect;

            cout << "������� " << i+1 << " ����ְ���ı�ţ�" << endl;
            bool idInputFlag = true;
            while(idInputFlag)
            {
                cin >> id;
                if(this->isExist(id) == -1) //�����ڴ�Ա�������id������
                {
                    idInputFlag = false;
                }
                else
                {
                    cout << "ְ������ظ����뻻�±��" << endl;
                }
            }

            cout << "������� " << i+1 << " ����ְ����������" << endl;
            bool nameInputFlag = true;
            while(nameInputFlag)
            {
                cin >> name;
                if(this->isExistByName(name) == -1) //�����ڴ�Ա����������ֿ�����
                {
                    nameInputFlag = false;
                }
                else
                {
                    cout << "ְ�������ظ����뻻�±��" << endl;
                }
            }

            cout << "��ѡ��� " << i+1 << " ����ְ���ĸ�λ��" << endl;
            cout << "1����ְͨ�� 2������ 3���ϰ�" << endl;
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
                    cout << "�������� �����������λ������" << endl;
                    goto worker_FLAG;
            }

            //��������ְ�����浽������
            newSpace[this->m_EmpNum + i] = worker;
        }

        //�ͷ�ԭ���Ŀռ�
        delete [] this->m_EmpArray;
        //�����¿ռ��ָ��
        this->m_EmpArray = newSpace;
        //�����µ�ְ������
        this->m_EmpNum = newSize;

        //���浽�ļ���
        this->save();

        cout << "�ɹ����" << addNum << "����ְ��" << endl;
    }
    else
    {
        cout << "��������" << endl;
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
        cout << "�ļ������ڻ�Ϊ��" << endl;
    else
    {
        for (int i = 0; i < this->m_EmpNum; ++i) {
            this->m_EmpArray[i]->showInfo();
        }
    }
    system("pause");
    system("cls");
}

//����Ա���ı�ţ�����Ա���������е�λ�ã���������-1������û���ҵ������ŵ�Ա��
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

//����Ա�������֣�����Ա���������е�λ�ã���������-1������û���ҵ�������ֵ�Ա��
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
        cout << "�ļ������ڣ�û��ְ��" << endl;
    }
    else
    {
        cout << "������Ҫɾ����ְ�����" << endl;
        int id;
        cin >> id;

        int index = this->isExist(id);

        if(index != -1) //ְ������
        {
            //����ǰ�ƣ����и���
            for (int i = index; i < this->m_EmpNum; ++i)
            {
                this->m_EmpArray[i] = this->m_EmpArray[i+1];
            }

            this->m_EmpNum--;

            //�������±��浽�ļ���
            this->save();

            cout << "ɾ���ɹ�" << endl;
        }
        else //ְ��������
        {
            cout << "ɾ��ʧ�ܣ�δ�ҵ�ְ��" << endl;
        }
    }
    system("pause");
    system("cls");
}

void WorkerManager::modifyEmp() {
    if(this->m_FileIsEmpty == true)
    {
        cout << "�ļ������ڻ�Ϊ��" << endl;
    }
    else
    {
        cout << "������Ҫ�޸ĵ�Ա�����" << endl;
        int id;
        cin >> id;
        int index = this->isExist(id);
        if(index != -1) //Ա�����ڣ������޸�
        {
            //���ͷŵ����λ���ϵ�����
            delete this->m_EmpArray[index];

            int new_id = 0;
            string new_name = " ";
            int new_dId = 0;

            cout << "�鵽���Ϊ: " << id << "��ְ�����������µ�ְ�����" << endl;
            cin >> new_id;
            cout << "������������" << endl;
            cin >> new_name;
            cout << "�������λ" << endl;
            cout << "1����ְͨ�� 2������ 3���ϰ�" << endl;
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

            cout << "�޸ĳɹ�" << endl;
        }
        else
        {
            cout << "δ�ҵ���ְ�����޸�ʧ��" << endl;
        }
    }
    system("pause");
    system("cls");
}

void WorkerManager::searchEmp() {
    if(this->m_FileIsEmpty == true)
    {
        cout << "�ļ�Ϊ�գ�û��Ա��" << endl;
    }
    else
    {
        cout << "������Ҫ����Ա���ķ�ʽ 1����Ų��� 2����������" << endl;
        int waySelect = 0;

        bool waySelectFlag = true;
        while(waySelectFlag)
        {
            cin >> waySelect;
            if(waySelect == 1)  //��Ų���
            {
                waySelectFlag = false;

                cout << "������Ҫ���ҵ�ְ���ı��" << endl;
                int id_input;
                cin >> id_input;
                int id_index = this->isExist(id_input);
                if(id_index != -1) //�ҵ���
                {
                    this->m_EmpArray[id_index]->showInfo();
                }
                else
                {
                    cout << "δ�ҵ���������ְ��" << endl;
                }
            }
            else if(waySelect == 2)  //��������
            {
                waySelectFlag = false;

                cout << "������Ҫ���ҵ�ְ��������" << endl;
                string name_input;
                cin >> name_input;
                int indexByName = this->isExistByName(name_input);
                if( indexByName != -1)
                {
                    this->m_EmpArray[indexByName]->showInfo();
                }
                else
                {
                    cout << "δ�ҵ���������ְ��" << endl;
                }
            }
            else
            {
                cout << "��ʽѡ���������������" << endl;
                waySelectFlag = true;
            }
        }
    }
    system("pause");
    system("cls");
}

//ʹ��ѡ�������㷨����Ա���Ľ��б������
void WorkerManager::sortEmp() {
    if(this->m_FileIsEmpty == true)
    {
        cout << "�ļ������ڣ�û��Ա��" << endl;
        system("pause");
        system("cls");
    }
    else
    {
        cout << "��ѡ��������� 1������ 2������" << endl;
        int sortSelect = 0;
        bool sortSelectFLAG = true;
        while(sortSelectFLAG)
        {
            cin >> sortSelect;
            if(sortSelect == 1 || sortSelect ==2)
            {
                sortSelectFLAG = false;

                //ѡ�������㷨
                for (int i = 0; i < this->m_EmpNum; ++i)
                {
                    int minOrMax = i;
                    for (int j = i+1; j < this->m_EmpNum; ++j) {
                        if(sortSelect == 1) //����
                        {
                            if(this->m_EmpArray[minOrMax]->m_ID > this->m_EmpArray[j]->m_ID)
                            {
                                minOrMax = j;
                            }
                        }
                        if(sortSelect == 2) //����
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
                cout << "��������������ѡ��" << endl;
                sortSelectFLAG = true;
            }
        }
        cout << "����ɹ��������Ľ��Ϊ" << endl;
        this->save();
        this->showEmp();
    }
}

void WorkerManager::clearFile() {

    cout << "ȷ�����? 1��ȷ�� 2������" << endl;

    int inputSelect = 0;
    bool inputSelectFLAG = true;

    while(inputSelectFLAG)
    {
        cin >> inputSelect;
        if(inputSelect == 1 || inputSelect ==2)
        {
            inputSelectFLAG = false;
            if(inputSelect == 1) {
                //��ģʽΪios::trunc��������ڣ�ɾ���ļ������´���
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

                cout << "����ɹ�" << endl;
            }
        }
        else
        {
            cout << "������������������" << endl;
            inputSelectFLAG = true;
        }
    }

    system("pause");
    system("cls");
}
