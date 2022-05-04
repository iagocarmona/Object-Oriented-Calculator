#include "IagoKeyboard.hpp"

//******************************************************************
//                 ADDING KEYS ON KEYBOARD                         *
//******************************************************************

  void IagoKeyboard::addKey(Key* key){
    this->keys[keysCounter] = key;
    this->keysCounter++;

    key->setReceiver(this);
  }

//******************************************************************
//            RECEIVING THE DIGIT TO PASS TO CPU                   *
//******************************************************************

  void IagoKeyboard::receiveDigit(Digit digit){
     this->cpu?this->cpu->receiveDigit(digit):void();
  }

//******************************************************************
//            RECEIVING THE OPERATION TO PASS TO CPU               *
//******************************************************************

  void IagoKeyboard::receiveOperation(Operation operation){
    this->cpu?this->cpu->receiveOperation(operation):void();
  }

//******************************************************************
//            RECEIVING THE CONTROL KEYS TO PASS TO CPU            *
//******************************************************************

  void IagoKeyboard::receiveControl(Control control){
    this->cpu?this->cpu->receiveControl(control):void();
  }
