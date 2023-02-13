#include "Results.h"

static struct Results new(int pin[51][51], bool Continuity, bool Shielding
                          bool PinToPin, char cablename[50], char testname[60]) {
                          return (struct Results){.pi=pin, .Co=Continuity, .Sh=Shielding,
                          .PtP=PinToPin, .cn=cablename, .tn=testname};
                          }
const struct ResultsClass Results={.new=&new};