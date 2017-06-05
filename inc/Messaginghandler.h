#ifndef MESSAGINGHANDLER_H
#define MESSAGINGHANDLER_H

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#define MSGSZ     128
/*
 * Declare the message structure.
 */

typedef struct msgbuf_my {
         long    mtype;
         char    mtext[MSGSZ];
         } message_buf;

class MessagingHandler
{
public:
    MessagingHandler(std::string serverOrClient);
    void sendMessage(std::string datatoSend);
    std::string receiveMessage();
    int msqid;
    int msgflg;
    key_t key;
    message_buf sendBuf;
    message_buf receiveBuf;

    size_t buf_length;
};

#endif // MESSAGINGHANDLER_H
