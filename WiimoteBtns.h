#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <iostream>

class NumStorage {
public:
void set(int a, int b, int c, int d, int e);
int u, v, w, x, y;
NumStorage();
};

;
class WiimoteBtns {
  //Open Wiimote file
  int fd;
  public:
    WiimoteBtns();
    ~WiimoteBtns();
    void Listen();
    void ButtonEvent(int code, int value, NumStorage num);
};

class WiimoteAccel{
    //Open Wiimote file
    int fd;
    public:
      WiimoteAccel();
      ~WiimoteAccel();
      void Listen(NumStorage num);
      void AccelerationEvent(int code, short acceleration, NumStorage num);
};