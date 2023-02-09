#include "ComboBox.h"

namespace CUI{
  ComboBox::ComboBox(std::string defaultText, ComboBoxStyle style, CUI::Rect baseRect, void(*callback)(std::string id)){
    m_defaultText = defaultText;
    m_baseRect = baseRect;
    centralRectToCorner(&m_baseRect);
    m_callback = callback;
    m_open = false;
    
    m_style = style;
  }

  void ComboBox::addEntry(std::string entry){
    m_entries.push_back(entry);
  }

  void ComboBox::tick(vex::brain *b, bool clicked){
    if(clicked){
      int xPos = b->Screen.xPosition();
      int yPos = b->Screen.yPosition();

      //check if clicked in first box
      if(inRect(Vec2(xPos,yPos), m_baseRect)){
        m_open = !m_open;
      }
      else if(m_open){
        int yOffset = m_baseRect.y + m_baseRect.height;

        for(int i = 0; i < m_entries.size(); i++){
          if(strcmp(m_defaultText.c_str(), m_entries[i].c_str())){
            Rect r(m_baseRect.x,yOffset,m_baseRect.width,m_baseRect.height);
            if(inRect(Vec2(xPos,yPos), r)){
              m_callback(m_entries[i]);
              m_defaultText = m_entries[i];
            }
            yOffset += m_baseRect.height;
          }
        }
      }
    }
  }

  void ComboBox::render(vex::brain *b, double dt){
    
    b->Screen.setFillColor(m_style.baseColor);
    b->Screen.setPenColor(m_style.borderColor);
    b->Screen.setPenWidth(m_style.borderThickness);
    
    b->Screen.drawRectangle(m_baseRect.x, m_baseRect.y, m_baseRect.width, m_baseRect.height);
    b->Screen.setPenColor(m_style.textColor);
    printCenteredTextInRect(m_baseRect, m_defaultText.c_str());
    
    if(m_open){
      int padding = m_style.borderThickness*2 + m_style.boxPadding;
      int yOffset = m_baseRect.y + m_baseRect.height + padding;

      for(int i = 0; i < m_entries.size(); i++){

        if(strcmp(m_defaultText.c_str(), m_entries[i].c_str())){
          b->Screen.setPenColor(m_style.borderColor);
          b->Screen.drawRectangle(m_baseRect.x, yOffset, m_baseRect.width, m_baseRect.height);
          Rect r = m_baseRect;
          r.y = yOffset;
          b->Screen.setPenColor(m_style.textColor);
          printCenteredTextInRect(r, m_entries[i].c_str());
          yOffset += m_baseRect.height + padding;
        }
        
      }
    }
  }

  void ComboBox::setPosition(Vec2 pos){
    m_baseRect.x = pos.x;
    m_baseRect.y = pos.y;
  }

  void ComboBox::setSize(Size2 size){
    m_baseRect.width = size.width;
    m_baseRect.height = size.height;
  }
}