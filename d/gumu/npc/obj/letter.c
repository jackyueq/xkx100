// letter.c

inherit ITEM;

void create()
{
        set_name("��", ({"long xin", "xin", "letter"}));
        set_weight(100);
        set("value",1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long","����һ�������С��Ů�����š�\n");
//		set("no_drop", "�������������뿪�㡣\n");
                set("material", "paper");
        }
}

