#include "header.h"

int main_menu(void)
{
  
  printw("Hephaestus 0.1 ©2020");
  attron(A_UNDERLINE);
  mvprintw(15, 50, "MAIN MENU");
  attroff(A_UNDERLINE);
  mvprintw(17, 50, "Open/View List");
  mvprintw(18, 50, "Forge New List");
  mvprintw(19, 50, "Delete List");
  mvprintw(20, 50, "Exit");
  return (0);
}

int main_menu2(void)
{
  char arr[4][15] =
    {
      "Open/View List",
      "Forge New List",
      "Delete List",
      "Exit"
    };
  int choice;
  int highlight = 0;

  printw("Hephaestus 0.1 ©2020");
  WINDOW * menwin = newwin(12, 30, 10, 40);
  box(menwin, 0, 0);
  refresh();
  wrefresh(menwin);
  keypad(menwin, true);
  while(1)
    {
      wattron(menwin, A_UNDERLINE);
      mvwprintw(menwin, 3, 7, "MAIN MENU");
      wattroff(menwin, A_UNDERLINE);
	  for(int i = 0; i < 3; i++)
	    {
	      if (i == highlight)
		wattron(menwin, A_REVERSE);
	      mvwprintw(menwin, 5 + i, 7, arr[i]);
	      wattroff(menwin, A_REVERSE);
	    }
	  choice = wgetch(menwin);

	  switch(choice)
	    {
	    case KEY_UP:
	      highlight--;
	      if (highlight == -1)
		highlight = 0;
	      break;
	    case KEY_DOWN:
	      highlight++;
	      if (highlight == 3)
		highlight = 2;
	      break;
	    default:
	      break;
	    }
	  if (choice == 10)
	    break;
	}
      printw("Your choice was: %s", arr[highlight]);
      endwin();
}

