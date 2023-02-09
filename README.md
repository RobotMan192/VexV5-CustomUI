# VexV5-CustomUI
A library to help with creating GUI for VexV5 brains

## Installation
1. Install the library by creating a new folder called "lib" in your project directory
2. Drag and drop the CustomUI directory into it
3. Update your projects makefile by adding the following code


```makefile
SRC_C += $(wildcard lib/*/*.cpp)
SRC_C += $(wildcard lib/*/*/*.cpp)

SRC_H  += $(wildcard lib/*/*.h)
SRC_H  += $(wildcard lib/*/*/*.h)
```


## Example

Include the CustomUI header in your file that you are going to use it

```C++
#include "../lib/CustomUI/CustomUI.h"
```

Create a display this is where you will add widgets

```C++
CUI::Display display(&Brain);
```

In the main function add a button

```C++
CUI::Button randomButton("Press Me",CUI::ButtonStyle{},CUI::Rect(4,4,100,25),[](){
  printf("Button Clicked\n");
});
```
Connect the button to the display

```C++
display.addWidget(&randomButton);
```

Initialize the display

```C++
display.init();
```


### Final Code:
```C++
int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  
  CUI::Display display(&Brain);
  
  CUI::Button randomButton("Press Me",CUI::ButtonStyle{},CUI::Rect(4,4,100,25),[](){
    printf("Button Clicked\n");
  });
  
  display.addWidget(&randomButton);
  
  display.init();
}
```
