// Obj: /d/guiyun/obj/tuifa.c ����ɨҶ�ȷ�
// Last Modified by winder on Jul. 9 2001

inherit ITEM;

void create()
{
	set_name("����ɨҶ��ͼ��", ({ "tuifa tujie", "tujie", "shu", "book" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("treasure", 1);
		set("unit", "��");
		set("long", "�Ȿ�ȷ�����ϸ�ػ��Ż�ҩʦ����������ɨҶ�ȵ�ͼ�⣬��Ȼ������˵���Լ������������������ȷ��ľ���ȴ�ǿ��Եġ�\n");
		set("value", 40);
		set("material", "paper");
		set("skill", ([
			"name":	"leg",		// name of the skill
			"exp_required":	100,	// minimum combat experience required
			"jing_cost":	15,	// jing cost every time study this
			"difficulty":	25,	// the base int to learn this skill
			"max_skill":	30	// the maximum level you can learn
		]) );
	}
}
