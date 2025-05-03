void moveBS(){
	//new_move_on_line_dist(30, 1, 15);

	motor[RG]=50; motor[LF]=50; sleep(100);

	new_move_on_line(50, 1,90); //left?
	//sleep(2000);
	motor[RG]=50; motor[LF]=50; sleep(100);
	new_move_on_line_dist(50, 1, 32.8); //36 32.7
	turnRG(73);//70 65 //70 +3 72 70 68 70 74
	sliderOpenDegree(7);
	turnLF(-78);//85 //75  +3 77 75 73 75 81 (80);
	//gemisGashveba();
	sliderOpenDegree(71);
	move_straight(8.2, 20);//7
	move_straight(7.5, -40);
	turn(-90);
	move_straight(10.7, 40);//(10.2)
	turn(-90);
	//new_move_on_line_dist(30, 0, 10);

	//new_move_on_line(40, 0, 15);
	//move_straight(6, 40);
	//gemisDachera();
	//sliderCloseDegree(83);


}
