#include <iostream>
#include <SDL.h>
#include "Screen.h"

using namespace std;
using namespace caveofprogramming;

int main()
{
   Screen screen;

   if(screen.init() == false){
      cout << "Error initializing SDL." << endl;
   }

   bool      quit = false;
   SDL_Event event;

   while (!quit)
   {
      // update particles
      // Draw particles
      // Check for messages/events
      while (SDL_PollEvent(&event))
      {
         if (event.type == SDL_QUIT)
         {
            quit = true;
         }
      }
   } 

   screen.close(); 

   return 0;
} // main
