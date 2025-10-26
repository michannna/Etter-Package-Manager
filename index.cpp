#include <stdio.h>
#include <iostream>
#include <ncurses.h>
#include <string>
#include <cstring>
#include <sys/types.h>
#include <sys/socket.h>
#include <ifaddrs.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstdlib>
#include <fstream>
#include <map>
#include <cstdlib>

using namespace std;

 map<string, string> loadRepo() {
    map<string, string> repo;
    ifstream file("repo.txt");
    string line;

    while (getline(file, line)) {
        if (line.empty() || line[0] == '#')
            continue;

        size_t pos = line.find('=');
        if (pos != string::npos) {
            string name = line.substr(0, pos);
            string url = line.substr(pos + 1);
            repo[name] = url;
        }
    }

    return repo;
}


void ipaddress() {
struct ifaddrs *interfaces = nullptr;
    struct ifaddrs *ifa = nullptr;

    if (getifaddrs(&interfaces) == -1) {
        std::cerr << "Could not retrieve network adapters." << std::endl;
    }

    for (ifa = interfaces; ifa != nullptr; ifa = ifa->ifa_next) {
        if (ifa->ifa_addr && ifa->ifa_addr->sa_family == AF_INET) {
            char ipAddress[INET_ADDRSTRLEN];
            void* addr = &((struct sockaddr_in*)ifa->ifa_addr)->sin_addr;
            inet_ntop(AF_INET, addr, ipAddress, INET_ADDRSTRLEN);
            if (std::string(ipAddress) != "127.0.0.1") {
                std::cout << "Interface: " << ifa->ifa_name << ", IP Address: " << ipAddress << std::endl;
            }
        }
    }

    freeifaddrs(interfaces);
    }

int main() { //main of the code!
auto repo = loadRepo();


std::ifstream asciiFile("ascii.txt"); // Assuming 'ascii_art.txt' contains your ASCII art
    if (asciiFile.is_open()) {
        std::string line;
        while (getline(asciiFile, line)) {
            std::cout << line << std::endl;
        }
        asciiFile.close();
    }



main:

string input;

cout << "user> ";
system("cd ~/Downloads");
getline(cin, input);

if (input.empty()) {
goto main;
}

  else if (input.rfind("install ", 0) == 0) {
        string pkg = input.substr(8);
        if (repo.count(pkg)) {
            string url = repo[pkg];
            string cmd = "curl -O " + repo[pkg] + url;

            cout << "Downloading " << pkg << " from " << url << "..." << endl;
            system(cmd.c_str());
            cout << "✅ Download finished!, your downloaded files should be in your user files!" << endl;
            goto main;
        } else {
            cout << "❌ Package not found in repo!" << endl;
            goto main;
        }
    }
else if (input == "list") {
    cout << "📦 Available Packages:" << endl;
    for (auto& [name, url] : repo) {
    cout << " || " << name << " -> " << url << endl;
    cout << " " << endl;
            }
            cout << "click [enter] to continue" << endl;
        }
else if (input == "update-repo") {
    cout << "Checking for updates..." << endl;
    system("curl -O https://raw.githubusercontent.com/michannna/etter-repo/refs/heads/main/repo.txt");
    cout << "Do you want to exit and back again to take effects? [y/n]?" << endl;
    cout << "choose your choice? > ";
    cin >> input;

    if (input == "y") {
    return 0;
    }

    else if (input == "Y") {
    return 0;
    }

     else if (input == "n") {
    goto main;
    }

     else if (input == "N") {
    goto main;
    }

    else {
    return 0;
    }
}

else if (input == "clear"){
system("clear");
goto main;
}

else if (input == "install") {
printf("please add <package>?");
goto main;
}

else if (input == "ls") {
system("ls");
goto main;
}

else if (input == "cd Downloads"){
system("cd Downloads");
}


else if (input == "ip") {
ipaddress();
goto main;
}

else if (input == "free-mode"){
system("sudo su");
}

else if (input == "codeblocks"){
system("codeblocks");
}

else if (input == "neofetch"){
system("neofetch");
goto main;

}

else if (input == "exit"){
return 0;
}
else {
cout << "invalid argument"<<endl;
goto main;
}

cin.get();
goto main;

}
