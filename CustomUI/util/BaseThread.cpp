#include "BaseThread.h"

BaseThread::BaseThread(){
  
}


BaseThread::~BaseThread(){
  t->join();
  t->detach();
  delete t;
}

void BaseThread::createThread(){
  t = new thread(BaseThread::threadProc,static_cast<void*>(this));
}

void BaseThread::threadProc(void* arg){
  BaseThread *inst = static_cast<BaseThread *>(arg);
  inst->run();
}