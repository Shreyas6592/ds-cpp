//Problem statement
//1. Accept a string from user
//2. Create two threads
//3. One thread checks for vowels and outputs it's lower case
//4. Another thread checks for consonants and outputs it's upper case
//5. The characters from string should be in same order of as that of input

//Author: Shreyas Atul Pophli

#include <stdio.h> 
#include <pthread.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_LIMIT 20 
char str[MAX_LIMIT]; 
pthread_t t1,t2;
pthread_mutex_t lock;
pthread_cond_t cond;
unsigned int len;
int i = 0;

bool isVowel(char a)
{
   bool ret = false;
   if(a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u' || a == 'A' || a == 'E' || a == 'I' || a == 'O' || a == 'U')
   {
      ret = true;
   }

   return ret;
}
//Function invoked from thread 1
void* Vowels(void*arg)
{
   while(1)
   {
      pthread_mutex_lock(&lock);
      while(i<len)
      {
         if(isVowel(str[i]))
         {
            printf("%c",tolower(str[i]));
            i++;
            pthread_mutex_unlock(&lock);
            pthread_cond_signal(&cond);             
         } 
         else
         {
            pthread_cond_wait(&cond,&lock);  
         }  
      }
      if(i==len-1)
         break;
   }
}
//Function invoked from thread 2
void* Consonants(void*arg)
{
   while(1)
   {
      pthread_mutex_lock(&lock);
      while(i<len)
      {
         if(!isVowel(str[i]))
         {
            printf("%c",toupper(str[i]));
            i++; 
            pthread_mutex_unlock(&lock);
            pthread_cond_signal(&cond);  
         }
         else
         {
            pthread_cond_wait(&cond,&lock);                         
         } 
      }      
      if(i==len-1)
         break;
   }
}

int main() 
{ 
   pthread_mutex_init(&lock,0);
   pthread_cond_init(&cond,0);
   fgets(str, MAX_LIMIT, stdin); 
   printf("Received String: %s", str);

   len = strlen(str);

   printf("Len: %d\n",len);

   printf("Converted String: ");

   pthread_create(&t1,NULL,&Vowels,NULL);
   pthread_create(&t2,NULL,&Consonants,NULL); 

   pthread_join(t1,NULL);
   pthread_join(t2,NULL);

   return 0; 
} 
