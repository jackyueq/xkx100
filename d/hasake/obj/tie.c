#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIC"��ѩʱ����"NOR, ({ "kuaixueshiqing tie", "tie"})); 
       
	if (clonep())
		set_default_object(__FILE__);
	else {
                set("unit", "��");
                set("weight", 300);
		set("long", "���ǽ�����֮��д֮����ֽ�᱾���ݶ����磬��һ�Ĵ硣\n");
		set("material", "paper");
		}
	setup();
}