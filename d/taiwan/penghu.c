// Room: /d/taiwan/penghu.c
// Last Modifyed by Ahda on Jan. 4 2002

#include <ansi.h>;
inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
���Ϊ̨����������Ͽ���ƣ�̨�����ϡ������ڶ�Ϊ��������
��������������������
    ��������(zhou)��(chuan) ������½̨�����岨�����У��������
��ζ��
LONG );
	set("item_desc", ([
                "chuan" : "һ���󺣴�����Զ��û�����Ĵ��ɲ��С�\n",
                "zhou"  : "һ��ˮ��ս�ۣ�ǰ��̨�壬���ÿ�����\n",
	]));
	set("objects", ([
		__DIR__"npc/lanli": 1,
		__DIR__"npc/bing": 4,
	]));
	set("outdoors", "taiwan");
	set("coor/x", 2300);
	set("coor/y", -6800);
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
	if( !arg || (arg !="chuan" && arg !="zhou"))
	{
		tell_object(this_player() , "��Ҫ enter �Ķ���\n" ) ;
		return 1 ;
	}
	if (arg == "chuan")
	{
		message_vision("����һ�������ϴ���æ����һ��������ඣ�\n", ob);
		message_vision("�������𷫣�����������˳�纽�С�\n", ob);
		call_out("tdalu", 10 , ob );
	}
	else
	{
		message_vision("ˮ��һ�������ϴ���æ����һ��������ඣ�\n", ob);
		message_vision("ˮ�����𷫣������򶫷���纽�С�\n", ob);
		call_out("ttaiwan", 10 , ob );
	}
	ob->move(__DIR__"dahai") ;
	tell_object(ob, BLU "���ں��Ϻ����˺ܾúܾ�.......\n" NOR ) ;
	return 1 ;
}
void tdalu( object ob )
{
	tell_object(ob , "�����ڵִ��˸�����һ���������ۡ������´�����\n" ) ;
	ob->move("/d/quanzhou/houzhu") ;
}
void ttaiwan( object ob )
{
	tell_object(ob , "ս�����ڵִ���̨���һ���ۿڳ��С������´�����\n" ) ;
	ob->move(__DIR__"lugang") ;
}
