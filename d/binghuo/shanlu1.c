// Room: /binghuo/shanlu1.c
// Date: Oct.28 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "ʯɽС·");
	set("long", @LONG
���ڻ�ɽʯ�Ĵ��ƬҶ������ɽ·�ϡ����¾���ï�ܵĴ������ˡ�
��������ɽ��·��ɽ���������ӱ���¶��һ��ʯ��(dong)����������
�������㣬ϸ��ԭ���Ǵ�����һ��Բ�֪���Ļ����ϴ��������кں�
����ʲôҲ�Ʋ�����
LONG );
	set("outdoors", "binghuo");
	set("no_clean_up", 0);
	set("item_desc", ([
		"dong" : "���ԭ�������ѵ�ʯ�����������Ϊ������õľ�����\n",
	]));
	set("exits", ([
		"southeast" : __DIR__"shulin3",
		"northup"   : __DIR__"shanlu2",
	]));
	setup();
}

void init()
{
        add_action("do_enter", "enter");
}

int do_enter(string arg)
{
	object me;
	me = this_player();

        if( !arg || arg=="" ) return 0;

        if( arg=="dong" ) 
	{
		message("vision",
			me->name() + "һ�������������˽�ȥ��\n",
			environment(me), ({me}) );
                me->move(__DIR__"inhole1");
                message("vision",
			me->name() + "�Ӷ������˽�����\n",
                	environment(me), ({me}) );
		return 1;
	}
}	
