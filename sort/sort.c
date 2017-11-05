#include"sort.h"

void swap(int *x, int *y)
{
    int t = *x;
    *x    = *y;
    *y    = t;
}

int bubble_sort(int *buffer, int size)
{
    for (int i=0; i<size; i++)
    {
        for (int j=size-1; j>i; j--)
        {
           if (buffer[j] < buffer[j-1])
           {
               swap(buffer + j, buffer + j - 1);
           }
        }
    }

    return (0);
}


int select_sort(int *buffer, int size)
{
    for (int i=0; i<size; i++)
    {
        int min_index = i;

        for (int j=i; j<size; j++)
        {
            if (buffer[j]<buffer[min_index])
            {
                min_index = j;
            }
        }
        swap(buffer+i, buffer+min_index);
    }
    return (0);
}

int insert_sort(int *buffer, int size)
{
    for (int i=1; i<size; i++)
    {
        int tmp = buffer[i];
        int j = 0;
        for (j=i-1; j>=0; j--)
        {
            if (buffer[j]>=tmp)
            {
                buffer[j+1]=buffer[j];    
            }
            else{
                break;
            }
        }
        buffer[j+1] = tmp;
    }
    return(0);
}
