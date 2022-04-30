#include "IagoKeyboard.hpp"

  void IagoKeyboard::addKey(Key* key){
    this->keys[keysCounter] = key;
    this->keysCounter++;

    key->setReceiver(this);
  }

  void IagoKeyboard::receiveDigit(Digit digit){
     this->cpu?this->cpu->receiveDigit(digit):void();
  }

  void IagoKeyboard::receiveOperation(Operation operation){
    this->cpu?this->cpu->receiveOperation(operation):void();
  }

  void IagoKeyboard::receiveControl(Control control){
    this->cpu?this->cpu->receiveControl(control):void();
  }
