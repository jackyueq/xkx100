// xiang.c
#include <ansi.h>
inherit ITEM;

void setup()
{}

void create()
{
	set_name(HIC"������"NOR, ({"longxian xiang","xiang" }));
	set("unit","��");
	set("taskobj", 1);
	set("long","����һ��ں�ɫ�Ķ�����ɢ������������,��˵�����������档\n");
	set("value", 0);
	set_weight(50);
	setup();
}

