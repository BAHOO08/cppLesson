/*****************************************************************//**
 * \file   CppLearn.cpp
 * \brief  multithreading 9 example (with unique_lock)
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


    std::unique_lock<std::mutex> ul(mtx,std::defer_lock); // param std::defer_lock make ul in unlock state after creating ul
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));

    ul.lock();
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

    ul.unlock();

    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    /*
    unique_lock distructor  call unlock()
    */
}
int main() 
{

    std::thread t(Print, '#');
    std::thread t2(Print, '*');
  /*  for (size_t i = 0; i < 20; ++i)
    {
        std::cout << "ID thread = " << std::this_thread::get_id() << "\tMainThread\t"<< std::endl;
        // Emulating dificult process
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }*/

    t.join();
    t2.join();
}