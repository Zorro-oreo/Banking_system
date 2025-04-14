#pragma once  
#include <iostream>  
#include <vector>  

using namespace std;  

class Client {
public:  
   Client();  

   ~Client();  

   void clients();

   void displayClients();  

   void registerAccount(const string& username, const string& password);  

   bool login(const string& username, const string& password);  

   bool deleteAccount(const string& username, const string& password);  

   bool resetPassword(const string& username, long long id);  

   bool changePassword(const string& username, const string& oldPassword, const string& newPassword);  

};