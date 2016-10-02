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

    void Print(double value)
    {
        if (ShowProgress)
        {
            printf("\rProgress: %.2f%c", value, '%');
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
