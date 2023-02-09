#pragma once

#include "CustomUI.h"

namespace CUI{
  class IWidget{
    public:
      virtual void tick(vex::brain* b, bool clicked) = 0;
      virtual void render(vex::brain* b, double dt) = 0;

      virtual void setPosition(Vec2 pos) = 0;
      virtual void setSize(Size2 size) = 0;
  };
}