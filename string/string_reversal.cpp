class String_reverse {
public:
  void string_reverse1(char *string)  {
    int len = strlen(string);
    for(int i=0, j=len-1; i<j; i++, j--)  {
      char temp = string[i];
      string[i] = string[j];
      string[j] = temp;
    }
  }

  char *string_reverse2(const char *string) {
    int len = strlen(string);
    char *rev = new char[len+1];
    strcpy(rev, string);
    string_reverse1(rev);
    return rev;
  }
};
