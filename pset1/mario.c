#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Get the input
    int height = 0;
    printf("Height: ");
    
    while (height <= 0 || height >= 23)
    {
        height = GetInt();
        if (height >= 0 && height <= 23)
        {
            break;
        } 
        
        else if (height < 0 || height > 23)
        {
            printf("Height: ");
        }
        
        else
        {
            printf("Retry: ");
        }
    }
    
    
    // Make the Pyramid
    for (int i=0; i < height; i++){
        int hashes = i + 2;
        int spaces = height - hashes + 1;
        
        for (int s = 0; s < spaces; s++){
            printf(" ");
        }
        
        for (int h = 0; h < hashes; h++){
            printf("#");
        }
        printf("\n");   
    }
}
