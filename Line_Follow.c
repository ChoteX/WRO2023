
void line_follow_black(int dist)
{
	set_point=42;
	integrator=0;
	int target = 2 * abs(dist) * 360 / (3.14 * 4.95 * 2); //borblis diametri chaiwereba aq
	motor[RG]=speed;
	motor[LF]=speed;

	nMotorEncoder[RG] = 0; // reset right motor encoder
	nMotorEncoder[LF] = 0; // reset left motor encoder

	while (abs(nMotorEncoder[RG]) < target && abs(nMotorEncoder[LF]) < target) {
		int measurement=getColorReflected(LI);
		float dif=PID_line(set_point,measurement);
		setMotorSpeed(LF,30-dif);
		setMotorSpeed(RG,30+dif);
	}
	while(getColorReflected(LI)>20)
	{
		int measurement=getColorReflected(LI);
		float dif=PID_line(set_point,measurement);
		setMotorSpeed(LF,30-dif);
		setMotorSpeed(RG,30+dif);
	}
	stopp();

}



void line_follow_dist(int dist)
{
	set_point=42;
	integrator=0;
	int target = 2 * abs(dist) * 360 / (3.14 * 4.95 * 2); //borblis diametri chaiwereba aq
	motor[RG]=speed;
	motor[LF]=speed;

	nMotorEncoder[RG] = 0; // reset right motor encoder
	nMotorEncoder[LF] = 0; // reset left motor encoder

	while (abs(nMotorEncoder[RG]) < target && abs(nMotorEncoder[LF]) < target) {
		int measurement=getColorReflected(LI);
		float dif=PID_line(set_point,measurement);
		setMotorSpeed(LF,30-dif);
		setMotorSpeed(RG,30+dif);
	}
	//while(getColorReflected(LI)>20)
	//{
	//	int measurement=getColorReflected(LI);
	//	float dif=PID_line(set_point,measurement);
	//	setMotorSpeed(LF,30-dif);
	//	setMotorSpeed(RG,30+dif);
	//}
	stopp();
}




void move_haeri_black()
{
	nMotorEncoder[RG] = 0; // reset right motor encoder
  nMotorEncoder[LF] = 0; // reset left motor encoder
  while(getColorReflected(CL)>17)
  {
  	int measurement=nMotorEncoder[RG]-nMotorEncoder[LF];
  	float dif=PID_haeri(0,measurement);
  	motor[RG]=speed-dif;
  	motor[LF]=speed+dif;
  }
  stopp();
}

void ageba()
{
	resetMotorEncoder(XL);
	sleep(100);
	//setMotorTarget(XL,180,20);
	setMotorSpeed(XL, 20);
	waitUntil(abs(getMotorEncoder(XL))>=175);
	setMotorSpeed(XL, 0);
}

void dadeba()
{
	//setMotorTarget(XL,0,30);
resetMotorEncoder(XL);
	sleep(100);
	//setMotorTarget(XL,180,20);
	setMotorSpeed(XL, -20);
	waitUntil(abs(getMotorEncoder(XL))>=175);
	setMotorSpeed(XL, 0);
}
void fastDadeba()
{
	//setMotorTarget(XL,0,30);
resetMotorEncoder(XL);
	sleep(100);
	//setMotorTarget(XL,180,20);
	setMotorSpeed(XL, -50);
	waitUntil(abs(getMotorEncoder(XL))>=175);
	setMotorSpeed(XL, 0);
}
void sliderOpen()
{
	resetMotorEncoder(SM);
	sleep(100);
	setMotorSpeed(SM, 15);
	waitUntil(abs(getMotorEncoder(SM))>=115);
	setMotorSpeed(SM, 0);
}
void sliderOpenFast()
{
	resetMotorEncoder(SM);
	sleep(100);
	setMotorSpeed(SM, 30);
	waitUntil(abs(getMotorEncoder(SM))>=115);
	setMotorSpeed(SM, 0);
}
void sliderOpenDegree(int degree)
{
	resetMotorEncoder(SM);
	sleep(100);
	setMotorSpeed(SM, 30);
	waitUntil(abs(getMotorEncoder(SM))>=degree);
	setMotorSpeed(SM, 0);
}
void sliderClose()
{
	resetMotorEncoder(SM);
	sleep(100);
	setMotorSpeed(SM, -40);
	waitUntil(abs(getMotorEncoder(SM))>=115);
	setMotorSpeed(SM, 0);
}
void sliderCloseDegree(int degree)
{
	resetMotorEncoder(SM);
	sleep(100);
	setMotorSpeed(SM, -30);
	waitUntil(abs(getMotorEncoder(SM))>=degree);
	setMotorSpeed(SM, 0);
}
void gemisDachera(){
	resetMotorEncoder(SM);
	sleep(100);
	setMotorSpeed(SM, -30);
	waitUntil(abs(getMotorEncoder(SM))>=75);
	setMotorSpeed(SM, 0);
}
void gemisGashveba(){
resetMotorEncoder(SM);
	sleep(100);
	setMotorSpeed(SM, 30);
	waitUntil(abs(getMotorEncoder(SM))>=83);
	setMotorSpeed(SM, 0);
}
void sGemisGashveba(){
	resetMotorEncoder(SM);
	sleep(100);
	setMotorSpeed(SM, 20);
	waitUntil(abs(getMotorEncoder(SM))>=25);
	setMotorSpeed(SM, 0);
}
void sGemisGashvebaOri(){
	resetMotorEncoder(SM);
	sleep(100);
	setMotorSpeed(SM, 20);
	waitUntil(abs(getMotorEncoder(SM))>=25); //20
	setMotorSpeed(SM, 0);
}
void sGemisDachera(){
	resetMotorEncoder(SM);
	sleep(100);
	setMotorSpeed(SM, -30);
	waitUntil(abs(getMotorEncoder(SM))>=25);// 20
	setMotorSpeed(SM, 0);
}
void sGemisDacheraOri(){
	resetMotorEncoder(SM);
	sleep(100);
	setMotorSpeed(SM, -30);
	waitUntil(abs(getMotorEncoder(SM))>=20); //20
	setMotorSpeed(SM, 0);
}
