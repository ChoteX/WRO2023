void set_speed(int speed1)
{
	int current_speed=speed;
	int gagarini=0;
	while(current_speed>speed1)
	{
		gagarini++;
		current_speed--;
		if(gagarini%4==1 ||gagarini%4==3)
		{
			motor[RG]=current_speed;
			motor[LF]=current_speed;
			wait1Msec(20);
		}
		else
		if(gagarini%4==2  ||gagarini%4==0)
		{
			motor[LF]=current_speed;
			motor[RG]=current_speed;
			wait1Msec(20);
		}
	}

	/////////////////////

	while(current_speed<speed1)
	{
		gagarini++;
		current_speed++;
		if(gagarini%4==1 && gagarini%4==3)
		{
			motor[RG]=current_speed;
			motor[LF]=current_speed;
			wait1Msec(20);
		}
		else
		if(gagarini%4==2 || gagarini%4==0)
		{
			motor[LF]=current_speed;
			motor[RG]=current_speed;
			wait1Msec(20);
		}
	}
	levani=nMotorEncoder[LF];
}




////////////////////////////////////////////////////////////////////////////////////////////////////







void set_speed_LF(int speed)
{
	int current_speed=speed;
	while(current_speed>speed)
	{
		current_speed--;
		motor[LF]=current_speed;
		wait1Msec(3);
	}
	while(current_speed<speed)
	{
		current_speed++;
		motor[LF]=current_speed;
		wait1Msec(1);
	}
}

void stopp()
{
	set_speed(0);
}

//void set_speed(int current_speed_RG,int current_speed_LG,int speed);
//{
//}


//void stopp_RG(int current_speed)
//{
//	set_speed_RG(current_speed,0);
//}
