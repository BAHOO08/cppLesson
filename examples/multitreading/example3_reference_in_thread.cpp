/*****************************************************************//**
 * \file   CppLearn.cpp
 * \brief  multithreading 3 example (return result by reference from threading)
 * 
 * \author BAHOO
 * \date   April 2020
***********************************************************************/

#include <iostream>

#include <thread>
#include <chrono>



void DoWork(int &a)
{
    while (true)
    {
        std::cout << "ID thread = " << std::this_thread::get_id() << "\tDoWotk\t" << std::endl;
        // Emulating dificult process
        a += 1;
        std::this_thread::sleep_for(std::chrono::milliseconds(3000));
    }
}
int main() 
{
    int data = 0;
    std::thread th(DoWork, std::ref(data)); // create thread
   // th.detach();            // Do this thread while main thread in action(when main thread  will end, this end will finish)
    

    for (size_t i = 0; true; ++i)
    {
        std::cout << "ID thread = " << std::this_thread::get_id() << "\tMainThread\t" << data << std::endl;
        // Emulating dificult process
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }


    th.join();  // for  paralell
    std::cout << "Hello World!\n";
}
