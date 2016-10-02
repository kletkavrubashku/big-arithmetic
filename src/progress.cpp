#include "progress.h"

#include <stdio.h>

bool ShowProgress = true;

namespace Progress
{
    void Init()
    {
        if (ShowProgress)
        {
            setbuf(stdout, NULL);
        }
    }

    void Print(double value, double max)
    {
        if (ShowProgress)
        {
            printf("\rProgress: %.2f%c", 100 * (double)value/max, '%');
        }
    }

    void Deinit()
    {
        if (ShowProgress)
        {
            printf("\n");
            setbuf(stdin, new(char[BUFSIZ]));
        }
    }

    void SetEnable(bool value)
    {
        ShowProgress = value;
    }
}
