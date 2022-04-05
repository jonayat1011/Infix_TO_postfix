#include<iostream>
#include<string>
using namespace std;

class Conversion
{
public:

bool isOperator(char c)
{
	if(c=='+' || c=='-' ||  c=='*' ||c =='/'|| c=='^' ||c=='%')
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool isOpeningPa(char c)
{
	if(c=='('||c=='{'||c=='[')
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool isClosingPa(char c)
{
	if(c==')'||c=='}'||c==']')
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool isOperand(char c)
{
	if((c>='0' && c<='9')||(c>='a' && c<='z')||(c>='A' && c<='Z'))
    //if(c=='0'|| c=='1'|| c=='2'|| c=='3'|| c=='4'|| c=='5'|| c=='6'|| c=='7'|| c=='8'|| c=='9')
	{
		return true;
	}
	else
	{
		return false;
	}
}
char getTop()
	{
        return stack[top];
    }
int precedence(char c) 
{ 
    if(c == '^') 
    return 3; 
    else if(c == '*' || c == '/' || c =='%') 
    return 2; 
    else if(c == '+' || c == '-') 
    return 1; 
    else
    return -1; 
} 
char stack[100];
char postfixE[100];
int i=0,top=-1,t=-1;
void pushS(char c)
	{
      top++;
      stack[top]=c;

    }
void pushP(char c)
	{
      t++;
      postfixE[t]=c;
      
    }
void popS()
	{		
		top--;				
	}
void postfix(string infix)
{
while(infix[i]!='\0')
{
    if(isOperand(infix[i])){
       pushP(infix[i]);
       i++;
    }
    else if(isOpeningPa(infix[i])){
        pushS(infix[i]);
        i++;
    }
    else if(isOperator(infix[i])){
        if(isOperator(getTop())){
            while(precedence(getTop())>=precedence(infix[i])){
                pushP(getTop());
                popS();
            }
            if(precedence(getTop())<precedence(infix[i])){
                pushS(infix[i]);
                i++;
            }
        }
        else{
            pushS(infix[i]);
                i++;
        }
    }
    else if(isClosingPa(infix[i])){
        while((getTop()!='(' && infix[i]==')')||(getTop()!='{' && infix[i]=='}')||(getTop()!='[' && infix[i]==']')){
                pushP(getTop());
                popS();
        }
        if((getTop()=='(' && infix[i]==')')||(getTop()=='{' && infix[i]=='}')||(getTop()=='[' && infix[i]==']')){
                
                popS();
                i++;
        }

    }

}
while(top>-1){
    pushP(getTop());
      popS();
}
}
void print()
	{ 
      for(int k=0;k<=t;k++)
	cout<<postfixE[k];
   
    cout<<endl;
    }


int j=0,to=-1;
char validationStack[100];
bool Validation(string infix)
{
while(infix[j]!='\0')
    {
   if(infix[j]=='('||infix[j]=='{'||infix[j]=='['){
     to++;
      validationStack[to]=infix[j];
    
     j++;
   }
   else if(infix[j]==')'||infix[j]=='}'||infix[j]==']'){
       
          if((validationStack[to]=='('&& infix[j]==')')||(validationStack[to]=='{' && infix[j]=='}')||(validationStack[to]=='['&& infix[j]==']')){
              to--;
              j++;
          }
          else 
            break;
   }
   else
     j++;

}
if(to==-1){
    
   return true;
 }
 else

   return false;

}
};
int main(){
    Conversion s1;
    string infixExpr;
    //="[{1+2/(3-1*2)-1*8/2}/[6+2]]";
    cout<<endl;
    cout<<"Enter a Infix Expression : ";
    cin>>infixExpr;
    if(s1.Validation(infixExpr)){
    cout<<endl;
    cout<<endl;

    cout<<"*******The expression valid********"<<endl;
    s1.postfix(infixExpr);
    cout<<endl;
    
    cout<<"Postfix Expression       : ";
    s1.print();
    cout<<endl;
    cout<<endl;
    }
    else{
    cout<<endl;

    cout<<"***********The expression invalid ********"<<endl;}
   
   cout<<endl;
   cout<<endl;
}
//[{1+2/(3-1*2)-1*8/2}/[6+2]]