#pragma once

#include "../CustomUI.h"

namespace CUI{
  class TextBox : public IWidget{
    public:
      TextBox(std::string text, Vec2 pos);

      void tick(vex::brain *b, bool clicked) override;
      void render(vex::brain *b, double dt) override;

      void setPosition(Vec2 pos) override;
      void setSize(Size2 size) override;
      
    private:
      std::string m_text;
      Vec2 m_pos;
  };
}