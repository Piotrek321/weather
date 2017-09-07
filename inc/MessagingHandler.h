#ifndef MESSAGINGHANDLER_H
#define MESSAGINGHANDLER_H

#include <errno.h>
#include <mqueue.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
/*
 * Declare the message structure.
 */

class MessagingHandler
{
public:
    MessagingHandler(std::string serverOrClient, bool isThisMainQeueue=0);
    void sendMessage(std::string datatoSend, unsigned int priority);
    bool receiveMessage(std::string &messageToReceive);
    ~MessagingHandler();
private:
    struct mq_attr attr;
    std::string m_queueName;
    mqd_t createdQueue;
    mqd_t messageQueueSender;
    mqd_t messageQueueReceiver;

};

#endif // MESSAGINGHANDLER_H
