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
    MessagingHandler(std::string serverOrClient, bool send);
    void sendMessage(std::string datatoSend, unsigned int priority);
    bool receiveMessage(std::string &messageToReceive);
 		struct mq_attr attr;
    mqd_t messageQueueSender;
    mqd_t messageQueueReceiver;


};

#endif // MESSAGINGHANDLER_H
