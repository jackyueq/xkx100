// Obj: /d/guiyun/obj/tuijian_xin.c
// Last Modified by winder on Jul. 9 2001

inherit ITEM;

void create()
{
        set_name("�Ƽ���", ({ "recommend letter", "letter", "xin" }) );
	set("owner", "jpei");
	set("long","����½�˷�д����ҩʦ��һ���š�\n");
        set_weight(2);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
        }
        setup();
}

