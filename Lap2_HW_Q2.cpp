// STT: 22520165
// Full Name: Nguyễn Chu Nguyên Chương
// Homework
// Notes or Remarks: ......
#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Browser
{
private:
    stack<string> backStack;    // Stack to store history for back navigation
    stack<string> forwardStack; // Stack to store history for forward navigation
    string currentUrl;          // Stores the current URL

public:
    Browser()
    {
        currentUrl = ""; // Initial state with no URL loaded
    }

    // Visit a new URL
    void visit(string url)
    {
        if (!currentUrl.empty())
        {
            backStack.push(currentUrl); // Store the current URL before navigating away
        }
        currentUrl = url; // Update to the new URL
        // Clear the forward stack because we can't go forward after visiting a new page
        while (!forwardStack.empty())
        {
            forwardStack.pop();
        }
        cout << "Visited: " << currentUrl << endl;
    }

    // Go back to the previous URL
    string back()
    {
        if (backStack.empty())
        {
            cout << "No previous URL to go back to." << endl;
            return currentUrl;
        }
        forwardStack.push(currentUrl); // Store the current URL in forward stack
        currentUrl = backStack.top();  // Move back to the previous URL
        backStack.pop();               // Remove the previous URL from the back stack
        cout << "Back to: " << currentUrl << endl;
        return currentUrl;
    }

    // Go forward to the next URL
    string forward()
    {
        if (forwardStack.empty())
        {
            cout << "No next URL to go forward to." << endl;
            return currentUrl;
        }
        backStack.push(currentUrl);      // Store the current URL in back stack
        currentUrl = forwardStack.top(); // Move forward to the next URL
        forwardStack.pop();              // Remove the next URL from the forward stack
        cout << "Forward to: " << currentUrl << endl;
        return currentUrl;
    }

    // Print current state for debugging
    void printCurrentUrl() const
    {
        cout << "Current URL: " << currentUrl << endl;
    }
};

int main()
{
    cout << "STT: 22520165\n";
    cout << "Full Name : Nguyen Chu Nguyen Chuong\n";
    cout << "Homework_Lap2\n";
    cout << "Notes or Remarks: ......\n";
    cout << "\n";
    Browser browser;
    browser.visit("httt.uit.edu.vn");
    browser.visit("uit.edu.vn");
    browser.back();    // Should print "httt.uit.edu.vn"
    browser.forward(); // Should print "uit.edu.vn"
    browser.visit("daa.uit.edu.vn");
    browser.back(); // Should print "uit.edu.vn"
    system("pause");
    return 0;
}
