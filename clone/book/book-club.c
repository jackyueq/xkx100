// Last Modified by winder on May. 29 2001

inherit ITEM;

void create()
{
	set_name("��ɮ����", ({ "clubbook", "shu", "book" }));
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long","�����ഫΪ�Ƴ�����ʮ����ɮ����\n��һ������������һЩ���γֹ���ս���Ļ�ҳ������д�����ھ���\n");
		set("treasure", 1);
		set("value", 200);		set("material", "paper");
		set("skill", ([
			"name"        : "club", // name of the skill
			"exp_required":	1000,   // minimum combat experience
						// required
			"jing_cost"  :  25, //jing cost every time study this
			"difficulty" :	20, // the base int to learn this skill
			"max_skill"  :  100 // the maximum level you can learn
		]) );
	}
}
