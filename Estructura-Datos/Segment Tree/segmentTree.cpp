#define maxn 100010
#define INF (1 << 28)

int a[maxn], T[4 * maxn], N;

void init(int node, int l, int r) {
	if(l == r) {
		T[node] = a[l];
	} else {
		int mi = (l + r) >> 1;
		init(2 * node, l, mi);
		init(2 * node + 1, mi + 1, r);
		T[node] = max(T[2 * node], T[2 * node + 1]);
	}
}

void init(int n) {
	N = n;
	init(1, 0, N-1);
}

int query(int node, int l, int r, int x, int y){
	if(r < x || l > y) return -INF;
	if(x <= l && r <= y) return T[node];
	int mi = (l + r) >> 1;
	return max(query(2 * node, l, mi, x, y), query(2 * node + 1, mi + 1, r, x, y));
}

int query(int x, int y) { return query(1, 0, N-1, x, y); }

void update(int node, int l, int r, int x, int val){
	if(r < x || l > x) return;
	if(l == r) T[node] = val;
	else {
		int mi = (l + r) >> 1;
		update(2 * node, l, mi, x, val);
		update(2 * node + 1, mi + 1, r, x, val);
		T[node] = max(T[2 * node],T[2 * node + 1]);
	}
}

void update(int x, int val) { update(1, 0, N-1, x, val); }