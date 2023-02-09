#include "TextBox.h"

namespace CUI{
  TextBox::TextBox(std::string text, Vec2 pos){
    m_text = text;
    m_pos.x = pos.x - calcTextBounds(text).width/2;
    m_pos.y = pos.y + calcTextBounds(text).height/2;
  }

  void TextBox::tick(vex::brain *b, bool clicked){

  }

  void TextBox::render(vex::brain *b, double dt){
    b->Screen.setPenColor(white);
    b->Screen.printAt(m_pos.x, m_pos.y, false, m_text.c_str());
  }

  void TextBox::setPosition(Vec2 pos){
    m_pos.x = calcTextBounds(m_text).width/2 + pos.x;
    m_pos.y = calcTextBounds(m_text).height/2 + pos.y;
  }

  void TextBox::setSize(Size2 size){
    PRINTMSG("Cannot Set a textbox size");
  }

}