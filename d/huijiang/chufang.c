// Room: /d/huijiang/chufang.c
// Last Modified by winder on Sep. 12 2001

inherit ROOM;

void create()
{
	set("short","����");
	set("long",@LONG
���Ǻ컨��ĳ������컨��������ڹ����ؽ�������������
һֱʮ��æµ�������Ĵ�ʦ�����������պ������ԣ���ʳһ�罭�ϡ�
�������˻���ˣ��������ʦ��Ҫ(serve) Щ�Եĺȵġ���ʦ��Ҳ
��Щ���ϵ�С�㣬ע������һ��ǽ��ÿ��ĸ�ʾ(gaoshi)�ͺ��ˡ�
LONG );
        set("objects", ([
		__DIR__"npc/shifu"     : 1,
        ]));
	set("exits", ([
		"south" : __DIR__"zoulang3",
	]));
	set("item_desc", ([
		"gaoshi" : 
"��������(Fish)           ��һ�������ֶ�ʮ��ͭ��
����Ϻ��(Shrimp)         ����ʮ��ͭ��
�л�ͯ��(Chicken)        ��һ�������ֶ�ʮ��ͭ��
��������(Guihua geng)  ��һ�������ֶ�ʮ��ͭ��
��ƿ(Jiuping)            ��ʮ��������\n"
	]));

	set("ricewater", 8);
	set("no_fight", 1);
	set("coor/x", -50050);
	set("coor/y", 9150);
	set("coor/z", 10);
	setup();
}

int valid_leave(object me, string dir)
{
	if ( present("soup", me) || present("baozi", me))
	return notify_fail("��ʦ��������һ��: �Բ���Ҫ�����߰���\n");
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
	if (me->query("family/family_name") != "�컨��")
		return notify_fail("��ʦ�������㲻�Ǻ컨����ӣ�������ȡʳ�\n");
        if(present("baozi",this_player()) ) 
		return notify_fail("��ʦ���������������ã����˷�ʳ�\n");
        if(present("baozi",this_object()) ) 
		return notify_fail("��ʦ���������������ã����˷�ʳ�\n");
	if (query("ricewater")>0)
	{
		message_vision("��ʦ��������Ӧ����$Nһ���ٹ��Ͱ���һ���Ҷ��������\n",me);
		food=new("/d/hangzhou/npc/obj/baozi");
		water=new("/d/suzhou/npc/obj/soup");
		food->move(me);
		water->move(me);
		add("ricewater",-1);
	}
	else 
		message_vision("��ʦ����$NǸ����: �ˣ��ԵĺȵĶ�û�ˡ�\n",me);
	return 1; 
}
