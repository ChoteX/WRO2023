void fuelAndReadCubes(){
	//gemisGashveba();
	sliderOpenDegree(83);
	//turnLF(-30);
	//turnRG(30);
	setMotorSpeed(RG, 45);//30
	setMotorSpeed(LF, 30);//20
	sleep(350);
	//setMotorSpeed(RG, 0);
	//setMotorSpeed(LF, 0);
	new_move_on_line_dist(30, 1, 6);
	move_on_line(30, 1);
	move_straight(5, 20);
	readTwoCube(0);
	move_straight(5, 20);
	readTwoCube(1);
	displayTwoColors();
	//sleep(1000);
	move_straight(4, 70);
	//gemisDachera();
	sliderCloseDegree(78); //74
	move_straight(12.2, -30); //10.5
	turnSlow(90);
	//move_straight(6, 30);
}
