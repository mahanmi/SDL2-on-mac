#!/bin/bash
ln -s /opt/homebrew/Cellar/sdl2/*/lib lib/sdl2
ln -s /opt/homebrew/Cellar/sdl2_image/*/lib lib/sdl2_image
ln -s /opt/homebrew/Cellar/sdl2_ttf/*/lib lib/sdl2_ttf
ln -s /opt/homebrew/Cellar/sdl2_mixer/*/lib lib/sdl2_mixer
ln -s /opt/homebrew/Cellar/sdl2_gfx/*/lib lib/sdl2_gfx
echo "Done linking SDL2 libraries"
