// taomujian.c
// Last Modified by winder on May. 25 2001

#include <weapon.h>
inherit SWORD;

void create()
{
	set_name("��ľ��", ({"taomu jian", "sword", "jian"}));
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","һ����ľ�Ƴɵĳ�����һ��������д�仭���ģ�\n");
		set("unit", "��");
		set("value", 200);

	}
	init_sword(5);
	setup();
}

