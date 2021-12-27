struct PolyTerm{
        int coeff;
        int expo;
        struct PolyTerm *next;
};

int addPolyTerm(int c, int e);

void displayPolynomial();

int evaluatePolynomial(int x);





