void merge(vector<int> &v,int p,int q,int r){
	int size1 = q-p+1;
	int size2 = r-q;
	vector<T> L(size1);
	vector<T> R(size2);
	FO(i,0,size1) L[i] = v[p+i];
	FO(i,0,size2) R[i] = v[i+q+1];
	
	int i=0,j=0;
	int k = p;		// starting point of L
	while(i<size1 && j<size2){
		if(L[i] <= R[j]){
			v[k] = L[i];
			i++,k++;
		}else{
			v[k] = R[j];
			k++,j++;
		}
	}
	while(i<size1){
		v[k] = L[i];
		k++,i++;
	}
	while(j<size2){
		v[k] = R[j];
		k++,j++;
	}
}

void merge_sort(vector<int> &v,int p,int r){
	if(p < r){
		int q = (p+r)/2;
		merge_sort(v,p,q);
		merge_sort(v,q+1,r);
		merge(v,p,q,r);
	}
}
