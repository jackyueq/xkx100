// /d/shenlong/obj/songci.c
// Last Modified by winder on Jul. 12 2002

inherit ITEM;

void create()
{
	set_name("�̴�", ({ "songci" }));
	set("weight", 1000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long","����һƪ������̴ʡ�\nϹ��������������������϶�ǧ��������̽�����ĳ�����������\n");
		set("unit", "��");
		set("value", 20);
	}
	setup();
}
