//implement the “Phone Contact Search” using Binary Search.........

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int searchContact(const vector<string>& contacts, string name) {
    int start = 0, end = contacts.size() - 1;

    while (start <= end) {
        int mid = (start + end) / 2;

        if (contacts[mid] == name)
            return mid;  
        else if (contacts[mid] < name)
            start = mid + 1;
        else
            end = mid - 1;
    }
    return -1; 
}

int main() {
    vector<string> contacts = {
        "Aarav", "Ananya", "Bhavesh", "Gaurav", "Isha", "Karan", "Nikhil", "Riya", "Tannu"
    };

    sort(contacts.begin(), contacts.end());

    string name;
    cout << "Enter name to search: ";
    cin >> name;

    int index = searchContact(contacts, name);

    if (index != -1)
        cout << "✅ " << name << " found at position " << index + 1 << " in contact list.\n";
    else
        cout << "❌ " << name << " not found in contacts.\n";

    return 0;
}
