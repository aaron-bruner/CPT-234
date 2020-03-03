/* ----------------------------------------------------------------------------------------------- */
/* description:  calculates the inner product of the two arrays specified                          */
/* inputs:  two arrays                                                                             */
/* outputs:  the result of the inner product calculation                                           */
/* ----------------------------------------------------------------------------------------------- */
int findInnerProduct(int array1[], int array2[]) {

    int i, product = 0;
	for (i = 0; i < arrSize; i++) {
		product = product + array1[i] * array2[i];
	}
	return product;
}

