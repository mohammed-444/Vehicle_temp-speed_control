# Vehicle_temp-speed_control
control the speed and temperature of the motor and the vehicle

 * vehicle_loop-->vehicle_state && vehicle_state_input
 * vehicle_state_input-->sensor_loop
 * sensor_loop-->system_state && sensor_state_input
 * sensor_state_input-->sensor_state_output && traffic_state && set_room_tem && set_engine_temp
