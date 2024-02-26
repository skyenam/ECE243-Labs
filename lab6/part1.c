int main(){
    volatile int *LEDs = (int*) 0xFF200000;
    volatile int *KEYs = (int*) 0xFF200050;
    int edge_cap, KEY0, KEY1;
    while(1){
        edge_cap = *(KEYs + 3);
        KEY0 = edge_cap & 0b1;
        KEY1 = edge_cap & 0b10;
        if (KEY0){
            *LEDs = 0b1111111111;
            *(KEYs + 3) = 0b1111; //reset edge counter
        } else if (KEY1) {
            *LEDs = 0;
            *(KEYs + 3) = 0b1111; //reset edge counter
        }
        
    }

}