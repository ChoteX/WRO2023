
void change_loc(int a, int b)
{
	a--;
	b--;
	move_straight(abs(didi[b]-didi[a]),sgn(didi[b]-didi[a])*30);
}
void adgili(int index)
{

	if(index!=1800);

	readCube(index-1);
			if(colors[index-1]=="blue")
				playSound(soundBeepBeep);
		else
			playSound(soundLowBuzz);
	if(colors[index-1]==twoColors[0] || colors[index-1]==twoColors[1])
	{

		if(colors[index-1]==twoColors[0])
			twoColors[0]=iakobi;
		else
			twoColors[1]=iakobi;
		change_loc(loc,mariami);
		loc=mariami;
		mariami++;
	}
	else
	{
		change_loc(loc,nikita);
		loc=nikita;
		nikita++;
	}
}
void lela()
{
	loc=1;
	adgili(1);
	chagdeba();
	adgili(2);
	chagdeba();
	adgili(3);
	chagdeba();
	adgili(4);
	chagdeba();
	change_loc(loc,5);
	chagdeba();

}



void change_hand(int speed,float cur,float angel)
{
	resetMotorEncoder(SM);
	sleep(100);
	setMotorSpeed(SM, sgn(angel-cur)*speed);
	waitUntil(abs(getMotorEncoder(SM))>=abs(angel-cur));//100
	setMotorSpeed(SM, 0);
}
