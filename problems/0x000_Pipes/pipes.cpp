#include <stdio.h>

int main() 
{
    char buf[100];
    int i = 0;
    FILE *p = popen("echo \"Test\"","r");
    if (p != NULL )
    {
        while (!feof(p) && (i < 99) )
        {
            fread(&buf[i++],1,1,p);
        }
        buf[i] = 0;
        printf("This is the output in the form of a string >%s<",buf);
        pclose(p);
        return 0;
    }
    else
    {
        return -1;
    }
}