#include <mosquittopp.h>
#include <string>
#include <iostream>
#include <thread>
#include <cstring>

using namespace mosqpp;
using namespace std;

class MyMqttWrapper : public mosquittopp
{
public:
    MyMqttWrapper(char const* id, const char* host, int port);

    void on_connect(int rc);
    void on_message(const struct mosquitto_message* message);
    bool send_message(const  char* message);
};

MyMqttWrapper::MyMqttWrapper(const char* id, const char* host, int port) : mosquittopp(id)
{
    int keepalive = 60;
    connect(host, port, keepalive);
};

void MyMqttWrapper::on_connect(int rc)
{
    if (rc == 0)
    {
        subscribe(NULL, "M30-212B-18/Game");
    }
}

void MyMqttWrapper::on_message(const struct mosquitto_message* message) {
    setlocale(LC_CTYPE, "rus");
    if (!strcmp(message->topic, "M30-212B-18/Game")) {
        printf("%s", message->payload);
    }
};

bool MyMqttWrapper::send_message(const  char* message)
{
    int ret = publish(NULL, "M30-212B-18/Game", (int)strlen(message), message, 2, false);
    return (ret == MOSQ_ERR_SUCCESS);
}

int main()
{
	string a;
	cout << "Hello world!" << endl;
    MyMqttWrapper MQTT = MyMqttWrapper("flower", "test.mosquitto.org",1883);
	
	while (cin>>a && a!="close")
	{   }
}