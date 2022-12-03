fn main() {
  let mut x: i32 = 5;
  x = x + 1;

  let y: i32 = 6;
  // y = y + 1;
  // 以上这行代码取消注释后，会报如下错误:
  //   cannot assign twice to immutable variable

  println!("The value of x is: {} {}", x, y);
}
