// /d/yixing/obj/tuchan.c
// Last Modified by winder on Jul. 12 2002

inherit ITEM;

void create()
{
	set_name("�ض�����", ({ "tuchan" }));
	set("weight", 200);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "����һ���ض�������\n");
		set("unit", "��");
		set("material", "wood");
		set("value", 300);
	}
	setup();
}
