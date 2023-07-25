/*
 * ESP01_TYPES.h
 *
 *  Created on: Mar 5, 2023
 *      Author: joseph
 */


/*Basic AT Commands*/
#ifndef WIFI_ESP01_ESP01_TYPES_H_
#define WIFI_ESP01_ESP01_TYPES_H_

typedef enum
{
	RECEIVED_NOT_DONE = 0,
	RECEIVED_DONE = 1,
}EPS01_Receive_Status;


#define AT_TEST_STARTUP_COMMAND			"AT\r\n"
#define AT_TEST_STARTUP_RESPONSE		"OK\r\n"

#define AT_REST_COMMAND					"AT+RST\r\n"
#define AT_REST_RESPONSE				"OK\r\n"

#define AT_VIEW_VERSION_COMMAND			"AT+GMR\r\n"
#define AT_VIEW_VERSION_RESPONSE		"OK\r\n"


#define AT_DEEP_SLEEP_COMMAND			"AT+GSLP\r\n"

#define AT_ECHO_OFF_COMMAND				"ATE0\r\n"
#define AT_ECHO_ON_RESPONSE				"ATE1\r\n"

#define AT_FACTORY_RESET_COMMAND		"AT+RESTORE\r\n"
#define AT_FACTORY_RESET_RESPONSE		"OK\r\n"
//////////////////////////////////////////////////////////////

/*Wi-Fi Related AT Commands*/
typedef enum
{
	ESP01_STATION_MODE = 1,
	ESP01_SOFTAP_MODE = 2,
	ESP01_STATION_SOFTAP_MODE = 3
}ESP_Mode;

#define	 AT_CURRENT_WIFI_STATION_MODE					"AT+CWMODE_CUR=1\r\n"
#define	 AT_CURRENT_WIFI_SOFTAP_MODE					"AT+CWMODE_CUR=2\r\n"
#define	 AT_CURRENT_WIFI_STATION_SOFTAP_MODE			"AT+CWMODE_CUR=3\r\n"
#define	 AT_CURRENT_WIFI_MODE_RSPONSE					"OK"


#define	 AT_CURRENT_STATION_CONNECT_AP					"AT+CWJAP_CUR="

#define	 AT_STATION_DISCONNECT_AP						"AT+CWQAP"
#define	 AT_STATION_DISCONNECT_AP_RESPONSE				"OK"

#define AT_CONFIAG_SOFTAP_MODE							"AT+CWSAP_CUR="
#define AT_CONFIAG_SOFTAP_MODE_RESPONSE					"OK"





#endif /* WIFI_ESP01_ESP01_TYPES_H_ */
