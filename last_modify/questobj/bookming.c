
inherit ITEM;

void init()
{
}

void create()
{
        set_name("��ʷ����", ({"book ming","book","ming"}));
        set_weight(1500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ�������顣\n");
                set("unit", "��");
                set("material", "paper");
        }
        setup();
}
