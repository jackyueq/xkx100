// mamian.c

#include <ansi.h>
inherit NPC;

void create()
{
	set_name(HIY "����" NOR, ({ "ma mian" }) );
        set("nickname",CYN "����" NOR);
        set("long",GRN @LONG
һ�����˷��ˣ������������֣��������棬��Ц�ƿޣ�������¶...
LONG NOR);
	set("max_jing", 10000);
	set("max_qi", 10000);
        set("age",1000000);
	set("combat_exp",1000000);
        
	setup();
}
int is_ghost()
{  
      return 1;
}
