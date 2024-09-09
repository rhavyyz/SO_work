#pragma once


#include <thread>
#include <sys/shm.h>
#include <sys/ipc.h>
// #include <cstdlib>
#include"signal.h"
#include <semaphore>

#include <unistd.h>

#include"classification.h"
#include "question/question_awnser.h"
#include "question/question_view.h"
#include"shared_memory.h"


/*
    Class that stores everything required to the comunication between server and client

    message_id - Stores the id to acess the shared memory to a Message class that is going
                 to be used for the comunication
    classification_id - Stores the id to acess the shared memory to a Classification class 
                        that is going to be use for the comunication

    client_id - stores the id from the client's thread and is used as a identifier within the 
                the server's business rules.

    from_client_signal - A semaphore that is going to be used as a signal from the client to the server
    from_server_signal - A semaphore that is going to be used as a signal from the client to the server
*/
class Connection
{
    public:
        pid_t client_id;
        pid_t server_id;
        QuestionAwnser question_awnser;
        QuestionView question_view;
        Classification classification = Classification(0, 0, 0, false);


        Signal from_client_signal, 
               from_server_signal;

        Connection(pid_t client_id, pid_t server_id)
        {
            this->client_id = client_id; 
            this->server_id = server_id;
        }

        void free()
        {
            // shared_memory::free_shared_memory(this->question_view_id);
            
        // return true;   
        }    

};