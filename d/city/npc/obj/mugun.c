// mugun.c ľ��

#include <weapon.h>
inherit CLUB;

void create()
{
	set_name("ľ��", ({ "mugun", "gun" }) );
	set_weight(350);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ�����úܾ��µĶ̹���\n");
		set("unit", "��");
		set("value", 100);
		set("wield_msg", "$Nץ��һ��$n���������е�������\n");
		set("material", "wood");
	}
	init_club(1);
	setup();
}
