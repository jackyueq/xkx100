// jiasha.c

inherit ITEM;
void setup()
{}

void init()
{
}

void create()
{
        set_name("����", ({"jia sha", "jia", "sha"}));
        set_weight(800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ���ɵ��Ѿ���������ɫ�����ģ������кö������\n");
                set("unit", "��");
                set("material", "cloth");

        }
        setup();
}

