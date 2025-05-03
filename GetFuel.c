void getFuel(){
	//iwyebs dasawyisidan da gems ajaxebs fuel station-s
	/*move_straight(15, 20);
	move_on_line(9, 1, 850); //20
	turnLF(-27);
	turnRG(27);
	drive_straight(12, 35); *///aq move-straight jobia albat (shenelebis gareSe);9
	//gemis_dachera();

	//move_straight(12, 30);
	//move_straight(12, -30);
	//turnRG(20);
	//turnLF(-20);
	/*drive_straight(24, 40);
	//sleep(2000);
	sliderOpen();
	turnRG(-20);
	move_straight(8, 20);
	turnRG(20);
	turnLF(-10);
	sliderClose();
	move_straight(2, -20);
	turnLF(10)
	move_straight(10, 25);
	readCube(0);
	move_straight(5, -25);
	readCube(1);
	displayTwoColors();
	sleep(5000);
	//sliderOpen();
	/*move_straight(12, -30);
	//sliderclose();
	turnLF(-48);
	sleep(2000);
	turnRG(48);
	move_straight(9, 30);
	sliderClose();
	sleep(3000);
	readTwoCube(0);
	sleep(1000);
	move_straight(6.5,-40);
	readTwoCube(1);
	sleep(1000);
	displayTwoColors();
	sleep(5000);*/
	//move_straight(4,-40);
	//turn(90);
	//line_follow_black(130);
	/*turnLF(-29);
	turnRG(29);
	move_straight(10
	move_straight_blackwhite(20, 0);*/
	//move_straight(1
	gemisGashveba();
	move_straight(10, 30);
	move_on_line(20, 0,0);
	move_straight(6, -20);
	turnLf(-35);
	turnRG(35);
	sleep(1000);
	move_straight(14, 40);
	gemisDachera();
	//move_straight(6, 40);
	move_straight(2, -10);
	sleep(1000);
	readTwoCube(0);
	move_straight(5, -20);
	sleep(1000);
	readTwoCube(1);
	displayTwoColors();
	sleep(2000);
	move_straight(3.5, -20);
	turn(95);
	motor[RG]=0;
	motor[LF]=0;
	sleep(4000);
	move_straight(3.5, 20);
	speed=70;
	line_follow_black(93);
	playSound(soundBeepBeep);
	move_straight(3.5, 20);
	line_follow_dist(40);
	turnRG(70);
	turnLF(-73);
	//speed=70;
	//line_follow_black(130);

	//new_move_on_line_dist(20, 1, 30);
}
