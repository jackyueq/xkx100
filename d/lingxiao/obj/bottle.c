// Obj: /d/lingxiao/obj/bottle.c ��ƿ
// Last Modified by winder on Jul. 15 2001

inherit ITEM;

void create()
{
	set_name("��ƿ", ({ "bottle", "hua ping", "bag" }));
	set_weight(500);
	set_max_encumbrance(10000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long","һ�������꺮�����ƵĻ�ƿ����Ө��͸������ޱȣ���֦÷���������棬�������硣\n");
		set("value", 0);
	}
}

int is_container() { return 1; }

