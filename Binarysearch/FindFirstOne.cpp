public int binSearch(int a[], int low, int high) {
		if (low > high)
			return -1;
		int mid = low + (high - low) / 2;
		if (a[mid] == 1 && (mid == 0 || a[mid - 1] == 0))
			return mid;
		else if (a[mid] == 1 && a[mid - 1] != 0)
			return binSearch(a, low, mid - 1);
		else
			return binSearch(a, mid + 1, high);
	}
