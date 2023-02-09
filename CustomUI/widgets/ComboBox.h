#pragma once

#include "../CustomUI.h"

namespace CUI{
  struct ComboBoxStyle{
    int borderThickness = 2;
    int boxPadding = 2;
    
    vex::color borderColor = blue;
    vex::color baseColor = black;
    vex::color textColor = white;

  };

  class ComboBox: public IWidget{
    public:
      ComboBox(std::string defaultText, ComboBoxStyle style, CUI::Rect baseRect, void(*callback)(std::string id));

      void addEntry(std::string entry);
      
      void tick(vex::brain *b, bool clicked) override;
      void render(vex::brain *b, double dt) override;

      void setPosition(Vec2 pos) override;
      void setSize(Size2 size) override;

    private:
      std::vector<std::string> m_entries;

      CUI::Rect m_baseRect;
      std::string m_defaultText;
      ComboBoxStyle m_style;

      void(*m_callback)(std::string id);

      bool m_open;

  };
}