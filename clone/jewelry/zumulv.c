// zhumulv.c

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIG"��ĸ��"NOR, ({ "zumu lv", "zumulv" }) );
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ�����̵ı�ʯ�������˼�ϡ���䱦��\n");
		set("unit", "��");
		set("value", 200000 );
	}

}
