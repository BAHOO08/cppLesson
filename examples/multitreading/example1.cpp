/*****************************************************************//**
 * \file   CppLearn.cpp
 * \brief  multithreading 1 example
 * 
 * \author BAHOO
 * \date   April 2020
***********************************************************************/

#include <iostream>

#include <thread>
#include <chrono>



void DoWork()
{
    for (size_t i = 0; i < 10; ++i)
    {
        std::cout << "ID thread = " << std::this_thread::get_id() << "\tDoWotk\t" << i << std::endl;
        // Emulating dificult process
        std::this_thread::sleep_for(std::chrono::milliseconds(1000)); 
    }
}
int main() 
{
    std::thread th(DoWork); // create thread
   // th.detach();            // Do this thread while main thread in action(when main thread  will end, this end will finish)
    

    for (size_t i = 0; i < 10; ++i)
    {
        std::cout << "ID thread = " << std::this_thread::get_id() << "\tMainThread\t" << i << std::endl;
        // Emulating dificult process
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }


    th.join();  // for  paralell
    std::cout << "Hello World!\n";
}
