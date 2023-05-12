#ifndef __test_helper__
#define __test_helper__

template <typename T>
void randomList ( List<T>& list, Rank n )
{
  ListNodePosi<T> p =
    ( rand() % 2 )
    ? list.insertAsLast( rand() % (T) ( n * 4 ) + 1)
    : list.insertAsFirst( rand() % (T) ( n * 4 ) + 1 );
  for (Rank i = 1; i < n; i++) {
    p = ( rand() % 2 )
                  ? list.insert( rand() % (T) ( n * 4 ) + 1, p )
                  : list.insert( p, rand() % (T) ( n * 4 ) + 1 );
  }
}
/*
 template <typename T>
 void print( List<T>* L ){
   if(L) print(&L);  else printf("<NULL>\n");
 }*/

std::ostream& operator <<(std::ostream& os, std::nullptr_t ptr)
{
  return os << "nullptr";
}
/*
template <typename T>
void print( const List<T>& L ) 
{
  std::cout << typeid(L).name() << "\t" << &L << "\t" << L.size();
  std::cout << std::endl;
  int count = 0;
  for( ListNodePosi<T> p = L.first(); count < L.size() ; p = p->next )
  {
    if ( !p->data )break;
    std::cout << p->data << "\t";
    if ((++count) % 10 == 0)
      std::cout << std::endl;
  }
  std::cout << std::endl;
}*/

template <typename T>
struct Increase
{
  Increase(unsigned int n) : num(n) {} 
  virtual void operator()(T& e) { e += num;} 
  private:
  unsigned int num;
};

template <typename T>
void increase(List<T>& L)
{
  Increase<T> inc7(7);
    L.traverse(inc7);
}

template <typename T>
struct Half
{
  virtual void operator()(T& e) { e /= 2;} 
};

template <typename T>
void half(List<T>& L)
{
  Half<T> half;
  L.traverse( half );
}

#define print(X) {std::cout << (X) << std::endl;}

  template <typename T>
void testList( int testSize )
{
  
  std::cout << "\n  --------- Test " << testID++ << " : list init: " << std::endl;
  List<T> L1; randomList( L1, testSize ); print(L1);
  std::cout << L1 << std::endl;

  std::cout << "\n  --------- Test " << testID++ << " : list sort: " << std::endl;
  L1.sort(); print(L1);

  std::cout << "\n  --------- Test " << testID++ << " : init 2 sorted lists: " << std::endl;
  List<T> Lx; randomList( Lx, testSize ); Lx.sort(); print(Lx);
  List<T> Ly; randomList( Ly, testSize ); Ly.sort(); print(Ly);

  std::cout << "\n  --------- Test " << testID++ << " : init 2 lists: " << std::endl;
  List<T> La; randomList( La, testSize ); print(La);
  List<T> Lb; randomList( Lb, testSize ); print(Lb);

  std::cout << "\n  --------- Test " << testID++ << " : call by bracket: " << std::endl;
  for (Rank i = 0; i <= La.size(); i++)
  {
    std::cout << La[i]->data << '\t';
    if ( i % 10 == 9)
      std::cout << std::endl;
  }
      std::cout << std::endl;
  for (Rank i = 0; i < Lb.size(); i++) 
  {
    std::cout << Lb[i]->data << '\t';
    if ( i % 10 == 9)
      std::cout << std::endl;
  }
      std::cout << std::endl;

  std::cout << "\n  --------- Test " << testID++ << " : concatenation: " << std::endl;
  while ( Lb.size() > 0 )
    La.insertAsLast( Lb.remove( Lb.first() ) );
  print(La); print(Lb);

  std::cout << "\n  --------- Test " << testID++ << " : increase(functor): " << std::endl;
  increase(La); print(La);

  std::cout << "\n  --------- Test " << testID++ << " : reverse:" << std::endl;
  La.reverse(); print(La);

  std::cout << "\n  --------- Test " << testID++ << " : copy constructor:" << std::endl;
  List<T> Lc (La); print(Lc);

  std::cout << "\n  --------- Test " << testID++ << " : find:" << std::endl;
  for (Rank i = 0; i < Lc.size(); i++) {
    ListNodePosi<T> p = Lc.find( ( T ) i ); 
    std::cout << "Looking for " << ( ( T ) i ) << " :" ;
    
    if ( p ) std::cout << " found : " << p->data << std::endl;
    else std::cout << " not found!" << std::endl;
  }

  std::cout << "\n  --------- Test " << testID++ << " : search:" << std::endl;
  Lc.sort(); print(Lc);
  for (Rank i = 0; i < Lc.size(); i++) {
    ListNodePosi<T> p = Lc.search( (T)i );
    std::cout << "Looking for " << ( (T)i ) << " :" ;
    printf( ( Lc.isValid( p ) && ( (T)i == p->data ) ) ? " found at " : " failed at " ) ;
    if (Lc.isValid(p)) std::cout << p->data << std::endl;
    else std::cout << "HEAD" << std::endl;
  }

  std::cout << "\n  --------- Test " << testID++ << " : traverse  ( += 7 ):" << std::endl;
  increase(Lc);
  print(Lc);

  std::cout << "\n  --------- Test " << testID++ << " : traverse  ( half ):" << std::endl;
  half(Lc);
  print(Lc);
  
  std::cout << "\n  --------- Test " << testID++ << " : uniquify:" << std::endl;
  std::cout << "Before uniquify:" << std::endl;
  print(Lx);
  std::cout << Lx.uniquify() << " node(s) removed. "<< std::endl;
  std::cout << "After uniquify:" << std::endl;
  print(Lx);

  std::cout << "\n  --------- Test " << testID++ << " : deduplicate:" << std::endl;
  std::cout << "Before deduplicate:" << std::endl;
  print(La);
  std::cout << La.deduplicate() << " node(s) removed. "<< std::endl;
  std::cout << "After deduplicate:" << std::endl;
  print(La);
}

#endif // !__test_helper__

