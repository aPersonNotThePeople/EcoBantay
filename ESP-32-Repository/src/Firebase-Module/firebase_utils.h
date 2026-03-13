#ifndef FIREBASE_UTILS
#define FIREBASE_UTILS

#define ENABLE_USER_AUTH
#define ENABLE_DATABASE

# include "..\..\..\config.h"
#include <Arduino.h>
#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <FirebaseClient.h>

using AsyncClient = AsyncClientClass;

// Firebase credentials
#define Web_API_KEY "API KEY"
#define DATABASE_URL "DATABASE URL"
#define USER_EMAIL "USER EMAIL"
#define USER_PASS "USER PASS"

// Authentication
extern UserAuth user_auth;

// Firebase components
extern FirebaseApp app;
extern WiFiClientSecure ssl_client;
extern AsyncClient aClient;
extern RealtimeDatabase Database;

// Timing variables for writing database
extern unsigned long lastSendTime;

// Process Data (MUST BE DECLARED FIRST)
void processData(AsyncResult &aResult);

// Functions
void initializeFirebase();
bool checkAuthentication(bool printAuthInfo=false);
void writeDatabase(String database_location, String stringValue, const unsigned long sendInterval);
void writeDatabase(String database_location, int intValue, const unsigned long sendInterval);
void writeDatabase(String database_location, float floatValue, const unsigned long sendInterval);
#endif