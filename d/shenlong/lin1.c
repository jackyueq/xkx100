// /d/shenlong/lin1.c
// Last Modified by winder on Aug. 18 2002

inherit ROOM;
string* npcs = ({
	__DIR__"npc/jinshe",
	__DIR__"npc/qingshe",
	__DIR__"npc/jinshe",
	__DIR__"npc/qingshe",
	__DIR__"npc/fushe",
});
 
void create()
{
	set("short", "��ľ��");
	set("long",@LONG
�嶥������һƬ������ʪ�Ĺ�ľ�֣�С·��û�ڹ�ľ���С������
��һ���µ��Ͼ���������һƬ��ľ��(bush)�е��ǳ��Ծ������ܵ�����
�г����˲�֪�����Ӳݡ�
LONG);
	set("exits", ([
		"southup" : __DIR__"fengding",
	]));
	set("item_desc", ([
		"bush" : "��Ƭ��ľ��̫���ˣ�Ҫ���ȥ����ֻ�п���һ��·��(kan)��\n",
	]));
	set("objects", ([
		__DIR__"npc/dushe" : 1+random(2),
		npcs[random(sizeof(npcs))] : 1,
		npcs[random(sizeof(npcs))] : 1,
		npcs[random(sizeof(npcs))] : 1,
	]) );
	set("outdoors", "shenlong");
	set("coor/x", 4000);
	set("coor/y", 3010);
	set("coor/z", 0);
	setup();
}

void init()
{
	add_action("do_kan", "kan");
}

int do_kan ( string arg )
{
	object ob, weapon, me = this_player();
	string dir;

	if( !arg || arg !="bush" ) return notify_fail("��Ҫ��ʲô��\n" ) ;
	if (!objectp(weapon = me->query_temp("weapon")))
		return notify_fail("�����������²��аɣ�\n");
	message_vision("$N������У����Ź�ľ��һ���ҿ���\n", me);
	if(me->query("neili")>100)
	{
		set("exits/north", __DIR__"lin2");
		message_vision( "$N�۵��������������ڿ���һ��С·��\n", me);
		me->add("neili",-50);
		remove_call_out("close");
		call_out("close", 20, this_object());
	}
	else	
	{
		message_vision("$N�۵�����������Ҳû����һ��·����\n", me);
		me->set("neili",0);
	}
	return 1;
}

void close(object room)
{
	message("vision","��ľ�Խ�����£�����������ָֻ���ԭ״��\n", room);
	room->delete("exits/north");
}
