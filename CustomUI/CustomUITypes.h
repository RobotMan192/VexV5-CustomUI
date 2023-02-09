#pragma once

namespace CUI{
  //forward declarations
  
  struct Vec2;
  struct Rect;
  struct Size2;
  struct Circle;
  
  class IWidget;

  class Canvas;
  class Display;
  class Button;
  class ComboBox;

  //types
  struct Vec2{
    Vec2(){

    }

    Vec2(int _x, int _y){
      x = _x;
      y = _y;
    }

    int x;
    int y;
  };

  struct Size2{
    Size2(){

    }

    Size2(int _width, int _height){
      width = _width;
      height = _height;
    }

    int width;
    int height;
  };

  struct Rect{
    Rect(){

    }

    Rect(Vec2 pos, int _width, int _height){
      x = pos.x;
      y = pos.y;
      width = _width;
      height = _height;
    }

    Rect(int _x, int _y, int _width, int _height){
      x = _x;
      y = _y;
      width = _width;
      height = _height;
    }

    int x;
    int y;
    int width;
    int height;
  };

  struct Circle{
    Circle(){
      
    }

    Circle(int _x, int _y, int _radius){
      x = _x;
      y = _y;
      radius = _radius;
    }

    int x;
    int y;
    int radius;
  };
  
}