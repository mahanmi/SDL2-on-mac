# SDL for mac

This repository is for Mac users who want to use SDL on Mac with VS Code (both Intel and Apple ARM compatible).

## Requirements

### Homebrew

- You need to have **Homebrew** installed on your Mac. If you don't have it, you can install Homebrew from [here](https://brew.sh/).
  Then, you need to install **SDL2** and **SDL2_image** and **SDL2_gfx** and **SDL2_ttf** and **SDL2_mixer** using Homebrew.

### C/C++ Extension

- You need to have **C/C++ Extension** installed on your VS Code. If you don't have it, you can install C/C++ Extension from [here](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools).

## install SDL2 Packages

SDL2

```bash
brew install sdl2
```

SDL2_image

```bash
brew install sdl2_image
```

SDL2_gfx

```bash
brew install sdl2_gfx
```

SDL2_ttf

```bash
brew install sdl2_ttf
```

SDL2_mixer

```bash
brew install sdl2_mixer
```

## Try it out

Now you can use SDL on your Mac. Try running `src/main.cpp` using the run button in VS Code, or you can use Ctrl+F5 to see if it works.

## Advanced Settings(Optional)

If you want to have **updated** SDL2 packages, you have to link the latest version of SDL2 packages to your project. You can do this by linking them from the `/opt/homebrew/Cellar` directory.
