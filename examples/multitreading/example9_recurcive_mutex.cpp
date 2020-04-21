/*****************************************************************//**
 * \file   CppLearn.cpp
 * \brief  multithreading 9 example (with recursuve_mutex)
 * 
 * \author BAHOO
 * \date   April 2020
***********************************************************************/

#include <iostream>

#include <thread>
#include <chrono>
#include <mutex>

std::recursive_mutex rm;

void RecursiveFnct(int a)
{
    rm.lock();
    std::cout << a << " ";
    std::this_thread::sleep_for(std::chrono::milliseconds(100));

    if (a <= 1)
    {
        std::cout << std::endl;
        rm.unlock();
        return;
    } 

    --a;
    RecursiveFnct(a);

    rm.unlock();

}

int main() 
{

    std::thread t(RecursiveFnct, 10);
    std::thread t2(RecursiveFnct, 10);
  /*  for (size_t i = 0; i < 20; ++i)
    {
        std::cout << "ID thread = " << std::this_thread::get_id() << "\tMainThread\t"<< std::endl;
        // Emulating dificult process
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }*/

    t.join();
    t2.join();
}