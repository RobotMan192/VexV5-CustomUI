#include "Canvas.h"

namespace CUI{
  void Canvas::addWidget(IWidget *widget){
    m_widgets.push_back(widget);
  }

  void Canvas::tickWidgets(brain* b, bool clicked){
    for(uint16_t i = 0; i < m_widgets.size(); i++){
      m_widgets[i]->tick(b, clicked);
    }
  }

  void Canvas::renderWidgets(brain* b, double dt){
    for(uint16_t i = 0; i < m_widgets.size(); i++){
      m_widgets[i]->render(b,dt);
    }
  }
  
}