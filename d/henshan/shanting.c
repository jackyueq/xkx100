// Room: /d/henshan/shanting.c
// Date: Sep.1 2001 by ahda

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����������������������շ�ʦ������æ����ͷ������ջ�������
��Ӧ��serve���������˵Ļ�ʳ��
LONG );
	set("exits", ([
		"south" : __DIR__"liufudating",
	]));
	set("objects", ([
		__DIR__"npc/shaofanshifu" : 1,
	]));
	set("coor/x", -400);
	set("coor/y", -1160);
	set("coor/z", 0);
	set("no_fight", 1);
	set("ricewater", 30);
	setup();
}

int valid_leave(object me, string dir)
{
	if ( present("soup", me) || present("rice", me))
	return notify_fail("�շ�ʦ������һ˫���ۣ��Բ���Ҫ�����߰���\n");
	return ::valid_leave(me, dir);
}

void init()
{
        add_action("do_serve","serve");
}

int do_serve()
{
	object me;
	object food;
	object water;
	me=this_player();
        if(present("rice",this_player()) ) 
		return notify_fail("�շ�ʦ���������������ã����˷�ʳ�\n");
        if(present("rice",this_object()) ) 
		return notify_fail("�շ�ʦ���������������ã����˷�ʳ�\n");
	if (query("ricewater")>0)
	{
		message_vision("�շ�ʦ����$Nһ���׷���һ������\n",me);
		food=new(__DIR__"obj/rice");
		water=new(__DIR__"obj/soup");
		food->move(me);
		water->move(me);
		add("ricewater",-1);
	}
	else 
		message_vision("�շ�ʦ����$NǸ����: �ˣ��ԵĺȵĶ�û�ˡ�\n",me);
	return 1; 
}
