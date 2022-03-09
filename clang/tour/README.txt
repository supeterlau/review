- longjmp / setjmp

gcc compiler

https://iq.opengenus.org/compiling-c-program-using-gcc/
  Preprocessor
    It removes all the comments in the source file and replaces them with a single space.
    It includes the code from the header files.
    It replaces the predefined macro names with their expansions.
    gcc -E program_name.c
    gcc -E program_name.c > program_name.i (a preprocessed file)
  Compiler
    takes the preprocessed file and depending on the compiler generates IR (Intermediate Representation) code or assembly code
    gcc -S program_name.c
  Assembler
    translates the assembly code into executable machine code
    gcc -c program_name.c
  Linker
    Linking together all the object files from the different source files.
    Linking function calls with their definitions. The linker knows the locations of the function definitions in the static or dynamic libraries.
    gcc program_name.c

- multithreading pthread

https://www.tutorialspoint.com/multithreading-in-c
https://man7.org/linux/man-pages/man3/pthread_create.3.html

gcc file.c -lpthread

- multiprocess fork/spawn

- fiber
