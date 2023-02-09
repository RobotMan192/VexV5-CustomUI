#pragma once

/*
  Description:
    A UI Library for creating custom UI on vex v5 brains
  
  Dependencies:
    auto generated vex.h file

  Version: 1.0

  Written By: Connor Axtell
*/

#define BIT(x) (1 << x)

#define IN_RANGE(x,min,max) (x>=min&&x<=max)
#define PRINTMSG(s) printf("Custom UI: %s\n",s)

#include "vex.h"
#include <vector>

#include "CustomUITypes.h"

#include "util/CustomUIUtil.h"
#include "util/BaseThread.h"

#include "IWidget.h"
#include "Canvas.h"
#include "Display.h"

#include "widgets/Button.h"
#include "widgets/ComboBox.h"
#include "widgets/TextBox.h"