#include <bits/stdc++.h>
using namespace std;

// string identifier="(_|a|b|c|d|e|f|g|h|i|j|k|l|m|n|o|p|q|r|s|t|u|v|w|x|y|z|A|B|C|D|E|F|G|H|I|J|K|L|M|N|O|P|Q|R|S|T|U|V|W|X|Y|Z).(_|a|b|c|d|e|f|g|h|i|j|k|l|m|n|o|p|q|r|s|t|u|v|w|x|y|z|A|B|C|D|E|F|G|H|I|J|K|L|M|N|O|P|Q|R|S|T|U|V|W|X|Y|Z|1|2|3|4|5|6|7|8|9|0)*";
// string number="(1|2|3|4|5|6|7|8|9|0).(1|2|3|4|5|6|7|8|9|0)*";

vector<int> operator+(vector<int> a, vector<int> b) // operator Overloading for vector Additions
{
    a.insert(a.end(), b.begin(), b.end());
    sort(a.begin(), a.end());                     // required for making unique element
    a.erase(unique(a.begin(), a.end()), a.end()); // for finding unique element within vector
    return a;
}

struct tree // Structure for Treenode
{
    char alpha;
    int pos;
    bool nullable;
    vector<int> fpos, lpos;
    tree *left, *right;
};

bool is_op(char ch)
{
    if (ch == '|' || ch == '*' || ch == '.')
        return true;
    return false;
}

tree *create(char ch, int pos) // Creating Node Memory and initialization
{
    tree *node = new tree;
    node->alpha = ch;
    node->pos = pos;
    node->left = node->right = NULL;
    node->lpos.clear();
    node->fpos.clear();
    return node;
}

void vec_print(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
}

void postfix(tree *root) // For Traversing The tree
{
    if (root)
    {
        string s("	    	");
        postfix(root->left);
        postfix(root->right);
        cout << root->alpha << s << root->pos << s << root->nullable << s << "{ ";
        vec_print(root->fpos);
        cout << " }" << s << s << "{ ";
        vec_print(root->lpos);
        cout << " }" << endl;
    }
}

int precedence(char op)
{
    switch (op)
    {
    case '.':
        return 0;
    case '|':
        return 1;
    case '*':
        return 2;

    default:
        return -1;
    }
}

string infixToPostfix(string infixExpression)
{
    string postfixExpression;
    stack<char> st;

    for (char symbol : infixExpression)
    {
        if (is_op(symbol))
        {
            // Operator encountered
            while (!st.empty() && precedence(symbol) <= precedence(st.top()))
            {
                postfixExpression += st.top();
                st.pop();
            }
            st.push(symbol);
        }
        else if (symbol == '(')
        {
            // Left parenthesis, push onto the stack
            st.push(symbol);
        }
        else if (symbol == ')')
        {
            // Right parenthesis, pop and append operators until left parenthesis is found
            while (!st.empty() && st.top() != '(')
            {
                postfixExpression += st.top();
                st.pop();
            }
            st.pop(); // Remove the left parenthesis from the stack
        }
        else
        {
            // Operand, append to the result
            postfixExpression += symbol;
            
        }
    }

    // Pop and append any remaining operators in the stack
    while (!st.empty())
    {
        postfixExpression += st.top();
        st.pop();
    }

    return postfixExpression;
}

class Lexer
{
    int gpos, fl_pos;                        // for finding  position and follow position index
    vector<int> follow_pos[300], state[300]; // follow_pos store the follow position and state store total no of Dstates
    map<int, char> alpha_int;                // pos to char mapping
    set<char> in_alpha;
    map<vector<int>, map<char, vector<int>>> re_dfa;

public:
    void dfa(tree *root, string input) // Finding DFA
    {
        int num_state = 1, cur_state = 1;
        int ch = 1;
        vector<int> temp;
        map<vector<int>, char> out_state; // Out_state used for removing Redundant States
        // map<vector<int>, map<char, vector<int>>> re_dfa; // for Storing The final DFA state
        state[num_state++] = root->fpos; // total number of State , Starting with root's First position
        out_state[root->fpos] = ch++;
        while (1)
        {
            for (int i = 0; i < input.size(); i++)
            {
                for (int j = 0; j < state[cur_state].size(); j++)
                {
                    if (alpha_int[state[cur_state][j]] == input[i])
                        temp = temp + follow_pos[state[cur_state][j]];
                    if (out_state[temp] == 0 && temp.size() > 0)
                    {
                        out_state[temp] = ch++;
                        state[num_state++] = temp;
                    }
                }
                re_dfa[state[cur_state]][input[i]] = temp;
                temp.clear();
            }
            if (cur_state == num_state - 1)
                break;
            cur_state++;
        }
        // cout << "\n\nThe Final State Table :\n\n"; // for Displaying the Final DFA states
        // for (auto an : re_dfa)
        // {
        //     cout << "{ ";
        //     for (auto jn : an.first)
        //         cout << jn << " ";
        //     cout << " } ";
        //     for (auto jn : an.second)
        //     {
        //         cout << " at : " << jn.first << " { ";
        //         for (auto kn : jn.second)
        //             cout << kn << " ";
        //         cout << " } ";
        //     }
        //     cout << endl;
        // }
        // return re_dfa;
    }

    bool isAccepted(const string &input)
    {
        int cur_state = 1;
        vector<int> current_state = state[cur_state];

        for (char ch : input)
        {
            if (re_dfa[current_state].find(ch) != re_dfa[current_state].end())
            {
                current_state = re_dfa[current_state][ch];
            }
            else
            {
                return false; // Transition not defined for the current input symbol
            }
        }

        // Check if the final state is accepting
        for (int state_index : current_state)
        {
            if (state_index == gpos)
            {
                return true;
            }
        }

        return false;
    }

    void fit(string &s1)//s1=input expression
    {
        tree *temp;
        stack<tree *> s;
        string str, sp("		"), input;
        // string s1;
        // cout << "Enter an expression : ";
        // cin >> s1;
        string s2 = infixToPostfix(s1);
        s2.append("#.");
        str = s2;
        // cout << "after infix to postfix conversion : \n";
        // cout << str;

        for (int i = 0; i < str.size(); i++)
        {
            if (!is_op(str[i]))
            {
                gpos++;
                if (str[i] != '#')
                {
                    fl_pos++;
                    alpha_int[fl_pos] = str[i];
                    in_alpha.insert(str[i]);
                }
                temp = create(str[i], gpos);
                temp->nullable = false;
                temp->fpos.push_back(gpos);
                temp->lpos.push_back(gpos);
            }
            else if (str[i] == '*')
            {
                temp = create(str[i], 0);
                temp->left = s.top(), s.pop();
                temp->nullable = true;
                temp->fpos = temp->left->fpos;
                temp->lpos = temp->left->lpos;
                for (int i = 0; i < temp->lpos.size(); i++)
                    follow_pos[temp->lpos[i]] = follow_pos[temp->lpos[i]] + temp->fpos;
            }
            else if (str[i] == '.')
            {
                temp = create(str[i], 0);
                temp->right = s.top(), s.pop();
                temp->left = s.top(), s.pop();
                temp->nullable = temp->right->nullable && temp->left->nullable;
                if (temp->left->nullable)
                    temp->fpos = temp->right->fpos + temp->left->fpos;
                else
                    temp->fpos = temp->left->fpos;
                if (temp->right->nullable)
                    temp->lpos = temp->right->lpos + temp->left->lpos;
                else
                    temp->lpos = temp->right->lpos;
                for (int i = 0; i < temp->left->lpos.size(); i++)
                    follow_pos[temp->left->lpos[i]] = follow_pos[temp->left->lpos[i]] + temp->right->fpos;
            }
            else
            {
                temp = create(str[i], 0);
                temp->right = s.top(), s.pop();
                temp->left = s.top(), s.pop();
                temp->nullable = temp->right->nullable || temp->left->nullable;
                temp->fpos = temp->right->fpos + temp->left->fpos;
                temp->lpos = temp->right->lpos + temp->left->lpos;
            }
            s.push(temp);
        }
        for (auto temp : in_alpha)
            input.push_back(temp);

        dfa(temp, input);
    }
};

// string getTokenizedExpression(){

// }

int main()
{
    string exp;
    // cout<<"Enter the expression"<<endl;
    // cin>>exp;
    // exp="(_|a|b|c|d|e|f|g|h|i|j|k|l|m|n|o|p|q|r|s|t|u|v|w|x|y|z|A|B|C|D|E|F|G|H|I|J|K|L|M|N|O|P|Q|R|S|T|U|V|W|X|Y|Z).(_|a|b|c|d|e|f|g|h|i|j|k|l|m|n|o|p|q|r|s|t|u|v|w|x|y|z|A|B|C|D|E|F|G|H|I|J|K|L|M|N|O|P|Q|R|S|T|U|V|W|X|Y|Z|1|2|3|4|5|6|7|8|9|0)*";
    exp="(1|2|3|4|5|6|7|8|9|0).(1|2|3|4|5|6|7|8|9|0)*";
    Lexer l1;
    l1.fit(exp);
    while(1){
        string s;
        cout<<"Enter the string to test"<<endl;
        cin>>s;
        if(l1.isAccepted(s)){
            cout<<"The string is accepted"<<endl;
        }
        else{
            cout<<"The string is not accepted"<<endl;
        }
    }
    return 0;
}
