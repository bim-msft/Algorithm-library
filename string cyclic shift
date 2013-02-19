//Time: O(n)   Space:O(1)

void swap(char *c1, char *c2) {
    char tmp = *c1;
    *c1      = *c2;
    *c2      = tmp;
}

void pszStringRotate(char *pszString, int nCharsRotate) {
    int len   = strlen(pszString);
    int cnt   = 0;                  // Current operate position on pszString
    int shift = nCharsRotate % len; // Current shift length
    for (int i = 1; i <= len - 1; i ++) { // Operation times upper bound : len - 1
        if (cnt == (cnt + len - shift) % len) { // Collision found
            cnt ++;    // Update current operate position
            cnt %= len;
        }
        swap(&pszString[cnt], &pszString[(cnt + len - shift) % len]); // Do operate
        shift += nCharsRotate; // Update shift length
        shift %= len;
    }
}
