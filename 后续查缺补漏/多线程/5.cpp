#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
using namespace std;

mutex m;

std::unique_lock<std::mutex> get_unique_lock()
{
    std::unique_lock<std::mutex> tmp(m);
    return tmp; // 从函数返回一个局部的unique_lock对象时可以的.返回这种局部对象tmp会导致系统生成临时unique_lock对象,并调用unique_lock的移动构造函数
}

void myprint(int num)
{
    std::unique_lock<std::mutex> g(m);
    std::mutex *pmtx = g.release(); // release后,需要我们自己解锁这个m
    cout << "myprint,id:" << this_thread::get_id() << endl;
    pmtx->unlock(); // 自己解锁
    delete pmtx;
    pmtx = nullptr;
}

int main()
{
    // 创建和等待多个线程
    vector<thread> mythreads;
    // 创建10个线程,线程入口函数统一为myprint

    for (size_t i = 0; i < 10; i++)
    {
        mythreads.push_back(thread(myprint, i));
    }

    for (auto &th : mythreads)
    {
        th.join();
    }

    cout << "end main" << endl;
    return 0;
}