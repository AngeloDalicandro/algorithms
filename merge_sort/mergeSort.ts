function merge(arr: number[], lo: number, hi: number, mid: number): void {
    
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