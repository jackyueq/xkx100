// shanshen.c ��ɽ��

#include <ansi.h>
inherit ITEM;

void setup()
{}

void init()
{
}

void create()
{
	set_name(YEL"��ɽ��"NOR, ({"laoshan shen", "shen"}));
	set("taskobj", 1);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ��մ��ɽ��ĳ�����ɽ�Ρ�\n");
		set("value", 0);
	}
	setup();
}

