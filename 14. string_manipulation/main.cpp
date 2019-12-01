/*Write a C++ program to perform the following operations on STRING using
string library
i. Parameterized and copy constructor
ii. Compare two string objects
iii. Find substring in a main string
iv. Return the position of the first occurrence a given substring in the string.
v. Return the position of the last occurrence a given substring in the string
vi. Insert a given substring at the end of main string
vii. Swap content of two given strings
*/
#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;
int main()
{
    string s1("abc");
    string s2("def");
    string s3(s2);
    string s4,s5;
    cout<<s1<<endl<<s2<<endl<<s3<<endl;
    cout<<"enter first string"<<endl;
    cin>>s4;
    cout<<"enter second string"<<endl;
    cin>>s5;
    while(1)
    {
        int ch,x1,x2,x3,x4,x5;
        string str1,sbst;
        char c1,c2;
        cout<<"1:compare \n2:substring \n3:position of 1st occurence \n4:position of last occurence";
        cout<<"\n5:insert a substring at end \n6:swapping \n7:concatenate \n8:exit"<<endl;
        cout<<"enter the choice"<<endl;
        cin>>ch;
        switch(ch)
        {
            case 1 :cout<<"compare two string"<<endl;
                    x1=s4.compare(s5);
                    if(x1==0)
                        cout<<s4<<" = "<<s5<<endl;
                    else if(x1>0)
                        cout<<s4<<" > "<<s5<<endl;
                    else
                        cout<<s4<<" < "<<s5<<endl;
                    break;

            case 2 :cout<<"enter the substring to be found"<<endl;
                    cin>>str1;
                    x2=s4.find(str1);
                    cout<<"substring"<<" "<<str1<<" is found at : "<<x2<<"th position"<<endl;
                    break;

            case 3: cout<<"enter the char to be found first"<<endl;
                    cin>>c1;
                    x3=s4.find_first_of(c1);
                    cout<<c1<<"is found first at: "<<x3<<endl;
                    break;

            case 4: cout<<"enter the char to be found last"<<endl;
                    cin>>c2;
                    x4=s4.find_last_of(c2);
                    cout<<c2<<"is found last at: "<<x4<<endl;
                    break;

            case 5: cout<<"enter the substring to be inserted"<<endl;
                    cin>>sbst;
                    x5=s4.length();
                    s4.insert(x5,sbst);
                    cout<<"modified s4: "<<s4<<endl;
                    break;

            case 6: s4.swap(s5);
                    cout<<"after swapping"<<endl;
                    cout<<s4<<endl<<s5<<endl;
                    break;

            case 7: s4=s4+" "+s5;
                    cout<<"concatenated string is "<<s4<<endl;
                    break;

            case 8: exit(0);

            default: cout<<"Invalid choice"<<endl;
        }
    }
    return 0;
}
