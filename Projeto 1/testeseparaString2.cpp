#include <iostream>
#include <string>
#include <vector>

using std::cout; using std::cin;
using std::endl; using std::string;
using std::vector;
using std::istringstream;

int main(){
    string text = "augusto,108064056";
    string delimiter = ",";
    vector<string> words{};

    size_t pos;
    while ((pos = text.find(delimiter)) != string::npos) {

        words.push_back(text.substr(0, pos));
        text.erase(0, pos + delimiter.length());
        delimiter = "\0";


    }
    for (const auto &str : words) {
        cout << str << endl;
    }

    return EXIT_SUCCESS;
}
