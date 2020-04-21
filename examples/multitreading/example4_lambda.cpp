/*****************************************************************//**
 * \file   CppLearn.cpp
 * \brief  multithreading 4 example (with lambda fnct)
 * 
 * \author BAHOO
 * \date   April 2020
***********************************************************************/

#include <iostream>

#include <thread>
#include <chrono>



int DoWork(int a)
{

        std::this_thread::sleep_for(std::chrono::milliseconds(3000));
        std::cout << "ID thread = " << std::this_thread::get_id() << "\tDoWotk\t" << std::endl;
        // Emulating dificult process
        a += 10;
        return a;
}

int main() 
{
    int data = 0;
    std::thread th([&data]()
    {
        data = DoWork(5);
    }); // create thread
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
