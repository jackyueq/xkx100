#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(RED"��������"NOR, ({"xhcuyu"}));
        set_weight(1300);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "һ��������˵��������㣬�������еĽ�ɫ����
���ƶ��ɣ���������һ���ˡ�\n");
                set("unit", "��");
                set("value", 120);
                set("food_remaining", 20);
                set("food_supply", 20);
                set("cook_msg", "
$N�Ƚ���������,���ų�����ζ��������ɱ��ȥ���ۡ��������࣬
ϴ������ͷ��βƬ����Ƭ�����µ����ϵ��ƣ����� ��ˮ��������
�����������²�������������ʱ���̳����㱳���װ�����ڡ���
�������ˮ���������뽴�͡��ס��ܾơ����ǣ��տ�������ʪ��ۣ�
�ƽ�������֭�����������ϡ�\n\n"
		);                
        }
}
