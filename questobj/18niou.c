// 18niou.c

#include <ansi.h>
inherit ITEM;
void create()
{
	set_name(YEL"ʮ����ż"NOR, ({ "18 niou", "niou" }));
	set_weight(600);
	set("taskobj", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", 
"����һ��Сľ�У����е����޻�������������������ż��ÿ����
��������һʮ�˸�����ż�������ɣ�ÿ��������������ˣ�Ƥ��
��Ϳ�˰��ѣ�������һ�������ߣ����������ڵ㣬���������Ѩ
���ķ�λ��\n");
		set("value", 0);
		set("material", "mud");
	}
}

