
float PID_line(float set_point, float measurement)
{
	float error=(set_point-measurement);
	float abc= error*0.5+integrator*0.000001+(error-P_error)*25;
	if(abc<=60 && abc>=-80)
		integrator+=error;
	P_error=error;
	return abc;
}



float PID_gyro(float set_point, float measurement)
{
	float error=(set_point-measurement);
	float abc= error*0.3+integrator*0.00000+(error-P_error)*0.0;
	if(abc<=60 && abc>=-80)
		integrator+=error;
	P_error=error;
	return abc;
}


float PID_gyro_turn(float set_point, float measurement)
{


	float error=(set_point-measurement);
	float abc= error*0.1+integrator*0.1+(error-P_error)*0.2;
	if(abc<=60 && abc>=-80)
		integrator+=error;
	P_error=error;
	return abc;
}


float PID_haeri(float set_point, float measurement)
{


	float error=(set_point-measurement);
	float abc= error*1.25+integrator*0.00001+(error-P_error)*2.75; //  0.0001
	if(abc<=60 && abc>=-80)
		integrator+=error;
	P_error=error;
	return abc;
}
