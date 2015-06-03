#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <termios.h>
#include <curses.h>
#include <unistd.h>
#include <time.h>
#include <sys/timeb.h>
#include <vector>
using namespace std;


vector< vector<char> > tBoard; //notch
vector< vector < vector< vector<int> > > > tElement; //element record
int score;

static struct termios initial_settings, new_settings;
static int peek_character = -1;

void close_keyboard(){
    tcsetattr(0, TCSANOW, &initial_settings);
}

void init_keyboard(){
    tcgetattr(0,&initial_settings);
    new_settings = initial_settings;
    new_settings.c_lflag &= ~ICANON;
    new_settings.c_lflag &= ~ECHO;
    new_settings.c_lflag &= ~ISIG;
    new_settings.c_cc[VMIN] = 1;
    new_settings.c_cc[VTIME] = 0;
    tcsetattr(0, TCSANOW, &new_settings);
}

int kbhit(){
    char ch;
    int nread;
    if (peek_character != -1){
        return 1;
    }
    new_settings.c_cc[VMIN]=0;
    tcsetattr(0, TCSANOW, &new_settings);
    nread = read(0,&ch,1);
    new_settings.c_cc[VMIN]=1;
    tcsetattr(0, TCSANOW, &new_settings);
    if (nread == 1){
        peek_character = ch;
        return 1;
    }
    return 0;
}

int readch(){
    char ch;
    if(peek_character != -1){
        ch = peek_character;
        peek_character = -1;
        return ch;
    }
    read(0, &ch, 1);
    return ch;
}

void initialEle(){
    vector< vector< vector<int> > > type;
    vector< vector<int> > unit;
    vector<int> coord;
    //===================================================
    // Type T
    //===================================================
    //
    // Type1      ###
    //             #
    coord.clear();
    coord.push_back(6);
    coord.push_back(1);
    unit.push_back(coord);
    coord.clear();
    coord.push_back(7);
    coord.push_back(1);
    unit.push_back(coord);
    coord.clear();
    coord.push_back(5);
    coord.push_back(1);
    unit.push_back(coord);
    coord.clear();
    coord.push_back(6);
    coord.push_back(2);
    unit.push_back(coord);
    type.push_back(unit);
    //            #
    // Type2     ##
    //            #
    unit.clear();
    coord.clear();
    coord.push_back(6);
    coord.push_back(2);
    unit.push_back(coord);
    coord.clear();
    coord.push_back(6);
    coord.push_back(3);
    unit.push_back(coord);
    coord.clear();
    coord.push_back(6);
    coord.push_back(1);
    unit.push_back(coord);
    coord.clear();
    coord.push_back(5);
    coord.push_back(2);
    unit.push_back(coord);
    type.push_back(unit);
    //
    // Type3       #
    //            ###
    unit.clear();
    coord.clear();
    coord.push_back(6);
    coord.push_back(2);
    unit.push_back(coord);
    coord.clear();
    coord.push_back(5);
    coord.push_back(2);
    unit.push_back(coord);
    coord.clear();
    coord.push_back(7);
    coord.push_back(2);
    unit.push_back(coord);
    coord.clear();
    coord.push_back(6);
    coord.push_back(1);
    unit.push_back(coord);
    type.push_back(unit);
    //            #
    // Type4      ##
    //            #
    unit.clear();
    coord.clear();
    coord.push_back(6);
    coord.push_back(2);
    unit.push_back(coord);
    coord.clear();
    coord.push_back(6);
    coord.push_back(1);
    unit.push_back(coord);
    coord.clear();
    coord.push_back(6);
    coord.push_back(3);
    unit.push_back(coord);
    coord.clear();
    coord.push_back(7);
    coord.push_back(2);
    unit.push_back(coord);
    type.push_back(unit);
    tElement.push_back(type);
    //===================================================
    // Type L
    //===================================================
    //            #
    // Type1      #
    //            ##
    unit.clear();
    coord.clear();
    type.clear();
    coord.push_back(6);
    coord.push_back(3);
    unit.push_back(coord);
    coord.clear();
    coord.push_back(6);
    coord.push_back(2);
    unit.push_back(coord);
    coord.clear();
    coord.push_back(6);
    coord.push_back(1);
    unit.push_back(coord);
    coord.clear();
    coord.push_back(7);
    coord.push_back(3);
    unit.push_back(coord);
    type.push_back(unit);
    //
    // Type2     ###
    //           #
    unit.clear();
    coord.clear();
    coord.push_back(6);
    coord.push_back(1);
    unit.push_back(coord);
    coord.clear();
    coord.push_back(7);
    coord.push_back(1);
    unit.push_back(coord);
    coord.clear();
    coord.push_back(8);
    coord.push_back(1);
    unit.push_back(coord);
    coord.clear();
    coord.push_back(6);
    coord.push_back(2);
    unit.push_back(coord);
    type.push_back(unit);
    //           ##
    // Type3      #
    //            #
    unit.clear();
    coord.clear();
    coord.push_back(6);
    coord.push_back(1);
    unit.push_back(coord);
    coord.clear();
    coord.push_back(6);
    coord.push_back(2);
    unit.push_back(coord);
    coord.clear();
    coord.push_back(6);
    coord.push_back(3);
    unit.push_back(coord);
    coord.clear();
    coord.push_back(5);
    coord.push_back(1);
    unit.push_back(coord);
    type.push_back(unit);
    //
    // Type4       #
    //           ###
    unit.clear();
    coord.clear();
    coord.push_back(6);
    coord.push_back(2);
    unit.push_back(coord);
    coord.clear();
    coord.push_back(5);
    coord.push_back(2);
    unit.push_back(coord);
    coord.clear();
    coord.push_back(4);
    coord.push_back(2);
    unit.push_back(coord);
    coord.clear();
    coord.push_back(6);
    coord.push_back(1);
    unit.push_back(coord);
    type.push_back(unit);
    tElement.push_back(type);
    //===================================================
    // Type L mirrored
    //===================================================
    //             #
    // Type1       #
    //            ##
    unit.clear();
    coord.clear();
    type.clear();
    coord.push_back(6);
    coord.push_back(3);
    unit.push_back(coord);
    coord.clear();
    coord.push_back(6);
    coord.push_back(2);
    unit.push_back(coord);
    coord.clear();
    coord.push_back(6);
    coord.push_back(1);
    unit.push_back(coord);
    coord.clear();
    coord.push_back(5);
    coord.push_back(3);
    unit.push_back(coord);
    type.push_back(unit);
    //
    // Type2      #
    //            ###
    unit.clear();
    coord.clear();
    coord.push_back(6);
    coord.push_back(2);
    unit.push_back(coord);
    coord.clear();
    coord.push_back(7);
    coord.push_back(2);
    unit.push_back(coord);
    coord.clear();
    coord.push_back(8);
    coord.push_back(2);
    unit.push_back(coord);
    coord.clear();
    coord.push_back(6);
    coord.push_back(1);
    unit.push_back(coord);
    type.push_back(unit);
    //           ##
    // Type3     #
    //           #
    unit.clear();
    coord.clear();
    coord.push_back(6);
    coord.push_back(1);
    unit.push_back(coord);
    coord.clear();
    coord.push_back(6);
    coord.push_back(2);
    unit.push_back(coord);
    coord.clear();
    coord.push_back(6);
    coord.push_back(3);
    unit.push_back(coord);
    coord.clear();
    coord.push_back(7);
    coord.push_back(1);
    unit.push_back(coord);
    type.push_back(unit);
    //
    // Type4   ###
    //           #
    unit.clear();
    coord.clear();
    coord.push_back(6);
    coord.push_back(1);
    unit.push_back(coord);
    coord.clear();
    coord.push_back(5);
    coord.push_back(1);
    unit.push_back(coord);
    coord.clear();
    coord.push_back(4);
    coord.push_back(1);
    unit.push_back(coord);
    coord.clear();
    coord.push_back(6);
    coord.push_back(2);
    unit.push_back(coord);
    type.push_back(unit);
    tElement.push_back(type);
    //===================================================
    // Type Z
    //===================================================
    //
    // Type1        ##
    //               ##
    unit.clear();
    coord.clear();
    type.clear();
    coord.push_back(6);
    coord.push_back(1);
    unit.push_back(coord);
    coord.clear();
    coord.push_back(5);
    coord.push_back(1);
    unit.push_back(coord);
    coord.clear();
    coord.push_back(6);
    coord.push_back(2);
    unit.push_back(coord);
    coord.clear();
    coord.push_back(7);
    coord.push_back(2);
    unit.push_back(coord);
    type.push_back(unit);
    //               #
    // Type2        ##
    //              #
    unit.clear();
    coord.clear();
    coord.push_back(6);
    coord.push_back(2);
    unit.push_back(coord);
    coord.clear();
    coord.push_back(6);
    coord.push_back(1);
    unit.push_back(coord);
    coord.clear();
    coord.push_back(5);
    coord.push_back(2);
    unit.push_back(coord);
    coord.clear();
    coord.push_back(5);
    coord.push_back(3);
    unit.push_back(coord);
    type.push_back(unit);
    //              ##
    // Type3         ##
    //
    unit.clear();
    coord.clear();
    coord.push_back(6);
    coord.push_back(2);
    unit.push_back(coord);
    coord.clear();
    coord.push_back(7);
    coord.push_back(2);
    unit.push_back(coord);
    coord.clear();
    coord.push_back(6);
    coord.push_back(1);
    unit.push_back(coord);
    coord.clear();
    coord.push_back(5);
    coord.push_back(1);
    unit.push_back(coord);
    type.push_back(unit);
    //               #
    // Type4        ##
    //              #
    unit.clear();
    coord.clear();
    coord.push_back(6);
    coord.push_back(2);
    unit.push_back(coord);
    coord.clear();
    coord.push_back(6);
    coord.push_back(3);
    unit.push_back(coord);
    coord.clear();
    coord.push_back(7);
    coord.push_back(2);
    unit.push_back(coord);
    coord.clear();
    coord.push_back(7);
    coord.push_back(1);
    unit.push_back(coord);
    type.push_back(unit);
    tElement.push_back(type);
    //===================================================
    // Type Z mirrored
    //===================================================
    //
    // Type1        ##
    //             ##
    unit.clear();
    coord.clear();
    type.clear();
    coord.push_back(6);
    coord.push_back(1);
    unit.push_back(coord);
    coord.clear();
    coord.push_back(7);
    coord.push_back(1);
    unit.push_back(coord);
    coord.clear();
    coord.push_back(6);
    coord.push_back(2);
    unit.push_back(coord);
    coord.clear();
    coord.push_back(5);
    coord.push_back(2);
    unit.push_back(coord);
    type.push_back(unit);
    //             #
    // Type2       ##
    //              #
    unit.clear();
    coord.clear();
    coord.push_back(6);
    coord.push_back(2);
    unit.push_back(coord);
    coord.clear();
    coord.push_back(6);
    coord.push_back(3);
    unit.push_back(coord);
    coord.clear();
    coord.push_back(5);
    coord.push_back(2);
    unit.push_back(coord);
    coord.clear();
    coord.push_back(5);
    coord.push_back(1);
    unit.push_back(coord);
    type.push_back(unit);
    //            ##
    // Type3     ##
    //
    unit.clear();
    coord.clear();
    coord.push_back(6);
    coord.push_back(2);
    unit.push_back(coord);
    coord.clear();
    coord.push_back(5);
    coord.push_back(2);
    unit.push_back(coord);
    coord.clear();
    coord.push_back(6);
    coord.push_back(1);
    unit.push_back(coord);
    coord.clear();
    coord.push_back(7);
    coord.push_back(1);
    unit.push_back(coord);
    type.push_back(unit);
    //            #
    // Type4      ##
    //             #
    unit.clear();
    coord.clear();
    coord.push_back(6);
    coord.push_back(2);
    unit.push_back(coord);
    coord.clear();
    coord.push_back(6);
    coord.push_back(1);
    unit.push_back(coord);
    coord.clear();
    coord.push_back(7);
    coord.push_back(2);
    unit.push_back(coord);
    coord.clear();
    coord.push_back(7);
    coord.push_back(3);
    unit.push_back(coord);
    type.push_back(unit);
    tElement.push_back(type);
    //===================================================
    // Type I
    //===================================================
    //            #
    //            #
    // Type1      #
    //            #
    unit.clear();
    coord.clear();
    type.clear();
    coord.push_back(6);
    coord.push_back(3);
    unit.push_back(coord);
    coord.clear();
    coord.push_back(6);
    coord.push_back(4);
    unit.push_back(coord);
    coord.clear();
    coord.push_back(6);
    coord.push_back(2);
    unit.push_back(coord);
    coord.clear();
    coord.push_back(6);
    coord.push_back(1);
    unit.push_back(coord);
    type.push_back(unit);
    //
    // Type2     ####
    //
    //
    unit.clear();
    coord.clear();
    coord.push_back(6);
    coord.push_back(1);
    unit.push_back(coord);
    coord.clear();
    coord.push_back(5);
    coord.push_back(1);
    unit.push_back(coord);
    coord.clear();
    coord.push_back(7);
    coord.push_back(1);
    unit.push_back(coord);
    coord.clear();
    coord.push_back(8);
    coord.push_back(1);
    unit.push_back(coord);
    type.push_back(unit);
    //           #
    // Type3     #
    //           #
    //           #
    unit.clear();
    coord.clear();
    coord.push_back(6);
    coord.push_back(2);
    unit.push_back(coord);
    coord.clear();
    coord.push_back(6);
    coord.push_back(1);
    unit.push_back(coord);
    coord.clear();
    coord.push_back(6);
    coord.push_back(3);
    unit.push_back(coord);
    coord.clear();
    coord.push_back(6);
    coord.push_back(4);
    unit.push_back(coord);
    type.push_back(unit);
    //
    // Type4   ####
    //
    //
    unit.clear();
    coord.clear();
    coord.push_back(6);
    coord.push_back(1);
    unit.push_back(coord);
    coord.clear();
    coord.push_back(7);
    coord.push_back(1);
    unit.push_back(coord);
    coord.clear();
    coord.push_back(5);
    coord.push_back(1);
    unit.push_back(coord);
    coord.clear();
    coord.push_back(4);
    coord.push_back(1);
    unit.push_back(coord);
    type.push_back(unit);
    tElement.push_back(type);
    //===================================================
    // Type square
    //===================================================
    //
    // Type1     ##
    //           ##
    unit.clear();
    coord.clear();
    type.clear();
    coord.push_back(6);
    coord.push_back(1);
    unit.push_back(coord);
    coord.clear();
    coord.push_back(6);
    coord.push_back(2);
    unit.push_back(coord);
    coord.clear();
    coord.push_back(7);
    coord.push_back(1);
    unit.push_back(coord);
    coord.clear();
    coord.push_back(7);
    coord.push_back(2);
    unit.push_back(coord);
    type.push_back(unit);
    //
    // Type2     ##
    //           ##
    unit.clear();
    coord.clear();
    coord.push_back(6);
    coord.push_back(1);
    unit.push_back(coord);
    coord.clear();
    coord.push_back(6);
    coord.push_back(2);
    unit.push_back(coord);
    coord.clear();
    coord.push_back(7);
    coord.push_back(1);
    unit.push_back(coord);
    coord.clear();
    coord.push_back(7);
    coord.push_back(2);
    unit.push_back(coord);
    type.push_back(unit);
    //
    // Type3     ##
    //           ##
    unit.clear();
    coord.clear();
    coord.push_back(6);
    coord.push_back(1);
    unit.push_back(coord);
    coord.clear();
    coord.push_back(6);
    coord.push_back(2);
    unit.push_back(coord);
    coord.clear();
    coord.push_back(7);
    coord.push_back(1);
    unit.push_back(coord);
    coord.clear();
    coord.push_back(7);
    coord.push_back(2);
    unit.push_back(coord);
    type.push_back(unit);
    //
    // Type4     ##
    //           ##
    unit.clear();
    coord.clear();
    coord.push_back(6);
    coord.push_back(1);
    unit.push_back(coord);
    coord.clear();
    coord.push_back(6);
    coord.push_back(2);
    unit.push_back(coord);
    coord.clear();
    coord.push_back(7);
    coord.push_back(1);
    unit.push_back(coord);
    coord.clear();
    coord.push_back(7);
    coord.push_back(2);
    unit.push_back(coord);
    type.push_back(unit);
    tElement.push_back(type);
    type.clear();
    unit.clear();
    coord.clear();
}

double getNowtime(){
    double now;
    struct timeb tp;
    ftime(&tp);
    now = tp.time*1000+tp.millitm;
    return now;
}

void fall(){
    int i;
    //===================================================
    // clear the screen
    //===================================================
    printf("\033[2J");
    //===================================================
    // redraw the notch
    //===================================================
    for (i=1; i<21; i++){
        printf("\033[%d;%dH", i, 1);
        putchar('|');
        printf("\033[%d;%dH", i, 12);
        putchar('|');
    }
    printf("\033[%d;%dH", 21, 1);
    putchar('+');
    for (i=2; i<12; i++){
        printf("\033[%d;%dH", 21, i);
        putchar('-');
    }
    printf("\033[%d;%dH", 21, 12);
    putchar('+');
    //===================================================
    // draw score
    //===================================================
    printf("\033[%d;%dH", 2, 15);
    printf("score: %d", score);
    //===================================================
    // show keys
    //===================================================
    printf("\033[%d;%dH", 25, 2);
    printf("Move Left: a     Move Right: d     Down: s     Rotate: w     Quick: q");
    //===================================================
    // draw stack
    //===================================================
    for (i=0; i<tBoard.size(); i++){
        int k;
        for (k=0; k<tBoard[i].size(); k++){
            if (tBoard[i][k] == 'y'){
                printf("\033[%d;%dH", k+1, i+2);
                printf("\033[%d;%dm%c\033[0m", 40, 30, ' ');
                //putchar('#');
            }
        }
    }
}

int can_fall(int x, int y){
    if (x < 0){
        x = 0;
    }
    if (y < 0){
        y = 0;
    }
    if (tBoard[x][y] == 'y'){
        return 0;
    }
    else {
        return 1;
    }
}

void upper_fall(int y){
    int i,j;
    for (i=y; i>-1; i--){
        if (i==0){
            for (j=0; j<10; j++){
                tBoard[j][i] = 'n';
            }
        }
        else {
            for (j=0; j<10; j++){
                tBoard[j][i] = tBoard[j][i-1];
            }
        }
    }
}

int main(){
    //printf("\033[2J");
    int i;
    score = 0;
    //===================================================
    // clear the screen
    //===================================================
    printf("\033[2J");
    //===================================================
    // redraw the notch
    //===================================================
    for (i=1; i<21; i++){
        printf("\033[%d;%dH", i, 1);
        putchar('|');
        printf("\033[%d;%dH", i, 12);
        putchar('|');
    }
    printf("\033[%d;%dH", 21, 1);
    putchar('+');
    for (i=2; i<12; i++){
        printf("\033[%d;%dH", 21, i);
        putchar('-');
    }
    printf("\033[%d;%dH", 21, 12);
    putchar('+');
    //===================================================
    // draw score
    //===================================================
    printf("\033[%d;%dH", 2, 15);
    printf("score: %d", score);
    //===================================================
    // show keys
    //===================================================
    printf("\033[%d;%dH", 25, 2);
    printf("Move Left: a     Move Right: d     Down: s     Rotate: w     Quick: q");
    //===================================================
    // initialize keyboard
    //===================================================
    init_keyboard();
    //===================================================
    // initialize notch
    //===================================================
    char temp = 'n';
    vector<char> subBoard;
    //vector<char> stack;
    for (i=0; i<20; i++){
        subBoard.push_back(temp); // 1 column pix
    }
    for (i=0; i<10; i++){
        tBoard.push_back(subBoard); // 10 columns pix
    }
    //===================================================
    // initialize elements
    //===================================================
    initialEle();
    //===================================================
    //===================================================
    double Delta = 0;
    double last_time = getNowtime();
    int j = 1;
    vector< vector<int> > now;
    vector< vector<int> > next;
    vector<int> original_now;
    vector<int> original_next;
    //===================================================
    // Original position 0:x 1:type 2:state_number
    //===================================================
    original_now.push_back(6);
    original_next.push_back(6);
    //===================================================
    // generate now unit
    //===================================================
    srand(time(NULL));
    int random_type = rand()%7;
    //srand(time(NULL));
    int random_number = rand()%4;
    now = tElement[random_type][random_number];
    original_now.push_back(random_type);
    original_now.push_back(random_number);
    //===================================================
    // generate next unit
    //===================================================
    //srand(time(NULL));
    random_type = rand()%7;
    //srand(time(NULL));
    random_number = rand()%4;
    next = tElement[random_type][random_number];
    original_next.push_back(random_type);
    original_next.push_back(random_number);
    //===================================================
    // show next unit
    //===================================================
    printf("\033[%d;%dH", 5, 15);
    printf("next:");
    for (i=0; i<4; i++){
        printf("\033[%d;%dH", next[i][1]+4, next[i][0]+20);
        if (original_next[1] == 0){
            printf("\033[%d;%dm%c\033[0m", 40, 30, ' ');
        }
        else if (original_next[1] == 1){
            printf("\033[%d;%dm%c\033[0m", 41, 31, ' ');
        }
        else if (original_next[1] == 2){
            printf("\033[%d;%dm%c\033[0m", 42, 32, ' ');
        }
        else if (original_next[1] == 3){
            printf("\033[%d;%dm%c\033[0m", 43, 33, ' ');
        }
        else if (original_next[1] == 4){
            printf("\033[%d;%dm%c\033[0m", 44, 34, ' ');
        }
        else if (original_next[1] == 5){
            printf("\033[%d;%dm%c\033[0m", 45, 35, ' ');
        }
        else if (original_next[1] == 6){
            printf("\033[%d;%dm%c\033[0m", 46, 36, ' ');
        }
        //putchar('#');
    }
    //===================================================
    while (true){
        double now_time = getNowtime();
        Delta += (now_time - last_time);
    //===================================================
    // draw the notch
    //===================================================
        for (i=1; i<21; i++){
            printf("\033[%d;%dH", i, 1);
            putchar('|');
            printf("\033[%d;%dH", i, 12);
            putchar('|');
        }
        printf("\033[%d;%dH", 21, 1);
        putchar('+');
        for (i=2; i<12; i++){
            printf("\033[%d;%dH", 21, i);
            putchar('-');
        }
        printf("\033[%d;%dH", 21, 12);
        putchar('+');
        //===================================================
        // draw score
        //===================================================
        printf("\033[%d;%dH", 2, 15);
        printf("score: %d", score);
        //===================================================
        // show keys
        //===================================================
        printf("\033[%d;%dH", 25, 2);
        printf("Move Left: a     Move Right: d     Down: s     Rotate: w     Quick: q");
        //===================================================
        // show next unit
        //===================================================
        printf("\033[%d;%dH", 5, 15);
        printf("next:");
        for (i=0; i<4; i++){
            printf("\033[%d;%dH", next[i][1]+4, next[i][0]+20);
            if (original_next[1] == 0){
                printf("\033[%d;%dm%c\033[0m", 40, 30, ' ');
            }
            else if (original_next[1] == 1){
                printf("\033[%d;%dm%c\033[0m", 41, 31, ' ');
            }
            else if (original_next[1] == 2){
                printf("\033[%d;%dm%c\033[0m", 42, 32, ' ');
            }
            else if (original_next[1] == 3){
                printf("\033[%d;%dm%c\033[0m", 43, 33, ' ');
            }
            else if (original_next[1] == 4){
                printf("\033[%d;%dm%c\033[0m", 44, 34, ' ');
            }
            else if (original_next[1] == 5){
                printf("\033[%d;%dm%c\033[0m", 45, 35, ' ');
            }
            else if (original_next[1] == 6){
                printf("\033[%d;%dm%c\033[0m", 46, 36, ' ');
            }
            //printf("\033[%d;%dm%c\033[0m", 41, 41, ' ');
            //putchar('#');
        }
    //===================================================
    // add new stack
    //===================================================
        for (i=0; i<tBoard.size(); i++){
            int k;
            for (k=0; k<tBoard[i].size(); k++){
                if (tBoard[i][k] == 'y'){
                    printf("\033[%d;%dH", k+1, i+2);
                    printf("\033[%d;%dm%c\033[0m", 40, 30, ' ');
                    //putchar('#');
                }
            }
        }
    //===================================================
    // falling element
    //===================================================
        if (Delta > 500){
            Delta = 0;
            //===========================================
            //printf("\033[2J");
            //if (j==20){
              //  for (i=1; i<21; i++){
                //    printf("\033[%d;%dH", i, 1);
                  //  putchar('|');
                    //printf("\033[%d;%dH", i, 12);
                    //putchar('|');
                //}
                //printf("\033[%d;%dH", 21, 1);
                //putchar('+');
                //for (i=2; i<12; i++){
                  //  printf("\033[%d;%dH", 21, i);
                    //putchar('-');
                //}
                //printf("\033[%d;%dH", 21, 12);
                //putchar('+');
            //}
            //===================================================
            // renew notch and stack
            //===================================================
            fall();
            //===================================================
            // generate unit
            //===================================================
            char block = 'n';
            for (i=0; i<4; i++){
                if (!can_fall(now[i][0]-2, now[i][1]-1)){
                    block = 'y';
                }
            }
            char touch_end = 'n';
            for (i=0; i<4; i++){
                if (now[i][1] == 20){
                    touch_end = 'y';
                }
            }
            if (touch_end == 'y' && block == 'n'){
                for (i=0; i<4; i++){
                    tBoard[now[i][0]-2][now[i][1]-1] = 'y';
                }
                now.clear();
                now = next;
                next.clear();
                //srand(time(NULL));
                random_type = rand()%7;
                //srand(time(NULL));
                random_number = rand()%4;
                next = tElement[random_type][random_number];
                original_now[0] = 6;
                original_now[1] = original_next[1];
                original_now[2] = original_next[2];
                original_next[1] = random_type;
                original_next[2] = random_number;
            }
            else if (block == 'n' ){
                for (i=0; i<4; i++){
                    printf("\033[%d;%dH", now[i][1], now[i][0]);
                    if (original_now[1] == 0){
                        printf("\033[%d;%dm%c\033[0m", 40, 30, ' ');
                    }
                    else if (original_now[1] == 1){
                        printf("\033[%d;%dm%c\033[0m", 41, 31, ' ');
                    }
                    else if (original_now[1] == 2){
                        printf("\033[%d;%dm%c\033[0m", 42, 32, ' ');
                    }
                    else if (original_now[1] == 3){
                        printf("\033[%d;%dm%c\033[0m", 43, 33, ' ');
                    }
                    else if (original_now[1] == 4){
                        printf("\033[%d;%dm%c\033[0m", 44, 34, ' ');
                    }
                    else if (original_now[1] == 5){
                        printf("\033[%d;%dm%c\033[0m", 45, 35, ' ');
                    }
                    else if (original_now[1] == 6){
                        printf("\033[%d;%dm%c\033[0m", 46, 36, ' ');
                    }
                    //printf("\033[%d;%dm%c\033[0m", 41, 41, ' ');
                    //putchar('#');
                    now[i][1] += 1;
                }
            }
            else {
                for (i=0; i<4; i++){
                    tBoard[now[i][0]-2][now[i][1]-2] = 'y';
                }
                now.clear();
                now = next;
                next.clear();
                //srand(time(NULL));
                random_type = rand()%7;
                //srand(time(NULL));
                random_number = rand()%4;
                next = tElement[random_type][random_number];
                original_now[0] = 6;
                original_now[1] = original_next[1];
                original_now[2] = original_next[2];
                original_next[1] = random_type;
                original_next[2] = random_number;
            }
            //===================================================
            //if (can_fall(5, j-1)){
              //  printf("\033[%d;%dH", j, 6);
               // putchar('#');
                //j++;
                //=======================================
                // the bottom of the column
                //=======================================
                //if (j == 21){
                  //  tBoard[5][j-2] = 'y';
                    //j = 1;
                //}
            //}
            //else {
              //  tBoard[5][j-2] = 'y';
                //j = 1;
            //}
        }
    //===================================================
    // check effacement
    //===================================================
        for (i=19; i>-1; i--){
            int y_number = 0;
            int k;
            for (k=0; k<tBoard.size(); k++){
                if (tBoard[k][i] == 'y'){
                    y_number++;
                }
            }
            if (y_number == 10){
                upper_fall(i);
                score += 1;
                i += 1;
            }
        }
    //===================================================
    // end game
    //===================================================
        for (i=0; i<tBoard.size(); i++){
            if (tBoard[i][0] == 'y'){
                fall();
                printf("\033[%d;%dH", 1, i+2);
                printf("\033[%d;%dm%c\033[0m", 40, 30, ' ');
                //putchar('#');
                //===================================================
                // show next unit
                //===================================================
                printf("\033[%d;%dH", 5, 15);
                printf("next:");
                for (i=0; i<4; i++){
                    printf("\033[%d;%dH", next[i][1]+4, next[i][0]+20);
                    if (original_next[1] == 0){
                        printf("\033[%d;%dm%c\033[0m", 40, 30, ' ');
                    }
                    else if (original_next[1] == 1){
                        printf("\033[%d;%dm%c\033[0m", 41, 31, ' ');
                    }
                    else if (original_next[1] == 2){
                        printf("\033[%d;%dm%c\033[0m", 42, 32, ' ');
                    }
                    else if (original_next[1] == 3){
                        printf("\033[%d;%dm%c\033[0m", 43, 33, ' ');
                    }
                    else if (original_next[1] == 4){
                        printf("\033[%d;%dm%c\033[0m", 44, 34, ' ');
                    }
                    else if (original_next[1] == 5){
                        printf("\033[%d;%dm%c\033[0m", 45, 35, ' ');
                    }
                    else if (original_next[1] == 6){
                        printf("\033[%d;%dm%c\033[0m", 46, 36, ' ');
                    }
                    //printf("\033[%d;%dm%c\033[0m", 41, 41, ' ');
                    //putchar('#');
                }
                return 0;
            }
        }
    //===================================================
    // change time
    //===================================================
        last_time = now_time;
    //===================================================
    // keyboard effect
    //===================================================
        if (kbhit()){
            char key = readch();
            //
            // move left
            //
            if (key == 'a'){
                char touch_end = 'n';
                for (i=0; i<4; i++){
                    if (now[i][0]==2){
                        touch_end = 'y';
                    }
                    else if (tBoard[now[i][0]-3][now[i][1]-1] == 'y'){
                        touch_end = 'y';
                    }
                }
                if (touch_end == 'n'){
                    for (i=0; i<4; i++){
                        now[i][0] -= 1;
                    }
                    original_now[0] -= 1;
                }
            }
            //
            // move right
            //
            if (key == 'd'){
                char touch_end = 'n';
                for (i=0; i<4; i++){
                    if (now[i][0]==11){
                        touch_end = 'y';
                    }
                    else if (tBoard[now[i][0]-1][now[i][1]-1] == 'y'){
                        touch_end = 'y';
                    }
                }
                if (touch_end == 'n'){
                    for (i=0; i<4; i++){
                        now[i][0] += 1;
                    }
                    original_now[0] += 1;
                }
            }
            //
            // down
            //
            if (key == 's'){
                char touch_end = 'y';
                int distance = 1000;
                for (i=0; i<4; i++){
                    int k;
                    for (k=now[i][1]; k<20; k++){
                        if (tBoard[now[i][0]-2][k] == 'y'){
                            touch_end = 'n';
                            if (distance > (k - now[i][1])){
                                distance = k - now[i][1];
                            }
                            break;
                        }
                    }
                    
                }
                for (i=0; i<4; i++){
                    if (distance > (20 - now[i][1])){
                        distance = 20 - now[i][1];
                    }
                }
                for (i=0; i<4; i++){
                    now[i][1] += distance;
                }
            }
            //
            // rotate
            //
            if (key == 'w'){
                char can_change = 'y';
                int distance_x = now[0][0] - 6;
                int distance_y = now[0][1] - tElement[original_now[1]][original_now[2]][0][1];
                vector< vector<int> > temp_now;
                if (original_now[2] == 3){
                    temp_now = tElement[original_now[1]][0];
                }
                else {
                    temp_now = tElement[original_now[1]][original_now[2]+1];
                }
                for (i=0; i<4; i++){
                    temp_now[i][0] += distance_x;
                    temp_now[i][1] += distance_y;
                }
                int out_of_range = 0;
                for (i=0; i<4; i++){
                    if (temp_now[i][0] < 2){
                        out_of_range += 1;
                    }
                }
                if (out_of_range == 2){
                    for (i=0; i<4; i++){
                        temp_now[i][0] += 2;
                    }
                }
                else if (out_of_range == 1){
                    for (i=0; i<4; i++){
                        temp_now[i][0] += 1;
                    }
                }
                else {
                    out_of_range = 0;
                    for(i=0; i<4; i++){
                        if (temp_now[i][0] > 11){
                            out_of_range += 1;
                        }
                    }
                    if (out_of_range == 2){
                        for (i=0; i<4; i++){
                            temp_now[i][0] -= 2;
                        }
                    }
                    else if (out_of_range == 1){
                        for (i=0; i<4; i++){
                            temp_now[i][0] -= 1;
                        }
                    }
                }
                out_of_range = 0;
                for (i=0; i<4; i++){
                    if (temp_now[i][1] > 20){
                        out_of_range += 1;
                    }
                }
                if (out_of_range == 2){
                    for (i=0; i<4; i++){
                        temp_now[i][1] -= 2;
                    }
                }
                else if (out_of_range == 1){
                    for (i=0; i<4; i++){
                        temp_now[i][1] -= 1;
                    }
                }
                else {
                }
                for (i=0; i<4; i++){
                    if (tBoard[temp_now[i][0]-2][temp_now[i][1]-1] == 'y'){
                        can_change = 'n';
                    }
                }
                if (can_change == 'y'){
                    now = temp_now;
                    original_now[0] = temp_now[0][0];
                    if (original_now[2] == 3){
                        original_now[2] = 0;
                    }
                    else {
                        original_now[2] += 1;
                    }
                }
            }
            //
            // quick
            //
            if (key == 'q'){
                return 0;
            }
        }
    //===================================================
        //if (j > 20){
          //  return 0;
        //}
        if (cin.eof()){
            return 0;
        }
    //===================================================
    //===================================================
    // test
    //time_t Delta = 0;
    //time_t last_time = time(NULL);
    //i = 1;
    //while (true){
      //  time_t now_time = time(NULL);
        //Delta += (now_time - last_time);
        //if (Delta > 1){
          //  Delta = 0;
            //printf("\033[%d;%dH", i-1, 6);
            //putchar('.');
            //printf("\033[%d;%dH", i, 6);
            //putchar('#');
        //}
    }
    //for (i=1; i<21; i++){
      //  printf("\033[%d;%dH", i-1, 6);
       // putchar(NULL);
       // printf("\033[%d;%dH", i, 6);
       // putchar('#');
   // }
    close_keyboard();
}