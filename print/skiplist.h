#include "../SkipList/Entry.h"
#include "../SkipList/QuadList.h"
#include "../SkipList/QuadNode.h"
#include "../SkipList/SkipList.h"

/******************************************************************************************
 * Entry
 ******************************************************************************************/
template <typename K, typename V>
void Print::p(Entry<K, V> &e) // ÒýÓÃ
{
  printf("-<");
  print(e.key);
  printf(":");
  print(e.value);
  printf(">-");
}

/******************************************************************************************
 * Quadlist
 ******************************************************************************************/

template <typename T>           // ÔªËØÀàÐÍ
void Print::p(Quadlist<T> &q) { // ÒýÓÃ
  // std::cout << boost::core::demangle(typeid(q).name()) << "\t@  " << &q
  //           << "\tsize = " << q.size() << std::endl; // »ù±¾ÐÅÏ¢
  if (q.size() <= 0) {
    printf("\n");
    return;
  }
  QNode<T> *curr = q.header;
  QNode<T> *base = q.header->next; // µ±Ç°½ÚµãËùÔÚ
  while (base->below)
    base = base->below; // Ëþµ×
  while (base->prev)
    base = base->prev;                  // µ×²ãÖ®header
  for (Rank i = 0; i < q.size(); i++) { // ¶ÔÓÚµ±Ç°²ãµÄÃ¿Ò»½Úµã
    curr = curr->next;                  // curr
    QNode<T> *proj = curr;              // ÕÒµ½Óëcurr¶ÔÓ¦µÄ
    while (proj->below)
      proj = proj->below;               // Ëþµ×½Úµã£¨Í¶Ó°£©
    while ((base = base->next) != proj) // ÒÆ¶¯baseÖ±µ½proj£¬ÆÚ¼ä²»¶Ï
      printf("------------");           // ÑÓ³¤Ë®Æ½Áª½ÓÏß
    print(curr->entry); // ×îºó£¬Êä³öµ±Ç°²ãµÄµ±Ç°´ÊÌõ
  }
  printf("\n");
}

/******************************************************************************************
 * Skiplist
 ******************************************************************************************/

template <typename K, typename V>  // e¡¢value
void Print::p(Skiplist<K, V> &s) { // ÒýÓÃ
  std::cout << boost::core::demangle(typeid(s).name()) << "\t@  " << &s
            << "\tsize = " << s.size() << std::endl; // »ù±¾ÐÅÏ¢
  s.traverse(print); // Í¨¹ýprint()±éÀúÊä³öËùÓÐÔªËØ
  printf("\n");
}
