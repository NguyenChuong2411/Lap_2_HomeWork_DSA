// STT: 22520165
// Full Name: Nguyễn Chu Nguyên Chương
// Homework
// Notes or Remarks: ......
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// Function to display the current state of towers
void displayTowers(stack<int> A, stack<int> B, stack<int> C)
{
    vector<stack<int>> towers = {A, B, C};
    char names[] = {'A', 'B', 'C'};
    for (int i = 0; i < 3; i++)
    {
        cout << names[i] << " Tower STACK = < ";
        stack<int> temp = towers[i];
        while (!temp.empty())
        {
            cout << temp.top() << " ";
            temp.pop();
        }
        cout << ">" << endl;
    }
}

// Function to move a disk based on user input
bool moveDisk(stack<int> &src, stack<int> &dest, char s, char d)
{
    if (src.empty())
    {
        cout << "No disk to move from " << s << " to " << d << endl;
        return false;
    }
    if (!dest.empty() && src.top() > dest.top())
    {
        cout << "Cannot move larger disk onto a smaller one!" << endl;
        return false;
    }
    int disk = src.top();
    src.pop();
    dest.push(disk);
    cout << "Move disk " << disk << " from " << s << " to " << d << endl;
    return true;
}

int main()
{
    cout << "STT: 22520165\n";
    cout << "Full Name : Nguyen Chu Nguyen Chuong\n";
    cout << "Homework_Lap2\n";
    cout << "Notes or Remarks: ......\n";
    cout << "\n";
    int n; // Number of disks
    cout << "Enter number of disks: ";
    cin >> n;

    stack<int> A, B, C; // Stacks representing the three towers

    // Initialize the first tower with disks
    for (int i = n; i >= 1; i--)
    {
        A.push(i);
    }

    cout << "Initial status:\n";
    displayTowers(A, B, C);

    char src, dest;
    while (C.size() != n)
    {
        cout << "Please input move (e.g., A B to move from A to B): ";
        cin >> src >> dest;

        // Normalize input to uppercase
        src = toupper(src);
        dest = toupper(dest);

        stack<int> *from, *to;

        // Map the input letters to corresponding towers
        if (src == 'A')
            from = &A;
        else if (src == 'B')
            from = &B;
        else if (src == 'C')
            from = &C;
        else
        {
            cout << "Invalid source tower!" << endl;
            continue;
        }

        if (dest == 'A')
            to = &A;
        else if (dest == 'B')
            to = &B;
        else if (dest == 'C')
            to = &C;
        else
        {
            cout << "Invalid destination tower!" << endl;
            continue;
        }

        // Perform the move
        if (moveDisk(*from, *to, src, dest))
        {
            displayTowers(A, B, C);
        }
    }

    cout << "Puzzle solved!" << endl;
    system("pause");
    return 0;
}
