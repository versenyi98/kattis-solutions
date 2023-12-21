#include <bits/stdc++.h>

using namespace std;

stack<long long int> st;
vector<string> commands = {"SS", "SNS", "SNT", "SNN", "TSSS", "TSST", "TSSN", "TSTS", "TNST"};

// SS   szám stackra berak
// SNS  copy top "Invalid copy operation"
// SNT  swap top "Invalid swap operation"
// SNN  remove top "Invalid remove operation"
// TSSS sum top 2 "Invalid addtion operation"
// TSST diff top 2 "Invalid substraction operation"
// TSSN * top 2 "Invalid multiplication operation"
// TSTS / top 2 "division by zero", "Invalid division operation"
// TNST int int "Invalid print operation"

void apply_command(string command) {
    while (command.length() > 0) {
        for (long long int i = 0; i < commands.size(); i++) {
            if (command.length() >= commands[i].length() && command.substr(0, commands[i].length()) == commands[i]) {
                long long int substr_begin = commands[i].length();
                if (i == 0) {
                    bool positive = command[commands[i].length()] == 'S';
                    long long int j = commands[i].length() + 1;
                    string temp_num = "";
                    while (command[j] != 'N') {
                        temp_num = temp_num + command[j];
                        j++;
                    }
                    substr_begin = j + 1;

                    long long int num = 0;
                    for (long long int i = temp_num.length() - 1; i >= 0; i--) {
                        if (temp_num[i] == 'S') continue;
                        num += pow(2, (temp_num.length() - 1) - i);
                    }
                    if (!positive) num *= -1;
                    st.push(num);

                } else if (i == 1) {
                    if (st.size()) {
                        st.push(st.top());
                    } else {
                        cout << "Invalid copy operation\n";
                    }
                } else if (i == 2) {
                    if (st.size() >= 2) {
                        long long int top1 = st.top();
                        st.pop();
                        long long int top2 = st.top();
                        st.pop();
                        st.push(top1);
                        st.push(top2);
                    } else {
                        cout << "Invalid swap operation\n";
                    }
                } else if (i == 3) {
                    if (st.size()) {
                        st.pop();
                    } else {
                        cout << "Invalid remove operation\n";
                    }
                } else if (i == 4) {
                    if (st.size() >= 2) {
                        long long int top1 = st.top();
                        st.pop();
                        long long int top2 = st.top();
                        st.pop();
                        st.push(top1 + top2);
                    } else {
                        cout << "Invalid addition operation\n";
                    }
                } else if (i == 5) {
                    if (st.size() >= 2) {
                        long long int top1 = st.top();
                        st.pop();
                        long long int top2 = st.top();
                        st.pop();
                        st.push(top2 - top1);
                    } else {
                        cout << "Invalid subtraction operation\n";
                    }
                } else if (i == 6) {
                    if (st.size() >= 2) {
                        long long int top1 = st.top();
                        st.pop();
                        long long int top2 = st.top();
                        st.pop();
                        st.push(top1 * top2);
                    } else {
                        cout << "Invalid multiplication operation\n";
                    }
                } else if (i == 7) {
                    if (st.size() >= 2) {
                        if (st.top() == 0) {
                            cout << "Division by zero\n";
                        } else {
                            long long int top1 = st.top();
                            st.pop();
                            long long int top2 = st.top();
                            st.pop();
                            st.push(top2 / top1); 
                        }
                    } else {
                        cout << "Invalid division operation\n";
                    }
                } else if (i == 8) {
                    if (st.size()) {
                        cout << st.top() << endl;
                        st.pop();
                    } else {
                        cout << "Invalid print operation\n";
                    }
                }
                command = command.substr(substr_begin);
            }
        }

    }

}

string command;
int main() {
    cin >> command;
    apply_command(command);
}