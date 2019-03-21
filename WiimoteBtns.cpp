#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <iostream>
#include "WiimoteBtns.h"
#include "RoboticArm.h"

WiimoteBtns::WiimoteBtns(){
      fd = open("/dev/input/event2", O_RDONLY);
      if (fd == -1){
          std::cerr << "Error: Could not open event file - forgot sudo?\n";
          exit(1);
       }
    };
WiimoteBtns::~WiimoteBtns(){
      close(fd);
    };

NumStorage::NumStorage() {
u = 90;
v = 90;
w = 90;
x = 90;
y = 90;
}



      
void WiimoteBtns::Listen(){
NumStorage num = NumStorage();
WiimoteAccel wii;
      while (true){
         // Read a packet of 32 bytes from Wiimote
         char buffer[32];
         read(fd, buffer, 32);

         // Extract code (byte 10) and value (byte 12) from packet
         int code = buffer[10];
         int value = buffer[12];
         //Call function to print code and value
         ButtonEvent(code, value, num);
         wii.Listen(num);
      }
    };
    
    
void NumStorage::set(int a, int b, int c, int d, int e) {
     u = a;
     v = b;
     w = c;
     x = d;
     y = e;
}    
 
 
 
 
WiimoteAccel::WiimoteAccel(){
        fd = open("/dev/input/event0", O_RDONLY);
        if (fd == -1){
         std::cerr << "Error: Could not open event file - forgot sudo?\n";
         exit(1);
        }
      };
WiimoteAccel::~WiimoteAccel(){
        close(fd);
      }
void WiimoteAccel::Listen(NumStorage num){
           for (int x = 0; x <= 1; x++){
            // Read a packet of 16 bytes from Wiimote
           char buffer[16];
           read(fd, buffer, 16);

           // Extract code (byte 10) and value (byte 12) from packet
           int code = buffer[10];
           short acceleration = * (short *) (buffer + 12);
           //Call function to print code and acceleration
           AccelerationEvent(code, acceleration, num);}
      }; 
      
int arr[5] = {90, 90, 90, 90, 90};  

void WiimoteAccel::AccelerationEvent(int code, short acceleration, NumStorage n){
         std::cout << "Code = " << code <<", acceleration = " << acceleration << '\n';
         RoboticArm roboticarm;
         
         if (acceleration > 95 && (code == 4 || code == 5)) {
          roboticarm.MoveServo(4, 60, 180);
          roboticarm.MoveServo(0, 60, arr[0]);
          roboticarm.MoveServo(1, 60, arr[1]);
          roboticarm.MoveServo(2, 60, arr[2]);
          roboticarm.MoveServo(3, 60, arr[3]);
          n.set(n.u, n.v, n.w, n.x, 180);
          arr[0] = n.u;
          arr[1] = n.v;
          arr[2] = n.w;
          arr[3] = n.x;
          arr[4] = 180;
         }
         else if (acceleration < -95 && code == 0) {
          roboticarm.MoveServo(4, 60, 0);
          roboticarm.MoveServo(0, 60, arr[0]);
          roboticarm.MoveServo(1, 60, arr[1]);
          roboticarm.MoveServo(2, 60, arr[2]);
          roboticarm.MoveServo(3, 60, arr[3]);
          n.set(n.u, n.v, n.w, n.x, 0);
          arr[0] = n.u;
          arr[1] = n.v;
          arr[2] = n.w;
          arr[3] = n.x;
          arr[4] = 0;
         }
         
         else {
          roboticarm.MoveServo(0, 60, arr[0]);
          roboticarm.MoveServo(1, 60, arr[1]);
          roboticarm.MoveServo(2, 60, arr[2]);
          roboticarm.MoveServo(3, 60, arr[3]);
          roboticarm.MoveServo(4, 60, arr[4]);}
      };
      
      
      
    
 
 
 void WiimoteBtns::ButtonEvent(int code, int value, NumStorage num){
 int A;
 int B;
 int U;
 int D;
 int L;
 int R;
 int M;
 int P;
 int H;
 int O;
 int T;
 RoboticArm roboticarm;
 A = 48;
 B = 49;
 U = 103;
 D = 108;
 L = 105;
 R = 106;
 M = 156;
 P = 151;
 H = 60;
 O = 1;
 T = 2;
 
 
       std::cout << "Code = " << code << ", value = " << value << '\n';
       
       if (code == A && value == 1 && arr[0] < 180){
          arr[0] = arr[0] + 5;
          roboticarm.MoveServo(0, 60, arr[0]);
          roboticarm.MoveServo(1, 60, arr[1]);
          roboticarm.MoveServo(2, 60, arr[2]);
          roboticarm.MoveServo(3, 60, arr[3]);
          roboticarm.MoveServo(4, 60, arr[4]);
          num.set(arr[0], arr[1], arr[2], arr[3], arr[4]);
   
          std::cout << "1: " << arr[0] << " " << arr[1] << " " << arr[2] << " " << arr[3] << " " << arr[4] << '\n';
          }
       
       else if (code == B && value == 1 && arr[0] > 0){
          arr[0] = arr[0] - 5;
          roboticarm.MoveServo(0, 60, arr[0]);
          roboticarm.MoveServo(1, 60, arr[1]);
          roboticarm.MoveServo(2, 60, arr[2]);
          roboticarm.MoveServo(3, 60, arr[3]);
          roboticarm.MoveServo(4, 60, arr[4]);
          num.set(arr[0], arr[1], arr[2], arr[3], arr[4]);
    
           std::cout << "2: " << arr[0] << " " << arr[1] << " " << arr[2] << " " << arr[3] << " " << arr[4] << '\n';
          }
          
       else if (code == U && value == 1 && arr[1] < 180){
          arr[1] = arr[1] + 5;
          roboticarm.MoveServo(1, 60, arr[1]);
          roboticarm.MoveServo(0, 60, arr[0]);
          roboticarm.MoveServo(2, 60, arr[2]);
          roboticarm.MoveServo(3, 60, arr[3]);
          roboticarm.MoveServo(4, 60, arr[4]);
          num.set(arr[0], arr[1], arr[2], arr[3], arr[4]);
     
           std::cout << "3: " << arr[0] << " " << arr[1] << " " << arr[2] << " " << arr[3] << " " << arr[4] << '\n';
          }
       
       else if (code == D && value == 1 && arr[1] > 0){
          arr[1] = arr[1] - 5;
          roboticarm.MoveServo(1, 60, arr[1]);
          roboticarm.MoveServo(0, 60, arr[0]);
          roboticarm.MoveServo(2, 60, arr[2]);
          roboticarm.MoveServo(3, 60, arr[3]);
          roboticarm.MoveServo(4, 60, arr[4]);
          num.set(arr[0], arr[1], arr[2], arr[3], arr[4]);

           std::cout << "4: " << arr[0] << " " << arr[1] << " " << arr[2] << " " << arr[3] << " " << arr[4] << '\n';
          }
          
       else if (code == L && value == 1 && arr[2] < 180){
          arr[2] = arr[2] + 5;
          roboticarm.MoveServo(2, 60, arr[2]);
          roboticarm.MoveServo(1, 60, arr[1]);
          roboticarm.MoveServo(0, 60, arr[0]);
          roboticarm.MoveServo(3, 60, arr[3]);
          roboticarm.MoveServo(4, 60, arr[4]);
          num.set(arr[0], arr[1], arr[2], arr[3], arr[4]);
    
           std::cout << "5: " << arr[0] << " " << arr[1] << " " << arr[2] << " " << arr[3] << " " << arr[4] << '\n';
          }
       
       else if (code == R && value == 1 && arr[2] >= 0 ){
          arr[2] = arr[2] - 5;
          roboticarm.MoveServo(2, 60, arr[2]);
          roboticarm.MoveServo(1, 60, arr[1]);
          roboticarm.MoveServo(0, 60, arr[0]);
          roboticarm.MoveServo(3, 60, arr[3]);
          roboticarm.MoveServo(4, 60, arr[4]);
          num.set(arr[0], arr[1], arr[2], arr[3], arr[4]);

           std::cout << "6: " << arr[0] << " " << arr[1] << " " << arr[2] << " " << arr[3] << " " << arr[4] << '\n';
          }
          
       else if (code == P && value == 1 && arr[3] < 180){
          arr[3] = arr[3] + 5;
          roboticarm.MoveServo(3, 60, arr[3]);
          roboticarm.MoveServo(1, 60, arr[1]);
          roboticarm.MoveServo(2, 60, arr[2]);
          roboticarm.MoveServo(0, 60, arr[0]);
          roboticarm.MoveServo(4, 60, arr[4]);
          num.set(arr[0], arr[1], arr[2], arr[3], arr[4]);
   
           std::cout << "7: " << arr[0] << " " << arr[1] << " " << arr[2] << " " << arr[3] << " " << arr[4] << '\n';
          }
       
       else if (code == M && value == 1 && arr[3] > 0){
          arr[3] = arr[3] - 5;
          roboticarm.MoveServo(3, 60, arr[3]);
          roboticarm.MoveServo(1, 60, arr[1]);
          roboticarm.MoveServo(2, 60, arr[2]);
          roboticarm.MoveServo(0, 60, arr[0]);
          roboticarm.MoveServo(4, 60, arr[4]);
          num.set(arr[0], arr[1], arr[2], arr[3], arr[4]);
        
           std::cout << "8: " << arr[0] << " " << arr[1] << " " << arr[2] << " " << arr[3] << " " << arr[4] << '\n';
          }
          
       else if (code == O && value == 1 && arr[4] < 180){
          arr[4] = arr[4] + 5;
          roboticarm.MoveServo(4, 60, arr[4]);
          roboticarm.MoveServo(1, 60, arr[1]);
          roboticarm.MoveServo(2, 60, arr[2]);
          roboticarm.MoveServo(3, 60, arr[3]);
          roboticarm.MoveServo(0, 60, arr[0]);
          num.set(arr[0], arr[1], arr[2], arr[3], arr[4]);
      
           std::cout << "9: " << arr[0] << " " << arr[1] << " " << arr[2] << " " << arr[3] << " " << arr[4] << '\n';
          }
       
       else if (code == T && value == 1 && arr[4] > 0 && arr[4] <= 180){
          arr[4] = arr[4] - 5;
          roboticarm.MoveServo(4, 60, arr[4]);
          roboticarm.MoveServo(1, 60, arr[1]);
          roboticarm.MoveServo(2, 60, arr[2]);
          roboticarm.MoveServo(3, 60, arr[3]);
          roboticarm.MoveServo(0, 60, arr[0]);
          num.set(arr[0], arr[1], arr[2], arr[3], arr[4]);
          
           std::cout << "10: " << arr[0] << " " << arr[1] << " " << arr[2] << " " << arr[3] << " " << arr[4] << '\n';
          }
          
       
       else if (code == H && value == 1){
          arr[0] = 90;
          arr[1] = 90;
          arr[2] = 90;
          arr[3] = 90;
          arr[4] = 90;
          roboticarm.MoveServo(0, 100, arr[0]);
          roboticarm.MoveServo(1, 100, arr[1]);
          roboticarm.MoveServo(2, 100, arr[2]);
          roboticarm.MoveServo(3, 100, arr[3]);
          roboticarm.MoveServo(4, 100, arr[4]);
          num.set(arr[0], arr[1], arr[2], arr[3], arr[4]);
         
          std::cout << "11: " << arr[0] << " " << arr[1] << " " << arr[2] << " " << arr[3] << " " << arr[4] << '\n';
          }
          
       else {
          roboticarm.MoveServo(0, 60, arr[0]);
          roboticarm.MoveServo(1, 60, arr[1]);
          roboticarm.MoveServo(2, 60, arr[2]);
          roboticarm.MoveServo(3, 60, arr[3]);
          roboticarm.MoveServo(4, 60, arr[4]);
          
          }
    };