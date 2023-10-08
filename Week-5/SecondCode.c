
#include<stdio.h>
#include<string.h>
char *ip;
char string[50];
int S(), L(), LPRIME();


int main()
{
    printf("Enter the string : \n");
    scanf("%s", string);
    ip = string;
    printf("\n\nInput\t\t\tAction\n-----------------------------------------------\n");

    if (S() && *ip == '\0')
    {
        printf("-----------------------------------------------");
        printf("\nString is successfully parsed\n\n");
    }
    else
    {
        printf("\n-----------------------------------------------\n");
        printf("Error in parsing String!!!\n\n");
    }
    return 0;
}


// S -> (L) | a
int S()
{
    if( *ip=='(' )
    {
        printf("%s\t\t\tS -> (L) | a \n",ip);
        ip++;
        if(L())
        {
            if(*ip==')')
            {
                printf("%s\t\t\tS -> (L) | a \n",ip);
                ip++;
                return 1;
            }
        }
        else
        {
            return 0;
        }
    }
    else if( *ip=='a' )
    {
        printf("%s\t\t\tS -> (L) | a \n",ip);
        ip++;
    }
    else
    {
        return 0;
    }
}

// L -> SL'
int L()
{
    printf("%s\t\t\tL -> SL' \n",ip);
    if(S())
    {
        if(LPRIME())
        {
            return 1;
        }
    }
    else
    {
        return 0;
    }
}


// L' -> ,SL' | ^
int LPRIME()
{
    printf("%s\t\t\tL' -> ,SL' | ^ \n",ip);
    if(*ip==',')
    {
        printf("%s\t\t\tL' -> ,SL' | ^ \n",ip);
        ip++;
        if(S())
        {
            if(LPRIME())
            {
                return 1;
            }
        }
        else
        {
            return 0;
        }
    }
    else
    {
        printf("%s\t\t\tL' -> ,SL' | ^ \n",ip);
        return 1;
    }
}
