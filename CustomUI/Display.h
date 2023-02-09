#pragma once
#include "CustomUI.h"

#define SCREEN_WIDTH 480
#define SCREEN_HEIGHT 240

#define FPS_PLUS_1000 1001

enum CUIDisplayFlags{
  CUIDisplayFlags_NON_BLOCKING = BIT(0)
};

namespace CUI{
  class Display : public BaseThread{
    public:
      Display(vex::brain* b, int flags = 0);

      void setFont(fontType f) {m_brain->Screen.setFont(f);};

      //returns msec frame time
      int getFrameTime();
      //returns fps
      int getFPS();

      void swapCanvas(Canvas *canvas);

      void init();
      void shutdown();

      void addWidget(CUI::IWidget* widget);

    protected:
      void run() override;
    private:
      void genFrame();

      Canvas *m_canvas;

      int m_flags;

      double m_deltaTime;

      bool m_running;

      bool m_holding;
      bool m_clicked;

      double m_frameTime;

      vex::brain* m_brain;

      std::vector<CUI::IWidget*> m_widgets;

  };
}