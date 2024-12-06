class Solution {
public:
    bool canChange(string start, string target) {
       // intialise two queue
       int n=start.size(),k=target.size();
       if(n!=k)return false;

       queue<pair<char,int>>q1,q2;
       
       for(int i=0;i<n;i++){
        if(start[i]!='_'){
        q1.push({start[i],i});
        }
       }

        for(int i=0;i<k;i++){
        if(target[i]!='_'){
        q2.push({target[i],i});
        }
       }

    //  std::queue<pair<char,int>> temp = q1; // Create a copy of the queue

    // std::cout << "Queue contents: ";
    // while (!temp.empty()) {
    //     std::cout << temp.front().first << " "<<temp.front().second; // Print the front element
    //     temp.pop();                       // Remove the front element
    // }

    //  std::queue<pair<char,int>>prev = q2; // Create a copy of the queue

    // std::cout << "Queue contents: ";
    // while (!prev.empty()) {
    //     std::cout << prev.front().first<< " "<<prev.front().second; // Print the front element
    //     prev.pop();                       // Remove the front element
    // }

       if(q1.size()!=q2.size())return false;
       
          while(q1.size()>0){
            char ch1=q1.front().first;
            int index1=q1.front().second;

            char ch2=q2.front().first;
            int index2=q2.front().second;

            q1.pop();
            q2.pop();

            if(ch1!=ch2 ){
                cout<<ch1<<endl;
                cout<<index1<<endl;
            return false;
            }
             
             else if(ch1=='L'){

                cout<<index1<<" "<<index2<<endl;
                if(index1<index2)
                return false;

             }

             else if(ch1=='R'){
                cout<<index1<<" "<<index2<<endl;
                if(index1>index2)
                return false;
             }
 
          }

          return true;
        
    }
};