void chagdeba(){
	sliderOpen();
	sliderClose();
}
int position;
int ssnum=0;
int bsnum=0;
char order[4];
void chayra(){
		dif_move_on_line(40, 0, 16);
	//sGemisDacheraOri();
//dif_move_on_line(30, 0, 16);
	sliderCloseDegree(30);
	fastDadeba();
	move_straight(3, -30);
	//sawkisi wertili, iwkeba chayra
	//getColorReflected(CL);
	//sleep(60);
	//getColorName(CL);
	//sleep(60);
	//sleep(1000);
	readCube(0);
	if(colors[0]==twoColors[0]){
		chagdeba();
		twoColors[0]="done";
		bsnum++;
		order[0]=2;
	}else if(colors[0]==twoColors[1]){
		chagdeba();
		twoColors[1]="done";
		bsnum++;
		order[0]=2;
	}else{
		move_straight(17, -30); //8 13
		chagdeba();
		ssnum++;
		order[0]=3;
	}
	sleep(1000);
	readCube(1);
	if((colors[1]==twoColors[0]||colors[1]==twoColors[1])&&bsnum==1){
		move_straight(5, 30); //4
		chagdeba();
		bsnum++;
		order[1]=1;
	}else if((colors[1]==twoColors[0]||colors[1]==twoColors[1])&&bsnum==0){
		move_straight(17, 30);
		chagdeba();
		bsnum++;
		if(colors[1]==twoColors[0]){
			twoColors[0]="done";
		}else if(colors[1]==twoColors[1]){
			twoColors[1]="done";
		}
		order[1]=2;
	}else if(bsnum==1){
		move_straight(17, -30);//9
		chagdeba();
		ssnum++;
		order[1]=3;
	}else if(ssnum==1){
		move_straight(5, -30); //4
		chagdeba();
		ssnum++;
		order[1]=4;
	}
	//if(bsnum!=2){
	sleep(1000);
	readCube(2);
	if(ssnum==2){
		move_straight(22, 30); //10 //30
		chagdeba();
		bsnum++;
		order[2]=2;
	}else if((colors[2]==twoColors[0]||colors[2]==twoColors[1])&&order[1]==3){
		move_straight(22, 30); //12 //18
		chagdeba();
		bsnum++;
		order[2]=1;
	}else if((colors[2]==twoColors[0]||colors[2]==twoColors[1])&&order[1]==2){
		move_straight(5, 30);//4
		chagdeba();
		bsnum++;
		order[2]=1;
	}else{
		if(bsnum==2){
		move_straight(22, -30); //18
		chagdeba();
		order[2]=3;
		ssnum++;
		}else if(bsnum==1&&order[1]==2){
			move_straight(22, -30); //14
		chagdeba();
		order[2]=4;
		ssnum++;
		}else if(bsnum==1&&order[1]==3){
			move_straight(5, -30);
		chagdeba();
		order[2]=4;
		ssnum++;
		}
	}

	if(bsnum==2){
		if(order[2]==3){
			move_straight(5, -30); //6
			chagdeba();
		}else if(order[2]==1){
			move_straight(27, -30); //22
			chagdeba();
		}
		order[3]=4;
	}else if(ssnum==2){
		if(order[2]==4){
			move_straight(27, 30); //26
			chagdeba();
		}else if(order[2]==2){
			move_straight(5, 30);
			chagdeba();
		}
		order[3]=1;
	}

	if(order[3]==1){
		//turnRG(2);
		move_straight(12,30);
		/*setMotorSpeed(LF, 30);
		setMotorSpeed(LF, 20);
		sleep(300);*/

		//chagdeba();
		sliderOpenDegree(120);
		sleep(100);
		sliderCloseDegree(120);
	}else if(order[3]==4){

	//turnRG(2);
		move_straight(38.8,30);
		//setMotorSpeed(LF, 30);
		//setMotorSpeed(LF, 20);
		//sleep(300);

		//chagdeba();
		sliderOpenDegree(120);
		sleep(100);
		sliderCloseDegree(120);
	}
}
