
// zogadi PID-s struqtura
struct PID
{
	// sasurveli shedegi
	float sp;

	// koeficientebi
	float kp,ki,kd;

	// PID-s I nawili
	float integrator;
	// PID-s D nawili
	float differentiator;

	// wina errori
	float last_error;

	// integratoris limitebi
	float max_lim,min_lim;

	// 1 / (dzravis sixshire)
	float T;

	// 1 / (low-pass filtris sixshire)
	float tau;

	// PID-s shedegi
	float out;
}

// PID-s inicializacia (sawyisi mnishvnelobebis miniweba)
void PID_set(PID* name,float Kp,float Ki,float Kd,float Tau,float sp)
{
	// set point-is miniweba
	name->sp = sp;

	// koeficientebis miniweba
	name->kp = Kp;
	name->ki = Ki;
	name->kd = Kd;

	// sawyisis ganuleba
	name->integrator = 0;
	name->differentiator = 0;
	name->last_error = 0;

	// limitebis miniweba
	name->max_lim =  40;
	name->min_lim = -40;

	// sixshireebis miniweba
	name->T = 0.02;
	name->tau = Tau;

	// pasuxis ganuleba
	name->out = 0;
}

// PID-s erti gamotvla
float PID_upd(PID* name, float measurement) //void iko
{
	// cdomilebis gamotvla
	float error = name->sp - measurement;

	// PID-s P nawilis gamotvla
	float proportional = name->kp * error;

	// PID-s I nawilis gamotvla
	name->integrator += (name->ki*name->T)/2.0*(error+name->last_error);

	// PID-s D nawilis gamotvla
	name->differentiator =
		(2.0*name->kd)/(2.0*name->tau+name->T)*(error-name->last_error) +
		(2.0*name->tau-name->T)/(2.0*name->tau+name->T)*name->differentiator;

	// erroris damaxsovreba
	name->last_error = error;

	// integratoris dinamic clamping (integratoris shezgudva)
	if (name->integrator > name->max_lim - proportional - name->differentiator)
			name->integrator = name->max_lim - proportional - name->differentiator;
	if (name->integrator < name->min_lim + proportional + name->differentiator)
			name->integrator = name->min_lim + proportional + name->differentiator;

	// pasuxis datvla
	name->out = proportional + name->integrator + name->differentiator;
	return name->out;
}
struct PID new_line_follower;
struct PID dif_lf;
struct PID fast_line_follower;
struct PID blue_lf;
void new_move_on_line(int speed, int side, float dist){
	new_line_follower.integrator=0;
	new_line_follower.differentiator = 0;
	new_line_follower.last_error = 0;
	if(speed<65)
	{
		resetMotorEncoder(LF);
		resetMotorEncoder(RG);
		sleep(200);
		int degree=(dist/(2*radius*PI))*360;
		while(abs(getMotorEncoder(RG))<degree&&abs(getMotorEncoder(LF))<degree){
			float measurement=getColorReflected(LI);
			float output=PID_upd(&new_line_follower, measurement);
			if(side==0){
				setMotorSpeed(LF, speed+output);
				setMotorSpeed(RG, speed-output);
			}else if(side==1){
				setMotorSpeed(LF, speed-output);
				setMotorSpeed(RG, speed+output);
			}
		}
		repeat(forever){
			float measurement=getColorReflected(LI);
			float output=PID_upd(&new_line_follower, measurement);
			if(side==0){
				setMotorSpeed(LF, speed+output);
				setMotorSpeed(RG, speed-output);
			}else if(side==1){
				setMotorSpeed(LF, speed-output);
				setMotorSpeed(RG, speed+output);
			}
			if(getColorReflected(LI)<16){
				setMotorSpeed(LF, 0);
				setMotorSpeed(RG, 0);
				break;
			}
		}
	}
	else
		{
		resetMotorEncoder(LF);
		resetMotorEncoder(RG);
		sleep(200);
		int degree=(dist/(2*radius*PI))*360;
		while(abs(getMotorEncoder(RG))<degree&&abs(getMotorEncoder(LF))<degree){
			float measurement=getColorReflected(LI);
			float output=PID_upd(&fast_line_follower, measurement);
			if(side==0){
				setMotorSpeed(LF, speed+output);
				setMotorSpeed(RG, speed-output);
			}else if(side==1){
				setMotorSpeed(LF, speed-output);
				setMotorSpeed(RG, speed+output);
			}
		}
		repeat(forever){
			float measurement=getColorReflected(LI);
			float output=PID_upd(&fast_line_follower, measurement);
			if(side==0){
				setMotorSpeed(LF, speed+output);
				setMotorSpeed(RG, speed-output);
			}else if(side==1){
				setMotorSpeed(LF, speed-output);
				setMotorSpeed(RG, speed+output);
			}
			if(getColorReflected(LI)<16){
				setMotorSpeed(LF, 0);
				setMotorSpeed(RG, 0);
				break;
			}
		}
	}
}
void new_move_on_line_dist(int speed, int side, float dist){
	if(speed<65)
	{
		new_line_follower.integrator=0;
		new_line_follower.differentiator = 0;
		new_line_follower.last_error = 0;
		resetMotorEncoder(LF);
		resetMotorEncoder(RG);
		sleep(100);
		int degree=(dist/(2*radius*PI))*360;
		repeat(forever){
			float measurement=getColorReflected(LI);
			float output=PID_upd(new_line_follower, measurement);
			if(side==0){
				setMotorSpeed(LF, speed+output);
				setMotorSpeed(RG, speed-output);
			}else if(side==1){
				setMotorSpeed(LF, speed-output);
				setMotorSpeed(RG, speed+output);
			}
			if(abs(getMotorEncoder(RG))>=degree&&abs(getMotorEncoder(LF))>=degree){
				setMotorSpeed(LF, 0);
				setMotorSpeed(RG, 0);
				break;
			}
		}
	}
	else
	{
		new_line_follower.integrator=0;
		new_line_follower.differentiator = 0;
		new_line_follower.last_error = 0;
		resetMotorEncoder(LF);
		resetMotorEncoder(RG);
		sleep(100);
		int degree=(dist/(2*radius*PI))*360;
		repeat(forever){
			float measurement=getColorReflected(LI);
			float output=PID_upd(fast_line_follower, measurement);
			if(side==0){
				setMotorSpeed(LF, speed+output);
				setMotorSpeed(RG, speed-output);
			}else if(side==1){
				setMotorSpeed(LF, speed-output);
				setMotorSpeed(RG, speed+output);
			}
			if(abs(getMotorEncoder(RG))>=degree&&abs(getMotorEncoder(LF))>=degree){
				setMotorSpeed(LF, 0);
				setMotorSpeed(RG, 0);
				break;
			}
		}
	}
}



void new_move_on_line_dist_rev(int speed, int side, float dist){
	new_line_follower.integrator=0;
	new_line_follower.differentiator = 0;
	new_line_follower.last_error = 0;
	resetMotorEncoder(LF);
	resetMotorEncoder(RG);
	sleep(100);
	int degree=(dist/(2*radius*PI))*360;
	repeat(forever){
		float measurement=getColorReflected(LI);
		float output=PID_gyro(37, measurement);
		if(side==0){
			setMotorSpeed(LF, speed-output);
			setMotorSpeed(RG, speed+output);
		}else if(side==1){
			setMotorSpeed(LF, speed+output);
			setMotorSpeed(RG, speed-output);
		}
		if(abs(getMotorEncoder(RG))>=degree&&abs(getMotorEncoder(LF))>=degree){
			setMotorSpeed(LF, 0);
			setMotorSpeed(RG, 0);
			break;
		}
	}
}
void dif_move_on_line(int speed, int side, int dis){
	blue_lf.integrator=0;
	blue_lf.differentiator = 0;
	blue_lf.last_error = 0;
	resetMotorEncoder(LF);
	resetMotorEncoder(RG);
	sleep(100);
	int degree=(dis/(2*radius*PI))*360;
	while(abs(getMotorEncoder(RG))<degree&&abs(getMotorEncoder(LF))<degree){
		float measurement=getColorReflected(LI);
		float output=PID_upd(blue_lf, measurement);
		if(side==0){
			setMotorSpeed(LF, speed+output);
			setMotorSpeed(RG, speed-output);
		}else if(side==1){
			setMotorSpeed(LF, speed-output);
			setMotorSpeed(RG, speed+output);
		}
	}
	repeat(forever){
		float measurement=getColorReflected(LI);
		float output=PID_upd(blue_lf, measurement);
		if(side==0){
			setMotorSpeed(LF, speed+output);
			setMotorSpeed(RG, speed-output);
		}else if(side==1){
			setMotorSpeed(LF, speed-output);
			setMotorSpeed(RG, speed+output);
		}
		if(getColorReflected(LI)>70){
			setMotorSpeed(LF, 0);
			setMotorSpeed(RG, 0);
			break;
		}
		//sleep(50);
	}
}
void dif_move_on_line_dist(int speed, int side, float dist){
	resetMotorEncoder(LF);
	resetMotorEncoder(RG);
	sleep(100);
	int degree=(dist/(2*radius*PI))*360;
	repeat(forever){
		float measurement=getColorReflected(LI);
		float output=PID_upd(dif_lf, measurement);
		if(side==0){
			setMotorSpeed(LF, speed+output);
			setMotorSpeed(RG, speed-output);
		}else if(side==1){
			setMotorSpeed(LF, speed-output);
			setMotorSpeed(RG, speed+output);
		}
		if(abs(getMotorEncoder(RG))>=degree&&abs(getMotorEncoder(LF))>=degree){
			setMotorSpeed(LF, 0);
			setMotorSpeed(RG, 0);
			break;
		}
	}
}
