#include "../../interface.h"

class IagoCpu: public Cpu{
  
  //INT
  int countDecimalSeparator;
  int is_true_DecimalSeparator;
  int operationCounter;
  int operation;      
  int countDigits;
  int count_equal;
  int memory_disc;
  int control_mrc;
  int is_integer;
  
  //FLOAT
  float operation1;
  float operation2;
  float memo;
  float memory;
  float memo1;
  float memo2;
  
  //CHAR
  char digit;
  char firstOperation[9];
  char secondOperation[9];
  
  //BOOL
  bool decimal_separator;
  bool control_operation;
  bool control_equal;

  Operation store_operation;
  Signal signal;
  Operation receive_operation;

  //FUNÇÕES AUXILIARES
  char digitToChar(Digit );
  float charToFloat(char* );
  void floatToChar(float);
  void convertResultToDigit(float );

  public:
    IagoCpu();
    void receiveDigit(Digit );
    void receiveOperation(Operation );
    void receiveControl(Control );
};

