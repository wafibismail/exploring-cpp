/*
 * Class: AddKFunction
 * -------------------
 * This class defines a function object that takes a single integer x and
 * computes the value x + k, where k is a constant specified by the client.
 */

class AddKFunction {

public:

/*
 * Constructor: AddKFunction
 * Usage: AddKFunction addk = AddKFunction(k);
 * -------------------------------------------
 * Creates a function object that adds k to its argument.
 */

    AddKFunction(int k) {
        this->k = k;
    }

/*
 * Operator: ()
 * ------------
 * Defines the behaviour of an AddKFunction object when it is called
 * as a function
 */

    int operator() (int x) {
        return x + k;
    }

private:

    int k;  // Instance variable that keeps track of the increment value
};