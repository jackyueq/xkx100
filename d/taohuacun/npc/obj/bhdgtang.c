#include <ansi.h>
inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name(HIG "�ٺ϶�����" NOR, ({"bhdgtang"}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ������ˬ�ڣ�����ȥ֬���İٺ϶�������\n");
		set("unit", "��");
		set("value", 120);
		set("max_liquid", 20);
		set("cook_msg", "
$N�Ѷ���ȥ��ϴ����Ƥ�м����ʰٺ��п�ȥ�ģ���ˮ���룬
��ԼһСʱ����������\n\n"
		);		
	}

	// because a container can contain different liquid
	// we set it to contain wine at the beginning
	set("liquid", ([
		"name": "�ٺ϶�����",
		"remaining": 20,
		"drunk_apply": 6,
	]));
}

