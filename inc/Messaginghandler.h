#ifndef MESSAGINGHANDLER_H
#define MESSAGINGHANDLER_H

#include <errno.h>
#include <mqueue.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#define MSGSZ     128
/*
 * Declare the message structure.
 */

class MessagingHandler
{
public:
    MessagingHandler(std::string serverOrClient);
    void sendMessage(std::string datatoSend, unsigned int priority);
    std::string receiveMessage();
 struct mq_attr attr;
    mqd_t messageQueueHandler;


};

#endif // MESSAGINGHANDLER_H
