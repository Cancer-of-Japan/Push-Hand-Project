/*
 * How to test encoder with Arduino
 * url: http://osoyoo.com/?p=30267
 */
#define outputA 6
#define outputB 7
int counter = 0; 
int aState;
int aLastState;  

void setup() { 
   pinMode (outputA,INPUT);
   pinMode (outputB,INPUT);
   
   Serial.begin (9600);
   // Reads the initial state of the outputA
   aLastState = digitalRead(outputA);   
} 
void loop() { 
    aState = digitalRead(outputA); // Reads the "current" state of the outputA
    // If the previous and the current state of the outputA are different, that means a Pulse has occured
    /*
    if (aState != aLastState){     
        // If the outputB state is different to the outputA state, that means the encoder is rotating clockwise
        if (digitalRead(outputB) != aState) { 
            counter ++;
        } else {
            counter --;
        }
        Serial.print("Position: ");
        Serial.println(counter);
    }
    */
    int i = 0;
    int Cur_State;
    for(i = 0; i<100; i++){
        Cur_State = digitalRead(outputA);
        if(Cur_State < aState + 100){
            while(Cur_State == Cur_State+1){
                Cur_State = digitalRead(outputA);
                
            }
        }
    }

   aLastState = aState; // Updates the previous state of the outputA with the current state
 }
