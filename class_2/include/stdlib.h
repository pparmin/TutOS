#ifndef STDLIB
#define STDLIB

//definitions
typedef char int8;
typedef unsigned char uint8;
typedef short int16;
typedef unsigned short uint16;
typedef int int32;
typedef unsigned int uint32;
typedef long long int64;
typedef unsigned long long uint64;

//we define our Video Buffer which is a pointer to 0xB8000
static uint16* VidBuff = (uint16*)0xB8000;
//we define the x and y of the cursor
static uint8 x = 0, y = 0;

/*
Hello
*/

//clear function
void clear()
{
    //this nested for loop goes over every position and sets it to a space character (80x25)
    for(y = 0; y < 25; y++)
    {
        for(x = 0; x < 80; x++)
        {
           VidBuff[80*y+x] = (VidBuff[80*y+x] & 0xFF00) | ' '; 
        }
    }

    //we set our x and y positions back to 0
    x = 0;
    y = 0;
}

void printnl() 
{
    x = 0;
    y++;
}

//printf function
void printf(char* string)
{
    //we iterate over the string and increase the memory address of VGA
    for(int i = 0; string[i] != '\0'; ++i)
    {
        switch(string[i])
        {
            //if it's a newline character, we increase y and go back to the first x position
            case '\n':
                printnl();
                break;
            default:
                //we move the char into the video buffer
                VidBuff[80*y+x] = (VidBuff[80*y+x] & 0xFF00) | string[i];
                //we also increment x
                x++;
                break;
        }

        //if we exceed the x character limit, we go to a new line
        if(x >= 80)
        {
            x = 0;
            y++;
        }

        //we clear the screen if we exceed the y limit
        //optional homework: make it scroll
        if(y >= 25)
        {
            
            clear();
        }
    }
}

#endif