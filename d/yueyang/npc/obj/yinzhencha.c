// yinzhencha.c ��ɽ�����

#include <ansi.h>;
inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name(HIW"��ɽ�����"NOR, ({"junshan yinzhencha", "yinzhen", "cha"}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long","һ���ɽ����裬�װ׵�����Ĳ�Ҷ�ڷ�ˮ����ֱ����������ǳ���\n");
		set("unit", "��");
		set("value", 200);
		set("max_liquid", 15);
	}

	// because a container can contain different liquid
	// we set it to contain wine at the beginning
	set("liquid", ([
		"type": "tea",
		"name": "��ɽ�����",
		"remaining"  : 5,
		"drunk_apply": 2,
	]));
}
