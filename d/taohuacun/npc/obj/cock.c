#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIR "����" NOR,({"cock"}));
	set_weight(200);
	if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һֻ�۹�����\n");
                set("unit", "ֻ");
        }
}