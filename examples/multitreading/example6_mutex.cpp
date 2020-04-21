/*****************************************************************//**
 * \file   CppLearn.cpp
 * \brief  multithreading 6 example (with mutex)
 * 
 * \author BAHOO
 * \date   April 2020
***********************************************************************/

#include <iostream>

#include <thread>
#include <chrono>
#include <mutex>

std::mutex mtx;

void Print(char ch)
{
    mtx.lock();
    for (size_t i = 0; i < 5; ++i)
    {
        for (size_t j = 0; j < 10; ++j)
        {
            std::cout << ch;
            std::this_thread::sleep_for(std::chrono::milliseconds(20));
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;
    mtx.unlock();
}



int main() 
{

    Print('*');
    Print('#');
    std::thread t1(Print, '*');
    std::thread t2(Print, '#');

    for (size_t i = 0; i < 20; ++i)
    {
        std::cout << "ID thread = " << std::this_thread::get_id() << "\tMainThread\t"<< std::endl;
        // Emulating dificult process
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }

    t1.join();
    t2.join();

}