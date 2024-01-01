CC = g++
BUILD_DIR = build
SRC_DIR = src
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
OBJ_NAMES = $(patsubst $(SRC_DIR)/%.cpp,%,$(SRC_FILES))
INCLUDE_PATHS = -Iinclude
LIB_DIR = lib
LIBRARY_PATHS = -L${LIB_DIR}/SDL2 -L${LIB_DIR}/SDL2_image -L${LIB_DIR}/SDL2_mixer -L${LIB_DIR}/SDL2_ttf -L${LIB_DIR}/SDL2_gfx
COMPILER_FLAGS = -std=c++11 -Wall -o0 -g
LINKER_FLAGS = -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf -lSDL2_gfx

all: $(OBJ_NAMES)

$(OBJ_NAMES): %: $(SRC_DIR)/%.cpp
	$(CC) $(COMPILER_FLAGS) $(LINKER_FLAGS) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $< -o $(BUILD_DIR)/$@
