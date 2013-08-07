// /d/meizhuang/midao4.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;

void create()
{
	set("short", "�ص�");
	set("long", @LONG
����һ�����������µĵص���ǽ���ϵ���һյ�͵ƣ���������ɫ��
â����â���Ź��䴦������һ�����ҡ�
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
		"northup"   : __DIR__"midao3",
	]));
	set("no_clean_up", 0);

	set("coor/x", 3510);
	set("coor/y", -1450);
	set("coor/z", -150);
	setup();
}
void init()
{
	add_action("do_unlock", "unlock");
}
int do_unlock(string arg)
{
	object ob, jianyu;

	if (query("exits/east"))
		return notify_fail("���������Ѿ��Ǵ򿪵ġ�\n");
	if (!arg || (arg != "men" && arg != "door"))
		return notify_fail("��Ҫ��ʲô��\n");
	if (!(ob = present("gang yaoshi", this_player())))
		return notify_fail("�㲻��������\n");
	if(!( jianyu = find_object(__DIR__"jianyu")) )
		jianyu = load_object(__DIR__"jianyu");
	if(objectp(jianyu))
	{
		set("exits/east", __DIR__"jianyu");
		message_vision("$N�Ѹ�оԿ�ײ�����һ���׿ף�ת�˼�ת�������ƶ���\nֻ����һ����ɬ���춯��$N���ְ�����������\n", this_player());
		jianyu->set("exits/west", __FILE__);
                message("vision","ֻ��һ��Կ���룬�����Ǳߺ������˿����ˡ�\n", jianyu);
		remove_call_out("close_gate");
		call_out("close_gate", 5);
	}
        return 1;
}
void close_gate()
{
	object jianyu;

	if( !query("exits/east") ) return;
        message("vision","��������ѽѽһ���룬���һ���ֹ����ˡ�\n", this_object
());
	if( jianyu = find_object(__DIR__"jianyu") )
	{
		message("vision", "��������ѽѽһ���룬���һ���ֹ����ˡ�\n", jianyu);
		jianyu->delete("exits/west");
        }
        delete("exits/east");
}

