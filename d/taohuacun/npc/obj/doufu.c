#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIW "����" NOR,({"doufu"}));
	set_weight(50);
	if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "�������۵Ķ�����\n");
                set("unit", "Щ");
        }
}