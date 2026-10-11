#include <iostream>
#include <stack>
#include <string>
using namespace std;

class TextEditor
{
    string document;
    stack<string> undoStack;
    stack<string> redoStack;

public:
    void type(string word)
    {
        undoStack.push(document);
        document += (document.empty() ? "" : " ") + word;

        while (!redoStack.empty())
            redoStack.pop();

        print();
    }

    void undo()
    {
        if (!undoStack.empty())
        {
            redoStack.push(document);
            document = undoStack.top();
            undoStack.pop();
        }

        print();
    }

    void redo()
    {
        if (!redoStack.empty())
        {
            undoStack.push(document);
            document = redoStack.top();
            redoStack.pop();
        }

        print();
    }

    void print()
    {
        cout << "Document: \"" << document << "\"" << endl;
    }
};

int main()
{
    TextEditor editor;

    editor.type("Hello");
    editor.type("World");

    editor.undo();
    editor.redo();

    editor.undo();
    editor.type("There");

    editor.redo();

    return 0;
}

