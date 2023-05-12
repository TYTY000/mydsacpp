#ifndef __WINDOW__
#define __WINDOW__

struct Sum
{
  Sum(unsigned int n) : num(n) {} 
  virtual void operator()(Customer& e) { num += e.time; } 
  friend Rank sum( Queue< Customer >);
  private:
  unsigned int num;
};

Rank sum( Queue< Customer > Q )
{
  Sum s(0);
  Q.traverse(s);
  return s.num;
}

int bestWindow ( Queue< Customer > windows[], Rank nWin )
  {
    Rank minSize = sum( windows[0] ), opti = 0;
    for (Rank i = 1; i < nWin; i++) {
      Rank cur = sum( windows[i] );
      if ( minSize > cur )
      {
        minSize = cur;
        opti = i;
      }
    }
    return opti;
  }

#endif // !__WINDOW__
