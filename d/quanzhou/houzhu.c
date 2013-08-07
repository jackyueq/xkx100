// Room: /d/quanzhou/houzhu.c
// Last Modified by winder on May. 29 2001
#include <ansi.h>;
inherit ROOM;

void create()
{
	set("short", "��侸�");
	set("long", @LONG
��侸���Ȫ������ۿ�֮�ס��������ˮ���ƽ�˾�����ĿԶ����
����һɫ��ε����Ͼ������ͣ������������ĸ��ִ�ֻ�����ں���ó��
�Ĺ㷺��չ��Ȫ�������Ϊ������˿��֮·������㡣���ڶ�Ĵ�ֻ��
�䣬����һֻ��ս��(chuan)��
LONG );
	set("outdoors", "quanzhou");
	set("item_desc", ([
                "chuan" : "һ���󺣴�����Զ��û�����Ĵ��ɲ��С�\n",
	]));
	set("exits", ([
		"north"   : __DIR__"portroad2",
	]));
	set("objects", ([
		__DIR__"npc/boy": 2,
		__DIR__"npc/girl": 1,
		__DIR__"npc/shuishi" : 1,
	]));
	set("coor/x", 1880);
	set("coor/y", -6610);
	set("coor/z", 0);
	setup();
}

void init()
{
	add_action("do_enter", "enter");
}
int do_enter ( string arg )
{
	object ob = this_player () ;
	string dir;
	if( !arg || arg !="chuan" ) 
	{
		tell_object(this_player() , "��Ҫ enter �Ķ���\n" ) ;
		return 1 ;
	}
	message_vision("����һ�������ϴ���æ����һ��������ඣ�\n", ob);
	message_vision("�������𷫣������򶫷����С�\n", ob);
	ob ->move("/d/taiwan/dahai") ;
	tell_object(ob, BLU "���ں��Ϻ����˺ܾúܾ�.......\n" NOR ) ;
	call_out("tpenghu", 10 , ob );
	return 1 ;
}
void tpenghu(object ob )
{
	tell_object(ob , "�����ڵִ��˴���һ�����졣�����´�����\n" ) ;
	ob->move ("/d/taiwan/penghu") ;
}
