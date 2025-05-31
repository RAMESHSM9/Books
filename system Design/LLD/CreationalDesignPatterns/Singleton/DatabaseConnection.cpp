#include <bits/stdc++.h>
using namespace std;

//@ dummy class connecting to Database
//@ This class will hold the connection parameters
//! Will act as the interface for the DB connection
//@ Might as enhance with adapter to consider multiple DBs
class Connection {
public:
  Connection() { cout << "Constructing DB connector" << endl; }
  ~Connection() { cout << "Destroying DB connector" << endl; }
};

class DatabaseConnection {

private:
  Connection dbConnection;
  DatabaseConnection() { cout << "DatabaseConnection Constructor" << endl; }
  DatabaseConnection(const DatabaseConnection &) = delete;
  DatabaseConnection &operator=(const DatabaseConnection &) = delete;

public:
  static DatabaseConnection &getDBConnectionInstance() {
    static DatabaseConnection dbconnector;
    return dbconnector;
  }
  Connection &getConnection() { return dbConnection; }
  ~DatabaseConnection() { cout << "DatabaseConnection Destructor" << endl; }
};

int main() {
  DatabaseConnection &db1 = DatabaseConnection::getDBConnectionInstance();
  cout << " Address of db1 " << &db1 << endl;

  DatabaseConnection &db2 = DatabaseConnection::getDBConnectionInstance();
  cout << " Address of db2 " << &db2 << endl;

  Connection &dbConnector = db1.getConnection();
  cout << " Address of dbConnector " << &dbConnector << endl;

  Connection &dbConnector2 = db2.getConnection();
  cout << " Address of dbConnector " << &dbConnector << endl;
}