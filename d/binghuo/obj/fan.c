// fan.c
#include <ansi.h>
inherit ITEM;

void setup()
{}

void create()
{
	set_name("����", ({"fan bu", "fan" }));
	set("unit", "��");
	set("long", "����һ�������ķ�������������ʲô�á�\n");
	set("value", 0);
	set("no_drop", "�������������뿪�㡣\n");
	set_weight(500);

        setup();
}

