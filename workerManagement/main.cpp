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
        cout << "����������ѡ��" << endl;
        cin >> select;
        switch (select) {
            case 0: //�˳�ϵͳ
                wm.exitSystem();
                break;
            case 1: //����ְ����Ϣ
                wm.addEmp();
                break;
            case 2: //��ʾְ����Ϣ
                wm.showEmp();
                break;
            case 3: //ɾ����ְְ��
                wm.deleteEmp();
                break;
            case 4: //�޸�ְ����Ϣ
                wm.modifyEmp();
                break;
            case 5: //����ְ����Ϣ
                wm.searchEmp();
                break;
            case 6: //���ձ������
                wm.sortEmp();
                break;
            case 7: //��������ĵ�
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
