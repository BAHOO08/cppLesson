/*****************************************************************//**
 * \file   CppLearn.cpp
 * \brief  multithreading 7 example (with lock_guard)
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
    std::lock_guard<std::mutex> guard(mtx);

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
}



int main() 
{

    std::thread t1(Print, '*');
    std::thread t2(Print, '#');

  /*  for (size_t i = 0; i < 20; ++i)
    {
        std::cout << "ID thread = " << std::this_thread::get_id() << "\tMainThread\t"<< std::endl;
        // Emulating dificult process
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }*/

    t1.join();
    t2.join();

}