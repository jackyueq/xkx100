// tupu.c

inherit ITEM;

void create()
{
        set_name("�Ź�����ͼ��", ({ "tupu", "book", "shu" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		set("long", "
�Ź�������Ź�֮�壬������ꡣ����Ϊ�磬����Ϊ�㣻�������ߣ�������һ������м䡣
����ͼ�⣺Ǭ�����������Σ������飬�������������ۣ��޸��룻����ȱ�����¶ϡ�
��������������ˮ��ˮ��ľ��ľ���𣬻�������������
������ˣ����ľ��ľ����������ˮ��ˮ�˻𣬻�˽�
");
		set("value", 20);
        	set_weight(10);
		set("material", "paper");
		set("skill", ([
			"name":	"qimen-wuxing",	// name of the skill
			"exp_required":	100,	// minimum combat experience required
			"jing_cost":	20,	// jing cost every time study this
			"difficulty":	25,	// the base int to learn this skill
			"min_skill":	20,	// the minimum level you need before study
			"max_skill":	50	// the maximum level you can learn
		]) );
        }
        setup();
}

