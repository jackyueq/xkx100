//longjing.c

inherit ITEM;
inherit F_LIQUID;

void create()
{
//ʵ�������Ӧ���Ǹ������һ��ʼ�����ġ�
	set_name("������",({"longjing cha", "cha hu", "hu"}));
 	set_weight(120);
	if (clonep())
		 set_default_object(__FILE__);
	 else {
 		set("long", "һ������������裬���Ƶ�ð������~~~~~~\n");
		set("unit", "��");
 		set("value", 80);
        set("remaining",10);
		set("drink_supply", 20);
	}
	set("liquid", ([
		"type": "tea",
		"name": "������",
		"remaining": 15,
		"drunk_apply": 3,
	]));
}

