function mergeSortedArrays(arr1, arr2) {
  const arr = [];
  let i = 0;
  let j = 0;

  while (i < arr1.length || j < arr2.length) {
    if (j >= arr2.length || arr1[i] <= arr2[j]) {
      arr.push(arr1[i]);
      i++;
    } else {
      arr.push(arr2[j]);
      j++;
    }
  }

  return arr;
}

console.log(mergeSortedArrays([0, 3, 4, 31], [4, 6, 30]));
