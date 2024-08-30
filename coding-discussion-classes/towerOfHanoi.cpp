long long toh(int n, int from, int to, int aux) {
        
        
        if(n == 1){
            
            cout << "move disk " <<  n  << " from rod " << from  << " to rod " << to  << endl;
            return 1;
        }
        
        long long count = 0;
        
        // move n - 1 disks to from se aux using to
        
        
        count = toh(n - 1, from, aux, to);
        
        cout << "move disk " <<  n  << " from rod " <<  from << " to rod " << to  << endl;
        // now move the alone nth disk (from se to)
        count ++;
        
        // at last move those n-1 disks (aux se to using from)
        count += toh(n - 1, aux, to, from);
        
        
        return count;
        
   }
