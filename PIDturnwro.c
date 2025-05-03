
//float radius=2.475;
//float width=17.22;//19.5 17.8
float width1=17.25;
float width2=16.68;//855 17.57 17 16.9
//float prev=0;
///float integrator=0;
float gyroscope(int set_point, int measurement){
	float kp=0.5, ki=0.00005, kd=0;
	float error=set_point-measurement;
	float error_change=error-prev;
	float output=error*kp+integrator*ki+error_change*kd;
	integrator+=error;
	prev=error;
	return output;
}
float wheel_degree(int set_point, int measurement){
	float kp=2.5, ki=0, kd=0;
	float error=set_point-measurement;
	float error_change=error-prev;
	float output=error*kp+integrator*ki+error_change*kd;
	integrator+=error;
	prev=error;
	return output;
}
void turn(float degree){
	resetMotorEncoder(LF);
	resetMotorEncoder(RG);
	sleep(100);
	float distance=width2*PI*degree/360;
	float degreetwo=abs((distance/(2*radius*PI))*360);
	if(degree>=0){
		setMotorSpeed(RG, -20);
		setMotorSpeed(LF, 20);
		waitUntil(abs(getMotorEncoder(RG))>=degreetwo&&abs(getMotorEncoder(LF))>=degreetwo);
		setMotorSpeed(LF,0);
		setMotorSpeed(RG,0);
	}else{
		setMotorSpeed(RG, 20);
		setMotorSpeed(LF, -20);
		waitUntil(abs(getMotorEncoder(RG))>=degreetwo&&abs(getMotorEncoder(LF))>=degreetwo);
		setMotorSpeed(RG,0);
		setMotorSpeed(LF,0);
	}
}
void turnSlow(float degree){
	resetMotorEncoder(LF);
	resetMotorEncoder(RG);
	sleep(100);
	float distance=width2*PI*degree/360;
	float degreetwo=abs((distance/(2*radius*PI))*360);
	if(degree>=0){
		setMotorSpeed(RG, -10);
		setMotorSpeed(LF, 10);
		waitUntil(abs(getMotorEncoder(RG))>=degreetwo&&abs(getMotorEncoder(LF))>=degreetwo);
		setMotorSpeed(LF,0);
		setMotorSpeed(RG,0);
	}else{
		setMotorSpeed(RG, 10);
		setMotorSpeed(LF, -10);
		waitUntil(abs(getMotorEncoder(RG))>=degreetwo&&abs(getMotorEncoder(LF))>=degreetwo);
		setMotorSpeed(RG,0);
		setMotorSpeed(LF,0);
	}
}
void fastTurn(int degree){
	resetMotorEncoder(LF);
	resetMotorEncoder(RG);
	sleep(100);
	float distance=width2*PI*degree/360;
	float degreetwo=abs((distance/(2*radius*PI))*360);
	if(degree>=0){
		setMotorSpeed(RG, -30);
		setMotorSpeed(LF, 30);
		waitUntil(abs(getMotorEncoder(RG))>=degreetwo&&abs(getMotorEncoder(LF))>=degreetwo);
		setMotorSpeed(LF,0);
		setMotorSpeed(RG,0);
	}else{
		setMotorSpeed(RG, 30);
		setMotorSpeed(LF, -30);
		waitUntil(abs(getMotorEncoder(RG))>=degreetwo&&abs(getMotorEncoder(LF))>=degreetwo);
		setMotorSpeed(RG,0);
		setMotorSpeed(LF,0);
	}
}
void fastTurnLF(int degree){
	resetMotorEncoder(LF);
	resetMotorEncoder(RG);
	sleep(100);
	float distance=width1*PI*degree/360;
	float degreetwo=abs((distance/(2*radius*PI))*360);
	if(degree>=0){
		setMotorSpeed(RG, -40);
		waitUntil(abs(getMotorEncoder(RG))>=2*degreetwo);
		setMotorSpeed(RG,0);
		setMotorSpeed(LF,0);
	}else{
		setMotorSpeed(RG, 40);
		waitUntil(abs(getMotorEncoder(RG))>=2*degreetwo);
		setMotorSpeed(RG,0);
		setMotorSpeed(LF,0);
	}
}
void turnLF(int degree){
	resetMotorEncoder(LF);
	resetMotorEncoder(RG);
	sleep(100);
	float distance=width1*PI*degree/360;
	float degreetwo=abs((distance/(2*radius*PI))*360);
	if(degree>=0){
		setMotorSpeed(RG, -20);
		waitUntil(abs(getMotorEncoder(RG))>=2*degreetwo);
		setMotorSpeed(RG,0);
		setMotorSpeed(LF,0);
	}else{
		setMotorSpeed(RG, 20);
		waitUntil(abs(getMotorEncoder(RG))>=2*degreetwo);
		setMotorSpeed(RG,0);
		setMotorSpeed(LF,0);
	}
}
void turnRG(int degree){
	resetMotorEncoder(LF);
	resetMotorEncoder(RG);
	sleep(100);
	float distance=width1*PI*degree/360;
	float degreetwo=abs((distance/(2*radius*PI))*360);
	if(degree>=0){
		setMotorSpeed(LF, 20);
		waitUntil(abs(getMotorEncoder(LF))>=2*degreetwo);
		setMotorSpeed(LF,0);
		setMotorSpeed(RG,0);
	}else{
		setMotorSpeed(LF, -20);
		waitUntil(abs(getMotorEncoder(LF))>=2*degreetwo);
		setMotorSpeed(LF,0);
		setMotorSpeed(RG,0);
	}
}
void fastTurnRG(int degree){
	resetMotorEncoder(LF);
	resetMotorEncoder(RG);
	sleep(100);
	float distance=width1*PI*degree/360;
	float degreetwo=abs((distance/(2*radius*PI))*360);
	if(degree>=0){
		setMotorSpeed(LF, 40);
		waitUntil(abs(getMotorEncoder(LF))>=2*degreetwo);
		setMotorSpeed(LF,0);
		setMotorSpeed(RG,0);
	}else{
		setMotorSpeed(LF, -40);
		waitUntil(abs(getMotorEncoder(LF))>=2*degreetwo);
		setMotorSpeed(LF,0);
		setMotorSpeed(RG,0);
	}
}
