// /d/meizhuang/shimen.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;

void create()
{
	set("short", "ʯ��");
	set("long", @LONG
������һ���谵��ʪ�ĵص����һ��ʯ�š�ǽ���ϵ���һյ�͵ƣ�
��������ɫ��â��
LONG
	);
	set("weapon_count",1);
	set("exits", ([ /* sizeof() == 2 */
		"northup" : __DIR__"midao1",
	]));
	set("coor/x", 3510);
	set("coor/y", -1420);
	set("coor/z", 0);
	setup();
}
void init()
{
	add_action("do_unlock", "unlock");
}
int do_unlock(string arg)
{
	object ob, midao2;

	if (query("exits/southdown"))
		return notify_fail("����ʯ���Ѿ��Ǵ򿪵ġ�\n");
	if (!arg || (arg != "men" && arg != "door"))
		return notify_fail("��Ҫ��ʲô��\n");
	if (!(ob = present("gang yaoshi", this_player())))
		return notify_fail("�㲻��������\n");
	if(!( midao2 = find_object(__DIR__"midao2")) )
                midao2 = load_object(__DIR__"midao2");
	if(objectp(midao2))
	{
		set("exits/southdown", __DIR__"midao2");
		message_vision("$N�Ѹ�оԿ�ײ�����һ���׿ף�ת�˼�ת�������ƶ���\nֻ�����������죬һ��ʯ�Ż������ˡ�\n", this_player());
		message("vision","ֻ��һ��Կ���룬ʯ���Ǳߺ������˿����ˡ�\n",
 midao2);
        }
	return 1;
}
