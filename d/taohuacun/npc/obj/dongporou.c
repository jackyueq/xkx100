
#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(RED"������"NOR, ({"dongporou"}));
        set_weight(1000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "һ��������Ķ����⣬���Ļ��з�������ɣ�
�ն��������غ���ʱ��������������Ʋ��÷����Żݴ˷���ǧ�����¡�\n");
                set("unit", "��");
                set("value", 120);
                set("food_remaining", 10);
                set("food_supply", 100);
                set("cook_msg", "
$N�������廨�����з�����飬�·�ˮ��������Ȼ���ڴ�ɰ��������
�кͽ��飬������������⣬�ӵ��ϸǺù��ǣ�����ɴֽ��졣��ɰ��
�������ϣ��տ������΢���˶�Сʱ������鷭���ټӸ��ܷ⣬��΢
���˶�Сʱ������鷭�����ã������չ���������������\n\n"
		);                
        }
}
