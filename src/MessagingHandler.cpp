#include "../inc/MessagingHandler.h"
//TODO add design pattern
MessagingHandler::MessagingHandler(std::string queueName, bool isThisMainQeueue): m_queueName(queueName), createdQueue(-1),messageQueueReceiver(-1)
{
  attr.mq_maxmsg = 10;
  attr.mq_msgsize = 1024;
  if(isThisMainQeueue)
  {
      createdQueue = mq_open( m_queueName.c_str(), O_RDWR|O_CREAT, 0666, &attr);
      if(createdQueue == -1)
      {
        std::cout <<"Creating queue went wrong. Error: " << strerror (errno) <<std::endl;
      }
  }
}
MessagingHandler::~MessagingHandler()
{
    mq_close(messageQueueReceiver);
    mq_close(createdQueue);
    mq_unlink(m_queueName.c_str());
}

void MessagingHandler::sendMessage(std::string datatoSend, unsigned int priority)
{   
  std::cout <<"Sending messag: " << datatoSend <<"AAAA"<< std::endl;
  messageQueueSender= mq_open(m_queueName.c_str(), O_WRONLY );
  if(messageQueueSender == -1)
  {
    std::cout <<"Mq_open for sedner went wrong. Error: " << strerror (errno) <<std::endl;
  }
  if(mq_send(messageQueueSender,datatoSend.c_str(), datatoSend.length(), priority)<0)
  {
    std::cout <<"Mq_send for went wrong. Error: " << strerror (errno) <<std::endl;
  }
 // mq_close(createdQueue);

}

bool MessagingHandler::receiveMessage(std::string &messageToReceive)
{
  messageQueueReceiver= mq_open(m_queueName.c_str(), O_RDWR | O_NONBLOCK);
  if(messageQueueReceiver == -1)
  {
    std::cout <<"Mq_open for receiver went wrong.Error: " << strerror (errno) <<std::endl;
  }
  char message[1024];
  if( mq_receive(messageQueueReceiver, message, sizeof (message), NULL) != -1)
  {
    messageToReceive = std::string(message);
    return 1;
  }
  return 0;
}
