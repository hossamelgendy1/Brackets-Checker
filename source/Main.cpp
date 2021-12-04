#include <iostream>

using namespace std;

template <class T>
class stack
{
private:
    int top, maxSize;
    T* arr;
public:
    // default size of the stack will be 10.
    stack()
    {
        maxSize = 10;
        arr = new T[maxSize];
        top = -1;
    }
    stack(T value, int intial_size)
    {
        if (intial_size <= 0)
        {
            cout << "Error: invalid size!\nProgram terminated\n";
            exit(EXIT_FAILURE);
        }
        maxSize = intial_size;
        top = -1;
        arr = new T[maxSize];
        while (top < maxSize - 1)
        {
            arr[++top] = value;
        }
    }
    stack(int size)
    {
        if (size <= 0)
        {
            cout << "Error: invalid size!\nProgram terminated\n";
            exit(EXIT_FAILURE);
        }
        maxSize = size;
        top = -1;
        arr = new T[maxSize];
    }
    ~stack()
    {
        delete[] arr;
    }

    void push(T value)
    {
        if (top < maxSize - 1)
        {
            top++;
            arr[top] = value;
        }
        else
        {
            throw "the array is full\n";
        }
    }
    void pop()
    {
        if (top == -1)
        {
            throw "the stack is empty\n";
        }
        else
        {
            top--;
        }
    }
    T& Top()
    {
        if (isEmpty())
        {
            cout << "Error: The stack is empty.\nProgram terminated.\n";
            exit(EXIT_FAILURE);
        }
        return arr[top];
    }
    int size()
    {
        return (top + 1);
    }

    bool isEmpty()
    {
        if (top == -1)
            return true;
        else
            return false;
    }

};

bool arePaired(char open, char close)
{
    if (open == '/' && close == '/')
        return true;
    else if (open == '(' && close == ')') 
        return true;
    else if (open == '{' && close == '}')
        return true;
    else if (open == '[' && close == ']')
        return true;
    else
        return false;

}


bool isBalanced(string statement)
{
    stack <char> stk(statement.length());
    bool ignore = false; // to ignore comment texts between /**/ .
    for (int i = 0; i < statement.length(); i++)
    {
        if (ignore && !(statement[i] == '/' && statement[i - 1] == '*'))
        {
            continue;
        }
        else if (statement[i] == '{' || statement[i] == '[' || statement[i] == '(')
        {
            stk.push(statement[i]);
        }
        else if (statement[i] == '/' && statement[i + 1] == '*')
        {
            stk.push(statement[i]);
            i += 2; // to jump to closing tag'/' directly. If the increment is normal this statement: /*/ will be valid. 
            ignore = true;
        }
        else if (statement[i] == '}' || statement[i] == ']' || statement[i] == ')')
        {
            if (stk.isEmpty() || !arePaired(stk.Top(), statement[i]))
                return false;
            else
                stk.pop();
        }
        else if (i > 0 && statement[i] == '/' && statement[i - 1] == '*')
        {
            if (stk.isEmpty() || !arePaired(stk.Top(), statement[i]))
                return false;
            else
            {
                stk.pop();
                ignore = false;
            }
        }
        else
        {
            return false;
        }
    }
    return stk.isEmpty();
}

void bracketsTest();
void stackTest();

int main()
{
    cout << "======================================\n"
        << "1- test \"stack\" class\n"
        << "2- test \"brackets matching\" function\n"
        << "======================================\n";
    int testChoice;
    cin >> testChoice;
    switch (testChoice)
    {
    case 1:
        stackTest();
        break;
    case 2:
        bracketsTest();
        break;
    default:
        cout << "Invalid test choice!\n";
        break;
    }
}

void bracketsTest()
{
    cout << "Testing \"brackets matching\" function...\n\n";
    int choice = 0;
    while (choice != 2)
    {
        cout << "Enter a string to check:\n";
        string expression;
        cin >> expression;
        if (isBalanced(expression))
        {
            cout << "valid\n\n";
        }
        else
        {
            cout << "not valid\n\n";
        }
        cout << "1- Try again\n"
            << "2- Exit\n";
        cin >> choice;
    }
    
}

void stackTest()
{
    cout << "Testing \"stack\" class...\n\n"
        << "Choose the data type for the stack\n"
        << "1- int     2- float     3- string\n";
    int dataType, size;
    cin >> dataType;
    cout << "Enter size of the queue: ";
    cin >> size;
    switch (dataType)
    {
    case 1:
    {
        stack<int> myStack(size);
        cout << "A stack of \"int\" with size " << size << " is created\n\n";
        int choice = 0;
        while (choice != 5)
        {
            cout << "1- Add element\n"
                << "2- Remove element\n"
                << "3- Get element\n"
                << "4- Get current stack size\n"
                << "5- Exit\n";
            cin >> choice;
            switch (choice)
            {
            case 1:
                cout << "Enter element: ";
                int element;
                cin >> element;
                try
                {
                    myStack.push(element);
                    cout << "Element added successfully.\n\n";
                }
                catch (const char* msg)
                {
                    cout << msg << endl;
                }
                break;
            case 2:
                try
                {
                    myStack.pop();
                    cout << "Element removed successfully.\n\n";
                }
                catch (const char* msg)
                {
                    cout << msg << endl;
                }
                break;
            case 3:
                cout << "last element: " << myStack.Top() << endl << endl;
                break;
            case 4:
                cout << "current size: " << myStack.size() << endl << endl;
                break;
            case 5:
                break;
            default:
                cout << "Invalid choice!\n\n";
                break;
            }
        }
        break;
    }
    case 2:
    {
        stack<float> myStack(size);
        cout << "A stack of \"float\" with size " << size << " is created\n\n";
        int choice = 0;
        while (choice != 5)
        {
            cout << "1- Add element\n"
                << "2- Remove element\n"
                << "3- Get element\n"
                << "4- Get current stack size\n"
                << "5- Exit\n";
            cin >> choice;
            switch (choice)
            {
            case 1:
                cout << "Enter element: ";
                float element;
                cin >> element;
                try
                {
                    myStack.push(element);
                    cout << "Element added successfully.\n\n";
                }
                catch (const char* msg)
                {
                    cout << msg << endl;
                }
                break;
            case 2:
                try
                {
                    myStack.pop();
                    cout << "Element removed successfully.\n\n";
                }
                catch (const char* msg)
                {
                    cout << msg << endl;
                }
                break;
            case 3:
                cout << "Last element: " << myStack.Top() << endl << endl;
                break;
            case 4:
                cout << "current size: " << myStack.size() << endl << endl;
                break;
            case 5:
                break;
            default:
                cout << "Invalid choice!\n\n";
                break;
            }
        }
        break;
    }
    case 3:
    {
        stack<string> myStack(size);
        cout << "A stack of \"string\" with size " << size << " is created\n\n";
        int choice = 0;
        while (choice != 5)
        {
            cout << "1- Add element\n"
                << "2- Remove element\n"
                << "3- Get element\n"
                << "4- Get current stack size\n"
                << "5- Exit\n";
            cin >> choice;
            switch (choice)
            {
            case 1:
            {
                cout << "Enter element: ";
                string element;
                cin >> element;
                try
                {
                    myStack.push(element);
                    cout << "Element added successfully.\n\n";
                }
                catch (const char* msg)
                {
                    cout << msg << endl;
                }
                break;
            }
            case 2:
                try
                {
                    myStack.pop();
                    cout << "Element removed successfully.\n\n";
                }
                catch (const char* msg)
                {
                    cout << msg << endl;
                }
                break;
            case 3:
                cout << "First element: " << myStack.Top() << endl << endl;
                break;
            case 4:
                cout << "current size: " << myStack.size() << endl << endl;
                break;
            case 5:
                break;
            default:
                cout << "Invalid choice!\n\n";
                break;
            }
        }
        break;
    }
    default:
        cout << "Invalid data type choice!\n";
        break;
    }
}
