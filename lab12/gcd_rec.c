int gcdRec (int a, int b) {
    if (b == 0)
       return a;
    else
       return gcdRec(b, a % b);
}
