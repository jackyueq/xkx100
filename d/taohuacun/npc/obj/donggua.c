#include <ansi.h>	
inherit ITEM;
#include <ansi.h>;

void create()
{
	set_name("����",({"donggua"}));
	set_weight(1000);
	if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ�����ϡ�\n");
                set("unit", "��");
        }
}