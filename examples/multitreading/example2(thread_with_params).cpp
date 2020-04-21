/*****************************************************************//**
 * \file   CppLearn.cpp
 * \brief  multithreading 2 example (multitrheading with params)
 * 
 * \author BAHOO
 * \date   April 2020
***********************************************************************/

#include <iostream>

#include <thread>
#include <chrono>



void DoWork(int a, int b)
{
    while (true)
    {
        std::cout << "ID thread = " << std::this_thread::get_id() << "\tDoWotk\t" << (a + b) << std::endl;
        // Emulating dificult process
        std::this_thread::sleep_for(std::chrono::milliseconds(3000));
    }
}
int main() 
{
    std::thread th(DoWork,1,2); // create thread
   // th.detach();            // Do this thread while main thread in action(when main thread  will end, this end will finish)
    

    for (size_t i = 0; true; ++i)
    {
        std::cout << "ID thread = " << std::this_thread::get_id() << "\tMainThread\t" << i << std::endl;
        // Emulating dificult process
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }


    th.join();  // for  paralell
    std::cout << "Hello World!\n";
}
