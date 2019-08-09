bool isMatch(string s, string p) {
        int m = s.length();
        int n = p.length();
        int i=0, j=0, index_s = -1, index_p = -1;
        if(n==0)
            return (m==0);
        while(i<m){
            if(j<n && (p[j]==s[i] || p[j]=='?')){
                i++;
                j++;
            }
            else if(j<n && p[j]=='*'){
                index_p = j;
                index_s = i;
                j++;
            }
            else if (index_p != -1) { 
                j = index_p + 1; 
                i = index_s + 1; 
                index_s++;
            } 
            else 
                return false;             
        }
        while(j<n && p[j]=='*')
            j++;
        if(j==n)
            return true;
        return false;
    }
