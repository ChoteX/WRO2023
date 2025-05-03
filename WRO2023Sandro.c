#pragma config(Sensor, S2,     CL,             sensorEV3_Color, modeEV3Color_Color)
#pragma config(Sensor, S3,     LI,             sensorEV3_Color)
#pragma config(Sensor, S4,     BL,             sensorEV3_Color, modeEV3Color_Color)
#pragma config(Motor,  motorA,          SM,            tmotorEV3_Large, PIDControl, encoder)
#pragma config(Motor,  motorB,          RG,            tmotorEV3_Medium, PIDControl, encoder)
#pragma config(Motor,  motorC,          LF,            tmotorEV3_Medium, PIDControl, reversed, encoder)
#pragma config(Motor,  motorD,          XL,            tmotorEV3_Large, PIDControl, encoder)



//CL- marcxena, semotrialebuli light sensori
//LI_marjvena, line follower-is light sensori
//dasawkisSi xeli aweulia, slideric_aweuli
int integrator=0,P_error=0,set_point=0,levani;
string iakobi="8";
int numGreen=0;
int numBlue=0;
string colors[5];
char chayraOrder[5];
string twoColors[2];
int location[10];


int mariami=1; int nikita=3;
int didi[7]={1,-3,-20,-25,13,   0,0};
int loc;

int i=0;

location[1]=1; location[2]=5; location[5]=-6; location[3]=10; location[4]=13;
int speed=40;
int colorLeft=0;
int BSNum=0;
int SSNum=0;
int fix[5];

#include "SetMotorSpeed.c"
#include "PID.c"
#include "Line_Follow.c"
#include "Move_haeri.c"
#include "MovingLineStraigthSandro.c"
#include "PIDturnwro.c"
#include "CubeColorsFunctions.c"
#include "goodPID.c"
#include "Chayra.c"
#include "mari.c"
#include "chayraFunctions.c"
//chapters
#include "FuelAndReadCubes.c"
#include "MoveBS.c"
#include "MoveToFourCubes.c"
#include "GetFourCubes.c"
#include "GetWhiteCube.c"
#include "GetSmallShip.c"
#include "GetBigship.c"
#include "GetSmallShipToBlackSea.c"
#include "DamatebitiFunqciebi2dgistvis.c"
#include "park.c"

task main()

{

colors[4]="white";
chayraOrder[4]='b';
	
PID_set(&new_line_follower, 0.35, 0.0003, 1.2, 0.5, 37); //0.45 0.5//old
 
PID_set(&dif_lf, 0.15, 0.000005, 0.2, 0.5, 27);
PID_set(&blue_lf, 0.35, 0.0005, 1.2, 0.5, 33);
PID_set(&fast_line_follower, 0.6, 0, 0.18, 0.0003, 36);
twoColors[0]="green"; twoColors[1]="green"

changeSide(1);
fuelAndReadCubes();
getBigShip();

getSmallShip();
sliderCloseDegree(13);
	
moveToFourCubes();
getFourCubes();
getWhiteCube();

getSmallShipToBlackSea();
	
chayra();
mate();
	
	
}
