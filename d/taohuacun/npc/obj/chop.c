
inherit ITEM;
#include <ansi.h>;

void create()
{
	set_name(YEL"�Ź�"NOR,({"chop","paigu"}));
	set_weight(300);
	if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ�����ʵ����Źǡ�\n");
                set("unit", "��");
        }
}