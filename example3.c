#include <stdio.h>
#include "tlist.h"

int main()
{
  int i, j;
  TLISTDEF(int, tintlist);
  TLIST(tintlist, l5);
  for (i=1; i<10; i++)
  {
    TLISTITER(l5) li = TLISTPUSHBACK(l5, (tintlist){0});
    TLISTINIT(TLISTREF(li));
    for (j=1; j<10; j++)
      TLISTPUSHBACK(TLISTREF(li), i*j);
  }
  TLISTFOREACH(i, l5, ({
    TLISTFOREACH(j, TLISTREF(i), ({
      printf("%d\t", TLISTREF(j));
    }));
    printf("\n");
  }));
  TLISTFOREACH(i, l5, ({ TLISTCLEAR(TLISTREF(i));}));
  TLISTCLEAR(l5);
}
