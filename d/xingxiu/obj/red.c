// Room: /d/xingxiu/obj/red.c
// Last Modified by winder on Apr. 25 2001

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIR"���"NOR, ({"prize"}));
	set("unit", "��");
	seteuid(getuid());
	set("long","һ���������̶����������ĺ�����ø���Ȼ��Ӧ�þͿ��Եõ������ˡ�\n");
	set("value", 0);
	setup();
}

