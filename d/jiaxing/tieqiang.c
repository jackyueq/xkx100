// Room: /d/jiaxing/tieqiang.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "��ǹ��");
	set("long", @LONG
����ǹ�����������ʱ������ǹ�����¡�������������������Ⱥ
ѻ����Ϊ������������˵��ǹ�����ѻ������񽫣����������ַ���
����������ֳ��Խ��Խ�ࡣ�������и�С��(dong)��
LONG );
	set("exits", ([
                "west"  : __DIR__"jxnanmen",
		"north" : __DIR__"nanhu",
	]));
        set("item_desc", ([
	    "dong" : "һ���ڰ��������صúܺõ�������\n",
	]));
        set("objects", ([
		__DIR__"npc/wuya": 4
	]));
//	set("no_clean_up", 0);
	set("outdoors", "jiaxing");
	set("coor/x", 1510);
	set("coor/y", -1010);
	set("coor/z", 0);
	setup();
}

void init()
{
        add_action("do_enter", "enter");
        add_action("do_enter", "zuan");
}

int do_enter(string arg)
{
	object me;
	mapping fam;

	me = this_player();
	if( !arg || arg=="" ) return 0;
	if( arg=="dong" )
	{
		if( (fam = me->query("family")) && fam["family_name"] == "ؤ��" ) 
		{
			message("vision",
				me->name() + "����ؤ�����ǹ���һ�������������˽�ȥ��\n",
				environment(me), ({me}) );
			me->move("/d/gaibang/underqz");
                	message("vision",
				me->name() + "�Ӷ������˽�����\n",
                		environment(me), ({me}) );
			return 1;
		}
		else 
			return notify_fail("��ôС�Ķ�������ý�ȥ��\n");
	}
}