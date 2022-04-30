#include "../../interface.h"

class IagoCalculator:public Calculator{ 
  Display* display;
  Cpu* cpu;
  Keyboard* keyboard;
  
  public:
    void setDisplay(Display* );
    void setCpu(Cpu* );
    void setKeyboard(Keyboard* );
};