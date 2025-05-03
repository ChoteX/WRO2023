void drive_straight(float distance, int speed123) {

		nMotorEncoder[LF] = 0; // Reset left motor encoder
    nMotorEncoder[RG] = 0; // Reset right motor encoder
    speed=0;
  	set_speed(speed123);
		playSound(soundFastUpwardTones);

		set_speed(speed);
		speed=40;
    int target = distance * 360 / (3.14 * 4.95) ; // Convert distance to encoder ticks
		levani=target;
    while (abs(nMotorEncoder[LF])< target && abs(nMotorEncoder[RG])< target){
        float measurement = nMotorEncoder[LF] + nMotorEncoder[RG];
        float diff =PID_haeri(0, measurement);
        setMotorSpeed(LF, speed -diff);
        setMotorSpeed(RG, speed +diff);
    }
	playSound(soundBeepBeep);
	//setMotorSpeed(LF, 0);
        //setMotorSpeed(RG, 0);
stopp();
}
void drive_straight_black(int speed123) {

		nMotorEncoder[LF] = 0; // Reset left motor encoder
    nMotorEncoder[RG] = 0; // Reset right motor encoder
    //speed=0;
  	//set_speed(speed123);
		playSound(soundFastUpwardTones);

		//set_speed(speed);
		//speed=40;
    //int target = distance * 360 / (3.14 * 4.95) ; // Convert distance to encoder ticks
		//levani=target;
    repeat(forever){
        float measurement = nMotorEncoder[LF] + nMotorEncoder[RG];
        float diff =PID_haeri(0, measurement);
        setMotorSpeed(LF, speed123 -diff);
        setMotorSpeed(RG, speed123 +diff);
        if(getColorReflected(LI)>=60){
        	setMotorSpeed(LF, 0);
        setMotorSpeed(RG, 0);
        break;
      	}
    }
	//playSound(soundBeepBeep);
	//set_speed(0);
  //stopp();
}
