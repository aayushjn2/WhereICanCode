// C++ program to sort the dates in a string array 
#include <bits/stdc++.h> 
using namespace std; 
  
// Map to store the numeric value of each month depending on 
// its occurrence i.e. Jan = 1, Feb = 2 and so on. 
unordered_map<string, int> monthsMap; 
  
// Function which initializes the monthsMap 
void sort_months() 
{ 
    monthsMap["Jan"] = 1; 
    monthsMap["Feb"] = 2; 
    monthsMap["Mar"] = 3; 
    monthsMap["Apr"] = 4; 
    monthsMap["May"] = 5; 
    monthsMap["Jun"] = 6; 
    monthsMap["Jul"] = 7; 
    monthsMap["Aug"] = 8; 
    monthsMap["Sep"] = 9; 
    monthsMap["Oct"] = 10; 
    monthsMap["Nov"] = 11; 
    monthsMap["Dec"] = 12; 
} 
  
// Comparator function to sort an array of dates 
bool comp(string a, string b) 
{ 
  
    // Comparing the years 
    string str1 = a.substr(7, 5); 
    string str2 = b.substr(7, 5); 
    if (str1.compare(str2) != 0) { 
        if (str1.compare(str2) < 0) 
            return true; 
        return false; 
    } 
  
    // Comparing the months 
    string month_sub_a = a.substr(3, 3); 
    string month_sub_b = b.substr(3, 3); 
  
    // Taking numeric value of months from monthsMap 
    int month_a = monthsMap[month_sub_a]; 
    int month_b = monthsMap[month_sub_b]; 
    if (month_a != month_b) { 
        return month_a < month_b; 
    } 
  
    // Comparing the days 
    string day_a = a.substr(0, 2); 
    string day_b = b.substr(0, 2); 
    if (day_a.compare(day_b) < 0) 
        return true; 
    return false; 
} 
  
// Utility function to print the contents 
// of the array 
void printDates(vector<string> & dates, int n) 
{ 
    for (int i = 0; i < n; i++) { 
        cout << dates[i] << endl; 
    } 
} 
  
// Driver code 
int main() 
{
    int n;
    cin>>n;
    vector<string> dates(n);
  
    // Order the months 
    sort_months(); 
  
    // Sort the dates 
    sort(dates, dates + n, comp); 
  
    // Print the sorted dates 
    printDates(dates, n); 
}