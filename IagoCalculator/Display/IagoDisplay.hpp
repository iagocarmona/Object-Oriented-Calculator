#include "../../interface.h"

class IagoDisplay: public Display{
  int countDigits = 0;

  public:
    IagoDisplay();
    void add(Digit );
    void setDecimalSeparator();
    void setSignal(Signal );
    void setError();
    void clear();
};
