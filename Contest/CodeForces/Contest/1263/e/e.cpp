/**
 * author:  apikdech
 * created: 29.11.2019 22:39:48
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 1e6 + 5;

string words = "";
int idx = 1, lst = -1, n, val[N];

struct Node{
	int mn, mx;
};

template <typename T>
struct SegmentTree{
	using F = function<T(T,T)>;
	int n;
	F f;
	T ti;
	vector<T> dat;
	SegmentTree(){};
	SegmentTree(F f, T ti) : f(f), ti(ti){}
	void init(int n_){    
		n = 1;
		while(n < n_) n <<= 1;
		dat.assign(n << 1, ti);
	}
	void build(const vector<T> &v){
		int n_ = v.size();
		init(n_);
		for(int i = 0; i < n_; i++) 
			dat[n + i] = v[i];
		for(int i = n - 1; i; i--) 
			dat[i] = f(dat[i << 1], dat[i << 1 | 1]);
	}
	void set_val(int k, T x){			//update val on index k
		dat[k += n] = x;
		while(k >>= 1)
  			dat[k] = f(dat[k << 1], dat[k << 1 | 1]);    
  	}
	T query(int a, int b) {				//query from [a, b)
		T vl = ti, vr = ti;
		for(int l = a + n, r = b + n; l < r; l >>= 1, r >>= 1) {
			if(l & 1) vl = f(vl, dat[l++]);
			if(r & 1) vr = f(dat[--r], vr);
		}
		return f(vl,vr);
  	}
};

void init() {
	for (int i = 0;  i < N; i++) {
		words += ' ';
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	// init();
	cin >> n;
	string s;
	cin >> s;
	vector<Node> v(n+5);
	vector<int> w(n+5);
	for (int i = 0; i < n+5; i++) {
		v[i] = {0, 0};
		w[i] = 0;
	}
	Node defaultNode = {0, 0};
	auto g = [&](int x, int y) {
		return x + y;
	};
	auto f = [&](Node x, Node y) {
		Node res;
		res.mx = max(x.mx, y.mx);
		res.mn = min(x.mn, y.mn);
		return res;
	}; //fungsi yang bakal dipake buat gabung treenya
	SegmentTree<int> segsum(g, 0); //ini berarti init segment tree pake fungsi f, nilai awal elemen '0'
	SegmentTree<Node> segrmq(f, defaultNode);
	segsum.build(w);
	segrmq.build(v); //build segtree dari nodes
	for (char c : s) {
		int tmp;
		if (c == 'R') idx++;
		else if (c == 'L') {
			if (idx != 1) idx--;
		} else {
			// if (words[idx] == '(') val[idx] = 1;
			// else if (words[idx] == ')') val[idx] = -1;
			if (c == '(') {
				val[idx] = 1;
				// words[idx] = '(';
			}
			else if (c == ')') {
				val[idx] = -1;
				// words[idx] = ')';
			} 
			else {
				val[idx] = 0;
				// words[idx] = c;
			}
			segsum.set_val(idx, val[idx]);
			tmp = segsum.query(1, idx+1);
			segrmq.set_val(idx, {tmp, tmp});
		}
		Node rmq = segrmq.query(1, n+1);
		int sum = segsum.query(1, n+1);
		if (rmq.mn < 0 || sum != 0) cout << "-1 ";
		else cout << rmq.mx << " ";
	}
	return 0;
}
