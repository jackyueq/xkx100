// hongbao.c ���
#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIR"���"NOR, ({ "red bag", "hong bao", "bao" }));
	set_weight(500);
	set_max_encumbrance(1000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ�����Ƶĺ�ֽ�����������̽�Ļ��ƣ�����װ������������ʡ�\n");
		set("value", 1000);
	}
}

int is_container() { return 1; }
