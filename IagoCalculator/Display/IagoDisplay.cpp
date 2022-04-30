#include <iostream>
#include "IagoDisplay.hpp"

  void IagoDisplay::add(Digit digit){
    if(this->countDigits < 8){
      switch (digit){
      case ZERO: std::cout << "0"; break;
      case ONE: std::cout << "1"; break;
      case TWO: std::cout << "2"; break;
      case THREE: std::cout << "3"; break;
      case FOUR: std::cout << "4"; break;
      case FIVE: std::cout << "5"; break;
      case SIX: std::cout << "6"; break;
      case SEVEN: std::cout << "7"; break;
      case EIGHT: std::cout << "8"; break;
      case NINE: std::cout << "9"; break;
      this->countDigits++;
      }
    }
  }

  void IagoDisplay::setDecimalSeparator(){
      std::cout << ".";
  }

  void IagoDisplay::setSignal(Signal signal){
    if(NEGATIVE) std::cout << "-"; 
  }

  void IagoDisplay::setError(){
    this->clear();
    std::cout << "E";
  }

  void IagoDisplay::clear(){
    this->countDigits = 0;
    std::cout << "\n";
    std::cout << "\n";
    std::cout << "\n";
    std::cout << "\n";
    std::cout << "\n";
    std::cout << "\n";
    std::cout << "\n";
    std::cout << "\n";
  }