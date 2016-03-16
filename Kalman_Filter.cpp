/*

Lib Kalman Filter 
by Marcelo Campos
Garoa Hacker Club

baseado: http://adrianboeing.blogspot.com.br/2010/05/kalman-filters.html
Wikipedia: https://en.wikipedia.org/wiki/Kalman_filter

versão 0 - Março/2016

*/


#include "Kalman_Filter.h"

void Kalman_Filter::kalman_init (void)
{
    x_est_last = 485;	// valor esperado 1a medição / interação
    P_last = 0; 
    
    Q = 0.03;    // covariância do processo
    R = 0.707;   // covariância do ruído
} 

float Kalman_Filter::kalman_filter (float value)
{   
  //do a prediction 
  x_temp_est = x_est_last; 
  P_temp = P_last + Q; 
  //calculate the Kalman gain 
  K = P_temp * (1.0/(P_temp + R));
  
  x_est = x_temp_est + K * (/*z_measured*/value - x_temp_est);  
  P = (1- K) * P_temp; 
  //we have our new system 
  
  //update our last's 
  P_last = P; 
  x_est_last = x_est; 
        
  return x_est;
      
}









