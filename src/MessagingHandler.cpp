#include "../inc/MessagingHandler.h"
//TODO add design pattern
MessagingHandler::MessagingHandler(std::string queueName)
{
  attr.mq_maxmsg = 100;
  attr.mq_msgsize = 200;
  messageQueueSender= mq_open(queueName.c_str(), O_WRONLY|O_CREAT, 0655, &attr);
  if(messageQueueSender == -1)
  {
    std::cout <<"Mq_open for sedner went wrong" <<std::endl;
  }

  messageQueueReceiver= mq_open(queueName.c_str(), O_RDWR | O_NONBLOCK, 0655, &attr);
  if(messageQueueReceiver == -1)
  {
    std::cout <<"Mq_open for receiver went wrong" <<std::endl;
  }
}

void MessagingHandler::sendMessage(std::string datatoSend, unsigned int priority)
{
  mq_send(messageQueueSender,datatoSend.c_str(), datatoSend.length(), priority);
}

bool MessagingHandler::receiveMessage(std::string &messageToReceive)
{
  char * message = new char [200];
  if( mq_receive(messageQueueReceiver, message, 200, NULL) != -1)
  {
    messageToReceive = std::string(message);
    delete[] message;
    return 1;
  }
  delete[] message;
  return 0;
}
