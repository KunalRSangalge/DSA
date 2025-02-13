if(idx!=-1){
                ll j=0;
                for(int i=0;i<idx;i++)ans.push_back(a[i]);
                for(int i=0;i<(n-idx-m+1);i++)ans.push_back(b[0]);
                for(int i=1;i<m;i++)ans.push_back(b[i]);
                
            }