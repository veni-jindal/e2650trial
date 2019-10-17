#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<algorithm>
using namespace std;

int vertex_count (string s1){
    int vertices;
    int len = s1.size();
    vertices = stoi(s1.substr(2, len-2));
    return vertices;
        }

vector<vector<int> > adjency_matrix(string s1, int vertex, vector<vector<int> > &adj ){
        //vector<vector<int> > adj(vertex,vector<int> (vertex, 0));
        adj.resize(vertex);
        for (int d=0; d<adj.size();d++){
            adj[d].resize(vertex);
        }
        for (int e=0; e<adj.size(); e++){
            for (int f=0; f<adj.size(); f++){
                adj[e][f] =0;
            }
        }
        int len = s1.size();
        while (s1 != "{"){
            s1 = s1.substr(s1.find("{"),len -2);
            //cout<<s1<<endl;
            string i = s1.substr(s1.find("<")+1 , s1.find(",")-s1.find("<")-1);
            int row = stoi(i);
            //cout <<"row" << row<< endl;
            if (row >= vertex){
                
                cout<< "Error: "<< "a vertex " << row << " doesn't exist for vertices "<< vertex<< endl;
                return {};}
            string j = s1.substr(s1.find(",")+1 , s1.find(">")-s1.find(",")-1);
            int col = stoi(j);
            //cout<< "col" << col<< endl;
            if (col >= vertex){
                cout<< "Error:"<< "a vertex " << col << " doesn't exist for vertices "<< vertex<< endl;
                return {};
            }
            //cout << "hjgjgj"<<endl;
            adj[row][col] = 1;
            adj[col][row] =1;
            //cout<< s1<< endl;
            s1.erase(s1.find("<"), s1.find(">")+1);
            //cout << s1 << endl;
            //cout<< row << col << adj[row][col]<< endl;
            
        }
        return adj;
        }
void display_adj(vector<vector<int> > vect){
    
        for(int i=0;i<vect.size(); i++) {
        for (int j=0;j<vect[i].size(); j++)
            cout << vect[i][j] << " "; 
        cout << endl;
        }
    
}

int start_vert(string str1, int vertex){
    str1.erase(0,2);
    int vert1 = stoi(str1.substr(0, str1.find(" ")));
    if (vert1 >= vertex){
            //cout<< "Error: "<< "a vertex " << vert1 << " doesn't exist src"<< endl;
            return 10000;}
    //cout<< vert1<< endl;
    return vert1;}

int end_vert(string str1, int vertex){
    str1.erase(0,2);
    str1.erase(0, str1.find(" ")+1);
    int vert2 = stoi(str1);
    if (vert2 >= vertex){
            //cout<< "Error: "<< "a vertex " << vert2 << " doesn't exist dst"<< endl;
            return 10000;}
    //cout<< vert2<< endl;
    return vert2;}

//int vert_dis_pre(int vertex_pt, vector<vector<int> > &adj, int src){
int min_dis_ver(vector<int> &d, vector<int> unvis){
    //cout<< d[0] <<endl;
    //cout << unvis[0]<< endl;

    int min = d[unvis[0]];
    int vert;
    
    for (int x= 0; x< d.size(); x++){
        for (int y=0; y<unvis.size(); y++){
            
            if (x==unvis[y]){
                //cout << "y" << unvis[y]<<endl;
                if (d[x] <= min){
                //cout<< "min"<< min << " d"<< d[x] << endl;
                min = d[x];
                vert = x;
            }
        }
    }}
    //cout << min << endl;
    return vert;
}

string int_string(int k){
    stringstream ss;  
    ss<<k;  
    string s;  
    ss>>s;  
    return s;
}

string shortest_path (int vertex_pt, vector<vector<int> > &adj, string str1){
    int src_ver = start_vert(str1, adj.size());
    int dst_ver = end_vert(str1, adj.size());
    string short_path;
    if (src_ver == 10000){
        string error_src = "Error: a vertex given in the statement doesn't exist ";
        return error_src;
    }
    if (dst_ver == 10000){
         string error_dst = "Error: a vertex given in the statement doesn't exist ";
        return error_dst;
    }
    //cout << src_ver<< ", "<< dst_ver<<endl;
     if (src_ver == dst_ver){
        short_path = int_string(src_ver) + "-" + int_string(dst_ver);
        return short_path;
    }
    vector<int> dist(adj.size(), 1000000);
    vector<int> visted;
    vector<int> unvisited;

    for (int k=0; k< adj.size(); k++){
        for(int l=0; l<adj.size(); l++){
            if (adj[k][l] == 1){
                if (unvisited.size() == 0){
                    //cout<< "k"<<k<<endl;
                    unvisited.push_back(k);
                }
                else{
                    int h =0;
                  string op;
                  while( h < unvisited.size()){
                    if (k!= unvisited[h]){
                    h = h+1;}
                    else{
                      op = "duplicate";
                      break;}

                  }
                   if (op!= "duplicate"){
                       //cout<< "k"<<k<<endl;
                   unvisited.push_back(k);}
                /*for(int m=0; m<unvisited.size(); m++){
                if (k != unvisited[m]){
                unvisited.push_back(k);}
            }*/
            }}
        }
        
    
    }
    for (int k=0; k< unvisited.size(); k++){
        //cout<< unvisited[k] << " ";
    }
    //cout <<endl;
    if(find(unvisited.begin(), unvisited.end(), src_ver) == unvisited.end()){
        string Error1 = "Error: No path exists to the vertex" ;
        return Error1;
    }
    if(find(unvisited.begin(), unvisited.end(), dst_ver) == unvisited.end()){
        string Error2 = "Error: No path exists to the vertex" ;
        return Error2;
    }
    vector<int> pred(adj.size(),1000);
    dist[src_ver] = 0;
    for (int k=0; k< adj.size(); k++){
      //cout<<  unvisited[k]<< " ";
      //cout<< dist[k]<< " " ;
      //cout<< endl;
    
    } 
    int vert1, vert2, dist_v1_v2, idx_vert1;
    while (unvisited.size()!=1){
        
        vert1 = min_dis_ver(dist, unvisited);
        //cout<< "vert1 " << vert1 <<endl;
        
        for(int p=0; p<unvisited.size(); p++){
            if(vert1 == unvisited[p]){
                idx_vert1 =p;
                //cout<< "idx_vert1"<< idx_vert1<< endl;
            }
        }
        for (int a=0; a< adj.size(); a++){
            for (int b = 0; b<unvisited.size(); b++){
            if(a == unvisited[b]){
            if (adj[vert1][a] == 1){
                vert2 = a;
               // cout<< "vert2 "<< vert2 << endl;
                if(vert1 == src_ver){
                    dist_v1_v2 =1;
                    }
                else{
                        dist_v1_v2 = dist[vert1] + adj[vert1][vert2];
                    }
                //cout<< dist_v1_v2<<endl;
                if (dist_v1_v2 < dist[vert2]){
                    dist[vert2] = dist_v1_v2;
                    pred[vert2] = vert1;
                }
               // cout<< dist[vert2]<<endl;
               // cout<< pred[vert2]<<endl;
            }}

        }}
    visted.push_back(vert1);
    unvisited.erase(unvisited.begin() + idx_vert1, unvisited.begin() + idx_vert1 + 1);
    //cout<< "visted";
    for (int m =0; m<visted.size(); m++){
       // cout<<visted[m] <<" ";
    }
      //cout << endl;  
      //cout<< "unvisted";
    for (int m =0; m<unvisited.size(); m++){
        //cout<<unvisited[m] <<" ";
    }    
    //cout<<endl;
    }

    
    int vert_pt = dst_ver;
    short_path = int_string(vert_pt) ;
    //cout<<short_path<<endl;
     
    for (int i = 0; i<adj.size(); i++){
        vert_pt = pred[vert_pt];
        short_path = int_string(vert_pt) + "-" + short_path;
        if (vert_pt ==src_ver){
            break;
        }
    }    
return short_path;
    
}


int main()
{
    
    string ip_by_user;
    //ifstream Myfile("test.txt");
    while (!cin.eof()){
    
        getline(cin, ip_by_user); 
        
        
        int ver ;
        static vector<vector<int> > adja;
        if (ip_by_user.find("V") == 0){
            cout<<ip_by_user<<endl;
            ver = vertex_count(ip_by_user);}
            //cout << vertex_count(ip_by_user) << endl;
            //cout <<ver<< endl;}
        
        
        
        if(ver!=0){
            //static vector<vector<int> > adja;
            
        if (ip_by_user.find("E") == 0){
            cout<<ip_by_user<<endl;
            adja = adjency_matrix(ip_by_user, ver, adja);
            if (adja.size() == 0){
                ver =0;}
            //display_adj(adja);
        }
        
        if(ip_by_user.find("s") == 0){
            cout<<ip_by_user<<endl;
            string s_path = shortest_path(ver, adja, ip_by_user);
            string er_str = s_path.substr(0, s_path.find(" "));
            //cout<< er_str<<endl;;
            //if (er_str =="Error:"){
              //  ver =0;}
            //else{
            cout<< s_path << endl;
        }}
    }    
    
    return 0;
}
