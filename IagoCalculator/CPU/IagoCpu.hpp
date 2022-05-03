#include "../../interface.h"

class IagoCpu: public Cpu{
  
  //INT
  int countDecimalSeparator = 0;
  int is_true_DecimalSeparator = 0;
  int operationCounter = 0;
  int operation = 0;      
  int countDigits = 0;
  int count_equal = 0;
  int memory_disc = 0;
  int control_mrc = 0;
  int is_integer = 0;
  
  //FLOAT
  float operation1 = 0;
  float operation2 = 0;
  float memo = 0;
  float memory = 0;
  float memo1 = 0;
  float memo2 = 0;
  
  //CHAR
  char digit;
  char firstOperation[9];
  char secondOperation[9];
  
  //BOOL
  bool decimal_separator = false;
  bool control_operation;
  bool control_equal = false;

  Operation store_operation;
  Signal signal;
  Operation receive_operation;


  char digitToChar(Digit );
  float charToFloat(char* );
  void floatToChar(float);
  void convertResultToDigit(float );

  public:
    void receiveDigit(Digit );
    void receiveOperation(Operation );
    void receiveControl(Control );
};

