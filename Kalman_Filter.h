/*
	Kalman_Filter.h
	
Lib Kalman Filter 
by Marcelo Campos
Garoa Hacker Club

baseado: http://adrianboeing.blogspot.com.br/2010/05/kalman-filters.html
Wikipedia: https://en.wikipedia.org/wiki/Kalman_filter

versão 0 - Março/2016	
	
*/	

class Kalman_Filter
{
private:
	//initial values for the kalman filter 
	float x_est_last; // Global 
	float P_last ; 
	//the noise in the system 
	float Q ;
	float R ;
	float K; 
	float P; 
	float P_temp; 
	float x_temp_est; 
	float x_est; 			
	
public:
	void kalman_init (void);
	float kalman_filter (float value);
	
};

