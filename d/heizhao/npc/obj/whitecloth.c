// item: whitecloth.c

inherit ITEM;
#include <ansi.h>;
void create()
{
        set_name(HIW"�ײ�"NOR, ({"bai bu", "bu"}));
        set_weight(80);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", 
"����һ��ײ����������һ�ŵ�ͼ��ͼ��ע�������ֵ�������ͼ
����ʾ·�����У�·����ϵһ���ٲ�������é�ᡣ����ʱ���ɫ
���ҡ���\n");
                set("unit", "��");
                set("value", 1);
        }
}

