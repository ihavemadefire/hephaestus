#include "header.h"

int main(void)
{
  initscr();/*creates stdscr*/
  cbreak();
  main_menu2();
  getch();
  endwin();
  
  return (0);
}
