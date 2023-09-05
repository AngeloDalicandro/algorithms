function merge(arr: number[], lo: number, hi: number, mid: number): void {
    
    let n = hi - lo + 1;
    let temp: number[] = new Array(n);

    let i: number = lo;
    let k: number = 0;
    let j: number = mid + 1;

    while (i <= mid && j <= hi) {
        if (arr[i] < arr[j]) {

            temp[k] = arr[i];
            k++;
            i++;

        } else {

            temp[k] = arr[j];
            k++;
            j++;
        }
    }

    while (i <= mid) {

        temp[k] = arr[i];
        k++;
        i++;
    }
 
    while (j <= hi) {

        temp[k] = arr[j];
        k++;
        j++;
    }
 
    for (i = lo; i <= hi; i++) {

        arr[i] = temp[i-lo];

    }
}

function mergeSort(arr: number[], lo: number, hi: number): void {
    
    let mid: number;
    
    if (lo > hi) {

        mid = (hi - lo) / 2;

        mergeSort(arr, lo, mid);
        mergeSort(arr, mid +1, hi);

        merge(arr, lo, hi, mid)
    }
}