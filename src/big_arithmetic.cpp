#include "big_arithmetic.h"

namespace BigArithmetic
{
    UInteger::UInteger(unsigned int a)
    {
        while(a > 0)
        {
            Value.push_back(static_cast<uint8_t>(a % 10));
            a /= 10;
        }
    }

    UInteger operator+(const UInteger& a, const UInteger& b)
    {
        UInteger result = 0;
        result.Value.resize(std::max(a.Value.size(), b.Value.size()), 0);
        for(int aI = 0; aI < a.Value.size(); ++aI)
        {
            result.Value[aI] += a.Value[aI];
        }
        for(int bI = 0; bI < b.Value.size(); ++bI)
        {
            result.Value[bI] += b.Value[bI];
        }


        for (int rI = 0; rI < result.Value.size(); ++rI)
        {
            const uint8_t digit = result.Value[rI] % 10;
            const uint8_t excess = result.Value[rI] / 10;
            result.Value[rI] = digit;
            if (excess > 0)
            {
                if (result.Value.size() <= rI + 1)
                {
                    result.Value.push_back(0);
                }
                result.Value[rI + 1] += excess;
            }
        }
        return result;
    }

    UInteger operator*(const UInteger& a, const UInteger& b)
    {
        auto addToPos = [](UInteger& uInt, int pos, uint8_t a)
        {
            while (uInt.Value.size() <= pos)
            {
                uInt.Value.push_back(0);
            }
            uInt.Value[pos] += a;
            const uint8_t excess = uInt.Value[pos] / 10;
            uInt.Value[pos] %= 10;
            return excess;
        };

        UInteger result = 0;

        const uint8_t x = 5;
        for(int aI = 0; aI < a.Value.size(); ++aI)
        {
            for(int bI = 0; bI < b.Value.size(); ++bI)
            {
                auto resElem = a.Value[aI] * b.Value[bI];
                auto resI = aI + bI;
                while(resElem = addToPos(result, resI++, resElem));
            }
        }

        return result;
    }

    std::ostream& operator<<(std::ostream& out, const UInteger& a)
    {
        for(auto it = a.Value.rbegin(); it != a.Value.rend(); ++it)
        {
            out << std::to_string(*it);
        }
        return out;
    }
}
