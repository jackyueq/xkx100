// dongtingchun.c ��ͥ����

#include <ansi.h>;
inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name(HIG"��ͥ����"NOR, ({"dongtingchun cha", "cha", "tea"}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ�붴ͥ���裬�Ⱥ�����ð��һ�ɲ���ζ��\n");
		set("unit", "��");
		set("value", 100);
		set("max_liquid", 15);
	}

	// because a container can contain different liquid
	// we set it to contain wine at the beginning
	set("liquid", ([
		"type": "tea",
		"name": "��ͥ����",
		"remaining"  : 5,
		"drunk_apply": 2,
	]));
}
