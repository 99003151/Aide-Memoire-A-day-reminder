#include <aide_memoire.h>

int Leap_Year(int l)
    {
        int x=2;
        if(l>=2020&& l<=2030)
        {
            if(l % 400==0) x=1;
            else if(l % 100==0) x=0;
            else if(l % 4==0) x=1;
            else x=0;
        }
        return x;       
}  

