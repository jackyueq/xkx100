// Room: /d/gumu/qinshi.c
// Last Modifyed by Winder on Jan. 14 2002

#include <ansi.h>;
inherit ROOM;
void create()
{
	set("short", HIC"����"NOR);
	set("long", @LONG
һ��ʯ��(table)��һ��ʯ�ʣ����Ϸ���һ�ѹ���(qin)����С��Ů
���ʱ�̸����㻳�ĵط���ÿÿ����������ƽ����ͣ�ֱ�����ĳ�������
����������
LONG	);
	set("exits", ([
		"west" : __DIR__"mudao18",
	]));
	set("item_desc", ([
		"qin"   : HIC"����һ�������Զ�Ĺ��٣��ٷ���ӣ�����������
���Ͽ��š���Զ ���� �ɷ硱�����֡�\n"NOR,
		"table" : "���Ϸ���һ�ѹ��١� \n",
	]));
	set("coor/x", -3160);
	set("coor/y", 10);
	set("coor/z", 90);
	setup();
}

void init()
{
	add_action("do_tan", "tan");
	add_action("do_tan", "play");
}

int do_tan(string arg)
{
	mapping fam;
	object me = this_player();
	int c_exp, c_skill;

	c_skill=(int)me->query_skill("force", 1);
	c_exp=me->query("combat_exp");

	if (arg == "qin")
	{
		if(!(fam = me->query("family")) || fam["family_name"]!="��Ĺ��")
			return notify_fail("�ǹ�Ĺ���ˣ����������Ĺ�书��\n");
		if (me->query("qi") < 30 || me->query("jing") < 30)
			return notify_fail("�㾫��к�����ȥЪϢһ���������ٰɡ�\n");
		write(HIC"���Ŀ����һ����Ϣ�����������ĸ��ٶ�����\n"NOR);
		if (c_skill < 50 )
			return notify_fail("�㵯�˰��죬��������ѻ�����㻹�ǵ��޻�ȥ�ɡ�\n");
		if (me->query_skill("force", 1) > 100)
		{
			message_vision(
HIC"$N�������ߣ������پ�����������������������\n\n"
BLINK HIY"�׺�һ��Ц ����������\t�������� ֻ�ǽ�
����Ц �׷����ϳ�\t˭��˭ʤ�� ��֪��
��ɽЦ ����ң\t�����Ծ� �쳾�������ཿ
���Ц ���Ǽ���\t���黹ʣ��һ������
����Ц ���ټ���\t�������� �ճ�ЦЦ\n"NOR,me);
			return 1;
		}
		if( c_skill > 100)
			return notify_fail("���ڹ���տ��������������������������\n");
		write("���������ߣ������پ�����������ƽ�ͣ�����������Ȼ������\n");
		me->receive_damage("qi", 15+random(10), me);
		me->receive_damage("jing", 15+random(10), me);
		if ((random(10)>3) && c_skill*c_skill*c_skill/10<c_exp)
			me->improve_skill("force", random(me->query("int")) );
		return 1;
	}
	write("��Ҫ��ʲô�����޻���\n");
	return 1;
}

