#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
#include "date_process.cpp"
#include <ctime>

using  namespace std;

bool is_in_past(string date, string time) {
    string input_time = date + " " + time;

    char now_buf[20];
    time_t now = std::time(nullptr);
    strftime(now_buf, sizeof(now_buf), "%Y-%m-%d %H:%M:%S", std::localtime(&now));
    return input_time < now_buf;
}

int main(int argc, char* argv[]) {
    if (argc != 4 && argc != 5) { 
        cout << "There are less than 4 arguments" << endl;
        return 1;
    }

    stringstream result;


    string date = argv[1];
    date_processing(date);

    string time = argv[2];
    if (time.length() == 5) time += ":00";
    
    if (is_in_past(date, time)) {
        cout << "You can't set a reminder in the past. Sorry :(" << endl;
        return 1;
    } 

    string head;
    string info;

    if (argc == 4) {
        head = "Reminder";
        info = argv[3];
    }
    else {
        head = argv[3];
        info = argv[4];
    }

    result << "systemd-run --user --on-calendar=\"" << date << " " << time 
        << "\" notify-send \"" << head << "\" \"" << info << "\"";    
    return system(result.str().c_str());
}