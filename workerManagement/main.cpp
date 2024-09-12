#include <iostream>
#include <string>
#include "inc/workerManagement.h"

//#include "inc/worker.h"
//#include "inc/employee.h"
//#include "inc/manager.h"
//#include "inc/boss.h"

using namespace std;

int main() {

    WorkerManager wm;
    int select = -1;

    while(true)
    {
        wm.showMenu();
        cout << "请输入您的选择" << endl;
        cin >> select;
        switch (select) {
            case 0: //退出系统
                wm.exitSystem();
                break;
            case 1: //增加职工信息
                wm.addEmp();
                break;
            case 2: //显示职工信息
                wm.showEmp();
                break;
            case 3: //删除离职职工
                wm.deleteEmp();
                break;
            case 4: //修改职工信息
                wm.modifyEmp();
                break;
            case 5: //查找职工信息
                wm.searchEmp();
                break;
            case 6: //按照编号排序
                wm.sortEmp();
                break;
            case 7: //清空所有文档
                wm.clearFile();
                break;
            default:
                system("cls");
                break;
        }
    }

    system("pause");
    return 0;
}
