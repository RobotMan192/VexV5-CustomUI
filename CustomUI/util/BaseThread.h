#pragma once
#include "vex.h"

class BaseThread{
  private:
    thread *t;
  public:
    BaseThread();
    virtual ~BaseThread();
    
    void createThread();
  protected:
    virtual void run() = 0;

    static void threadProc(void* arg);

    
};