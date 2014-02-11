#include <stdio.h>
#include <cs50.h>

long long getLastDigit(long long input);
bool isValid(long long number);
string cardType(long long card_num, long long num_to_check);

int main(void)
{
    printf("Please input a number: ");
    long long cardnumber = GetLongLong();
    if (isValid(cardnumber))
    {
        printf("%s", cardType(cardnumber, cardnumber));
    }
    
    else
    {
        printf("INVALID\n");
    }
    
    
    
}


/*
*
* Returns the last digit of an integer that it is passed
*/
long long getLastDigit(long long input)
{
    if (input % 10 == 0){
        return 0;
    }

    else
    {
        return input % 10;
    }
}

bool isValid(long long number)
{
    int sum = 0;
    int n = 1;
    while (number > 0)
    {
        int last_digit = getLastDigit(number);

        if (n % 2 == 0)
        {
            // If number is greater than 10, mult. by 2, take the last number
            // of the product, add it to the sum, and then add on
            int product = last_digit * 2;
            
            if (product > 10)
            {
                int last_dig_product = getLastDigit(product);
                sum += last_dig_product + 1;
//                printf("Sum: %d\n", sum);
            }
            else if (product == 10)
            {
                sum += 1;
//                printf("Sum: %d\n", sum);
            }
            else
            {
                sum += product;
//                printf("Sum: %d\n", sum);
            }   
        }

        else
        {
            sum = last_digit + sum;

//            printf("Sum: %d\n", sum);
               
        }
        

        if (last_digit == 0)
        {
            number /= 10;
//            printf("%lld", number);
        }
        
        else
        {
            number = (number - last_digit) / 10;
//            printf("%lld", number);
        }
//        printf("%d\n", last_digit);
        n++;

    }
//    printf("Sum: %d\n", sum);
    
    if (sum % 10 == 0)
    {
        return true;
    }
    
    else
    {
        return false;
    }
}

string cardType(long long card_num, long long num_to_check)
{
    
    
    int i = 0;
    while (card_num > 0)
    {
        int last_digit = getLastDigit(card_num);
        if (last_digit == 0)
        {   
            card_num /= 10;
            i++;
        }
        
        else
        {
            i++;
            card_num = (card_num - last_digit) / 10;
        }
    }
    if (i == 15)
    {
        return("AMEX\n");
    }
    
    else if(i == 13 ||  (num_to_check / 1000000000000000 == 4L))
    {
        return("VISA\n");
    }
    else
    {
        return("MASTERCARD\n");
    }

}
