// tiepai.c

inherit ITEM;

void create()
{
        set_name("����", ({ "qulingfeng tiepai", "tiepai", "pai" }) );
	set("long","
һ�����ɰ�����״�����ƣ���������������д��һ���������֡�
");
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
        }
        setup();
}

