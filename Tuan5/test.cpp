#include<bits/stdc++.h>
using namespace std;
   int t=1;
   string chuanhoaten(string &s){
   	for( int i=0;i<s.size();i++){
   		if(s[i]<='Z' && s[i]>='A'){
   			s[i]+=32;
		   }
	   }
	s=" "+s;
	for( int i=0;i<s.size()-1;i++){
   		if(s[i]==' ' && s[i+1]!=' '){
   			s[i+1]-=32;
		   }
	   }
   	stringstream ss(s);
   	string tmp;
   	vector< string > v;
   	while( ss >> tmp){
   		 v.push_back(tmp);
	   }
	s="";
	for( int i=0;i<v.size();i++){
		s+=(v[i]+" ");
	}
	return s;
   }
   class SinhVien{
   	public:
   	  	string msv, ten, lop, ngaysinh;
   	  	float gpa;
   	  		friend istream &operator >> ( istream &in, SinhVien &x){
				 	in.ignore();
					getline(in,x.ten);
   	  			    in>> x.lop >> x.ngaysinh ;
   	  			    in>> x.gpa;

   	  			    if(x.ngaysinh[2]!='/'){
   	  			    	x.ngaysinh="0"+x.ngaysinh;
						}
					  if(x.ngaysinh[5]!='/'){
   	  			    	x.ngaysinh.insert(3,"0");
					}

				    chuanhoaten(x.ten);

				      string s = to_string(t);
   	  		          t++;
	               while(s.size()<3){
	           	        s='0'+s;
	                 }
				 	x.msv="B20DCCN"+s;
					return in;
			}

			 friend ostream &operator << ( ostream &out, SinhVien x){
                    out<< x.msv << " " << x.ten<<" "<<x.lop<<" "<<x.ngaysinh  <<" "<< fixed << setprecision(2)<<x.gpa<< endl;
                    return out;
			 }
   };

   bool cmp(SinhVien a, SinhVien b){
   	   return a.gpa > b.gpa;
   }

   void sapxep(SinhVien x[], int n){
   	    sort(x,x+n,cmp);
   }
int main(){
    SinhVien ds[50];
    int N, i;
    cin >> N;
    for(i=0;i<N;i++){
        cin >> ds[i];
    }

    sapxep(ds, N);

    for(i=0;i<N;i++){
        cout << ds[i];
    }
    return 0;
}
