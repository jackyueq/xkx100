// shigu.c
#include <ansi.h>

inherit ITEM;

void create()
{
	set_name("ʯ��", ({ "shi gu", "gu" }) );
	set_weight(30000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
                set("long", "����һ���ܹ��ӵ�ʯ�ģ����������ŵ��еİ��\n");
		set("value", 100);
		set("material", "stone");
		set("no_get",1);
		set("no_drop",1);
	}
	setup();
}

