
void main() {
    const int v[1] = {1}; // line comment test
    int i = v[0]; // line comment \
    cross line
    if(i > 0) i = 1;
    else i = -1;
    i = (i + 1 - 1) * 3 / 2 % 3;
    while (i > 0) i = i - 1;
    while (i < 0) i = i - 1;
    while (i == 0) i = i - 1; /* block
    comment */
    while (i != 0) i = i - 1;
    while (i >= 0) i = i - 1;
    while (i <= 0) i = i - 1;
    i = 0x1234FeDc;
}