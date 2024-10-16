// STT: 22520165
// Full Name: Nguyễn Chu Nguyên Chương
// Homework
// Notes or Remarks: ......
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> visiblePeople(vector<int> &heights)
{
    int n = heights.size();
    vector<int> answer(n, 0); // Result array to store how many people each person can see
    stack<int> st;            // Stack to track the heights of visible people

    // Traverse the heights array from right to left
    for (int i = n - 1; i >= 0; --i)
    {
        // While the current person can see the people in the stack (i.e., they are shorter), pop them
        while (!st.empty() && heights[i] > st.top())
        {
            answer[i]++; // Count how many people can be seen
            st.pop();    // Remove the person from the stack
        }

        // If there is still someone in the stack, they can also be seen by the current person
        if (!st.empty())
        {
            answer[i]++;
        }

        // Push the current person onto the stack
        st.push(heights[i]);
    }

    return answer;
}

int main()
{
    cout << "STT: 22520165\n";
    cout << "Full Name : Nguyen Chu Nguyen Chuong\n";
    cout << "Homework_Lap2\n";
    cout << "Notes or Remarks: ......\n";
    cout << "\n";
    int n;
    cout << "Enter number of people: ";
    cin >> n;

    vector<int> heights(n);
    cout << "Enter heights of people: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> heights[i];
    }

    vector<int> result = visiblePeople(heights);

    cout << "Visible people for each person: ";
    for (int i = 0; i < n; ++i)
    {
        cout << result[i] << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}
