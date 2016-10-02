#include "big_arithmetic.h"
#include "elapsed_time.h"
#include "progress.h"

#include <fstream>
#include <iostream>

BigArithmetic::UInteger Fibonacci(int n)
{
    BigArithmetic::UInteger a1 = 1;
    BigArithmetic::UInteger a2 = 1;
    for (int i = 3; i <= n; ++i)
    {
        const BigArithmetic::UInteger& next = a1 + a2;
        a1 = a2;
        a2 = next;
        
        Progress::Print(i, n);
    }
    return a2;
}

int main() {
    int number;
    std::cout << "Input: ";
    std::cin >> number;

    Timer t;

    Progress::SetEnable(true);
    Progress::Init();
    const BigArithmetic::UInteger& result = Fibonacci(number);
    Progress::Deinit();

    std::cout
        << "Result: " << result << std::endl
        << "Elapsed time: " << t.ElapsedTime() << "sec" << std::endl;

    std::ofstream file;
    file.open("output");
    file << result;
    file.close();
    return 0;
}