int *border, *match;
int n_match;

void KMP(string text, string pattern) {
	int n = text.size(), m = pattern.size(), pos;
	border = new int[m + 1];
	border[0] = pos = -1;
	for(int i = 1; i <= m; i++) {
		while(pos >= 0 && pattern[pos] != pattern[i - 1]) pos = border[pos];
		border[i] = ++pos;
	}
	match = new int[n];
	n_match = 0;
	for(int sp = 0, kp = 0; sp < n; sp++) {
		while(kp >= 0 && (kp == m || pattern[kp] != text[sp])) kp = border[kp];
		kp++;
		if(kp == m) match[n_match++] = sp + 1 - m;
	}
}