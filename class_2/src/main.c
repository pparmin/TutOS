//include standard library
#include <stdlib.h>

typedef void (*constructor)();
constructor start_constructors;
constructor end_constructors;

//a function that calls all constructors by iterating the memory addresses from the very first one to the very last, but not least one
void CallAllConstructors()
{
    for(constructor* i = &start_constructors; i != &end_constructors; i++)
    {
        (*i)();
    }
}

void kmain()
{
    //calling our printf function passing in a basic hello world string
    clear();
    int ylimit = 6;
    for (int i = 0; i <= ylimit; ++i) 
    {
        if (i == 0) 
        {
            printf("Hello World!"); 
            printnl();
        } else if (i >= 1 && i < ylimit) 
        {
            printnl();
        } else if (i == ylimit) 
        {
            printf("Kenix Kil");
        }
    }
    while(1);
}

/* Scrolling function: 
Whenever you exceed the y-limit
--> delete/move stuff from the top of the video buffer
--> have new stuff appear at the bottom

*/