#ifndef __DATALOGGER_H__
#define __DATALOGGER_H__

#include <Arduino.h>
#include <FS.h>

class Datalogger {
  public:
    Datalogger();
    void logError(char* errorStr);
  private:
    const static unsigned int NUM_JSON_FILES = 4;
    const static unsigned int NUM_CSV_FILES = 4;
    constexpr static char csv_files[NUM_CSV_FILES][20]= {"/hour.csv","/day.csv","/aut-irrig.csv","/man-irrig.csv"};
    constexpr static char json_files[NUM_JSON_FILES][20]= {"/hour.json","/day.json","/aut-irrig.json","/man-irrig.json"};
    constexpr static char csv_files_headers[NUM_CSV_FILES][80] = {"ts,tmp_min,tmp_max,tmp_avg,hum_min,hum_max,hum_avg",
                                                   	   	   	   	  "ts,kc,eto,irrig_duration",
																  "ts_init,ts_stop,duration",
																  "ts_init,ts_stop,duration"};
    void loadFiles();
};

#endif