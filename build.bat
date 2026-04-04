@echo off
cd /d "%~dp0"
set PATH=C:\Program Files\CodeBlocks\MinGW\bin;%PATH%
echo === BUILDING WORDSCAPES ===

g++ -g -std=c++17 ^
  src\main.cpp ^
  core\Game.cpp ^
  core\Input.cpp ^
  core\TextureManager.cpp ^
  puzzle\Grid.cpp ^
  puzzle\LetterWheel.cpp ^
  puzzle\Level.cpp ^
  puzzle\WordValidator.cpp ^
  ui\Button.cpp ^
  ui\Menu.cpp ^
  ui\HUD.cpp ^
  data\LevelLoader.cpp ^
  -o game.exe ^
  -IC:\SDL_LIBRARIES\include ^
  -LC:\SDL_LIBRARIES\lib ^
  -lSDL3 -lSDL3_ttf

if %ERRORLEVEL% EQU 0 (
    echo === BUILD THANH CONG! ===
    echo Chay game.exe de choi...
) else (
    echo === BUILD LOI! ===
)
pause
