#include"Header.h";


ArrayStack::ArrayStack() {
    top = -1;
}

void ArrayStack::push(char val) {
    if (top < Size - 1) {
        arr[++top] = val;
    }
}

char ArrayStack::pop() {
    if (top > -1) {
        return arr[top--];
    }
    return ' ';
}

char ArrayStack::peek() {
    if (top > -1) {
        return arr[top];
    }
    return ' ';
}

bool ArrayStack::isEmpty() {
    return top == -1;
}


string balance(string data) {

    ArrayStack s;

    for (int i = 0; i < data.length(); i++) {

        char ch = data[i];

        if (ch == '(' || ch == '[' || ch == '{') {

            s.push(ch);

        }
        else if (ch == ')') {

            if (s.isEmpty() || s.peek() != '(') {

                return "Unbalance";

            }
            s.pop();
        }
        else if (ch == ']') {

            if (s.isEmpty() || s.peek() != '[') {

                return "Unbalance";

            }
            s.pop();
        }
        else if (ch == '}') {

            if (s.isEmpty() || s.peek() != '{') {

                return "Unbalance";

            }
            s.pop();
        }



    }

    if (s.isEmpty()) {

        return"Balance";
    }
    else {
        return "Unbalance";
    }


}





stringStack::stringStack() {
    top = -1;
    unTop = -1;
    ReTop = -1;
}

void stringStack::type(string val) {
    if (top < Size - 1) {

        undo[++unTop] = "type";
        unVal[unTop] = val;
        arr[++top] = val;
        ReTop = -1;
    }
}

string stringStack::pop() {
    if (top > -1) {
        unTop++;
        undo[unTop] = "delete";
        unVal[unTop] = arr[top];
        return arr[top--];
    }
    return " ";
}

void stringStack::undoFun() {

    if (top > -1) {

        if (undo[unTop] == "type") {

            Redo[++ReTop] = "type";
            ReVal[ReTop] = unVal[unTop];
            top--;


        }

        else if (undo[unTop] == "delete") {

            arr[++top] = unVal[unTop];
            Redo[++ReTop] = "delete ";
            ReVal[ReTop] = unVal[unTop];


        }
        unTop--;

    }

    else
    {
        cout << "Stack Empty";
    }

}

void stringStack::redoFun() {


    if (ReTop > -1) {

        if (Redo[ReTop] == "type") {

            arr[++top] = ReVal[ReTop];
            undo[++unTop] = "type";
            unVal[unTop] = ReVal[ReTop];


        }


        else if (Redo[ReTop] == "delete") {

            undo[++unTop] = "delete";
            unVal[unTop] = ReVal[ReTop];
            top--;

        }

        ReTop--;


    }
    else
    {
        cout << "Nothing to Redo!" << endl;
    }
}



string stringStack::peek() {
    if (top > -1) {
        return arr[top];
    }
    return " ";
}

bool stringStack::isEmpty() {
    return top == -1;
}


void stringStack::display() {

    for (int i = 0; i <= top; i++) {

        cout << arr[i] << " ";


    }
    cout << endl;


}