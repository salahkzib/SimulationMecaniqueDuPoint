@ echo off
cd C:\Users\kzibs\Desktop\aacs\programming\programming_languages\c#\tests\NativeAPIC
gcc -c program.c -o program.o
gcc -shared -o program.dll program.o
pause