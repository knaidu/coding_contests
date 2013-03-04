/*
 * circularQueue.cpp
 *
 *  Created on: Feb 23, 2013
 *      Author: karthiknaidudj
 */

#include<pthread.h>
#define DEFAULT_SIZE 100

class circularQueue{
 private:
    int *m_queue;
    int p_head;
    int p_tail;
    int m_cap;
    pthread_mutex_t mp = PTHREAD_MUTEX_INITIALIZER;
    public:
        circularQueue(int size)
        {
            /*in case invalid input*/
            if(size<0)
                size = DEFAULT_SIZE ;

            m_queue = new int[size];
            p_head = 0;
            p_tail = -1;
            m_cap = 0;
            pthread_mutex_init(&mp,NULL);
        }

        bool enqueue(int x)
        {
            bool res= false;
            p_thread_mutex_lock(&mp);
            /*queue is full*/
            if(m_cap == size)
            {
                res = false;
            }
            else
            {
                m_queue[(++p_tail)%size)] = x;
                ++m_cap;
                res = true;
            }
            p_thread_mutex_unlock(&mp);
            return res;
        }
        int dequeue()
        {
            int res=0;

            pthread_mutex_lock(&mp);
            /*empty queue*/
            if(m_cap == 0)
            {
                throw("empty queue!");
                pthread_mutex_unlock(&mp);
            }
            else{
                res = m_queue[p_head];
                p_head = (p_head+1)%size;
            }
            pthread_mutex_unlock(&mp);
            return res;
        }
        ~circularQueue()
        {
            delete[] m_queue;
            m_queue = NULL;
            pthread_mutex_destroy(&mp);
        }
}



