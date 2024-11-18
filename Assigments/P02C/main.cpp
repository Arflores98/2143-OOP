#include "buttonClass.hpp"
#include "colors.hpp"
#include "diceClass.hpp"
#include "gridClass.hpp"
#include "logger.hpp" // Logger utility
#include <fstream>    // File I/O
#include <iostream>   // Input/Output
#include <locale.h>
#include <map>       // Map data structure
#include <ncurses.h> // Ncurses library
#include <string>    // String data structure
#include <vector>    // Vector data structure\
#include <ctime>

using namespace std;

class InputHandler {
  int x;
  int y;
  bool leftClick;
  bool rightClick;

public:
  InputHandler() {
    x = 0;
    y = 0;
    leftClick = false;
    rightClick = false;
  }

  bool quit(int ch) { return ch == 'q'; }
  bool clicked(int ch) {
    MEVENT event;
    if (ch == KEY_MOUSE) {
      if (getmouse(&event) == OK) {
        if (event.bstate & BUTTON1_CLICKED) {
          leftClick = true;
        } else if (event.bstate & BUTTON2_CLICKED) {
          rightClick = true;
        }
        y = event.y;
        x = event.x;
      }
    }
  }
  bool backspace(int ch) { return (ch == KEY_BACKSPACE || ch == 127); }
};


class Ncursed {
  int height;
  int width;

public:
  Ncursed() { init(); }
  void init() {
    setlocale(LC_ALL, ""); // Enable Unicode support

    initscr(); // Start ncurses mode
    // Get terminal size
    getmaxyx(stdscr, height, width);
    noecho();                          // Don't echo input
    cbreak();                          // Disable line buffering
    curs_set(0);                       // Hide the cursor
    start_color();                     // enable colors in ncurses
    keypad(stdscr, TRUE);              // enable keypad for special keys
    mousemask(ALL_MOUSE_EVENTS, NULL); // enable mouse events
  }
  int getWidth() { return width; }
  int getHeight() { return height; }
};

int main() {
  srand(time(0));

  Ncursed ncursed;


  int width = ncursed.getWidth();
  int height = ncursed.getHeight();

  int x, y;
  string str;
  int color;

  colorful(); // my custom color class to create many colors

  clear();   // clear screen to prevent scrolling
  refresh(); // refresh / redraw screen

  Button button("ROLL", 32, 5, Frame({3, 10, height - 4, width / 2 - 4}));
  button.draw_button();

  DiceViz diceviz(height - 12, width / 2 - 4);
  diceviz.setDotColor(5);
  diceviz.setBorderColor(11);

  color = rand() % 32 + 1;
  Colorly::setColor(13);
  Colorly::colorOn();
  // mvprintw(height / 4, (width - 50) / 2,
  //          "This is a basic skeleton for a ncurses program\n");
  Colorly::colorOff();

  Grid grid((height / 2) - 2, (width / 2) - 5, 6, 9);

  while (true) {
    int ch = getch();
    if (input.quit(ch)) {
      break;
    }
    if (input.clicked()) {
    }
    if (input.backspace(ch)) {
    }

    Colorly::randColor();
    Colorly::colorOn();
    Logger::printLastLine(stdscr);
    Colorly::colorOff();
    refresh();
  }

  // Wait for a key press before exiting
  // getch();
  endwin(); // End ncurses mode

  return 0;
}