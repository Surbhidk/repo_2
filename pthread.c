#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
void *worker(void*data)
{
   char*name = (char*)data;
   for (int i = 0; i<5; i++)
    {
      printf("Hi from thread name = %s\n",name);
      sleep(1);
    }
    printf("Thread%s done!\n",name);
}

void main() {
  pthread_t th1,th2,th3;
  pthread_create(&th1,NULL,worker,"X");
  pthread_create(&th2,NULL,worker,"Y");
  pthread_create(&th3,NULL,worker,"Z");
  sleep(10);
  printf("Exiting from main program\n");
}
