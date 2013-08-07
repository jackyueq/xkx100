// Room: /yangzhou/shiliji4.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;
look_gaoshi();

void create()
{
	set("short","����㳡");
	set("long",@LONG
�����ǳ��е������ģ�һ���ܿ����Ĺ㳡��������ʯ���棬ʮ�ﳤ
�ִ���������һЩ���ֺ��е�������������������������������
�ݡ�������һ�ô��������̸���ڣ��ݴ�����ǧ������䣬����������
����ʷ��֤�����ɵײ���һ���ܴ������(dong)������Կ�����������
�Ը��ص��������������������������У�һ�ɷ������󡣶������Ÿ�Ȫ
�֡�������ͨ���ţ���ͷ����һ���ʾ��(gaoshi)�����ž���ͨ������
���õĵ�·��
LONG );
	set("outdoors", "yangzhouw");
	set("no_sleep_room",1);
	set("visitor", 0);
	set("item_desc", ([
		"dong"  : "����һ���ڲ����еĴ󶴣����治֪����Щʲô�Ź֡�\n",
		"gaoshi" : (: look_gaoshi :),
	]));

	set("exits", ([
		"east"  : __DIR__"ganquanjie",
		"west"  : __DIR__"tongsiqiao",
		"south" : __DIR__"shilijie5",
		"north" : __DIR__"shilijie3",
		"down"	: __DIR__"lajichang",
	]));
	set("objects", ([
//		__DIR__"npc/xunbu" : 1,
		__DIR__"npc/liumang" : 4,
		__DIR__"npc/liumangtou" : 1,
		"/clone/misc/dache" : 1,
	]));
	set("coor/x", 10);
	set("coor/y", -10);
	set("coor/z", 0);
	setup();
}

void init()
{
	if(userp(this_player())) 
	{
		this_object()->add("visitor", 1);
		if(this_object()->query("visitor") % 500 == 0)
		{
			AUTOSAVE_D->create();
		}
	}
	add_action("do_enter", "enter");
//	UPDATE_D->check_user(this_player());
}

int do_enter(string arg)
{
	object me;
	me = this_player();

	if( !arg || arg=="" ) return 0;

	if( arg=="dong" ) 
	{
		if (me->is_busy()) return notify_fail("����æ���ء�\n");
		message("vision",
			me->name() + "һ�������������˽�ȥ��\n",
			environment(me), ({me}) );
		me->move("/d/gaibang/inhole");
		message("vision",
			me->name() + "�Ӷ������˽�����\n",
			environment(me), ({me}) );
		return 1;
	}
}

string look_gaoshi()
{
	string returnback;
	int count, sp;
	count=query("visitor");
	returnback="\n\n"+
	"������������������������������������������������������������������\n"+
	"��������                                                  ��������\n"+
	"��������                    ���ݸ�ͨ��                    ��������\n"+
	"��������                                                  ��������\n"+
	"��������    ����ͨ���˵ع���"+chinese_number(count)+"�ˡ�";
	for (sp = 0; sp < 26-strlen(chinese_number(count)); sp++)
		returnback += " ";

	returnback += "��������\n"
	"��������                                                  ��������\n"+
	"������������������������������������������������������������������\n";
	return returnback;
}
