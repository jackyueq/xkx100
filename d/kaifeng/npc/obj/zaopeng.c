inherit ITEM;
inherit F_LIQUID;

void create()
{
        set_name("ľ����", ({"zaopen"}));
        set_weight(500000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "ľͷ������,�Ѿ��ܳ¾ɡ�\n");
                set("unit", "ֻ");
                set("value", 100);
                set("max_liquid", 15);
        }
        set("liquid", ([
                "type": "alcohol",
                "name": "ϴ��ˮ",
                "remaining": 15,
                "drunk_apply": 3,
        ]));
}

