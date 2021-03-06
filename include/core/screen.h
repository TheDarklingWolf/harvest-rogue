/*
    harvest-rogue is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    harvest-rogue is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with harvest-rogue.  If not, see <http://www.gnu.org/licenses/>.     */

#ifndef HARVEST_ROGUE_SCREEN_H
#define HARVEST_ROGUE_SCREEN_H

#include <memory>
#include <string>
#include "tiles.h"
#include "colors.h"

class Screen {
private:
   Screen();

   Screen(Screen const &) { };

   Screen &operator=(Screen const &) { };
public:
   ~Screen();

   static Screen &Get() {
      static Screen screen;
      return screen;
   }

   int GetWidth();

   int GetHeight();

   void WriteText(int x, int y, std::string text, Color::Color color = Color::White);

   void WriteCenterText(int y, std::string text, Color::Color color = Color::White);

   void WriteButton(int x, int y, int width, std::string text, bool active);

   void ClearLine(int y, Color::Color color = Color::White);

   void WriteCharacter(int x, int y, const char character, Color::Color color = Color::White);

   void WriteTile(int x, int y, int tileIndex, char character, Color::Color color);

   void BeginScreenUpdate();

   void EndScreenUpdate();

   void WriteWindow(int x, int y, int width, int height, std::string text = "");
};


#endif //HARVEST_ROGUE_SCREEN_H

