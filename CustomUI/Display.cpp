#include "Display.h"

namespace CUI{
  Display::Display(vex::brain* b, int flags){
    m_brain = b;
    m_flags = flags;
    m_holding = false;
    m_clicked = false;
    m_canvas = nullptr;
    m_deltaTime = 0;
    m_frameTime = 0;
  }
  
  void Display::addWidget(CUI::IWidget *widget){
    m_widgets.push_back(widget);
  }

  void Display::swapCanvas(Canvas *canvas){
    m_canvas = canvas;
  }

  void Display::init(){
    if(m_flags & CUIDisplayFlags_NON_BLOCKING){
      this->createThread();
    }
    else{
      m_running = true;
      while(m_running){
        m_brain->Screen.clearScreen();
        genFrame();
        m_brain->Screen.render(true);
      }
    }
  }


  void Display::run(){
    m_running = true;
    while(m_running){
      m_brain->Screen.clearScreen();
      m_brain->Screen.setFont(fontType::cjk16);
      genFrame();
      m_brain->Screen.render(true);
    }
  }

  void Display::genFrame(){
    //reset the clicked variable every frame to make sure that it is only handled once
    double beginFrame = m_brain->Timer.time(msec);

    m_clicked = false;
    //Clicking logic
    if(m_brain->Screen.pressing()){
      m_holding = true;
    }
    else if (m_holding) {
      m_holding = false;
      m_clicked = true;
    }

    for(uint16_t i = 0; i < m_widgets.size(); i++){
      m_widgets[i]->tick(m_brain, m_clicked);
    }
    if(m_canvas!=nullptr){
      m_canvas->tickWidgets(m_brain,m_clicked);
    }

    for(uint16_t i = 0; i < m_widgets.size(); i++){
      m_widgets[i]->render(m_brain, m_deltaTime);
    }
    if(m_canvas!=nullptr){
      m_canvas->renderWidgets(m_brain,m_deltaTime);
    }

    double endFrame = m_brain->Timer.time(msec);

    m_frameTime = endFrame - beginFrame;
    m_deltaTime = m_frameTime/1000;

  }

  int Display::getFrameTime(){
    return m_frameTime;
  }

  int Display::getFPS(){
    return m_frameTime<1 ? FPS_PLUS_1000 : 1000/m_frameTime;
  };
}