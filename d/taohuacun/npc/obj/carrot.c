
inherit ITEM;
#include <ansi.h>;

void create()
{
	set_name(HIR"���ܲ�"NOR,({"carrot","huluobo"}));
	set_weight(300);
	if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ�����ܲ���\n");
                set("unit", "��");
        }
}