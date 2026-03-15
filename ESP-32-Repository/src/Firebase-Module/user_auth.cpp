#include "firebase_utils.h"

bool checkAuthentication(bool printAuthInfo){
  if (app.ready()){
    // Print authentication info
    if(printAuthInfo){
    Serial.println("Authentication Information");
    Firebase.printf("User UID: %s\n", app.getUid().c_str());
    Firebase.printf("Auth Token: %s\n", app.getToken().c_str());
    Firebase.printf("Refresh Token: %s\n", app.getRefreshToken().c_str());
    }
    return true;
  }
  return false;
}
