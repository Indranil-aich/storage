/*
#include <mutex>
#include <thread>
#include <semaphore.h>
#include <iostream>

#define SIZE 5

int  _iTail = 0;
int  _iHead = 0;
int  _iBuf[SIZE];
bool bFull = false;
bool bEmpty = true;

sem_t sem_pr, sem_co;
std::mutex mtx;  // Mutex to protect shared resources

void producer_()
{
   for(int i = 0 ; i < SIZE*2; i++)
   {
       sem_wait(&sem_pr);
       {
           std::lock_guard<std::mutex> lock(mtx);  // Lock the mutex

           _iBuf[_iTail] = (i+1)*10;
           std::cout << "produce::" << _iBuf[_iTail] << std::endl;
           _iTail = (_iTail+1) % SIZE;
           if(_iTail == _iHead)
           {
               bFull = true;
           }
           bEmpty = false;
       }  // Mutex is automatically released here
       sem_post(&sem_co);
   }
}

void consumer_()
{
   for(int i = 0 ; i < SIZE*2; i++)
   {
       sem_wait(&sem_co);
       {
           std::lock_guard<std::mutex> lock(mtx);  // Lock the mutex

           std::cout << "consumer::" << _iBuf[_iHead] << std::endl;
           _iHead = (_iHead+1) % SIZE;
           if(_iHead == _iTail)
           {
               bEmpty = true;
           }
           bFull = false;
       }  // Mutex is automatically released here
       sem_post(&sem_pr);
   }
}

int main()
{
   sem_init(&sem_pr, 0, SIZE);
   sem_init(&sem_co, 0, 0);
   std::thread th1(producer_);
   std::thread th2(consumer_);
   th1.join();
   th2.join();
   return 0;
}


/////////////////////////////////////////////////////////////////////////////////
#include <mutex>
#include <thread>
#include <semaphore.h>
#include <iostream>
#include <condition_variable>

#define SIZE 5

int  _iTail = 0;
int  _iHead = 0;
int  _iBuf[SIZE];
bool bFull = false;
bool bEmpty = true;

std::mutex mutx;  // Using std::mutex instead of pthread_mutex_t
std::condition_variable sem_pr, sem_co;

void producer_()
{
   for(int i = 0 ; i < SIZE*2; i++)
   {
       {
           std::unique_lock<std::mutex> lock(mutx);  // Lock the mutex using lock_guard
           sem_pr.wait(lock, []{ return !bFull; });  // Wait while buffer is full

           _iBuf[_iTail] = (i+1) * 10;
           std::cout << "produce::" << _iBuf[_iTail] << std::endl;
           _iTail = (_iTail + 1) % SIZE;

           if (_iTail == _iHead)
           {
               bFull = true;
           }

           bEmpty = false;
       }  // Mutex is automatically unlocked here
       sem_co.notify_one();  // Signal the consumer
   }
}

void consumer_()
{
   for(int i = 0 ; i < SIZE*2; i++)
   {
       {
           std::unique_lock<std::mutex> lock(mutx);  // Lock the mutex using lock_guard
           sem_co.wait(lock, []{ return !bEmpty; });  // Wait while buffer is empty

           std::cout << "consumer::" << _iBuf[_iHead] << std::endl;
           _iHead = (_iHead + 1) % SIZE;

           if (_iHead == _iTail)
           {
               bEmpty = true;
           }

           bFull = false;
       }  // Mutex is automatically unlocked here
       sem_pr.notify_one();  // Signal the producer
   }
}

int main()
{
   std::thread th1(producer_);
   std::thread th2(consumer_);
   th1.join();
   th2.join();
   return 0;
}

//

#include <iostream>
#include <thread>
#include <vector>
#include <semaphore.h>

sem_t sem_ev, sem_od;
void even(std::vector<int> v1)
{
   for(auto & tmp:v1)
   {
     if(tmp % 2 == 0)
     {
        sem_wait(&sem_ev);
          std::cout<<" "<<tmp;
        sem_post(&sem_od);
     }
   }
}

void odd(std::vector<int> v1)
{
   for(auto & tmp:v1)
   {
     if(tmp % 2 != 0)
     {
        sem_wait(&sem_od);
          std::cout<<" "<<tmp;
        sem_post(&sem_ev);
     }
   }
}

int main()
{
   sem_init(&sem_od, 0,1);
   sem_init(&sem_ev, 0, 0);
   std::vector<int>v1{1,2,3,4,5,6,7,8,9};
   std::thread th1(odd, v1);
   std::thread th2(even, v1);
   th1.join();
   th2.join();
   sem_destroy(&sem_od);
   sem_destroy(&sem_ev);
   return 0;
}

//


*/