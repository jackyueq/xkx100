// Room: /d/xingxiu/obj/yushi.c
// Last Modified by Winder on Apr. 25 2001
#include <ansi.h>
inherit ITEM;
void create()
{
	switch(random(8))
	{
		case 0 : set_name(HIW "����ʯ" NOR, ({ "yushi"})); break;
		case 1 : set_name(GRN "è��ʯ" NOR, ({ "yushi"})); break;
		case 2 : set_name(RED "��Ѫʯ" NOR, ({ "yushi"})); break;
		case 3 : set_name(BLU "����ʯ" NOR, ({ "yushi"})); break;
		case 4 : set_name(WHT "����ʯ" NOR, ({ "yushi"})); break;
		case 5 : set_name(MAG "�ϻ���" NOR, ({ "yushi"})); break;
		case 6 : set_name(YEL "�ư���" NOR, ({ "yushi"})); break;
		case 7 : set_name(CYN "������" NOR, ({ "yushi"})); break;
	}
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("value", 300000);
		set("unit", "��");
		set("weight", 100);
		set("long", "����һС����ʯ��������ֵ����Ǯ��\n");
		set("material", "stone");
		}
	setup();
}
