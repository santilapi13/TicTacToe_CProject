# Tic-Tac-Toe in C + SDL2
This Tic-Tac-Toe was made in order to learn how to program videogames in C with SDL2. 
Project made in Linux.

Compiler C-flags: -Wall -Wextra -g3 -lSDL2main -lSDL2 -lm -ldl

# Compile it in Windows
It needs the src folder in the project root. Inside src should be the include and lib folders.
Compiler C-flags: -Wall -Wextra -g3 -Isrc/include -Lsrc/lib -lmingw32 -lSDL2main -lSDL2 -lm

# Open it in Windows
Once main.c is compiled, main.exe is created. In order to open it, SDL2.dll file is needed in the same directory of main.exe.
