#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(WHT "�㹽" NOR,({"xianggu"}));
	set_weight(200);
	if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ���ղ�ժ�������㹽��\n");
                set("unit", "��");
        }
}