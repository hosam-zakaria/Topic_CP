int N; cin >> N;
vector<ll> V;
for (int i = 1; i * i <= N; ++i){
	if (N % i == 0){
		V.push_back(i);
		if (i * i != N) V.push_back(N / i);
	}
}

// Time complexity is O(sqrt(N))
