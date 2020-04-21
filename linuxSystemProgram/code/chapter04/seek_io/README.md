# Usage
## 1. create a directory named 'build' to store build output file.
## 2. enter build directory.
## 3. type 'cmake ..' to generate build file
## 4. Enter make to build the project execuable file.
## 5. Enter 'make clean' to clean build output and ready for clean build.
## 6. Remove directory 'build' to clean all build output file.

# Example
__touch tfile__     *create new empty file*
__./seek_io tfile s100000 wabc__    *Seek to offset 100,000, write 'abc'*
S100000: seek succeeded
wabc: wrote 3 bytes
__ls -l tfile__
-rw-r--r--  1  user  user  100003  date
__./seek_io tfile s10000 R5__ *Seek to offset 10000, read 5 bytes from hole*
s10000: seek succeeded
R5: 00 00 00 00 00