int numb=0;
void readCube(int index){
	//es funkcia naxulobs kubikis fers da 'colors' massivSi svams 'index' ze
sleep(100);
	getColorAmbient(CL);
	sleep(60);
	getColorName(CL);
	sleep(60);
	/*getColorReflected(CL);
	getColorName(CL);
	sleep(400);
	if(getColorName(CL)==colorGreen){
		numb++;
}
	sleep(100);
	if(getColorName(CL)==colorGreen){
		numb++;
}
	sleep(100);
	if(getColorName(CL)==colorGreen){
		numb++;
}
	sleep(100);
	if(getColorName(CL)==colorGreen){
		numb++;
}
	sleep(50);
	if(getColorName(CL)==colorGreen){
		numb++;
}*/
	sleep(100);
	if(getColorName(CL)==colorBlue){
		playSound(soundBeepBeep);
		sleep(300);
		colors[index]="blue";
}else{
		//playSound(soundBeepBeep);
		//sleep(400);
		colors[index]="green";
}
	numb=0;
	/*getColorReflected(CL);
	sleep(60);
	getColorName(CL);
	sleep(60);*/
	/*if(getColorName(CL)== colorBlue){
		//playSound(soundBeepBeep);
		//sleep(500);
		colors[index]="blue";
		//numBlue++;
	}else{
		colors[index]="green";
		//numGreen++;
	}*/
}
void readTwoCube(int index){
	//es funkcia naxulobs kubikis fers da 'colors' massivSi svams 'index' ze
	if(getColorName(BL)== colorBlue){

		twoColors[index]="blue";
	}else{
		twoColors[index]="green";
	}
}
void setFirstCubeColor(){
	if(numGreen==2){
		colors[0]="blue";
	}else if(numBlue==2){
		colors[0]="green";
	}
}
void displayTwoColors(){
	//es prosta ori kubikis ferebis sesamowmeblad
	displayBigTextLine(1,twoColors[0]);
	displayBigTextLine(3,twoColors[1]);
	//sleep(10000);
}
void displayColors(){
	//es prosta otxi kubikis sesamowmeblad
	//setFirstCubeColor();
	displayBigTextLine(1,colors[0]);
	displayBigTextLine(3,colors[1]);
	displayBigTextLine(5,colors[2]);
	displayBigTextLine(7,colors[3]);
	//sleep(10000);
}
void setChayraOrder(){
	for(int i=0; i<4; i++){
		if(twoColors[0]==colors[i]){
			chayraOrder[i]='b';
			i=5;
			colors[i]="alreadyUsed";
		}
	}
	for(int i=0; i<4; i++){
		if(twoColors[1]==colors[i]){
			chayraOrder[i]='b';
			i=5;
		}
	}
	for(int i=0; i<5; i++){
		if(chayraOrder[i]!='b'){
			chayraOrder[i]='s';
		}
	}
}
