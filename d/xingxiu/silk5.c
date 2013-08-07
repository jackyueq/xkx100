// /d/xingxiu/silk4.c
// Last Modified by winder on Feb. 28 2001

inherit ROOM;

void create()
{
	set("short", "˿��֮·");
	set("long", @LONG
����һ����ԭ������֮����̵���������һ���޼ʵĴ�ɳĮ����˵
���ﳣ�е��˳�û��������ͨ��һƬ�����ɽ�����������ͨ����ԭ��
·��·����һ��ʯ��(shibei)��
LONG );
	set("outdoors", "xiyu");
	set("exits", ([
		"southeast" : __DIR__"tugu",
		"west"      : __DIR__"shamo1",
		"northwest" : __DIR__"shanjiao",
		"southwest" : "/d/xueshan/caoyuan" ,
	]));
	set("objects", ([
		__DIR__"npc/trader" : 1,
	]));
	set("item_desc", ([
		"shibei" : "�������򣬶�����ԭ��˭�����У���ɱ���ۡ�����ɽ��������\n",
	]));
	set("coor/x", -24000);
	set("coor/y", 1000);
	set("coor/z", 0);
	setup();
}

void init()
{
	add_action("do_push", "push");
	add_action("do_push", "tui");
}

int valid_leave(object me, string dir)
{
	object ob;

	if ((dir == "west")&& !userp(me)) return 0;
	return ::valid_leave(me, dir);
	if(me->query_temp("wait_target") &&
		objectp(present("anran zi", environment(me))))
		return notify_fail("��Ȼ��������������ǰ���ȵ�������������ҹ�������\n");
	if(me->query_temp("xx_rob") &&
		objectp(ob = present("hubiao biaoshi", environment(me))) &&
		ob->query("target") == me)
		return notify_fail("������ʦ������ס���ȥ·�����������������ˣ�\n");  
	if(me->query_temp("xx_rob") && objectp(present("shangdui",environment(me))))
		return notify_fail("�̶��������أ�����(qiang)����\n");  
	return ::valid_leave(me, dir);
}

int do_push(string arg)
{
	object me = this_player();
	mapping fam;

	if( !arg || arg=="" ) return 0;
	if( arg=="shibei" )
	{
		if((fam = me->query("family")) && fam["family_name"] == "ؤ��")
		{
			message_vision("$N�ƿ�ʯ����ֻ����ɳ�׷׵��䣬������¶��һ��С����\n", me);
			message("vision", me->name() + "����ؤ�����ǹ���һ�������������˽�ȥ��\n", environment(me), ({me}) );
			me->move("/d/gaibang/underxx");
			message("vision", me->name() + "�Ӷ������˽�����\n", environment(me), ({me}) );
			return 1;
		}
		else return notify_fail("��ôС�Ķ�������ý�ȥ��\n");
	}
}	

