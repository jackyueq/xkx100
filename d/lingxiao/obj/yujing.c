// Obj: /d/lingxiao/obj/yujing.c
// Last Modified by winder on Jul. 15 2001

inherit ITEM;
#include <ansi.h>

void create()
{
	set_name(HIW"������"NOR, ({"bingpo yujing", "yujing"}));
	set_weight(80);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long","�������꺮����������ɵı����񾫣�����ȥ�����͸��ɢ���������ĵĹ�â��\n");
		set("unit", "��");
		set("value", 70000);
	}
}

