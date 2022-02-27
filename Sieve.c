#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

#define NUM_LIST_SIZE 10000

static unsigned int list[NUM_LIST_SIZE]; // list of numbers x...y

int range(unsigned short int from, unsigned int to){
    int len = to-from;
    // Check if $from is greater than $to
    if(len <= 0)
        printf("Error: 0");

    for(int n=from,i=0; n < to, i <= len; n++, i++)
        list[i] = n;

    return len;
}

// Get first element in arr, greater than x
int first_gt(unsigned int x, unsigned int arr[]){
    for(int i=0; i < NUM_LIST_SIZE; i++)
        if(arr[i] > x)
            return arr[i];
}

void ABORT(char *msg){
    puts(msg); exit(1);
}

int main(){
    unsigned int sieve_to;
    printf("Sieve from 2-?: ");
    scanf("%d", &sieve_to);
    
    if(sieve_to <= 2)
        ABORT("Please enter a number greater than 2");
    if(sieve_to > NUM_LIST_SIZE){
        char str[40];
        sprintf(str, "Please enter a number litter than %d", NUM_LIST_SIZE);
        ABORT(str);
    }


    unsigned int len = range(2, sieve_to);
    unsigned int prime = 2; // current prime number

    while(prime < len){
        for(int i=0; i < len; i++){
            if(list[i] == '\0'){ // Do nothing
            } else if(list[i]%prime==0 && list[i]!=prime){
                // Delete composite number
                list[i] = '\0';
            }
        }
        printf("%d\n", prime); // print the current prime number
        prime = first_gt(prime, list); // change the current prime number
    }
}
