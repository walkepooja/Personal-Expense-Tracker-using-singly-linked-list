#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int pnr, height;
    Node *left, *right;
};

int h(Node* n){
    return n ? n->height : 0;
}

int bf(Node* n) {
    return n ? h(n->left) - h(n->right) : 0;
}

Node* create(int p) {
    return new Node{p, 1, NULL, NULL};
}

Node* rightRotate(Node*y) {
    Node* x = y->left;
    y->left = x->right;
    x->right = y;
    y->height = 1 + max(h(y->left), h(y->right));
    x->height = 1 + max(h(x->left), h(x->right));
    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    x->right = y->left;
    y->left = x;
    x->height = 1 + max(h(x->left), h(x->right));
    y->height = 1 + max(h(y->left), h(y->right));
    return y;
}

Node* insert(Node* r, int p) {
    if (!r) return create(p);
    if (p < r->pnr) r->left = insert(r->left, p);
    else if (p > r->pnr) r->right = insert(r->right, p);
    else return r;

    r->height = 1 + max(h(r->left), h(r->right));
    int b = bf(r);

    if (b > 1 && p < r->left->pnr) {
        cout << "LL Rotation\n";
        return rightRotate(r);
    }
    if (b < -1 && p > r->right->pnr) {
        cout << "RR Rotation\n";
        return leftRotate(r);
    }
    if (b > 1 && p > r->left->pnr) {
        cout << "LR Rotation\n";
        r->left = leftRotate(r->left);
        return rightRotate(r);
    }
    if (b < -1 && p < r->right->pnr) {
        cout << "RL Rotation\n";
        r->right = rightRotate(r->right);
        return leftRotate(r);
    }
    return r;
}

Node* minNode(Node* r) {
    while (r->left) r = r->left;
    return r;
}

Node* deletePNR(Node* r, int p) {
    if (!r) return r;

    if (p < r->pnr) r->left = deletePNR(r->left, p);
    else if (p > r->pnr) r->right = deletePNR(r->right, p);
    else {
        if (!r->left || !r->right) {
            Node* t = r->left ? r->left : r->right;
            if (!t) {
                delete r;
                return NULL;
            }
            *r = *t;
            delete t;
        } else {
            Node* t = minNode(r->right);
            r->pnr = t->pnr;
            r->right = deletePNR(r->right, t->pnr);
        }
    }

    r->height = 1 + max(h(r->left), h(r->right));
    int b = bf(r);

    if (b > 1 && bf(r->left) >= 0) {
        cout << "LL Case: Right Rotation\n";
        return rightRotate(r);
    }
    if (b > 1 && bf(r->left) < 0) {
        cout << "LR Case: Left-Right Rotation\n";
        r->left = leftRotate(r->left);
        return rightRotate(r);
    }
    if (b < -1 && bf(r->right) <= 0) {
        cout << "RR Case: Left Rotation\n";
        return leftRotate(r);
    }
    if (b < -1 && bf(r->right) > 0) {
        cout << "RL Case: Right-Left Rotation\n";
        r->right = rightRotate(r->right);
        return leftRotate(r);
    }
    return r;
}

void display(Node* r) {
    if (r) {
        display(r->left);
        cout << r->pnr << " ";
        display(r->right);
    }
}

int main() {
    Node* root = NULL;
    int ch, p;

    do {
        cout << "\n1.Insert PNR\n2.Display PNR";
        cout << "\n3.Delete PNR\n4.Exit\nChoice: ";
        cin >> ch;

        if (ch == 1) {
            cout << "Enter PNR: ";
            cin >> p;
            root = insert(root, p);
        }
        else if (ch == 2) {
            cout << "PNRs: ";
            display(root);
            cout << endl;
        }
        else if (ch == 3) {
            cout << "Enter PNR to delete: ";
            cin >> p;

            root = deletePNR(root, p);
            cout << "Updated PNRs: ";
            display(root);
            cout << endl;
        }
    } while (ch != 4);

    return 0;
}
