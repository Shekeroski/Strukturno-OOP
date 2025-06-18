#include <iostream>
#include <string>
#include <fstream>
#include <cctype>
using namespace std;

void writeToFile() {
    ofstream file("text.txt");
    char c;
    while ((c = cin.get()) != '#') {
        file.put(c);
    }
    file.close();
}

class WeatherData {
private:
    string location_id;
    string timestamp;
    double temperature;
    int humidity;
    double wind_speed;
    int precipitation;

public:
     WeatherData() {}
    WeatherData(string location_id, string timestamp, double temperature, int humidity,double wind_speed,int precipitation) {
         this->location_id = location_id;
         this->timestamp = timestamp;
         this->temperature = temperature;
         this->humidity = humidity;
         this->wind_speed = wind_speed;
         this->precipitation = precipitation;
     }
    WeatherData(const WeatherData &weather) {
         this->location_id = weather.location_id;
         this->timestamp = weather.timestamp;
         this->temperature = weather.temperature;
         this->humidity = weather.humidity;
         this->wind_speed = weather.wind_speed;
         this->precipitation = weather.precipitation;
     }
    WeatherData &operator=(const WeatherData &other) {
         if (this != &other) {
             this->location_id = other.location_id;
             this->timestamp = other.timestamp;
             this->temperature = other.temperature;
             this->humidity = other.humidity;
             this->wind_speed = other.wind_speed;
             this->precipitation = other.precipitation;
         }
         return *this;
     }
    friend istream &operator>>(istream &is, WeatherData &weather) {
         is >> weather.location_id >> weather.timestamp;
         is >> weather.temperature;
         is >> weather.humidity;
         is >> weather.wind_speed;
         is >> weather.precipitation;
         return is;
     }
    friend ostream &operator<<(ostream &os, const WeatherData &weather) {
         os << weather.location_id << endl;
         os << weather.timestamp << endl;
         os << weather.temperature << endl;
         os << weather.humidity << endl;
         os << weather.wind_speed << endl;
         os << weather.precipitation << endl;
         return os;
     }
    string WeatherAlert() {
         if (temperature > 35.0 || temperature < -10.0 || humidity > 90 || wind_speed > 30.0 || precipitation > 50) {
             return "Severe";
         }
         else if (temperature > 30.0 || temperature < 0.0 || humidity > 80 || wind_speed > 20.0 || precipitation > 30) {
             return "Warning";
         }
         else {
             return "Normal";
         }
     }
};
WeatherData FilterByAlertLevel( WeatherData *arr,int n,const string alertLevel) {
    int count=0;
    for(int i=0;i<n;i++) {
        if(arr[i].WeatherAlert() == alertLevel) {
            count++;
        }
    }
    WeatherData *filtered = new WeatherData[count];
    int idx=0;
    for(int i=0;i<n;i++) {
        if(arr[i].WeatherAlert() == alertLevel) {
            filtered[idx++] = arr[i];
        }
    }
    return *filtered;
}

int main() {
    writeToFile();
    ifstream fin("text.txt");
    if (!fin) {
        std::cerr << "Cannot open file\n";
        return 1;
    }

    // TODO: Вчитајте податоци од датотека (број на тест примери (testCase), број на WeatherData записи (n) и податоци за WeatherData)
    int testCase, n;
    fin >> testCase;
    fin >> n;
    WeatherData *records = new WeatherData[n];
    for (int i = 0; i < n; i++) {
        fin>>records[i];
    }
    fin.close();
    if (testCase == 1) {
        cout << "===== Testing Constructor, Istream Operator & OstreamOperator =====" << endl;
        for (int i = 0; i < n; i++) {
            cout << records[i];
        }
    }

    if (testCase == 2) {
        cout << "===== Testing WeatherAlert Function =====" << endl;
        for (int i = 0; i < n; i++) {
            cout << records[i].WeatherAlert() << endl;
        }
    }
    if (testCase == 3) {
        cout << "===== Testing FilterByAlertLevel Global Function =====" << endl;
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (records[i].WeatherAlert() == "Normal") {
                count++;
            }
        }
        WeatherData filtered = FilterByAlertLevel(records, n, "Normal");
        cout << "Normal Weather Conditions:" << endl;
        for (int i = 0; i < count; i++) {
            cout << filtered[i];
        }
        delete[] filtered;
    }

    if (testCase == 4) {
        cout << "===== Testing FilterByAlertLevel Global Function =====" << endl;
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (records[i].WeatherAlert() == "Warning") {
                count++;
            }
        }
        WeatherData *filtered = FilterByAlertLevel(records, n, "Warning");
        cout << "Warning Weather Conditions:" << endl;
        for (int i = 0; i < count; i++) {
            cout << filtered[i];
        }
        delete[] filtered;
    }

    if (testCase == 5) {
        cout << "===== Testing FilterByAlertLevel Global Function =====" << endl;
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (records[i].WeatherAlert() == "Severe") {
                count++;
            }
        }
        WeatherData *filtered = FilterByAlertLevel(records, n, "Severe");
        cout << "Severe Weather Conditions:" << endl;
        for (int i = 0; i < count; i++) {
            cout << filtered[i];
        }
        delete[] filtered;
    }

    delete[] records;
    return 0;
}