#pragma once
#include "CustomUI.h"

namespace CUI{
  //A canvas can be used to store widgets and can be changed in the display
  //Only the active canvas ticks and renders
  class Canvas{
    public:

      void addWidget(IWidget* widget);

      void tickWidgets(brain* b, bool clicked);
      void renderWidgets(brain* b, double dt);

    private:
      std::vector<IWidget*> m_widgets;
  };
}