int *id, *sz, size;

void init(int n) {
	id = new int[n];
	sz = new int[n];
	size = n;
	for(int i = 0; i < n; ++i) { id[i] = i; sz[i] = 1; }
}

int root(int i) {
	if(i != id[i]) id[i] = root(id[i]);
	return id[i];
}

void unionOf(int i, int j) {
	i = root(i);
	j = root(j);
	if(i == j) return;
	--size;
	if(sz[i] < sz[j])   { id[i] = j; sz[j] += sz[i]; }
	else                { id[j] = i; sz[i] += sz[j]; }
}

bool connected(int i, int j) { return root(i) == root(j); }

int numberOfSets() { return size; }

int sizeOfSet(int i) { return sz[root(i)]; }