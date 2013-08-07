// Room: /d/suzhou/.c
// Last Modified by winder on Mar. 8 2001

inherit ROOM;

void init()
{
//	add_action("lingwu","lingwu");
	add_action("do_jump","jump");
}

void create()
{
	set("short", "����");
	set("long",@long
���Ǳ�ˮͤ�ϵķ��������滭����ϣ��Źֵ��ֻ���
long
        );
	set("outdoors","suzhou");
	set("no_clean_up", 0);
	set("coor/x", 800);
	set("coor/y", -1200);
	set("coor/z", 10);
	setup();
}

int lingwu(string arg)
{
	object me=this_player();
	string special;
	int bl,sl;

	if (!living(me)) return 0;
	if (!arg) return notify_fail("��Ҫ����ʲô��\n");
	if (!find_object(SKILL_D(arg)))
// 	if (!find_object(SKILL_D(arg)))
		return notify_fail("û�����ּ��ܡ�\n");
	if (!me->query_skill(arg,1))
		return notify_fail("�㲻�����ּ��ܡ�\n");
	if (!(special=me->query_skill_mapped(arg)))
		return notify_fail("��ֻ�ܴ����⼼��������\n");
	bl=me->query_skill(arg,1);
	if (bl > me->query("jing") ||
		me->query("jing")*100/me->query("max_jing") < 20)
	{
		me->receive_damage("jing",bl/2);
		return notify_fail("��û�취���о���\n");
	}
	sl=me->query_skill(special,1);
	if (bl > sl)
		return notify_fail("���"+CHINESE_D->chinese(special)+"���費�����޷��������һ���"+CHINESE_D->chinese(arg)+"��\n");
	write("������ֻ��˼���룬��"+CHINESE_D->chinese(arg)+"�����������һ�㡣\n");
	me->receive_damage("jing",bl/2);
	me->improve_skill(arg,sl/5+1);
	return 1;
}
int do_jump(string arg)
{
	object me = this_player();

	if (arg !="down") return notify_fail("��Ҫ����ȥ��\n");
	if( arg=="down")
	{
		write("�����������˷�����\n");
		message("vision", me->name() + "һ���������˷�����\n", environment(me), ({me}) );
		me->move(__DIR__"bishuiting");
		message("vision", me->name() + "����������������\n", environment(me), ({me}) );
	}
	return 1;
}
