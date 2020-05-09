#include <iostream>
#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <sys/ioctl.h>

using namespace std;

//
//reference: http://www.linuxdiyf.com/linux/17232.html
// check if a keystroke is received
//
int kbhit(void)
{
struct timeval tv;
struct termios old_termios, new_termios;
int error;
int count = 0;
tcgetattr(0, &old_termios);
new_termios = old_termios;
new_termios.c_lflag &= ~ICANON;
new_termios.c_lflag &= ~ECHO;
new_termios.c_cc[VMIN] = 1;
new_termios.c_cc[VTIME] = 0;
error = tcsetattr(0, TCSANOW, &new_termios);
tv.tv_sec = 0;
tv.tv_usec = 100;
select(1, NULL, NULL, NULL, &tv);
error += ioctl(0, FIONREAD, &count);
error += tcsetattr(0, TCSANOW, &old_termios);
return error == 0 ? count : -1;
}

//
//reference: https://blog.csdn.net/chent86/article/details/76377345
// returns
//
char inputchar(){
       char c;
    static struct termios oldt, newt;
    tcgetattr( STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON);
    tcsetattr( STDIN_FILENO, TCSANOW, &newt);
    system("stty -echo");
    c=getchar();
 system("stty echo");
 tcsetattr( STDIN_FILENO, TCSANOW, &oldt);
return c;

}


//
// returns number of rows on the screen
//
int get_screen_rows()
{
        struct winsize w;
        ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
        return w.ws_row;
}

//
// returns number of cols on the screen
//
int get_screen_cols()
{
        struct winsize w;
        ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
        return w.ws_col;
}
