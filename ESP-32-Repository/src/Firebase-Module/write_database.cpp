#include "firebase_utils.h"

unsigned long lastSendTime = 0;
static unsigned long lastTrashCapacitySendTime = 0;

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

void writeTrashCapacityToFirebase(float distanceCm, float capacityPercent) {
  if (!checkAuthentication()) {
    return;
  }

  const unsigned long sendInterval = 1000;
  unsigned long currentTime = millis();
  if (currentTime - lastTrashCapacitySendTime < sendInterval) {
    return;
  }

  lastTrashCapacitySendTime = currentTime;

  Database.set<float>(aClient, "/trash_capacity/distance_cm", distanceCm, processData, "RTDB_Trash_Distance");
  Database.set<float>(aClient, "/trash_capacity/fill_percent", capacityPercent, processData, "RTDB_Trash_Fill");
}
