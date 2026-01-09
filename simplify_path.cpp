class Solution
{
public:
    string simplifyPath(string path)
    {
        stack<string> st;
        int n = path.size();
        for (int i = 0; i < n; i++)
        {
            if (path[i] == '/')
            {
                continue;
            }
            string s;
            while (i < n && path[i] != '/')
            {
                s += path[i];
                i++;
            }
            if (s == "..")
            {
                if (!st.empty())
                {
                    st.pop();
                }
            }
            else if (s == ".")
            {
                continue;
            }
            else
            {
                st.push(s);
            }
        }
        string fpath;
        while (!st.empty())
        {
            fpath = "/" + st.top() + fpath;
            st.pop();
        }
        if (fpath.size() == 0)
        {
            fpath = "/";
        }
        return fpath;
    }
};