/* ----------------------------------------------------------------------------------------------- */
/* description:  calculates the highest number in the array specified                              */
/* inputs:  the name of the array wanting to be sorted                                             */
/* outputs:  the max of the array specified                                                        */
/* ----------------------------------------------------------------------------------------------- */
int findHighest(int array[]) {

    int i, max;
	max = array[0];

	for (i = 0; i < arrSize; i++) {
		if (array[i] > max) {
			max = array[i];
		}
	}
	return max;
}

/* ----------------------------------------------------------------------------------------------- */
/* description:  calculates the second highest number in the array specified                       */
/* inputs:  the name of the array wanting to be sorted                                             */
/* outputs:  the second max of the array specified                                                 */
/* ----------------------------------------------------------------------------------------------- */
int findSecondHighest(int array[]) {

    int i, max = findHighest(array), smax = array[0];

	for (i = 0; i < arrSize; i++) {
        if (array[i] > smax && array[i] < max)
			smax = array[i];
	}
	return smax;
}

