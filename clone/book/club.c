//club.c

inherit ITEM;

void create()
{
	set_name("����ͨ��", ({"shu", "book" }));
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long","����һ����ϰ�������侭��\n��������������ɵ���������������ĵã����滭�Ÿ�ʽ�����С�ˡ�\n");
		set("value", 500);
		set("material", "book");
		set("skill", ([
			"name":	"club",	// name of the skill
			"exp_required":	0,	// minimum combat experience required
			"jing_cost":	20,	// jing cost every time study this
			"difficulty":	20,	// the base int to learn this skill
			"max_skill":	100	// the maximum level you can learn
		]) );
	}
}
