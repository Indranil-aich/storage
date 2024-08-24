#include "CommonHeader.h"
class CmyFinal;
class CmkFinal
{
private:
	friend class CmyFinal;
	CmkFinal() = default;
};

class CmyFinal:public virtual CmkFinal
{
public:
	CmyFinal() = default;
};

class CmyClass :public CmyFinal
{
public:
	CmyClass() = default;
};
void funcToMakeFinalClass_()
{
	std::cout << __FUNCTION__ << " execute at line no" << __LINE__ << std::endl;
	//CmyClass* obj = new CmyClass();
	std::cout << "end " << __FUNCTION__ << std::endl;
} 

/*
#include <iostream>
#include <semaphore.h>
#include <thread>
#include <vector>

sem_t read_sem;
sem_t rw_sem;
int data = 0;
int read_count = 0;

void reader(int id)
{
    sem_wait(&read_sem);
    read_count++;
    if(read_count == 1)
    {
        sem_wait(&rw_sem);
    }
    sem_post(&read_sem);
    std::cout<<" reader "<< id <<" read "<<data<<std::endl;
    sem_wait(&read_sem);
    read_count--;
    if(read_count == 0)
    {
        sem_post(&rw_sem);
    }
    sem_post(&read_sem);
}

void writer(int id)
{
    sem_wait(&rw_sem);
    data = id;
    std::cout<<" writer "<< id <<" write "<<data<<std::endl;
    sem_post(&rw_sem);
}

#if 0
int main()
{
    sem_init(&rw_sem, 0, 1);
    sem_init(&read_sem, 0, 1);
    std::vector<std::thread> readTh;
    std::vector<std::thread> writerTh;
    readTh.emplace_back(reader, 1);
    writerTh.emplace_back(writer,1);

    readTh.emplace_back(reader, 2);
    writerTh.emplace_back(writer,2);
    readTh.emplace_back(reader, 3);


    for(auto &tmp:writerTh)
    {
        tmp.join();
    }
    for(auto &tmp:readTh)
    {
        tmp.join();
    }
    sem_destroy(&rw_sem);
    sem_destroy(&read_sem);
    return 0;
}
#endif
/*
The Reader-Writer problem is a classic synchronization issue where:

Readers: Can read shared data concurrently without interference from other readers.
Writers: Need exclusive access to the data to modify it, preventing both readers and other writers from accessing the data during the write operation.
Problem Goals:
Readers should be able to read the data simultaneously as long as no writers are active.
Writers should have exclusive access to the data, meaning no readers or other writers can access the data while a writer is working.
Variants:
First Readers, First Writers: Prioritize readers over writers or vice versa.
Fair Readers-Writers: Ensure fairness so that neither readers nor writers are starved.
The problem is typically solved using synchronization mechanisms like semaphores, mutexes, or read-write locks to manage access to the shared data.
*/
