// Room: /d/songshan/chufang.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
������ɽ�ɵĳ�����һλ�͹�����Ļ�������ջ�������������ɢ
���ŷ��˵���ζ����������ż���С���Σ����������Ҫ(serve) Щ
�Եĺȵġ�
LONG);
	set("exits",([
		"east" : __DIR__"westting",
	]));
	set("no_clean_up", 0);
	set("ricewater", 5);
	set("no_fight","1");
	set("coor/x", -50);
	set("coor/y", 900);
	set("coor/z", 90);
	setup();
}
int valid_leave(object me, string dir)
{
	if ( present("soup", me) || present("rice", me))
		return notify_fail("��һת�������ſ������Ÿ�ʾ������ʳ���������\n");
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
	if (me->query("family/family_name") != "��ɽ��")
		return notify_fail("������һ̯�����㲻����ɽ�ɵ��ӣ�������ȡʳ���\n");
        if(present("rice",this_player()) ) 
		return notify_fail("���һ��ţ�ۣ������������ã����˷�ʳ���\n");
        if(present("rice",this_object()) ) 
		return notify_fail("����˿����ϣ����������������ã����˷�ʳ���\n");
	if (query("ricewater")>0)
	{
		message_vision("���������Ӧ����$Nһ����׷���һ���ʹ�����\n",me);
		food=new("/d/huashan/obj/rice");
		water=new("/d/huashan/obj/soup");
		food->move(me);
		water->move(me);
		add("ricewater",-1);
	}
	else 
		message_vision("����$NǸ���������ˣ��ԵĺȵĶ�û�ˡ���\n",me);
	return 1; 
}
