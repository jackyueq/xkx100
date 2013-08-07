// kudingcha.c

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("��ˮ��", ({ "wan", "bowl" }) );
	set_weight(400);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "����һ��ඡ�衣��ǳ��Ŀඡ�����΢�࣬��ζ��������ζ�೤��ʵΪ��Ʒ��\n");
		set("unit", "��");
		set("value", 0);
		set("max_liquid", 60);
	}

	// The liquid contained in the container is independent, we set a copy
	// in each cloned copy.
	set("liquid", ([
		"type": "water",
		"name": "�ඡ��",
		"remaining": 50,
	]) );
}
