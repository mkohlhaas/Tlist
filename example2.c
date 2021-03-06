#include <stdio.h>
#include <string.h>
#include "tlist.h"

int main()
{
  TLIST(struct s { int a; char *s; }, l2);
  TLISTINSERT(TLISTINSERT(TLISTPUSHBACK(l2, ((struct s){71451, "Apr"})),
                                            ((struct s){0, "Mar"}) ),
                                            ((struct s){69891, "Feb"}) );
  TLISTFOREACH(i, l2, ({ printf("%s %d\n", TLISTREF(i).s, TLISTREF(i).a); }));
  printf("Updating Mar\n");
  TLISTREF(TLISTFIND(i, l2, ({ strcmp(TLISTREF(i).s, "Mar") == 0; }))).a += 71660;
  TLISTFOREACH(i, l2, ({ printf("%s %d\n", TLISTREF(i).s, TLISTREF(i).a); }));
  TLISTCLEAR(l2);
}
