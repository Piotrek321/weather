#include "../inc/Messaginghandler.h"
//TODO add design pattern
MessagingHandler::MessagingHandler(std::string serverOrClient)
{
    if(serverOrClient == "server")
    {
      msgflg = IPC_CREAT | 0666;
    }
    else if(serverOrClient == "client")
    {}
    /*
     * Get the message queue id for the
     * "name" 1234, which was created by
     * the server.
     */
    key = 1234;
}


void MessagingHandler::sendMessage(std::string datatoSend)
{
    if ((msqid = msgget(key, msgflg )) < 0) {
        perror("msgget");
        exit(1);
    }

    /*
     * We'll send message type 1
     */

    sendBuf.mtype = 1;

    (void) strcpy(sendBuf.mtext,datatoSend.c_str());

    buf_length = strlen(sendBuf.mtext) + 1 ;

    /*
     * Send a message.
     */
    if (msgsnd(msqid, &sendBuf, buf_length, IPC_NOWAIT) < 0) {
       printf ("%d, %d, %s, %d\n", msqid, sendBuf.mtype, sendBuf.mtext, buf_length);
        perror("msgsnd");
        exit(1);
    }
}
std::string MessagingHandler::receiveMessage()
{
    if ((msqid = msgget(key, 0666)) < 0) {
          perror("msgget");
          exit(1);
    }
/*
     * Receive an answer of message type 1.
     */
    if (msgrcv(msqid, &receiveBuf, MSGSZ, 1, 0) < 0) {
        perror("msgrcv");
        exit(1);
    }

    /*
     * Print the answer.
     */
    return receiveBuf.mtext;
}
