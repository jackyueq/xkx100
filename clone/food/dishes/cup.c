// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
inherit ITEM;
inherit F_LIQUID;

void create()
{
        set_name("�����յ", ({"jiu zhan","zhan", "cup"}));
        set_weight(700);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "һ���������С��յ��\n");
                set("unit", "��");
                set("value", 500);
                set("max_liquid", 10);
        }

        // because a container can contain different liquid
        // we set it to contain wine at the beginning
        set("liquid", ([
                "type": "alcohol",
                "name": "Ů����",
                "remaining": 10,
                "drunk_apply": 5,
        ]));
}

