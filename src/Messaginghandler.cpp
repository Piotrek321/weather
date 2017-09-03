#include "../inc/Messaginghandler.h"
//TODO add design pattern
MessagingHandler::MessagingHandler(std::string queueName, bool send)
{
   attr.mq_maxmsg = 10;
   attr.mq_msgsize = 30;
	 if(send)
	 {   
		 messageQueueHandler= mq_open(queueName.c_str(), O_WRONLY|O_CREAT, 0655, &attr);
   }
	 else
	 {
	   messageQueueHandler= mq_open(queueName.c_str(), O_RDWR | O_NONBLOCK, 0655, &attr);
	 }
   if(messageQueueHandler == -1)
   {
     std::cout <<"Mq_open went wrong" <<std::endl;
   }
}


void MessagingHandler::sendMessage(std::string datatoSend, unsigned int priority)
{
  mq_send(messageQueueHandler,datatoSend.c_str(), datatoSend.length(), priority);

}
bool MessagingHandler::receiveMessage(std::string messageToReceive)
{
  char * message = new char [100];
	if( mq_receive(messageQueueHandler, message, 100, NULL) != -1)
	{
    messageToReceive = std::string(message);
		delete[] message;
		return 1;
	}
	delete[] message;
	return 0;	
}
