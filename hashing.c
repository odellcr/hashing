#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

// The purpose of this module is to provide a simple hashing library
// Functionality included: insert, delete, retreive, calculate

#define MAX_SIZE 20

static bool hash_array[MAX_SIZE];

int GenerateRandomNumber(void);
int CalculateHash(int value);
bool InsertHash(int value);
bool DeleteHash(int key);

int main(void)
{
    int random_num;
    int hash_val;
    int i;

    printf("Basic Hash Module\n");

    for(i = 0; i < 10; i++)
    {
        random_num = GenerateRandomNumber();

        if(random_num < 0)
        {
            random_num = random_num * -1;
        }
        
        hash_val = CalculateHash(random_num);

        InsertHash(hash_val);
    }

    for(i = 0; i < MAX_SIZE; i++)
    {
        printf("hash[%d] = %s\n", i, hash_array[i] ? "true" : "false");
    }

    return 0;
}

int GenerateRandomNumber(void)
{
    static bool init = false;

    if(!init)
    {
        srand(time(NULL)); // Initialization, call once
        init = true;
    }

    return rand();
}

// This assumes a known size of information to hash
int CalculateHash(int value)
{
    return value % MAX_SIZE;
}

bool InsertHash(int value)
{
    if(value < MAX_SIZE)
    {
        hash_array[value] = true;
    }

    return hash_array[value];

}

bool DeleteHash(int key)
{
    if(key < MAX_SIZE)
    {
        hash_array[key] = false;
    }

    return !hash_array[key];
}