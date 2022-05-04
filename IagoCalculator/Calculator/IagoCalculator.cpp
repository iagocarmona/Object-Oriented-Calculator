#include "IagoCalculator.hpp"

//******************************************************************
//               SETTING DISPLAY ON CALCULATOR                     *
//******************************************************************

  void IagoCalculator::setDisplay(Display* display){
    this->display = display;
  }

//******************************************************************
//               SETTING CPU ON CALCULATOR                     *
//******************************************************************

  void IagoCalculator::setCpu(Cpu* cpu){
    this->cpu = cpu;
  }

//******************************************************************
//               SETTING KEYBOARD ON CALCULATOR                     *
//******************************************************************

  void IagoCalculator::setKeyboard(Keyboard* keyboard){
    this->keyboard = keyboard;
  }
