#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    // Get the user's change owed, taking care not to allow it to be negative or a string
    float change_owed = 0.0;
    printf("oh hai! How much changed is owed?\n");
    
    while (change_owed <= 0.0)
    {
        change_owed = GetFloat();
        if (change_owed > 0.0)
        {
            break;
        }
        
        else if (change_owed <= 0.0)
        {
            printf("How much change is owed?\n");
        }
        
        else
        {
            printf("Retry: ");
        }
    }
    
    
//    printf("Change owed: %f\n", change_owed);
    // Convert user's input into only cents
    int cents = round(100.0 * change_owed);
//    printf("%d cents\n", cents);  
       
    int coins = 0;
    while (cents >= 1){   
        if (cents >= 25)
        {
           cents -= 25;
           coins++;
        }
        
        if (cents >= 10 && cents < 25)
        {
            cents -= 10;
            coins++;
        }
        
        if (cents >= 5 && cents < 10)
        {
            cents -= 5;
            coins++;
        }
        
        if (cents < 5)
        {
            while (cents > 0)
            {
                cents -= 1;
                coins++;
            }
        }
        
        else if (cents == 0){
            break;
        }
    }
    
    printf("%d\n", coins);
    return 0;
}
