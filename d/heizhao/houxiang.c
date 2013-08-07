// Room: /heizhao/houxiang.c
// Date: Nov.18 1998 by Winder

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
��������Դ�µĳ�����һ���Ϻ����������æ��æȥ��������
��������Ĵ�ʦ���ˡ������Ķ��Ӷ��ˣ��͸Ͽ�Ҫ (serve)Щ��
�İɡ�
LONG );
	set("no_clean_up", 0);
	set("no_fight", 1);
	set("objects", ([
		__DIR__"npc/laoheshang" : 1,
	]));
	set("exits", ([
		"south" : __DIR__"chanyuan",
	]));
	set("ricewater", 5);
	set("coor/x", -5020);
	set("coor/y", -1190);
	set("coor/z", 50);
	setup();
}

void init()
{
        add_action("do_serve","serve");
}

int do_serve()
{
	object food, water, me = this_player(), ob = this_object();

	if (me->query("family/family_name") != "����μ�")
return notify_fail("�Ϻ��е��������ӷ���Ǳ��ɵ��ӣ�������ȡʳ�\n");
	if(present("mifang", me) || present("qingtang", me)) 
return notify_fail("�Ϻ��е��������ӷ𣬳��������ã����˷�ʳ�\n");
	if(present("mifang", ob) || present("qingtang", ob)) 
return notify_fail("�Ϻ��е������������ã����˷�ʳ�\n");
	if (query("ricewater")>0)
	{
		message_vision("�Ϻ���������Ӧ����$Nһ��������һ���׷���\n",me);
		food=new(__DIR__"obj/mifang");
		water=new(__DIR__"obj/qingtang");
		food->move(me);
		water->move(me);
		add("ricewater",-1);
	}
	else 
		message_vision("�Ϻ��ж�$NǸ����: �ˣ��ԵĺȵĶ�û�ˡ�\n",me);
	return 1; 
}
int valid_leave(object me,string dir)
{
        if(dir=="south" && (present("mifang", me) || present("qingtang", me))) 
             return notify_fail("�Ϻ���˵�������˾ͱ���ߡ�\n");
        return ::valid_leave(me,dir);
}