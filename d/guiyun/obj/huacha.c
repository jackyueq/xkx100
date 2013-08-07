// Obj: /d/guiyun/obj/huacha.c
// Last Modified by winder on Jul. 9 2001

inherit ITEM;
inherit F_LIQUID;

void each_drink();

void create()
{
	set_name("���򻨲�", ({"moli huacha", "huacha", "cha", "tea"}));
	set_weight(20);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ��ɢ������������򻨲衣\n");
		set("unit", "��");
		set("value", 0);
		set("max_liquid", 5);
	}

    // because a container can contain different liquid
    // we set it to contain tea at the beginning
	set("liquid", ([
		"type": "tea",
		"name": "��ˮ",
		"remaining": 5,
		"drunk_supply": 0,
		"drink_func": (: call_other, this_object(), "each_drink" :),
	]));
}
/*
void each_drink()
{
	if (!query("liquid/remaining")) 
		destruct(this_object());
}
*/
