#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::ifstream;
using std::cerr;


class Device {
public:
	virtual void poll() = 0; // Abstract class
};

class Electric_Meter : public Device { // "Реализация" получения данных с электросчетчика.
	void poll() override {
		cout << "Electic meter has been polled" << endl; 
	}
};
class Discrete_Signal_Input : public Device { // "Реализация" получения данных с блока вводов дискретных сигналов.
	void poll() override {
		cout << "Discrete signal input has been polled" << endl;
	}
};
class Heating_Control : public Device { // "Реализация" получения данных с блоков управления отоплением.
	void poll() override {
		cout << "Heating control has been polled" << endl;
	}
};

class Configuration {
public:
	void add_device(Device* device) {
		m_devices.push_back(device);
	}
	vector<Device*> get_devices() {
		return m_devices;
	}
private:
	vector<Device*> m_devices;

};

void Read_Devices_From_A_File(Configuration& config, const string& filename) {
	ifstream file(filename);
	if (!file.is_open()) {
		cerr << "Cannot open a file " << filename << endl;
		return;
	}

	string device_name;
	while (std::getline(file, device_name)) {
		if (device_name == "Mercury230" || device_name == "NevaMT314" || device_name == "CE308") {
			config.add_device(new Electric_Meter);
		}
		else if (device_name == "ReallabNL-16HV" || device_name == "PriboRELEKTRO_PRE-16" || device_name == "EnergoservisENMV-1-24") {
			config.add_device(new Discrete_Signal_Input);
		}
		else if (device_name == "OumanS203" || device_name == "OvenTRM232") {
			config.add_device(new Heating_Control);
		}
		else {
			cerr << "Unknown device type: " << device_name << endl;
		}
	}
	file.close();

}

int main() {
	Configuration config;

	Read_Devices_From_A_File(config, "configuration/devices.txt");

	auto devices = config.get_devices();

	for (auto device : devices) {
		device->poll();
	}






	return 0;
}
