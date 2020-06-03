/* pseudo code

LEFT-ROTATE(T, x)
  y = x.right
  x.right = y.left // turn y's left subtree into x's right subtree
  if y.left != T.nil
    y.left.p = x
  y.p = x.p
  if x.p == T.nil
    T.root = y
  elseif x == x.p.left
    x.p.left = y
  else 
    x.p.right = y
  y.left =x
  x.p = y

*/
int left_rotate(void *T, void *x)
{
  return 0;
}


/* pseudo code

RIGHT-ROTATE(T, y)
  x = y.left
  y.left = x.right

  if x.right != T.nil
    x.right.p = y
  
  x.p = y.p

  if y.p == T.nil
    T.root = x
  elseif y == y.p.right
    y.p.right = x
  else
    y.p.left = x
  x.right = y
  y.p = x

*/
int right_rotate(void *T, void *y)
{
  return 0;
}
