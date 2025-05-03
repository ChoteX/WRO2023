void getSmallShip(){
	//new_move_on_line_dist(30, 0, 15);
	new_move_on_line(40, 0, 15);
	move_straight(3.5, 20);
	turn(90);
	//new_move_on_line_dist(30, 0, 15);
	new_move_on_line(40, 0, 20);
	move_straight(2, 25);
	turn(-90);
	//sGemisGashveba();
	sliderOpenDegree(23);
	new_move_on_line(35, 1, 14);
	setMotorSpeed(LF, 20);
	setMotorSpeed(RG, 20);
	sleep(500);
	//sGemisDachera();
	sliderCloseDegree(20);
	sleep(200);
	setMotorSpeed(LF, 0);
	setMotorSpeed(RG, 0);
	turn(-90);
	move_straight(9,50);//40
	turn(-90);
	move_straight_blackwhite(50, 1);//40
	move_straight(7, 40);
	turn(90);
	new_move_on_line(40, 0, 20);
	move_straight(5, 30);
	//setMotorSpeed(LF, 35);
	//setMotorSpeed(RG, 35);
	//sleep(100);
	new_move_on_line_dist(50,0,47.5); //30
	turn(90);
	move_straight(3.1, 20);
	//sGemisGashvebaOri();
	sliderOpenDegree(15);//21
	move_straight(9, -20);
	turn(-90);
	//move_straight(5, -25);
	//dif_move_on_line(40, 0, 16);
	//move_straight(7, 30);
	//sGemisDachera();

	//new_move_on_line(35, 0, 13);

	/*turn(90);
	new_move_on_line(40, 0, 15);
	move_straight(5, 20);
	new_move_on_line_dist(40, 0, 32);
	turn(90);
	move_straight(15, 30);
	sGemisGashvebaOri();
	/*move_straight(21, 30);
	turn(-90);
	dif_move_on_line(25, 0, 13);*/
	/*turn(90);
	new_move_on_line(40, 0,20);
	move_straight(5, 20);
	new_move_on_line_dist(40, 0, 22);
	turn(-90);
	move_straight(37, 40);
	turn(-87); //-90
	setMotorSpeed(LF, 0);
	setMotorSpeed(RG, 0);
	sGemisGashveba();
	setMotorSpeed(LF, 40);
	setMotorSpeed(RG, 40);
	sleep(900);
	sGemisDachera();
	sleep(900);
	setMotorSpeed(LF, 0);
	setMotorSpeed(RG, 0);
	turn(-90);
	move_straight_blackwhite(30, 1);
	move_straight(6, 20);
	turn(90);
	//new_move_on_line_dist(30, 0, 10);
	//new_move_on_line_dist(30, 0, 15);
	new_move_on_line(30, 0, 8);
	move_straight(5, 30);
	new_move_on_line_dist(30,0,25);//28 25
	//
	//turn(90);
	//move_straight(5, 20);
	//
	turnRg(70);
	turnLF(-73);
	sGemisGashvebaOri();
	sleep(500);
	move_straight(2, -20);
	turnLF(73); //67
	turnRG(-70);//65
	turnLF(-42);
	turnRG(42);
	//dif_move_on_line_dist(25, 0, 13);
	dif_move_on_line(25, 0, 13);*/
}
