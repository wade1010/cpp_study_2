#include <iostream>
#include <chrono>
#include <iomanip> //put_time()������Ҫ������ͷ�ļ�
#include <sstream>
using namespace std;

void test()
{
    // 1 ��̬��Ա����chrono::system_clock::now()���ڻ�ȡϵͳʱ�� (C++ʱ��)
    // chrono::time_point<chrono::system_clock> now = chrono::system_clock::now();
    auto now = chrono::system_clock::now();

    // 2 ��̬��Ա����chrono::system_clock::to_time_t()��ϵͳʱ��ת��Ϊtime_t.(UTCʱ��)
    // time_t t_now = chrono::system_clock::to_time_t(now);
    auto t_now = chrono::system_clock::to_time_t(now);

    // 3 std::localtime()������time_tת���ɱ���ʱ�� (����ʱ��)
    // localtime()�����̰߳�ȫ��,VS��localtime_s����,Linux��localtime_r����//vscode g++ ����û������
    // tm *tm_now = std::localtime(&t_now);
    auto *tm_now = std::localtime(&t_now);

    // 4 ��ʽ�����tm�ṹ���еĳ�Ա
    cout << put_time(tm_now, "%Y-%m-%d %H:%M:%S") << endl;
    cout << put_time(tm_now, "%Y-%m-%d") << endl;
    cout << put_time(tm_now, "%H:%M:%S") << endl;
    cout << put_time(tm_now, "%Y%m%d%H%M%S") << endl;

    stringstream ss; //����stringstream����ss,��Ҫ����ͷ�ļ� <sstream>
    ss << put_time(tm_now, "%Y-%m-%d %H:%M:%S");
    string time_str = ss.str();
    cout << time_str << endl;

    //ʱ��ƫ��
    t_now += 24 * 3600;

    auto *tm_now2 = std::localtime(&t_now);
    cout << "ƫ�ƺ�:" << put_time(tm_now2, "%Y-%m-%d %H:%M:%S") << endl;
}
int main()
{
    test();
    return 0;
}
/* 2022-12-01 19:36:19
2022-12-01
19:36:19
20221201193619
2022-12-01 19:36:19
ƫ�ƺ�:2022-12-02 19:36:19 */