#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(YEL "Сţ����" NOR,({"yaozi"}));
	set_weight(300);
	if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ��Сţ���ӡ�\n");
                set("unit", "��");
        }
}