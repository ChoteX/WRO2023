void readCubes(){
	//es kitxulobs dasawkisis or kubiks
	/*move_straight(32, -20);
	turnLF(45);
	sleep(1500);
	turnRG(-45);
	sleep(1500);
	move_straight(20, 20);*/


	move_straight(15, 35);
	new_move_on_line_dist(25, 0, 8);
	turnLF(-40);
	turnRG(40);
	readTwoCube(0);
	//displayTwoColors(); //achvenebs pirveli kubikis fers
	//sleep(2000);
	turnLF(-30);
	turnLF(30);
	move_straight(7, 20);
	move_straight(1, -20);
	readTwoCube(1);
	displayTwoColors(); //achvenebs orive kubikis fers
	sleep(3000);
}
