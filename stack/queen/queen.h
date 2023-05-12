#ifndef __QUEEN__
#define __QUEEN__

struct Queen { 
  Rank x, y; 
  Queen ( int xx = 0, int yy = 0 ) : x ( xx ), y ( yy ) {};
  bool operator== ( const Queen& q ) const { 
      return    ( x == q.x )
             || ( y == q.y )
             || ( x + y == q.x + q.y )
             || ( x - y == q.x - q.y );
   }
   bool operator!= ( const Queen& q ) const { return ! ( *this == q ); }
};

#endif // !__QUEEN__
