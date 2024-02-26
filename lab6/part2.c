int main(){
    volatile int * audio_ptr = (int*) 0xFF203040;
    int left, right, fifospace;
    *audio_ptr = 0b1100; //clear input and output fifo
    *audio_ptr = 0; //stop clearing fifos
    while (1){
        fifospace = *(audio_ptr + 1);
        if ((fifospace & 0x000000FF) > 0) {//check RARC for input sample
            //load input microphone channels
            left = *(audio_ptr + 2);
            right = *(audio_ptr + 3);
            //store to output channels
            *(audio_ptr + 2) = left;
            *(audio_ptr + 3) = right;
        }
    }
}