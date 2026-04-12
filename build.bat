@echo off
setlocal enabledelayedexpansion
cd /d "%~dp0"

set MSYS2_PATH=C:\msys64\ucrt64
set PATH=%MSYS2_PATH%\bin;%PATH%

echo === DANG BUILD GAME WORDSCAPES ===

:: Kiem tra va copy DLL neu thieu
echo Checking for required DLLs...
set "DLLS=SDL3.dll SDL3_image.dll SDL3_ttf.dll libgcc_s_seh-1.dll libstdc++-6.dll libwinpthread-1.dll"
for %%D in (%DLLS%) do (
    if not exist "%%D" (
        if exist "%MSYS2_PATH%\bin\%%D" (
            echo Copying %%D from MSYS2...
            copy "%MSYS2_PATH%\bin\%%D" . >nul
        ) else (
            echo WARNING: %%D not found in MSYS2 bin folder.
        )
    )
)

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
  -I"%MSYS2_PATH%/include" ^
  -L"%MSYS2_PATH%/lib" ^
  -lSDL3_image -lSDL3_ttf -lSDL3

if %ERRORLEVEL% EQU 0 (
    echo ---------------------------------------
    echo === BUILD THANH CONG! ===
    echo Game dang khoi chay...
    .\game.exe
) else (
    echo === BUILD LOI ===
    pause
)