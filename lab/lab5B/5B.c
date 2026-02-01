#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main() 
{
    char filename[20];
    scanf("%s", filename);
    FILE* file = fopen(filename, "r");//open the file for reading
    int count[256] = { 0 };//00-FF
    char pixel[3];//store the value
    while (fscanf(file, "%2s", pixel) != EOF)//stop until the end of the file 
    {
            int value;
            sscanf(pixel, "%02x", &value);//change str into integer
            count[value]++;
    }
    fclose(file);
    int max_count = 0;
    int max_pixel = 256;
    for (int i = 0; i < 256; i++) 
    {
        if (count[i] > max_count) 
        {
            max_count = count[i];
            max_pixel = i;
        }
        else if (count[i] == max_count && i < max_pixel) 
        {
            max_pixel = i;
        }
    }
    FILE* file1 = fopen("output.txt", "a");//appand the output
        fprintf(file1, "%02X %d\n", max_pixel, max_count);
        fclose(file1);
    return 0;
}