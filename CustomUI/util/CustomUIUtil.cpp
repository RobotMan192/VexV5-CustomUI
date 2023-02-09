#include "CustomUIUtil.h"

namespace CUI{
  bool inRect(CUI::Vec2 point, CUI::Rect rect){
    if(IN_RANGE(point.x, rect.x, rect.x + rect.width) && IN_RANGE(point.y, rect.y, rect.y + rect.height)){
      return true;
    }
    return false;
  }

  Size2 calcTextBounds(std::string text){
    Size2 bounds;
    bounds.width = vexDisplayStringWidthGet(text.c_str());
    bounds.height = vexDisplayStringHeightGet(text.c_str())/2;
    
    return bounds;
  }

  Vec2 normalCoords(float x, float y){
    Vec2 pos;
    pos.x = SCREEN_WIDTH*(.5+(.5*x));
    pos.y = SCREEN_HEIGHT*(.5+(.5*y));
    return pos;
  }

  Rect cornerRect(Rect rect){
    rect.x += rect.width/2;
    rect.y += rect.height/2;
    return rect;
  }

  void printCenteredTextInRect(Rect rect, std::string text){
    Size2 r = calcTextBounds(text);
    
    int tCenterX = (rect.x - r.width/2);
    int tCenterY = (rect.y + r.height/2);
  
    vexDisplayPrintf(tCenterX + rect.width/2, tCenterY + rect.height/2, false, text.c_str());
  }
  
  void centralRectToCorner(Rect *rect){
    rect->x -= rect->width/2;
    rect->y -= rect->height/2;
  }

}