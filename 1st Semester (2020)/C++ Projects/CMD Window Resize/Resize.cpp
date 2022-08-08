#include <windows.h>

int main(){
  system("mode 160,50");   //Set mode to ensure window does not exceed buffer size
  SMALL_RECT WinRect = {0, 0, 160, 50};   //New dimensions for window in 8x12 pixel chars
  SMALL_RECT* WinSize = &WinRect;
  SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), true, WinSize);   //Set new size for window

  //Insert your code here
  system("pause");

  return 0;
}
