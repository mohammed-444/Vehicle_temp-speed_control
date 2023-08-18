/*
 ============================================================================
 Name        : c_final_project.c
 Author      : Mohammed Alaa
 group       :61

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
//--------------------------------------------------------------------------
/* the traffic of the functions is as follow:
 *
 * vehicle_loop-->vehicle_state && vehicle_state_input
 * vehicle_state_input-->sensor_loop
 * sensor_loop-->system_state && sensor_state_input
 * sensor_state_input-->sensor_state_output && traffic_state && set_room_tem && set_engine_temp
 * */
//--------------------------------------------------------------------------
void vehicle_loop(){
	char quit_the_system=1;
	char engine_flag=1;
	int speed=0,room_temp=25, engine_temp=110;
	while(quit_the_system){
		vehicle_state();
		vehicle_state_input(&quit_the_system,&engine_flag, &speed,&room_temp, &engine_temp);
	}

}
//--------------------------------------------------------------------------
void sensor_loop(char* engine_flag,int* speed,int* room_temp,int* engine_temp){
	char quite_the_system=1;
	while(quite_the_system){
		system_state();
		sensor_state_input(&quite_the_system,engine_flag, speed,room_temp, engine_temp);
	}
}
//---------------------------------------------------------------------------
void vehicle_state(){
	printf("--------------------------------------------------\n");
	printf("a. Turn on the vehicle engine\n");
	printf("b. Turn off the vehicle engine\n");
	printf("c. Quit the system\n\n");
	printf("--------------------------------------------------\n");
	}
//--------------------------------------------------------------------------

void system_state(){
	printf("--------------------------------------------------\n");
	printf("a. Turn off the vehicle engine\n");
	printf("b. set the traffic color\n");
	printf("c. Set the room temperature (Temperature Sensor)\n");
	printf("d. Set the engine temperature (Engine Temperature Sensor)\n\n");
	printf("--------------------------------------------------\n");
}
//--------------------------------------------------------------------------
void vehicle_state_input(char* flag,char* engine_flag,int* speed,int* room_temp,int* engine_temp){
	char input;
	scanf(" %c",&input);
	switch (input) {
		case 'a':
			sensor_loop(engine_flag, speed, room_temp, engine_temp);
			break;
		case 'b':
			printf("vehicle engine is off\n\n");
			vehicle_state();
			vehicle_state_input(flag,engine_flag, speed,room_temp, engine_temp);
			break;
		case 'c':
			printf("quit the system is done\n\n");
			*flag=0;
			break;
		default:
			printf("select right input\n\n");
			vehicle_state();
			vehicle_state_input(flag,engine_flag, speed,room_temp, engine_temp);
			break;
	}
}


//--------------------------------------------------------------------------
void sensor_state_input(char* flag,char* engine_flag,int* speed,int* room_temp,int* engine_temp){
	char input;
	scanf(" %c",&input);
	switch (input) {
		case 'a':
			*flag=0;
			break;
		case 'b':
			printf("enter the required color(g-o-r)\n");
			traffic_state(speed);
			sensor_state_output (engine_flag, speed,room_temp, engine_temp);
			break;
		case 'c':
			printf("enter the required room temperature\n");
			set_room_tem(room_temp);
			sensor_state_output (engine_flag, speed,room_temp, engine_temp);
			break;
		case 'd':
			printf("enter the required engine temperature\n");
			set_engine_temp(engine_temp);
			sensor_state_output (engine_flag, speed,room_temp, engine_temp);
			break;
		default:
			printf("select right input\n\n");
			sensor_state_input(flag,engine_flag, speed,room_temp, engine_temp);
			break;
}
}
//--------------------------------------------------------------------------
void traffic_state(int* speed){
	char input;
	scanf(" %c",&input);
	switch (input) {
		case 'g':
			*speed=100;
			break;
		case 'o':
			*speed=30;

			break;
		case 'r':
			*speed=0;

			break;

		default:
			printf("select right input\n\n");
			traffic_state(speed);
			break;
}}
//--------------------------------------------------------------------------
void set_room_tem(int* room_temp){

	scanf("%d",room_temp);

}

//--------------------------------------------------------------------------
void set_engine_temp(int* engine_temp){
	scanf("%d",engine_temp);
}
//--------------------------------------------------------------------------

void sensor_state_output(char* engine_flag,int* speed,int* room_temp,int* engine_temp){
	char AC_flag=1;
	char engine_temp_flag=1;
	printf("--------------------------------------------------\n");
	switch (*engine_flag) {
		case 0:
			printf("Engine is off\n");

			break;
		default:
			printf("Engine is on\n");
			break;
	}
//--------------------------------------
	if(*room_temp>30||*room_temp<10){
		printf("AC is ON\n");
		*room_temp=20;
		AC_flag=0;
	}

	if((*speed)==30&& AC_flag) {
		printf("AC is ON\n");
		*room_temp=(*room_temp)*(5.0/4)+1;
	}
	 if((*speed)==30&&(!AC_flag) ){
			*room_temp=(*room_temp)*(5.0/4)+1;
	}
	 if((*speed)!=30&& AC_flag) {
	 		printf("AC is OFF\n");

	 	}

//--------------------------------------
	printf("vehicle speed : %d Km/Hr\n",*speed);
	printf("Room temperature :%d C\n",*room_temp);
//--------------------------------------
	if(*engine_temp>150||*engine_temp<100) {
		printf("Engine temperature controller is on\n");
	     *engine_temp=125;
	     engine_flag=0;
	}

	 if((*speed)==30&& engine_flag) {
			printf("Engine temperature controller is on\n");
			*engine_temp=(*engine_temp)*(5.0/4)+1;
		}
	 if((*speed)==30&& (!engine_flag)){
				*engine_temp=(*engine_temp)*(5.0/4)+1;
			}
	 if((*speed)!=30&& engine_flag){
			printf("Engine temperature controller is off\n");
	 }
//--------------------------------------
	printf("Engine Temperature :%d C\n\n",*engine_temp);
	printf("--------------------------------------------------\n");

}



//--------------------------------------------------------------------------
int main(void) {
setvbuf(stdout, NULL, _IONBF, 0);
setvbuf(stderr, NULL, _IONBF, 0);

vehicle_loop();

return 0;
}
