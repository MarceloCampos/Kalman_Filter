

#include <Kalman_Filter.h>

float z_real = 480; // the real value "measured"

double frand() 
{ 
    return 100*((rand()/(double)RAND_MAX) - 0.5); 
} 

// create an instance of Kalman Filter
Kalman_Filter Kalman_Filter_i1;
    
void setup() 
{
  Serial.begin(115200);
  
  // initialize values
  Kalman_Filter_i1.kalman_init();
  
  Serial.println("Init Ok");
}

void loop() 
{
     int i;
     float kalman_returned;
     float z_measured;
     
    srand(3565); 
     
    // for ( i=0; i<100; i++ )   // only 100 interations
    for ( ;; )
    {
        // measure Simulated:
        z_measured = z_real + 2 * frand()*0.1; // real simulated measurement plus noise  
 
        //correct the value            
         kalman_returned = Kalman_Filter_i1.kalman_filter( z_measured ) ; 

        // formatted CSV - for use use Serial Chart Graphic 
        Serial.print("0000, "); 
        Serial.print(z_measured);
        Serial.print(", ");           
        Serial.print(kalman_returned);  
        Serial.println("  ");

        //  formatted text for use with Serial Terminal
        //  Serial.print("Medido: "); 
        //  Serial.print(z_measured);
        //  Serial.print(" | Kalman: ");           
        //  Serial.print(kalman_returned);  
        //  Serial.print(" | Erro: " );
        //  Serial.print(z_real - x_est);
        //  Serial.println("  ");
        
        delay(50);
    } 
     
  while(1);
  
}









