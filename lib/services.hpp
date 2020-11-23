#ifndef SYMBOL_services_1601875909
#define SYMBOL_services_1601875909
#include <vector>
#include <random>
#include <chrono>
#include <iomanip>
#include<bits/stdc++.h>
#include <iostream>
#include<stdlib.h>
#include <pthread.h>
using namespace std;

string NONE_SYMBOL = "*";
pthread_mutex_t* consoleLock = new pthread_mutex_t;

void initGlobalVariables() {
   pthread_mutex_init(consoleLock, NULL);
}

void destroyGlobalVariables() {
   pthread_mutex_destroy(consoleLock);
}

vector<string>* split(string* line, const char* spl) {
   vector<string>* vec = new vector<string>;
   char* token;
   char str[line->size()];
   strcpy(str, line->c_str());
   token = strtok(str, spl);
   while (token != NULL) {
      vec->push_back(token);
      token = strtok(NULL, spl);
   }
   return vec;
}

minstd_rand0 generator(chrono::system_clock::now().time_since_epoch().count());

enum constants { DELIMETER = '~', EMPTY = ' ' };
const unsigned horizWidth = 20;
const unsigned vertiWidth = 7;

const void horizDiv(char fill) {
   cout << left << setw(horizWidth) << setfill(fill) << "";
   cout << setfill(' ');
}

const void vertiDiv(char fill) {
   cout << left << setw(vertiWidth) << setfill(fill) << "|";
   cout << setfill(' ');
}

const void partition(unsigned size, char ch, bool hasVerti = true) {
   for (unsigned i = 0; i < size; ++i) {
      if (hasVerti) vertiDiv(ch);
      horizDiv(ch);
   }
}
enum possibleColors {
   WHITE, BOLD, GREY, ITALIC, UNDERLINE, BG_GREY = 7,MAGENTA=35,BG_MAGENTA=45,
   BLACK = 30, RED, GREEN, ORANGE, BLUE=94, PINK, PURPLE,CYAN=36,
   BG_BLACK = 40, BG_RED, BG_GREEN, BG_ORANGE, BG_BLUE, BG_PINK, BG_PURPLE,BG_WHITE=107,BG_BrightYellow=103,BrightYellow=93  
};

class ColorPalette {

private:
   static vector<possibleColors>* colorStack;

public:
   static void add(possibleColors col) {
      colorStack->push_back(col);
      cout << "\033[" << col << "m";
   }

   static void remove() {
      colorStack->pop_back();
      cout << "\033[" << ((colorStack->size() == 0) ? WHITE : colorStack->back()) << "m";
   }

   static void clear() {
      colorStack->clear();
      cout << "\033[m";
      
   }

};
vector<possibleColors>* ColorPalette::colorStack = new vector<possibleColors>;
#endif