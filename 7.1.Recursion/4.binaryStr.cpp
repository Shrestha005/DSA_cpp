#include <iostream>
#include <vector>
using namespace std;

void generateBinaryStringsHelper(int N, string current, char prev, vector<string>& result){
    if(current.length()==N){
        result.push_back(current);
        return;
    }
    //append 0 and continue
    generateBinaryStringsHelper(N, current+"0", '0', result);

    //append 0 and continue
    if(prev!='1'){
        generateBinaryStringsHelper(N, current+"1", '1', result);
    }
}
vector<string> generateBinaryStrings(int N){
    vector<string> result;
    generateBinaryStringsHelper(N, "", '\0', result);
    return result;
}

int main() {
    int N = 3;
    vector<string> binaryStrings = generateBinaryStrings(N);
    for (const string& str : binaryStrings) {
        cout << str << " ";
    }
    return 0;
}
