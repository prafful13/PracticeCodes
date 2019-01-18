// link: https://leetcode.com/problems/wildcard-matching/

class Solution {
public:
    struct pair_hash {
      template <class T1, class T2>
      std::size_t operator () (const std::pair<T1,T2> &p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);
        return h1 ^ h2;
    }
    };

    unordered_map<pair<string,string>,bool, pair_hash> m;

    bool isMatch(string s, string p)    {
        helper(s,p);
        return m[make_pair(s,p)];
    }

    bool helper(string s, string p) {
        if(m.find(make_pair(s,p))!=m.end()) return m[make_pair(s,p)];

        if(s.length()==0 && p.length()==0)   m[make_pair(s,p)] = true;
        else if(s.length()==0 && p[0]!='*')  m[make_pair(s,p)] = false;
        else if(p[0]=='*')   {
            if(s.length()==0)   m[make_pair(s,p)] = helper(s,p.substr(1,p.length()-1));
            else {
                m[make_pair(s,p)] = helper(s, p.substr(1,p.length()-1));
                if(m[make_pair(s,p)] == false)  m[make_pair(s,p)] = helper(s.substr(1,s.length()-1), p);
            }
        }
        else if(p[0]=='?')  {
            m[make_pair(s,p)] = helper(s.substr(1,s.length()-1), p.substr(1,p.length()-1));
        }
        else if(s[0]==p[0]) {
            int i=0;
            while(s[i]==p[i] && s[i]!='\0' && p[i]!='\0')   i++;
            m[make_pair(s,p)] = helper(s.substr(i,s.length()-i),p.substr(i,p.length()-i));
        }
        else m[make_pair(s,p)] = false;

        return m[make_pair(s,p)];
    }
};
