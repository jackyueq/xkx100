// liuhuang.c ���
inherit ITEM;
void create()
{
        set_name("���", ({"liuhuang"}));
        set_weight(40);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "һ���ɫ����Ǿ��塣\n");
                set("unit", "��");
                set("value", 10);
        }
}
