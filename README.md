# SDL for Mac

This repository is for Mac users who want to use SDL on Mac with **VS Code** (both Intel and Apple ARM compatible).

## Requirements

### Homebrew

- You need to have **Homebrew** installed on your Mac. If you don't have it, you can install Homebrew from [here](https://brew.sh/).
  Then, you need to install **SDL2**, **SDL2_image**, **SDL2_gfx**, **SDL2_ttf**, and **SDL2_mixer** using Homebrew.

### C/C++ Extension

- You need to have the **C/C++ Extension** installed in your VS Code. If you don't have it, you can install the C/C++ Extension from [here](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools).

## Clone this repository

Open VS Code and clone this repository use cmnd+shift+p and type `git clone` and paste this repository URL in the input box.

```bash
https://github.com/mahanmi/SDL-for-mac.git
```

## install SDL2 Packages

- **SDL2**

```bash
brew install sdl2
```

- **SDL2_image**

```bash
brew install sdl2_image
```

- **SDL2_gfx**

```bash
brew install sdl2_gfx
```

- **SDL2_ttf**

```bash
brew install sdl2_ttf
```

- **SDL2_mixer**

```bash
brew install sdl2_mixer
```

## link SDL2 Libraries

There is a script file in this repository called `link.sh` located in the `lib` folder. You need to run this script file to link the SDL2 libraries to your project.
To do this, open your terminal and navigate to the root directory of this repository. Then, run the following command:

```bash
sh lib/link.sh
```

## Try it out

Now you can use SDL on your Mac.Clone this repository and Try running `src/main.cpp` using the run button in VS Code, or you can use Ctrl+F5 to see if it works.
