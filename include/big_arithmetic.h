#pragma once

#include <vector>
#include <stdint.h>
#include <ostream>

namespace BigArithmetic
{
    class UInteger
    {
    public:
        UInteger(unsigned int a);

    private:
        typedef std::vector<uint8_t> Type;
        Type Value;

        friend UInteger operator+(const UInteger&, const UInteger&);
        friend UInteger operator*(const UInteger&, const UInteger&);
        friend std::ostream& operator<<(std::ostream&, const UInteger&);
    };

    UInteger operator+(const UInteger& a, const UInteger& b);
    UInteger operator*(const UInteger& a, const UInteger& b);
    std::ostream& operator<<(std::ostream& out, const UInteger& a);
}