#pragma once

#include "../CustomUI.h"


namespace CUI{
  extern bool inRect(CUI::Vec2 point, CUI::Rect rect);
  extern Size2 calcTextBounds(std::string text);

  //converts normalized coords to coordinates 0-1
  //x:0 y:0 is the center of the screen with normalCoords
  extern Vec2 normalCoords(float x, float y);

  //convert a centralized rect into corner based use for inputing to functions that take centralized coords
  //use it to convert to corner based rect coords
  extern Rect cornerRect(Rect rect);

  extern void printCenteredTextInRect(Rect rect, std::string text);
  //used to convert centralized coordinates to corner based
  extern void centralRectToCorner(Rect *rect);
}
