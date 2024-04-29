#ifndef TASK3_H_INCLUDED
#define TASK3_H_INCLUDED
class Client{
public:
    int id;
    string password;
};
class Bank{
public:
    static bool authenticate(int id, string password){
        return true;
    }
     static void performAdminOptions(Client* client){
          cout << "Admin options performed for client with ID " << client->id << endl;
    }
};

class AdminManager {
public:
    static void printClientMenu() {
        cout << "Client Menu" << endl;}
};

 static Client* login(int id, string password) {
        if (Bank::authenticate(id, password))
            {
            Client* client = new Client();
            client->id = id;
            client->password = password;
            return client;
        } else {
            return nullptr;
        }
    }
static bool AdminOptions(Client* client) {

        if (client->id == 1234 ) {
            Bank::performAdminOptions(client);
            return true;
        } else {
            cout << "You are not authorized to access admin options." << endl;
            return false;
        }
    }
};





#endif // TASK3_H_INCLUDED
