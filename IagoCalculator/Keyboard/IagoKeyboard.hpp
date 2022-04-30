#include "../../interface.h"

class IagoKeyboard: public Keyboard{
  Key* keys[100];
  int keysCounter = 0;
  
   public:
      void addKey(Key* );
      void receiveDigit(Digit );
      void receiveOperation(Operation );
      void receiveControl(Control );
};

// class IagoKey:public Key{
//   public:
//     void press();
// };