@echo off
cd /d "%~dp0"
set PATH=C:\msys64\ucrt64\bin;%PATH%

echo === DANG BUILD GAME WORDSCAPES ===

g++ -g -std=c++17 ^
  src/main.cpp ^
  core/Game.cpp ^
  core/Input.cpp ^
  core/TextureManager.cpp ^
  puzzle/Grid.cpp ^
  puzzle/LetterWheel.cpp ^
  puzzle/Level.cpp ^
  puzzle/WordValidator.cpp ^
  ui/Button.cpp ^
  ui/Menu.cpp ^
  ui/HUD.cpp ^
  data/LevelLoader.cpp ^
  -o game.exe ^
  -I"C:/msys64/ucrt64/include" ^
  -L"C:/msys64/ucrt64/lib" ^
  -lSDL3_image -lSDL3_ttf -lSDL3

if %ERRORLEVEL% EQU 0 (
    echo ---------------------------------------
    echo === BUILD THANH CONG! ===
    .\game.exe
) else (
    echo === BUILD LOI ===
)
pause