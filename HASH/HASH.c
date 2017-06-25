#include <stdio.h> //I/O FUNCTIONS
#include <string.h> //USEFUL string functions 
#include <stdlib.h> //memory allocations

#define HASH_TAB 512 //macro for hash table size 

struct hashrec{
    char *key; // pointer for a char to hold keys 
}

// double hashing functions

unsigned int hash(char *k, int i){ //k = current key, int i = pos
    return (h1(k)+i * h2(k))% HASH_TAB; //HASH DOUBLING FUNC
}

unsigned int h1(char *k){ //takes in char for arg 
    unsigned int h;
    unsigned char *c;

    h = 0; // initialize key to 0
    for (c=(unsigned char*)k; *c; c++)
        h = h*37+c; //prime number 37 for hashing strings
        return h;

}
unsigned int h2(char *k){ //takes in char for arg 
    unsigned int h;
    unsigned char *c;

    h = 0; // initialize key to 0
    for (c=(unsigned char*)k; *c; c++)
        h = h*31+c; //different prime number than h1 co prime
        return h%2=0 ? h+1 : h; //if h=0 add 1 so it becomes odd

}

//locate : returns bucket of index with a given key 

unsigned int locate(struct hashrec hashtab[], char*k){//takes in hash table and key 
    unsigned int i, b; // local vars i = how many buckets probed, b = current address 

    for(i=0; i<HASH_tab; i++){
        b = hash(k,i);
        if(NULL == hashtab[b].key || strcmp(hashtab[b].key,k)== 0) // scans entire hashtable, stop if empty bucket found or a key that matches k, or all buckets have been probed. 
        break;
    }
    return b;

}

//member function : uses locate to return val

int member(struct hashrec hashtab[], char *k){
    unsigned int b = locate(hashtab, k);

    if (NULL == hashtab[b].key) //if empty bucket returned, hash key not in hash table 
        return 0;
    else
        return strcmp(hashtab[b].key, k) == 0; //non empty bucket key and entered key match 

}

int insert (struct hashrec hashtab[], char *k){
    unsigned int b; //bucket
    b = locate(hashtab, k); //returns address of first empty bucket
    if (NULL==hashtab[b].key){ //if empty bucket found
        hashtab[b].key = cpy(k); //make copy of target key and copy into bucket key
        return 1; //insertion successful
    }

    else 
        return strcmp(hashtab[b].key, k) == 0; //check if key is already in bucket
      //return 0 if insertion failed  
}

//copy function for copying string 

char *cpy(char *s){ //takes in a string pointer 
    char *dest, *d;
    d = dest = malloc(strlen(s)*sizeof(char)+1); //size allocated to hold string and extra space
    if (d)
        while ((*d++ = *s++));
        return dest;
}

//initialize hash table and set values to NULL 

void init_hash_table(struct hashrec hashtab[]){
    unsigned int b;

    for (b = 0; b< HASH_TAB; b++)
        hashtab[b].key = NULL;
}


