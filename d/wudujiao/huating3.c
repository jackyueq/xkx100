// Room: /d/wudujiao/huating3.c

inherit ROOM;

void create()
{
	set("short", "����ͤ");
	set("long", @LONG
������һ����԰�е�Сͤ�ӣ�������������ɫ���㡣���Ϲ���һ��
����Ů�����轣ͼ��(picture)��
LONG
	);
	set("outdoors", "wudujiao");
	set("no_clean_up", 0);
	set("exits", ([
		"south" : __DIR__"huating1",
		"west" : __DIR__"huayuan3",
	]));
	set("item_desc",([
	    "picture":"ֻ��������Ů�ֳָֹ�����Ц��������㱼����ƺ��������������������������\n�������ƺ�������ĳ�ְ��أ���������Ż��е����ƱȻ�(bihua)һ�¿���\n\n",
]));
	set("coor/x", -44890);
	set("coor/y", -81040);
	set("coor/z", 30);
	setup();
}

void init()
{
	add_action("do_bihua", "bihua");
}

int do_bihua(string arg)
{
	object weapon;
	object me=this_player();
	int hookskill=(int)me->query_skill("hook", 1);
	int maxlevel, exp=(int)me->query("combat_exp");

	if( !arg || arg != "picture")
		return notify_fail("���ұȻ�ʲô��\n");
	if( me->query("qi") < (int)(me->query("max_qi")/5))
		return notify_fail("������ȥ��������ģ�\n");
	if (!objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "hook")
		return notify_fail("���ù������ұȻ�ʲô��\n");
	if (!((string)me->query("family/family_name")=="�嶾��"))
	{
		message_vision("$N���ű��ϵĻ����˼��Σ�����һ�������\n", me);
	}
	else
	{
		message_vision("$N�����������ջ�����Ů����������һ�ˡ�\n", me);
		if (exp*10 <= (hookskill*hookskill*hookskill))
		{
			me->receive_damage("qi", 30);
			return notify_fail("��ľ��鲻�����Ѿ����ܴӻ�������ʲô�ˡ�\n");
		}
		if (hookskill < 150)
		{
			me->improve_skill("hook", random((int)(me->query("int") +me->query_skill("literate"))));
			tell_object(me, "����������һЩ����������������š�\n");
		}
		else
		{
			tell_object(me, "����˰��쾢������ʲôҲû��ѧ����\n");
		}
	}
	me->receive_damage("qi", 30);
	return 1;
}

