// qin.c

#include <weapon.h>
inherit HAMMER;
void create()
{
	set_name("��ľ��", ({ "gumu qin", "qin" }) );
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ������ɫ���㣬�����ڰ������������١�\n");
		set("value", 3);
		set("material", "iron");
	}

	init_hammer(16);
	setup();
}
