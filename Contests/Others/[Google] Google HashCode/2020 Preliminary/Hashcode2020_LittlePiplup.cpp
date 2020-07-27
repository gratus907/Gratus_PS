#include <bits/stdc++.h>
using namespace std;
#define int long long

/* Code Author : Team Little_Piplup, mainly dlwocks31 */
int B, L, D;
int count_books[101010];
int cc[6];
vector<int> scores;
vector<char> used;
int score_book(int b) 
{
    if (used[b]) 
        return 0;
	return scores[b];
}
struct signup 
{
	int Y;
	int left_time;
	vector<int> books;
};
vector<signup> ans;
void register_signup(signup &sig) 
{
	for(int b: sig.books)
		used[b] = 1;
	ans.push_back(sig);
}
struct library 
{
	int ind, N, T, M, sign_time; // book count, signup days, ship capacity
    int score_lib = 0;
	vector<int> books;
	void init() {
		cin >> N >> T >> M;
		books.resize(N);
		for(int i=0; i<N; i++) {
			cin >> books[i];
            score_lib += scores[books[i]];
            count_books[books[i]]++;
		}
		// somehow sort books
	}
	void sort_book_intime() { // unsafe.
		sort(books.begin(), books.end(), [&](int i, int j) {
			bool ap = score_book(i) > score_book(j);
			return ap;
		});
	}
	signup make_signup(int t) { // safe function. in order of current books
		signup sig;
		sig.Y = ind;
        int cnt = 0;
        t += T;
		for(int b: books) {
            if (t > D) break;
			if(!used[b])
            {
                cnt++;
				sig.books.push_back(b);
            }
            if (cnt == M+3)
            {
                cnt = 0; t++;
            }
		}
		sig.left_time = (D>=t)? D-t:0;
		return sig;
	}
    double evaluate_signup(int t) {
		signup sig = make_signup(t);
		int sum = 0;
		for(int b: sig.books) {
			sum += scores[b];
		}
		return (pow(sum, 1))/pow(sig.left_time+1,0);
	}
};
vector<library> libraries;
double score_library(library& lib, int current_time) 
{
	return lib.evaluate_signup(current_time)*1.0/(pow(lib.T-15,0.4)*1.0);
}
void outans() {
	int cnt = 0;
	for(auto& sig: ans) {
		if(sig.books.empty())
			continue;
		cnt++;
	}
	cout << cnt << '\n';
	for(auto& sig: ans) {
		if(sig.books.empty())
			continue;
		cout << sig.Y << ' ' << sig.books.size() << '\n';
		for(int b: sig.books) {
			cout << b << ' ';
		}
		cout << '\n';
	}
}
int32_t main(int32_t argc, char** argv) 
{
	srand(time(0));
	ios::sync_with_stdio(0);cin.tie(0);
	cin >> B >> L >> D;
	scores.resize(B);
	used.resize(B);
	for(int i=0; i<B; i++)
		cin >> scores[i];
	libraries.resize(L);
	for(int i=0; i<L; i++) {
		libraries[i].init();
		libraries[i].ind = i;
	}
	int t = 0;
	while(t <= D) 
    {
		if(libraries.empty())
			break;
		double mxscore = -1e9;
		int mxlib = 0, curind = 0;
		vector <pair<double, int>> indices;
		for(library& lib: libraries) 
        {
			double sc = score_library(lib, t);
			indices.push_back(make_pair(sc,curind));
			curind++;
		}
		sort(indices.begin(),indices.end(),greater<pair<double, int>>());
		mxlib = indices[0].second;
		library& lib = libraries[mxlib];
		lib.sort_book_intime();
		signup sig = lib.make_signup(t);
        if (sig.books.size())
        {
            register_signup(sig);
            t += lib.T;
            lib.sign_time = t;
        }
		
		libraries.erase(libraries.begin()+mxlib); // last line!!
	}
	outans();
}