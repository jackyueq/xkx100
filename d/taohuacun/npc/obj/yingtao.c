#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIR"ӣ��"NOR,({"yingtao"}));
	set_weight(50);
	if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ���ʺ��ӣ�ҡ�\n");
                set("unit", "��");
        }
}