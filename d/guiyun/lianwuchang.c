// Room: /d/guiyun/lianwuchang.c
// Last Modified by winder on Jul. 9 2001

inherit ROOM;

int do_jump(string arg);
int do_squat();
string look_zhuang();

void create()
{
	set("short","���䳡");
	set("long",@LONG
���ǹ�����ׯ�ڵ����������ĳ��ӡ����߰������ű����ܣ������
�Ÿ��ֱ��������Ļ��Ǹ�ʽ�����Ľ����ڳ��ӵ�һ�������ﲢ������
������ߵ�ľ׮(zhuang)�����Լһ�ף��������������õġ���������
������Ϣ�ң�����������Ů������Ϣ�ҡ��ϱ��ǳԷ��ͺȲ�ĵط���
LONG
);
	set("exits",([
		"west" : __DIR__"xiuxishi-m",
		"east" : __DIR__"xiuxishi-f",
		"north" : __DIR__"zoulang6",
		"south" : __DIR__"fanting",
	]) );
	set("objects",([
		"/clone/weapon/changjian" : 1,
		__DIR__"obj/mujian" : 1,
		__DIR__"npc/dizi-m" : 1,
		__DIR__"npc/dizi-f" : 1,
	]));

	set("item_desc",([
		"zhuang" : (: look_zhuang :),
	]) );
	set("no_clean_up",0);
	set("outdoors", "guiyun");
	setup();
}

void init()
{
	add_action("do_jump", "jump");
	add_action("do_jump", "tiao");
	add_action("do_squat", "squat");
	add_action("do_squat", "dun");
}

int do_jump(string arg)
{
	object me = this_player();
	int level, qicost, exp;

	if (me->is_busy())
		return notify_fail("����һ��������û����ɣ�\n");
	level = me->query_skill("dodge", 1);
	exp = me->query("combat_exp");
	if (arg == "zhuang")
	{
		if (me->query_temp("thd_zhuang"))
		{
			write("���Ѿ���׮���ˣ�����վ����ͷ��ɣ�\n");
			return 1;
		}
		qicost = level / 3 + random(level / 3);
		if (me->query("qi") <= qicost)
		{
			write("��̫���ˣ���ЪЪ�ɣ�\n");
			return 1;
		}
		if (level < 20)
		{
			write("���������ƣ���׮��Ծȥ����ϧ���ǽż⻹��һЩ���ܹ�����\n");
			return 1;
		}
		me->receive_damage("qi", qicost);
		if (level < 60)
		{
			message_vision("$N���˿�����������ľ׮�����ƺ��Ƕ����Ṧ�ĺ÷�����\n", me);
			if (level * level * level / 10 < exp)
				me->improve_skill("dodge", me->query_int() / 2);
		}
		else
			message_vision("$N����΢һ�˾��������һ�ݾ�����ľ׮��������ľ׮��$P����Ҳ̫���ˡ�\n", me);
		me->set_temp("thd_zhuang", 1);
		me->start_busy(random(2)+1);
		return 1;
	}
	if (arg == "down")
	{
		if (!me->query_temp("thd_zhuang"))
		{
			message_vision("$N���ڸ�������ȥ���Ĵ��Ȼ���һ����ȴ������Χ���˶����������۹⿴���Լ���\n", me);
			return 1;
		}
		qicost = level / 4 + random(level / 4);
		if (me->query("qi") <= qicost)
		{
			write("��̫���ˣ���ЪЪ�ɣ�\n");
			return 1;
		}
		me->receive_damage("qi", qicost);
		if (level < 60)
		{
			message_vision("$N���ֱ��ŵش�׮�ϵ����������������������ͨ�Ṧ��һʽ��ƽɳ���㡱��\n", me);
			if (level * level * level / 10 < exp)
				me->improve_skill("dodge", me->query_int() / 5);
		}
		else
			message_vision("$N����һ���䵽�˵��ϣ�����������ľ׮��$P����Ҳ̫���ˡ�\n", me);
		me->start_busy(random(2)+1);
		me->delete_temp("thd_zhuang");
		return 1;
	}
	return notify_fail("��Ҫ����������\n");
}
	
int do_squat()
{
	object me = this_player();
	int level, qicost, exp;

	if (me->is_busy())
		return notify_fail("����һ��������û����ɣ�\n");
	level = me->query_skill("leg", 1);
	exp = me->query("combat_exp");
	qicost = level / 3 + random(level / 3);
	if (!me->query_temp("thd_zhuang"))
	{
		message_vision("$N��������һ�ף����и�ׯ�����ܹ����������ȵ�������׼��ش�С�㣡��\n", me);
		return 1;
	}
	if (me->query("qi") <= qicost)
	{
		write("��̫���ˣ���վ����������ɣ�\n");
		return 1;
	}
	if (level < 30)
	{
		write("�����Ŷ�������ȴ�������ȷ�����ʱ�е���ȥ��Σ�գ���æ��վֱ�����ӡ�\n");
		return 1;
	}
	if (level < 100)
	{
		write("��˫�ȳ�����ͦ���ո�����վ׮���ƶ���������\n");
		write("������ã����˫�ȶ���ľ�ˣ�ֻ��վ�����һ�¡�\n");
		if (level * level * level / 10 < exp)
			me->improve_skill("leg", me->query_int());
		me->receive_damage("qi", qicost);
		me->start_busy(random(2)+1);
		if (!random(8))
			tell_room(this_object(), me->name() + "˫�ȳ�����ͦ���ո�����վ׮���ƶ���һ�ᡣ\n", ({me}));
	}
	else
		write("����������һ�ף�ֻ��ľ׮��֨�¡����죬��������Ⱦ������ˡ�\n");
	return 1;
}

string look_zhuang()
{
	if (this_player()->query_temp("thd_zhuang"))
		return "�������µ�ľ׮��ȥ�������е���ѣ���ղ��ڵ��Ͽ�ʱ����û����ô�ߣ�\n";
	else
		return "ľ׮��ش��һ�����ң���ͨ����������ȥ��\n";
}

int valid_leave(object me, string dir)
{
	if (me->query_temp("thd_zhuang"))
		return notify_fail("�ȴ�ľ׮��������(down)��˵�ɣ�\n");

	if (dir == "west" && me->query("gender") != "����")
		return notify_fail("�������Ҫ�����ߣ���Ȼ�������涼�ǹ���ӵ��е��ӣ����æ���������˳�����\n");

	if (dir == "east" && me->query("gender") != "Ů��")
		return notify_fail("�������Ҫ�����ߣ�ȴ�������洫��һ��Ů���ӵļ���������ŵø�æ���˳�����\n");
	return ::valid_leave(me, dir);
}
