#include<iostream>
using namespace std;

void Password_validate(string s)
{
    int l=s.length();
    if(l < 6)
    {
        cout<<"Failure Password must be at least 6 characters long.";
        return;

    }

    if(l > 24)
    {
        cout<<"Failure Password must be at max 12 characters long.";
        return;
    }
        int Lower_case=0, Upper_case=0, Number=0, Special_Char=0;
        bool flag=false;
        for(int i=0; i<=s.length(); i++)
        {
            if(s[i]>='a' && s[i]<='z')
                Lower_case++;
            else if(s[i]>='A' && s[i]<='Z')
                Upper_case++;
            else if(s[i]>='0' && s[i]<= '9')
                Number++;
            else if(s[i]=='*' || s[i]=='$' || s[i]=='_' || s[i]=='#' || s[i]=='=' || s[i]=='@')
                Special_Char++;
            else if(s[i]=='%' || s[i]=='!' || s[i]=='(' || s[i]==')')
            {
                flag=true;
                break;
            }

        }

        if(flag)
        {
            cout<<"Failure Password cannot contain %!)(.";
            return;

        }

        if(Lower_case >0 && Upper_case>0 && Number>0 && Special_Char>0)
        {
            cout<<"Success";
            return;

        }
        else
        {
            if(Lower_case==0)
                cout<<"Failure Password must contain at least one letter from a-z.";
            else if(Upper_case==0)
                cout<<"Failure Password must contain at least one letter from A-Z.";
            else if(Number==0)
                cout<<"Failure Password must contain at least one letter from 0-9.";
            else
                cout<<"Failure Password must contain at least one letter from *$_#=@.";
            return;
        }
}

int main()
{
    string Password_list;
    getline(cin,Password_list);
    string s="";
    for(int i=0; i<=Password_list.length(); i++)
    {
        if(Password_list[i]==','||Password_list[i]=='\0')
        {
            if(s.length()>0)
            {   cout<<s<<" ";
                Password_validate(s);
                cout<<endl;
                s="";
            }
        }
        else s+=Password_list[i];
    }
}
