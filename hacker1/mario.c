#include <cs50.h>
#include <stdio.h>

int main(void)
{
    printf("Height: ");
    int height = GetInt();
    
    if (height == 0){
        return 0;
    }
    else if (height > 23 || height < 0)
    {
        while (height > 23 || height < 0)
        {
            printf("Heigt: ");
            height = GetInt();
        }
    }
    


    for (int i = 1; i <= height; i++)
    {
        int spaces = height - i;
        for (int j = 0; j < spaces; j++)
        {
            printf(" ");
        }

        int hashes = i;
        for (int k = 0; k < hashes; k++)
        {
            printf("#");
        }
        printf("  ");

        for (int l = 0; l < hashes; l++)
        {
            printf("#");
        }
        printf("\n");
    }

    return 0;
}
