#include <iostream>
#include <cstdio>
#include  <fstream>



#define BREAK 1
#define CONST 2
#define CONTINUE 3
#define DO 4
#define DOUBLE 5
#define ELSE 6
#define FLOAT 7
#define FOR 8
#define IF 9
#define INT 10
#define LONG 11
#define RETURN 12
#define SHORT 13
#define SIGNED 14
#define UNSIGENED 15
#define WHILE 16
#define ID 17
#define INTEGER 18
#define ARRARY 19
#define REAL 20
#define ADD 21
#define MINUS 22
#define MUL 23
#define DIV 24
#define PLSE 25
#define MNSE 26
#define MTPE 27
#define DIVE 28
#define INC 29
#define DEC 30
#define CAP 31
#define EQ 32
#define LT 33
#define GT 34
#define EQT 35
#define UEQ 36
#define LE 37
#define GE 38
#define NOT 39
#define LR_BRACE 40
#define RR_BRACE 41
#define SEMIC 42
#define LS_BRACE 43
#define RS_BRACE 44
#define LB 45
#define RB 46
#define PRINT 47
#define READ 48
#define AND 49
#define OR 50
#define MOD 51

#define MAX 100

using namespace std;
struct token
{
    int type;
    int value;
}; //标识符数据类型。第一个为种别码

string baoliuzi[18] = {"break","const","continue","do","double","else","float","for","if","int","long","return","short","signed","unsigned","while","print","read"};
string fuhaomingbiao[MAX];
token* fuhaobiao[MAX];
int fuhaoshu;
int hanghao;

int shibiebiaoshifu(string s, int pos);
void chatianfuhaobaio(string s);
void print_token(token t);
int shibieshuzi(string s,int pos);


void classfy(string  s)
{
    int quekuohao = 0; //判断是否缺少（）
    int quezhongkuohao = 0;//判断是否缺少【】
    int quedakuohao = 0;//判断是否缺少{}


    int if_float = 0;
    int num_ctrl = 0;
    string num_cache;


    int len = s.length();



    for(int i = 0; i < len; i ++)
    {
        if(isalpha(s[i]) || s[i] == '_')
        {
            if(num_ctrl == 0)
            {
                i = shibiebiaoshifu(s,i);
                continue;
            }
            else
            {
                cout<<"第"<<hanghao<<"行出现变量名定义错误"<<endl;
            }
        }
        if((s[i] > 47 && s[i] <58))
        {
            i = shibieshuzi(s,i);
            num_ctrl = 1;
        }
        if(s[i] == '#')
        {
            cout<<"("<<"#"<<","<<0<<")"<<endl;
        }
        if(s[i] == '+')
        {
            if(s[i+1] == '=')
            {
                i ++;
                cout<<"("<<"+="<<","<<0<<")"<<endl;
                num_ctrl = 0;
            }
            else
            {
                if(s[i+1] == '+')
                {
                    i ++;
                    cout<<"("<<"++"<<","<<0<<")"<<endl;
                    num_ctrl = 0;
                }
                else
                {
                    cout<<"("<<"+"<<","<<0<<")"<<endl;
                    num_ctrl = 0;
                }
            }

        }
        if(s[i] == '-')
        {
            if(s[i+1] == '=')
            {
                i ++;
                cout<<"("<<"-="<<","<<0<<")"<<endl;
                num_ctrl = 0;
            }
            else
            {
                if(s[i+1] == '-')
                {
                    i ++;
                    cout<<"("<<"--"<<","<<0<<")"<<endl;
                    num_ctrl = 0;
                }
                else
                {
                    cout<<"("<<"-"<<","<<0<<")"<<endl;
                    num_ctrl = 0;
                }
            }
        }
        if(s[i] == '*')
        {
            if(s[i+1] == '=')
            {
                i ++;
                cout<<"("<<"*="<<","<<0<<")"<<endl;
                num_ctrl = 0;
            }
            else
            {
                cout<<"("<<"*"<<","<<0<<")"<<endl;
                num_ctrl = 0;
            }
        }
        if(s[i] == '/')
        {
            if(s[i+1] == '=')
            {
                i ++;
                cout<<"("<<"/="<<","<<0<<")"<<endl;
                num_ctrl = 0;
            }
            else
            {
                cout<<"("<<"/"<<","<<0<<")"<<endl;
                num_ctrl = 0;
            }
        }

        if(s[i] == '>')
        {
            if(s[i+1] == '=')
            {
                i ++;
                cout<<"("<<">="<<","<<0<<")"<<endl;
                num_ctrl = 0;
            }
            else
            {
                cout<<"("<<">"<<","<<0<<")"<<endl;
                num_ctrl = 0;
            }
        }
        if(s[i] == '<')
        {
            if(s[i+1] == '=')
            {
                i ++;
                cout<<"("<<"<="<<","<<0<<")"<<endl;
                num_ctrl = 0;
            }
            else
            {
                cout<<"("<<"<"<<","<<0<<")"<<endl;
                num_ctrl = 0;
            }
        }
        if(s[i] == '!')
        {
            if(s[i+1] == '=')
            {
                i ++;
                cout<<"("<<"!="<<","<<0<<")"<<endl;
                num_ctrl = 0;
            }
            else
            {
                cout<<"("<<"!"<<","<<0<<")"<<endl;
                num_ctrl = 0;
            }
        }
        if(s[i] == ';')
        {
            cout<<"("<<";"<<","<<0<<")"<<endl;
            num_ctrl = 0;
        }
        if(s[i] == '(')
        {
            cout<<"("<<"("<<","<<0<<")"<<endl;
            num_ctrl = 0;
            quekuohao = 1;
        }
        if(s[i] == ')')
        {
            cout<<"("<<")"<<","<<0<<")"<<endl;
            num_ctrl = 0;
            quekuohao = 0;
        }
        if(s[i] == '[')
        {
            cout<<"("<<"["<<","<<0<<")"<<endl;
            num_ctrl = 0;
            quezhongkuohao = 1;
        }
        if(s[i] == ']')
        {
            cout<<"("<<"]"<<","<<0<<")"<<endl;
            num_ctrl = 0;
            quezhongkuohao = 0;
        }
        if(s[i] == '{')
        {
            cout<<"("<<"{"<<","<<0<<")"<<endl;
            num_ctrl = 0;
            quedakuohao = 1;
        }
        if(s[i] == '}')
        {
            cout<<"("<<"}"<<","<<0<<")"<<endl;
            num_ctrl = 0;
            quedakuohao = 0;
        }
        if(s[i] == '&')
        {
            if(s[i+1] == '&')
            {
                i ++;
                cout<<"("<<"&&"<<","<<0<<")"<<endl;
                num_ctrl = 0;
            }
            else
            {
                cout<<"错误，没有&"<<endl;
                num_ctrl = 0;
            }
        }
        if(s[i] == '|')
        {
            if(s[i+1] == '|')
            {
                i ++;
                cout<<"("<<"||"<<","<<0<<")"<<endl;
                num_ctrl = 0;
            }
            else
            {
                cout<<"错误，没有|"<<endl;
                num_ctrl = 0;
            }
        }
        if(s[i] == '%')
        {
            cout<<"("<<"&"<<","<<0<<")"<<endl;
            num_ctrl = 0;
        }
        if(s[i] == '.')
        {
            cout<<"第"<<hanghao<<"行错误的书写数字"<<endl;
        }
        if(s[i] == ' ')
        {
            num_ctrl = 0;
        }

    }
    if(quedakuohao == 1)
        cout<<"第"<<hanghao<<"行缺大括号"<<endl;
    if(quekuohao == 1)
        cout<<"第"<<hanghao<<"行缺括号"<<endl;
    if(quezhongkuohao == 1)
        cout<<"第"<<hanghao<<"行缺中括号"<<endl;


}


void print_token(token* t)
{
    cout<<"("<<t->type<<","<<t->value<<")"<<endl;
}

void chatianfuhaobaio(string s)
{
    //int zhongbiema = 0;
    int if_blz = 0;
    int if_bsf = 0;

    for(int i = 0; i < 18 ; i ++)
    {
        if(s == baoliuzi[i])
        {
            //cout<<baoliuzi[i]<<endl;
            if_blz = 1;
            token* t = new(token);
            t->type = i + 1;
            t->value = 0;
            print_token(t);
        }
    }
    if(if_blz == 0)
    {
        for(int i = 1; i <= fuhaoshu; i ++)
        {
            if(s == fuhaomingbiao[i])
            {
                if_bsf = 1;
                print_token(fuhaobiao[i]);
            }
        }
        if(if_bsf == 0)
        {
            fuhaoshu ++;
            fuhaomingbiao[fuhaoshu] = s;
            token* t = new(token);
            t->type = ID;
            t->value = fuhaoshu;
            fuhaobiao[fuhaoshu] = t;
            print_token(t);
        }
    }
}

int shibieshuzi(string s, int pos)
{
    string cache;
    int pos2 = pos;
    int num_ctrl = 0;

    for(int i = pos; i < s.length(); i ++)
    {
        //cout<<"i: "<<i<<endl;
        if((s[i] > 47 && s[i] <58) || s[i] == '.' )
        {
            pos2 = i;
            if(s[i] == '.' && num_ctrl == 0)
            {
                num_ctrl = 1;
            }
            if(s[i] == '.' && num_ctrl != 1)
            {
                num_ctrl = 10;
                break;
            }
            if((s[i] > 47 && s[i] <58) && num_ctrl == 0)
            {

            }
            if((s[i] > 47 && s[i] <58) && num_ctrl == 1)
            {
                num_ctrl = 2;
            }
        }
        else
        {
            break;
        }
    }

    //cout<<"pos :"<<pos<<"pos2: "<<pos2<<"s: "<<s<<endl;

    cache = s.substr(pos,pos2 - pos + 1);
    //cout<<"num_ctrl"<<num_ctrl<<endl;

    if(num_ctrl == 0)
        cout<<"("<<"10"<<","<<cache<<")"<<endl;
    if(num_ctrl == 2)
        cout<<"("<<"7"<<","<<cache<<")"<<endl;
    if(num_ctrl == 1 || num_ctrl == 10)
        cout<<"第"<<hanghao<<"行数字定义错误"<<endl;

    //cout<<"substring: "<<cache<<endl;

    return pos2;

}

int shibiebiaoshifu(string s, int pos)
{
    string cache;
    int pos2 = pos;
    //cout<<"pos:"<<pos<<endl;
    for(int i = pos; i < s.length(); i ++)
    {
        //cout<<"i: "<<i<<endl;
        if(isalnum(s[i]) || s[i] == '_')
        {
            pos2 = i;
        }
        else
        {
            break;
        }
    }
    cache = s.substr(pos,pos2 - pos + 1);


    //cout<<"substring: "<<cache<<endl;
    chatianfuhaobaio(cache);

    //cout<<"pos2: "<<pos2<<endl;

    return pos2;
}



int main()
{
    string  s; //用来存储读入的一行源程序
    string cache;//用来存储可能有用的字符串
    string biaoshifu[200];//存储已经识别到的表示符：符号表
    //string baoliuzi[18] = {"break","const","continue","do","double","else","float","for","if","int","long","return","short","signed","unsigned","while","print","read"};
    fuhaoshu = 0;

    ifstream fin( "data.txt" );
    ofstream fout("output.txt");
    hanghao = 0;
    while ( getline(fin,s) )
    {
        hanghao ++;
        if(s.length() != 0)
        {
            cout <<  "读取源代码第"<<hanghao<<"行"<<endl;
            cout<<s<<endl;
            classfy(s);
        }
    }
    for(int i = 1; i <= fuhaoshu; i ++)
        fout<<"fuhao"<<i<<": "<<fuhaomingbiao[i]<<endl;
    return 0;
}
