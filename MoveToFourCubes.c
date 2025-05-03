
void moveToFourCubes(){
	new_move_on_line(45, 0, 70); //30
	//motor[RG]=50; motor[LF]=50; sleep(100);
	move_straight(3, 40);
	new_move_on_line_dist(30, 0, 26);
	sliderCloseDegree(76);
	turn(93);
	move_straight(40.8, 30); //40.5 41.7 40.7
	turn(89.5);
	move_straight(6.4, 15); //(6.3, 15) 6.7 7.6 7.4 7.2
}
