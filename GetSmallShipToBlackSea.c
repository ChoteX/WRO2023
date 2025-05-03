void getSmallShipToBlackSea(){
	move_straight(6, 30);
	turn(90);
	new_move_on_line(40, 'r');
	move_straight(5, 40);
	new_move_on_line(40, 'r');
	move_straight(5,40);
	new_move_on_line(40, 'r');
	turn(180);
	new_move_on_line_dist(40, 'l', 20);// pataras agsworeba didis paralelurad
	move_straight(20, -30);
	turn(60);
	move_straight(35, 30);
	turn(-150);
	move_straight(40, 40);
	turn(-90);
	move_straight(10, 30);//gemebs Soris cherdeba
}
