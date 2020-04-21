/*****************************************************************//**
 * \file   CppLearn.cpp
 * \brief  multithreading 5 example (with lambda fnct)
 * 
 * \author BAHOO
 * \date   April 2020
***********************************************************************/

#include <iostream>

#include <thread>
#include <chrono>


class Example
{
public:
    void DoWork2(int a)
    {
        std::cout << "ID thread = " << std::this_thread::get_id() << "\tDoWotk2 start\t" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(3000));
        std::cout << "ID thread = " << std::this_thread::get_id() << "\tDoWotk2 end\t" << std::endl;
        // Emulating dificult process
        a += 10;
        std::cout << "a = " << 10 << std::endl;
    }

    void DoWork()
    {
        std::cout << "ID thread = " << std::this_thread::get_id() << "\tDoWotk start\t" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(4000));
        std::cout << "ID thread = " << std::this_thread::get_id() << "\tDoWotk end\t" << std::endl;
    }
    int Sum(int a, int b)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        std::cout << "ID thread = " << std::this_thread::get_id() << "\tSum start\t" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(4000));
        std::cout << "ID thread = " << std::this_thread::get_id() << "\tSum end\t" << std::endl;
        return a + b;
    }
};


int main() 
{
    int result = 0;
    Example example;

    std::thread th([&]()
    {
        result = example.Sum(2, 5);
    }); // create thread*/
   // th.detach();            // Do this thread while main thread in action(when main thread  will end, this end will finish)
    
    /* First variant
    std::thread th2([&]()
    {
        example.DoWork();
    });
    */

    // Second Variant
    std::thread th2(&Example::DoWork, example);

    std::thread th3(&Example::DoWork2, example, 5);

    for (size_t i = 0; i < 20; ++i)
    {
        std::cout << "ID thread = " << std::this_thread::get_id() << "\tMainThread\t"<< std::endl;
        // Emulating dificult process
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }

    th.join();  // for  paralell
    th2.join();
    th3.join();
    std::cout << result;
}
