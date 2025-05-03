void changeSide(int s){
	resetMotorEncoder(LF);
	resetMotorEncoder(RG);
	sleep(100);
	if(s==0){
		float distance=17.25*PI*30/360;
		float degreetwo=abs((distance/(2*radius*PI))*360);
		setMotorSpeed(RG, 50);
		waitUntil(abs(getMotorEncoder(RG))>=2*degreetwo);
		setMotorSpeed(RG,0);
		setMotorSpeed(LF,0);

		setMotorSpeed(LF, 50);
		waitUntil(abs(getMotorEncoder(LF))>=2*degreetwo);
		setMotorSpeed(LF,0);
		setMotorSpeed(RG,0);
	}else if(s==1){
		float distance=17.25*PI*30/360;
		float degreetwo=abs((distance/(2*radius*PI))*360);
		setMotorSpeed(LF, 50);
		waitUntil(abs(getMotorEncoder(LF))>=2*degreetwo);
		setMotorSpeed(LF,0);
		setMotorSpeed(RG,0);

		setMotorSpeed(RG, 50);
		waitUntil(abs(getMotorEncoder(RG))>=2*degreetwo);
		setMotorSpeed(RG,0);
		setMotorSpeed(LF,0);

	}
}
void startLeft(){
	setMotorSpeed(RG, 40);
	setMotorSpeed(LF, 30);
	sleep(500);
	setMotorSpeed(RG, 0);
	setMotorSpeed(LF, 0);
}
void startRight(){
	move_straight(10, 40);
}
void move01l(){
	new_move_on_line_dist(40, 1, 20);
}
void move01r(){
	new_move_on_line(40, 1,15);

}
