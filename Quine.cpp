#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(int argc, char* argv[])
{
    char q = 34;
    string l[] = {
    "#include <iostream>",
    "#include <string>",
    "#include <vector>",
    "using namespace std;",
    "int main(int argc, char* argv[])",
    "{",
    "    char q = 34;      ",
    "    string l[] = {",
    "    ",
    "    };",
    "    for(int i = 0;  i <= 7; i++)",
    "        cout << l[i] << endl;",
    "    for(int i = 0; i <= 19; i++)",
    "        cout << l[8] << q << l[i] << q << ','<< endl;",
    "    for(int i = 9; i <= 19; i++)",
    "        cout << l[i] << endl;",
    "    vector<int> myints;",
    "    myints.push_back(25);",
    "    return 0;",
    "}",
    };
  for(int i = 0;  i <= 7; i++)
      cout << l[i] << endl;
  for(int i = 0; i <= 19; i++)
      cout << l[8] << q << l[i] << q <<','<< endl;
  for(int i = 9; i <= 19; i++)
      cout << l[i] << endl;
  vector<int> myints;
  myints.push_back(25);
  return 0;
}
