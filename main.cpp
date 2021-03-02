#include <bits/stdc++.h>

using namespace std;

string Hex[16] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F"};
string decToBinary(int x)
{
    ostringstream scout;
    string ans;
    while(x/2)
    {
        scout << x%2;
        x/=2;
        if(x == 1)
            scout << 1;
    }
    ans = scout.str();
    reverse(ans.begin(), ans.end());
    return ans;
}

string decToHex(int x)
{
    string str = decToBinary(x);
    ostringstream scout;
    int time = 0, sum = 0;
    string temp;
    for(int i = (int)str.size() - 1; i >= 0; i--)
    {
        time++;
        sum += int(str[i] - '0')*pow(2, time - 1);
        if(time%4 == 0 && i)
        {
            scout << Hex[sum];
            time = 0;
            sum = 0;
        }
        if(i == 0)
            scout << Hex[sum];
    }
    string ans = scout.str();
    reverse(ans.begin(), ans.end());
    return ans;
}
int main()
{
    int n;
    do
    {
        cout << "Please enter an decimal integer: ";
        cin >> n;
        if(!n)
            return 0;
        else
        {
            cout << "Binary system: ";
            cout << decToBinary(n) << endl;
            cout << "Hexadecimal system: ";
            cout << decToHex(n) << endl;
        }
    }
    while(n);
    return 0;
}
