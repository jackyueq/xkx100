// Room: /d/gumu/obj/box.c ����
// Last Modifyed by Winder on Jan. 14 2002

#include <ansi.h>
inherit ITEM;
void create()
{
	set_name(RED "������" NOR, ({ "da tiehe", "tiehe", "box" }) );
	set_weight(30000000);
	if( clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ���⼣�߰ߵĴ������ӣ������ܾ�û���˶����ˡ�\n");
		set("value", 1000);
		set("material", "steel");
		set("no_get",1);
		set("no_drop",1);
		set("amount",30);
	}
	setup();
}

