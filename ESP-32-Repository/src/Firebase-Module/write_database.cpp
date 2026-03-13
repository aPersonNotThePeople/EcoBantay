#include "firebase_utils.h"

unsigned long lastSendTime = 0;

void writeDatabase(String database_location, String stringValue, const unsigned long sendInterval){
  if (checkAuthentication()){ 
    // Periodic data sending every 10 seconds
    unsigned long currentTime = millis();
    if (currentTime - lastSendTime >= sendInterval){
      // Update the last send time
      lastSendTime = currentTime;
      
      // send a string
      Database.set<String>(aClient, database_location, stringValue, processData, "RTDB_Send_String");
    }
  }
}

void writeDatabase(String database_location, int intValue, const unsigned long sendInterval){
  if (checkAuthentication()){ 
    // Periodic data sending every 10 seconds
    unsigned long currentTime = millis();
    if (currentTime - lastSendTime >= sendInterval){
      // Update the last send time
      lastSendTime = currentTime;
      
      // send a string
      Database.set<int>(aClient, database_location, intValue, processData, "RTDB_Send_String");
    }
  }
}

void writeDatabase(String database_location, float floatValue, const unsigned long sendInterval){
  if (checkAuthentication()){ 
    // Periodic data sending every 10 seconds
    unsigned long currentTime = millis();
    if (currentTime - lastSendTime >= sendInterval){
      // Update the last send time
      lastSendTime = currentTime;
      
      // send a string
      Database.set<float>(aClient, database_location, floatValue, processData, "RTDB_Send_String");
    }
  }
}
