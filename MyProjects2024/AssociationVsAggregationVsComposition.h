#pragma once
/*******************************************************************************************************
Association:
===========================
Association represents a relationship between two or more objects where each object has its own lifecycle,
and there is no ownership or dependency between them.For example, let's say we have a Car class and a Driver class.
The Car and Driver have an association, as a driver can drive multiple cars, and a car can be driven by multiple drivers.
The Car and Driver objects are connected through this association, but neither object owns or depends on the other.

Aggregation:
============================
Aggregation represents a relationship between two objects where one object is a part or a component of the other object,
but their lifecycles are not necessarily dependent on each other. For example, a Car class may have a relationship
with a Wheel class through aggregation. A car consists of four wheels, and the wheels are part of the car.
However, even if the car is destroyed, the wheels can still exist independently or be used by another car.
The Car class may have a collection of Wheel objects as a member variable, and it can create, modify, or delete wheels as needed.

Composition:
===========================

Composition is a strong form of aggregation where one object is responsible for the existence and lifecycle of another object.
For example, a Car class may have a relationship with an Engine class through composition. The engine is an essential component of
the car, and it cannot exist without the car.
The Car class owns an Engine object, and the engine is created, modified, and destroyed along with the car.
In this case, the Car class may have an Engine object as a member variable, and it is responsible for
creating and destroying the engine.

/**************************************************************************************************************/


/*
#include <iostream>
#include <semaphore.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <unistd.h>  // For fork()

struct sSemObj
{
    sem_t _mSem[4];
    int _mBuf;
};

void initialize_semaphores(sSemObj* sObj)
{
    sem_init(&sObj->_mSem[0], 1, 1); // Semaphore to control write access
    sem_init(&sObj->_mSem[1], 1, 0); // Semaphore to signal reader to read
    sem_init(&sObj->_mSem[2], 1, 0); // Semaphore to signal writer to write
    sem_init(&sObj->_mSem[3], 1, 1); // Semaphore to control read access
}

void cleanup(sSemObj* sObj, int shmid)
{
    shmdt(sObj);
    shmctl(shmid, IPC_RMID, NULL);
}

int main()
{
    int key = ftok("file", 65);
    int shmid = shmget(key, sizeof(sSemObj), 0666 | IPC_CREAT);
    sSemObj* sObj = static_cast<sSemObj*>(shmat(shmid, NULL, 0));

    initialize_semaphores(sObj);

    pid_t pid = fork();

    if (pid == 0)  // Child process (Reader)
    {
        for (int i = 0; i < 5; i++)
        {
            sem_wait(&sObj->_mSem[3]);
            std::cout << "Child Read: " << sObj->_mBuf << std::endl;
            sem_post(&sObj->_mSem[2]);
            sem_wait(&sObj->_mSem[1]);
            sObj->_mBuf = (i + 1) * 100;
            std::cout << "Child Write: " << sObj->_mBuf << std::endl;
            sem_post(&sObj->_mSem[0]);
        }
    }
    else if (pid > 0)  // Parent process (Writer)
    {
        for (int i = 0; i < 5; i++)
        {
            sem_wait(&sObj->_mSem[0]);
            sObj->_mBuf = (i + 1) * 10;
            std::cout << "Parent Write: " << sObj->_mBuf << std::endl;
            sem_post(&sObj->_mSem[1]);
            sem_wait(&sObj->_mSem[2]);
            std::cout << "Parent Read: " << sObj->_mBuf << std::endl;
            sem_post(&sObj->_mSem[3]);
        }

        // Wait for the child process to finish
        //wait(NULL);
    }
    else
    {
        std::cerr << "Fork failed!" << std::endl;
        cleanup(sObj, shmid);
        return 1;
    }

    cleanup(sObj, shmid);
    return 0;
}



=====================================================
#include <iostream>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <unistd.h>  // For fork()
#include <cstdlib>   // For exit()
#include <wait.h>    // For wait()

// Define the message structure
struct message
{
    long mtype;      // Message type
    int mtext;       // Message text
};

void cleanup(int msgid)
{
    msgctl(msgid, IPC_RMID, NULL);
}

int main()
{
    key_t key = ftok("file", 65);


    // Create a message queue
    int msgid = msgget(key, 0666 | IPC_CREAT);
    if (msgid == -1)
    {
        std::cerr << "msgget failed!" << std::endl;
        exit(1);
    }

    pid_t pid = fork();

    if (pid == 0)  // Child process (Reader)
    {
        message rcvbuf;
        for (int i = 0; i < 5; i++)
        {
            // Receive message from the queue
            if (msgrcv(msgid, &rcvbuf, sizeof(rcvbuf.mtext), 1, 0) == -1)
            {
                std::cerr << "msgrcv failed!" << std::endl;
                exit(1);
            }
            std::cout << "Child Read: " << rcvbuf.mtext << std::endl;

            // Prepare message to send back
            message sndbuf;
            sndbuf.mtype = 2; // Message type for writing
            sndbuf.mtext = (i + 1) * 100;

            // Send message to the queue
            if (msgsnd(msgid, &sndbuf, sizeof(sndbuf.mtext), 0) == -1)
            {
                std::cerr << "msgsnd failed!" << std::endl;
                exit(1);
            }
            std::cout << "Child Write: " << sndbuf.mtext << std::endl;
        }
    }
    else if (pid > 0)  // Parent process (Writer)
    {
        for (int i = 0; i < 5; i++)
        {
            // Prepare message to send
            message sndbuf;
            sndbuf.mtype = 1; // Message type for reading
            sndbuf.mtext = (i + 1) * 10;

            // Send message to the queue
            if (msgsnd(msgid, &sndbuf, sizeof(sndbuf.mtext), 0) == -1)
            {
                std::cerr << "msgsnd failed!" << std::endl;
                exit(1);
            }
            std::cout << "Parent Write: " << sndbuf.mtext << std::endl;

            // Receive message from the queue
            message rcvbuf;
            if (msgrcv(msgid, &rcvbuf, sizeof(rcvbuf.mtext), 2, 0) == -1)
            {
                std::cerr << "msgrcv failed!" << std::endl;
                exit(1);
            }
            std::cout << "Parent Read: " << rcvbuf.mtext << std::endl;
        }

        // Wait for the child process to finish
        wait(NULL);
    }
    else
    {
        std::cerr << "fork failed!" << std::endl;
        cleanup(msgid);
        exit(1);
    }

    cleanup(msgid);
    return 0;
}

*/