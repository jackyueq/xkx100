// niutou.c

#include <ansi.h>
inherit NPC;

void create()
{
	set_name(HIB "ţͷ" NOR, ({ "niu tou" }) );
        set("nickname",CYN "����" NOR);
        set("long",RED @LONG
һ�����˷��ˣ������������֣�����ţͷ����Ц�ƿޣ�������¶...
LONG NOR);
        set("age",0);
	set("max_jing", 10000);
	set("max_qi", 10000);
	set("combat_exp",1000000);
        
	setup();
}
int is_ghost()
{  
      return 1;
}
