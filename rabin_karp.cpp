#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

const int P = 31;
const int M = 1e9 + 7;
vector<long long> p_powers;


void precompute_p_powers(int max_len){
    p_powers.resize(max_len+1);
    p_powers[0] = 1;
    for(int i = 1 ; i <= max_len ; ++i){
        p_powers[i] = (p_powers[i-1] * P)%M;
    }
}

long long calculateHash(const string& s,int len){
    long long hash = 0;
    for(int i= 0 ; i < len ; ++i){
        long long contribution = (long long)(s[i] - 'a' + 1) * p_powers[len - 1 - i];
        hash = (hash + contribution) % M;
    }

    return hash;
}

string readTextFromFile(const string& filename){

    ifstream inputFile;
    inputFile.open(filename);
    if(!inputFile.is_open()){
        cerr << "Error: Could not open file " << filename << endl;
        return "";
    }
    string fileContent((istreambuf_iterator<char>(inputFile)), istreambuf_iterator<char>());
    inputFile.close();

    return fileContent;
}

vector<int> rabinKarpSearch(const string& text , const string& pattern ){

    int n = text.length();
    int m = pattern.length();

    cout << "Text: " << text << endl;
    cout << "Pattern: " << pattern << endl;
    cout << "Text length (n): " << n << endl;
    cout << "Pattern length (m): " << m << endl;


    if (m == 0 || n == 0 || m > n) {
        cout << "Cannot find pattern: Invalid lengths." << endl;
    }

    precompute_p_powers(max(n, m));

    long long pattern_hash = calculateHash(pattern, m);
    long long current_text_hash = calculateHash(text, m);

    vector<int> found_indices;

    for(int i = 0 ; i <= n-m ; ++i){

        if(current_text_hash == pattern_hash){
            cout << "Potential match at index: " << i << endl;
            bool match_found = true;
            for(int k = 0 ; k < m ; ++k){
                if(text[i+k] != pattern[k]){
                    match_found = false;
                    break;
                }
            }
            if(match_found){
                cout << "TRUE Match found at index: " << i << endl;
                cout << "Initial Text Window Hash (text[" << i <<"..." << i+m-1 << "]): " << current_text_hash << std::endl;
                found_indices.push_back(i);
            }
        }
        if(i < n-m){
            current_text_hash = (current_text_hash - (long long)(text[i] - 'a' + 1) * p_powers[m - 1]) % M;
            if (current_text_hash < 0) {
                current_text_hash += M;
            }
            current_text_hash = (current_text_hash * P) % M;
            current_text_hash = (current_text_hash + (long long)(text[i + m] - 'a' + 1)) % M;
        }
    }

    return found_indices;
}

int main() {
    string filename;
    string userPattern;


    cout << "Enter the filename to search in: ";
    cin >> filename;

    string file_text = readTextFromFile(filename);
    if (file_text.empty()) {
        return 1;
    }

    cout << "Enter the pattern to search for: ";
    cin >> userPattern;


    vector<int> results  = rabinKarpSearch(file_text,userPattern);

    if (results.empty()) {
        cout << "Pattern '" << userPattern << "' not found in the file." << endl;
    } else {
        cout << "Pattern '" << userPattern << "' found at indices: ";
        for (int index : results) {
            cout << index << " ";
        }
        cout << endl;
    }

    return 0;
}