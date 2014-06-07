double howMany(int c, int time) {
	double lo = 0;
	double hi = 2000000000;

	int times = 100;
	while(times-- >= 0) {
		double mid = lo + (hi - lo) / 2;
        double result = c * mid * log10(mid) / log10(2);
		if(result <=  time) lo = mid;
        else hi = mid;
    }

	return lo;
}

int main(int argc, char *argv[]) {
    return 0;
}
