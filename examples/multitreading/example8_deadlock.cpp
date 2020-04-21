/*****************************************************************//**
 * \file   CppLearn.cpp
 * \brief  multithreading 8 example (with deadlock)
 * 
 * \author BAHOO
 * \date   April 2020
***********************************************************************/

#include <iostream>

#include <thread>
#include <chrono>
#include <mutex>

std::mutex mtx1;
std::mutex mtx2;

#define MUTEX_DEADLOCK 0

void Print(char ch)
{
#if MUTEX_DEADLOCK == 1
    mtx2.lock();
    std::this_thread::sleep_for(std::chrono::milliseconds(1));
    mtx1.lock();
#else
    mtx1.lock();
    std::this_thread::sleep_for(std::chrono::milliseconds(1));
    mtx2.lock();
#endif // MUTEX_DEADLOCK


    


    for (size_t i = 0; i < 5; ++i)
    {
        for (size_t j = 0; j < 10; ++j)
        {
            std::cout << ch;
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;

    mtx1.unlock();
    mtx2.unlock();
}

void Print2(char ch)
{
    mtx1.lock();

    std::this_thread::sleep_for(std::chrono::milliseconds(1));

    mtx2.lock();

    for (size_t i = 0; i < 5; ++i)
    {
        for (size_t j = 0; j < 10; ++j)
        {
            std::cout << ch;
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;

    mtx2.unlock();
    mtx1.unlock();
}

int main() 
{

    std::thread t1(Print, '*');
    std::thread t2(Print2, '#');

  /*  for (size_t i = 0; i < 20; ++i)
    {
        std::cout << "ID thread = " << std::this_thread::get_id() << "\tMainThread\t"<< std::endl;
        // Emulating dificult process
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }*/

    t1.join();
    t2.join();

}