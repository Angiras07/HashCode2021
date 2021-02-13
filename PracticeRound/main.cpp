#include<bits/stdc++.h>
using namespace std;

#define ll long long

class pizza{
	public:
		ll n;
		vector<string> ings;
		ll idx;
};
ll M,T[3];
vector<pizza> pizzas;
vector<vector<ll>> ans;

void greedy(){
	sort(pizzas.begin(),pizzas.end(),[](pizza a,pizza b){
			return a.n > b.n;
			});
	ll i=0;
	for(ll sz=2;sz<5;++sz){
		while(T[sz-2] && i+sz<=M){
			vector<ll> tmp;
			ll j=sz;
			while(j--){
				tmp.push_back(pizzas[i].idx);
				i++;
			}
			ans.push_back(tmp);
			T[sz-2]--;
		}
	}
}

int main(){
	cin >> M;
	pizzas.resize(M);
	for(auto &x : T) cin >> x;
	ll id=0;
	for(auto &x : pizzas){
		cin >> x.n;
		x.ings.resize(x.n);
		for(auto &y : x.ings) cin >> y;
		x.idx=id;
		id++;
	}
	greedy();
	cout << static_cast<ll>(ans.size()) << endl;
	for(auto ele : ans){
		cout << static_cast<ll>(ele.size()) << " ";
		for(auto idx : ele) cout << idx << " ";
		cout << endl;
	}
	return 0;
}
