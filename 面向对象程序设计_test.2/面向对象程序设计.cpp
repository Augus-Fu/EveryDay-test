#include <iostream>
using namespace std;

/* ����������д�� */
/*
1. ����һ��Car��;
2. ����public��Ա����:
(1) disp_welcomemsg()���޷�������;
(2) get_wheels()������һ��Car������ݳ�Աm_nWheels��ֵ��
(3) set_wheels(int)����ָ�����βγ�ʼ�����ݳ�Աm_nWheels��ֵ��
3. һ��˽�����ݳ�Աm_nWheels���������ͣ����������ĳ���������
*/
class Car
{
private:
    int m_nWhilees;
public:
    void disp_welcomemsg() { cout << "Welcome to the car world!" << endl; };
    int get_wheels() { return m_nWhilees; };
    void set_wheels(int i) { m_nWhilees = i; };
};

int main()
{
    int n;
    cin >> n;
    Car myfstcar, myseccar;    //���������
    myfstcar.disp_welcomemsg();//���ʳ�Ա��������ʾ��ӭ��Ϣ
    myfstcar.set_wheels(n);    //���ʳ�Ա���������ó�������
    myseccar.set_wheels(n + 4);  //���ʳ�Ա���������ó�������
    //���ʳ�Ա��������ʾ��������
    cout << "my first car wheels num = " << myfstcar.get_wheels() << endl;
    cout << "my second car wheels num = " << myseccar.get_wheels() << endl;

    return 0;
}
