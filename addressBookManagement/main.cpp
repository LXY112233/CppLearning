#include <iostream>
#include <string>
#define MAX 1000
using namespace std;

struct Person
{
    string m_Name;
    int m_Sex;      //1男 2女
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
    cout << "***** 1、添加联系人 *****" << endl;
    cout << "***** 2、显示联系人 *****" << endl;
    cout << "***** 3、删除联系人 *****" << endl;
    cout << "***** 4、查找联系人 *****" << endl;
    cout << "***** 5、修改联系人 *****" << endl;
    cout << "***** 6、清空联系人 *****" << endl;
    cout << "***** 0、退出通讯录 *****" << endl;
    cout << "*************************" << endl;
}

void addPerson(Addressbooks *abs)
{
    //人数满了
    if(abs->m_Size == MAX)
    {
        cout << "通讯录已满，无法添加" << endl;
        return;
    }
    //人数没满
    else
    {
        string name;
        cout << "请输入姓名" << endl;
        cin >> name;
        abs->personArray[abs->m_Size].m_Name = name;

        cout << "请输入性别 1男 2女" << endl;
        int sex;
        sex_select_FLAG:
        cin >> sex;
        if(sex == 1 || sex ==2)
        {
            abs->personArray[abs->m_Size].m_Sex = sex;
        }
        else
        {
            cout << "输入有误，请重新输入" << endl;
            goto sex_select_FLAG;
        }

        cout << "请输入年龄" << endl;
        int age = 0;
        cin >> age;
        abs->personArray[abs->m_Size].m_Age = age;

        cout << "请输入电话" << endl;
        string phone;
        cin >> phone;
        abs->personArray[abs->m_Size].m_Phone = phone;

        cout << "请输入住址" << endl;
        string addr;
        cin >> addr;
        abs->personArray[abs->m_Size].m_Addr = addr;

        abs->m_Size++;
        cout << "添加成功" << endl;
    }
    system("pause");
    system("cls");
}

void showPerson(Addressbooks *abs)
{
    if(abs->m_Size == 0)
    {
        cout << "当前通讯录中无联系人" << endl;
    }
    else
    {
        for (int i = 0; i < abs->m_Size; ++i) {
            cout << "姓名：" << abs->personArray[i].m_Name << "\t";
            cout << "性别：" << (abs->personArray[i].m_Sex==1 ? "男" : "女") << "\t";
            cout << "年龄：" << abs->personArray[i].m_Age << "\t";
            cout << "电话：" << abs->personArray[i].m_Phone << "\t";
            cout << "地址：" << abs->personArray[i].m_Addr << "\n";
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
    cout << "请输入要删除的联系人的姓名" << endl;
    string name;
    cin >> name;

    int person_index;
    person_index = isExist(abs, name);

    if(person_index == -1)
    {
        cout << "查无此人" << endl;
        system("pause");
        system("cls");
    }
    else
    {
        cout << "查到此人，是否确定删除 1确定 2取消" << endl;
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
            cout << "删除成功" << endl;
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
    cout << "姓名：" << abs->personArray[person_index].m_Name << "\t";
    cout << "性别：" << (abs->personArray[person_index].m_Sex==1 ? "男" : "女") << "\t";
    cout << "年龄：" << abs->personArray[person_index].m_Age << "\t";
    cout << "电话：" << abs->personArray[person_index].m_Phone << "\t";
    cout << "地址：" << abs->personArray[person_index].m_Addr << "\n";
}

void searchPerson(Addressbooks *abs)
{
    cout << "请输入要查找的联系人的姓名" << endl;
    string name;
    cin >> name;

    int search_index;
    search_index = isExist(abs, name);
    if(search_index == -1)
    {
        cout << "查无此人" << endl;
        system("pause");
        system("cls");
    }
    else
    {
        cout << "查到此人" << endl;
        printPerson(abs,search_index);
        system("pause");
        system("cls");
    }
}

void modifyPerson(Addressbooks *abs)
{
    cout << "请输入要修改的联系人的姓名" << endl;
    string input_name;
    cin >> input_name;
    int name_index = -1;
    name_index = isExist(abs,input_name);
    if(name_index == -1)
    {
        cout << "查无此人" << endl;
        system("pause");
        system("cls");
    }
    else
    {
        cout << "查到此人" << endl;
        printPerson(abs, name_index);

        string name;
        cout << "请输入姓名" << endl;
        cin >> name;
        abs->personArray[name_index].m_Name = name;

        cout << "请输入性别 1男 2女" << endl;
        int sex;
        sex_select_FLAG_modify:
        cin >> sex;
        if(sex == 1 || sex ==2)
        {
            abs->personArray[name_index].m_Sex = sex;
        }
        else
        {
            cout << "输入有误，请重新输入" << endl;
            goto sex_select_FLAG_modify;
        }

        cout << "请输入年龄" << endl;
        int age = 0;
        cin >> age;
        abs->personArray[name_index].m_Age = age;

        cout << "请输入电话" << endl;
        string phone;
        cin >> phone;
        abs->personArray[name_index].m_Phone = phone;

        cout << "请输入住址" << endl;
        string addr;
        cin >> addr;
        abs->personArray[name_index].m_Addr = addr;

        cout << "修改成功" << endl;
        system("pause");
        system("cls");
    }
}

void clearPerson(Addressbooks *abs)
{
    cout << "请确认是否要清空联系人 1确定 2取消" << endl;
    int input_select;
    int input_flag = 1;
    while(input_flag)
    {
        cin >> input_select;
        if(input_select == 1)
        {
            input_flag = 0;
            abs->m_Size = 0;
            cout << "清除成功" << endl;
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
            cout << "输入有误 请重新输入" << endl;
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
                cout << "欢迎下次使用" << endl;
                system("pause");
                return 0;
            default:
                break;
        }
    }
}
