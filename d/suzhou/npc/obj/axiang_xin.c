// Last Modified by Winder on May. 15 2001
// /d/suzhou/obj/axiang_xin.c

inherit ITEM;

void create()
{
        set_name("�������", ({ "letter", "axiang letter", "xin" }) );
	set("long", "���ǰ���д�������޵�һ���ţ�ϣ������һ�׵�Ĺ���߸������ˡ�\n");
        set_weight(2);
	seteuid(getuid());
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
        }
        setup();
}

