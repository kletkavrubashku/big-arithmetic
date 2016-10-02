#include "big_arithmetic.h"
#include "elapsed_time.h"
#include "progress.h"

#include <fstream>
#include <iostream>

BigArithmetic::UInteger Factorial(int n)
{
    BigArithmetic::UInteger result(1);
    for (int i = 2; i <= n; ++i)
    {
        result = result * i;
        Progress::Print(100 * (double)i/n);
    }
    return result;
}

int main() {
    int number;
    std::cout << "Input: ";
    std::cin >> number;

    Timer t;

    Progress::SetEnable(true);
    Progress::Init();
    const BigArithmetic::UInteger& result = Factorial(number);
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