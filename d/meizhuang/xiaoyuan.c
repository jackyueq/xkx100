// /d/meizhuang/xiaoyuan.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;

void create()
{
	set("short", "����СԺ");
	set("long", @LONG
����һ���������ǳ���ͨ��СС��Ժ�䣬Ժ�ӵ��м佨��һ��С�ݣ�
С��Ҳ����ͨ��������é��Ϊ����ש��Ϊǽ��Ժ����û��ʲô���裬ֻ
�м��Ѹ�ľ��(wood)���ڽ����������һ���ر�����עĿ�� 
LONG
	);
	set("weapon_count",1);
	set("exits", ([ /* sizeof() == 2 */
		"south" : __DIR__"xiaodao",
		"enter" : __DIR__"xiaowu",
	]));
	set("item_desc",([
		"wood" : "һ��Ѹɲ�������һ������ɫ�Ƚ��ر�\n",
	]));
	set("objects", ([
		__DIR__"npc/ding" : 1,
	]));
	set("outdoors", "meizhuang");

	set("coor/x", 3510);
	set("coor/y", -1430);
	set("coor/z", 20);
	setup();
}
void init()
{
	add_action("do_pull", "pull");
	add_action("do_unlock", "unlock");
	if (present("ding jian", environment(this_player())))
		delete("exits/east");
}
int do_unlock(string arg)
{
	object ob;
	if (query("exits/east"))
		return notify_fail("�������Ѿ��Ǵ򿪵ġ�\n");
	if (!arg || (arg != "men" && arg != "east"))
		return notify_fail("��Ҫ��ʲô��\n");
	if (!(ob = present("hongyu yaoshi", this_player())))
		return notify_fail("�㲻��������\n");
	set("exits/east", __DIR__"mishi2");
	message_vision("$N�Ѻ���Կ�׷Ž��ŵİ��ݴ������ߵ�һ���������Ĵ��ˡ�\n", this_player());
	destruct(ob);
	return 1;
}
int do_pull(string arg)
{
	object ob, me = this_player();
	if (arg == "wood" && !present("sea-wood", me) &&
		query("weapon_count") >= 1)
	{
		add("weapon_count", -1);
		ob=new(WEAPON_DIR"treasure/sea-wood");
		if ( ob->violate_unique() )
		{
			destruct( ob );
			message_vision("$N���˰��죬Ҳû�з���ʲô�ر�Ķ�����\n", me);
			return 1;
		}
		ob->move(__DIR__"xiaoyuan");
		message_vision("$N��ľ����ﲦŪ�ţ�һ�����ε�ľ�����˳�����\n", me);
		return 1;
	}
	else {
		message_vision("$N���˰��죬Ҳû�з���ʲô�ر�Ķ�����\n", me);
		return 1;
	}
}
