// wenshu.c
#include <ansi.h>
inherit ITEM;
string target;

void create()
{
	set_name(WHT "��������" NOR, ({ "wenshu", "wen",}));
	set("weight", 100);
	if(clonep()) set_default_object(__FILE__);
	else{
		set("unit", "��");
		set("long", WHT"����һ�ź������飬������һ�����񣬵�����һ��С�֣��������ϸ������\n" NOR);
		set("value", 0);
		set("no_get", 1);
		set("no_drop", 1);
	}
	setup();
}
 
 
#include "wenshu.h"
