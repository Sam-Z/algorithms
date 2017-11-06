#include"sort.h"
#include<string.h>
#include<stdlib.h>

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



void __merge(int *buffer, int l, int r, int m)
{
    int size = r-l+1;

    int *p = malloc(size*sizeof(int));
    memcpy(p, buffer+l, size*sizeof(int));

    for (int i = l, j=m+1, k=l; k<=r; k++)
    {
        if (j>r)
        {
            buffer[k]=p[i++-l];
        }
        else if (i>m)
        {
            buffer[k]=p[j++-l];
        }else if(p[i-l]<p[j-l])
        {
            buffer[k]=p[i++-l];
        }else 
        {
            buffer[k]=p[j++-l];
        }
    }
    if (p != NULL)
    {
        free(p);
    }
}

void __merge_sort(int *buffer, int l, int r)
{
    if (l>=r)
    {
        return;
    }

    int m = (l+r)/2;

    __merge_sort(buffer, l, m);
    __merge_sort(buffer, m+1, r);
    __merge(buffer, l,r,m);
}

int merge_sort(int *buffer, int size)
{ 
    __merge_sort(buffer, 0, size-1);
}
