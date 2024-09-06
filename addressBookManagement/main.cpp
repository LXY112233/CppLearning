#include <iostream>
#include <string>
#define MAX 1000
using namespace std;

struct Person
{
    string m_Name;
    int m_Sex;      //1�� 2Ů
    int m_Age;
    string m_Phone;
    string m_Addr;
};

struct Addressbooks
{
    struct Person personArray[MAX];
    int m_Size;
};

void showMenu()
{
    cout << "*************************" << endl;
    cout << "***** 1�������ϵ�� *****" << endl;
    cout << "***** 2����ʾ��ϵ�� *****" << endl;
    cout << "***** 3��ɾ����ϵ�� *****" << endl;
    cout << "***** 4��������ϵ�� *****" << endl;
    cout << "***** 5���޸���ϵ�� *****" << endl;
    cout << "***** 6�������ϵ�� *****" << endl;
    cout << "***** 0���˳�ͨѶ¼ *****" << endl;
    cout << "*************************" << endl;
}

void addPerson(Addressbooks *abs)
{
    //��������
    if(abs->m_Size == MAX)
    {
        cout << "ͨѶ¼�������޷����" << endl;
        return;
    }
    //����û��
    else
    {
        string name;
        cout << "����������" << endl;
        cin >> name;
        abs->personArray[abs->m_Size].m_Name = name;

        cout << "�������Ա� 1�� 2Ů" << endl;
        int sex;
        sex_select_FLAG:
        cin >> sex;
        if(sex == 1 || sex ==2)
        {
            abs->personArray[abs->m_Size].m_Sex = sex;
        }
        else
        {
            cout << "������������������" << endl;
            goto sex_select_FLAG;
        }

        cout << "����������" << endl;
        int age = 0;
        cin >> age;
        abs->personArray[abs->m_Size].m_Age = age;

        cout << "������绰" << endl;
        string phone;
        cin >> phone;
        abs->personArray[abs->m_Size].m_Phone = phone;

        cout << "������סַ" << endl;
        string addr;
        cin >> addr;
        abs->personArray[abs->m_Size].m_Addr = addr;

        abs->m_Size++;
        cout << "��ӳɹ�" << endl;
    }
    system("pause");
    system("cls");
}

void showPerson(Addressbooks *abs)
{
    if(abs->m_Size == 0)
    {
        cout << "��ǰͨѶ¼������ϵ��" << endl;
    }
    else
    {
        for (int i = 0; i < abs->m_Size; ++i) {
            cout << "������" << abs->personArray[i].m_Name << "\t";
            cout << "�Ա�" << (abs->personArray[i].m_Sex==1 ? "��" : "Ů") << "\t";
            cout << "���䣺" << abs->personArray[i].m_Age << "\t";
            cout << "�绰��" << abs->personArray[i].m_Phone << "\t";
            cout << "��ַ��" << abs->personArray[i].m_Addr << "\n";
        }
    }
    system("pause");
    system("cls");
}

int isExist(Addressbooks *abs, string name)
{
    for (int i = 0; i < abs->m_Size; ++i) {
        if(abs->personArray[i].m_Name == name)
        {
            return i;
        }
    }
    return -1;
}

void deletePerson(Addressbooks *abs)
{
    cout << "������Ҫɾ������ϵ�˵�����" << endl;
    string name;
    cin >> name;

    int person_index;
    person_index = isExist(abs, name);

    if(person_index == -1)
    {
        cout << "���޴���" << endl;
        system("pause");
        system("cls");
    }
    else
    {
        cout << "�鵽���ˣ��Ƿ�ȷ��ɾ�� 1ȷ�� 2ȡ��" << endl;
        int select = 0;
        cin >> select;
        if(select == 1)
        {
            for (int i = person_index; i < abs->m_Size; ++i) {
                abs->personArray[i].m_Name = abs->personArray[i+1].m_Name;
                abs->personArray[i].m_Sex = abs->personArray[i+1].m_Sex;
                abs->personArray[i].m_Age = abs->personArray[i+1].m_Age;
                abs->personArray[i].m_Phone = abs->personArray[i+1].m_Phone;
                abs->personArray[i].m_Addr = abs->personArray[i+1].m_Addr;
            }
            abs->m_Size--;
            cout << "ɾ���ɹ�" << endl;
            system("pause");
            system("cls");
        }
        else
        {
            system("pause");
            system("cls");
        }
    }
}

void printPerson(Addressbooks *abs, int person_index)
{
    cout << "������" << abs->personArray[person_index].m_Name << "\t";
    cout << "�Ա�" << (abs->personArray[person_index].m_Sex==1 ? "��" : "Ů") << "\t";
    cout << "���䣺" << abs->personArray[person_index].m_Age << "\t";
    cout << "�绰��" << abs->personArray[person_index].m_Phone << "\t";
    cout << "��ַ��" << abs->personArray[person_index].m_Addr << "\n";
}

void searchPerson(Addressbooks *abs)
{
    cout << "������Ҫ���ҵ���ϵ�˵�����" << endl;
    string name;
    cin >> name;

    int search_index;
    search_index = isExist(abs, name);
    if(search_index == -1)
    {
        cout << "���޴���" << endl;
        system("pause");
        system("cls");
    }
    else
    {
        cout << "�鵽����" << endl;
        printPerson(abs,search_index);
        system("pause");
        system("cls");
    }
}

void modifyPerson(Addressbooks *abs)
{
    cout << "������Ҫ�޸ĵ���ϵ�˵�����" << endl;
    string input_name;
    cin >> input_name;
    int name_index = -1;
    name_index = isExist(abs,input_name);
    if(name_index == -1)
    {
        cout << "���޴���" << endl;
        system("pause");
        system("cls");
    }
    else
    {
        cout << "�鵽����" << endl;
        printPerson(abs, name_index);

        string name;
        cout << "����������" << endl;
        cin >> name;
        abs->personArray[name_index].m_Name = name;

        cout << "�������Ա� 1�� 2Ů" << endl;
        int sex;
        sex_select_FLAG_modify:
        cin >> sex;
        if(sex == 1 || sex ==2)
        {
            abs->personArray[name_index].m_Sex = sex;
        }
        else
        {
            cout << "������������������" << endl;
            goto sex_select_FLAG_modify;
        }

        cout << "����������" << endl;
        int age = 0;
        cin >> age;
        abs->personArray[name_index].m_Age = age;

        cout << "������绰" << endl;
        string phone;
        cin >> phone;
        abs->personArray[name_index].m_Phone = phone;

        cout << "������סַ" << endl;
        string addr;
        cin >> addr;
        abs->personArray[name_index].m_Addr = addr;

        cout << "�޸ĳɹ�" << endl;
        system("pause");
        system("cls");
    }
}

void clearPerson(Addressbooks *abs)
{
    cout << "��ȷ���Ƿ�Ҫ�����ϵ�� 1ȷ�� 2ȡ��" << endl;
    int input_select;
    int input_flag = 1;
    while(input_flag)
    {
        cin >> input_select;
        if(input_select == 1)
        {
            input_flag = 0;
            abs->m_Size = 0;
            cout << "����ɹ�" << endl;
            system("pause");
            system("cls");
        }
        else if(input_select == 2)
        {
            input_flag = 0;
            system("pause");
            system("cls");
        }
        else
        {
            cout << "�������� ����������" << endl;
            input_select = 1;
            system("pause");
            system("cls");
        }
    }
}

int main() {

    Addressbooks abs;
    abs.m_Size = 0;

    int select = 0;

    while(true)
    {
        showMenu();
        cin >> select;
        switch (select) {
            case 1:
                addPerson(&abs);
                break;
            case 2:
                showPerson(&abs);
                break;
            case 3:
                deletePerson(&abs);
                break;
            case 4:
                searchPerson(&abs);
                break;
            case 5:
                modifyPerson(&abs);
                break;
            case 6:
                clearPerson(&abs);
                break;
            case 0:
                cout << "��ӭ�´�ʹ��" << endl;
                system("pause");
                return 0;
            default:
                break;
        }
    }
}
