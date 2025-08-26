//#define _POSIX_C_SOURCE 200112L
//#define _DARWIN_C_SOURCE


#include <unistd.h>
#include <termios.h>
#include <stdio.h>

void enableRawMode(void) {

	struct termios raw ;

//stdin_fileno not working , i am not able to fetch the valure of this variable
// well the problem was , spelling mistake 	

	tcgetattr(STDIN_FILENO , &raw );
	raw.c_lflag &= ~(ECHO) ;
	tcsetattr(STDIN_FILENO , TCSAFLUSH , &raw );
}

int main(void) {
	
	enableRawMode() ;
	char c;
	while ( read(STDIN_FILENO ,&c , 1 ) == 1 && c != 'q' ) ;
	return 0 ;

}
