// quanzhen-ling.c ȫ����

inherit ITEM;

void create()
{
        set_name("ȫ����", ({"quanzhen ling", "letter", "ling"}));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long","����һ���������������ƣ��ɵ�������ǩ����ƾ�˿ɵ���������ʦ����ս��\n");
//		set("no_drop", "�������������뿪�㡣\n");
                set("material", "steel");
        }
}

