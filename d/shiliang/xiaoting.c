// Room: xiaoting.c
// Feb. 6, 1999 by Winder
inherit ROOM;
void create()
{
	set("short", "С��");
	set("long",@LONG
����һ��СС�Ŀ�����ǽ�Ϲ���һЩ�ֻ������������۵�����
��֮��һ������ͤ���򡷣��и�Ů�������ڴ�ɨ��������
LONG
	);
	set("exits", ([
		"south" : __DIR__"xiaoyuan",
                "up" : __DIR__"xiaolou",
	]));
        set("objects", ([
                 __DIR__"npc/afeng" : 1,
	]));
	set("item_desc", ([
		"����ͤ����" : "�����������������漣���ʷ��پ�����Ȼһ�ɴ�ҷ緶��\n" ,
	]));
	set("coor/x", 1620);
	set("coor/y", -1770);
	set("coor/z", 0);
	setup();
}
void init()
{
	add_action("do_enter", "enter");
//	add_action("do_move", "open");
	add_action("do_kneel", "kneel");
}
int do_kneel(string arg)
{
        object me,hole;
	string dir;
        me = this_player();
        if (!arg||arg=="") return 0;
	if( arg=="����ͤ����" ) {
		message_vision("$N�ϵع��ڡ���ͤ�����£�����ͷ���������ˡ��ذ�����ǿյġ�\n", this_player());
	}
	if( sscanf(arg, "����ͤ���� %s", dir)==1 ) 
	{
		if( dir=="9" || dir=="nine")
		{
			if(!objectp(present("hole", environment(me))))
			{
message_vision("$Nһ�������˾Ÿ���ͷ��ͻȻ�䣬�ذ��ɶ��ˣ�¶��һ���󶴡�\n",me);
				hole = new("/d/shiliang/obj/hole");
				hole->move("/d/shiliang/xiaoting");
			}
	        }   
		else return notify_fail("����ҿ��˼���ͷ�����ɶҲû������\n");
	}		
	return 1;
}
int do_enter(string arg)
{
	if( !arg || arg!="floor" ) return 0;
		return notify_fail(" �봩�ذ尡���㲻�����Ŷݼס�\n");
	return 1;
}