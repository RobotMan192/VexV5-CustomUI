#pragma once

#include "../CustomUI.h"

namespace CUI{
  struct ButtonStyle{
    int borderThickness = 2;

    vex::color borderColor = blue;
    vex::color baseColor = black;
    vex::color textColor = white;
  };

  class Button: public IWidget{
    public:
      Button(std::string title, ButtonStyle style, CUI::Rect rect, void(*callback)());

      void tick(vex::brain *b, bool clicked) override;
      void render(vex::brain *b, double dt) override;

      void setPosition(Vec2 pos) override;
      void setSize(Size2 size) override;
      
    private:
      std::string m_title;
      
      ButtonStyle m_style;

      CUI::Rect m_rect;
      void(*m_callback)();

  };
}