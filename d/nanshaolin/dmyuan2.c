// Room: /d/nanshaolin/dmyuan2.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void init()
{
	add_action("lingwu","lingwu");
}

void create()
{
	set("short", "��ĦԺ���");
	set("long", @LONG
����һ�����ӵĵ��á����׵�ǽ�Ϲ����˸����书ͼ�ף����ٰ���
��ü����ɮ����������ͼ�׻���֮ǰ���ƺ��ڿ��˼�����ϱ�ɽǽ�Ǹ�
���ݶ��Ĵ���ܣ��߽�ϸ���������Ǹ��Ÿ��ɵ��书���ţ������а���
���Ű���ڭ�ͼ����ţ���λ��ɮ�����붨�С�
LONG );
	set("exits", ([
		"south" : __DIR__"dmyuan",
	]));
	set("coor/x", 1790);
	set("coor/y", -6080);
	set("coor/z", 20);
	setup();
}

int lingwu(string arg)
{
	object me=this_player();
	string special;
	int bl,sl;

	if (!me->query("muren_winner"))
		return notify_fail("��δ��ľ��������ڴ�����\n");
	if (!arg) return notify_fail("��Ҫ����ʲô��\n");
	if (!me->query_skill(arg,1))
		return notify_fail("�㲻�����ּ��ܡ�\n");
	if (me->is_busy() || me->is_fighting())
		return notify_fail("����æ���ء�\n");
	if (arg == "force" )
		return notify_fail("���޷���������ڹ���\n");
	if ((int)me->query("potential") -(int)me->query("learned_points") < 1 ) 
		return notify_fail("���ʵս�еõ���Ǳ���Ѿ������ˡ�\n");
	if (!(special=me->query_skill_mapped(arg)))
		return notify_fail("��ֻ�ܴ����⼼��������\n");
	bl=me->query_skill(arg,1);
	if (bl > me->query("jing") ||
		me->query("jing")*100/me->query("max_jing") < 50)
	{
		me->receive_damage("jing",bl/5);
		return notify_fail("��û�취���о���\n");
	}
	sl=me->query_skill(special,1);
	if (sl > 200)
		return notify_fail("���" +to_chinese(special)+"�����Ѿ��ܸ��ˣ�����������������ʲô�ˡ�\n");
	if (bl > sl)
		return notify_fail("���" +to_chinese(special)+"���費�����޷��������һ���"+to_chinese(arg)+"��\n");
	write("���˼���룬��"+to_chinese(arg)+"�����������һ�㡣\n");
	if ((int)me->query("combat_exp",1) >850000)
	{
		me->receive_damage("jing",bl/5*3);
		me->add("learned_points", 1);
		me->improve_skill(arg, me->query_int()*3/2);
		me->start_busy(1);
		return 1;
	}
	me->receive_damage("jing",bl/5*2);
	me->add("learned_points", random(2));
	me->improve_skill(arg, me->query_int()*3/2);
	me->start_busy(1);
	return 1;
}

