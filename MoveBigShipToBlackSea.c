void moveBigShipToBlackSea(){
	turn(90);
	move_straight(60, 40);
	move_straight_blackwhite(40, 1);
	move_straight(6, 30);
	turn(90);
	new_move_on_line(40, 'l');
	turn(90);
	new_move_on_line_dist(40, 'l', 45);
	move_straight(17, -30);
	turn(-60);
	move_straight(29, 30);
	turn(150);
	move_straight(40, 35);
}
