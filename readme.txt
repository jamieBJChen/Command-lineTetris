CSCI-4120                  Assignment:Tetris

In this assignment, there is only one file which call "tetris.cpp".

I am using C++ to write "tetris.cpp".

Compiling:       $ g++ tetris.cpp

run:             $ ./a.out

The file "tetris.cpp" including the following functions:
	1. close_keyboard();
	2. init_keyboard();
	3. kbhit();
	4. readch();
	5. initialEle(); // initializes all seven elements
	6. getNowtime(); // gets current time in milliseconds
	7. fall(); // renews the stack and notch
	8. can_fall(int x, int y); // checks whether element can fall
	9. upper_fall(int y); // when effacement, drops the lines which are full and renews the notch and stack
       10. main(); // main function

Remark: this application only tested in Macintosh.
