// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
                 // wine.c ���׾�

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("���׾�", ({"mijiu"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "�Ϸ��˰��ԵĽ��׾ơ�\n");
                set("unit", "��");
                set("value", 120);
     set("food_remaining",6);
                set("food_supply", 20);
        }

        // because a container can contain different liquid
        // we set it to contain wine at the beginning
        set("liquid", ([
                "type": "alcohol",
                "name": "���׾�",
                "drunk_apply": 10,
        ]));
}
