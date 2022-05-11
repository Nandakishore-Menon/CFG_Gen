int main(void) {
    int x = 0 ;
    int y = 0 ;
    for(int i=0; i<5;i++) {
        if ( x < i ) {
            x++;
        }
        else {
            y++;
        }
    }
    x=x+y;
}