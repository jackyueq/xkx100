// Room: /d/huijiang/obj/box.c ����
// Last Modified by winder on Sep. 12 2001

#include <ansi.h>;
inherit ITEM;

void create()
{
	set_name(YEL"����"NOR, ({ "gold xiang", "xiang", "box" }) );
	set_weight(3000);
	set_max_encumbrance(500000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
                set("long","һ��װǮ�����ӣ��컨��Ӹ��ؽ����Ĳ���֮��ȫ�������\n");
		set("value", 1000);
		set("material", "wood");
		set("no_get",1);
		set("no_drop",1);
		set("amount",30);
	}
	setup();
}

int is_container() { return 1; }
