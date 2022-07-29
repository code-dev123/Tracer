#define printclock() cerr <<"\nTime : "<<1000*(long double)clock()/(long double)CLOCKS_PER_SEC<<"ms\t";printf("\n")
#define watch(xxx)   cerr << (#xxx) << " is " << xxx << "\n";

long long mem = 0, tim = 0;
#define ttt {tim++;if(tim>250000000){cout<<"Line:"<<__LINE__<<" "<<"TLE\n"; exit(0);}}
#ifdef printline
#define cout cout << "Line "<<__LINE__<< ": ";cout
#else
#define cout if(++mem&&mem>110000){cout<<"Line:"<<__LINE__<<" "<<"MLE";exit(0);}else cout
#endif

// data type supported :-
// 1. int
// 2. long long
// 3. float
// 4. double
// 5. long double
// 6. char
// 7. bool
// 8. signed and unsigned int

// Data structure supported :-
// 1.  string
// 2.  pair
// 3.  vector(array)
// 4.  N-D vector(array)
// 5.  stack
// 6.  queue
// 7.  set
// 8.  multiset
// 9.  map
// 10. unorderd_map
// 11. any compination of above data structure

class print_class
{
private:
    template<typename type_1>
    void __print_(type_1 a)
    {
        cout << a;
    }
    template<typename type_1, typename type_2>
    void __print_(pair<type_1, type_2> a)
    {
        cout << "{";
        __print_(a.first);
        cout << " ";
        __print_(a.second);
        cout << "}";
    }

    template<typename type_1>
    void __print_(stack<type_1> a)
    {
        vector<type_1> ar;
        while (!a.empty())
        {
            ar.push_back(a.top());
            a.pop();
        }
        cout << "{";
        for (auto it = ar.rbegin(); it < ar.rend(); it++)
        {
            __print_(*it);
            if (it + 1 != ar.rend())
                cout << " ";
        }
        cout << "}";
    }

    template<typename type_1>
    void __print_(queue<type_1> a)
    {
        cout << "{";
        while (!a.empty())
        {
            __print_(a.front());
            a.pop();
            if (!a.empty())
                cout << " ";
        }
        cout << "}";
    }

    template<typename type_1>
    void __print_(vector<type_1> a)
    {
        cout << "{";
        for (auto it = a.begin(); it < a.end(); it++)
        {
            __print_(*it);
            if (it + 1 != a.end())
                cout << " ";
        }
        cout << "}";
    }

    template<typename type_1>
    void __print_(vector<vector<type_1>> a)
    {
        cout << "{";
        for (auto it = a.begin(); it < a.end(); it++)
        {
            cout << "{";
            for (auto it2 = (*it).begin(); it2 < (*it).end(); it2++)
            {
                __print_(*it2);
                if (it2 != (--(*it).end()))
                    cout << " ";
            }
            cout << "}\n";
        }
        cout << "}";
    }

    template<typename type_1>
    void __print_(set<type_1> a)
    {
        cout << "{";
        for (auto it = a.begin(); it != a.end();)
        {
            __print_(*it);
            if (++it != a.end())
                cout << " ";
        }
        cout << "}";
    }
    template<typename type_1>
    void __print_(multiset<type_1> a) {
        cout << "{";
        for (auto it = a.begin(); it != a.end();)
        {
            __print_(*it);
            if (++it != a.end())
                cout << " ";
        }
        cout << "}";
    }
    template<typename type_1, typename type_2>
    void __print_(map<type_1, type_2> a)
    {
        cout << "{\n";
        for (auto it = a.begin(); it != a.end(); ++it)
        {
            cout << "  ";
            __print_(it->first);
            cout << ": ";
            __print_(it->second);
            cout << "\n";
        }
        cout << "}\n";
    }
    template<typename type_1, typename type_2>
    void __print_(unordered_map<type_1, type_2> a)
    {
        cout << "{\n";
        for (auto it = a.begin(); it != a.end(); ++it)
        {
            cout << "  ";
            __print_(it->first);
            cout << ": ";
            __print_(it->second);
            cout << "\n";
        }
        cout << "}\n";
    }
    template<typename type_1, typename ...Arg>
    void __print_(type_1 a1, Arg ...a)
    {
        __print_(a1);
        __print_(a...);
        cout << "\n";
    }

    void Print_Variable(const char *names, int start, int end)
    {
        while (start <= end && names[start] == ' ')
        {
            start++;
        }

        for (int i = start; i <= end; i++)
        {
            cout << names[i];
        }
        cout << " : ";
    }

    template<typename Arg1>
    void __print_manager(const char *name, Arg1 && arg1)
    {
        Print_Variable(name, 0, (int)strlen(name) - 1);
        __print_(arg1);
        cout << " | ";
    }
public:
    template<typename Arg1, typename ... Args>
    void __print_manager(const char *names, Arg1 && arg1, Args &&... args)
    {
        int bracket = 0, i = 0;
        for (;; i++)
        {
            if (names[i] == ',' && bracket == 0)
                break;
            else if (names[i] == '(')
                bracket++;
            else if (names[i] == ')')
                bracket--;
        }
        Print_Variable(names, 0, i - 1);
        __print_(arg1);
        cout << " | \n";
        const char *comma = names + i;
        __print_manager(comma + 1, args...);
    }
} printvar;
#define trace(...) cout<<"Line:"<<__LINE__<<" ->\n", printvar.__print_manager(#__VA_ARGS__, __VA_ARGS__)
