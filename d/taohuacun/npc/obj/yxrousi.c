
#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(HIY "������˿" NOR, ({"yxrousi"}));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "һ��������磬΢����ζ��������˿��\n");
                set("unit", "��");
                set("value", 50);
                set("food_remaining", 4);
                set("food_supply", 20);
                set("cook_msg", "
$N�����⡢����Ƭ��ľ������˿�������мӵ������硣�ٽ����ϼ�����
�տ�������֭��Ȼ����˿���͹��л���ɢ���ӽ����⡢�ݺ콷����
����ζ������������Ƭ��ľ��˿�Գ���������֭��\n\n"
		);               
        }
}
