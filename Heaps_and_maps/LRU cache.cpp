 #include<list> 
    unsigned int maxa;
    list<int> q;
    unordered_set<int> s;
    unordered_map<int,int> m;
LRUCache::LRUCache(int capacity) {
    maxa  = capacity;
    q.clear();
    s.clear();
    m.clear();
    }

int LRUCache::get(int key) {
        if(s.find(key)==s.end()) return -1;
        else {
            q.remove(key);
            q.push_front(key);
            return m[key];
        }
}

void LRUCache::set(int key, int value) {
    if(s.find(key)==s.end()){
            if(maxa==s.size()){
             int least = q.back();
                s.erase(least);
                q.pop_back();
                q.push_front(key);
                s.insert(key);
                m[key]=value;
            }
            else {
               q.push_front(key);
                s.insert(key);
                m[key]=value; 
            }
        }
        else {
            q.remove(key);
            q.push_front(key);
            //s.insert(key);
            m[key]=value;
        }

}
