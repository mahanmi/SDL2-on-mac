#!/bin/bash
cd /Users/mahan/Documents/VS\ Code/C++/SDL
result=$(echo "$1" | sed 's/\/Users\/mahan\/Documents\/VS Code\/C++\/SDL\///')
make SRC_DIR="$result"
