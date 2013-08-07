// /yubifeng/shimen.c
// Last modified by winder 2003.9.2

inherit ROOM;

void create()
{
	set("short", "ʯ��");
	set("long", @LONG
��Ѩ������խ����ù�����з���ͨ�������е�����ǧ�겻���ļ�
������Щ�����ı����絶�������ͻ������ʱͷ��ײ���˼����ǣ���
�����ۡ�ͨ����ͷ��ֻ��һ��Բ�ξ��ҵ�����һ��Բ���ϣ�������ҷ�
ס��ȥ·��ٲȻһ��ʯ�š�����(yan)֮�䶼�Ǽ��(bing)���ᡣ
LONG );
	set("exits", ([
		"south" : __DIR__"tongdao2",
	]));
	set("objects", ([
		__DIR__"npc/huyidao" : 1,
		__DIR__"npc/hu-wife" : 1,
	]));
	set("item_desc", ([
		"yan"  : "����������ͨ���ľ��ҡ�\n",
		"bing" : "������ҵı��㣬��Ө��͸����������һʱһ�ն��ɡ�\n",
	]));
	set("no_clean_up", 0);
	set("coor/x", 6110);
	set("coor/y", 5130);
	set("coor/z", 0);
	setup();
}

void init()
{
	add_action("do_push", "tui");
	add_action("do_push", "push");
	add_action("do_burn", "use");
	add_action("do_burn", "burn");
	add_action("do_burn", "shao");
}

int do_burn(string arg)
{
	object ob, me = this_player();

	if( !arg || arg=="" ) return 0;
	if (!present("fire", me)) return 0;
	if (!objectp(ob = present("mu chai", me))) return 0;
	if( arg=="yan" )
	{
		message_vision("$N����ľ��ȥ�ն���֮��ļ����\n����Խ��Խ�󣬱���Ϊˮ��ֻ���ö���֮��������һ���������ڵ��¡�\n", me);
		destruct(ob);
		if (me->query("neili",1) > 1000)
		{
			message_vision("�ۼ�����֮��ļ������ȥ��룬$N�����Ƽ����Ǿ��һ��˼��ϣ�������ת����ȥ��¶��һ����϶�����Ƹ���������ʯ��һ�㡣\n", me);
			set("exits", ([
				"enter" : __DIR__"baozang",
				"south" : __DIR__"tongdao2",
			]));
		}
		else
		{
			message_vision("$N˫���ھ���������һ�ƣ�����ʯ����������\n", me);
		}
	}
	else
	{
		write("��Ҫ����������������ʲô��\n");
	}
	return 1;
}

int do_push(string arg)
{
	object me = this_player();

	if (!arg || arg !="yan")
	{
		message_vision("����ط���ôС����ʲôѽ��\n", me);
		return 1;
	}
	else
	{
		message_vision("$N���ֵ��ھ����ϣ���������������ôһ�ƣ������˿������\n", me);
		return 1;
	}
}
