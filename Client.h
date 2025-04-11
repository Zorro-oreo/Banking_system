#pragma once  
#include <iostream>  
#include <vector>  

using namespace std;  

class Client {  
private: // Change from private to protected to allow access in derived classes or friend classes  
   vector<string> usernames;
   vector<string> passwords;  
   vector<long long> ids;  
   const string filename = "users.dat";  

   void loadUsers();  

   void saveUsers();  

   long long generateRandomId();  

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