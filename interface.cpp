#include "interface.h"
#include <iostream>

void Cpu::setDisplay(Display* display){
  this->display = display;
}

void Keyboard::setCpu(Cpu* cpu){
  this->cpu = cpu;
}

void Key::setReceiver(Receiver* receiver){
  this->receiver = receiver;
}

// ********************** KEYS ************************

//KEY DIGIT
  KeyDigit::KeyDigit(Digit digit){
    this->digit = digit;
  }

  void KeyDigit::press(){
    this->receiver?this->receiver->receiveDigit(this->digit):void();
  }

//KEY OPERATION 
  KeyOperation::KeyOperation(Operation operation){
    this->operation = operation;
  }

  void KeyOperation::press(){
    this->receiver?this->receiver->receiveOperation(this->operation):void();
  }

//KEY CONTROL
  KeyControl::KeyControl(Control control){
    this->control = control;
  }

  void KeyControl::press(){
    this->receiver?this->receiver->receiveControl(this->control):void();
  }