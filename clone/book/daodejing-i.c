// daodejing-i.c

inherit ITEM;

void create()
{
	set_name("���¾����Ͼ�", ({ "jing", "daode jing" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit","��");
		set("long","����һ����¾����Ͼ����������һʼ��ȥ�õ���ʮֹ��\n");
		set("value", 500);
		set("material", "paper");
		set("skill", ([
			"name"        : "taoism",
			"exp_required":	0,
			"jing_cost"   : 20,
			"difficulty"  : 20,
			"max_skill"   : 49,
		]) );
	}
}
