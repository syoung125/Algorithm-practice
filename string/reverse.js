/**
 * input: 'Hi my name is seoyoung'
 * output: 'gnuoyoes si eman ym iH'
 */
function reverse(str) {
  if (!str || str.length < 2 || typeof str !== "string") {
    return str;
  }

  let reversed = [];
  for (let i = 0; i < str.length; i++) {
    reversed.push(str[str.length - 1 - i]);
  }
  return reversed.join("");
}

console.log(reverse("Hi my name is seoyoung"));
