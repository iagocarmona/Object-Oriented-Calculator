#include "IagoCpu.hpp"
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cmath>


IagoCpu::IagoCpu(){
  this->countDecimalSeparator = 0;
  this->is_true_DecimalSeparator = 0;
  this->operationCounter = 0;
  this->operation = 0;      
  this->countDigits = 0;
  this->count_equal = 0;
  this->memory_disc = 0;
  this->control_mrc = 0;
  this->is_integer = 0;
  
  //FLOAT
  this->operation1 = 0.0;
  this->operation2 = 0.0;
  this->memo = 0.0;
  this->memory = 0.0;
  this->memo1 = 0.0;
  this->memo2 = 0.0;
  
  //BOOL
  this->decimal_separator = false;
  this->control_equal = false;
}

//******************************************************************
//                        RECEIVE DIGIT                            *
//******************************************************************

  void IagoCpu::receiveDigit(Digit digit){  
    this->count_equal = 0;
    char digitChar = this->digitToChar(digit);

    if(this->countDigits == 0){
      this->display?this->display->clear() : void();
    }

    if(this->countDigits < 8){
      if(this->operation == 0){
        this->firstOperation[this->countDigits] = digitChar;
      } else {
        this->secondOperation[this->countDigits] = digitChar;
      }
    }

    this->display?this->display->add(digit):void();
    this->countDigits++;
  }

//******************************************************************
//                        RECEIVE OPERATION                        *
//******************************************************************

  void IagoCpu::receiveOperation(Operation op){
    this->operationCounter++;
    this->operation = 1;
    std::cout << "\n\n";
    if(op == SUBTRACTION && this->operationCounter > 1){
      this->display?this->display->setSignal(NEGATIVE): void();
    }
    if(op == SUBTRACTION && this->operationCounter == 1){
      this->display?this->display->setSignal(NEGATIVE): void();
      this->operation = 0;
    }
    if(this->countDigits != 0){
      this->store_operation = op;
    }
    this->operation1 = this->charToFloat(this->firstOperation);
    this->countDigits = 0;
    this->decimal_separator = false;
    if(this->control_operation == false){
        this->control_operation = true;
    }
    this->receive_operation = op;
    if(op == SUBTRACTION){
      this->signal = NEGATIVE;
    }
  }

//******************************************************************
//                        RECEIVE CONTROL                          *
//******************************************************************

  void IagoCpu::receiveControl(Control control){
    switch (control){
      case CLEAR: 
        this->operation = 0;
        this->display?this->display->clear(): void();
        this->countDigits = 0;
        memset(this->firstOperation, '\0', 9);
        memset(this->secondOperation, '\0', 9);
        this->decimal_separator = false;
        this->operation1 = 0;
        this->operation2 = 0;
        this->memo = 0;
        this->operation = 0;
        this->operationCounter = 0;
        break;

      case RESET: 
        this->display?this->display->clear(): void();
        this->countDigits = 0;
        memset(this->firstOperation, '\0', 9);
        memset(this->secondOperation, '\0', 9);
        this->decimal_separator = false;
        this->operation1 = 0;
        this->operation2 = 0;
        this->memo = 0;
        this->memo1 = 0;
        this->memo2 = 0;
        this->memory = 0;
        this->memory_disc = 0;
        this->operation = 0;
        this->operationCounter = 0;
        break;

      case DECIMAL_SEPARATOR:
        this->is_true_DecimalSeparator += 1;

        if(this->countDigits == 0){
          if(this->decimal_separator == false){
            if(this->operation == 0){
              this->firstOperation[this->countDigits] = '.';
            } else {
              this->secondOperation[this->countDigits] = '.';
            }
            std::cout << ".";
            this->countDigits++;
            this->decimal_separator = true;
          }
        }

        break;

      case MEMORY_READ_CLEAR: 
        this->control_mrc++;
        if(this->control_mrc >= 2){
          this->memory = 0;
          this->control_mrc = 0;
          this->memory_disc = 0;
          this->memo1 = 0;
          this->memo2 = 0;

        }
        if(this->memory_disc != 0){
          this->operation1 = (float)this->memory;
          convertResultToDigit(this->operation1);
        }

        break;

      case MEMORY_ADDITION:
        this->memo1 = atof(this->firstOperation);
        this->memo2 = atof(this->secondOperation);

        this->control_mrc = 0; 
        
        if(this->operation == 0 && this->memory_disc != 0){
          this->memory += this->operation1; 
        }
        if(this->operation == 1 && this->memory_disc != 0){
          this->memory += this->operation1; 
        }

        if(this->operation == 0 && this->memory_disc == 0 && this->memory == 0){
          this->memory = this->memo1;
          this->memory_disc ++;
        }
        
        if(this->operation == 1 && this->memory_disc == 0 && this->memory == 0){
          this->memory = this->memo2;
          this->memory_disc++;
        }

        break;

      case MEMORY_SUBTRACTION:
        this->memo1 = atof(this->firstOperation);
        this->memo2 = atof(this->secondOperation);

        this->control_mrc = 0; 
        
        if(this->operation == 0 && this->memory_disc != 0){
          this->memory -= this->operation1; 
        }
        if(this->operation == 1 && this->memory_disc != 0){
          this->memory -= this->operation1; 
        }
        if(this->operation == 0 && this->memory_disc == 0 && this->memory == 0){
          this->memory = this->memo1;
          this->memory_disc++;
        }
  
        if(this->operation == 1 && this->memory_disc == 0 && this->memory == 0){
          this->memory = this->memo2;
          this->memory_disc++;
        }
        break;

      case EQUAL:
          std::cout << "\n";
          this->operation2 = this->charToFloat(this->secondOperation);
          if(this->count_equal == 0){
            this->memo = this->operation2;
          }
          this->count_equal++;
          this->control_equal = true;

          if (this->control_equal == true){
            switch (this->receive_operation)
            {
            case ADDITION:
              this->operation1 = this->operation1 + (this->memo);
              this->operation2 = 0;
              memset(this->secondOperation, '\0', 9);
              break;

            case SUBTRACTION:
              this->operation1 = this->operation1 - (this->memo);
              this->operation2 = 0;
              memset(this->secondOperation, '\0', 9);
              break;

            case DIVISION:
              this->operation1 = this->operation1 / this->memo;
              this->operation2 = 0;
              memset(this->secondOperation, '\0', 9);
              break;

            case MULTIPLICATION:
              this->operation1 = this->operation1 * this->memo;
              this->operation2 = 0;
              memset(this->secondOperation, '\0', 9);
              break;

            case SQUARE_ROOT:
              this->operation1 = sqrt(this->operation1);
              this->operation2 = 0;
              memset(this->secondOperation, '\0', 9);
              break;

            case PERCENTAGE:
              this->operation1 = this->operation1 / 100;
              this->operation2 = 0;
              memset(this->secondOperation, '\0', 9);
              break;
            
            default:
              break;

            }}
          this->control_equal = false;
          this->operation2 = 0;
          
        this->convertResultToDigit(this->operation1);
        break;

    }
  }

//******************************************************************
//                     CONVERTING DIGIT TO CHAR                    *
//******************************************************************

  char IagoCpu::digitToChar(Digit digit){
    switch(digit){
      case ZERO: this->digit = '0';
        break;
      case ONE: this->digit = '1';
        break;
      case TWO: this->digit = '2';
        break;
      case THREE: this->digit = '3';
        break;
      case FOUR: this->digit = '4';
        break;
      case FIVE: this->digit = '5';
        break;
      case SIX: this->digit = '6';
        break;
      case SEVEN: this->digit = '7';
        break;
      case EIGHT: this->digit = '8';
        break;
      case NINE: this->digit = '9';
        break;
    }
    return this->digit;
  }

//******************************************************************
//                   CONVERTING CHAR TO FLOAT                      *
//******************************************************************

  float IagoCpu::charToFloat(char* operation){
    float num;
    num = atof(operation); 
    if (this->signal == NEGATIVE){
      num = num * -1;
      this->signal = POSITIVE;
    }
    return num;
  }

//******************************************************************
//                     CONVERTING FLOAT TO CHAR                    *
//******************************************************************

  void IagoCpu::floatToChar(float operation){
    std::sprintf(this->firstOperation,"%.3f", operation);
  }

//******************************************************************
//              CONVERTING RESULT IN FLOAT TO DIGIT                *
//******************************************************************

  void IagoCpu::convertResultToDigit(float num){
    this->floatToChar(num);
    
    this->countDigits = 0;
    std::cout << "\n";
    if(num < 0){
      this->display?this->display->setSignal(NEGATIVE): void();
    }
    char result[100];
    memset(result, '\0', 100);
    std::sprintf(result, "%g", num);
  
    for(int i = 0; i < 12; i++){
      switch(result[i]){
        case '0':
          this->display?this->display->add(ZERO): void(); 
          break;
        case '1': 
          this->display?this->display->add(ONE): void(); 
          break;
        case '2': 
          this->display?this->display->add(TWO): void(); 
          break;
        case '3': 
          this->display?this->display->add(THREE): void(); 
          break;
        case '4': 
          this->display?this->display->add(FOUR): void(); 
          break;
        case '5': 
          this->display?this->display->add(FIVE): void(); 
          break;
        case '6': 
          this->display?this->display->add(SIX): void(); 
          break;
        case '7': 
          this->display?this->display->add(SEVEN): void(); 
          break;
        case '8': 
          this->display?this->display->add(EIGHT): void(); 
          break;
        case '9': 
          this->display?this->display->add(NINE): void(); 
          break;
        case '.': 
          this->decimal_separator = false;
          this->display?this->display->setDecimalSeparator(): void(); 
          break;
    }
  }
}