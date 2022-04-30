#include "IagoCalculator.hpp"

  void IagoCalculator::setDisplay(Display* display){
    this->display = display;
  }

  void IagoCalculator::setCpu(Cpu* cpu){
    this->cpu = cpu;
  }

  void IagoCalculator::setKeyboard(Keyboard* keyboard){
    this->keyboard = keyboard;
  }
