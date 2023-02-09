#include "Button.h"

namespace CUI{
  Button::Button(std::string title, ButtonStyle style, CUI::Rect rect,void(*callback)()){
    m_title = title;
    m_rect = rect;
    centralRectToCorner(&m_rect);
    m_callback = callback;

    m_style = style;
  }

  void Button::setPosition(Vec2 pos){
    m_rect.x = pos.x;
    m_rect.y = pos.y;
  }

  void Button::setSize(Size2 size){
    m_rect.width = size.width;
    m_rect.height = size.height;
  }

  void Button::tick(vex::brain *b, bool clicked){
    if(clicked){
      int xPos = b->Screen.xPosition();
      int yPos = b->Screen.yPosition();

      if(inRect(CUI::Vec2(xPos,yPos), m_rect)){
        m_callback();
      }
    }
  }

  void Button::render(vex::brain *b, double dt){
    b->Screen.setPenWidth(m_style.borderThickness);

    b->Screen.setFillColor(m_style.baseColor);
    b->Screen.setPenColor(m_style.borderColor);
    b->Screen.drawRectangle(m_rect.x, m_rect.y, m_rect.width, m_rect.height);

    b->Screen.setPenColor(m_style.textColor);
    printCenteredTextInRect(m_rect, m_title);
  }
}